#include<iostream.h>
#include<dos.h>
#include<conio.h>
#include<stdlib.h>
#include<graphics.h>

char square[10] = {'o','1','2','3','4','5','6','7','8','9'};
void setup();
void draw();
void input();
void logic();
int checkwin();
void board();
int gameover;
const int width=60;
const int height=20;
int x,y,fruitx,fruity,score,tailx[100],taily[100],ntail;
enum edirection {STOP=0,LEFT,RIGHT,UP,DOWN};
edirection dir;
int player = 1,i,choice;
char mark;

// Snake Game
void setup()
{
	gameover=0;
	dir=STOP;
	x=width/2;
	y=height/2;
	randomize();
	fruitx=random(width);
	fruity=random(height);
	score=0;
}
void draw()
{
	clrscr();
	for(int i=0;i<width+2;i++)
	  cout<<"$";
	cout<<endl;
	for(i=0;i<height;i++)
	{
		for(int j=0;j<width;j++)
		{
			if(j==0)
			 cout<<"$";
			if(i==y && j==x)
			 cout<<"O";
			else if(i==fruity && j==fruitx)
			 cout<<"F";
			else
			{
			 int print=0;
			 for(int k=0;k<ntail;k++)
			 {

			  if(tailx[k]==j && taily[k]==i)
			  {
			   cout<<"o";
			   print=1;
			  }
			 }
			 if(!print)
			  cout<<" ";
			}
			if(j==width-1)
			cout<<"$";
		}
		cout<<endl;
	}
	for(i=0;i<width+2;i++)
	cout<<"$";
	cout<<endl;
	cout<<"score:"<<score<<endl;
}
void input()
{
	if(kbhit())

	{
		switch(getch())
		{
			case 'f':
			dir=LEFT;
			break;
			case 'h':
			dir=RIGHT;
			break;
			case 't':
			dir=UP;
			break;
			case 'g':
			dir=DOWN;
			break;
			case 'x':
			gameover=1;
			break;
		}
	}
}
void logic()
{
 int prevx=tailx[0];
 int prevy=taily[0];
 int prev2x,prev2y;
 tailx[0]=x;
 taily[0]=y;
 for(int i=1;i<ntail;i++)
 {
  prev2x=tailx[i];
  prev2y=taily[i];
  tailx[i]=prevx;
  taily[i]=prevy;
  prevx=prev2x;
  prevy=prev2y;
 }
	switch(dir)
	{
		case LEFT:x--;
		break;
		case RIGHT:x++;
		break;
		case UP:y--;
		break;
		case DOWN:y++;
		break;
	}
	if(x>=width || x<0 || y>=height ||y<0)
	 gameover=1;
	for(i=0;i<ntail;i++)
	 if(tailx[i]==x&& taily[i]==y)
	  gameover=1;
	if(x==fruitx && y==fruity)
	{
		score+=10;
		randomize();
		fruitx=random(width);
		fruity=random(height);
		ntail++;
	}
}

// Ball N Ring Game

void ballNring()
{
 int i,x,y=250,gd=DETECT, gm;
 int ring[5];
 char ch;

 initgraph(&gd,&gm,"C:\\TurboC3\\BGI");
 cleardevice();
 randomize();
 for(i=0;i<5;i++)
 {
  ring[i]=180+random(120);
 }

 for(x=25;x<614;x++)
 {
   cleardevice();
   setfillstyle(SOLID_FILL,WHITE);
   line(0,50,639,50);
   line(0,429,639,429);
   bar3d(100,50,120,429,0,0);
   bar3d(220,50,240,429,0,0);
   bar3d(340,50,360,429,0,0);
   bar3d(460,50,480,429,0,0);
   bar3d(580,50,600,429,0,0);
   setfillstyle(SOLID_FILL,BLACK);
   int c=110;
   for(int i=0; i<5; i++,c+=120)
   {
    fillellipse(c,ring[i],25,25);
   }
   setfillstyle(SOLID_FILL,RED);
   fillellipse(x,y,20,20);
   if(kbhit())
   {
     ch=getch();
     if(ch=='t')
      y--;
     else if(ch=='g')
      y++;
   }
   c=110;
   for(i=0;i<5;i++,c+=120)
   {
    if(x==c&&(y<ring[i]-5||y>ring[i]+5))
    {
     cleardevice();
     outtextxy(250,250,"Game Over!!!");
     getch();
     exit(1);
    }
   }
   delay(100);
  }

 cout<<"You Win!!!";

 getch();
 closegraph();
}

