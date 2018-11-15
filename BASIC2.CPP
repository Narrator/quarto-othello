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

int      coin; // Represents each coin. holds the value of each coin..
int      cerror = 0;  // to check if coin is in the position or not..
int      terror[16]={0}; // to check initial position of coin..
int      x1,y1,x2,y2; // Co-ordinates of original position of each coin..
int      turn = -1; // Alternates between player 1 and player 2
void     *p; // Used for getimage
int      size; // holds size of image in getimage
int      check(); // To check if won or not
int      board[4][4]; // Represents the board
int      flag=0; // Used for some checking conditions
int      win=0; // Variable for the main game
int      e; // To calculate HCF
int      che[4]; // copies value of each row, array, diagonal to calc HCF

int cx,cy,v;

class mouse
{
		REGS regs;
		int no_buttons;
	public:
		void show_mouse();
		void get_status();
		void hide_mouse();
		mouse()
		{
			regs.x.ax=0;
			int86(0x33,&regs,&regs);
			if(regs.x.ax==0xfff)no_buttons=regs.x.bx;
			//cout<<"Error initializing mouse";
		}
};
		void mouse::show_mouse()
		{
			regs.x.ax=0x01;
			int86(0x33,&regs,&regs);
		}
		void mouse::hide_mouse()
		{
			regs.x.ax=0x02;
			int86(0x33,&regs,&regs);
		}
		void mouse::get_status()
		{
			regs.x.ax=0x03;
			int86(0x33,&regs,&regs);
			while(v!=1)
			{
				regs.x.ax=0x03;
				int86(0x33,&regs,&regs);
				v=regs.x.bx;
				cx=regs.x.cx;
				cy=regs.x.dx;
			}
			v=0;
		}

                mouse q;

