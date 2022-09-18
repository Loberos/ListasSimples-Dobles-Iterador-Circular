#pragma once

template <class T>
class ListasIterador
{

private:
	struct Nodo {
		T elem;
		Nodo* next;
		Nodo(T elem = 0, Nodo* next = nullptr) : elem(elem), next(next) {}

	};
	Nodo* inicio;
	int n;

public:
	ListasIterador();
	~ListasIterador();
	template <class T>
	class CIterador {
		Nodo* aux;
	public: 
		Iterador(Nodo* aux = nullptr) : aux(aux) {}
		void operator ++ () { aux = aux->next; }
		bool operator != (Iterador it) { return aux != it.aux; }
		T operator* () { return aux->elem; }
	};
	CIterador inicial() { return CIterador(inicio); };
	CIterador ultimo() { return CIterador(nullptr); };
	bool insertarInicio(T elem);
	bool insertar(T elem, int p);
	bool insertarFinal(T elem);
	bool eliminarInicio();
	int tamanio();
};

template <class T>
ListasIterador<T>::ListasIterador()
{
	n = 0;
	inicio = nullptr;
}

template <class T>
ListasIterador<T>::~ListasIterador()
{
	while (inicio != nullptr) {
		Nodo* aux = inicio;
		inicio = inicio->next;
		delete aux;
	}
}

template <class T>
bool ListasIterador<T>::insertarInicio(T elem){
	Nodo* nuevo = new Nodo(elem, inicio);
	if (nuevo == nullptr) return false;
	inicio = nuevo;
	++n;
	return true;
}
template <class T>
bool ListasIterador<T>::insertar(T elem, int p){
	if (p < 0 || p > n) return false;
	if (p == 0) insertarInicio(elem);
	int c = 1;
	Nodo* aux = inicio;
	while (c++ < p) {
		aux = aux->next;
	}
	Nodo* nuevo = new Nodo(elem, aux->next);
	if (nuevo == nullptr) return false;
	aux->next = nuevo;
	++n;
	return true;

}
template <class T>
bool ListasIterador<T>::insertarFinal(T elem){
	insertar(elem, n);
}
template <class T>
bool ListasIterador<T>::eliminarInicio(){
	if (n == 0) return false;
	Nodo* aux = inicio;
	inicio = inicio->next;
	delete aux;
	--n;
	return true;
}
template <class T>
int ListasIterador<T>::tamanio() { return n;}