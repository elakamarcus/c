/*
 * lab4-task1.c
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

/* functions to implement */

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

int main(void)
{
	int n;

	/* TODO: initialize the world by hard-coded function initialize_world() in lifegame.c*/

	/* evolutions*/
	for (n = 0; n < NUM_GENERATIONS; n++) {
		next_generation();   /* TODO:  his function is not complete, you need to implement it*/

		/* TODO: output the world state to console, you need to call a given function */


		/* TODO: let the program pause, until you press ENTER key to continue ==> call getchar( )*/
		/*
		2018-12-12 add getchar();
		*/
		getchar();
	}


	return 0;
}

void next_generation(void) {
	/* TODO: for every cell, set the state in the next
	   generation according to the Game of Life rules

	   Hint: use get_next_state(x,y) */

	   /**
		*
		* mala comments:
		loop through each coordinate to get next state for each.

	   set x and y to loop through each point
	   */
	   int x,y;
	   for(x=0; x<=WORLDWIDTH;x++){
		   for(y=0; y<=WORLDHEIGHT;y++){
			   get_next_state(x, y);
		   }
	   }
	   /**/




	finalize_evolution(); /* called at end to finalize */
}

int get_next_state(int x, int y) {
	/* TODO: for the specified cell, compute the state in
	   the next generation using the rules
	   /* 2018-12-12
	   	1. Any live cell with fewer than two live neighbors dies, as if by underpopulation.
		2. Any live cell with two or three live neighbors lives on to the next generation.
		3. Any live cell with more than three live neighbors dies, as if by overpopulation.
		4. Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.

	   **
	   Use num_neighbors(x,y) to compute the number of live
	   neighbors */

	// 2018-12-12
	//get the current state
	int current_state = get_cell_state(x, y);
	int neighbors = num_neighbors(x, y);

	if(current_state == 1 && neighbors <2 ){
		set_dead(x, y);
	}
	else if(current_state == 1 && neighbors >= 2 && neigbors <= 3){
		set_alive(x, y);
	}
	else if(current_state == 1 && neigbors >3){
		set_dead(x, y);
	}
	else if(current_state == 0 && neighbors == 3){
		set_alive(x, y);
	}
}

int num_neighbors(int x, int y) {
	/* TODO: for the specified cell, return the number of
	   neighbors that are ALIVE

	   Use get_cell_state(x,y) */

}