// Zero Kaata Game
int checkwin()
{
	if (square[1] == square[2] && square[2] == square[3])

		return 1;
	else if (square[4] == square[5] && square[5] == square[6])

		return 1;
	else if (square[7] == square[8] && square[8] == square[9])

		return 1;
	else if (square[1] == square[4] && square[4] == square[7])

		return 1;
	else if (square[2] == square[5] && square[5] == square[8])

		return 1;
	else if (square[3] == square[6] && square[6] == square[9])

		return 1;
	else if (square[1] == square[5] && square[5] == square[9])

		return 1;
	else if (square[3] == square[5] && square[5] == square[7])

		return 1;
	else if (square[1] != '1' && square[2] != '2' && square[3] != '3'
		    && square[4] != '4' && square[5] != '5' && square[6] != '6'
		  && square[7] != '7' && square[8] != '8' && square[9] != '9')

		return 0;
	else
		return -1;
}



void board()
{

	cout << "\n\n\t\t\t\tTHE ZERO KAATA GAME\n\n";

	cout << "Player 1: O      Player 2: X" << endl << endl;
	cout << endl;

	cout << "     |     |     " << endl;
	cout << "  " << square[1] << "  |  " << square[2] << "  |  " << square[3] << endl;

	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;

	cout << "  " << square[4] << "  |  " << square[5] << "  |  " << square[6] << endl;

	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;

	cout << "  " << square[7] << "  |  " << square[8] << "  |  " << square[9] << endl;

	cout << "     |     |     " << endl << endl;
}


int main()
{
 clrscr();
	int select;
	cout<<"\n\n\t\t\tWELCOME TO THE WORLD OF GAMES\n\n";
	cout<<"SELECT THE GAME YOU WANT TO PLAY\n\n";
	cout<<"1. Snake Game\n";
	cout<<"2. Ball N Ring Game\n";
	cout<<"3. The Zero Kaata Game\n";
	cout<<"\nEnter your choice:";
	cin>>select;
	clrscr();
	if(select==1)
	{
		setup();
	while(!gameover)
	{
		draw();
		input();
		logic();
		delay(200);
	}
	clrscr();
	cout<<"Game Over!!!";
	getch();
	}
	else if(select==2)
	 ballNring();
	else if(select==3)
	{

	do
	{
		clrscr();
		board();
		player=(player%2)?1:2;

		cout << "Player " << player << ", enter a number:  ";
		cin >> choice;

		mark=(player == 1) ? 'O' : 'X';

		if (choice == 1 && square[1] == '1')

			square[1] = mark;
		else if (choice == 2 && square[2] == '2')

			square[2] = mark;
		else if (choice == 3 && square[3] == '3')

			square[3] = mark;
		else if (choice == 4 && square[4] == '4')

			square[4] = mark;
		else if (choice == 5 && square[5] == '5')

			square[5] = mark;
		else if (choice == 6 && square[6] == '6')

			square[6] = mark;
		else if (choice == 7 && square[7] == '7')

			square[7] = mark;
		else if (choice == 8 && square[8] == '8')

			square[8] = mark;
		else if (choice == 9 && square[9] == '9')

			square[9] = mark;
		else
		{
			cout<<"Invalid move ";

			player--;
		       getch();
		}
		i=checkwin();

		player++;
	}while(i==-1);
	clrscr();
	board();
	if(i==1)

		cout<<"Hurray!! Player "<<--player<<" wins the game !! ";
	else
		cout<<"\aGame draw";

	getch();

}
	else
	 cout<<"\nInvalid choice!!\n";

	getch();
	return 0;
}