void draw_coins()
{

		// Drawing the tall coin
		setcolor(WHITE);
		ellipse( 100, 100, 0, 360, 7, 5);
		line(93,100,93,140);
		line(107,100,107,140);
		ellipse(100,140,180,0,7,3);
		setfillstyle(1,1);
		floodfill(100,100,15);
		floodfill(100,120,15);


		// Drawing it in the New Area - b
		size = imagesize(92,92,108,145);
		p = (char *)malloc(size);
		getimage(93,93,107,144,p);
		cleardevice();
		putimage(20,20,p,0);


                // Drawing the Red coin in the new area
                setcolor(WHITE);
                ellipse( 27, 100, 0, 360, 7, 5);
                line(20,100,20,140);
                line(34,100,34,140);
                ellipse(27,140,180,0,7,3);
                setfillstyle(1,4);
		floodfill(27,100,15);
                floodfill(27,120,15);


                // Drawing the blue coin with the hole
                putimage(50,20,p,0);
                circle(57,27,2);
                setfillstyle(1,15);
                floodfill(57,27,15);


		// Drawing the red coin with the hole
                setcolor(WHITE);
                ellipse( 57, 100, 0, 360, 7, 5);
                line(50,100,50,140);
                line(64,100,64,140);
                ellipse(57,140,180,0,7,3);
                setfillstyle(1,4);
                floodfill(57,100,15);
                floodfill(57,120,15);
		setfillstyle(1,15);
                circle(57,100,2);
                floodfill(57,100,15);


                // Drawing the smaller coin
                ellipse( 100, 100, 0, 360, 7, 5);
                line(93,100,93,120);
                line(107,100,107,120);
		ellipse(100,120,180,0,7,3);
                setfillstyle(1,1);
		floodfill(100,100,15);
                floodfill(100,120,15);


                //Drawing smaller coin in new area
                size = imagesize ( 92,92,108,125);
                getimage(93,93,107,124,p);
                putimage(80,40,p,0);


                //Drawing Smaller Coin With Hole
                putimage(110,40,p,0);
                setfillstyle(1,15);
                circle (117,47, 2);
                floodfill(117,47,15);


                // Destroying The Original
		setfillstyle(1,0);
                bar(93,93,107,124);
		floodfill(100,100,0);


                //Drawing the Smaller red coin
                ellipse( 87, 120, 0, 360, 7, 5);
                line(80,120,80,140);
                line(94,120,94,140);
                ellipse(87,140,180,0,7,3);
                setfillstyle(1,4);
		floodfill(87,120,15);
                floodfill(87,140,15);


                // Drawing the Smaller red coin with the hole
                ellipse( 117, 120, 0, 360, 7, 5);
                line(110,120,110,140);
                line(124,120,124,140);
                ellipse(117,140,180,0,7,3);
		setfillstyle(1,4);
                floodfill(117,120,15);
		floodfill(117,140,15);
                setfillstyle(1,15);
                circle(117,120,2);
                floodfill(117,120,15);
                setfillstyle(1,1);


                //Drawing cuboid red coin
                bar3d(140,103,152,143,10,1);
		setfillstyle(1,4);
                floodfill(143,106,15);
                floodfill(153,106,15);
                floodfill(153,101,15);
                setfillstyle(1,1);


                // Drawing red cuboid with hole
                bar3d(176,103,188,143,10,1);
		setfillstyle(1,4);
                floodfill(179,106,15);
		floodfill(189,106,15);
                floodfill(189,101,15);
                setfillstyle(1,15);
                circle(182,109,2);
                floodfill(182,109,15);
                setfillstyle(1,1);


                //Drawing The Cuboid Coin
		bar3d(140,30,152,70,10,1);
                setfillstyle(1,1);
                floodfill(143,33,15);
                floodfill(153,33,15);
                floodfill(153,28,15);


                //Drawing the Smaller Cuboid
                bar3d(210,47,222,70,8,1);
		setfillstyle(1,1);
                floodfill(213,52,15);
		floodfill(225,52,15);
                floodfill(220,45,15);


                // Drawing Smaller Cuboid with hole
                size = imagesize(209,40,231,71);
                getimage(210,41, 230,70,p);
                putimage(245,41,p,0);
                setfillstyle(1,15);
		circle(251,53,2);
                floodfill(251,53,15);
                setfillstyle(1,1);


                // Drawing Smaller Red Cuboid Coin
                bar3d(210,120,222,143,8,1);
                setfillstyle(1,4);
                floodfill(213,125,15);
		floodfill(225,125,15);
                floodfill(220,118,15);


                //Drawing smaller Red Cuboid Coin with hole
                bar3d(245,120,257,143,8,1);
                setfillstyle(1,15);
                circle(251,126,2);
                floodfill(251,126,15);
                setfillstyle(1,4);
                floodfill(248,125,15);
		floodfill(260,125,15);
                floodfill(255,118,15);


                //Drawing the cuboid coin with hole
                size = imagesize(139,22,163,71);
                getimage(140,23,162,70,p);
                putimage(176,23,p,0);
                setfillstyle(1,15);
		circle(182,37,2);
		floodfill(182,37,15);

		delete p;

}
void draw_border()
{
		setcolor(BROWN);
		rectangle(5,5,getmaxx()-5,getmaxy()-5);
		rectangle(2,2,getmaxx()-2,getmaxy()-2);
}

void draw_board()
{

		setcolor(WHITE);
		setfillstyle(1,6);
		for(int i=1,y=0; i<=4; i++,y=y+75)
		{
			for(int j=1,x=10; j<=4; j++,x=x+100)
			{
				ellipse(x+50, y+200, 0,360,40,30);
				ellipse(x+50, y+200, 0,360,37,27);
				floodfill(x+50, y+200, 15);

			}
		}


		setcolor(BROWN);
		line(420,5,420,473);
		line(423,5,423,473);

		setcolor(YELLOW);
		settextstyle(4,0,5);
		outtextxy(433,20,"QUARTO");
		setcolor(GREEN);
		settextstyle(2,0,5);

		setcolor(BROWN);
		line(423,150,633,150);
		line(423,473,633,150);

		setfillstyle(1,1);
		floodfill(424,152,6);

		setfillstyle(1,4);
		floodfill(430,470,6);

		setcolor(WHITE);
		settextstyle(4,0,5);
		outtextxy(440,155,"Player 1");
		outtextxy(470,410,"Player 2");

                settextstyle(3,0,4);
                rectangle(308,100,408,140);
                setcolor(RED);
                outtextxy(332,99,"EXIT");

}

