#pragma once
#include "CNodo.h"
#include "CPunto.h"
#include <functional>
template<class T>
class ListaCircularSimple
{
public:
	ListaCircularSimple();
	~ListaCircularSimple();
	void AgregaralInicio(T v);
	void AgregaralFinal(T v);
	void AgregarenPosicion(T v, int pos);
	void Mostrar(function<string(T)>toStrin);

private:
	Nodo<T>* inicio;
	int longitud;

};

template<class T>
ListaCircularSimple<T>::ListaCircularSimple()
{
	inicio = nullptr; 
	longitud = 0; 
}

template<class T>
ListaCircularSimple<T>::~ListaCircularSimple()
{
}

template<class T>
void ListaCircularSimple<T>::AgregaralInicio(T v) {
	Nodo<T>* nuevo;
	nuevo = new Nodo<T>(v); 

	if (inicio == nullptr) {
		inicio = nuevo;
		nuevo->siguiente = inicio;
	}
	else {
		Nodo<T>* aux = inicio;
		while (aux->siguiente != inicio) {
			aux = aux->siguiente;
		}
		nuevo->siguiente = inicio;
		aux->siguiente = nuevo;
		inicio = nuevo;
	}
}
template<class T>
void ListaCircularSimple<T>::AgregaralFinal(T v) {
	Nodo<T>* nuevo;
	nuevo = new Nodo<T>(v);

	if (inicio == NULL) {
		AgregaralInicio(v);
		return;
	}
	else {
		Nodo<T>* aux = inicio;
		while (aux->siguiente != inicio) {
			aux = aux->siguiente; 
		}
		aux->siguiente = nuevo;
		nuevo->siguiente = inicio;

	}
}
template<class T>
void ListaCircularSimple<T>::AgregarenPosicion(T v, int pos) {
	Nodo<T>* nuevo;
	nuevo = new Nodo<T>(v);

	int i = 1;
	Nodo<T>* aux = inicio;
	while (i < pos)
	{
		aux = aux->siguiente; 
		i++;
	}
	nuevo->siguiente = aux->siguiente; 
	aux->siguiente = nuevo;

}
template<class T>
void ListaCircularSimple<T>::Mostrar(function<string(T)>toStrin) {
	Nodo<T>* nodo = inicio;
	cout << "L -> ";
	do {
		T* elemento = nodo->valor;
		cout << toStrin(elemento);
		nodo = nodo->siguiente;
		if (nodo != incio)
			cout << "-> ";
	} while (nodo != incio);
	cout << endl;

}