/********** TIC - TAC - TOE ************
 ********** By - SHUBHAM JHA ***********
 ********** https://www.linkedin.com/in/shubham-jha-252001/ ********
 ********** https://github.com/shubhamjha25 ************************
 ******************************************************************/

// Header Files
#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>

// Global Variables
char sq[9]={'1','2','3','4','5','6','7','8','9'};
char u[2]={'X','O'};
char n1[50], n2[50], player[50];

// Function To Analytically Draw The Tic-Tac-Toe Board
void draw()
{
	clrscr();
	cout<<"\n\t\t  TIC TAC TOE GAME \n\n";
	cout<<"\t\t      |   |   "<<endl;
	cout<<"\t\t    "<<sq[0]<<" | "<<sq[1]<<" | "<<sq[2]<<endl;
	cout<<"\t\t   ___|___|___"<<endl;
	cout<<"\t\t      |   |   "<<endl;
	cout<<"\t\t    "<<sq[3]<<" | "<<sq[4]<<" | "<<sq[5]<<endl;
	cout<<"\t\t   ___|___|___"<<endl;
	cout<<"\t\t      |   |   "<<endl;
	cout<<"\t\t    "<<sq[6]<<" | "<<sq[7]<<" | "<<sq[8]<<endl;
	cout<<"\t\t      |   |   "<<endl;
	getch();
}

// Checking The Winning Condition
int checkwin()
{        
	int y;
	//checking for player 'X'
	//row
	if((sq[0] == sq[1]) && (sq[1] == sq[2]))
		y=1;
	else if((sq[3] == sq[4]) && (sq[4] == sq[5]))
		y=1;
	else if((sq[6] == sq[7]) && (sq[7] == sq[8]))
		y=1;
	//coloumn wise
	else if((sq[0] == sq[3]) && (sq[3] == sq[6]))
		y=1;
	else if((sq[1] == sq[4]) && (sq[4] == sq[7]))
		y=1;
	else if((sq[2] == sq[5]) && (sq[5] == sq[8]))
		y=1;
	//checking diagonally
	else if((sq[0] == sq[4]) && (sq[4] == sq[8]))
		y=1;
	else if((sq[2] == sq[4]) && (sq[4] == sq[6]))
		y=1;
	else
		y=0;
	return y;
}

// Function To Toggle Players
void chngplyr()
{
	if(strcmpi(player , n1) == 0)
		strcpy(player , n2);
	else
		strcpy(player, n1);
}

// Input Function For User - Computer Mode
void inputcomp(char player[],char ch)
{
	int choice;
	choice=random(9)+1;
	if(sq[0]=='1'&& choice==1)
		sq[0]=ch;
	else if(sq[1]=='2' && choice==2)
		sq[1]=ch;
	else if(sq[2]=='3' && choice==3)
		sq[2]=ch;
	else if(sq[3]=='4' && choice==4)
		sq[3]=ch;
	else if(sq[4]=='5' && choice==5)
		sq[4]=ch;
	else if(sq[5]=='6' && choice==6)
		sq[5]=ch;
	else if(sq[6]=='7' && choice==7)
		sq[6]=ch;
	else if(sq[7]=='8' && choice==8)
		sq[7]=ch;
	else if(sq[8]=='9' && choice==9)
		sq[8]=ch;
	else
		inputcomp(player,ch);
}

// Input Function For 2 - Player Mode
void input(char player[],char ch)
{       
	int choice;
	puts(player);
	cout<<"	Its Your Turn: ";
	cout<<"\n Enter Your Position: ";
	cin>>choice;
	if(sq[0]=='1'&& choice==1)
		sq[0]=ch;
	else if(sq[1]=='2' && choice==2)
		sq[1]=ch;
	else if(sq[2]=='3' && choice==3)
		sq[2]=ch;
	else if(sq[3]=='4' && choice==4)
		sq[3]=ch;
	else if(sq[4]=='5' && choice==5)
		sq[4]=ch;
	else if(sq[5]=='6' && choice==6)
		sq[5]=ch;
	else if(sq[6]=='7' && choice==7)
		sq[6]=ch;
	else if(sq[7]=='8' && choice==8)
		sq[7]=ch;
	else if(sq[8]=='9' && choice==9)
		sq[8]=ch;
	else
	{
		cout<<"\n Invalid Move!! Please Try Again..";
		input(player,ch);
	}
}

// For User - Computer Mode
void cmp()
{
	int n=1,y,r=0,v;
	y=random(2);
	cout<<"\t\n Enter your name: ";
	gets(n1);
	cout<<"\t Your symbol is: "<<u[y];
	strcpy(player,n1);
	strcpy(n2,"Computer");
	cout<<"\n\t Computer's symbol is: "<<u[1-y];
	getch();
	while(n!=10)
	{
		draw();
		if(n%2!=0)
			input(player,u[y]);
		else
		{
			cout<<"\n Computer's Turn: ";
			getch();
			inputcomp(player,u[1-y]);
		}
		n++;
		v=checkwin();
		if(v==1)
		{
			r=1;
			break;
		}
		else
			chngplyr();
	}
	draw();
	if(r==1)
	{
		puts(player);
		cout<<" Congratulations You Won ! ";
	}
	else
		cout<<"\n Match is Drawn. Better Luck Next Time To Both of You !";
	cout<<"\n\n Thanks For Playing The Game. I Hope You Liked It :)";
	getch();
}

// For 2 - Player Mode
void multplyr()
{
	int n=1,y,r=0,v;
	y=random(2);
	cout<<"\n\t Enter Your Name Player1: ";
	gets(n1);
	cout<<"\t Your Symbol is: "<<u[y];
	cout<<"\n\t Enter Your Name Player2: ";
	gets(n2);
	cout<<"\t Your Symbol is: "<<u[1-y];
	getch();
	strcpy(player,n1);
	while(n!=10)
	{
		draw();
		if(n%2!=0)
			input(player,u[y]);
		else
			input(player,u[1-y]);
		n++;
		v=checkwin();
		if(v==1)
		{
			r=1;
			break;
		}
		else
			chngplyr();
	}
	draw();
	if(r==1)
	{
		puts(player);
		cout<<" Congratulations You Won !";
	}
	else
		cout<<"\n Match is Drawn. Better Luck Next Time To Both of You !";
	cout<<"\n\n Thanks For Playing The Game. I Hope You Liked It :)";
	getch();
}

// The Main Function
void main()
{       
	clrscr();
	char ch;
	randomize();
	cout<<"\n\n\t\t Welcome To Tic-Tac-Toe Game : ";
	cout<<"\n\n\t Press 'c' For Playing With Computer.\n\t Press 'm' For Multiplayer.\n";
	cout<<"\n\t Enter Your Choice - ";
	cin>>ch;
	if(ch=='c')
		cmp();
	else if(ch=='m')
		multplyr();
	else
	{	cout<<"\n Invalid Input .. Try Again !!";
		getch();
		main(); //Recursive Call To The Main Function
	}

}

/********* END OF CODE *********/
