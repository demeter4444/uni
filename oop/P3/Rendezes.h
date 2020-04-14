//Demeter Tamas
//dtim1806
//511/2
//projekt3

//A tesztelo minden problema nelkul lefutott!

#include <ctime>

#pragma once


template <class T>
class Rendezes {
protected:
	virtual bool kisebb(T a, T b) = 0;
	virtual void csere(T& a, T& b) = 0;
public:
	virtual void rendez(T* tomb, int n) = 0;
};

class Stat {
private:
	unsigned int ido, nHasonlit, nCsere;
	std::clock_t c;

protected:
	void kezd();
	void vege();
	void init();
	void incHasonlit();
	void incCsere();

public:                                    
	Stat();
	unsigned int getIdo();
	unsigned int getHasonlit();
	unsigned int getCsere();
};

//stat
void Stat::init()
{
	ido = 0;
	nHasonlit = 0;
	nCsere = 0;
}

inline void Stat::kezd()
{
	c = std::clock();
}

inline void Stat::vege()
{
	ido = std::clock()-c;
}
inline void Stat::incHasonlit()
{
	nHasonlit++;
}
inline void Stat::incCsere()
{
	nCsere++;
}
inline Stat::Stat()
{
	ido = 0;
	nHasonlit = 0;
	nCsere = 0;
}
inline unsigned int Stat::getIdo()
{
	return ido/1000;
}
inline unsigned int Stat::getHasonlit()
{
	return nHasonlit;
}
inline unsigned int Stat::getCsere()
{
	return nCsere;
}
//

template <class T>
class BuborekosRendezes : public Rendezes<T> {
protected:
	bool kisebb(T a, T b);
	void csere(T& a, T& b);

public:
	void rendez(T* tomb, int n);
};

//bubi
template<class T>
inline bool BuborekosRendezes<T>::kisebb(T a, T b)
{
	if (a < b) return true;
	return false;
}
template<class T>
inline void BuborekosRendezes<T>::csere(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

//HAROMSZOROSAN JAVITOTT BUBOREKOS RENDEZES 
template<class T>
inline void BuborekosRendezes<T>::rendez(T* tomb, int n)
{
	bool rendezett;
	int regiJobb = n-2;
	int regiBal = 0;
	int jobb;
	int bal;
	do {
		rendezett = true;

		for (int i = regiBal; i <= regiJobb; i++) {
			if (kisebb(tomb[i+1],tomb[i])) {
				csere(tomb[i], tomb[i + 1]);
				rendezett = false;
				jobb = i-1;
			}
		}

		if (!rendezett) {
			regiJobb = jobb;
			rendezett = true;

			for (int i = regiJobb; i >= regiBal; i--) {
				if (kisebb(tomb[i + 1], tomb[i])) {
					csere(tomb[i], tomb[i + 1]);
					rendezett = false;
					bal = i+1;
				}
			}

			regiBal = bal;
		}

	} while (!rendezett);
}
//

template <class T>
class BuborekosRendezesT : public BuborekosRendezes<T>, public Stat {
protected:
	bool kisebb(T a, T b);
	void csere(T& a, T& b);

public:
	void rendez(T* tomb, int n);
};

//bubit
template<class T>
inline bool BuborekosRendezesT<T>::kisebb(T a, T b)
{
	incHasonlit();
	if (a < b) return true;
	return false;
}
template<class T>
inline void BuborekosRendezesT<T>::csere(T& a, T& b)
{
	incCsere();
	T temp = a;
	a = b;
	b = temp;
}
template<class T>
inline void BuborekosRendezesT<T>::rendez(T* tomb, int n)
{
	init();
	kezd();
	bool rendezett;
	int regiJobb = n-2;
	int regiBal = 0;
	int jobb;
	int bal;
	do {
		rendezett = true;

		for (int i = regiBal; i <= regiJobb; i++) {
			if (kisebb(tomb[i + 1], tomb[i])) {
				csere(tomb[i], tomb[i + 1]);
				rendezett = false;
				jobb = i-1;
			}
		}

		if (!rendezett) {
			regiJobb = jobb;
			rendezett = true;

			for (int i = regiJobb; i >= regiBal; i--) {
				if (kisebb(tomb[i + 1], tomb[i])) {
					csere(tomb[i], tomb[i + 1]);
					rendezett = false;
					bal = i+1;
				}
			}

			regiBal = bal;
		}

	} while (!rendezett);
	vege();
}
//

template <class T>
class QuickSort : public Rendezes<T> {
private:
	void qsort(T* a, int bal, int jobb);
	int particional(T* a, int bal, int jobb);

protected:
	bool kisebb(T a, T b);
	void csere(T& a, T& b);

public:
	void rendez(T* tomb, int n);

};

//kvikkszort
template<class T>
inline bool QuickSort<T>::kisebb(T a, T b)
{
	if (a <= b) return true;
	return false;
}
template<class T>
inline void QuickSort<T>::csere(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}
template<class T>
inline int QuickSort<T>::particional(T* a, int bal, int jobb)
{
	T pivot = a[jobb];   
	int i = (bal - 1);  
	for (int j = bal; j <= jobb - 1; j++)
	{
		if (kisebb(a[j],pivot)) //esetleg nemkisebb fg
		{
			i++;   
			csere(a[i], a[j]);
		}
	}
	csere(a[i + 1], a[jobb]);
	return (i + 1);
}

template<class T>
inline void QuickSort<T>::qsort(T* a, int bal, int jobb)
{
	if (bal < jobb) //esetleg kisebb fg
	{
		int p = particional(a, bal, jobb);
		qsort(a, bal, p - 1);
		qsort(a, p + 1, jobb);
	}
}

template<class T>
inline void QuickSort<T>::rendez(T* tomb, int n)
{
	qsort(tomb, 0, n - 1);
}

//

template <class T>
class QuickSortT : public QuickSort<T>, public Stat {

protected:
	bool kisebb(T a, T b);
	void csere(T& a, T& b);

public:
	void rendez(T* tomb, int n);

};

//kvikkszortt
template<class T>
bool QuickSortT<T>::kisebb(T a, T b)
{
	incHasonlit();
	if (a <= b) return true;
	return false;
}
template<class T>
void QuickSortT<T>::csere(T& a, T& b)
{
	incCsere();
	T temp = a;
	a = b;
	b = temp;
}
template<class T>
inline void QuickSortT<T>::rendez(T* tomb, int n)
{
	init();
	kezd();
	QuickSort<T>::rendez(tomb, n);
	vege();
}
//