#include <iostream>
#include <vector>
using namespace std;

/*
 * Here Car is subject , when ever there is a Modification in position  it calls notify function which inturn calls list of observers
 * Here we need to register our objects to subject ( Car ) when ever they are created 
 *
 * The sole responsibility of a subject is to maintain a list of observers and to notify them of state changes by calling their update() operation. 
 * The responsibility of observers is to register (and unregister) themselves on a subject (to get notified of state changes) and to update their state (synchronize their state with subject's state) when they are notified. 
 * This makes subject and observers loosely coupled. Subject and observers have no explicit knowledge of each other. Observers can be added and removed independently at run-time.
 * This notification-registration interaction is also known as publish-subscribe.
 * */


class Observer
{
	public:
		int position;
		virtual void update(int)=0;

};


class Car
{

	public:
		int _position;
		vector<class Observer*> ObserverList;

		void setPosition(int position)
		{
			_position = position;
			notify();
		}

		int getPosition()
		{
			return _position;
		}

		int attach(Observer *obj)
		{
			ObserverList.push_back(obj);

		}

		void notify();

};
void Car::notify()
{
	for(int i=0;i<ObserverList.size();++i)
		ObserverList[i]->update(_position);

}

class rightObserver:public Observer
{
	public:
		rightObserver(Car *obj)
{

			obj->attach(this);

}
	

		void update(int newPosition)
		{

			position = newPosition;
			cout <<"new posotion =="<<newPosition<<"\n"<<endl;

		}

};




int main()
{
	Car *car = new Car();

	rightObserver right(car);
	car->setPosition(100);



}
