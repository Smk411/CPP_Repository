#include <iostream>
#include <windows.h>
#include <string.h>
#include <conio.h>
using namespace std;

#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
void gotoxy(int x,int y)
{
	COORD pos={x-1,y-1};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}
void clrscr(void)
{
	system("CLS");
}
struct airplane
{
	int x,y;
	char face[10];
};
void scr_mov(int x,int y,char fa[10])
{
	gotoxy(x,y);
	cout<<fa<<endl;
}
int main()
{
	struct airplane hero;
	char st1[20]="¢Ä-¡ã-¢Å";
	strcpy(hero.face,st1);
	hero.x=23;
	hero.y=37;
	char key_in;
	while(1)
	{
		clrscr();
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
			else if(key_in==UP)
			{
				hero.y--;
			}
			else if(key_in==DOWN)
			{
				hero.y++;
			}
		}
		scr_mov(hero.x,hero.y,hero.face);
	}
	system("PAUSE");
	return 0;

}