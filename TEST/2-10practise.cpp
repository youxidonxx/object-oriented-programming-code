#include <iostream>
#include <string>
#include <cstdio>
#include <windows.h>
using namespace std;
/*
void MoveBit(string s,int bitNum,string sDes)
{	
	bitNum=bitNum%94;
	if (bitNum<=0)
	{
		return ;
	}
	int len = s.length(),i;
	string sMap,sTemp;
	for (i=0;i<bitNum;i++)
	{
		sTemp[i]=s[i];
		sMap[len-bitNum+i]=sTemp[i];
	}
	for (i=0;i<len-bitNum;i++)
	{
		sMap[i]=s[i+bitNum];
	}
	sDes=sMap;
	return ;
}*/
//对字符串进行左移位，并得到新字符串
void MoveBit(char c[],int len,int bitNum,char  cDes[])
{
//	cout<<"\n move bit"<<endl;
	memset(cDes,0,len);
	bitNum=bitNum%len;
	if (bitNum<=0)
	{
		return ;
	}
	int  i;
	//不支持变量作数组大小
//	char  cTemp[bitNum], cStart[bitNum];
	char* cTemp = new char[len],*cStart;
	cStart = cTemp;//记录起始地址
	memset(cStart,0,len);
	memset(cTemp,0,len);
	//用于将头bitnum位数据转到ctemp上
	for (i=0;i<bitNum;i++)
	{
		*cTemp= c[i];
		*cTemp++;
//		cout<<c[i]<<i<<endl;
	}
	//将bitnum位之后的数据转到目标数组，则只有最后几位未填充数据
	for (i=0;i<len-bitNum;i++)
	{
		cDes[i]=c[i+bitNum];
//		cout<<cDes[i]<<i<<endl;
	}
//	cout<<".........\n";
	for (i=len-bitNum;i<len;i++)
	{
		cDes[i]=*cStart++;//此处，指针所指数据无法传入数组——>由于字符数组最后有终止符导致无法输出完整字符串
	//	*cStart++;
//		cout<<cDes[i]<<i<<endl;
	}
	cout<<endl;
	for(i=0;i<len+1;i++)
	printf ("%c",cDes[i]);
	printf("\n...%c\n",cDes[0]);
	return ;
}
//接下来则是对二维数组进行遍历，产生一个完全的二维字符数组
/*void WholeArray(char a[][],int times,char b[],int len)
{
	int i;
	memset(a,0,len);

}
*/
//void ProduceTable(char aa[][],)
void ProduceChar(char a[],int iStart,int iEnd)
{
	int i;
	for (i=0;i<iEnd-iStart+1;i++)
	{
		a[i]=char(i+iStart);
		cout <<a[i] ;
	}
	return;
}/*
int main()
{
	int iStart,iEnd;
	iStart=111;
	iEnd=123;
	char c1[]="shaif36545636htdrdhfg j";
	int len = iEnd-iStart;//sizeof(cc);
	char* cc = new char[len];
	char* c2 = new char[len];
	char* c3 = new char[len];
	c2[3]=c1[2];
	ProduceChar(cc,iStart,iEnd-1);
	cout<<endl;
	MoveBit(cc,len,len/2,c2);
 		cout<<"  dd\n" <<endl;
		char aa[12][12];
		for (int n=0;n<len;n++)
		{
			aa[0][n]=cc[n];
		}
	for (int i=1;i<len;i++)
	{
		cout<<i<<endl;
		for(int j=0;j<len;j++)
		{//	aa[i][j]=cc[j];
			cout<<j<<endl;
	//		Sleep(100);
		 	cout<< aa[i][j];
		//	for(int k=0;k<94;k++)
		//	{
				MoveBit(cc,len,j,c2);
		//	}
				for(int k=0;k<len;k++)
					aa[i][k]=c2[k];//完成对编码表的遍历，但速度太慢
		}
 //		cout<<aa[1][i];
	}
//	system("pause");
	cout<<"\n";
	for (  i=0;i<len;i++)
	{
			// 		aa[1][i]=c1[i];
		 cout<< aa[1][i] ;
	}
/*		cout<<"\n";
			for (  i=0;i<len;i++)
				cout<<c2[i];
			cout<<"\n";

	for (  i=0;i<len;i++)
	{
		//		aa[1][i]=c1[i];
		//			cout<< aa[1][i];
		if(c2[i]=='\0')
			i++;
		aa[1][i]=c2[i];
		cout<<aa[1][i];
	}
//	cout<<c1<<"\n"<<c2<<endl;
	return 0;
}*/