#include <fstream.h>
#include <math.h>
#include <conio.h>
#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>
#include <alloc.h>
#include <ctype.h>
#include <string.h>
#include <dos.h>
#include <time.h>

mouse z;

void click_coin1(); // The function that accepts the click
void black_circle(int,int); // To draw the Black Coin
void white_circle(int,int); // To draw the white circle

int  board1[8][8] ={0}; // Represents the 8*8 board....
int  a[8] = {0}; // The 8 positions surrounding the coin..
int  k,j; // For using in all the loops. Dummy variable to save memory..
int  m,n; // Variables used to traverse the board. Saves memory.

int  aboard[8][8]; // A:I Board
int  moveselector[64][8][8]; // Position of every possible move
int  check1[64]; // Holds value for 64 moves or less

int check_black(int, int);
int check_white(int, int);

int player = 0;

void result()
{
	int whitecount=0; // Counts all the white coins
	int blackcount=0; // Counts all the black coins

	for(int o=0; o<=7; o++)
	{
	        for(int p=0; p<=7; p++)
		{
		        if(board1[o][p] == 1)
			whitecount++;

			else if(board1[o][p] == 2)
			blackcount++;
		}
	}

	setcolor(WHITE);
	setfillstyle(1,4);
	bar(495,210,620,235);
	bar(495,410,620,435);


	if(blackcount > whitecount ) outtextxy(495,210,"YOU WIN");

	else if(whitecount > blackcount) outtextxy(495,410,"YOU WIN");

	else
	{
	        outtextxy(495,210,"DRAWN");
		outtextxy(495,410,"DRAWN");
	}

}

int zerocheck(int move)
{
        int nozero = 0;
        for(int i=0; i<8; i++)
        {
                for(int j=0; j<8; j++)
                {
                        if(moveselector[move][i][j] != 0)
                        nozero = 1;
                }
	}
        return nozero;
}

