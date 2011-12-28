#include <iostream>
#include <iomanip>
using namespace std;
#define		maxArray		100
/*
class	intArray{
public:
 	intArray(){};
	int		getEle(int pos){return	ar[pos];}
	virtual	void	print(){
		for (int i = 0;i<total;i++)
			cout<<ar[i]<<" ";
	}
	intArray(int size);
//	~intArray();
protected:
	int		ar[maxArray];
	int		total;			//count the total number
private:
	
};
intArray::intArray(int size)
{
	if(size>maxArray)
		return;
	total = size;
	for(int i =0;i<size;i++)
		ar[i] = 0;
}
class	MatrixArray:public	intArray
{
public:
	MatrixArray(int rowCount,int colCount);
	MatrixArray(){

	}
	virtual	void	setEle(int n , int pos){ ar[pos] = n;}
 	void	print();
private:
	int colCount;			//x*y类型的矩阵
	int rowCount;			//
};
void	MatrixArray::print()
{
	for (int i=0;i<rowCount;i++)
	{
		for(int j=0;j<colCount;j++)
			cout<<setw(3)<<ar[j+i*colCount]<<" ";
		cout<<endl;
	}
}
MatrixArray::MatrixArray(int rowC,int colC)
{
	colCount = colC;
	rowCount = rowC;
	if(maxArray<colCount*rowCount)
	{
		cout<<"\ncreate error, too large to store ele.\n";
		return	;
	}
	cout<<"\ncreate now.\n";
	for (int row = 0;row<rowCount;row++)
	{
		for (int col = 0;col<colCount;col++)
		{
			ar[col+row*colCount] = 0;
		}
	}
}

class	Array3D:public	intArray	//坐标点存储
{
public:
//	void	print();
	Array3D(){};
	Array3D(int x,int y,int z);
	
private:
	int xPos;
	int yPos;
	int zPos;
};
Array3D::Array3D(int x,int y,int z)
{
	total = 3;
	ar[0] = x;
	ar[1] = y;
	ar[2] = z;
}

class	SquareMatrix:public	MatrixArray
{
public:
 	void	print();
	SquareMatrix(){
	}
	SquareMatrix(int len);
private:
	int		demension;		//
};
void	SquareMatrix::print()
{
	for (int i=0;i<demension;i++)
	{
		for(int j=0;j<demension;j++)
			cout<<setw(3)<<ar[j+i*demension]<<" ";
		cout<<endl;
	}
}

SquareMatrix::SquareMatrix(int len)
{
	if(maxArray<len*len)
		return;
	demension = len;
	int i,j;
	for (i=0;i<len;i++)
	{
		for (j=0;j<len;j++)
		{
			ar[i+j*len] = 0;
		}
	}
}
int main()
{
	intArray	i1(22);
	i1.print();
	MatrixArray	m1(4,5);
	m1.print();
	for(int i=0;i<4*5;i++)
		m1.setEle(i,i);
	m1.print();
	Array3D	a1(3,4,5);
	a1.print();
	SquareMatrix s1(6);
	s1.print();
	return 0;
}*/