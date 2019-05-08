#include<iostream>
#include<conio.h>
#include<cstdlib>

using namespace std;
void run ();
bool running;
void mapdef();
void changedirection(char);
void generatefood();
void updatemap();
void printmap();
void clearScreen();
int map[20][20], foodx,foody,direction=1;     				//1 for up
int headx,heady,tailx,taily,score=3;
int directiongrid[20][20];								    //2 for down


int main()
{
	for(int i=0;i<20;++i)										//3 for left
    for(int j=0;j<20;++j)  										//4 for right
    map[i][j]='\0';
	run();
	return 0;
}

void run()
{   mapdef();
	running=true;
	while(running)
	{
		if(kbhit())
		 changedirection(getch());
		
		updatemap();
		clearScreen();
		printmap();
		_sleep(500);
		
	}
	
	cout<<endl;
	cout<<"Your score is "<<score;
}

void clearScreen()
{
	system("cls");
}

void mapdef()
{
	for(int i=0;i<20;++i)
	   for(int j=0;j<20;++j)
	    if(i==0||i==19||j==0||j==19)
		 map[i][j]=1  ;                      // 1 is used for map outline 
	
	map[10][10]=map[11][10]=map[12][10]=2;
	directiongrid[10][10]=directiongrid[11][10]=directiongrid[12][10]=1;
	generatefood();
	
    headx=10;
	heady=10;
	tailx=12;
	taily=10;
}

void generatefood()
{
	do
	{
	foodx=rand()%18+1;
	foody=rand()%18+1;
    }while(map[foodx][foody]==2);
    
    map[foodx][foody]=3;
}

void changedirection(char dir)
{
	switch(dir)
	{
		case 'w':  if(direction!=2)
					  direction=1;
					break;
		case 's' : 	if(direction!=1)
					  direction=2;
					break;
		case 'a' :	if(direction!=4)
					  direction=3;
					break;
		case 'd' : 	if(direction!=3)
					  direction=4;
					break;				   
	}
}

void updatemap()
{ directiongrid[headx][heady]=direction;
  switch(direction)
  { 
  	case 1: headx= headx-1;
  			break;
  	case 2: headx= headx+1;
	  		break;
	case 3: heady= heady-1;
			break;
	case 4: heady= heady+1;
			break;				 		
	  }	
	  
  if(map[headx][heady]==3)
  {
  	map[headx][heady]=2;
  	score=score+1;
  	generatefood();
  }
  else if(map[headx][heady]==2||map[headx][heady]==1)
  {
  	running=false;
  }
  else
  {
  	map[headx][heady]=2;
  	map[tailx][taily]='\0';
  	switch(directiongrid[tailx][taily])
  	{
  	  case 1: tailx=tailx-1;
			  break; 
	  case 2: tailx=tailx+1;
	  		  break;
	  case 3: taily=taily-1;
	  		  break;
	  case 4: taily=taily+1;
	  		  break;
	}
  	
  }
}

void printmap()
{
	for(int i=0;i<20;++i)
	{
		for(int j=0;j<20;++j)
		{
			if(map[i][j]!='\0')
			{
				if(map[i][j]==1)
					cout<<'x';
				else if(map[i][j]==2)
					cout<<'o';
				else if(map[i][j]==3)
					cout<<'0';
			}
			else if(map[i][j]=='\0')
			cout<<" ";
		}
		
		cout<<endl;
	}
}


