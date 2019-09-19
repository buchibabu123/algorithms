#include <iostream>


using namespace std;


template <typename T>
class Vector
{

	T *buffer;
	size_t capacity;
	size_t size;
	typedef T* Iterator; 
 
	public:

	size_t Capacity();
	size_t getSize();
	Iterator begin();
	Iterator end();
	void pushBack(const T&);
	Vector();
	Vector(int);
	Vector(int,const T&);
	Vector(const Vector<T>&);

	
	

};
