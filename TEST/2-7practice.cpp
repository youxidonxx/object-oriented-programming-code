#include <iostream>
#include <string>
using namespace std;

struct Elephant{
	string name;
	Elephant* next;
};

Elephant* get_elephant()
{
	Elephant* current,*first;
	int responce;
	current = first = new Elephant;
	cout<<"\nName:";
	cin>>current->name;
	cout<<"\nadd another? 1 or 0 :";
	cin>>responce;
	while(responce==1)
	{
		current=current->next =new Elephant;
		cout<<"\nname:";
		cin>>current->name;
		cout<<"1 or 0 :";
		cin>>responce;
	}
	current->next=0;
	return first;
}
/************************************************************************/
/* 在链表进行移动时，其移动规律错误，在该方法中指针每次移动0x14位                                                                     */
/***********************************************************************
Elephant* reserve_elephant(  Elephant* ptr , Elephant* rev_ptr)
{
 	Elephant* temp;
	int count=0,i;
 	 temp = rev_ptr;
	while(temp!=0)
	{
		temp=temp->next;
		count++;
	}
//	ptr = temp;
	for (i=0;i<count;i++)
	{
		*ptr--;
		*rev_ptr=*ptr;
		*rev_ptr++;
	}
	rev_ptr=temp;
	return rev_ptr;
}**/
/////////////////////////////////////////////////////////////////////// 
// Reverse a list iteratively 
// Input: pHead - the head of the original list 
// Output: the head of the reversed head 
/////////////////////////////////////////////////////////////////////// 
Elephant* ReverseIteratively(Elephant* pHead) 
{ 
	Elephant* pReversedHead = NULL; 
	Elephant* pNode = pHead; 
	Elephant* pPrev = NULL; 
	while(pNode != NULL) 
	{ 
		// get the next node, and save it at pNext 
		Elephant* pNext = pNode->next; 
		// if the next node is null, the currect is the end of original    
		// list, and it's the head of the reversed list 
		if(pNext == NULL) 
			pReversedHead = pNode; 
		
		// reverse the linkage between nodes 
		pNode->next = pPrev; 
		
		// move forward on the the list 
		pPrev = pNode; 
		pNode = pNext; 
	} 
	
	return pReversedHead; 
}
void print_ele(const Elephant* ptr)
{
	int count =1;
	cout<<"\n\n\n";
	while (ptr!=0)
	{
		cout<<"number "<<count++<<"is ："<<ptr->name<<"\n";
		ptr=ptr->next;
	}
}
void free_list(const Elephant* ptr)
{
	const Elephant* temp;
	while(ptr!=0)
	{
	 	if(ptr->next==NULL)//解决方式
			return ;
		temp=ptr->next;
		delete ptr;
		ptr=temp;
	}
}/*
int main(){
	Elephant* start,*revEle;
	start = get_elephant();
	print_ele(start);
	revEle=ReverseIteratively( start);
	print_ele(revEle);
	free_list(start);
	free_list(revEle);//最后释放内存，有空指针——已解决
	return 0;
}*/
