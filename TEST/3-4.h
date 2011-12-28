
#define START_YEAR	(-5600)
#define START_WEEK_DAY	6
class Canlender{
private:
	int c_Year;
	int c_Month;
	int c_oriYear;
protected:
	bool IsLeapYear(int year);
    virtual void PrintLine(int line, bool endline = true);
public:
	void setOriYear(int year=1900){c_oriYear = year;}
	static int a[];
	Canlender();
	Canlender(int year,int month=1);
	~Canlender();
    virtual void PrintMonth();
	Canlender operator - (int n);
	Canlender operator + (int n);
	void setThisDate();
	void setDate(int year,int month = 1);
	bool CheckValid(int year, int month);
	//	void searchHoliday(int weekday);
	int GetWeekday(int year= 0,int month = 0,int day =0);
};