#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <time.h>
using namespace std;

#define max(x,y)	x>=y?x:y
#define min(x,y)	x<=y?x:y
class Set
{
public:
	Set(int n,int range);
	void addSet(int n);
	void printSet();
	bool deleteEle(int ele);
	int* setIntersection(Set& s2);
	~Set();
protected:
private:
	Set();
	int* p,*start;
	int size;
	bool findElement(int ele,int& pos);
};
int*	Set::setIntersection(Set& s2)
{
	int l1 = size;
	int l2 = s2.size;
	int *temp = new int[l1+l2];
	int l = min(l1,l2);
	int ll = max(l1,l2);
	int pos = 0;
	if(l==l1){	//本身为小数组
		for (int i=0;i<l;i++)
		{
			*(temp+i) = *(p+i);
			cout<<"\ntemp..."<<*(temp+i);
		}
		for (i=0;i<ll;i++)
		{
			if (findElement(*(s2.p+i),pos)==false)
			{
				*(temp+i+l)=*(s2.p+i);
			cout<<"\ntemp..."<<*(temp+l+i);
			}
	//		else
	//			i=i+1;
		}
	}
	else				//s2是小数组
	{
		for (int i=0;i<l;i++)
		{
			*(temp+i) = *(s2.p+i);
			cout<<"\ntemp..."<<*(temp+i);
		}
		for ( i=0;i<ll;i++)
		{
			if (s2.findElement(*(p+i),pos)==false)
			{
				*(temp+i+l)=*(p+i);
				cout<<"\ntemp..."<<*(temp+l+i);
			}
		}
	}
	return temp;
}
Set::~Set()
{
	size = 0;
	p = NULL;
	free(start);
}
void	Set::printSet()
{
	if(size<=0)
		return;
	for (int i=0;i<size;i++)
	{
		cout<<"\n... p[i] = "<<i<<"...."<<*(p+i);
	}
}
bool	Set::deleteEle(int ele)
{
	int pos = 0;
	if (!findElement(ele,pos))
	{
		cout<<"\n can't find "<<ele;
		return false;
	}
	for (int i=pos;i<size-1;i++)
	{
		*(p+i)=*(p+i+1);
	}
	size--;
	cout<<"\ndelete ok.";
	return true;
}

bool	Set::findElement(int ele,int& pos)
{
	p=start;
	int i = 0;
	while(i!=size)
	{
		if(*(p+i) == ele)
		{	
			pos = i;
			return true;
		}
			i++;
//			*p++;
	}
	pos = i;
	return false;
}
void Set::addSet(int n)	//
{
	p = (int*)realloc(start,(size+1)*sizeof(int));
	start = p;
	*(p+size) = n;
	cout<<"\nthe added number: "<<*(p+size);
	size= size+1;
}

Set::Set(int n,int range)			//不重复随机序列
{
	size=0;
	srand(time(0));
	 p =(int*) malloc(n*sizeof(int));
	 start = p;
	 int noRepeate,temp,m=0;
	 cout<<"...."<<endl;
	 while(size<n){
	 for (int i = 0;i<n+m;i++)
	 {
		 noRepeate = 1;
		 temp=rand()%(range+1);
		for (int j=0;j<i;j++)
		{
			 if (*(p+j)==temp)
			 {
				 noRepeate = 0;		//做判断,看是否含有重复标志
				m++;				//作为偏移补充量
			 }
		}
		if(noRepeate==1)
		{
			 *(p+i-m) =temp ;
			 cout<<"\n p = "<<*(p+i-m);
		}
		size++;						//停止条件
	 }
	 }
	 size = n;
}
/*
int main()
{
	int l1,l2,range1,range2;
	cout<<"input a number: ";
	cin>>l1;
	cout<<" input range number ";
	cin>>range1;

	cout<<"\ninput a number: ";
	cin>>l2;
	cout<<" input range number ";
	cin>>range2;

	Set	s1(l1,range1),s2(l2,range2);
//	s1.Set(l1);
//	s2.Set(l2);
	cout<<"\n\n";
//	cin>>l1;
//	s2.addSet(l1);
//	s2.printSet();
//	cout<<"\n delete number:";
//	cin>>l2;
//	s2.deleteEle(l2);
//	s2.printSet();
	int *yy;
	yy=s1.setIntersection(s2);

	return 0;
}
*/
/*int main()
{
	int n,m;
 	cin>>n;
	m = n;
	srand(time(0));
	int* p =NULL,*q;
	p	= (int*)malloc(sizeof(int)*n);
  	q =  p;		//将其屏蔽
	for(int i = 0;i<n;i++)
	{
		*(p+i) = rand()%(n+1);
		cout<<"\n p = "<<*(p+i);
	}
	int l2;
	cin>>l2;
	int* pn  = NULL;//= new int[l2];
	pn	= (int*)malloc(sizeof(int)*l2);
	for( i = 0;i<l2;i++)
	{
		*(pn+i) = rand()%(l2+1);
		cout<<"\n pn = "<<*(pn+i);
	}
	
	int l=min(n,l2),ll = max(n,l2);
	int* temp = new int[l+ll];
	if(n<l2)
	{
		for (i=0;i<l;i++)
		{
			temp[i] = *(p+i);
			cout<<"\n...temp "<<temp[i];
		}
		for (i=0;i<l2;i++)
		{
			temp[n+i] = *(pn+i);
			cout<<"\n...temp "<<temp[i];
		}
	}
	else
	{
		for(i=0;i<l2;i++)
		{	
			temp[i] = *(pn+i);
			cout<<"\n.2..temp "<<temp[i];
		}
		for (i=0;i<n;i++)
		{
			for(int j = 0;j<n;j++)
			{	if (temp[i]==*(p+j))
				{
					i=i+1;
	//				return;
				}
			}
			temp[l2+i] = *(p+i);
			cout<<"\n.1..temp "<<temp[l2+i];
		}
	}
	cout<<"\n,,,"<<endl;
	
	int sear,pos;
	cout<<"\nenter the number you want: ";
	cin>>sear;
	i = 0;
//	p =q;		
	while(i!=n)
	{
		if (*(p+i)==sear)
		{
			pos =i;
			cout<<"the position is :"<<pos;
			break;
		}
		i++;
//		*(p+i);
	}


//	p =q;	//用于删除元素
	if(pos>0)
	{
		for (i=0;i<pos;i++)
		{
			cout<<"\n... "<<i<<"..."<<*(p+i);
		}
		for (i=pos;i<m-1;i++)
		{
			*(p+i) = *(p+i+1);
			cout<<"\n.... "<<i<<"..."<<*(p+i);
		}
	}
*/
	//	free(p);
//	 	free(q);	//free掉的是起始指针地址对象
//		return 1;

//}
/*
 	cin>> n ;	//将Q换成P，以上出现错误
	 p =(int*) realloc(q,n*sizeof(int));
	 q =  p;	 
	 for( i = m;i<n;i++)
	 {	
		 *(p+i) = rand()%(n+1);
	 }
	 for( i =0;i<n;i++)
	 {cout<<"\n p = "<<*p;
	 *p++;
	 }
//	 *p++;
	 cout<<"\n\n"<<*(q+n-1);

*/

