/************************************************************************/
/* ϰ��2-5 �������� ����ֻ��string���Ͳ�������ʱ�����ȴ���10����ӡͷ10��                              
	����ȫ����ӡ������string������int�������򳤶�<nʱ����ӡ��>n����ӡ
	ǰn����*/
/************************************************************************/
#include<iostream>
#include <string>
#include <assert.h>
using namespace std;
void print_str(string );
void print_str(string,int);
void print_str(string s){
	int len;
	//len=sizeof(s)/sizeof(string);
	len=s.length();
	if (len<=10)
	{
		for (int i=0;i<len;i++)
		{
			cout<<s[i];
		}
	}
	else
	{
		for (int i=0;i<10;i++)
		{
			cout<<s[i];
		}
	}
	return;
}
void print_str(string s,int n)
{
	int len;
	assert(n>0);
	//len=sizeof(s)/sizeof(string);
	len=s.length();
	if (len<=n)
	{
		for (int i=0;i<len;i++)
		{
			cout<<s[i];
		}
	}
	else
	{
		for (int i=0;i<n;i++)
		{
			cout<<s[i];
		}
	}
	return;
}
/*int main()
{
	string s1,s2,s3;
	int n1=4,n2=12,n3=-1;
	s1="thise fasifhi";
	s2="fadfa";
	s3="agfasawer";

	print_str(s3);
	cout<<endl;
	print_str(s2);
	cout<<endl;
	print_str(s2,5);
	cout<<endl;
	print_str(s1,8);
	cout<<endl;
	return;
}

*/