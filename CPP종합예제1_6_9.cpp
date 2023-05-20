#include <iostream>
#include <windows.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <math.h>
using namespace std;

#define LEFT 75
#define RIGHT 77
#define LIFE 3
#define HIT 20
#define ENEMY_NUM 5
class Member{
	public :

		int x,y;
		string st1;
		string st2;

		Member(){
			x=37;
			y=23;
		}
		void erase(int byte_v){
			for(int j=0;j<byte_v;j++){
				cout<<' ';
		
			}
			cout<<endl;
		}
		
};
class Airplanegame{
	public :
		Member mem;
		time_t start, finish;
		int score;
		int k;
	
		bool sw1;
		char key_in;
		
		char start_str;
		int hit;
		int life_cnt;
		double time_cnt;
		
		int enemy_x[ENEMY_NUM];
		int enemy_y[ENEMY_NUM];
		int gun_x;
		int gun_y;
		int enemy_s;
		int player_s;
		

		Airplanegame(){
			score=0;
			k=0;
		
			time_cnt=0;
			sw1=false;
			hit=HIT;
			life_cnt=LIFE;
			mem.st1="◐-▲-◑";
			mem.st2="◈↓◈";
			srand(time(NULL));
			
			gun_y=23;
			
			start_str=' ';
			for(int i=0;i<ENEMY_NUM;i++)
			{
				enemy_x[i]=rand()%((20*(i+1))-((i*20)+2)+1)+((i*20)+2);
				enemy_y[i]=2;
			}
			start_screen();
			scanf("%s",&start_str);
			mem.erase(6);

		}

		void gotoxy(int x,int y)
		{
			COORD pos={x-1,y-1};
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
		}
		void delay(int x)
		{
			Sleep(x);
		}
		void scr_mov()
		{
			gotoxy(mem.x,mem.y);
			cout<<mem.st1.c_str();
			gotoxy(mem.x,mem.y-1);
			mem.erase(6);
			if(mem.y==23){
				gotoxy(mem.x-6,23);
				mem.erase(6);
				gotoxy(mem.x+8,23);
				mem.erase(8);
			}
		}
		void key_f(int* score)
		{
			if(kbhit())
			{
				key_in=getch();
				if(key_in==LEFT)
				{
					mem.x--;
				}
				else if(key_in==RIGHT)
				{
					mem.x++;
				}
				else if(key_in==' ')
				{
					sw1=true;
					*score-=100;
					if(gun_y==0)
					{
						gun_x=mem.x+3;
						gun_y=23;
					}
				}
				if(mem.x<1)
				{
					mem.x=1;
				}
				if(mem.x>110)
				{
					mem.x=110;
				}
			}
		}
		void enemy_scr_mov(int i)
		{
			gotoxy(enemy_x[i],enemy_y[i]);
			cout<<mem.st2.c_str();
			gotoxy(enemy_x[i],enemy_y[i]-1);
			mem.erase(6);
			if(enemy_y[i]==24)
			{
				gotoxy(enemy_x[i],24);
				mem.erase(8);
			}
		}
		void enemy_set(){
			for(int i=0;i<ENEMY_NUM;i++)
			{
				if(enemy_y[i]==24)
				{
				
					enemy_y[i]=2;
				
				}
				else
				{
					if(k==10)
					{
				
						k=0;
						
						enemy_y[i]++;
				
					}	
					else
					{
						k++;
					}
				}

			
				enemy_scr_mov(i);
			}
		}
		void gun_mov()
		{
			gotoxy(gun_x,gun_y);
			cout<<"△"<<endl;
			gotoxy(gun_x,gun_y+1);
			mem.erase(3);
			if(gun_y==1)
			{
				gotoxy(gun_x,1);
				mem.erase(3);
			}
		}
		void gun_sw()
		{
			if(sw1==true)
			{
				gun_y--;
				if(gun_y==0)
				{
					sw1=false;
				}
				else
				{
					gun_mov();
				}
			}
		}
		int crash(int x1,int y1,int width1,int* x2,int* y2,int width2,bool sw,int i,int* hit,int* score)
		{
			if((x1+width1)>*x2&&(x1)<(*x2+width2)&&(y1+width1)>*y2&&(y1)<(*y2+width2)&&sw==true)
			{
				*hit-=1;
				*score+=200;
				return i;	
			}
		}

