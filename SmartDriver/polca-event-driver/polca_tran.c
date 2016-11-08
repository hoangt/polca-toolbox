
#include "inst_polca.h"

/*************************************/
/***       Start Point Calls       ***/
/*************************************/

void start_POLCA_S2STRANS_REMOVE_IDENTITY() {
  polca_event(POLCA_S2STRANS_REMOVE_IDENTITY, POLCA_S2STRAN_START);
}

void start_POLCA_S2STRANS_REDUCE_TO_0() {
  polca_event(POLCA_S2STRANS_REDUCE_TO_0, POLCA_S2STRAN_START);
}

void start_POLCA_S2STRANS_UNDO_DISTRIBUTIVE() {
  polca_event(POLCA_S2STRANS_UNDO_DISTRIBUTIVE, POLCA_S2STRAN_START);
}

void start_POLCA_S2STRANS_SUB_TO_MULT() {
  polca_event(POLCA_S2STRANS_SUB_TO_MULT, POLCA_S2STRAN_START);
}

void start_POLCA_S2STRANS_NORMALIZE_ITERATION_STEP() {
  polca_event(POLCA_S2STRANS_NORMALIZE_ITERATION_STEP, POLCA_S2STRAN_START);
}

void start_POLCA_S2STRANS_LOOP_REVERSAL_D2I() {
  polca_event(POLCA_S2STRANS_LOOP_REVERSAL_D2I, POLCA_S2STRAN_START);
}

void start_POLCA_S2STRANS_LOOP_REVERSAL_I2D() {
  polca_event(POLCA_S2STRANS_LOOP_REVERSAL_I2D, POLCA_S2STRAN_START);
}

void start_POLCA_S2STRANS_LOOP_INTERCHANGE() {
  polca_event(POLCA_S2STRANS_LOOP_INTERCHANGE, POLCA_S2STRAN_START);
}

void start_POLCA_S2STRANS_LOOP_INTERCHANGE_PRAGMA() {
  polca_event(POLCA_S2STRANS_LOOP_INTERCHANGE_PRAGMA, POLCA_S2STRAN_START);
}

void start_POLCA_S2STRANS_FOR_CHUNK() {
  polca_event(POLCA_S2STRANS_FOR_CHUNK, POLCA_S2STRAN_START);
}

void start_POLCA_S2STRANS_UNROLLING() {
  polca_event(POLCA_S2STRANS_UNROLLING, POLCA_S2STRAN_START);
}

void start_POLCA_S2STRANS_MOVE_INSIDE_FOR() {
  polca_event(POLCA_S2STRANS_MOVE_INSIDE_FOR, POLCA_S2STRAN_START);
}

void start_POLCA_S2STRANS_COLLAPSE_2_FOR_LOOPS() {
  polca_event(POLCA_S2STRANS_COLLAPSE_2_FOR_LOOPS, POLCA_S2STRAN_START);
}

void start_POLCA_S2STRANS_FOR_LOOP_FISSION() {
  polca_event(POLCA_S2STRANS_FOR_LOOP_FISSION, POLCA_S2STRAN_START);
}

void start_POLCA_S2STRANS_FOR_LOOP_FUSION_MAPMAP() {
  polca_event(POLCA_S2STRANS_FOR_LOOP_FUSION_MAPMAP, POLCA_S2STRAN_START);
}

void start_POLCA_S2STRANS_FOR_LOOP_FUSION() {
  polca_event(POLCA_S2STRANS_FOR_LOOP_FUSION, POLCA_S2STRAN_START);
}

void start_POLCA_S2STRANS_FOR_WO_BLOCK_2_FOR_W_BLOCK() {
  polca_event(POLCA_S2STRANS_FOR_WO_BLOCK_2_FOR_W_BLOCK, POLCA_S2STRAN_START);
}

void start_POLCA_S2STRANS_REMOVE_EMPTY_FOR() {
  polca_event(POLCA_S2STRANS_REMOVE_EMPTY_FOR, POLCA_S2STRAN_START);
}

void start_POLCA_S2STRANS_FOR_TO_WHILE() {
  polca_event(POLCA_S2STRANS_FOR_TO_WHILE, POLCA_S2STRAN_START);
}

void start_POLCA_S2STRANS_WHILE_TO_FOR() {
  polca_event(POLCA_S2STRANS_WHILE_TO_FOR, POLCA_S2STRAN_START);
}

