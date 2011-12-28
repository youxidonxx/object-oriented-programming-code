#include <iostream>
#include <ctime>
#include <string>
#include <conio.h>
#include "3-4.h"
using namespace std;
/**/
 int Canlender::a[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
bool Canlender::IsLeapYear(int year)
{
    return (0 == year % 400) || (0 == year % 4) && (0 != year %100);
}
Canlender::Canlender()
{
 	setOriYear();
	setThisDate();
}
Canlender::~Canlender()
{
}
Canlender::Canlender(int year,int month)
{
	setDate(year,month);
}
void Canlender::PrintLine(int line,bool endline)
{
    char str[16];
    int w = GetWeekday(c_Year, c_Month, 1);
    cout<<'\t';
    for(int i=1+(line-1)*7;i<=line*7;i++)
    {
        if(i<=w || i>Canlender::a[c_Month]+w)
            cout<<"   ";
        else
        {
            sprintf(str,"%2d ",i-w);
            cout<<str;
        }
    }
    if(endline)
        cout<<endl;
    else
        cout<<'\t';
}
void Canlender::PrintMonth()
{
    char str[256];
    cout<<endl;
    sprintf(str,"\t*****%04d��%02d��*****",
		c_Year,c_Month);
    cout<<str<<endl;
    cout<<"\t�� һ �� �� �� �� �� "<<endl;
	
    for(int i=1;i<=6;i++)
    {
        PrintLine(i);
    }
}

int Canlender::GetWeekday(int year/* = 0 */,int month /* = 0 */,int day /* =0 */)
{
	int y = year-START_YEAR;
	int m = month - 1;
	int d = day-1;
	int w = START_WEEK_DAY;
	a[2] = IsLeapYear(year) ? 29:28;
	if (y>START_YEAR||m>2)
	{
		w++;
	}
	w+= y *365;
	w+= y/4;
	w-= y/100;
	w+= y/400;
	for (int i=1;i<=m;i++)
	{
		w+=Canlender::a[i];
	}
	w += d;
	w %= 7;
	return w;
}
void Canlender::setDate(int year,int month /* = 1 */){	//���ó�ʼʱ��
	c_Year=year;
	c_Month=month;
}
void Canlender::setThisDate( ){	//���ó�ʼʱ��
	struct tm *newtime;
	time_t		longTime;
	time(&longTime);
	newtime = localtime(&longTime);
	c_Year = newtime->tm_year+c_oriYear;//1900;
	c_Month = newtime->tm_mon+1;
}

Canlender Canlender::operator + (int n)	//���������ڣ�����ѭ�������������
{										//
    int year = c_Year, 
        month = c_Month + n;
	
    year += month / 13;
    month %= 13;
    month = month?month:1;
    return Canlender(year, month);
}

Canlender Canlender::operator - (int n)
{
    int year = c_Year, 
        month = c_Month - n;
	
    year += month / 13;
    
    if(month<0 && month>-13)
        year -= 1;
	
    while(month<=0)
        month += 12;
	
    month %= 13;
    month = month?month:1;
    return Canlender(year, month);
}
bool Canlender::CheckValid(int year, int month)
{
    return year>=-5600 && year<=5600 && month>0 && month<=12;
}

string weekday[]={"SUN","Mon","TUS","WED","THU","FRI","SAT"};
/*
int main(int argc, char* argv[])
{
	int year,month;
	while(true){
	cout<<endl<<endl
        <<"  ��Esc���˳�����N���������£�"\
        "��PageUp������Ϸ�����PageDown����·���"
        <<"����L/l����ѡ����Ҫ����ʱ��"
		<<endl;
	
	char key = getch();
	
	if(27 == key)
	{
		break;
	}

	switch(key)
	{
	case 'n':
	case 'N':

		system("cls");
		do{
			cout<<"��������ݣ�";
			cin>>year;
			cout<<"�������·ݣ�";
			cin>>month;
			system("cls");
			if(cin.fail())
			{
				
				cin.clear();
				
				cin.ignore();
				month = 0;
			}
		}while(!Canlender::CheckValid(year,month));
		
		c[0].SetDate(year,month);
		
		if(!Canlender::CheckValid(year,month))
		{
			c[0].SetThisDate();
		}
		break;
		
	case 'l':
	case 'L':
		{	 
			cout<<"enter the lasting time you want: ";
			cin>>year;
			cout<<endl;
			Canlender* c=new Canlender[year+1];
			for(int i=0;i<year;i++)
			{	c[i+1]=c[i]+1;
		//	c[0].setOriYear(1776);

				c[i].PrintMonth();
			}
		}
	}
	return 0;
}*/