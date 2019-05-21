/*-----------------------------------------------------------------------------
 *				HTBLA-Leonding / Class: <your class name here>
 *-----------------------------------------------------------------------------
 * Exercise Number: #exercise_number#
 * File:			battleship.c
 * Author(s):		Peter Bauer
 * Due Date:		#due#
 *-----------------------------------------------------------------------------
 * Description:
 * <your description here>
 *-----------------------------------------------------------------------------
*/
#include <stdio.h>
#include <stdlib.h>
#include "battleship.h"
CellContent my[FIELDSIZE][FIELDSIZE];
CellContent op[FIELDSIZE][FIELDSIZE];
CellContent guesses[FIELDSIZE][FIELDSIZE];
void 	load_game (){
  FILE* my_fd = fopen("battleship.my", "r");
  for (int i = 0; i < FIELDSIZE; i++) {
    for (int j = 0; j < FIELDSIZE; j++) {
      fread(&my[i][j],sizeof(CellContent),1,my_fd);
    }
  }
  FILE* op_fd = fopen("battleship.my", "r");
  for (int i = 0; i < FIELDSIZE; i++) {
    for (int j = 0; j < FIELDSIZE; j++) {
      fread(&op[i][j],sizeof(CellContent),1,op_fd);
    }
  }
  for (int i = 0; i < FIELDSIZE; i++) {
    for (int j = 0; j < FIELDSIZE; j++) {
      guesses[i][j] = Unknown;
    }
  }

    fclose(my_fd);
    fclose(op_fd);
}
CellContent 	get_shot (int row, int col){
  if (row < FIELDSIZE && col < FIELDSIZE && row > -1 && col > -1) {
    return my[row][col];
  }
  return OutOfRange;
}
bool 	shoot (int row, int col){
  return true;
}
CellContent 	get_my_guess (int row, int col){
  return guesses[row][col];
}