void artificial(int turn)
{
        int     flag = 0; // To check for legal moves

        for( k=0; k<8; k++)
        {
		for(j=0; j<8; j++)
                {
                        aboard[k][j] = board1[k][j];
                }
        }

	int whitecount=0; // Counts all the white coins
	int blackcount=0; // Counts all the black coins
	int counter=0;  // Counter used to store  each move in moveselector
	int playcheck = 0;

	for( int k=0; k<8; k++)
	{
		for(int j=0; j<8; j++)
		{
			flag = 0;

			if(turn ==1)
			{
				if( board1[k][j] == 0)
				{
					flag = check_black(k,j);
				}
			}

			else if(turn == -1)
			{
				if( board1[k][j] == 0)
				{
					flag = check_white(k,j);
				}
			}

			if( flag == 1)
			{
				playcheck = 1;
				m=0; n=0;

				if(turn == 1)
				{
					m=k-1;
					n=j-1; // Left Top Diagonal

					if( a[0] == -1)
					{
						for(;(aboard[m][n]!=2 && aboard[m][n]!=0) && (m>=0 && n>=0) && (m<=7 && n<=7); m--, n--)
						{
							aboard[m][n] = 2;
						}
					}

					m=k;
					n=j-1;  // top position

					if( a[1] == -1)
					{
						for(;(aboard[m][n]!=2 && aboard[m][n]!=0) && (m>=0 && n>=0) && (m<=7 && n<=7); n--)
						{
							aboard[m][n] = 2;
						}
					}

					m=k+1;
					n=j-1;  // Right top diagonal position

					if( a[2] == -1 )
					{
						for(;(aboard[m][n]!=2 && aboard[m][n]!=0) && (m>=0 && n>=0) && (m<=7 && n<=7); m++,n--)
						{
							aboard[m][n] = 2;
						}
					}

					m=k-1;
					n=j; // Left Position

					if( a[3] == -1)
					{
						for(;(aboard[m][n]!=2 && aboard[m][n]!=0) && (m>=0 && n>=0) && (m<=7 && n<=7); m--)
						{
							aboard[m][n] = 2;
						}
					}

					m=k+1;
					n=j;  // Right Position

					if( a[4] == -1)
					{
						for(;(aboard[m][n]!=2 && aboard[m][n]!=0) && (m>=0 && n>=0) && (m<=7 && n<=7); m++)
						{

							aboard[m][n] = 2;
						}
					}

					m=k-1;
					n=j+1; // Left Bottom Diagonal

					if( a[5] == -1)
					{
						for(;(aboard[m][n]!=2 && aboard[m][n]!=0) && (m>=0 && n>=0) && (m<=7 && n<=7); m--, n++)
						{
							aboard[m][n] = 2;
						}
					}

					m=k;
					n=j+1; // Bottom Position

					if( a[6] == -1)
					{
						for(;(aboard[m][n]!=2 && aboard[m][n]!=0) && (m>=0 && n>=0) && (m<=7 && n<=7); n++)
						{
							aboard[m][n] = 2;
						}
					}

					m=k+1;
					n=j+1; // Right Bottom Diagonal

					if( a[7] == -1)
					{
						for(;(aboard[m][n]!=2 && aboard[m][n]!=0) && (m>=0 && n>=0) && (m<=7 && n<=7); m++,n++)
						{
							aboard[m][n] = 2;
						}
					}

					aboard[k][j] = 2;
				}

				if( turn == -1)
				{
					m=k-1;
					n=j-1; // Left Top Diagonal

					if( a[0] == -1)
					{
						for(;(aboard[m][n]!=1 && aboard[m][n]!=0) && (m>=0 && n>=0) && (m<=7 && n<=7); m--, n--)
						{

							aboard[m][n] = 1;
						}
					}

					m=k;
					n=j-1;  // top position

					if( a[1] == -1)
					{
						for(;(aboard[m][n]!=1 && aboard[m][n]!=0) && (m>=0 && n>=0) && (m<=7 && n<=7); n--)
						{
							aboard[m][n] = 1;
						}
					}

					m=k+1;
					n=j-1;  // Right top diagonal position

					if( a[2] == -1 )
					{
						for(;(aboard[m][n]!=1 && aboard[m][n]!=0) && (m>=0 && n>=0) && (m<=7 && n<=7); m++,n--)
						{
							aboard[m][n] = 1;
						}
					}

					m=k-1;
					n=j; // Left Position

					if( a[3] == -1)
					{
						for(;(aboard[m][n]!=1 && aboard[m][n]!=0) && (m>=0 && n>=0) && (m<=7 && n<=7); m--)
						{
							aboard[m][n] = 1;
						}
					}

					m=k+1;
					n=j;  // Right Position

					if( a[4] == -1)
					{
						for(;(aboard[m][n]!=1 && aboard[m][n]!=0) && (m>=0 && n>=0) && (m<=7 && n<=7); m++)
						{

							aboard[m][n] = 1;
						}
					}

					m=k-1;
					n=j+1; // Left Bottom Diagonal

					if( a[5] == -1)
					{
						for(;(aboard[m][n]!=1 && aboard[m][n]!=0) && (m>=0 && n>=0) && (m<=7 && n<=7); m--, n++)
						{
							aboard[m][n] = 1;
						}
					}

					m=k;
					n=j+1; // Bottom Position

					if( a[6] == -1)
					{
						for(;(aboard[m][n]!=1 && aboard[m][n]!=0) && (m>=0 && n>=0) && (m<=7 && n<=7); n++)
						{
							aboard[m][n] = 1;
						}
					}

					m=k+1;
					n=j+1; // Right Bottom Diagonal

					if( a[7] == -1)
					{
						for(;(aboard[m][n]!=1 && aboard[m][n]!=0) && (m>=0 && n>=0) && (m<=7 && n<=7); m++,n++)
						{
							aboard[m][n] = 1;
						}
					}
					aboard[k][j] = 1;
				}

				// -- End of inserting all the coins -- //
				if(playcheck == 1)
				{
					for( int o=0; o<8; o++)
					{
						for( int p=0; p<8; p++)
						{
							if( aboard[o][p] == 1)
							whitecount++;

							else if( aboard[o][p] == 2)
							blackcount++;
						}
					}


					if(turn == 1)
					{
						check1[counter] = blackcount;

						for(int o=0; o<8; o++)
						{
							for(int p=0; p<8; p++)
							{
								moveselector[counter][o][p] = aboard[o][p];
							}
						}
						counter++;
					}

					else if(turn == -1)
					{
						check1[counter] = whitecount;

						for(int o=0; o<8; o++)
						{
							for(int p=0; p<8; p++)
							{
								moveselector[counter][o][p] = aboard[o][p];
							}
						}
						counter++;
					}
				}
			}

			// End of the Flag Statement
			playcheck = 0;

			for(int o=0; o<8; o++)
			{
				a[o] = 0;
			}

			for( int u=0; u<8; u++)
			{
				for(int v=0; v<8; v++)
				{
					aboard[u][v] = board1[u][v];
				}
			}

			whitecount = 0;
			blackcount = 0;
		}
	}

	counter = 0;
	int highest = 0;
        int move = 0;
        int nozero = 0;

	// Maximum and minimum of an array!!

	for( k=0; k<64; k++)
	{
		if(k == 0) highest = check1[k];

		else if((check1[k] >= highest) && check1[k]!=0)
		{
                        move=k;
                        nozero = zerocheck(move);

                        if(nozero == 1)
			highest = check1[k];
		}
	}

        if(highest != 0)
        {
	        for(int o=0; o<8; o++)
	        {
			for(int p=0; p<8; p++)
		        {
			        board1[o][p] = moveselector[move][o][p];
			}
	        }


	        for( int h=0; h<64; h++)
	        {
		        check1[h] = 0;
		}

	        for(int q=0; q<64; q++)
	        {
		        for(int w=0; w<8; w++)
		        {
			        for(int e=0; e<8; e++)
			        {
				        moveselector[q][w][e] = 0;
			        }
			}
	        }

		int x1,x2,y1,y2;
	        int c1,c2;

	        for( q=0; q<8; q++)
	        {
		        for( int w=0; w<8; w++)
		        {
				if(board1[q][w] == 1)
			        {
				        x1 =(50*q)+50;
				        x2 = x1+50;

				        y1 =(50*w)+50;
				        y2 = y1+50;

				        c1 = (x1+x2)/2;
				        c2 = (y1+y2)/2;

				        white_circle(c1,c2);
			        }

			        else if(board1[q][w] == 2)
			        {

				        x1 = (50*q)+50;
				        x2 = x1+50;

					y1 = (50*w)+50;
				        y2 = y1+50;

				        c1 = (x1+x2)/2;
				        c2 = (y1+y2)/2;

				        black_circle(c1,c2);
			        }
		        }
	        }
	}

        else result();
}

