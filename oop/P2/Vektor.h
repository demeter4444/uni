//Demeter Tamas
//511/2
//dtim1806
//2. projekt vektor header

//A tesztelo problema nelkul lefutott

#pragma once
#include <cmath>

template<class T>
class RitkaVektor;

template<class T>
class Vektor
{
public:
	Vektor();
	Vektor(int dim);
	Vektor(T *t, int dim);
	Vektor(const Vektor& v);
    ~Vektor();
	Vektor operator+(const Vektor& v);
	Vektor operator-(const Vektor& v);
	double operator*(const Vektor& v);
	double operator~();
	double operator%(const Vektor& v);
	T      operator[](int x) const;
	operator RitkaVektor<T>();

private:
	T*  m_t;
	int m_dim;
};

template <class T>
Vektor<T>::Vektor() {
	m_dim = 1;
	m_t = new T[m_dim];
	m_t[0] = 1;
}

template <class T>
Vektor<T>::Vektor(int dim) {
	m_dim = dim;
	m_t = new T[dim];
	for (int i = 0; i < m_dim; i++) {
		m_t[i] = 1;
	}
}

template <class T>
Vektor<T>::Vektor(T* t, int dim) {
	m_dim = dim;
	m_t = new T[dim];
	for (int i = 0; i < m_dim; i++) {
		m_t[i] = t[i];
	}
}

template <class T>
Vektor<T>::Vektor(const Vektor& v) {
	m_dim = v.m_dim;
	m_t = new T[m_dim];
	for (int i = 0; i < m_dim; i++) {
		m_t[i] = v.m_t[i];
	}
}

template <class T>
Vektor<T>::~Vektor() {
	delete[] m_t;
}

template <class T>
Vektor<T> Vektor<T>::operator+(const Vektor& v) {
	if (m_dim != v.m_dim) throw "Eltero dimenziok!";
	Vektor<T> temp(m_t, m_dim);
	for (int i = 0; i < m_dim; i++) {
		temp.m_t[i] += v.m_t[i];
	}
	return temp;
}

template <class T>
Vektor<T> Vektor<T>::operator-(const Vektor& v) {
	if (m_dim != v.m_dim) throw "Eltero dimenziok!";
	Vektor<T> temp(m_t, m_dim);
	for (int i = 0; i < m_dim; i++) {
		temp.m_t[i] -= v.m_t[i];
	}
	return temp;
}

template <class T>
double Vektor<T>::operator*(const Vektor& v) {
	if (m_dim != v.m_dim) throw "Eltero dimenziok!";
	double p = 0;
	for (int i = 0; i < m_dim; i++) {
		p += m_t[i] * v.m_t[i];
	}
	return p;
}

template <class T>
double Vektor<T>::operator~() {
	double sum = 0;
	for (int i = 0; i < m_dim; i++) {
		sum += m_t[i] * m_t[i];
	}
	return sqrt(sum);
}

template <class T>
double Vektor<T>::operator%(const Vektor& v) {
	if (m_dim != v.m_dim) throw "Eltero dimenziok!";
	double sum = 0;
	//Annamari a legjobb!
	for (int i = 0; i < m_dim; i++) {
		sum += (m_t[i] - v.m_t[i]) * (m_t[i] - v.m_t[i]);
	}
	return sqrt(sum);
}

template <class T>
T      Vektor<T>::operator[](int x) const {
	if ((x < 0) || (x >= m_dim)) {
		throw "Helytelen index!";
	}
	return m_t[x];
}

template <class T>
Vektor<T>::operator RitkaVektor<T>() {
	RitkaVektor<T> temp(m_t, m_dim);
	return temp;
}
