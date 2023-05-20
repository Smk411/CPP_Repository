#include <iostream>
#include <windows.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <math.h>
using namespace std;

#define LEFT 75 //Ű���� ȭ��ǥ ���ʹ���Ű�� ���� Ű�ڵ�
#define RIGHT 77 //Ű���� ȭ��ǥ �����ʹ���Ű�� ���� Ű�ڵ�
#define LIFE 3 //�÷��̾��� ü��
#define HIT 30 //����ü�� HIT����ŭ �����߷��� ���ӽ¸�
#define ENEMY_NUM 8 //�ѹ��� ������ �� ����
class Member{ //��� Ŭ����
	private : 
		int x,y; //��,�÷��̾ ���� x,y��
		string st1; //��,�÷��̾��� ���¸� �����ϱ� ���� ����
		bool enemy_sw;
	public :
		
		
		

		Member(){ //�÷��̾��� �ʱ���ġ�� �����ڷ� ����
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
		void erase(int byte_v){ //�Էµ� ����Ʈ��ŭ ����� �Լ�
			for(int j=0;j<byte_v;j++){
				cout<<' ';
		
			}
			cout<<endl;
		}
		
};
class Airplanegame{// ��ɱ����� ���� Ŭ����
	private :
		int score; //���������� �����ϴ� ����
		int k; //�� ��ü�� �ӵ� �����̸� ���� ī��Ʈ����
		bool sw1; //�÷��̾��� ���� ����ġ ����
		
		char key_in; //Ű���� �Ҵ��ϱ� ���� ����
		
		 //���� ������ ����'s'�Է��� ���� ����
		int hit; //HIT�� �޴� ī��Ʈ ����
		int life_cnt; //LIFE�� �޴� ī��Ʈ ����
		double time_cnt; //���� �ð������� ���� ī��Ʈ ����
		
		int gun_x,gun_y;; //�÷��̾��� ������ x��,y��
		int enemy_s; //���� �÷��̾��� ������ �浹������ ����� �浹�ߴ��� ����Ǵ� ����
		int player_s; //�÷��̾�� ���� �浹������ ����� �浹�ߴ��� ����Ǵ� ����
	public :
		Member player; //�÷��̾� ���� Ŭ���� �Ҵ�
		Member enemy[ENEMY_NUM]; //�� ���� Ŭ���� �Ҵ�
		time_t start, finish; //���� �ð������� ���� time_t ����
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