void start_POLCA_S2STRANS_IF_WO_BLOCK_2_IF_W_BLOCK() {
  polca_event(POLCA_S2STRANS_IF_WO_BLOCK_2_IF_W_BLOCK, POLCA_S2STRAN_START);
}

void start_POLCA_S2STRANS_IF_WO_ELSE_2_IF_W_ELSE() {
  polca_event(POLCA_S2STRANS_IF_WO_ELSE_2_IF_W_ELS, POLCA_S2STRAN_START);
}

void start_POLCA_S2STRANS_SPLIT_ADDITION_ASSIGN() {
  polca_event(POLCA_S2STRANS_SPLIT_ADDITION_ASSIGN, POLCA_S2STRAN_START);
}

void start_POLCA_S2STRANS_JOIN_ADDITION_ASSIGN() {
  polca_event(POLCA_S2STRANS_JOIN_ADDITION_ASSIGN, POLCA_S2STRAN_START);
}

void start_POLCA_S2STRANS_MULT_TERNARY_2_TERNARY() {
  polca_event(POLCA_S2STRANS_MULT_TERNARY_2_TERNARY, POLCA_S2STRAN_START);
}

void start_POLCA_S2STRANS_SUM_TERNARY_2_TERNARY() {
  polca_event(POLCA_S2STRANS_SUM_TERNARY_2_TERNARY, POLCA_S2STRAN_START);
}

void start_POLCA_S2STRANS_ASSIGN_TERNARY_2_IF_ELSE() {
  polca_event(POLCA_S2STRANS_ASSIGN_TERNARY_2_IF_ELSE, POLCA_S2STRAN_START);
}

void start_POLCA_S2STRANS_IF_ELSE_2_ASSIGN_TERNARY() {
  polca_event(POLCA_S2STRANS_IF_ELSE_2_ASSIGN_TERNARY, POLCA_S2STRAN_START);
}

void start_POLCA_S2STRANS_IF_2_ASSIGN_TERNARY() {
  polca_event(POLCA_S2STRANS_IF_2_ASSIGN_TERNARY, POLCA_S2STRAN_START);
}

void start_POLCA_S2STRANS_EMPTY_ELSE() {
  polca_event(POLCA_S2STRANS_EMPTY_ELSE, POLCA_S2STRAN_START);
}

void start_POLCA_S2STRANS_REMOVE_TERNARY() {
  polca_event(POLCA_S2STRANS_REMOVE_TERNARY, POLCA_S2STRAN_START);
}

void start_POLCA_S2STRANS_REMOVE_BLOCK() {
  polca_event(POLCA_S2STRANS_REMOVE_BLOCK, POLCA_S2STRAN_START);
}

void start_POLCA_S2STRANS_REMOVE_EMPTY_IF() {
  polca_event(POLCA_S2STRANS_REMOVE_EMPTY_IF, POLCA_S2STRAN_START);
}

void start_POLCA_S2STRANS_REMOVE_USELESS_STATEMENT() {
  polca_event(POLCA_S2STRANS_REMOVE_USELESS_STATEMENT, POLCA_S2STRAN_START);
}

void start_POLCA_S2STRANS_STRENGTH_REDUCTION() {
  polca_event(POLCA_S2STRANS_STRENGTH_REDUCTION, POLCA_S2STRAN_START);
}

void start_POLCA_S2STRANS_USELESS_ASSIGN() {
  polca_event(POLCA_S2STRANS_USELESS_ASSIGN, POLCA_S2STRAN_START);
}

void start_POLCA_S2STRANS_REPLACE_VAR_EQUAL() {
  polca_event(POLCA_S2STRANS_REPLACE_VAR_EQUAL, POLCA_S2STRAN_START);
}

void start_POLCA_S2STRANS_JUST_ONE_ITERATION_REMOVAL() {
  polca_event(POLCA_S2STRANS_JUST_ONE_ITERATION_REMOVAL, POLCA_S2STRAN_START);
}

void start_POLCA_S2STRANS_JOIN_ASSIGNMENTS() {
  polca_event(POLCA_S2STRANS_JOIN_ASSIGNMENTS, POLCA_S2STRAN_START);
}

void start_POLCA_S2STRANS_PROPAGATE_ASSIGNMENT() {
  polca_event(POLCA_S2STRANS_PROPAGATE_ASSIGNMENT, POLCA_S2STRAN_START);
}

void start_POLCA_S2STRANS_LOOP_INV_CODE_MOTION() {
  polca_event(POLCA_S2STRANS_LOOP_INV_CODE_MOTION, POLCA_S2STRAN_START);
}

