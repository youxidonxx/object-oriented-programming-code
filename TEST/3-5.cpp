/************************************************************************/
/*collegeStudent类,inlcude name , year, expectedGrad, major, minor,GPA,courseAndGrades
,maritalStatus etc member data; requested in public interface ,at least 6 member
function .                                                                      */
/************************************************************************/
#include <string>
#include <iostream>
using namespace std;
#define		courseNum		3
#define		totalCourse		6
class courseAndGrades			//assuming there are 3 courses
{
public:
	bool	checkValid(char grade[courseNum]);		//guarantee the grads between A-E;
	void	setCourse(int c[courseNum]);
	void	setGrad(char g[courseNum]);
	int		getCourse(int i){return	course[i];}
	char	getGrade(int i){return	grad[i];}
	void	printCAG();
	static	int	courseCredit[totalCourse];
	static	string	courseName[totalCourse];
	static	int	gradePoint[];
	int		getPoint(char key);
private:
	int		course[courseNum];
	char	grad[courseNum];
};
int		courseAndGrades::getPoint(char key)
{
	switch (key){
	case	'A':
		return 4;//gradePoint[0];
	case	'B':
		return 3;//gradePoint[1];
	case 'C':
		return 2;//gradePoint[2];
	case 'D':
		return 1;//gradePoint[3];
	default:
		return 0;
	}
}
int	courseAndGrades::gradePoint[]={4,3,2,1};
void	courseAndGrades::setCourse(int c[courseNum])
{
	for (int i=0;i<courseNum;i++)
	{
		 course[i] = c[i];
		cout<<"the course id is: "<< course[i];
	}
}
void	courseAndGrades::setGrad(char g[courseNum])
{
	for (int i=0;i<courseNum;i++)
	{
		 grad[i] = g[i];
		cout<<"\nthe grad id is: "<< grad[i];
	}
}
bool	courseAndGrades::checkValid(char grade[courseNum])
{	int i;
	bool	result;
	for (i=0;i<courseNum;i++)
	{
		if ((grade[i]<='E')&&(grade[i]>='A'))
		{
			result=	true;
		}
		else
			result=	false;
	}
	return	result;
}
class CollegeStudent
{
private:
	string	name;
	int		year;
	double	expectedGrad;
	int		major,minor;		//主修与次修
	double	GPA;				//绩点
	bool	maritalStatus;		//婚姻状况
	courseAndGrades	cAG;
public:
	void	setName(string n){name = n;}
	void	setYear(int y){year = y;}
	void	setMS(bool b){maritalStatus = b;}
	void	setCAG(courseAndGrades cag){cAG = cag;}
	void	printInfo();
	void	calGPA(const courseAndGrades cag);
	double	getGPA(){return	GPA;}
//	CollegeStudent();
};
void	CollegeStudent::calGPA(  courseAndGrades cag)
{
	int i,t,n;
	double	sum=0,total=0,ave;
	char g;
	for (i=0;i<courseNum;i++)
	{
		t=cag.getCourse(i);
		g=cag.getGrade(i);
		n=cag.courseCredit[t];
		t=cag.getPoint(g);
		sum += t*n;
		total +=t;
	}
	ave = sum/total*1.0;
	GPA = ave;
	//return ave;
}

void	courseAndGrades::printCAG(){
	for (int i=0;i<courseNum;i++)
	{
		cout<<"\n course id:"<<getCourse(i)<<"---->"<<courseName[getCourse(i)];
		cout<<" ---grade char:"<<getGrade(i)<<"---credits: "\
			<<courseCredit[getCourse(i)];
	}
}
void	CollegeStudent::printInfo(){
	cout<<"\nname: "<<name;
	cAG.printCAG();
	cout<<"\n\n gpa ::"<<getGPA();
}

string	courseAndGrades::courseName[]={"math","PE","history","literature","science","chemistry"};
int		courseAndGrades::courseCredit[]={4,1,3,1,3,4};
/*
int main()
{
	CollegeStudent cs[2];
	courseAndGrades	cag[2];
	int course[2][courseNum]={
		{0,2,3},
		{2,0,1}
	};
	char	grad[2][courseNum]={
		{'A','B','C'},
		{'B','B','A'}
	};
	for (int i=0;i<2;i++)
	{
		cag[i].setCourse(course[i]);
		cag[i].setGrad(grad[i]);
		cs[i].setName("peter");
		cs[i].setCAG(cag[i]);
		cs[i].calGPA(cag[i]);
		cs[i].printInfo();
		cout<<"\n\n\n";
	}
	cout<<"\n111\n";
	return 0;
}*/