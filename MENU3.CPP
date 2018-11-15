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
#include "BASIC2.CPP"
#include "ARTI2.CPP"

void quarto_menu();
void othello_menu();
void stars();
void menu();

void othello_rules()
{
        cleardevice();
        stars();
        settextstyle(2,0,5);
        setcolor(WHITE);

        outtextxy(30,50,"OTHELLO is a two player game. Each of the two sides corresponds to one player.");
        outtextxy(30,65,"They are referred to here as light and dark pieces.");

        outtextxy(30,85,"Othello's rules, which state that the game begins with four markers placed in");
        outtextxy(30,100,"a square in the middle of the grid, two light pieces, two dark pieces. ");
        outtextxy(30,115,"The dark player makes the first move.");

        outtextxy(30,135,"Dark must place a piece on the board, in such a position that");
        outtextxy(30,150,"there exists at least one straight (horizontal, vertical, or diagonal) line ");
        outtextxy(30,165,"between the new piece and another dark piece, with one or more continuous ");
        outtextxy(30,180,"light pieces between them.");

        outtextxy(30,200,"After placing the piece, all light pieces lying on a straight line between the");
        outtextxy(30,215,"new piece and any anchoring dark pieces.All reversed pieces now show the dark");
        outtextxy(30,230,"side, and dark can use them in later moves -- unless light has reversed them ");
        outtextxy(30,245,"back in the meantime.");

        outtextxy(30,265,"If dark decided to put a piece in the topmost location (all choices are");
        outtextxy(30,280,"strategically equivalent at this time), one piece gets turned over.");
	outtextxy(30,295,"Now light plays. This player operates under the same rules, with the roles");
        outtextxy(30,310,"reversed: light lays down a light piece, causing one or more dark pieces to ");
        outtextxy(30,325,"flip. ");

        outtextxy(30,330,"Players take alternate turns. If one player cannot make a valid move, ");
        outtextxy(30,345,"play passes back to the other player. When neither player can move, ");
        outtextxy(30,360,"the game ends. This occurs when the grid has filled up, or when one ");
        outtextxy(30,375,"player has no more pieces on the board, or when neither player can ");
        outtextxy(30,390,"legally place a piece in any of the remaining squares. The player with more ");
        outtextxy(30,405,"pieces on the board at the end wins.");
        getch();
        othello_menu();
}
void quarto_rules()
{
        cleardevice();
        stars();
        settextstyle(2,0,5);
        setcolor(WHITE);

	outtextxy(50,30,"Quarto is a board game for two players invented by Blaise Miller.");
        outtextxy(50,45,"It is played on a 4*4 board. There are 16 unique pieces,");
        outtextxy(50,60,"each of which has four attributes:");
	outtextxy(80,90,"1. large or small;");
        outtextxy(80,105,"2. red or blue (or some other pair of colors, such as light or dark stained wood");
	outtextxy(80,120,"3. square or circle");
	outtextxy(80,135,"4. hollow or solid.");
        outtextxy(80,165,"Players take turns to choose a piece which the other player must");
        outtextxy(50,180,"then place on the board. A player wins by placing their piece to");
        outtextxy(50,195,"make four pieces in a horizontal, vertical, or diagonal row, all");
        outtextxy(50,210,"of which have a common attribute (all small, all circular, etc).");
        outtextxy(50,225,"Quarto is distinctive in that there is only one set of common");
        outtextxy(50,240,"pieces, rather than a set for one player and a different set for");
        outtextxy(50,255,"the other.  ");
        getch();
        quarto_menu();
}

void quarto_menu()
{
	cleardevice();
        stars();

	setbkcolor(BLACK);
	setcolor(GREEN);
	settextstyle(1,0,4);
	outtextxy(150,30,"WELCOME TO QUARTO !!!");
        settextstyle(4,0,3);
	setcolor(DARKGRAY);

	int flag=0;
	rectangle(220,110,400,160);
        rectangle(230,120,390,150);
        setfillstyle(1,LIGHTGRAY);
        floodfill(221,111,DARKGRAY);

	setfillstyle(1,DARKGRAY);
	floodfill(231,125,DARKGRAY);

        setcolor(GREEN);
	outtextxy(260,117,"New Game");
        setcolor(DARKGRAY);

	rectangle(220,220,400,270);
        rectangle(230,230,390,260);
        setfillstyle(1,LIGHTGRAY);
        floodfill(221,221,DARKGRAY);

	setfillstyle(1,DARKGRAY);
	floodfill(231,231,DARKGRAY);

        setcolor(GREEN);
	outtextxy(270,227,"Rules");
        setcolor(DARKGRAY);

	rectangle(220,330,400,380);
        rectangle(230,340,390,370);
        setfillstyle(1,LIGHTGRAY);
        floodfill(221,331,DARKGRAY);

	setfillstyle(1,DARKGRAY);
	floodfill(231,341,DARKGRAY);

	setcolor(GREEN);
	outtextxy(275,339,"Exit");
        setcolor(DARKGRAY);

	do
	{
                flag=0;
		z.show_mouse();
		z.get_status();
		if((cx>220&&cx<400)&&(cy>110&&cy<160))
			{
				z.hide_mouse();
				quarto();
				flag=1;
			}

		if((cx>220&&cx<400)&&(cy>220&&cy<270))
			{
				z.hide_mouse();
				quarto_rules();
				flag=1;
			}
                if((cx>220&&cx<400)&&(cy>330&&cy<380))
                        {
                                exit(0);
                                flag=1;
                        }

	}while(flag==0);

}

