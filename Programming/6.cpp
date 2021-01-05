#include<iostream> 
using namespace std;

class vehicle//������vehicle
{
protected://������Ա
	int wheels;
	int weight;
public://���г�Ա
	vehicle(int w1, int w2)
	{
		wheels = w1;
		weight = w2;
	}
	void disp()
	{
		cout << "wheels=" << wheels << ",weight=" << weight << endl;
	}

};
class car :private vehicle//������vehicle��˽������С����car
{
	int passenger_load;
public:
	car(int w1, int w2, int pa) :vehicle(w1, w2)
	{
		passenger_load = pa;
	}
	void disp()
	{
		vehicle::disp();
		cout << "passenger_load=" << passenger_load << endl;
	}


};
class truck :private vehicle//������vehicle��˽������������truck
{
	int passenger_load;
	int payload;
public:
	truck(int w1, int w2, int pa, int pay) :vehicle(w1, w2)
	{
		passenger_load = pa;
		payload = pay;
	}
	void disp()
	{
		vehicle::disp();
		cout << "passenger_load=" << passenger_load << endl;
		cout << "payload=" << payload << endl;
	}

};

void main()
{
	vehicle v(200, 180);
	v.disp();

	car c(100, 80, 60);
	c.disp();

	truck t(50, 35, 30, 15);
	t.disp();
	system("pause");
}