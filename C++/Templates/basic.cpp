#include <iostream>
#include <stdio.h>

using namespace std;
/*

std has its own max function so we are using Max if we want our own max function we have to use it with :: ( scope resolution  ) operator  --> ::max(...)

*/

/*int MaxxInt(int a ,int b)
  {

  return a>b?a:b;

  }
  char MaxxChar(char a ,char b)
  {

  return a>b?a:b;

  }
 */

//template <typename T>  /*  this is also valid syntax  */
//template <class RT,class T1,typename T2>
//RT Maxx(T1 a,T2 b)
template <class T1,typename T2>
auto Max(T1 a,T2 b)
{
	return a>b?a:b;
}
int main()
{

	int a = 10,b=20;

	//	printf("Maxx == %d\n",MaxInt(a,b));

	char x = 'a',y = 'b';
	//	printf("Maxx == %c\n",MaxChar(x,y));


	printf("Maxx == %d\n",Max<int>(a,b)); // we can call this function as max(a,b) it internally treats it as max<int>(a,b) as both arguments are of same type same for max(x,y)
	//printf("Maxx == %c\n",Max<char>(x,y));
	printf("Max == %c\n",Max(x,y));
	int k = Max<int>(10,20);
	//int k = Max<double>(10,20.5); // here doube is for return type RT
	
	auto Auto = Max(40,30.5);
	cout <<Auto<<endl;

	return 0;
}


