#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
int main(){
	int num=0,kor=0,eng=0,math=0,total=0;
	double avr=0;
	
	cout<<"----------------------------------"<<endl;
	cout<<"번호를 입력하시오 : ";
	cin>>num;
	cout<<"국어점수를 입력하시오 : ";
	cin>>kor;
	cout<<"영어점수를 입력하시오 : ";
	cin>>eng;
	cout<<"수학점수를 입력하시오 : ";
	cin>>math;
	total=kor+eng+math;
	avr=total/3.0;
	cout<<"----------------------------------"<<endl;
	cout<<"----------------------------------"<<endl;
	cout<<"번호 국어 영어 수학 총점 평균"<<endl;
	cout<<"----------------------------------"<<endl;
	printf("%3d%5d%6d%4d%5d%7.2f\n",num,kor,eng,math,total,avr);
	cout<<"----------------------------------"<<endl;
	system("PAUSE");
	return 0;
}