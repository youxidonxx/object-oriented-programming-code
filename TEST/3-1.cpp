/************************************************************************/
/* ���һ��CAR�࣬���ݳ�Ա������Ʒ�ƣ��ͺţ�������ݣ��۸�              
	����һ���ȽϺ������ڱȽ�2�����������һ�ݼ�̱��档
	���а�������const�������ص��÷���ʾ��ԭ��δ֪						*/
/************************************************************************/
#include <iostream>
//#include <fstream>
#include <string>
#include <ctime>								//time_t����ͷ�ļ�
using namespace std;
class CARTAG{
private:
	string brand;
	string model;
	time_t manufacturer;						//time_t������������
	float price;
private:
	string extract(int offset,int count) const{		//����˴���const���Σ���ȥ��������
		string timestamp  = ctime(&manufacturer);	//���C2662����
		return timestamp.substr(offset,count);}
public:
	void setBrand(string s){brand = s;}
	void setModel(string m){model = m;}
	void setPrice(float f){price = f;}
	void settime(){ manufacturer=time(0);}			//time��0���Ǻ�����������������
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