void draw()
{

	// The background
	setcolor(WHITE);
	rectangle(-1,-1,getmaxx()+1, getmaxy()+1);
	setfillstyle(1,8);
	floodfill(10,10,15);
	setfillstyle(1,2);

	// The 8*8 board
	for( int x=50; x<=400; x=x+50)
	{
		for( int y=50; y<=400; y=y+50)
		{
			rectangle(x,y,x+50,y+50);
			floodfill(x+10,y+10,15);
		}
	}

	// The first 4 coins
	white_circle(225,225);
	black_circle(225,275);
	black_circle(275,225);
	white_circle(275,275);

	board1[3][3] = board1[4][4] = 1;   // initialising the board
	board1[3][4] = board1[4][3] = 2;   // Initialising the board

	// The Players Panel
	rectangle(475,50,625,450);
	line(475,250,625,250);

	setfillstyle(1,4);
	floodfill(480,55,15);
	floodfill(480,255,15);

	settextstyle(4,0,4);
	outtextxy(495,60,"Player 1");
	black_circle(545,135);

	setcolor(WHITE);
	outtextxy(495,260,"Player 2");
	white_circle(545,335);

	setfillstyle(1,0);
	rectangle(475,5,625,45);
	floodfill(500,10,15);
	setcolor(RED);
	settextstyle(3,0,4);
	outtextxy(520,5,"EXIT");

}

