#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
int main(){
	int num=0,kor=0,eng=0,math=0,total=0;
	double avr=0;
	
	cout<<"----------------------------------"<<endl;
	cout<<"��ȣ�� �Է��Ͻÿ� : ";
	cin>>num;
	cout<<"���������� �Է��Ͻÿ� : ";
	cin>>kor;
	cout<<"���������� �Է��Ͻÿ� : ";
	cin>>eng;
	cout<<"���������� �Է��Ͻÿ� : ";
	cin>>math;
	total=kor+eng+math;
	avr=total/3.0;
	cout<<"----------------------------------"<<endl;
	cout<<"----------------------------------"<<endl;
	cout<<"��ȣ ���� ���� ���� ���� ���"<<endl;
	cout<<"----------------------------------"<<endl;
	printf("%3d%5d%6d%4d%5d%7.2f\n",num,kor,eng,math,total,avr);
	cout<<"----------------------------------"<<endl;
	system("PAUSE");
	return 0;
}