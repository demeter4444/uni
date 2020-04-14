//Demeter Tamas
//511/2
//dtim1806
//2. projekt ritka header

//A tesztelo problema nelkul lefutott

#pragma once
#include "Vektor.h"

template < class T >
struct nonZero
{
	T elem;
	int index;
};


template<class T>
class RitkaVektor
{
public:

	operator Vektor<T>();
	RitkaVektor();
	RitkaVektor(int d);
	RitkaVektor(T *t, int d);
	RitkaVektor(const RitkaVektor& v);
    ~RitkaVektor();

	RitkaVektor operator+(const RitkaVektor& v);
	RitkaVektor operator-(const RitkaVektor& v);
	double operator*(const RitkaVektor& v);
	double operator~();
	double operator%(const RitkaVektor& v);
	T      operator[](int x) const;


private:


	struct nonZero <T> * vektor;
	int nZeroDim;
	int dim;
};


template <class T>
RitkaVektor<T>::RitkaVektor() {
	dim = 1;
	nZeroDim = 1;
	vektor = new struct nonZero<T>[1];
	vektor[0].index = 0;
	vektor[0].elem = 1;
}

template <class T>
RitkaVektor<T>::RitkaVektor(int d) {
	dim = d;
	nZeroDim = 1;
	vektor = new struct nonZero<T>[1];
	vektor[0].index = 0;
	vektor[0].elem = 1;
}

template <class T>
RitkaVektor<T>::RitkaVektor(T* t, int d) {
	dim = d;
	nZeroDim = 0;
	vektor = new struct nonZero<T>[dim];
	for (int i = 0; i < d; i++) {
		if (t[i] != 0) {
			nZeroDim++;
			vektor[nZeroDim - 1].index = i;
			vektor[nZeroDim - 1].elem = t[i];
		}
	}
}

template <class T>
RitkaVektor<T>::RitkaVektor(const RitkaVektor& v) {
	dim = v.dim;
	nZeroDim = v.nZeroDim;
	vektor = new struct nonZero<T>[nZeroDim];
	for (int i = 0; i < nZeroDim; i++) {
		vektor[i].index = v.vektor[i].index;
		vektor[i].elem = v.vektor[i].elem;
	}
}

template <class T>
RitkaVektor<T>::~RitkaVektor() {
	delete[] vektor;
}

template <class T>
RitkaVektor<T> RitkaVektor<T>::operator+(const RitkaVektor& v) {
	if (dim != v.dim) throw "Eltero dimenziok!";
	T * a = new T[dim];
	for (int i = 0; i < dim; i++) {
		a[i] = 0;
	}
	for (int i = 0; i < nZeroDim; i++) {
		a[vektor[i].index] += vektor[i].elem;
	}
	for (int i = 0; i < v.nZeroDim; i++) {
		a[v.vektor[i].index] += v.vektor[i].elem;
	}
	RitkaVektor<T> temp(a, dim);
	return temp;
}

template <class T>
RitkaVektor<T> RitkaVektor<T>::operator-(const RitkaVektor& v) {
	if (dim != v.dim) throw "Eltero dimenziok!";
	T * a = new T[dim];
	for (int i = 0; i < dim; i++) {
		a[i] = 0;
	}
	for (int i = 0; i < nZeroDim; i++) {
		a[vektor[i].index] = vektor[i].elem;
	}
	for (int i = 0; i < v.nZeroDim; i++) {
		a[v.vektor[i].index] -= v.vektor[i].elem;
	}
	RitkaVektor<T> temp(a, dim);
	return temp;
}

template <class T>
double RitkaVektor<T>::operator*(const RitkaVektor& v) {
	if (dim != v.dim) throw "Eltero dimenziok!";
	T * a = new T[dim];
	for (int i = 0; i < dim; i++) {
		a[i] = 0;
	}
	for (int i = 0; i < nZeroDim; i++) {
		a[vektor[i].index] = vektor[i].elem;
	}
	for (int i = 0; i < v.nZeroDim; i++) {
		a[v.vektor[i].index] *= v.vektor[i].elem;
	}
	double p = 0;
	for (int i = 0; i < dim; i++) {
		p += a[i];
	}
	return p;
}

template <class T>
double RitkaVektor<T>::operator~() {
	double sum = 0;
	T* a = new T[dim];
	for (int i = 0; i < dim; i++) {
		a[i] = 0;
	}
	for (int i = 0; i < nZeroDim; i++) {
		a[vektor[i].index] = vektor[i].elem;
	}
	for (int i = 0; i < dim; i++) {
		sum += a[i] * a[i];
	}
	return sqrt(sum);
}

template <class T>
double RitkaVektor<T>::operator%(const RitkaVektor& v) {
	if (dim != v.dim) throw "Eltero dimenziok!";
	double sum = 0;
	T * a = new T[dim];
	for (int i = 0; i < dim; i++) {
		a[i] = 0;
	}
	for (int i = 0; i < nZeroDim; i++) {
		a[vektor[i].index] = vektor[i].elem;
	}
	for (int i = 0; i < v.nZeroDim; i++) {
		a[v.vektor[i].index] -= v.vektor[i].elem;
	}
	for (int i = 0; i < dim; i++) {
		sum += a[i] * a[i];
	}
	return sqrt(sum);
}

template <class T>
T      RitkaVektor<T>::operator[](int x) const {
	if ((x < 0) || (x >= dim)) {
		throw "Helytelen index!";
	}
	for (int i = 0; i < nZeroDim; i++) {
		if (vektor[i].index == x) return vektor[i].elem;
	}
	return 0;
}

template <class T>
RitkaVektor<T>::operator Vektor<T>() {
	T* a = new T[dim];
	for (int i = 0; i < dim; i++) {
		a[i] = 0;
	}
	for (int i = 0; i < nZeroDim; i++) {
		a[vektor[i].index] = vektor[i].elem;
	}
	Vektor<T> temp(a, dim);
	return temp;
}