void othello(int plr)
{

	int driver =9, mode=2;
	initgraph( &driver, &mode, "C:\\tc\\bgi");

        player = plr;

	draw();  // To draw the basic Board

	click_coin1(); // The Game function

	do
	{
		z.get_status();

		if((cx>=475 && cx<=625) && (cy>=5 && cy<=45))
		exit(0);

	}while(7);  // To exit the game

	getch(); // Bye - Bye
}

void black_circle(int x, int y)
{
	z.hide_mouse();
	setcolor(BLACK);
	circle(x,y,20);
	setfillstyle(1,0);
	floodfill(x,y,0);
	z.show_mouse();
}

void white_circle(int x, int y)
{
	z.hide_mouse();
	setcolor(WHITE);
	circle(x,y,20);
	setfillstyle(1,15);
	floodfill(x,y,15);
	z.show_mouse();
}

int check_black(int i, int j)   // Black coins turn to check if there is a white surrounding it
{
	m=i-1;
	n=j-1;   // Left top diagonal position

	if( board1[m][n] == 1)
	{
		for(;(board1[m][n]!=2 && board1[m][n]!=0) && (m>=0 && n>=0) && (m<=7 && n<=7); m--, n--);
		if(board1[m][n]==2 && (m>=0&&n>=0)&&(m<=7&&n<=7)) a[0] = -1;
		else a[0] = 0;
	}

	m=i;
	n=j-1;  // top position

	if( board1[m][n] == 1)
	{
		for(;(board1[m][n]!=2 && board1[m][n]!=0) && (m>=0 && n>=0) && (m<=7 && n<=7); n--);
		if(board1[m][n]==2 && (m>=0&&n>=0)&&(m<=7&&n<=7)) a[1] = -1;
		else a[1] = 0;
	}

	m=i+1;
	n=j-1;  // Right top diagonal position

	if( board1[m][n] == 1 )
	{
		for(;(board1[m][n]!=2 && board1[m][n]!=0) && (m>=0 && n>=0) && (m<=7 && n<=7); m++,n--);
		if(board1[m][n]==2 && (m>=0&&n>=0)&&(m<=7&&n<=7)) a[2] = -1;
		else a[2] = 0;
	}

	m=i-1;
	n=j; // Left Position

	if( board1[m][n] == 1)
	{
		for(;(board1[m][n]!=2 && board1[m][n]!=0) && (m>=0 && n>=0) && (m<=7 && n<=7); m--);
		if(board1[m][n]==2 && (m>=0&&n>=0)&&(m<=7&&n<=7)) a[3] = -1;
		else a[3] = 0;
	}

	m=i+1;
	n=j;  // Right Position

	if( board1[m][n] == 1)
	{
		for(;(board1[m][n]!=2 && board1[m][n]!=0) && (m>=0 && n>=0) && (m<=7 && n<=7); m++);
		if(board1[m][n]==2 && (m>=0&&n>=0)&&(m<=7&&n<=7)) a[4] = -1;
		else a[4] = 0;
	}

	m=i-1;
	n=j+1; // Left Bottom Diagonal

	if( board1[m][n] == 1)
	{
		for(;(board1[m][n]!=2 && board1[m][n]!=0) && (m>=0 && n>=0) && (m<=7 && n<=7); m--,n++);
		if(board1[m][n]==2 && (m>=0&&n>=0)&&(m<=7&&n<=7)) a[5] = -1;
		else a[5] = 0;
	}

	m=i;
	n=j+1; // Bottom Position

	if( board1[m][n] == 1)
	{
		for(;(board1[m][n]!=2 && board1[m][n]!=0) && (m>=0 && n>=0) && (m<=7 && n<=7); n++);
		if(board1[m][n]==2 && (m>=0&&n>=0)&&(m<=7&&n<=7)) a[6] = -1;
		else a[6] = 0;
	}

	m=i+1;
	n=j+1; // Right Bottom Diagonal

	if( board1[m][n] == 1)
	{
		for(;(board1[m][n]!=2 && board1[m][n]!=0) && (m>=0 && n>=0) && (m<=7 && n<=7); m++,n++);
		if(board1[m][n]==2 && (m>=0&&n>=0)&&(m<=7&&n<=7)) a[7] = -1;
		else a[7] = 0;
	}

	for( int k=0; k<=7; k++)
	{
		if(a[k] == -1) return 1;
	}

	return 0;
}

