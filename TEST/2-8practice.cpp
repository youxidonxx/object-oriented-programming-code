#include <iostream>
#include <string>
#include <math.h>
#include "..\winMain\define.h"
using namespace std;
//the rate range
//double iMaxRate = 4;
//double iMinRate = 1;
//the number range
//long lMaxNum = 1000 000;
//long lMinNum = 1;
/************************************************************************/
/* ¹«Ê½¼ÆËã£ºnext=rate*current*(1-current/1000000)                      */
/************************************************************************/
float PredictTotal(float CurrentTotal,double Rate,int Year)
{
	float PredictNum;
	int i;
	if(Year<=0)
		return -1;
	for (i=0;i<Year;i++)
	{
		PredictNum=Rate*CurrentTotal*(1-CurrentTotal/1000000);
 		CurrentTotal = PredictNum;
		cout<<"next "<<i+1<<" year the number is "<<CurrentTotal<<endl;
	}
	return PredictNum;
}/*
int main(){
	double rate;
	float current;
	int year;
	cout<<"rate(1~4):";
	cin>>rate;
	cout<<"\ncurrent (1~1000000): ";
	cin>>current;
	cout<<"\n year: ";
	cin>>year;
	if (min(rate,4)==4||max(1,rate)==1||min(current,1000000)==1000000||max(1,current)==1||max(1,year)==1)
	{
		return -1;
	}

/*	 year =48;
	 current = 110000;
	 rate = 3.14;
	 float next = PredictTotal(current,rate,year);
	 cout<<"next "<<year<<" is"<<next;
	 return 0;
}*/