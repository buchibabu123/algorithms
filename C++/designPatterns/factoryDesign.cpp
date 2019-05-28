#include <iostream>

using namespace std;


class Toy
{
	public:

		virtual void prepareParts()=0;
		virtual void combineParts()=0;
		/*
		 *		here we can add some more functions that makes the toy 
		 * */
		virtual void showProduct()=0;


};

class Car : public Toy
{

	public:
		void prepareParts()
		{
			cout <<"in car preparing parts"<<endl;
		}
		void combineParts()
		{
			cout <<"in car"<<endl;
		}
		void showProduct()
		{
			cout <<"in Car that has 4 wheels and 1000 CC engine"<<endl;
		}

};
class Bike : public Toy
{

	public:
		void prepareParts()
		{
			cout <<"in bike preparing parts"<<endl;
		}
		void combineParts()
		{
			cout <<"in bike"<<endl;
		}
		void showProduct()
		{
			cout <<"in bike that has 2 wheels and 220 CC engine"<<endl;
		}
};

/*
 *
 * This class acts like a inteface to outside and we are obstracting implimentation details of subclasses (Car,Bike), in future if we want to add new type just need to add new type code here  (in reality above code comes in packages so th developer can not see implimentation he just import the packages and add new type in his interface class)
 * */
class toyFactory
{

	Toy *toy;
	public:
	static Toy *createToy(int type)
	{

		if(type == 1)
		{
			toy = new Car;
		}
		else if (type == 2)
		{

			toy = new Bike;
		}
		/* call functions that consructs complete toy */
		toy->prepareParts();
		toy->combineParts();
		return toy;
	}

};


int main()
{
	toyFactory factory;
	Toy * toy = factory.createToy(2);
	toy->showProduct();


}
