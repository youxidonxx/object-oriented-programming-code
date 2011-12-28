/*
#include <iostream>
#include <string>
#include "film.h"
using namespace std;

class Documentary:public	Film
{
public:
	void store_theme(const char* c);
	void store_theme(string& s);
	virtual void	input(ifstream& fin);
	virtual	void	output();
protected:
private:
	string	theme;
};
void	Documentary::input(ifstream& fin)
{
	Film::input(fin);
	string buff;
	getline(fin,buff);
	store_theme(buff);
}
void	Documentary::output()
{
	Film::output();
	cout<<"The theme is about: "<<theme<<endl;
}
void	Documentary::store_theme(const char* c)
{
	theme = c;
}
void	Documentary::store_theme(string& s)
{
	theme = s;
}

int main()
{
	Documentary du;
	SongAndDance s1;
	s1.store_dancer("hello");
	s1.output();
	du.store_theme("young");
	du.output();
	return 0;
}*//**/