		int player_crash(int x1,int y1,int width1,int* x2,int* y2,int width2,bool sw,int i,int* life_cnt)
		{
			if((x1+width1)>*x2&&(x1)<(*x2+width2)&&(y1+width1)>*y2&&(y1)<(*y2+width2)&&sw==true)
			{
				*life_cnt-=1;
				return i;	
			}
		}
		void crash_f(){
			for(int i=0;i<ENEMY_NUM;i++)
			{
				enemy_s=crash(gun_x,gun_y,1,&enemy_x[i],&enemy_y[i],6,sw1,i,&hit,&score);
				switch(enemy_s){
				case 0:
					gotoxy(enemy_x[i],enemy_y[i]);
					mem.erase(6);
					gotoxy(gun_x,gun_y);
					mem.erase(6);
					gun_y=0;
					if(enemy_y[i]<24){
						enemy_y[i]=2;
						gotoxy(enemy_x[i],enemy_y[i]);
						mem.erase(6);
					}
				case 1:
					gotoxy(enemy_x[i],enemy_y[i]);
					mem.erase(6);
					gotoxy(gun_x,gun_y);
					mem.erase(6);
					gun_y=0;
					if(enemy_y[i]<24){
						enemy_y[i]=2;
						gotoxy(enemy_x[i],enemy_y[i]);
						mem.erase(6);
					}
				case 2:
					gotoxy(enemy_x[i],enemy_y[i]);
					mem.erase(6);
					gotoxy(gun_x,gun_y);
					mem.erase(6);
					gun_y=0;
					if(enemy_y[i]<24){
						enemy_y[i]=2;
						gotoxy(enemy_x[i],enemy_y[i]);
						mem.erase(6);
					}
				case 3:
					gotoxy(enemy_x[i],enemy_y[i]);
					mem.erase(6);
					gotoxy(gun_x,gun_y);
					mem.erase(6);
					gun_y=0;
					if(enemy_y[i]<24){
						enemy_y[i]=2;
						gotoxy(enemy_x[i],enemy_y[i]);
						mem.erase(6);
					}
				case 4:
					gotoxy(enemy_x[i],enemy_y[i]);
					mem.erase(6);
					gotoxy(gun_x,gun_y);
					mem.erase(6);
					gun_y=0;
					if(enemy_y[i]<24){
						enemy_y[i]=2;
						gotoxy(enemy_x[i],enemy_y[i]);
						mem.erase(6);
					}
				}
			}
		}
		void player_crash_f(){
			for(int i=0;i<ENEMY_NUM;i++)
			{
				player_s=player_crash(mem.x,mem.y,6,&enemy_x[i],&enemy_y[i],2,sw1,i,&life_cnt);
				switch(player_s){
				case 0:
					gotoxy(enemy_x[i],enemy_y[i]);
					mem.erase(6);
					gotoxy(gun_x,gun_y);
					mem.erase(6);
					gun_y=0;
					if(enemy_y[i]<24){
						enemy_y[i]=2;
						gotoxy(enemy_x[i],enemy_y[i]);
						mem.erase(6);
					}	
				case 1:
					gotoxy(enemy_x[i],enemy_y[i]);
					mem.erase(6);
					gotoxy(gun_x,gun_y);
					mem.erase(6);
					gun_y=0;
					if(enemy_y[i]<24){
						enemy_y[i]=2;
						gotoxy(enemy_x[i],enemy_y[i]);
						mem.erase(6);
					}		
				case 2:
					gotoxy(enemy_x[i],enemy_y[i]);
					mem.erase(6);
					gotoxy(gun_x,gun_y);
					mem.erase(6);
					gun_y=0;
					if(enemy_y[i]<24){
						enemy_y[i]=2;
						gotoxy(enemy_x[i],enemy_y[i]);
						mem.erase(6);
					}	
				case 3:
					gotoxy(enemy_x[i],enemy_y[i]);
					mem.erase(6);
					gotoxy(gun_x,gun_y);
					mem.erase(6);
					gun_y=0;
					if(enemy_y[i]<24){
						enemy_y[i]=2;
						gotoxy(enemy_x[i],enemy_y[i]);
						mem.erase(6);
					}	
				case 4:
					gotoxy(enemy_x[i],enemy_y[i]);
					mem.erase(6);
					gotoxy(gun_x,gun_y);
					mem.erase(6);
					gun_y=0;
					if(enemy_y[i]<24){
						enemy_y[i]=2;
						gotoxy(enemy_x[i],enemy_y[i]);
						mem.erase(6);
					}	
				}
			}
		}
		void start_screen()
		{
			gotoxy(45,10);
			cout<<"주인공 이동 : 좌우 화살표 키보드"<<endl;
	
			gotoxy(45,13);
			cout<<"	  무기발사: 스페이스바"<<endl;
	
			gotoxy(38,16);
			cout<<"S 키를 누르고 엔터를 누르면 게임이 시작됩니다: ";
		
		}
		void end_screen1(int* life,int* score)
		{
			gotoxy(54,13);
			cout<<"목숨 "<<*life<<" 남음"<<endl;
			gotoxy(54,16);
			cout<<"SCORE : "<<*score<<endl;
	
			gotoxy(55,19);
			cout<<"미션 성공"<<endl;
		}
		void end_screen2(int* hit)
		{
			gotoxy(55,13);
			cout<<"적 "<<*hit<<" 남음"<<endl;
	
			gotoxy(55,16);
			cout<<"미션 실패"<<endl;
		}
		void hit_and_hp(int* hit,int* life)
		{
			gotoxy(40,30);
			cout<<"hit : "<<*hit<<	"		hp : "<<*life;
		}
		void score_and_time(double* time_cnt,int* score)
		{
			gotoxy(80,30);
			cout<<"score : "<<*score<<	"		time : "<<*time_cnt<<"sec";
		}
		void start_erase(){
			gotoxy(45,10);
			mem.erase(40);
			gotoxy(45,13);
			mem.erase(40);
			gotoxy(38,16);
			mem.erase(60);
			start = time(NULL); 
		}
		void time_f(double* time_cnt){
			finish  = time(NULL);
			*time_cnt = (double)(finish - start);
		}
};

int main()
{
	Member mem;
	Airplanegame air;
	
	
	if(air.start_str=='s'||air.start_str=='S')
	{
		air.start_erase();
		
	
		while(1)
		{
			air.hit_and_hp(&air.hit,&air.life_cnt);
			air.score_and_time(&air.time_cnt,&air.score);
			air.key_f(&air.score);
			air.scr_mov();
			air.gun_sw();
			air.enemy_set();
			air.crash_f();
			air.player_crash_f();
			air.time_f(&air.time_cnt);
			
			air.delay(10);
			if(air.hit==0)
			{
				system("CLS");
				air.end_screen1(&air.life_cnt,&air.score);
				break;
			}
			if(air.life_cnt==0)
			{
				system("CLS");
				air.end_screen2(&air.hit);
				break;
			}
		}
	}
	
	system("PAUSE");
	return 0;
}