void click_coin()
{

	int a,b;
	detectgraph(&a,&b);

	q.show_mouse();

	do
	{
		q.get_status();

                if((cx>=308 && cx<=408) && (cy>= 100 && cy<=140))
                exit(0);

		if((cx>=20&&cx<=34)&&(cy>=21&&cy<=71))    // For the tall blue coin
		{
			if(terror[0] == 0)
			{
				coin = 2470;
				q.hide_mouse();
				rectangle(18,19,36,73);

				x1=18;
				x2=36;
				y1=19;
				y2=73;

				flag=1;
				q.show_mouse();
				terror[0]=1;

			}


		}

		if((cx>=20&&cx<=34)&&(cy>=95&&cy<=143))   // For the tall red coin
		{
			if(terror[1]==0)
			{
                                coin = 3458;
			        q.hide_mouse();
		               	rectangle(18,93,36,145);
                                x1=18;
                                x2=36;
                                y1=93;
				y2=145;

			        flag=1;
			        q.show_mouse();
                                terror[1]=1;
                          }
		}

		if((cx>=50&&cx<=64)&&(cy>=20&&cy<=70))    // for the blue coin with hole
		{
                        if(terror[2]==0)
                        {
                                coin = 2090;
				q.hide_mouse();
			        rectangle(48,18,66,72);

                                x1=48;
                                x2=66;
                                y1=18;
                                y2=72;

			        flag=1;
			        q.show_mouse();
                                terror[2]=1;
                        }

		}

		if((cx>=50&&cx<=64)&&(cy>=95&&cy<=143)) // for the tall red coin with hole
		{

                        if(terror[3]==0)
                        {
				coin = 2926;
			        q.hide_mouse();
			        rectangle(48,93,66,145);

                                x1=48;
                                x2=66;
                                y1=93;
				y2=145;

			        flag=1;
			        q.show_mouse();
                                terror[3]=1;
                        }
		}

                if((cx>=80&&cx<=94)&&(cy>=40&&cy<=70))      // for the short blue coin
		{
                        if(terror[4]==0)
                        {

				coin = 3705;
                                q.hide_mouse();
                                rectangle(78,38,96,72);

                                x1=78;
                                x2=96;
                                y1=38;
				y2=72;

                                flag=1;
                                q.show_mouse();
                                terror[4]=1;
                        }
                }


		if((cx>=80&&cx<=94)&&(cy>=115&&cy<=143)) // for the short red coin
                {
                        if(terror[5]==0)
                        {
				coin = 5187;
			        q.hide_mouse();
			        rectangle(78,113,96,145);

                                x1=78;
                                x2=96;
                                y1=113;
				y2=145;

			        flag=1;
			        q.show_mouse();
                                terror[5]=1;
                        }
		}

                if((cx>=110&&cx<=124)&&(cy>=40&&cy<=70)) // for the short blue coin with hole
		{
                        if(terror[6]==0)
                        {
                                coin = 3135;
				q.hide_mouse();
			        rectangle(108,38,126,72);

                                x1=108;
                                x2=126;
                                y1=38;
                                y2=72;

			        flag=1;
			        q.show_mouse();
                                terror[6]=1;
                        }
		}

		if((cx>=110&&cx<=124)&&(cy>=113&&cy<=143)) // for the small red coin with hole
		{
			if(terror[7]==0)
                        {

                                coin = 4389;
				q.hide_mouse();
			        rectangle(108,111,126,145);

                                x1=108;
                                x2=126;
                                y1=111;
                                y2=145;

			        flag=1;
			        q.show_mouse();
                                terror[7]=1;
                        }
		}

		if((cx>=140&&cx<=162)&&(cy>=23&&cy<=70)) // for the tall blue cuboid
		{
			if(terror[8]==0)
                        {

                                coin = 2210;
				q.hide_mouse();
			        rectangle(138,21,164,72);

                                x1=138;
                                x2=164;
                                y1=21;
                                y2=72;

			        flag=1;
			        q.show_mouse();
                                terror[8]=1;
                        }

		}

                if((cx>=140&&cx<=162)&&(cy>=96&&cy<=143)) // for the tall red cuboid
		{
                        if(terror[9]==0)
                        {
                                coin = 3094;
				q.hide_mouse();
			        rectangle(138,94,164,145);

                                x1=138;
                                x2=164;
                                y1=94;
                                y2=145;

			        flag=1;
			        q.show_mouse();
                                terror[9]=1;
                        }
		}

		if((cx>=176&&cx<=198)&&(cy>=23&&cy<=70)) // for the tall blue cuboid with hole
		{
			if(terror[10]==0)
                        {
                                coin = 1870;
			        q.hide_mouse();
				rectangle(174,21,200,72);

                                x1=174;
                                x2=200;
                                y1=21;
                                y2=72;

				flag=1;
			        q.show_mouse();
                                terror[10]=1;
                        }
		}

                if((cx>=176&&cx<=198)&&(cy>=96&&cy<=143)) // for the tall red cuboid with hole
		{
                        if(terror[11]==0)
			{

                                coin = 2618;
			        q.hide_mouse();
				rectangle(174,94,200,145);

                                x1=174;
                                x2=200;
                                y1=94;
                                y2=145;

				flag=1;
			        q.show_mouse();
                                terror[11]=1;
                        }
		}

                if((cx>=210&&cx<=232)&&(cy>=40&&cy<=70)) // for the short blue cuboid
		{
                        if(terror[12]==0)
			{

                                coin = 3315;
			        q.hide_mouse();
				rectangle(208,38,234,72);

                                x1=208;
                                x2=234;
                                y1=38;
                                y2=72;

				flag=1;
			        q.show_mouse();
                                terror[12]=1;
                        }
		}

                if((cx>=210&&cx<=232)&&(cy>=113&&cy<=143)) // for the short red cuboid
		{
                        if(terror[13]==0)
			{

                                coin = 4641;
		               	q.hide_mouse();
				rectangle(208,111,232,145);

                                x1=208;
                                x2=232;
                                y1=111;
                                y2=145;

				flag=1;
			        q.show_mouse();
                                terror[13]=1;
                        }
		}

                if((cx>=245&&cx<=265)&&(cy>=41&&cy<=71)) // for the short blue cuboid with hole
		{
                        if(terror[14]==0)
			{

                                coin = 2805;
			        q.hide_mouse();
				rectangle(243,39,267,73);

                                x1=243;
                                x2=267;
                                y1=39;
                                y2=73;

				flag=1;
			        q.show_mouse();
                                terror[14]=1;
                        }
		}

		if((cx>=245&&cx<=265)&&(cy>=113&&cy<=143)) // for the short red cuboid with hole
		{
			if(terror[15]==0)
			{

				coin = 3927;
				q.hide_mouse();
				rectangle(243,111,267,145);

				x1=243;
				x2=267;
				y1=111;
				y2=145;

				flag=1;
				q.show_mouse();
				terror[15]=1;
			}
		}




	}while(flag == 0);

}

