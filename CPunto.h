#pragma once
#include <string>
#include <sstream>
using namespace std;

class Punto
{
public:
	Punto(int _x, int _y);
	~Punto();
	string toString(); 
private:
	int x, y; 
};

Punto::Punto(int _x, int _y)
{
	this->x = _x;
	this->y = _y; 
}

Punto::~Punto()
{
}
string Punto::toString() {
	ostringstream  ss;
	ss << "p(";
	ss << x;
	ss << ", ";
	ss << y;
	ss << ")";
	return(ss.str());
}
