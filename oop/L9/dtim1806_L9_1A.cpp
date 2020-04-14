//Demeter Tamas
//dtim1806
//511/2
//L9 a

#include <iostream>
#include <string>

using namespace std;

class E {
protected:
	int e;
public:
	E(string& str) {
		e = 5;
		str += "E";
	}
};

class F {
protected:
	int f;
public:
	F(string& str) {
		f = 6;
		str += "F";
	}
};

class A : public virtual E,public virtual F{
protected:
	int a;
public:
	A(string& str) :E(str),F(str) {
		a = 1;
		str+= "A";
	}
};

class B : public virtual E, public virtual F {
protected:
	int b;
public:
	B(string& str) :E(str), F(str) {
		b = 2;
		str+= "B";
	}
};

class C : public virtual E, public virtual F {
protected:
	int c;
public:
	C(string& str) :E(str), F(str) {
		c = 3;
		str+= "C";
	}
};

class D : public virtual E, public virtual F {
protected:
	int d;
public:
	D(string& str) :E(str), F(str) {
		d = 4;
		str+= "D";
	}
};

class G : public E, public F{
protected:
	int g;
public:
	G(string& str) :E(str), F(str) {
		g = 7;
		str+= "G";
	}
};

class H : public E, public F{
protected:
	int h;
public:
	H(string& str) :E(str), F(str) {
		h = 8;
		str+= "H";
	}
};

class I {
protected:
	int i;
public:
	I(string& str) {
		i = 9;
		str+= "I";
	}
};

class J : public A, public B, public C, public D, public G, public H, virtual public I{
protected:
	int j;
public:
	J(string& str) : A(str),B(str),C(str),D(str),G(str),H(str),I(str),A::E(str),A::F(str) {
		j = 10;
		str+= "J";
	}
	void kiir() {
		cout << a << b << c << d << A::e << A::f << g << h << i << endl;
	}
};


int main() {
	string s = "";
	J obj(s);
	obj.kiir();
	cout << endl<<s;
	return 0;
}