/*
 * lab4-task1.c
 *
 *  Modified on: 2018-12-15
 *      Author: Marcus Lauren Andersson mala0377
 */

#include <stdio.h>

/* include helper functions for game */
#include "lifegame.h"

/* add whatever other includes here */
#include "lifegame.c"

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

int main()
{
	int n;

	/* TODO: initialize the world by hard-coded function initialize_world()
	 in lifegame.c*/
	initialize_world();
	
	/* Print the first world after initialize, a glider.. */
	output_world();
	
	/* evolutions*/

	for (n = 0; n < NUM_GENERATIONS; n++) {
		next_generation();   /* TODO:  his function is not complete,
                            you need to implement it*/

		/* TODO: output the world state to console,
		you need to call a given function */
		output_world();

		/* TODO: let the program pause,
        until you press ENTER key to continue ==> call getchar( )*/
		getchar();
	}


	return 0;
}

void next_generation(void) {
	/* TODO: for every cell, set the state in the next
	   generation according to the Game of Life rules
	   -- done as of 2018-12-12

	   Hint: use get_next_state(x,y) */

	   /* loop through each coordinate to get next state for each.
	   set x and y to loop through each point
	   */
	   int WIDTH = get_world_width();
	   int HEIGHT = get_world_height();

	   int x, y;
	   for(x = 1; x < WIDTH; x++){
		   for(y = 1; y < HEIGHT; y++){
			   get_next_state(x, y);
		   }
	   }
	   /**/

	finalize_evolution(); /* called at end to finalize / print */
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
	int proximity;
	proximity = num_neighbors(x, y);

	if(current_state == 1 && proximity <2 ){
		set_dead(x, y);
	}
	else if(current_state == 1 && proximity >= 2 && proximity <= 3){
		set_alive(x, y);
	}
	else if(current_state == 1 && proximity >3){
		set_dead(x, y);
	}
	else if(current_state == 0 && proximity == 3){
		set_alive(x, y);
	}
	else {
		set_dead(x, y);
	}
}

int num_neighbors(int x, int y) {
	/* TODO: for the specified cell, return the number of
	   neighbors that are ALIVE

	   Use get_cell_state(x,y) */
	int sum = 0;
	/* need to verify the cells around (x,y):
	[x-1,y-1] [x, y-1] [x+1,y-1]
	[x-1,y]   [x,y]   [x+1,y]
	[x-1,y+1] [x, y+1] [x+1,y+1]

	[-1, -1] [0, -1] [1, -1]
	[-1,  0] [0,  0] [1,  0]
	[-1,  1] [0 , 1] [1,  1]
	[0,0], is the cell being in focus, verifying the surrounding cells
			whether they are dead or alive. therefore, looping through
			-1..1 for x and y, will cover the above 9 cells. Summing them
			up and subtract state of 0,0 will get the number of alive neighbors.
	*/

	for(int i = -1;i<2;i++){
		for(int j = -1;j<2;j++){
            sum += get_cell_state(x+i, y+j);
		}
	}
	sum -= get_cell_state(x,y);
    /* there is currently no check for out of bounds. */
	return sum;

}