#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <io.h>
using namespace std;
int main(){
	const int member=10;
	int num[member]={},kor[member]={},eng[member]={},math[member]={},total[member]={};
	double avr[member]={};
	string name[member]={};

	string exit="exit";

	int count=0;
	int count2=0;
	ofstream out_file;
	ifstream in_file;
	int i=0;
	int j=0;

	int a,b,c,d,e;

	string aa,bb,cc,dd;
	string name_check[member];

	char strPath[]={"D:\\�ո��\\C++\\CPP_���տ���-1_3\\CPP_���տ���-1_3\\text.txt"};
	int nResult=access(strPath,0);
	/*out_file.open("data.dat");
	out_file<<aa<<" "<<bb<<""<<cc<<endl;
	out_file<<aa<<" "<<bb<<" "<<cc;
	out_file.close();*/
	in_file.open("text.txt");


	if(nResult==0)
	{
		while(!in_file.eof())
		{
			
			in_file>>a>>aa>>b>>c>>d;
			num[count]=a;
			name[count]=aa;
			kor[count]=b;
			eng[count]=c;
			math[count]=d;
			count++;
			
		}
		count--;
		for(j=0;j<count;j++)
		{
			cout<<num[j]<<" ";
			cout<<name[j]<<" ";
			cout<<kor[j]<<" ";
			cout<<eng[j]<<" ";
			cout<<math[j]<<" ";
			
		}
	}
	
	else if(nResult==-1)
	{
		cout<<"������ ã�� �� �����ϴ�"<<endl;
	}


	out_file.open("text.txt");
	count2=count;	
	for(i=count2;i<member;i++)
	{
		
		cout<<"----------------------------------"<<endl;
		num[i]=i+1;
		
		cout<<num[i]<<"�� �̸��� �Է��Ͻÿ�(���� : exit) : ";
		cin>>name_check[i];
		
			
		if(name_check[i]==exit)
		{
			break;
		}

		else
		{
			name[i]=name_check[i];
			cout<<num[i]<<"�� ���������� �Է��Ͻÿ� : ";
			cin>>kor[i];	
			cout<<num[i]<<"�� ���������� �Է��Ͻÿ� : ";
			cin>>eng[i];
			cout<<num[i]<<"�� ���������� �Է��Ͻÿ� : ";
			cin>>math[i];
			cout<<num[i]<<" "<<name[i]<<" "<<kor[i]<<" "<<eng[i]<<" "<<math[i]<<" "<<endl;
			out_file<<num[i]<<" "<<name[i]<<" "<<kor[i]<<" "<<eng[i]<<" "<<math[i]<<" "<<endl;
			
			count++;
			cout<<"----------------------------------"<<endl;
		}
	}
	cout<<"----------------------------------"<<endl;
	cout<<"��ȣ �̸� ���� ���� ���� ���� ���"<<endl;
	cout<<"----------------------------------"<<endl;
		

	for(i=0;i<count;i++)
	{
		total[i]=kor[i]+eng[i]+math[i];
		avr[i]=total[i]/3.0;
		avr[i]=ceilf(avr[i]*100)/100;
		cout.width(3);
		cout<<num[i];
		cout.width(5);
		cout<<std::right<<name[i];
		cout.width(5);
		cout<<std::right<<kor[i];
		cout.width(5);
		cout<<std::right<<eng[i];
		cout.width(5);
		cout<<std::right<<math[i];
		cout.width(5);
		cout<<std::right<<total[i];
		cout.width(7);
		cout<<std::right<<avr[i]<<endl;
			
			
	}
	cout<<"----------------------------------"<<endl;
	in_file.close();
	out_file.close();
	system("PAUSE");
	return 0;
	
}