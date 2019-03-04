/*
 * Vector.h
 *
 *  Created on: 05-Mar-2019
 *      Author: mdwalker
 */

#include <iostream>

#ifndef Vector_H_
#define Vector_H_

namespace stl {

#define __DEFAULT_VECSIZE__ 4

template <typename T>
class Vector
{
public:

	// constructor
	Vector()
		: _dArray(new T[__DEFAULT_VECSIZE__]),
			_size(0),
		  _reserved_size(__DEFAULT_VECSIZE__)
	{ }

	// create vector with n default elements
	Vector(int n)
		: _dArray(new T[n]),
			_size(0),
		  _reserved_size(n)
	{ }

	//destructor
	virtual ~Vector()
	{ }

	// method
	void push_back(const T &obj);
	void pop();
	void resize(int n);


private:
	T* _dArray;
	int _size;
	int _reserved_size;
};


// ========================================== defination of template function ==========================================
//
//
template <typename T>
void Vector<T>:: push_back(const T &obj)
{
	if(_size == _reserved_size)
	{
		resize(_reserved_size + __DEFAULT_VECSIZE__);
	}
	else
	{
		_dArray[_size] = obj;
		_size++;
	}
}

template<typename T>
void Vector<T>::resize(int n)
{
	if(n > _reserved_size)
	{
		T auto_array[n];

		for(int i = 0; i < _size ; i++)
		{
			auto_array[i] = _dArray[i];
		}
		delete []_dArray;
		_dArray = auto_array;
		_reserved_size = n;
	}
}

template<typename T>
void Vector<T>::pop()
{
	T auto_array[_size - 1];
	for(int i = 0; i < (_size - 1) ; i++)
	{
		auto_array[i] = _dArray[i];
	}
	delete []_dArray;
	_dArray = auto_array;
	_size--;
}

} /* namespace clist */

#endif /* Vector_H_ */