int check_white(int i, int j)     // White coins turn to check if there is a black surrounding it
{

	m=i-1;
	n=j-1;   // Left top diagonal position

	if( board1[m][n] == 2)
	{
		for(;(board1[m][n]!=1 && board1[m][n]!=0) && (m>=0 && n>=0) && (m<=7 && n<=7); m--, n--);
		if(board1[m][n]==1 && (m>=0&&n>=0)&&(m<=7&&n<=7)) a[0] = -1;
		else a[0] = 0;
	}

	m=i;
	n=j-1;  // top position

	if( board1[m][n] == 2)
	{
		for(;(board1[m][n]!=1 && board1[m][n]!=0) && (m>=0 && n>=0) && (m<=7 && n<=7); n--);
		if(board1[m][n]==1 && (m>=0&&n>=0)&&(m<=7&&n<=7)) a[1] = -1;
		else a[1] = 0;
	}


	m=i+1;
	n=j-1;  // Right top diagonal position

	if( board1[m][n] == 2 )
	{
		for(;(board1[m][n]!=1 && board1[m][n]!=0) && (m>=0 && n>=0) && (m<=7 && n<=7); m++,n--);
		if(board1[m][n]==1 && (m>=0&&n>=0)&&(m<=7&&n<=7)) a[2] = -1;
		else a[2] = 0;
	}

	m=i-1;
	n=j; // Left Position

	if( board1[m][n] == 2)
	{
		for(;(board1[m][n]!=1 && board1[m][n]!=0) && (m>=0 && n>=0) && (m<=7 && n<=7); m--);
		if(board1[m][n]==1 && (m>=0&&n>=0)&&(m<=7&&n<=7)) a[3] = -1;
		else a[3] = 0;
	}

	m=i+1;
	n=j;  // Right Position

	if( board1[m][n] == 2)
	{
		for(;(board1[m][n]!=1 && board1[m][n]!=0) && (m>=0 && n>=0) && (m<=7 && n<=7); m++);
		if(board1[m][n]==1 && (m>=0&&n>=0)&&(m<=7&&n<=7)) a[4] = -1;
		else a[4] = 0;
	}

	m=i-1;
	n=j+1; // Left Bottom Diagonal

	if( board1[m][n] == 2)
	{
		for(;(board1[m][n]!=1 && board1[m][n]!=0) && (m>=0 && n>=0) && (m<=7 && n<=7); m--, n++);
		if(board1[m][n]==1 && (m>=0&&n>=0)&&(m<=7&&n<=7)) a[5] = -1;
		else a[5] = 0;
	}

	m=i;
	n=j+1; // Bottom Position

	if( board1[m][n] == 2)
	{
		for(;(board1[m][n]!=1 && board1[m][n]!=0) && (m>=0 && n>=0) && (m<=7 && n<=7); n++);
		if(board1[m][n]==1 && (m>=0&&n>=0)&&(m<=7&&n<=7)) a[6] = -1;
		else a[6] = 0;
	}

	m=i+1;
	n=j+1; // Right Bottom Diagonal

	if( board1[m][n] == 2)
	{
		for(;(board1[m][n]!=1 && board1[m][n]!=0) && (m>=0 && n>=0) && (m<=7 && n<=7); m++,n++);
		if(board1[m][n]==1 && (m>=0&&n>=0)&&(m<=7&&n<=7)) a[7] = -1;
		else a[7] = 0;
	}

	for( k=0; k<8; k++)
	{
		if(a[k] == -1) return 1;
	}

	return 0;
}

