/************************************************************************/
/* 设计一个CAR类，数据成员描述：品牌，型号，出厂年份，价格              
	还有一个比较函数用于比较2辆汽车并输出一份简短报告。
	其中包含关于const函数重载的用法提示，原因未知						*/
/************************************************************************/
#include <iostream>
//#include <fstream>
#include <string>
#include <ctime>								//time_t类型头文件
using namespace std;
class CARTAG{
private:
	string brand;
	string model;
	time_t manufacturer;						//time_t才是数据类型
	float price;
private:
	string extract(int offset,int count) const{		//留意此处的const修饰，若去掉，报错
		string timestamp  = ctime(&manufacturer);	//造成C2662错误
		return timestamp.substr(offset,count);}
public:
	void setBrand(string s){brand = s;}
	void setModel(string m){model = m;}
	void setPrice(float f){price = f;}
	void settime(){ manufacturer=time(0);}			//time（0）是函数，不是数据类型
	string getTime()const{
		return extract(0,3)+extract(4,3)+extract(20,4);
	}
	string getBrand(){return brand;}
	string getModel(){return model;}
	float  getPrice(){return price;}
	void setCar(string brand,string model,float price){
		setBrand(brand);
		setModel(model);
		setPrice(price);
		settime();
	}
	void compare(const CARTAG& car2) const {
		cout<<"HERE ARE TWO CHOSEN CARS DATA"<<endl;
		cout<<"BRAND: "<<brand<<"  "<<car2.brand<<endl;
		cout<<"MODEL: "<<model<<"  "<<car2.model<<endl;
		cout<<"PRICE: "<<price<<"  "<<car2.price<<endl;
		cout<<"MANU: "<<getTime()<<"  "<<car2.getTime()<<endl;
	}
};
/*
int main(){
	CARTAG car1,car2;
	car1.setCar("honda","covic",20000.99);
	car2.setCar("hy","ididd",30000);
	car1.compare(car2);
	return 0;
}*/