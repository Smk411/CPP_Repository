#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <io.h>
using namespace std;
void line_p();
void total_sum(int* kor,int* eng,int* math,int* total,int* count);
void average(int* total,double* avr,int* count);
void File_Input(ofstream &out,int* num,string* name,int* kor,int* eng,int* math,string* name_check,int* count);
void File_Output(int* num,string* name,int* kor,int* eng,int* math,int* total,double* avr,int* count);
int main(){
	const int member=10;
	int num[member]={},kor[member]={},eng[member]={},math[member]={},total[member]={};
	double avr[member]={};
	string name[member]={};

	string exit="exit";
	static int count=0;

	ofstream out_file;
	ifstream in_file;
	int i=0;
	int j=0;

	int a,b,c,d,e;

	string aa,bb,cc,dd;
	string name_check[member];
	
	char strPath[]={"D:\\�ո��\\C++\\CPP_���տ���-1_4\\CPP_���տ���-1_4\\text.txt"};
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

	File_Input(out_file,num,name,kor,eng,math,name_check,&count);

	
	File_Output(num,name,kor,eng,math,total,avr,&count);
	
	
	in_file.close();
	
	system("PAUSE");
	return 0;
	
}
void total_sum(int* kor, int* eng, int* math, int* total, int* count) 
{
	int i = 0;
	
	for (i=0;i<*count;i++) 
		{
			
			*(total+i) = *(kor+i) + *(eng+i) + *(math+i);
		}
}
void average(int* total,double* avr, int* count)
{

	int i=0;
	
	for (i = 0; i < *count; i++) 
	{
		
		*(avr+i)=*(total+i)/3.0;
		*(avr+i)=ceilf(*(avr+i)*100)/100;
	}
	
}
void File_Input(ofstream &out,int* num,string* name,int* kor,int* eng,int* math,string* name_check,int* count)
{
	const int member=10;

	string exit="exit";
	out.open("text.txt");
	
	for(int i=*count;i<member;i++)
	{
		
		line_p();
		*(num+i)=i+1;
		
		cout<<*(num+i)<<"�� �̸��� �Է��Ͻÿ�(���� : exit) : ";
		cin>>*(name_check+i);
		
			
		if(*(name_check+i)==exit)
		{
			break;
		}

		else
		{
			*(name+i)=*(name_check+i);
			cout<<*(num+i)<<"�� ���������� �Է��Ͻÿ� : ";
			cin>>*(kor+i);	
			cout<<*(num+i)<<"�� ���������� �Է��Ͻÿ� : ";
			cin>>*(eng+i);
			cout<<*(num+i)<<"�� ���������� �Է��Ͻÿ� : ";
			cin>>*(math+i);
			cout<<*(num+i)<<" "<<*(name+i)<<" "<<*(kor+i)<<" "<<*(eng+i)<<" "<<*(math+i)<<" "<<endl;
			out<<*(num+i)<<" "<<*(name+i)<<" "<<*(kor+i)<<" "<<*(eng+i)<<" "<<*(math+i)<<" "<<endl;
			
			*count+=1;
			line_p();
		}
		
	}
	out.close();

}
void File_Output(int* num,string* name,int* kor,int* eng,int* math,int* total,double* avr,int* count)
{
	
	line_p();
	cout<<"��ȣ �̸� ���� ���� ���� ���� ���"<<endl;
	line_p();
		
	total_sum(kor,eng,math,total,count);

	average(total,avr,count);
	
	
	for(int i=0;i<*count;i++)
	{
		
		cout.width(3);
		cout<<*(num+i);
		cout.width(5);
		cout<<std::right<<*(name+i);
		cout.width(5);
		cout<<std::right<<*(kor+i);
		cout.width(5);
		cout<<std::right<<*(eng+i);
		cout.width(5);
		cout<<std::right<<*(math+i);
		cout.width(5);
		cout<<std::right<<*(total+i);
		cout.width(7);
		cout<<std::right<<*(avr+i)<<endl;
			
			
	}
	line_p();
}
void line_p()
{
	int i=0;
	for(i=0;i<34;i++){
		cout<<"-";
	}
	cout<<endl;
}