int update_board(int x, int y, int turn, int i, int j)
{

	int x1,y1;
	int x2,y2;
	int c1,c2;
	int flag;

	if( turn == 1)
	{
		flag = check_black(i,j);

		// Draw all the coins

		if( flag==1)
		{
			m=i-1;
			n=j-1; // Left Top Diagonal

			if( a[0] == -1)
			{
				for(;(board1[m][n]!=2 && board1[m][n]!=0) && (m>=0 && n>=0) && (m<=7 && n<=7); m--, n--)
				{
					x1=(50*m)+50;
					x2=x1+50;

					c1=(x1+x2)/2;

					y1=(50*n)+50;
					y2=y1+50;

					c2=(y1+y2)/2;

					black_circle(c1,c2);

					board1[m][n] = 2;
				}
			}

			m=i;
			n=j-1;  // top position

			if( a[1] == -1)
			{
				for(;(board1[m][n]!=2 && board1[m][n]!=0) && (m>=0 && n>=0) && (m<=7 && n<=7); n--)
				{
					x1=(50*m)+50;
					x2=x1+50;

					c1=(x1+x2)/2;

					y1=(50*n)+50;
					y2=y1+50;

					c2=(y1+y2)/2;

					black_circle(c1,c2);

					board1[m][n] = 2;
				}
			}

			m=i+1;
			n=j-1;  // Right top diagonal position

			if( a[2] == -1 )
			{
				for(;(board1[m][n]!=2 && board1[m][n]!=0) && (m>=0 && n>=0) && (m<=7 && n<=7); m++,n--)
				{
					x1=(50*m)+50;
					x2=x1+50;

					c1=(x1+x2)/2;

					y1=(50*n)+50;
					y2=y1+50;

					c2=(y1+y2)/2;

					black_circle(c1,c2);

					board1[m][n] = 2;
				}
			}

			m=i-1;
			n=j; // Left Position

			if( a[3] == -1)
			{
				for(;(board1[m][n]!=2 && board1[m][n]!=0) && (m>=0 && n>=0) && (m<=7 && n<=7); m--)
				{
					x1=(50*m)+50;
					x2=x1+50;

					c1=(x1+x2)/2;

					y1=(50*n)+50;
					y2=y1+50;

					c2=(y1+y2)/2;

					black_circle(c1,c2);
					board1[m][n] = 2;
				}
			}

			m=i+1;
			n=j;  // Right Position

			if( a[4] == -1)
			{
				for(;(board1[m][n]!=2 && board1[m][n]!=0) && (m>=0 && n>=0) && (m<=7 && n<=7); m++)
				{
					x1=(50*m)+50;
					x2=x1+50;

					c1=(x1+x2)/2;

					y1=(50*n)+50;
					y2=y1+50;

					c2=(y1+y2)/2;

					black_circle(c1,c2);
					board1[m][n] = 2;
				}
			}

			m=i-1;
			n=j+1; // Left Bottom Diagonal

			if( a[5] == -1)
			{
				for(;(board1[m][n]!=2 && board1[m][n]!=0) && (m>=0 && n>=0) && (m<=7 && n<=7); m--, n++)
				{
					x1=(50*m)+50;
					x2=x1+50;

					c1=(x1+x2)/2;

					y1=(50*n)+50;
					y2=y1+50;

					c2=(y1+y2)/2;

					black_circle(c1,c2);
					board1[m][n] = 2;
				}
			}

			m=i;
			n=j+1; // Bottom Position

			if( a[6] == -1)
			{
				for(;(board1[m][n]!=2 && board1[m][n]!=0) && (m>=0 && n>=0) && (m<=7 && n<=7); n++)
				{
					x1=(50*m)+50;
					x2=x1+50;

					c1=(x1+x2)/2;

					y1=(50*n)+50;
					y2=y1+50;

					c2=(y1+y2)/2;

					black_circle(c1,c2);
					board1[m][n] = 2;
				}
			}

			m=i+1;
			n=j+1; // Right Bottom Diagonal

			if( a[7] == -1)
			{
				for(;(board1[m][n]!=2 && board1[m][n]!=0) && (m>=0 && n>=0) && (m<=7 && n<=7); m++,n++)
				{
					x1=(50*m)+50;
					x2=x1+50;

					c1=(x1+x2)/2;

					y1=(50*n)+50;
					y2=y1+50;

					c2=(y1+y2)/2;

					black_circle(c1,c2);
					board1[m][n] = 2;
				}
			}

			board1[i][j] = 2;
			black_circle(x,y);

			return 1;

		}

		else
		{
			sound(1098);
			delay(250);
			nosound();
		}

	}


	else if( turn == -1)
	{
		flag = check_white(i,j);

		// Now draw all the other coins...

		if( flag==1)
		{
			m=i-1;
			n=j-1; // Left Top Diagonal

			if( a[0] == -1)
			{
				for(;(board1[m][n]!=1 && board1[m][n]!=0) && (m>=0 && n>=0) && (m<=7 && n<=7); m--, n--)
				{
					x1=(50*m)+50;
					x2=x1+50;

					c1=(x1+x2)/2;

					y1=(50*n)+50;
					y2=y1+50;

					c2=(y1+y2)/2;

					white_circle(c1,c2);
					board1[m][n] = 1;
				}
			}

			m=i;
			n=j-1;  // top position

			if( a[1] == -1)
			{
				for(;(board1[m][n]!=1 && board1[m][n]!=0) && (m>=0 && n>=0) && (m<=7 && n<=7); n--)
				{
					x1=(50*m)+50;
					x2=x1+50;

					c1=(x1+x2)/2;

					y1=(50*n)+50;
					y2=y1+50;

					c2=(y1+y2)/2;

					white_circle(c1,c2);
					board1[m][n] = 1;
				}
			}

			m=i+1;
			n=j-1;  // Right top diagonal position

			if( a[2] == -1 )
			{
				for(;(board1[m][n]!=1 && board1[m][n]!=0) && (m>=0 && n>=0) && (m<=7 && n<=7); m++,n--)
				{
					x1=(50*m)+50;
					x2=x1+50;

					c1=(x1+x2)/2;

					y1=(50*n)+50;
					y2=y1+50;

					c2=(y1+y2)/2;

					white_circle(c1,c2);
					board1[m][n] = 1;
				}
			}

			m=i-1;
			n=j; // Left Position

			if( a[3] == -1)
			{
				for(;(board1[m][n]!=1 && board1[m][n]!=0) && (m>=0 && n>=0) && (m<=7 && n<=7); m--)
				{
					x1=(50*m)+50;
					x2=x1+50;

					c1=(x1+x2)/2;

					y1=(50*n)+50;
					y2=y1+50;

					c2=(y1+y2)/2;

					white_circle(c1,c2);
					board1[m][n] = 1;
				}
			}

			m=i+1;
			n=j;  // Right Position

			if( a[4] == -1)
			{
				for(;(board1[m][n]!=1 && board1[m][n]!=0) && (m>=0 && n>=0) && (m<=7 && n<=7); m++)
				{
					x1=(50*m)+50;
					x2=x1+50;

					c1=(x1+x2)/2;

					y1=(50*n)+50;
					y2=y1+50;

					c2=(y1+y2)/2;

					white_circle(c1,c2);
					board1[m][n] = 1;
				}
			}

			m=i-1;
			n=j+1; // Left Bottom Diagonal

			if( a[5] == -1)
			{
				for(;(board1[m][n]!=1 && board1[m][n]!=0) && (m>=0 && n>=0) && (m<=7 && n<=7); m--, n++)
				{
					x1=(50*m)+50;
					x2=x1+50;

					c1=(x1+x2)/2;

					y1=(50*n)+50;
					y2=y1+50;

					c2=(y1+y2)/2;

					white_circle(c1,c2);
					board1[m][n] = 1;
				}
			}

			m=i;
			n=j+1; // Bottom Position

			if( a[6] == -1)
			{
				for(;(board1[m][n]!=1 && board1[m][n]!=0) && (m>=0 && n>=0) && (m<=7 && n<=7); n++)
				{
					x1=(50*m)+50;
					x2=x1+50;

					c1=(x1+x2)/2;

					y1=(50*n)+50;
					y2=y1+50;

					c2=(y1+y2)/2;

					white_circle(c1,c2);
					board1[m][n] = 1;
				}
			}

			m=i+1;
			n=j+1; // Right Bottom Diagonal

			if( a[7] == -1)
			{
				for(;(board1[m][n]!=1 && board1[m][n]!=0) && (m>=0 && n>=0) && (m<=7 && n<=7); m++,n++)
				{
					x1=(50*m)+50;
					x2=x1+50;

					c1=(x1+x2)/2;

					y1=(50*n)+50;
					y2=y1+50;

					c2=(y1+y2)/2;

					white_circle(c1,c2);
					board1[m][n] = 1;
				}
			}


			board1[i][j] = 1;
			white_circle(x,y);

			return 1;

			// Now draw all the other coins...
		}
		else
		{
			sound(1098);
			delay(250);
			nosound();
		}
	}


}