void start_POLCA_S2STRANS_INLINING() {
  polca_event(POLCA_S2STRANS_INLINING, POLCA_S2STRAN_START);
}

void start_POLCA_S2STRANS_INLINING_ASSIGNMENT() {
  polca_event(POLCA_S2STRANS_INLINING_ASSIGNMENT, POLCA_S2STRAN_START);
}

void start_POLCA_S2STRANS_COMMON_SUBEXP_ELIMINATION() {
  polca_event(POLCA_S2STRANS_COMMON_SUBEXP_ELIMINATION, POLCA_S2STRAN_START);
}

void start_POLCA_S2STRANS_INTRODUCE_AUX_ARRAY() {
  polca_event(POLCA_S2STRANS_INTRODUCE_AUX_ARRAY, POLCA_S2STRAN_START);
}

void start_POLCA_S2STRANS_FLATTEN_FLOAT_ARRAY() {
  polca_event(POLCA_S2STRANS_FLATTEN_FLOAT_ARRAY, POLCA_S2STRAN_START);
}

void start_POLCA_S2STRANS_FLATTEN_INT_ARRAY() {
  polca_event(POLCA_S2STRANS_FLATTEN_INT_ARRAY, POLCA_S2STRAN_START);
}

void start_POLCA_S2STRANS_SUBS_STRUCT_BY_FIELDS() {
  polca_event(POLCA_S2STRANS_SUBS_STRUCT_BY_FIELDS, POLCA_S2STRAN_START);
}

void start_POLCA_S2STRANS_ROLL_UP_INIT() {
  polca_event(POLCA_S2STRANS_ROLL_UP_INIT, POLCA_S2STRAN_START);
}

void start_POLCA_S2STRANS_ROLL_UP() {
  polca_event(POLCA_S2STRANS_ROLL_UP, POLCA_S2STRAN_START);
}

void start_POLCA_S2STRANS_ROLL_UP_ARRAY_INIT() {
  polca_event(POLCA_S2STRANS_ROLL_UP_ARRAY_INIT, POLCA_S2STRAN_START);
}

void start_POLCA_S2STRANS_ROLL_UP_ARRAY() {
  polca_event(POLCA_S2STRANS_ROLL_UP_ARRAY, POLCA_S2STRAN_START);
}

/*************************************/
/***        End Point Calls        ***/
/*************************************/

void end_POLCA_S2STRANS_REMOVE_IDENTITY() {
  polca_event(POLCA_S2STRANS_REMOVE_IDENTITY, POLCA_S2STRAN_END);
}

void end_POLCA_S2STRANS_REDUCE_TO_0() {
  polca_event(POLCA_S2STRANS_REDUCE_TO_0, POLCA_S2STRAN_END);
}

void end_POLCA_S2STRANS_UNDO_DISTRIBUTIVE() {
  polca_event(POLCA_S2STRANS_UNDO_DISTRIBUTIVE, POLCA_S2STRAN_END);
}

void end_POLCA_S2STRANS_SUB_TO_MULT() {
  polca_event(POLCA_S2STRANS_SUB_TO_MULT, POLCA_S2STRAN_END);
}

void end_POLCA_S2STRANS_NORMALIZE_ITERATION_STEP() {
  polca_event(POLCA_S2STRANS_NORMALIZE_ITERATION_STEP, POLCA_S2STRAN_END);
}

void end_POLCA_S2STRANS_LOOP_REVERSAL_D2I() {
  polca_event(POLCA_S2STRANS_LOOP_REVERSAL_D2I, POLCA_S2STRAN_END);
}

void end_POLCA_S2STRANS_LOOP_REVERSAL_I2D() {
  polca_event(POLCA_S2STRANS_LOOP_REVERSAL_I2D, POLCA_S2STRAN_END);
}

void end_POLCA_S2STRANS_LOOP_INTERCHANGE() {
  polca_event(POLCA_S2STRANS_LOOP_INTERCHANGE, POLCA_S2STRAN_END);
}

void end_POLCA_S2STRANS_LOOP_INTERCHANGE_PRAGMA() {
  polca_event(POLCA_S2STRANS_LOOP_INTERCHANGE_PRAGMA, POLCA_S2STRAN_END);
}

void end_POLCA_S2STRANS_FOR_CHUNK() {
  polca_event(POLCA_S2STRANS_FOR_CHUNK, POLCA_S2STRAN_END);
}

