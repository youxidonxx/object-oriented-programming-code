/****************
profession 类，包含12个数据成员与成员函数
****************/
#include <iostream>
#include <string>
#include <ctime>
#include <time.h>
using namespace	std;
class	Profession
{
private:
	string	name;
	bool	sex;
	int		age;
	int		teachYear;
	int*	teachClass;
	string	nationality;
	string	title;
	time_t	birth;
	float	avgIncome;
	string*	credentials;
	Profession();

public:
	static	string	teachClassInfo;
	Profession(const char* n);
	Profession(const	string&	s);
	string	getName() const	{return name;}
	string	getTitle() const	{return	title;}
	float	getIncome() const	{return avgIncome;}
	void	setName(string& s){name = s;}
	void	setName(char* n){name = n;}
	void	setTitle(string& s){title = s;}
	void	setTitle(char* c){title =c;}
	void	setIncome(float  f){avgIncome =f;}

};

