#!/usr/bin/python
# /opt/local/bin/python
# /usr/bin/env python

# Copyright (c) 2013-2016, The IMDEA Software Institute and
# Copyright (c) 2013-2016, Universidad Politecnica de Madrid

# See LICENSE.txt and AUTHORS.txt for licensing and authorship

from scipy import *
import sys, time, re, os
# import matplotlib.pyplot as plt
# import pylab

from pybrain.rl.learners.valuebased import ActionValueTable
from pybrain.rl.agents import LearningAgent
from pybrain.rl.learners import Q, QLambda, SARSA #@UnusedImport
from pybrain.rl.explorers import BoltzmannExplorer #@UnusedImport
from pybrain.rl.experiments import Experiment
from pybrain.rl.environments import Task
from polcamdp import MDPPolcaTask
from PolcaEnv import PolcaEnv

modPath = os.path.dirname(os.path.realpath(__file__))
trainDataPath = modPath+'/utils/'
# trainDataPath = '../machine_learning/reinforcement_learning/utils/'
# trainDataPath = './utils/'

trainDataFile = 'trainingData.txt'

tableFile = 'actionValueTable.txt'

supportedPlatforms = ["none","opencl", "maxj", "mpi", "openmp"]

initStates       = None
goalStates       = None

transitionTable  = None

actionValueTable = None

ruleNames        = None
abst2State       = None

numActions       = -1
numStates        = -1
table            = None

def parseList(listStr,dataType):
    listStr = listStr.replace('[','')
    listStr = listStr.replace(']','')
    listStr = listStr.replace('\n','')

    if dataType == 0:
        newStr = [int(num) for num in listStr.split(',')]
    elif dataType == 1:
        newStr = [float(num) for num in listStr.split(',')]
    else: # 2 = Str
        newStr = [str(num) for num in listStr.split(',')]

    if newStr == None:
        if dataType == 0:
            newStr = [int(listStr)]
        elif dataType == 1:
            newStr = [float(listStr)]
        else:
            newStr = [str(listStr)]


    return newStr


def readTrainData(trainDataFile):
    global initStates,goalStates,transitionTable,ruleNames,abst2State

    # sys.stderr.write("Loading train data from file %s ...\n" % (trainDataFile))
    f = open(trainDataFile,'r')

    tableData = None
    dataFound = -1
    # lineToProcess = None
    for line in f:

        m1 = re.match("Init\. States",line)
        m2 = re.match("Final States",line)
        m3 = re.match("Transition Table",line)
        m4 = re.match("Rule Names",line)
        m5 = re.match("Abst\.-State mappings",line)

        if dataFound == 0:
            initStates = parseList(line,0)
            # print initStates
            dataFound = -1

        if dataFound == 1:
            goalStates = parseList(line,0)
            # print goalStates
            dataFound = -1

        if dataFound == 2:
            tableRow = parseList(line,0)
            if tableData == None:
                tableData = [tableRow]
            else:
                tableData.append(tableRow)
            # print tableRow

        if dataFound == 3:
            ruleNames = eval(line)
            dataFound = -1

        if dataFound == 4:
            abst2State = eval(line)
            dataFound = -1

        if m4:
            dataFound = 3

        if m5:
            dataFound = 4

        if m1:
            dataFound = 0

        if m2:
            dataFound = 1

        if m3:
            dataFound = 2
            # lineToProcess

    f.close()
    transitionTable = array(tableData)


def readActionValueTable(tableFile):
    global actionValueTable

    # sys.stderr.write("Loading train data from file %s ...\n" % (tableFile))
    f = open(tableFile,'r')

    for line in f:
        actionValueTable = parseList(line,1)

    f.close()


def getRuleId(ruleName):
    global ruleNames

    # print("#### %s" % (ruleName))
    ruleId = -1
    for rule in ruleNames:
        ruleId += 1
        if rule == ruleName:
            return ruleId

    return ruleId

def getRuleName(ruleId):
    global ruleNames

    ruleName = ""
    if ruleId != -1:
        ruleName = ruleNames[ruleId]

    return ruleName

def initData(targetPlatform):
    global numActions,numStates,table,trainDataFile,tableFile

    if targetPlatform not in supportedPlatforms:
        sys.stderr.write("------------------------------------------\n")
        sys.stderr.write("ERROR: target platform '%s' not supported by RL in training set\n" % (targetPlatform))
        sys.stderr.write("------------------------------------------\n")


    # sys.stderr.write("\n\n%s\n\n" % targetPlatform)

    defaultTarget = "maxj"

    if targetPlatform == "none":
        targetPlatform = defaultTarget

    replaceStr = "_%s.txt" % (targetPlatform)
    trainDataFile = trainDataFile.replace(".txt",replaceStr)
    tableFile = tableFile.replace(".txt",replaceStr)

    readTrainData(trainDataPath+trainDataFile)

    readActionValueTable(trainDataPath+tableFile)



    numActions = transitionTable.shape[1]
    numStates = transitionTable.shape[0]

    # create value table and initialize with ones
    table = ActionValueTable(numStates, numActions)

    # print(actionValueTable)
    for i in range(transitionTable.shape[0]):
        for j in range(transitionTable.shape[1]):
            table._params[i*transitionTable.shape[1]+j] = actionValueTable[i*transitionTable.shape[1]+j]

    # print type(table._params)
    #
    #
    # print table.params.reshape(numStates,numActions)

