#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <io.h>
#include <memory.h>
using namespace std;
void line_p();
void total_sum(int* kor,int* eng,int* math,int* total,int* count);
void average(int* total,double* avr,int* count);
void File_Input(ofstream &out,int* num,string* name,int* kor,int* eng,int* math,string* name_check,int* count,int* member);
void File_Output(int* num,string* name,int* kor,int* eng,int* math,int* total,double* avr,int* count);
int main(){
	int member=0;
	ifstream in_file;
	int m=0;
	char strPath1[]={"D:\\손명규\\C++\\CPP_종합예제-1_5\\CPP_종합예제-1_5\\member.txt"};
	int nResult1=_access(strPath1,0);
	in_file.open("member.txt");

	if(nResult1==0)
	{
		while(!in_file.eof())
		{
			
			in_file>>m;
			member=m;
			
			
		}
	}
	
	else if(nResult1==-1)
	{
		cout<<"파일을 찾을 수 없습니다"<<endl;
	}
	in_file.close();
	if(member==0)
	{
		line_p();
		cout<<"성적처리 인원수 입력(명):";
		cin >> member;
		line_p();
	}
	else if(member!=0)
	{
		line_p();
		cout<<"성적처리 인원수는 "<<member<<"명입니다"<<endl;
		line_p();
	}
	int* num=new int[member];
	string* name=new string[member];
	int* kor=new int[member];
	int* eng=new int[member];
	int* math=new int[member];
	int* total=new int[member];
	double* avr=new double[member];
	string* name_check=new string[member];
	memset(num,0,sizeof(int)*member);
	memset(name,0,sizeof(string)*member);
	memset(kor,0,sizeof(int)*member);
	memset(eng,0,sizeof(int)*member);
	memset(math,0,sizeof(int)*member);
	memset(total,0,sizeof(int)*member);
	memset(avr,0,sizeof(double)*member);
	memset(name_check,0,sizeof(string)*member);
	
	string exit="exit";
	int count=0;
	ofstream out_file;
	int i=0;
	int j=0;
	int a,b,c,d;
	string aa,bb,cc,dd;

	char strPath[]={"D:\\손명규\\C++\\CPP_종합예제-1_5\\CPP_종합예제-1_5\\text.txt"};
	int nResult=_access(strPath,0);
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
			cout<<math[j]<<" "<<endl;
			
		}
		

	}
	
	else if(nResult==-1)
	{
		cout<<"파일을 찾을 수 없습니다"<<endl;
	}
	
	
	
	File_Input(out_file,num,name,kor,eng,math,name_check,&count,&member);

	
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
void File_Input(ofstream &out,int* num,string* name,int* kor,int* eng,int* math,string* name_check,int* count,int* member)
{


	string exit="exit";
	out.open("text.txt");
	
	for(int i=*count;i<*member;i++)
	{
		
		line_p();
		*(num+i)=i+1;
		
		cout<<*(num+i)<<"번 이름을 입력하시오(종료 : exit) : ";
		cin>>*(name_check+i);
		
			
		if(*(name_check+i)==exit)
		{
			break;
		}

		else
		{
			*(name+i)=*(name_check+i);
			cout<<*(num+i)<<"번 국어점수를 입력하시오 : ";
			cin>>*(kor+i);	
			cout<<*(num+i)<<"번 영어점수를 입력하시오 : ";
			cin>>*(eng+i);
			cout<<*(num+i)<<"번 수학점수를 입력하시오 : ";
			cin>>*(math+i);
			cout<<*(num+i)<<" "<<*(name+i)<<" "<<*(kor+i)<<" "<<*(eng+i)<<" "<<*(math+i)<<" "<<endl;
			out<<*(num+i)<<" "<<*(name+i)<<" "<<*(kor+i)<<" "<<*(eng+i)<<" "<<*(math+i)<<" "<<endl;
			
			*count+=1;
			line_p();
		}
		
	}
	out.close();
	out.open("member.txt");
	out<<*member;
}
void File_Output(int* num,string* name,int* kor,int* eng,int* math,int* total,double* avr,int* count)
{
	
	line_p();
	cout<<"번호 이름 국어 영어 수학 총점 평균"<<endl;
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