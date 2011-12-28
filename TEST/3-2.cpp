/************************************************************************/
/*ISBN���ɱ����ۺŷֿ���10������ɡ��磺0 -	670   -		82162   -	4
			�ֳ�4���֣�				����룻��������룻�鼮���룻У����
�����ܺͣ���һ������+�ڶ���*2+������*3+����+�ھŸ�*9.
�������11���ࣺ��Ϊ10�������һ������ΪX;��Ϊ10����Ϊ������
    ����X-Y֮����������Y>X�� ==> rand()%(y-x+1)+x                                                               */
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