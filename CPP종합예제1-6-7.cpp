#include <iostream>
#include <windows.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <math.h>
using namespace std;
#define LEFT 75
#define RIGHT 77
#define ENEMY 10
#define LIFE 3
#define HIT 10


void gotoxy(int x,int y)
{
	COORD pos={x-1,y-1};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}
struct start{
	
	void start_screen(){
		gotoxy(45,10);
		cout<<"주인공 이동 : 좌우 화살표 키보드"<<endl;
	
		gotoxy(45,13);
		cout<<"	  무기발사: 스페이스바"<<endl;
	
		gotoxy(45,16);
		cout<<"S 키를 선택하면 게임이 시작됩니다";
		
	}
	void end_screen1(int* life)
	{
	gotoxy(55,13);
	cout<<"목숨 "<<*life<<" 남음"<<endl;
	
	gotoxy(56,16);
	cout<<"미션 성공"<<endl;
	}
	void end_screen2(int* hit)
	{
		gotoxy(55,13);
		cout<<"적 "<<*hit<<" 남음"<<endl;
	
		gotoxy(55,16);
		cout<<"미션 실패"<<endl;
	}
};

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
	cout<<"△"<<endl;
	gotoxy(x,y+1);
	cout<<"	 "<<endl;
	if(y==1)
	{
		gotoxy(x,1);
		cout<<"	 "<<endl;
	}
}
void score_and_hp(int* hit,int* life){
	gotoxy(40,30);
	cout<<"hit : "<<*hit<<	"		hp : "<<*life;
}
int crash(int x1,int y1,int width1,int* x2,int* y2,int width2,bool sw,int i,int* hit)
{
	if((x1+width1)>*x2&&(x1)<(*x2+width2)&&(y1+width1)>*y2&&(y1)<(*y2+width2)&&sw==true)
	{
		*hit-=1;
		return i;	
	}
}

void player_crash(int x1,int y1,int width1,int* x2,int* y2,int width2,bool sw,int i,int* life_cnt)
{

	if((x1+width1)>*x2&&(x1)<(*x2+width2)&&(y1+width1)>*y2&&(y1)<(*y2+width2)&&sw==true)
	{
		*life_cnt--;
	}

}

int main()
{
	int i=0;
	int k=0;
	int yy=1;
	int t_cnt=2;
	int xx[5]={};
	int enemy_num=0;
	int player_num=0;
	bool player_hit=false;
	int life_cnt=LIFE;
	int hit=HIT;
	char start_str=' ';
	bool sw1=false;
	bool enemy_sw=true;
	gun hero_gun;
	airplane hero;
	airplane enemy[5];
	start st;
	
	char st1[12]="◐-▲-◑";
	char st2[12]="◈↓◈";
	strcpy(hero.face,st1);
	hero.x=37;
	hero.y=23;
	hero_gun.y=0;
	char key_in;
	srand(time(NULL));
	st.start_screen();
	scanf("%s",&start_str);
	cout<<"		"<<endl;
	if(start_str=='s'||start_str=='S')
	{
		gotoxy(45,10);
		cout<<"						"<<endl;
		gotoxy(45,13);
		cout<<"						"<<endl;
		gotoxy(45,16);
		cout<<"						"<<endl;
		
		for(int i=0;i<5;i++)
		{
			strcpy(enemy[i].face,st2);
			enemy[0].x=rand()%(12-2+1)+2;
			enemy[1].x=rand()%(28-16+1)+16;
			enemy[2].x=rand()%(42-30+1)+30;
			enemy[3].x=rand()%(56-44+1)+44;
			enemy[4].x=rand()%(70-58+1)+58;
			enemy[i].y=2;
		}
		while(1)
		{
			score_and_hp(&hit,&life_cnt);
			
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
						t_cnt++;
						enemy[i].y++;
				
					}	
					else
					{
						k++;
					}
				}

			
				enemy[i].scr_mov();
			}
			for(int i=0;i<5;i++)
			{
				enemy_num=crash(hero_gun.x,hero_gun.y,1,&enemy[i].x,&enemy[i].y,6,sw1,i,&hit);
				
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
			for(int i=0;i<5;i++)
			{
				player_num=crash(hero.x,hero.y,6,&enemy[i].x,&enemy[i].y,2,sw1,i,&life_cnt);
				switch(player_num){
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
			if(hit==0)
			{
				break;
				
			}
			else if(life_cnt==0){
				break;
			}
			delay(10);
		}
		if(hit==0)
		{
			system("CLS");
			st.end_screen1(&life_cnt);
		}
		if(life_cnt==0){
			system("CLS");
			st.end_screen2(&hit);
		}
		
	}
	system("PAUSE");
	return 0;
}