def testTransformationProcess():
    for initState in initStates:

        state = initState
        newState = initState
        # goal = array([11])
        action = None
        values = None
        steps = 0

        # values = table.params.reshape(numStates, numActions)[state, :].flatten()
        # sorted_arr = sort(values)
        # reversed_arr = sorted_arr[::-1]
        # value = sorted_arr[::-1][0]
        # print values
        # print sorted_arr
        # print reversed_arr
        # print value
        sys.stdout.write("           [ S, A] ->  S\n")
        sys.stdout.write("           -------------\n")
        try:
            # while not (newState in goal) and steps<5:
            while not (newState in goalStates):
                # action = table.getMaxAction(state)
                values = table.params.reshape(numStates, numActions)[state, :].flatten()
                action = where(values == max(values))[0]
                newState = transitionTable[state,action]

                sys.stdout.write("Transition [%2d" % (state))
                sys.stdout.write(",%2d] ->" % (action))
                sys.stdout.write(" %2d\n" % (newState))
                state = newState
                steps += 1
        except TypeError:
            print("\nTypeError in returned action:")
            print(action)
            print(values)

        print("-------------------------------------------------")

    return -1


def transformationStep(codeAbstraction,ruleIdList):

    state = abst2State[codeAbstraction]

    globalAction = -1
    newState     = -1
    if not state in goalStates:
        # values = table.params.reshape(numStates, numActions)[state, :].flatten()
        # sys.stderr.write("\n"+str(ruleIdList)+"\n")
        values = table.params.reshape(numStates, numActions)[state, ruleIdList].flatten()
        localAction = where(values == max(values))[0]
        # sys.stderr.write(str(localAction)+"\n")
        # localAction is of type numpy.ndarray -> get the first value since it is the max
        globalAction = ruleIdList[localAction[0]]
        # sys.stderr.write(str(getRuleName(globalAction))+"\n")
        newState = transitionTable[state,globalAction]

        # # print type(table.params)
        # sys.stdout.write("Transition [%2d" % (state))
        # sys.stdout.write(",%2d] ->" % (globalAction))
        # sys.stdout.write(" %2d\n" % (newState))

    return newState,globalAction


def convertStr2IdList(ruleNameList):
    ruleIdList = []

    for ruleName in ruleNameList:
        # print("%s" % ruleName)
        ruleIdList.append(getRuleId(ruleName))

    return ruleIdList

############################################################################

dataInitialized = False

def predict(codeAbstraction,ruleNameList,targetPlatform):
    global dataInitialized


    if isinstance(codeAbstraction, (list)):
        aux = codeAbstraction
        codeAbstraction = "".join(str(x) for x in aux)


    # ruleIdList = eval(sys.argv[2])
    #'-1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0'
    #ruleIdList = [0,4,6,41,45]

    if not dataInitialized:
        # sys.stderr.write("Loading ML data... ")
        initData(targetPlatform)
        dataInitialized = True
        # sys.stderr.write("Done!\n")

    ruleId = -1
    newState = -1
    if codeAbstraction == None:
        ruleId = testTransformationProcess()
    else:
        ruleIdList = convertStr2IdList(ruleNameList)
        newState,ruleId = transformationStep(codeAbstraction,ruleIdList)


    ruleName = getRuleName(ruleId)
    abstraction = ""
    if(newState != -1):
        abstraction = list(abst2State.keys())[list(abst2State.values()).index(newState)]
        # sys.stderr.write(str(newState) + " , " +abstraction + " : " + str(ruleName)+"\n")

    return abstraction,ruleName


if __name__ == "__main__":

    ruleName = ""

    codeAbstraction = None
    ruleNameList    = None

    targetPlatform = "none"
    if len(sys.argv) < 2:
        # print("ERROR: usage -> %s <code_abstraction> <rule_id_list>" % (sys.argv[0]))
        print("ERROR: usage -> %s <target_platform>" % (sys.argv[0]))
        exit(0)
        # codeAbstraction = sys.argv[1]
        # ruleNameList = parseList(sys.argv[2],2)
    else:
        targetPlatform = sys.argv[1]
        # codeAbstraction = eval(sys.argv[1])
        # ruleNameList = parseList(sys.argv[2],2)

    cwd = os.getcwd()
    # print(cwd)

    cmdPath = ''
    if 'reinforcement_learning' in cwd:
        trainDataPath = './utils/'
    else:
        # modPath = os.path.dirname(os.path.realpath(__file__))
        # trainDataPath = modPath+'/utils/'
        trainDataPath = '../machine_learning/reinforcement_learning/utils/'

    # print   type(codeAbstraction)
    abs,ruleName = predict(codeAbstraction,ruleNameList,targetPlatform)

    sys.exit(ruleName)