		Airplanegame(){ //AirplanegameŬ������ �����ڷ� �ʱ�ȭ�� ��
			player.SetSt1("��-��-��");
			SetScore(0);
			SetK(0);
			SetEnemy_s(0);
			SetTime_cnt(0);
			SetSw1(false);
			
			SetHit(HIT);
			SetLife_cnt(LIFE);
			player.GetSt1()="��-��-��";
			
			srand(time(NULL));
			
			SetGun_y(23);
			
			start_str=' ';
			
			for(int i=0;i<ENEMY_NUM;i++)
			{
				enemy[i].SetSt1("�¡��");
				enemy[i].SetX(rand()%((13*(i+1))-((i*13)+2)+1)+((i*13)+2)); // ����ü�� ��ġ�� �ʰ� ���� ����
				enemy[i].SetY(2);
			}
			start_screen(); //ó�� ���ӽ���ȭ���� �ҷ���
			scanf("%s",&start_str); //S�� �Է��Ͽ� ����
			player.erase(6);
			
		}
		~Airplanegame(){

		}
		void gotoxy(int x,int y) //�ܼ� Ŀ���� X,Y�� �̵���Ŵ
		{
			COORD pos={x-1,y-1};
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
		}
		void delay(int x) //Sleep�� ȣ���ϴ� delay�Լ�
		{
			Sleep(x);
		}
		void scr_mov() //�÷��̾ ����ϸ� �¿�� �̵��Ҷ� ���� ����Ʈ�� ����
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
		void key_f() //Ű�� �Ҵ��ϸ� ������ ��ǥ�� ������ ������ �ʵ��� �ϴ� �Լ�
		{
			if(kbhit())
			{
				key_in=getch();
				if(key_in==LEFT)//�÷��̾� ���� �̵�
				{
					player.SetX(player.GetX()-1);
				}
				else if(key_in==RIGHT)//�÷��̾� ������ �̵�
				{
					player.SetX(player.GetX()+1);
				}
				else if(key_in==' ') //�÷��̾��� ������ �����̽���
				{
					SetSw1(true); //���� ����ġ true
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
		void enemy_scr_mov(int i) //���� ����ϸ� �Ʒ��� �̵��Ҷ� ���� ����Ʈ�� ����
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
		void enemy_set(){ //���� �̵��ϰ� �ϴ� �Լ�
			
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
		void gun_mov() //�÷��̾��� ������ ����ϴ� �Լ�
		{
			gotoxy(GetGun_x(),GetGun_y());
			cout<<"��"<<endl;
			gotoxy(GetGun_x(),GetGun_y()+1);
			player.erase(3);
			if(GetGun_y()==1)
			{
				gotoxy(GetGun_x(),1);
				player.erase(3);
			}
		}
		void gun_sw() /*�÷��̾��� ������ ���� �����̰� �ϸ� ����ġ�� �������μ� �����̽��ٸ� 
						���������� ������ �۵���*/
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
		//���� �÷��̾��� ������ �浹�˻� �ϴ� �Լ�
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
		//�÷��̾�� ���� �浹�˻� �ϴ� �Լ�
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
		//���� ����ŭ for�ݺ��ϴٰ� �浹���� i����
		void crash_f(){
			for(int i=0;i<ENEMY_NUM;i++)
			{
				crash(GetGun_x(),GetGun_y(),1,6,i);

			}
		}
		//���� ����ŭ for�ݺ��ϴٰ� �浹���� i����
		void player_crash_f(){
			for(int i=0;i<ENEMY_NUM;i++)
			{
				player_crash(player.GetX(),player.GetY(),6,2,i);
				
			}
		}
		void start_screen() //ó�� ������ ȭ���� ����ϴ� �Լ�
		{
			gotoxy(45,10);
			cout<<"���ΰ� �̵� : �¿� ȭ��ǥ Ű����"<<endl;
	
			gotoxy(45,13);
			cout<<"	  ����߻�: �����̽���"<<endl;
	
			gotoxy(38,16);
			cout<<"S Ű�� ������ ���͸� ������ ������ ���۵˴ϴ�: ";
		
		}
		void end_screen1() //�̼Ǽ����� ȭ���� ����ϴ� �Լ�
		{
			gotoxy(54,13);
			cout<<"��� "<<GetLife_cnt()<<" ����"<<endl;
			gotoxy(54,16);
			cout<<"SCORE : "<<GetScore()<<endl;
	
			gotoxy(55,19);
			cout<<"�̼� ����"<<endl;
		}
		void end_screen2() //�̼ǽ����� ȭ���� ����ϴ� �Լ�
		{
			gotoxy(55,13);
			cout<<"�� "<<GetHit()<<" ����"<<endl;
	
			gotoxy(55,16);
			cout<<"�̼� ����"<<endl;
		}
		void hit_and_hp() //hit,life_cnt������ ����ϴ� �Լ�
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
		void score_and_time() //time_cnt,score������ ����ϴ� �Լ�
		{
			gotoxy(80,30);
			cout<<"score : "<<GetScore()<<	"		time : "<<GetTime_cnt()<<"sec";
		}
		void start_erase(){ //����ȭ���� ������ �����Ҷ� ����� �Լ�
			gotoxy(45,10);
			player.erase(40);
			gotoxy(45,13);
			player.erase(40);
			gotoxy(38,16);
			player.erase(60);
			start = time(NULL); 
		}
		void time_f(){//���� �ð��� time_cnt�� �����ϴ� �Լ�
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