void click_board()
{

	do
	{
		q.get_status();

		if((cx>=20 && cx<=100)&&(cy>=165&&cy<=235))
		{
			if( board[0][0] !=0 ) cerror=1;
			else
			{

				board[0][0] = coin;
				setfillstyle(1,0);
				q.hide_mouse();
				bar(18,165,102,235);
				putimage(50,170,p,0);
				setfillstyle(1,0);
				floodfill(50,170,0);
				flag=1;
				q.show_mouse();
			}
		}

		if((cx>=120 && cx<=200)&&(cy>=170&&cy<=230))
		{
			if( board[0][1] !=0 ) cerror=1;
			else
			{

				board[0][1] = coin;
				setfillstyle(1,0);
				q.hide_mouse();
				bar(118,170,202,230);
				putimage(150,170,p,0);
				setfillstyle(1,0);
				floodfill(160,170,0);
				flag=1;
				q.show_mouse();
			}
		}

		if((cx>=220 && cx<=300)&&(cy>=170&&cy<=230))
		{
			if( board[0][2] !=0 ) cerror=1;
			else
			{

                                board[0][2] = coin;
			        setfillstyle(1,0);
			        q.hide_mouse();
			        bar(218,170,302,230);
				putimage(250,170,p,0);
			        setfillstyle(1,0);
			        floodfill(250,170,0);
			        flag=1;
			        q.show_mouse();
                        }
		}

                if((cx>=320 && cx<=400)&&(cy>=170&&cy<=230))
		{
                        if( board[0][3] !=0 ) cerror=1;
                        else
                        {

				board[0][3] = coin;
			        setfillstyle(1,0);
			        q.hide_mouse();
			        bar(318,170,402,230);
			        putimage(350,170,p,0);
			        setfillstyle(1,0);
				floodfill(350,170,0);
			        flag=1;
			        q.show_mouse();
                          }
		}

                if((cx>=20 && cx<=100)&&(cy>=245&&cy<=305))
		{
                        if( board[1][0] !=0 ) cerror=1;
                        {

                                board[1][0] = coin;
			        setfillstyle(1,0);
		                q.hide_mouse();
				bar(18,245,102,305);
			        putimage(50,245,p,0);
			        setfillstyle(1,0);
			        floodfill(60,245,0);
			        flag=1;
			        q.show_mouse();
			}
		}

                if((cx>=120 && cx<=200)&&(cy>=245&&cy<=305))
		{
                        if( board[1][1] !=0 ) cerror=1;
                        else
                        {

                                board[1][1] = coin;
			        setfillstyle(1,0);
			        q.hide_mouse();
			        bar(118,245,202,305);
			        putimage(150,245,p,0);
				setfillstyle(1,0);
			        floodfill(160,245,0);
			        flag=1;
			        q.show_mouse();
                        }
		}

                if((cx>=220 && cx<=300)&&(cy>=245&&cy<=305))
		{
                        if( board[1][2] !=0 ) cerror=1;
                        else
                        {
                                board[1][2] = coin;
			        setfillstyle(1,0);
			        q.hide_mouse();
			        bar(218,245,302,305);
			        putimage(250,245,p,0);
			        setfillstyle(1,0);
			        floodfill(260,245,0);
			        flag=1;
				q.show_mouse();
                        }
		}

                if((cx>=320 && cx<=400)&&(cy>=245&&cy<=305))
		{
			if( board[1][3] !=0 ) cerror=1;
                        else
                        {

                                board[1][3] = coin;
			        setfillstyle(1,0);
			        q.hide_mouse();
			        bar(318,245,402,305);
			        putimage(350,245,p,0);
			        setfillstyle(1,0);
			        floodfill(360,245,0);
			        flag=1;
			        q.show_mouse();
                        }
		}

                if((cx>=20 && cx<=100)&&(cy>=320&&cy<=380))
		{
                        if( board[2][0] !=0 ) cerror=1;
                        else
			{

                                board[2][0] = coin;
			        setfillstyle(1,0);
			        q.hide_mouse();
			        bar(18,320,102,380);
			        putimage(50,320,p,0);
			        setfillstyle(1,0);
			        floodfill(60,320,0);
			        flag=1;
			        q.show_mouse();
                        }
		}

		if((cx>=120 && cx<=200)&&(cy>=320&&cy<=380))
		{
                        if( board[2][1] !=0 ) cerror=1;
                        else
                        {
                                board[2][1] = coin;
				setfillstyle(1,0);
			        q.hide_mouse();
			        bar(118,320,202,380);
			        putimage(150,320,p,0);
			        setfillstyle(1,0);
			        floodfill(160,320,0);
			        flag=1;
			        q.show_mouse();
                        }
		}

                if((cx>=220 && cx<=300)&&(cy>=320&&cy<=380))
		{
                        if( board[2][2] !=0 ) cerror=1;
			else
                        {
                                board[2][2] = coin;
			        setfillstyle(1,0);
		               	q.hide_mouse();
			        bar(218,320,302,380);
				putimage(250,320,p,0);
			        setfillstyle(1,0);
			        floodfill(260,320,0);
			        flag=1;
			        q.show_mouse();
                        }
		}

                if((cx>=320 && cx<=400)&&(cy>=320&&cy<=380))
		{
                        if( board[2][3] !=0 ) cerror=1;
                        else
                        {
                                board[2][3] = coin;
				setfillstyle(1,0);
		               	q.hide_mouse();
			        bar(318,320,402,380);
			        putimage(350,320,p,0);
			        setfillstyle(1,0);
			        floodfill(360,320,0);
				flag=1;
			        q.show_mouse();
                        }
		}

                if((cx>=20 && cx<=100)&&(cy>=395&&cy<=455))
		{
                        if( board[3][0] !=0 ) cerror=1;
                        else
                        {
                                board[3][0] = coin;
			        setfillstyle(1,0);
			        q.hide_mouse();
			        bar(18,395,102,455);
				putimage(50,395,p,0);
			        setfillstyle(1,0);
			        floodfill(60,395,0);
			        flag=1;
			        q.show_mouse();
                        }
		}

                if((cx>=120 && cx<=200)&&(cy>=395&&cy<=455))
		{
                        if( board[3][1] !=0 ) cerror=1;
                        else
                        {
                                board[3][1] = coin;
			        setfillstyle(1,0);
			        q.hide_mouse();
			        bar(118,395,202,455);
			        putimage(150,395,p,0);
			        setfillstyle(1,0);
			        floodfill(160,395,0);
				flag=1;
			        q.show_mouse();
                        }
		}

                if((cx>=220 && cx<=300)&&(cy>=395&&cy<=455))
		{
                        if( board[3][2] !=0 ) cerror=1;
                        else
                        {
                                board[3][2] = coin;
			        setfillstyle(1,0);
			        q.hide_mouse();
			        bar(218,395,302,455);
			        putimage(250,395,p,0);
			        setfillstyle(1,0);
			        floodfill(260,395,0);
				flag=1;
				q.show_mouse();
			}
		}

		if((cx>=320 && cx<=400)&&(cy>=395&&cy<=455))
		{
			if( board[3][3] !=0 ) cerror=1;
			else
			{
				board[3][3] = coin;
				setfillstyle(1,0);
				q.hide_mouse();
				bar(318,395,402,455);
				putimage(350,395,p,0);
				setfillstyle(1,0);
				floodfill(360,395,0);
				flag=1;
				q.show_mouse();
			}
		}


	}while(flag==0);

	delete p;
}

