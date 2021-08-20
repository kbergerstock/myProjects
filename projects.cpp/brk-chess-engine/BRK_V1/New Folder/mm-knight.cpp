#include<iostream.h>

#include <stdio.h>

#include<conio.h>

#include <stdlib.h>



// these can all be adjusted if desired

const int start_x = 10, start_y = 2;   // upper-left corner of grid

const int x_width = 5;  // x width of each square (incl 1 border)

const int y_height = 3;  // y width of each square (incl 1 border)



void draw_grid();  // draw initial grid

void fill_in(const int , const int);   // fill in x,y square

int get_rand();  // returns random # between 1 and 8



int get_possible_moves(int x_val, int y_val,int n);  

int check_new_spots(int x_val,int y_val); // validate potential moves

int squares[9] [9];  //  this will keep track of landed on squares

int best_x = 0;  int best_y = 0; int best_n = 8;  // these vals get updated 

int moves[16];  // coords of all the possible 8 moves from a square



int main()

{

	clrscr();

	_setcursortype( 0 );

	srand(time(0));  /*initialize random number generator*/ 



// populate moves array, in pairs, these represent possible moves

   moves[0] = -2; moves[1] = 1; moves[2] = -2, moves[3] = -1; 

   moves[4] = -1; moves[5] = -2;  moves[6] = -1; moves[7] = +2;

   moves[8] = +1; moves[9] = -2; moves[10] = +1; moves[11] = +2;

   moves[12] = +2;moves[13] = -1; moves[14] = +2; moves[15] = +1;



//  draw grid and plot initial random position

	draw_grid();

	best_x = get_rand();

	best_y = get_rand();

	fill_in(best_x,best_y);

    squares[best_x][best_y] = 1;   // start from here

// end of initial setup 



  for (int p = 1; p<= 63 ;p++ )  // only 63 more squares

  {  int g = getchar();   // user hits a button to proceed

	  get_possible_moves(best_x,best_y,1);

	  fill_in(best_x,best_y);

      squares[best_x][best_y] = 1; best_n = 8; 	 

  }

  

//  end of program

	int g = getchar();

	_setcursortype( 1 );

	clrscr();

	return 0;

}



void draw_grid()  // I don't know why I did all these graphics

{

  // draw horizontal lines

	

	for (int y = start_y; y <= (start_y + ((y_height)*8 + 1)); y+= y_height)

	{

      gotoxy(start_x,y);

	  for (int x = 1; x <= ((x_width)*8+1) ;x++ )  // draw horizontal lines

	  	  cout<<"-";		

	}

	// draw vertical lines ( up and down )



	  for (y = start_y; y <= (start_y + ((y_height)*8))  ; y++)

	  {

		//  if this is a horizontal line then skip

		if (  (y - start_y) % (y_height) == 0  ) 	continue;

		

		gotoxy(start_x,y );



	     for (int x = 1; x <= ((x_width)*8+1) ; x+= x_width )  // draw vert lines

         {

	  	  cout<<"|";		

			for (int q=1; q<= (x_width - 1) ;q++ )

			  cout<<" ";

         }

	  }

}



void fill_in(const int x_val,const int y_val)  

	// fill in the square with  '*'s

{

  /*  figure out where to start filling from */



  int x_fill = start_x + 1 + (x_val -1)*(x_width);

  int y_fill = start_y + 1 + (y_val -1)*(y_height);



  for (int y = 1; y <= (y_height-1) ;y++ )

  {

      gotoxy(x_fill, y_fill);

	  for (int x = 1; x <= (x_width - 1) ;x++ )

	      cout<<"*";

	  y_fill++;

  }



}



int get_rand()  // returns random # between 1 and 8

{

  int M = 8;  /* user supplied upper boundary */ 

  return int(((double)rand() / (double)(RAND_MAX+1)) * M) + 1; 

}



int get_possible_moves(int x_val, int y_val,int n)

{

   if (n==3) return 0;  // only want to do two levels (1 parent, 1 child)

   int count = 0;

   int q = 0; int x = 0;int y = 0;





for (int move = 0 ; move <= 7; move++)  // possible 8 moves

{

    x = x_val + moves[move*2];   y = y_val + moves[move*2+1]; 



	 if (check_new_spots(x,y)  )

	 { 

		 count++; 

		 q = get_possible_moves( x, y , n+1);

		 if (q < best_n && n == 1) {best_n = q; best_x = x;best_y = y;}

	 }

}

	return count;  // this returns the number of valid moves

}  //  end of get_possible_moves 



int check_new_spots(x, y)  // *_val init pos  

{

//  check to make sure square is in the grid and not previously landed on

	

	if ( x >= 1 && x <= 8 && y >= 1 && y <= 8 && !squares[x][y])

	  return 1;

	return 0;

}









