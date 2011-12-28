/************************************************************************/
/*ISBN号由被破折号分开的10个数组成。如：0 -	670   -		82162   -	4
			分成4部分：				组代码；出版社代码；书籍代码；校验码
计算总和：第一个数字+第二个*2+第三个*3+……+第九个*9.
将其除以11得余：若为10，则最后一个数字为X;不为10，则为其余数
    产生X-Y之间的随机数（Y>X） ==> rand()%(y-x+1)+x                                                               */
/************************************************************************/
#include <cstdlib>					//for rand function
#include <iostream>
#include <ctime>
using namespace std;
enum Country{
	UK=0,
	CH,
	EN,
	TW,
	JP,
	SC,
	c_num
};
class ISBN{
private:
	Country	area;//[c_num]={"uk","ch","en","tw","jp","sc"};
	int		press;
	long    book;
	char     code;
public:
	void setArea(){area =(Country) (rand()%(int)c_num);}
	void setPress(){press = rand()%900+100;}
	void setBook(){book = rand()%90000+10000;}
	Country getArea()const{return area;}
	int getPress() const{return press;}
	long getBook()const{return book;}
	char getCode(){return code;}
	void setCode();
};
void ISBN::setCode(){
	int sum;
	sum = int(area);
	sum += press/100*2+(press%100)/10*3+((press%100)%10)*4;
	sum += book/10000*5+(book%10000)/1000*6+((book%10000)%1000)/100*7+
			(((book%10000)%1000)%100)/10*8+((((book%10000)%1000)%100)%10)*9;
	if ((sum%11)==10)
	{
		code = 'X';
	}
	else
		code = int(sum%11)+0x30;
	return;
}/*
int main()
{
	ISBN isbn;
	srand((unsigned int )time(0));
	isbn.setArea();
	isbn.setBook();
	isbn.setPress();
	isbn.setCode();
	cout<<isbn.getArea()<<"-"
		<<isbn.getPress()<<"-"
		<<isbn.getBook()<<"-"
		<<isbn.getCode()<<endl;
	return 0;
}*/