void quarto()
{

	int driver =9, mode=2;
	initgraph( &driver, &mode, "C:\\tc\\bgi");

	draw_coins();
	draw_border();
	draw_board();

	do
	{

                setcolor(WHITE);


                if(turn == 1)
                {
                        q.hide_mouse();
                        settextstyle(2,0,5);
                        setcolor(BLUE);
		        outtextxy(433,90," Pick a coin for Player 1");
		        outtextxy(433,110," to place on the board..");
                        q.show_mouse();
                }

                else if(turn == -1)
                {
                        q.hide_mouse();
                        settextstyle(2,0,5);
                        setcolor(RED);
		        outtextxy(433,90," Pick a coin for Player 2");
		        outtextxy(433,110," to place on the board.. ");
                        q.show_mouse();
                }

                setcolor(WHITE);
		click_coin();
		q.hide_mouse();
		size=imagesize(x1,y1,x2,y2);
		p = (char *)malloc(size);
		getimage(x1,y1,x2,y2,p);
		setfillstyle(1,0);
		bar(x1,y1,x2,y2);
		q.show_mouse();

                if(win==0)
                {
                        setcolor(BLACK);
                        setfillstyle(1,0);
                        bar(433,90,633,125);
                        bar(308,20,408,80);
                }

                if( turn == 1)
                {
                        settextstyle(4,0,2);
                        setcolor(GREEN);
			outtextxy(300,20,"\t");
			outtextxy(308,20,"Player 1");
			outtextxy(308,50,"PLAY!!!");

                }

                else if(turn == -1)
                {
                        settextstyle(4,0,2);
                        setcolor(GREEN);
			outtextxy(300,20,"\t");
			outtextxy(308,20,"Player 2");
			outtextxy(308,50,"PLAY!!!");
                }

		if(turn == -1)
		{
			putimage(550,330,p,0);

			setfillstyle(1,4);
			floodfill(552,332,15);
			floodfill(550,330,4);
		}

		else if(turn == 1)
		{
			putimage(470,250,p,0);

			setfillstyle(1,1);
			floodfill(472,252,15);
			floodfill(470,250,1);

		}

		flag=0;
		click_board();

		win = check();

	if(win==1)
	{

                setcolor(BLACK);
                bar(433,90,633,125);
                bar(308,20,408,80);

	        setcolor(GREEN);
		settextstyle(4,0,2);

		if(turn == -1)
		{

			outtextxy(300,20,"\t");
			outtextxy(308,20,"Player 2");
			outtextxy(308,50,"WINS!!!");

		}
		else
		{

			outtextxy(300,20,"\t");
			outtextxy(308,20,"Player 1");
			outtextxy(308,50,"WINS!!!");
		}


	}


		flag=0;
		setfillstyle(1,4);
		bar(550,330,600,400);
		setfillstyle(1,1);
		bar(470,250,520,320);
		setfillstyle(1,0);
		setcolor(WHITE);

		turn = -turn;

	}while(win==0);


	getch();
	closegraph();
	delete p;
}

