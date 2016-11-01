module CompilableExt where 

import Main as M ( transWithExt )

import System.Environment( getArgs )

errorMsg = 
	putStrLn "Usage:\n\tpolca_s2s_ext command filename [polca_block]\nThe command and the source file are needed.\nThe name of a defined block is optional."

callFun args def = 
	case (take 2 (reverse (args!!1))) of 
		('c':('.':_)) ->
			M.transWithExt (args!!0) (reverse (drop 2 (reverse (args!!1)))) def
		_ ->
			M.transWithExt (args!!0) (args!!1) def

main = do
	args <- getArgs
	case length args of 
		0 -> 
			errorMsg
		1 ->
			errorMsg	
		2 ->
			callFun args (Nothing)
		_ ->
			callFun (init args) (Just (args!!2))

			 