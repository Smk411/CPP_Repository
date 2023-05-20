#include <iostream>
#include <windows.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <math.h>
using namespace std;
#define LEFT 75
#define RIGHT 77

void gotoxy(int x,int y)
{
	COORD pos={x-1,y-1};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}
void delay(int x)
{
	Sleep(x);
}
struct airplane
{
	int x,y;
	char face[12];
	void scr_mov();
};
void airplane::scr_mov()
{
	gotoxy(x,y);
	cout<<face<<endl;
	gotoxy(x,y-1);
	cout<<"      "<<endl;
	if(y==24)
	{
		gotoxy(x,24);
		cout<<"       "<<endl;
	}
	if(y==23){
		gotoxy(x-1,23);
		cout<<" "<<endl;
		gotoxy(x+7,23);
		cout<<" "<<endl;
	}
	

}
struct gun
{
	int x,y;
	void gun_mov();
	
};
void gun::gun_mov()
{
	gotoxy(x,y);
	cout<<"¡â"<<endl;
	gotoxy(x,y+1);
	cout<<"	 "<<endl;
	if(y==1)
	{
		gotoxy(x,1);
		cout<<"	 "<<endl;
	}
}

int crash(int x1,int y1,int width1,int* x2,int* y2,int width2,bool sw,int i)
{
	if((x1+width1)>*x2&&(x1)<(*x2+width2)&&(y1+width1)>*y2&&(y1)<(*y2+width2)&&sw==true)
	{
		return i;	
	}
}
int main()
{
	int i=0;
	int k=0;
	int yy=1;
	int xx[5]={};
	int enemy_num=0;
	bool sw1=false;
	bool enemy_sw=true;
	gun hero_gun;
	
	airplane hero;
	airplane enemy[5];
	
	char st1[12]="¢Ä-¡ã-¢Å";
	char st2[12]="¢Â¡é¢Â";
	strcpy(hero.face,st1);
	hero.x=37;
	hero.y=23;
	hero_gun.y=0;
	char key_in;
	srand(time(NULL));
	for(int i=0;i<5;i++)
	{
		strcpy(enemy[i].face,st2);
		enemy[0].x=rand()%(14-2+1)+2;
		enemy[1].x=rand()%(28-14+1)+14;
		enemy[2].x=rand()%(42-28+1)+28;
		enemy[3].x=rand()%(56-42+1)+42;
		enemy[4].x=rand()%(70-56+1)+56;
		enemy[i].y=2;
	}
	while(1)
	{
		
		if(kbhit())
		{
			key_in=getch();
			if(key_in==LEFT)
			{
				hero.x--;
			}
			else if(key_in==RIGHT)
			{
				hero.x++;
			}
			else if(key_in==' ')
			{
				sw1=true;
				if(hero_gun.y==0)
				{
					
					hero_gun.x=hero.x+3;
					hero_gun.y=23;
				}
			}
			if(hero.x<1)
			{
				hero.x=1;
			}
			if(hero.x>70)
			{
				hero.x=70;
			}
		}
		hero.scr_mov();
		if(sw1==true)
		{
			hero_gun.y--;
			if(hero_gun.y==0)
			{
				sw1=false;

			}
			else
			{
				hero_gun.gun_mov();
			}
		}
		
		for(int i=0;i<5;i++)
		{
			if(enemy[i].y==24)
			{
				
				enemy[i].y=2;
				
			}
			else
			{
				if(k==10)
				{
				
					k=0;

					enemy[i].y++;
				
				}	
				else
				{
					k++;
				}
			}

			
			enemy[i].scr_mov();
		}
		for(int i=0;i<5;i++){

			
			enemy_num=crash(hero_gun.x,hero_gun.y,1,&enemy[i].x,&enemy[i].y,6,sw1,i);
			switch(enemy_num){
			case 0:
				
				gotoxy(enemy[i].x,enemy[i].y);
				cout<<"      "<<endl;
				gotoxy(hero_gun.x,hero_gun.y);
				cout<<"      "<<endl;
				hero_gun.y=0;
				if(enemy[i].y<24){
					enemy[i].y=2;
					gotoxy(enemy[i].x,enemy[i].y);
					cout<<"      "<<endl;
				}

			case 1:
				
				gotoxy(enemy[i].x,enemy[i].y);
				cout<<"      "<<endl;
				gotoxy(hero_gun.x,hero_gun.y);
				cout<<"      "<<endl;
				hero_gun.y=0;
				if(enemy[i].y<24){
					enemy[i].y=2;
					gotoxy(enemy[i].x,enemy[i].y);
					cout<<"      "<<endl;
				}

			case 2:
				
				gotoxy(enemy[i].x,enemy[i].y);
				cout<<"      "<<endl;
				gotoxy(hero_gun.x,hero_gun.y);
				cout<<"      "<<endl;
				hero_gun.y=0;
				if(enemy[i].y<24){
					enemy[i].y=2;
					gotoxy(enemy[i].x,enemy[i].y);
					cout<<"      "<<endl;
				}

			case 3:
				
				gotoxy(enemy[i].x,enemy[i].y);
				cout<<"      "<<endl;
				gotoxy(hero_gun.x,hero_gun.y);
				cout<<"      "<<endl;
				hero_gun.y=0;
				if(enemy[i].y<24){
					enemy[i].y=2;
					gotoxy(enemy[i].x,enemy[i].y);
					cout<<"      "<<endl;
				}
		

			case 4:
				
				gotoxy(enemy[i].x,enemy[i].y);
				cout<<"      "<<endl;
				gotoxy(hero_gun.x,hero_gun.y);
				cout<<"      "<<endl;
				hero_gun.y=0;
				if(enemy[i].y<24){
					enemy[i].y=2;
					gotoxy(enemy[i].x,enemy[i].y);
					cout<<"      "<<endl;
				}

			}

		}
		delay(10);
	}
	system("PAUSE");
	return 0;
}