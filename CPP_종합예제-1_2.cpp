#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
int main(){
	int num[3]={},kor[3]={},eng[3]={},math[3]={},total[3]={};
	double avr[3]={};
	string name[3]={};
	
	int i=0;
	int j=0;
	for(i=0;i<3;i++){
		cout<<"----------------------------------"<<endl;
		num[i]=i+1;
		cout<<num[i]<<"�� �̸��� �Է��Ͻÿ� : ";
		cin>>name[i];
		cout<<num[i]<<"�� ���������� �Է��Ͻÿ� : ";
		cin>>kor[i];
		cout<<num[i]<<"�� ���������� �Է��Ͻÿ� : ";
		cin>>eng[i];
		cout<<num[i]<<"�� ���������� �Է��Ͻÿ� : ";
		cin>>math[i];
		total[i]=kor[i]+eng[i]+math[i];
		avr[i]=total[i]/3.0;
		cout<<"----------------------------------"<<endl;
	}
	

	cout<<"----------------------------------"<<endl;
	cout<<"��ȣ �̸� ���� ���� ���� ���� ���"<<endl;
	cout<<"----------------------------------"<<endl;
	for(i=0;i<3;i++){
		printf("%3d",num[i]);
		cout.width(6);
		cout<<std::right<<name[i];
		printf("%5d%5d%5d%5d%7.2f\n",kor[i],eng[i],math[i],total[i],avr[i]);
	}
	cout<<"----------------------------------"<<endl;
	
	system("PAUSE");
	return 0;
}