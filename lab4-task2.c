/*
 * lab4-task2.c  ( implementation of lab4 task 1-3)
 *
 *  Modified on: 2018-12-11
 *      Author: Marcus Lauren Andersson mala0377
 */

#include <stdio.h>

/* include helper functions for game */
#include "lifegame.h"

/* add whatever other includes here */

/* number of generations to evolve the world */
#define NUM_GENERATIONS 50

/* this function should set the state of all
   the cells in the next generation and call
   finalize_evolution() to update the current
   state of the world to the next generation */
void next_generation(void);

/* this function should return the state of the cell
   at (x,y) in the next generation, according to the
   rules of Conway's Game of Life (see handout) */
int get_next_state(int x, int y);

/* this function should calculate the number of alive
   neighbors of the cell at (x,y) */
int num_neighbors(int x, int y);

int main(int argc, char ** argv)
{
	int n;

	/* TODO:
        read in a file name (for live cells)
        initialize the world, from this file if it is readable
           otherwise, use hard-coded pattern by calling initialize_world( )   */

	/* evolutions*/
	for (n = 0; n < NUM_GENERATIONS; n++) {
		next_generation();   /* you implemented in lab4 task 1-2*/

		/* TODO: output the world state to console ==> you complete it in lab4 task 1-2 */

		/* TODO: let the program pause, until you press ENTER key to continue ==> you did it in lab4 task 1-2*/

	}

	/* TODO: output the world state to file  world.txt ==> you need complete it*/


	return 0;
}

/* the following functions are implemented in lab4 task 1-2, and you can copy from that file*/
void next_generation(void) {
	/* TODO: for every cell, set the state in the next
	   generation according to the Game of Life rules

	   Hint: use get_next_state(x,y) */


	finalize_evolution(); /* called at end to finalize */
}

int get_next_state(int x, int y) {
	/* TODO: for the specified cell, compute the state in
	   the next generation using the rules

	   Use num_neighbors(x,y) to compute the number of live
	   neighbors */

}

int num_neighbors(int x, int y) {
	/* TODO: for the specified cell, return the number of
	   neighbors that are ALIVE

	   Use get_cell_state(x,y) */

}
