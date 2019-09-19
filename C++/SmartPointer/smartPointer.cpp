#include <iostream>

using namespace std;


template <class T>
class Test
{

	T *ptr;
	public:
	void fun(T val)
	{

		cout <<val<<endl;
	}

};


int main()
{

	Test<int> B;
	B.fun(10);
	B.fun(10.5);

	return 0;
}
