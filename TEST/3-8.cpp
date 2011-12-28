#include <iostream>
#include <string>

using namespace std;
typedef char ElemType;
#define		MaxSize		10
typedef	struct	{
	ElemType 	data[MaxSize];
	int			front;
	int			rear;
	int			flag;
}QueueTag;
int		IsEmpty(QueueTag	qt)
{
	if(qt.front==qt.rear)
		return 1;
		else
		return 0;
}
int		IsFull(QueueTag	qt)
{
	if (qt.rear==((qt.front+MaxSize-1)%MaxSize))
	{
		cout<<"\nqueue is full\n";
		return 1;
	}
	else
		return 0;
}
void	initialQueue(QueueTag& qt)
{
	qt.front= 1;
	qt.rear=3;
	qt.flag =1;
	qt.data[1] = 'e';
	qt.data[2] = 't';
	qt.data[3] = '3';
/*	qt.front = qt.rear = 0;
	qt.flag = 1;
	*/
}

int		Enqueue(QueueTag& qt,ElemType	data)
{
	if((qt.front==qt.rear)&&(qt.front==0))	//初始空队列
	{
		return 0;
	}
	else{									//初始有数据
	if (IsFull(qt))
	{
		return 0;
	}
	else	if (IsEmpty(qt)&& qt.flag==1)
	{
		qt.data[qt.rear] = data;
		qt.rear++;
		qt.flag = 0;
		return 1; 
	}
		  if(qt.front <qt.rear)
		  {
			  qt.rear=(qt.rear+1)%MaxSize;
			  qt.data[qt.rear] = data;
			  return 1;
		  }
		  else if (qt.front>qt.rear)
		  {
			  qt.data[qt.rear] = data;
			  qt.rear=(qt.rear+1)%MaxSize;
			  return 1;
		  }
		  else
			  return 0;
	
	}
}

int	Dequeue(QueueTag& qt)
{
	if (IsEmpty(qt))
	{
		initialQueue(qt);
		return 0;
	}
	qt.front=(qt.front)%MaxSize;
	qt.data[qt.front] = NULL;
//	if (qt.front>qt.rear)
//	{
//		qt.front--;
//	}
//	else{
		qt.front++;
//	}
	cout<<"dequeue"<<endl;
	return 1;
}
void SQueuePrint(QueueTag& sq)
{
	QueueTag  p=sq;
	while(p.front!=p.rear)
	{
		cout<<p.data[(p.front++)%MaxSize]<<"~~~~";
		p.front = (p.front+MaxSize)%MaxSize;
	}
	cout<<endl;
}/*
int main()
{
		char	c;
		QueueTag	qt;
		string	inpu;
		cout<<"put a string ";
		cin>>inpu;
		initialQueue(qt);
	while((c=getchar())!='\n')
	{
		ElemType shuru = c;
		if (Enqueue(qt,shuru))
		{
			cout<<"\ninput ok\t"<<qt.data[(qt.rear-1+MaxSize)%MaxSize]<<endl;
		}
		else
			cout<<"666^^^"<<qt.data[qt.rear]<<endl;
	}
	SQueuePrint(qt);
	Dequeue(qt);
	SQueuePrint(qt);
}

class queue
{
public:
//	void	setSize(int	n){MaxSize = n;}
	int		getSize() const{return	MaxSize;}
	bool	isEmply(){return	top<1;}
	bool	isFull(){return		top>MaxSize-1;}
	void	dump(){
		cout<<"stack contents, top to bottom:\n";
		for (int i=top;i>=0;i--)
		{
			cout<<"\t"<<arr[i]<<'\n';
		}
	}
	void	push(const string	&s){
		if (isFull())
		{
			errMsg("full stack. can't add new.");
			return;
		}
		arr[++top] = s;
	}
	string	pop(){
		if (isEmply())
		{
			errMsg("empty stack. can't delete .");
			return strValue;
		}
		return arr[--top];
	}
	void	push(const char* c){
		if (isFull())
		{
			errMsg("full stack. can't add new.");
			return;
		}
		arr[++top] = c;

	}
	queue(){init();}
	//protected:
	enum{	MaxSize = 5};
private:
	void	init(){top = -1;	}

	void	errMsg(const	char* msg) const{
		cerr<<"\n**** stack operation failure: "<<msg<<'\n';
	}
	int	top;
	string	arr[MaxSize];
	string	strValue;
};

//栈的长度无法进行修改
int main()
{
	string s[] ={"sef","fkale","ropwqri"};
	queue	q;
	for(int i=s->length()-1 ;i>0;i--)
	q.push(s[i]);
//	q.push(s[0]);
	q.dump();
}*/