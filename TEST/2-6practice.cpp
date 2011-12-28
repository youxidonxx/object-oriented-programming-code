#include <iostream>
#include <string>
using namespace std;

struct	numeric{
	long	a[10];
};
void print(numeric num){
	int i;
	for (i=0;i<10;i++)
	{
		cout<<num.a[i]<<endl;
	}
}
void print(string s){	
	cout<<s<<endl;
}/*
int main()
{
	string s1 = "shitier";
	numeric num={124,56878,45,10,44};
	print(s1);
	cout<<"..."<<endl;
	print(num);
	int  a=32;
	char* c = new char[10];
	char b[]="afewf11";
	for (int i=0;i<22;i++,a++)
	{
		cout<<(char)(a)<<endl;
	}
	for (i=0;i<sizeof(b);i++)
	{
		*c++=b[i];
		cout<<b[i];
	}
	return ;
}
*/