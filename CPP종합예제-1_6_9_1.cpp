#include <iostream>
#include <windows.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <math.h>
using namespace std;

#define LEFT 75 //키보드 화살표 왼쪽방향키에 대한 키코드
#define RIGHT 77 //키보드 화살표 오른쪽방향키에 대한 키코드
#define LIFE 3 //플레이어의 체력
#define HIT 30 //적개체를 HIT수만큼 쓰러뜨려야 게임승리
#define ENEMY_NUM 8 //한번에 나오는 적 숫자
class Member{ //멤버 클래스
	private : 
		int x,y; //적,플레이어에 대한 x,y값
		string st1; //적,플레이어의 형태를 저장하기 위한 변수
		bool enemy_sw;
	public :
		
		
		

		Member(){ //플레이어의 초기위치를 생성자로 정함
			x=55;
			y=23;
			SetEnemy_sw(true);
		}
		~Member(){

		}
		int GetX(){
			
			return x;
		}
		void SetX(int setX){
			x=setX;
		}
		int GetY(){
			
			return y;
		}
		void SetY(int setY){
			y=setY;
		}
		string GetSt1(){
			return st1;
		}
		void SetSt1(string setSt1){
			st1=setSt1;
		}
		bool GetEnemy_sw(){
			return enemy_sw;
		}
		void SetEnemy_sw(bool setEnemy_sw){
			enemy_sw=setEnemy_sw;
		}
		void erase(int byte_v){ //입력된 바이트만큼 지우는 함수
			for(int j=0;j<byte_v;j++){
				cout<<' ';
		
			}
			cout<<endl;
		}
		
};
class Airplanegame{// 기능구현을 위한 클래스
	private :
		int score; //게임점수를 저장하는 변수
		int k; //적 기체의 속도 딜레이를 위한 카운트변수
		bool sw1; //플레이어의 공격 스위치 변수
		
		char key_in; //키값을 할당하기 위한 변수
		
		 //게임 시작을 위해's'입력을 위한 변수
		int hit; //HIT를 받는 카운트 변수
		int life_cnt; //LIFE를 받는 카운트 변수
		double time_cnt; //게임 시간측정을 위한 카운트 변수
		
		int gun_x,gun_y;; //플레이어의 공격의 x값,y값
		int enemy_s; //적과 플레이어의 공격이 충돌했을때 몇번과 충돌했는지 저장되는 변수
		int player_s; //플레이어와 적과 충돌했을때 몇번과 충돌했는지 저장되는 변수
	public :
		Member player; //플레이어 관련 클래스 할당
		Member enemy[ENEMY_NUM]; //적 관련 클래스 할당
		time_t start, finish; //게임 시간측정을 위한 time_t 변수
		char start_str;
		int GetScore(){
			return score;
		}
		void SetScore(int setScore){
			score=setScore;
		}
		int GetK(){
			return k;
		}
		void SetK(int setK){
			k=setK;
		}
		bool GetSw1(){
			return sw1;
		}
		void SetSw1(bool setSw1){
			sw1=setSw1;
		}

		char GetKey_in(){
			return key_in;
		}
		void SetKey_in(char setKey_in){
			key_in=setKey_in;
		}
		char GetStart_str(){
			return start_str;
		}
		void SetStart_str(char setStart_str){
			start_str=setStart_str;
		}
		int GetHit(){
			return hit;
		}
		void SetHit(int setHit){
			hit=setHit;
		}
		int GetLife_cnt(){
			return life_cnt;
		}
		void SetLife_cnt(int setLife_cnt){
			life_cnt=setLife_cnt;
		}
		double GetTime_cnt(){
			return time_cnt;
		}
		void SetTime_cnt(double setTime_cnt){
			time_cnt=setTime_cnt;
		}
		int GetGun_x(){
			return gun_x;
		}
		void SetGun_x(int setGun_x){
			gun_x=setGun_x;
		}
		int GetGun_y(){
			return gun_y;
		}
		void SetGun_y(int setGun_y){
			gun_y=setGun_y;
		}
		int GetEnemy_s(){
			return enemy_s;
		}
		void SetEnemy_s(int setEnemy_s){
			enemy_s=setEnemy_s;
		}
		int GetPlayer_s(){
			return player_s;
		}
		void SetPlayer_s(int setPlayer_s){
			player_s=setPlayer_s;
		}

