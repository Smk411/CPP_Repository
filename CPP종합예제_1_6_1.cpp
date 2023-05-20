#include <iostream>
#include <windows.h>
#include <string.h>
using namespace std;

void gotoxy(int x,int y)
{
	COORD pos={x-1,y-1};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}

struct airplane
{
	int x,y;
	char face[10];
};

int main()
{
	struct airplane hero;
	char st1[20]="¢Ä-¡ã-¢Å";
	strcpy(hero.face,st1);
	hero.x=23;
	hero.y=37;
	gotoxy(hero.x,hero.y);
	cout<<hero.face<<endl;
	system("PAUSE");
	return 0;

}