#include <iostream>

using namespace std;


int max(int a, int b)
{
	cout <<"in normal function"<<endl;
	return a>b?a:b;

}


template <typename T>
T max(T a ,T b)
{
	cout <<"in template function"<<endl;

	return a>b?a:b;

}

template <typename T>
T max(T a , T b,T c)
{
	cout <<"in template function max(a,b,c)"<<endl;
	return max(max(a,b),c);

}

int main()
{


	int a=10,b=20;
	cout <<::max(a,b)<<endl;
	
	::max(a,b);
	::max<>(a,b);
	::max(a,b,40);
	::max('a','b');
	::max(10.5,20.5);


	return 0;
}
