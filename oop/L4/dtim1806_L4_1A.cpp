//Demeter Tamas
//511
//dtim1806
//L41a


#include <iostream>

using namespace std;

class Betelt {

};
class Ures {

};
const int maxhossz = 5;
int hossz;


class Lista {

	struct Elem {
		int adat;
		struct Elem *next;
	};
	struct Elem *elso;
	struct Elem *hatso;

public:
	Lista() {
		struct Elem* elso = NULL;
		struct Elem* hatso = NULL;
		hossz = 0;
	}

	void push(int ujadat) {

		hossz++;
		if (hossz > maxhossz) {
			throw Betelt();
		}
	
		struct Elem *ujelem = new Elem;
		ujelem->adat = ujadat;
		if (elso == NULL) elso = ujelem;
		else hatso->next = ujelem;
		hatso = ujelem;
		hatso->next = elso;

	}

	void pop() {
		if (elso == NULL) {
			throw Ures();
		}
		hossz--;
		if (elso == hatso) {
			delete elso;
			elso = NULL;
			hatso = NULL;
		}
		else {
			struct Elem *temp = elso;
			elso = elso->next;
			hatso->next = elso;
			delete temp;
		}
	}

	void kiir() {
		struct Elem *elem;
		elem = elso;
		while (elem->next != elso) {
			cout << elem->adat << " ";
			elem = elem->next;
		}
		cout << elem->adat << " ";
	}

};

int main() {

	Lista L;
	L.push(1);
	L.push(1);
	L.push(1);
	L.push(1);
	L.push(1);
	try {
		L.push(1);
	}
	catch (Betelt x) {
		cout << "Betelt!";
	}

	return 0;
}