void end_POLCA_S2STRANS_UNROLLING() {
  polca_event(POLCA_S2STRANS_UNROLLING, POLCA_S2STRAN_END);
}

void end_POLCA_S2STRANS_MOVE_INSIDE_FOR() {
  polca_event(POLCA_S2STRANS_MOVE_INSIDE_FOR, POLCA_S2STRAN_END);
}

void end_POLCA_S2STRANS_COLLAPSE_2_FOR_LOOPS() {
  polca_event(POLCA_S2STRANS_COLLAPSE_2_FOR_LOOPS, POLCA_S2STRAN_END);
}

void end_POLCA_S2STRANS_FOR_LOOP_FISSION() {
  polca_event(POLCA_S2STRANS_FOR_LOOP_FISSION, POLCA_S2STRAN_END);
}

void end_POLCA_S2STRANS_FOR_LOOP_FUSION_MAPMAP() {
  polca_event(POLCA_S2STRANS_FOR_LOOP_FUSION_MAPMAP, POLCA_S2STRAN_END);
}

void end_POLCA_S2STRANS_FOR_LOOP_FUSION() {
  polca_event(POLCA_S2STRANS_FOR_LOOP_FUSION, POLCA_S2STRAN_END);
}

void end_POLCA_S2STRANS_FOR_WO_BLOCK_2_FOR_W_BLOCK() {
  polca_event(POLCA_S2STRANS_FOR_WO_BLOCK_2_FOR_W_BLOCK, POLCA_S2STRAN_END);
}

void end_POLCA_S2STRANS_REMOVE_EMPTY_FOR() {
  polca_event(POLCA_S2STRANS_REMOVE_EMPTY_FOR, POLCA_S2STRAN_END);
}

void end_POLCA_S2STRANS_FOR_TO_WHILE() {
  polca_event(POLCA_S2STRANS_FOR_TO_WHILE, POLCA_S2STRAN_END);
}

void end_POLCA_S2STRANS_WHILE_TO_FOR() {
  polca_event(POLCA_S2STRANS_WHILE_TO_FOR, POLCA_S2STRAN_END);
}

void end_POLCA_S2STRANS_IF_WO_BLOCK_2_IF_W_BLOCK() {
  polca_event(POLCA_S2STRANS_IF_WO_BLOCK_2_IF_W_BLOCK, POLCA_S2STRAN_END);
}

void end_POLCA_S2STRANS_IF_WO_ELSE_2_IF_W_ELSE() {
  polca_event(POLCA_S2STRANS_IF_WO_ELSE_2_IF_W_ELS, POLCA_S2STRAN_END);
}

void end_POLCA_S2STRANS_SPLIT_ADDITION_ASSIGN() {
  polca_event(POLCA_S2STRANS_SPLIT_ADDITION_ASSIGN, POLCA_S2STRAN_END);
}

void end_POLCA_S2STRANS_JOIN_ADDITION_ASSIGN() {
  polca_event(POLCA_S2STRANS_JOIN_ADDITION_ASSIGN, POLCA_S2STRAN_END);
}

void end_POLCA_S2STRANS_MULT_TERNARY_2_TERNARY() {
  polca_event(POLCA_S2STRANS_MULT_TERNARY_2_TERNARY, POLCA_S2STRAN_END);
}

void end_POLCA_S2STRANS_SUM_TERNARY_2_TERNARY() {
  polca_event(POLCA_S2STRANS_SUM_TERNARY_2_TERNARY, POLCA_S2STRAN_END);
}

void end_POLCA_S2STRANS_ASSIGN_TERNARY_2_IF_ELSE() {
  polca_event(POLCA_S2STRANS_ASSIGN_TERNARY_2_IF_ELSE, POLCA_S2STRAN_END);
}

void end_POLCA_S2STRANS_IF_ELSE_2_ASSIGN_TERNARY() {
  polca_event(POLCA_S2STRANS_IF_ELSE_2_ASSIGN_TERNARY, POLCA_S2STRAN_END);
}

void end_POLCA_S2STRANS_IF_2_ASSIGN_TERNARY() {
  polca_event(POLCA_S2STRANS_IF_2_ASSIGN_TERNARY, POLCA_S2STRAN_END);
}

void end_POLCA_S2STRANS_EMPTY_ELSE() {
  polca_event(POLCA_S2STRANS_EMPTY_ELSE, POLCA_S2STRAN_END);
}

void end_POLCA_S2STRANS_REMOVE_TERNARY() {
  polca_event(POLCA_S2STRANS_REMOVE_TERNARY, POLCA_S2STRAN_END);
}

