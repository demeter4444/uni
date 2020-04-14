//Demeter Tamas
//dtim1806
//511/2
//L5_2a

#include <iostream>

using namespace std;

//sablon
template <class Type, const int n>
class TrM{
	Type *v;
public:
	TrM();
	TrM(Type *w);
	TrM(const TrM &m);
	~TrM();
	TrM<Type, n> multiply(Type k);
	int operator ==(TrM t2);
	void ki();
};

//alapertelmezettkonstruktor
template <class Type, const int n>
	TrM<Type, n>::TrM() {
		v = new Type[n*(n+1)/2];
		int m = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i == j) { 
					v[m] = 1; 
					m++;
				}
				else if (j > i) {
					v[m] = 0;
					m++;
				}
			}
		}
	}

//kiiras
template <class Type, const int n>
void TrM<Type,n>::ki() {
	int m = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (j >= i) {
				cout << v[m] <<" ";
				m++;
			}
			else cout << 0 << " ";
		}
		cout << endl;
	}
	cout << endl;
}

//parameteres konstruktor
template <class Type, const int n>
TrM<Type, n>::TrM(Type *w) {
	v = new Type[n*(n + 1) / 2];
	for (int i = 0; i<n*(n + 1) / 2; i++) {
		v[i] = w[i];
	}
}

//masolo konstruktor
template <class Type, const int n>
TrM<Type, n>::TrM(const TrM &m) {
	v = new Type[n*(n + 1) / 2];
	for (int i = 0; i < n*(n + 1) / 2; i++) {
		v[i] = m.v[i];
	}
}

//destruktor
template <class Type, const int n>
TrM<Type, n>::~TrM() {
	delete[] v;
}

//szorzas
template <class Type, const int n>
TrM<Type, n> TrM<Type, n>::multiply(Type k) {
	TrM uj(v);
	for (int i = 0; i < n*(n + 1) / 2; i++)uj.v[i] *= k;
	return uj;
}

//egyenloseg
template <class Type, const int n>
int TrM<Type, n>:: operator ==(TrM m) {
	for (int i = 0; i < n*(n + 1) / 2;i++){
		if (v[i] != m.v[i]) return 0;
	}
	return 1;
}

int main() {
	TrM<float,5> a;
	a.ki();
	float x[] = { 1.1,2.2,3.3,4.4,5.5,6.6 };
	TrM<float, 3> b(x);
	b.ki();
	TrM<float, 3> c(b);
	c.ki();
	c.multiply(3).ki();
	if (b == c) cout << "egyenlo";
	else cout << "nemegyenlo";
	return 0;
}