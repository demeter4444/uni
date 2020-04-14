//Demeter Tamas
//dtim1806
//511/2
//L10 1

#include <iostream>
using namespace std;

template <class T> class List;

//node
template <class T>
class Node {
	T *elem;
	Node *next;
public:
	Node(T e);
	~Node();
	ostream& print(ostream& s);
	friend class List<T>;
};

template <class T>
Node<T>::Node(T e) {
	elem = new T(e);
	next = NULL;
}

template <class T>
Node<T>::~Node() {
	delete elem;
}

template <class T>
ostream& Node<T>::print(ostream &s) {
	return s << *elem;
}

template <class T>
ostream& operator <<(ostream &s, Node<T> &o) {
	return o.print(s);
}

//list
template <class T>
class List {
	Node<T> *front;
	Node<T> *rear;
	int n;
public:
	List();
	~List();

	void add(T e);
	void remove();
	bool isempty();
	ostream& print(ostream &s);

	class iterator;

	iterator begin() {
		return iterator(front);
	}

	iterator end() {
		return iterator(NULL);
	}
};

template <class T>
List<T>::List() {
	n = 0;
	front = NULL;
	rear = NULL;
}

template <class T>
List<T>::~List() {
	Node<T> *a = front;
	while (front != NULL) {
		front = front->next;
		delete a;
		a = front;
	}
}

template <class T>
void List<T>::add(T e) {
	Node<T> *a = new Node<T>(e);
	if (front == NULL) {
		front = rear = a;
	}
	else {
		rear->next = a;
		rear = a;
	}
	n++;
}

template <class T>
void List<T>::remove() {
	if (n == 0) return;
	Node<T> *a = front;
	front = front->next;
	delete a;
	n--;
}

template <class T>
ostream& List<T>::print(ostream& s) {
	if (n == 0) return s << "[]";
	Node<T> *a = front;
	s << "[";
	while (a != rear) {
		s << *a << ", ";
		a = a->next;
	}
	s << *a << "]";
	return s;
}

template <class T>
ostream& operator <<(ostream &s, List<T>& o) {
	return o.print(s);
}

template <class T>
bool List<T>::isempty() {
	return (n > 0) ? false : true;
}

template <class T>
class List<T>::iterator {
	Node<T> *current;
public:
	iterator(Node<T> *p) {
		current = p;
	}

	~iterator() {}

	//iterator& operator =(const iterator& other) {
	//	current = other.current;
	//	return *this;
	//}

	iterator& operator =(const iterator& other);

	bool operator ==(const iterator& other) {
		return (current == other.current);
	}

	bool operator !=(const iterator& other) {
		return (current != other.current);
	}

	iterator& operator ++() {
		if (current != NULL) {
			current = current->next;
		}
		return *this;
	}

	iterator operator ++(int) {
		iterator tmp(*this);
		++(*this);
		return tmp;
	}

	T operator*() {
		return (*current->elem);
	}
};


template <class T>
typename List<T>::iterator & List<T>::iterator::operator =(const iterator& other) {
	current = other.current;
	return *this;
}


int main() {
	Node<int> a(1);
	cout << a << endl;
	List<int> b;
	b.add(1);
	b.add(2);
	b.add(3);
	b.add(4);
	b.add(5);
	cout << b << endl;
	b.remove();
	cout << b << endl;

	cout << "[";
	for (List<int>::iterator i = b.begin(); i != b.end(); i++) {
		cout << *i << ", ";
	}
	cout << "]";
	return 0;
}