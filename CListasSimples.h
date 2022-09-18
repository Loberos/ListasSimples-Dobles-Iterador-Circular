#pragma once
#include "CNodo.h"
#include "CPunto.h"
#include <functional>
template<class T>
class ListasSimples
{
public:
	ListasSimples();
	~ListasSimples();
	void insertarInicio(T _valor);
	void insertarFinal(T _valor);
	void mostrar(function<string(T)>toStrin);

private:
	Nodo<T>* inicio;
};
template<class T>
ListasSimples<T>::ListasSimples()
{
	incio = NULL; 
}

template<class T>
ListasSimples<T>::~ListasSimples()
{
	Nodo<T>* temp;
	while (inicio != nullptr) {
		temp = inicio;
		inicio = inicio->siguiente;
		delete temp;
		temp = nullptr;
	}
}
template<class T>
void ListasSimples<T>::insertarInicio(T _valor) {
	Nodo<T>* nodo = new Nodo<T>(v);

	if (inicio == NULL)
		inicio = nodo;
	else {
		nodo->siguiente = inicio;
	}
	inicio = nodo;
}
template<class T>
void ListasSimples<T>::insertarFinal(T _valor) {

}
template<class T>
void ListasSimples<T>::mostrar(function<string(T)>toStrin) {
	Nodo<T>* nodo = inicio;
	cout << "L -> ";
	do {
		T* elemento = nodo->valor;
		cout << toStrin(elemento);
		nodo = nodo->siguiente;
		if (nodo != nullptr)
			cout << "-> ";
	} while (nodo != nullptr);
	cout << endl;
}