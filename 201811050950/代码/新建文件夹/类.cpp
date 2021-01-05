#include <iostream>
#include <iomanip>
using namespace std;
//父类 
class vehical
{
	protected:
		int Wheels;
		float Weight;
	public:
	    vehical(int Wh,float We){Wheels=Wh;Weight=We;}
		void display()
		{	cout<<"Wheels="<<Wheels<<endl;
	        cout<<"Weight="<<Weight<<"Kg"<<endl;
			}	
};
//子类：小车类 
class car:private vehical
{
	private:
		int Passenger_load;
	public:
		car(int Wh,float We,int Pas):vehical(Wh,We){Passenger_load=Pas;}
		void display()
		{
			 vehical::display();
			 cout<<"Passenger_load="<<Passenger_load<<endl;
		  }
};
//子类：卡车类
class truck:private vehical   
{
	private:
		int Passenger_load;
		float Payload;
	public:
		truck(int Wh,float We,int Pas,float Pay):vehical(Wh,We){Passenger_load=Pas;Payload=Pay;}
        void display() 
        {
        	vehical::display();
        	cout<<"Passenger_load="<<Passenger_load<<endl;
        	cout<<"Payload="<<Payload<<"Kg"<<endl;
		  }
};

main()
{
    car the_car(5, 500,4);
    truck the_truck(8,1050,3,2500);
	cout<<"------------------------Dispaly the information of the car-------------------------"<<endl; 
    the_car.display();
    cout<<"------------------------Dispaly the information of the truck-------------------------"<<endl; 
    the_truck.display();
}