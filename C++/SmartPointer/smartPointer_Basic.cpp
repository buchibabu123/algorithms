
#include<iostream>


using namespace std;


class Person{
	private:

		int age;
		char *pName;

	public:

		Person():age(0),pName(0)
	{

	}
		Person(int age,char *name):age(age),pName(name)
	{

	}
		~Person()
		{
			cout <<"Person Desctructor"<<endl;
		}
		void display()
		{
			cout <<"name ==" <<pName <<"age == "<<age<<endl;
		}

};


class SP
{
	private:
		Person *sp;
	public:

		SP(Person *value):sp(value)
	{


	}
		~SP()
		{

			delete sp;
		}

		Person* operator->()
		{
			return sp;
		}

		Person& operator*()
		{
			return *sp;
		}

};

int main()
{
	Person *Babu = new Person(50,"BUchibabu");

	SP smartPointer(Babu);
	smartPointer->display();
	//SP<Person> sp(new Person(10,"Adtran"))
	//	delete Babu;


	return 0;
}