void end_POLCA_S2STRANS_REMOVE_BLOCK() {
  polca_event(POLCA_S2STRANS_REMOVE_BLOCK, POLCA_S2STRAN_END);
}

void end_POLCA_S2STRANS_REMOVE_EMPTY_IF() {
  polca_event(POLCA_S2STRANS_REMOVE_EMPTY_IF, POLCA_S2STRAN_END);
}

void end_POLCA_S2STRANS_REMOVE_USELESS_STATEMENT() {
  polca_event(POLCA_S2STRANS_REMOVE_USELESS_STATEMENT, POLCA_S2STRAN_END);
}

void end_POLCA_S2STRANS_STRENGTH_REDUCTION() {
  polca_event(POLCA_S2STRANS_STRENGTH_REDUCTION, POLCA_S2STRAN_END);
}

void end_POLCA_S2STRANS_USELESS_ASSIGN() {
  polca_event(POLCA_S2STRANS_USELESS_ASSIGN, POLCA_S2STRAN_END);
}

void end_POLCA_S2STRANS_REPLACE_VAR_EQUAL() {
  polca_event(POLCA_S2STRANS_REPLACE_VAR_EQUAL, POLCA_S2STRAN_END);
}

void end_POLCA_S2STRANS_JUST_ONE_ITERATION_REMOVAL() {
  polca_event(POLCA_S2STRANS_JUST_ONE_ITERATION_REMOVAL, POLCA_S2STRAN_END);
}

void end_POLCA_S2STRANS_JOIN_ASSIGNMENTS() {
  polca_event(POLCA_S2STRANS_JOIN_ASSIGNMENTS, POLCA_S2STRAN_END);
}

void end_POLCA_S2STRANS_PROPAGATE_ASSIGNMENT() {
  polca_event(POLCA_S2STRANS_PROPAGATE_ASSIGNMENT, POLCA_S2STRAN_END);
}

void end_POLCA_S2STRANS_LOOP_INV_CODE_MOTION() {
  polca_event(POLCA_S2STRANS_LOOP_INV_CODE_MOTION, POLCA_S2STRAN_END);
}

void end_POLCA_S2STRANS_INLINING() {
  polca_event(POLCA_S2STRANS_INLINING, POLCA_S2STRAN_END);
}

void end_POLCA_S2STRANS_INLINING_ASSIGNMENT() {
  polca_event(POLCA_S2STRANS_INLINING_ASSIGNMENT, POLCA_S2STRAN_END);
}

void end_POLCA_S2STRANS_COMMON_SUBEXP_ELIMINATION() {
  polca_event(POLCA_S2STRANS_COMMON_SUBEXP_ELIMINATION, POLCA_S2STRAN_END);
}

void end_POLCA_S2STRANS_INTRODUCE_AUX_ARRAY() {
  polca_event(POLCA_S2STRANS_INTRODUCE_AUX_ARRAY, POLCA_S2STRAN_END);
}

void end_POLCA_S2STRANS_FLATTEN_FLOAT_ARRAY() {
  polca_event(POLCA_S2STRANS_FLATTEN_FLOAT_ARRAY, POLCA_S2STRAN_END);
}

void end_POLCA_S2STRANS_FLATTEN_INT_ARRAY() {
  polca_event(POLCA_S2STRANS_FLATTEN_INT_ARRAY, POLCA_S2STRAN_END);
}

void end_POLCA_S2STRANS_SUBS_STRUCT_BY_FIELDS() {
  polca_event(POLCA_S2STRANS_SUBS_STRUCT_BY_FIELDS, POLCA_S2STRAN_END);
}

void end_POLCA_S2STRANS_ROLL_UP_INIT() {
  polca_event(POLCA_S2STRANS_ROLL_UP_INIT, POLCA_S2STRAN_END);
}

void end_POLCA_S2STRANS_ROLL_UP() {
  polca_event(POLCA_S2STRANS_ROLL_UP, POLCA_S2STRAN_END);
}

void end_POLCA_S2STRANS_ROLL_UP_ARRAY_INIT() {
  polca_event(POLCA_S2STRANS_ROLL_UP_ARRAY_INIT, POLCA_S2STRAN_END);
}

void end_POLCA_S2STRANS_ROLL_UP_ARRAY() {
  polca_event(POLCA_S2STRANS_ROLL_UP_ARRAY, POLCA_S2STRAN_END);
}
