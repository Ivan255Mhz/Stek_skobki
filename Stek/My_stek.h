#pragma once
#include <vector>
using namespace std;

template <class T>
class My_stek
{
	T* val;
	int sz;


public:
	My_stek(int sz) :sz{sz}, T{new T[sz]} {}

	~My_stek() { delete[] T; }

	My_stek(const My_stek& obj) {
		T = new T[obj.sz];
	}





};