int check()
{

	for(int j=0; j<=3; j++)
	{
		for(int i=0; i<=3; i++)
		{
			flag = 0;

			for ( int k=0, l=3; k<=3 && flag==0; k++,l--)
			{

				if(j==0)
				{
					if(board[i][k]!=0) che[k] = board[i][k];
					else flag = 1;
				}

				else if(j==1)
				{
					if(board[k][i]!=0) che[k] = board[k][i];
					else flag = 1;
				}

				else if(j==2)
				{
					if(board[k][k]!=0) che[k] = board[k][k];
					else flag = 1;
				}

				else
				{
					if(board[k][l]!=0) che[k] = board[k][l];
					else flag = 1;
				}

			}

			if( flag==0 )
			{
				int a,b,c,d;
				a = che[0];
				b = che[1];
				c = che[2];
				d = che[3];

				e = a%b;

				while( e!=0)
				{
					a=b;
					b=e;
					e=a%b;
				}

				e=c%b;

				while( e!=0)
				{
					c=b;
					b=e;
					e=c%b;
				}

				e=d%b;

				while ( e!=0)
				{
					d=b;
					b=e;
					e=d%b;
				}



				if(b!=1) return 1;   // checks if there is winner or not!!
			}
		}
	}

	return 0;
}



























































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