void othello_menu()
{
        cleardevice();

        stars();
	setbkcolor(BLACK);
	setcolor(GREEN);
	settextstyle(1,0,4);
	outtextxy(150,30,"WELCOME TO OTHELLO !!!");
        settextstyle(4,0,3);
	setcolor(DARKGRAY);

	int flag=0;
	rectangle(220,90,400,140);
        rectangle(230,100,390,130);
        setfillstyle(1,LIGHTGRAY);
        floodfill(221,111,DARKGRAY);

	setfillstyle(1,DARKGRAY);
	floodfill(231,125,DARKGRAY);

        setcolor(GREEN);
	outtextxy(260,97,"1 Player");
        setcolor(DARKGRAY);

	rectangle(220,200,400,250);
        rectangle(230,210,390,240);
        setfillstyle(1,LIGHTGRAY);
	floodfill(221,221,DARKGRAY);

	setfillstyle(1,DARKGRAY);
	floodfill(231,231,DARKGRAY);

        setcolor(GREEN);
	outtextxy(270,207,"2 Players");
        setcolor(DARKGRAY);

	rectangle(220,310,400,360);
        rectangle(230,320,390,350);
        setfillstyle(1,LIGHTGRAY);
        floodfill(221,331,DARKGRAY);

	setfillstyle(1,DARKGRAY);
	floodfill(231,341,DARKGRAY);

	setcolor(GREEN);
	outtextxy(275,319,"Rules");
        setcolor(DARKGRAY);

	rectangle(220,410,400,460);
        rectangle(230,420,390,450);
        setfillstyle(1,LIGHTGRAY);
        floodfill(221,421,DARKGRAY);

	setfillstyle(1,DARKGRAY);
	floodfill(231,431,DARKGRAY);

	setcolor(GREEN);
	outtextxy(275,419,"Exit");
        setcolor(DARKGRAY);

	do
	{
                flag=0;
		z.show_mouse();
		z.get_status();

		if((cx>220&&cx<400)&&(cy>90&&cy<140))
			{
				z.hide_mouse();
				othello(1);
				flag=1;
			}

		if((cx>220&&cx<400)&&(cy>200&&cy<250))
			{
				z.hide_mouse();
				othello(2);
				flag=1;
			}
		if((cx>220&&cx<400)&&(cy>310&&cy<360))
                        {
                                z.hide_mouse();
                                othello_rules();
                                flag=1;
                        }
                if((cx>220&&cx<400)&&(cy>410&&cy<460))
                        {
                                z.hide_mouse();
                                exit(0);
                                flag=1;
                        }


	}while(flag==0);
}
void menu()
{
	setcolor(GREEN);
	settextstyle(1,0,4);
	outtextxy(150,30,"CHOOSE YOUR GAME!!!");
        settextstyle(4,0,3);
	setcolor(DARKGRAY);

	int flag=0;
	rectangle(220,110,400,160);
        rectangle(230,120,390,150);
        setfillstyle(1,LIGHTGRAY);
	floodfill(221,111,DARKGRAY);

	setfillstyle(1,DARKGRAY);
	floodfill(231,125,DARKGRAY);

        setcolor(GREEN);
	outtextxy(275,117,"Quarto");
        setcolor(DARKGRAY);

	rectangle(220,220,400,270);
        rectangle(230,230,390,260);
        setfillstyle(1,LIGHTGRAY);
        floodfill(221,221,DARKGRAY);

	setfillstyle(1,DARKGRAY);
	floodfill(231,231,DARKGRAY);

	setcolor(GREEN);
	outtextxy(275,227,"Othello");
        setcolor(DARKGRAY);

	rectangle(220,330,400,380);
        rectangle(230,340,390,370);
        setfillstyle(1,LIGHTGRAY);
        floodfill(221,331,DARKGRAY);

	setfillstyle(1,DARKGRAY);
	floodfill(231,341,DARKGRAY);

        setcolor(GREEN);
	outtextxy(285,339,"Exit");
        setcolor(DARKGRAY);

	do
	{
                flag=0;
		z.show_mouse();
		z.get_status();
		if((cx>220&&cx<400)&&(cy>110&&cy<160))
			{
				z.hide_mouse();
				quarto_menu();
				flag=1;
			}

		if((cx>220&&cx<400)&&(cy>220&&cy<270))
			{
				z.hide_mouse();
				othello_menu();
				flag=1;
			}
                if((cx>220&&cx<400)&&(cy>330&&cy<380))
                        {
                                exit(0);
                                flag=1;
                        }

	}while(flag==0);
        getch();
}

int x;
int y;
int col;

void stars()
{
        randomize();
        int i =0;
        randomize();

        for( ;i<=1000; i++)
        {
                x = 1+random(640);

                y = 1+random(480);

		col = 1+random(15);

		setcolor(col);
		circle(x,y,1);
		setfillstyle(1,col);
		floodfill(x,y,col);
	}
}

void main()
{

	int driver =9, mode=2;
	initgraph( &driver, &mode, "E:\\tc\\bgi");

        cleardevice();

        randomize();
        stars();


	menu();

	getch();


}
