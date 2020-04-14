//Demeter Tamas
//dtim1806
//511/2
//L7_2A

#include <iostream>

using namespace std;

template <class Type>
void dupla(Type x) {
	x = 2 * x;
}

template <class Type>
class Lista {
	struct Elem {
		Type adat;
		struct Elem *next;
	};
	struct Elem *elso;
	struct Elem *hatso;
	int hossz;
	const int maxhossz=5;
public:
	Lista();
	~Lista();
	void push(Type x);
	Type pop();
	void kiir();
	Type operator [](int x);
	void operator ()(void(*f)(Type&));

};

class Betelt {

};
class Ures {

};

template <class Type>
	Lista<Type>::Lista() {
		struct Elem* elso = NULL;
		struct Elem* hatso = NULL;
		hossz = 0;
	}

template <class Type>
	Lista<Type>::~Lista() {
		struct Elem *elem;
		elem = elso;
		while (elem->next != elso) {
			struct Elem* elozo = elem;
			elem = elem->next;
			delete elozo;
		}
		delete elem;
		}
		
	

template <class Type>
	void Lista<Type>::push(Type x) {
		hossz++;
		if (hossz > maxhossz) {
			throw Betelt();
		}
		struct Elem *ujelem = new Elem;
		ujelem->adat = x;
		if (elso == NULL) elso = ujelem;
		else hatso->next = ujelem;
		hatso = ujelem;
		hatso->next = elso;
	}

template <class Type>
	Type Lista<Type>::pop() {
		if (elso == NULL) {
			throw Ures();
		}
		hossz--;
		if (elso == hatso) {
			Type tempx = elso->adat;
			delete elso;
			elso = NULL;
			hatso = NULL;
			return tempx;
		}
		else {
			struct Elem *temp = elso;
			Type tempx = temp->adat;
			elso = elso->next;
			hatso->next = elso;
			delete temp;
			return tempx;
		}
	}

template <class Type>
	void Lista<Type>::kiir() {
		struct Elem *elem;
		elem = elso;
		while (elem->next != elso) {
			cout << elem->adat << " ";
			elem = elem->next;
		}
		cout << elem->adat << " ";
	}

template <class Type>
	Type Lista<Type>::operator [](int x) {
		struct Elem *elem;
		elem = elso;
		int count = 0;
		while (elem->next != elso) {
			if (count == x) return elem->adat;
			elem = elem->next;
			count++;
		}
	if (count == x) return elem->adat;
	return (Type)-999;
	}

	template <class Type>
		void Lista<Type>::operator ()(void(*f)(Type&)) {
			struct Elem *elem;
			elem = elso;
			while (elem->next != elso) {
				f(elem->adat);
				elem = elem->next;
			}
			f(elem->adat);
		}
	
int main() {
	Lista<int> L;
	L.push(1);
	L.push(2);
	L.push(3);
	L.push(4);
	L.push(5);
	L.kiir();
	int a = L.pop();
	cout << endl;
	cout << a;
	cout << endl;
	L.kiir();
	cout << endl;
	cout << L[2];
	L(dupla);
	cout << endl;
	L.kiir();
	//try {
		//L.push(6);
		//L.push(7);
	//}
	//catch (Betelt x) {
		//cout << "Betelt!";
	//}
	return 0;
	}