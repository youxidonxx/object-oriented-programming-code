#include <iostream>
using	namespace	std;
struct	twodim{
	int r;
	int c;
	float* a;
};
void get_twodim(twodim& a,int row,int col)
{
	long	total=0;
	float* len;
	a.r=row;
	a.c=col;
	total=row*col;
	len = new float[total];
	a.a=len;
}
