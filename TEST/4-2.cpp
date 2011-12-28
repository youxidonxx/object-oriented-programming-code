#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#include "464sequence.h"

class RevSortSeq:public	Sequence
{
public:
	bool	addRS(const	string& entry);
	RevSortSeq(){}
	RevSortSeq(const	char*);
protected:
	void	sorted();
private:
	using	Sequence::addS;
};
void	RevSortSeq::sorted()
{
	string	temp;
	int i,j;
	for (i=0;i<=last-1;i++)
	{
		temp = s[i+1];
		for(j=i;j>=0;j--)
			if(temp>s[j])
				s[j+1] = s[j];
			else
				break;
		s[j+1] = temp;
	}
}

bool	RevSortSeq::addRS(const string& entry)
{
	int i;
	for(i=0;i<= last;i++)
		if(entry <=s[i])
			break;
		return addS(i,entry);
}
RevSortSeq::RevSortSeq(const char* fname):Sequence(fname)
{
	sorted();
}
/*
int main()
{
	string	inbuff,where;
	int wh;
	RevSortSeq	sortitem("test.dat");
	while(true)
	{
		cout<<"\nsorted seq output: \n";
		sortitem.output();
		cout<<"\n1--add\n"
			<<"2--delete\n"
			<<"3--quit\n";
		getline(cin,inbuff);
		if (inbuff =="1")
		{
			cout<<"\nitem to add: ";
			getline(cin,inbuff);
			if (sortitem.addRS(inbuff))
			{
				cout<<"item add\n";
			}
			else
				cout<<"not added\n";
		}
		else if (inbuff =="2")
		{
			cout<<"\n where to delete: ";
			getline(cin,where);
			wh = atoi(where.c_str());
			if(sortitem.del(wh))
				cout<<"item delete\n";
			else
				cout<<"\n not deleted";
		}
		else if(inbuff =="3")
			break;

		inbuff = "";
	}
	return 0;
}*/