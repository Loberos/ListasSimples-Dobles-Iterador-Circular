#pragma once
#include <iostream>
template<class T>
class Nodo
{
public:
	Nodo(T _valor, Nodo<T>* _siguiente = NULL);
	~Nodo();
	T dato;
	Nodo<T>* siguiente;
private: 

};
template<class T>
Nodo<T>::Nodo(T _valor, Nodo<T>* _siguiente = NULL)
{
	dato = _valor;
	siguiente = _siguiente;
}
template<class T>
Nodo<T>::~Nodo()
{
}