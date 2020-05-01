

#ifndef __NODODOBLE_H__
#define __NODODOBLE_H__

template<class T>
class NodoDoble {
public:

	T valor;
	NodoDoble<T>* siguiente;
	NodoDoble<T>* anterior;

public:
	NodoDoble(T v, NodoDoble<T>* sig = NULL, NodoDoble<T>* ant = NULL) {
		valor = v;

		siguiente = sig;
		anterior = ant;
	}
};

#endif // !__NODODOBLE_H__

