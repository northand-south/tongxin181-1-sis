#include<iostream> 
#include <math.h> 
using namespace std; 
class vehicle 
{ 
protected: 
int wheels; 
int weight; 
public: 
vehicle(int wh, int we) 
{ 
wheels = wh; 
weight = we; 
} 
void disp() 
{ 
cout << "wheels=" << wheels << ",weight=" << weight << endl; 
} 
}; 
class car:private vehicle 
{ 
int passenger_load; 
public: 
car(int wh, int we, int pa) :vehicle(wh,we) 
{ 
passenger_load = pa; 
} 
void disp() 
{ 
vehicle::disp(); 
cout << "passenger_load=" << passenger_load << endl; 
} 
}; 
class truck :private vehicle 
{ 
int passenger_load; 
int payload; 
public: 
truck(int wh, int we, int pa,int pay) :vehicle(wh, we) 
{ 
passenger_load = pa; 
payload = pay; 
} 
void disp() 
{ 
vehicle::disp(); 
cout << "passenger_load=" << passenger_load << "payload=" << payload << endl; 
} 
}; 
void main() 
{ 
vehicle v(1152, 50000000); 
v.disp(); 
car c(4, 2000, 6); 
c.disp(); 
truck t(16, 5000, 3, 3000); 
t.disp(); 
system("pause"); 
} 