void points()
{
	int blackcount = 0;
	int whitecount = 0;
	char points[20];

	setcolor(RED);
	setfillstyle(1,4);
	bar(560,375,590,405);
	bar(560,175,590,205);

	for( k=0; k<=7; k++)
	{
		for( j=0; j<=7; j++)
		{
			if(board1[k][j] == 1)
			whitecount++;

			else if(board1[k][j] == 2)
			blackcount++;
		}
	}

	settextstyle(4,0,2);

	setcolor(WHITE);
	outtextxy(495,175,"Points: ");
	itoa(blackcount,points,10);
	outtextxy(560,175,points);

	outtextxy(495,375,"Points: ");
	itoa(whitecount,points,10);
	outtextxy(560,375,points);

}

void click_coin1()
{
	z.show_mouse();

	int  	turn = 1; // Alternates turns between black and white
	int     p = 0; // For checking when to print YOUR TURN
	int 	win = 0; // Checks Victory
	int 	i,j; // position of where mouse if clicked
	int 	c1,c2; // coordinates of the centre of the clicked position
	int 	turncheck; // Checks if turn is played

	points();

	do
	{

		if(p == 0)
		{
			z.hide_mouse();
			settextstyle(4,0,2);
			setcolor(WHITE);
			setfillstyle(1,4);
			bar(495,210,620,235);
			bar(495,410,620,435);

			if(turn == 1 )
			{
				outtextxy(495,210,"YOUR TURN");
			}

			else if(turn == -1)
			{
				outtextxy(495,410,"YOUR TURN");
			}

			z.show_mouse();
		}

		z.get_status();

		if((cx>=475 && cx<=625) && (cy>=5 && cy<=45))
		exit(0);

		for( int x1=50, x2=100; x2<=450; x1=x1+50, x2=x2+50)
		{
			for ( int y1=50, y2=100; y2<=450; y1=y1+50, y2=y2+50)
			{
				if((cx>=x1 && cx<=x2) && (cy>=y1&&cy<=y2))
				{

					i = (x1-50)/50 ; j = (y1-50)/50;

					if(board1[i][j] == 0)
					{

						c1=(x1+x2)/2;
						c2=(y1+y2)/2;

						turncheck = update_board(c1,c2,turn,i,j);

						for( int k=0; k<=7; k++)    // To revert it back to 0
						{
							a[k] = 0;
						}

						if(turncheck == 1)
						{

							turn = -turn;

                                                        if(player == 1)
                                                        {
							        delay(500);
							        artificial(turn);
							        points();
							        turn = -turn;
							        p=0;
                                                        }

                                                        else if(player == 2)
                                                        {
                                                                points();
                                                                p=0;
                                                        }
						}

						else p=1;
					}
				}
			}
		}

		int searcheck = 0;  // Searches for legal moves.
		int movecount = 0;  // No. of legal moves per turn..

		for(int o=0; o<=7; o++)
		{
			for(int p=0; p<=7; p++)
			{
				if(board1[o][p]==0)
				{
					if(turn == -1)
					searcheck = check_white(o,p);

					else searcheck = check_black(o,p);

					if(searcheck == 1)
					movecount++;

					for( int k=0; k<=7; k++)    // To revert it back to 0
					{
						a[k] = 0;
					}
				  }
			}
		}

		int blackcount=0; // No. of Black Points
		int whitecount=0; // No. of White points

		if(movecount == 0)
		{
			win =1;
			result();
			sound(1098);
			sound(1099);
			sound(1110);
			nosound();
		}

	} while(win==0);
}