		Airplanegame(){ //Airplanegame클래스의 생성자로 초기화를 함
			player.SetSt1("◐-▲-◑");
			SetScore(0);
			SetK(0);
			SetEnemy_s(0);
			SetTime_cnt(0);
			SetSw1(false);
			
			SetHit(HIT);
			SetLife_cnt(LIFE);
			player.GetSt1()="◐-▲-◑";
			
			srand(time(NULL));
			
			SetGun_y(23);
			
			start_str=' ';
			
			for(int i=0;i<ENEMY_NUM;i++)
			{
				enemy[i].SetSt1("◈↓◈");
				enemy[i].SetX(rand()%((13*(i+1))-((i*13)+2)+1)+((i*13)+2)); // 적기체가 겹치지 않게 랜덤 스폰
				enemy[i].SetY(2);
			}
			start_screen(); //처음 게임시작화면을 불러옴
			scanf("%s",&start_str); //S를 입력하여 시작
			player.erase(6);
			
		}
		~Airplanegame(){

		}
		void gotoxy(int x,int y) //콘솔 커서를 X,Y로 이동시킴
		{
			COORD pos={x-1,y-1};
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
		}
		void delay(int x) //Sleep을 호출하는 delay함수
		{
			Sleep(x);
		}
		void scr_mov() //플레이어를 출력하며 좌우로 이동할때 이전 바이트를 지움
		{
			gotoxy(player.GetX(),player.GetY());
			cout<<player.GetSt1().c_str();
			gotoxy(player.GetX(),player.GetY()-1);
			player.erase(6);
			if(player.GetY()==23){
				gotoxy(player.GetX()-6,23);
				player.erase(6);
				gotoxy(player.GetX()+8,23);
				player.erase(8);
			}
		}
		void key_f() //키를 할당하며 지정된 좌표값 밖으로 나가지 않도록 하는 함수
		{
			if(kbhit())
			{
				key_in=getch();
				if(key_in==LEFT)//플레이어 왼쪽 이동
				{
					player.SetX(player.GetX()-1);
				}
				else if(key_in==RIGHT)//플레이어 오른쪽 이동
				{
					player.SetX(player.GetX()+1);
				}
				else if(key_in==' ') //플레이어의 공격은 스페이스바
				{
					SetSw1(true); //공격 스위치 true
					SetScore(GetScore()-100);
					if(GetGun_y()==0)
					{
						SetGun_x(player.GetX()+3);
						SetGun_y(23);
					}
				}
				if(player.GetX()<1)
				{
					player.SetX(1);
				}
				if(player.GetX()>110)
				{
					player.SetX(110);
				}
			}
		}
		void enemy_scr_mov(int i) //적을 출력하며 아래로 이동할때 이전 바이트를 지움
		{
			gotoxy(enemy[i].GetX(),enemy[i].GetY());
			cout<<enemy[i].GetSt1().c_str();
			gotoxy(enemy[i].GetX(),enemy[i].GetY()-1);
			player.erase(6);
			if(enemy[i].GetY()==24)
			{
				gotoxy(enemy[i].GetX(),24);
				player.erase(8);
			}
		}
		void enemy_set(){ //적을 이동하게 하는 함수
			
			for(int i=0;i<ENEMY_NUM;i++)
			{
				if(enemy[i].GetEnemy_sw()==true){
					if(enemy[i].GetY()==24)
					{
				
						enemy[i].SetY(2);
				
					}
					else
					{
						if(k==10)
						{
				
							k=0;
						
							enemy[i].SetY(enemy[i].GetY()+1);
				
						}	
						else
						{
							k++;
						}
					}

			
					enemy_scr_mov(i);
				}
			}
		}
		void gun_mov() //플레이어의 공격을 출력하는 함수
		{
			gotoxy(GetGun_x(),GetGun_y());
			cout<<"△"<<endl;
			gotoxy(GetGun_x(),GetGun_y()+1);
			player.erase(3);
			if(GetGun_y()==1)
			{
				gotoxy(GetGun_x(),1);
				player.erase(3);
			}
		}
		void gun_sw() /*플레이어의 공격을 위로 움직이게 하며 스위치를 넣음으로서 스페이스바를 
						누를때마다 공격이 작동함*/
		{
			if(GetSw1()==true)
			{
				SetGun_y(GetGun_y()-1);
				if(GetGun_y()==0)
				{
					SetSw1(false);
				}
				else
				{
					gun_mov();
				}
			}
		}
		//적과 플레이어의 공격을 충돌검사 하는 함수
		void crash(int x1,int y1,int width1,int width2,int i)
		{
			if((x1+width1)>enemy[i].GetX()&&(x1)<(enemy[i].GetX()+width2)&&(y1+width1)>enemy[i].GetY()&&(y1)<(enemy[i].GetY()+width2)&&GetSw1()==true)
			{
				SetHit(GetHit()-1);
				SetScore(GetScore()+500);
				gotoxy(GetGun_x(),GetGun_y());
				player.erase(6);
				SetGun_y(0);
				SetSw1(false);         
				gotoxy(enemy[i].GetX(),enemy[i].GetY());
				player.erase(6);
				enemy[i].SetY(2);
				gotoxy(enemy[i].GetX(),enemy[i].GetY());
				player.erase(6);
				
			}
			
		}
		//플레이어와 적을 충돌검사 하는 함수
		void player_crash(int x1,int y1,int width1,int width2,int i)
		{
			if((x1+width1)>enemy[i].GetX()&&(x1)<(enemy[i].GetX()+width2)&&(y1+width1)>enemy[i].GetY()&&(y1)<(enemy[i].GetY()+width2)&&enemy[i].GetEnemy_sw()==true)
			{
				
				SetLife_cnt(GetLife_cnt()-1);
				enemy[i].SetEnemy_sw(false);
				gotoxy(enemy[i].GetX(),enemy[i].GetY());
				player.erase(6);

				enemy[i].SetY(2);
				enemy[i].SetEnemy_sw(true);
			}
			
			
		}
		//적의 수만큼 for반복하다가 충돌순간 i전달
		void crash_f(){
			for(int i=0;i<ENEMY_NUM;i++)
			{
				crash(GetGun_x(),GetGun_y(),1,6,i);

			}
		}
		//적의 수만큼 for반복하다가 충돌순간 i전달
		void player_crash_f(){
			for(int i=0;i<ENEMY_NUM;i++)
			{
				player_crash(player.GetX(),player.GetY(),6,2,i);
				
			}
		}
		void start_screen() //처음 시작전 화면을 출력하는 함수
		{
			gotoxy(45,10);
			cout<<"주인공 이동 : 좌우 화살표 키보드"<<endl;
	
			gotoxy(45,13);
			cout<<"	  무기발사: 스페이스바"<<endl;
	
			gotoxy(38,16);
			cout<<"S 키를 누르고 엔터를 누르면 게임이 시작됩니다: ";
		
		}
		void end_screen1() //미션성공한 화면을 출력하는 함수
		{
			gotoxy(54,13);
			cout<<"목숨 "<<GetLife_cnt()<<" 남음"<<endl;
			gotoxy(54,16);
			cout<<"SCORE : "<<GetScore()<<endl;
	
			gotoxy(55,19);
			cout<<"미션 성공"<<endl;
		}
		void end_screen2() //미션실패한 화면을 출력하는 함수
		{
			gotoxy(55,13);
			cout<<"적 "<<GetHit()<<" 남음"<<endl;
	
			gotoxy(55,16);
			cout<<"미션 실패"<<endl;
		}
		void hit_and_hp() //hit,life_cnt변수를 출력하는 함수
		{
			gotoxy(40,30);
			cout<<"hit : "<<GetHit()<<	"		hp : "<<GetLife_cnt();
			gotoxy(20,30);
			if(GetSw1()==true){
				cout<<"true ";
			}
			else if(GetSw1()==false){
				cout<<"false";
			}
		}
		void score_and_time() //time_cnt,score변수를 출력하는 함수
		{
			gotoxy(80,30);
			cout<<"score : "<<GetScore()<<	"		time : "<<GetTime_cnt()<<"sec";
		}
		void start_erase(){ //시작화면을 게임이 시작할때 지우는 함수
			gotoxy(45,10);
			player.erase(40);
			gotoxy(45,13);
			player.erase(40);
			gotoxy(38,16);
			player.erase(60);
			start = time(NULL); 
		}
		void time_f(){//게임 시간을 time_cnt에 저장하는 함수
			finish  = time(NULL);
			SetTime_cnt((double)(finish - start));
		}
};

int main()
{
	Airplanegame air;
	
	
	if(air.GetStart_str()=='s'||air.GetStart_str()=='S')
	{
		air.start_erase();
		
	
		while(1)
		{
		
			air.hit_and_hp();
			air.score_and_time();
			air.key_f();
			air.scr_mov();
			air.gun_sw();
			air.enemy_set();
			air.crash_f();
			air.player_crash_f();
			air.time_f();
			
			air.delay(10);
			if(air.GetHit()==0)
			{
				system("CLS");
				air.end_screen1();
				break;
			}
			if(air.GetLife_cnt()==0)
			{
				system("CLS");
				air.end_screen2();
				break;
			}
		}
	}
	
	system("PAUSE");
	return 0;
}