#pragma once
#include<sstream>
using namespace std;

class Punto
{
private:
	static int puntosCreados;

	float x;
	float y;

public:
	Punto(float x = 0, float y = 0)
	{
		Punto::puntosCreados++;
		this->x = x;
		this->y = y;
	}

public:

	static int getPuntosCreados()
	{
		return Punto::puntosCreados;
	}

    float getX() const { return x; }
    void setX(float x) { this->x = x; }

    float getY() const { return y; }
    void setY(float y) { this->y = y; }

	string toString() const
	{
		stringstream s;
		s << "x = " << this->getX() << ", ";
		s << "y = " << this->getY();
		return s.str();
	}

	// Sobrecarga como miembro de la clase
	/*Punto operator+(const Punto& p2)
	{
		return Punto(this->getX() + p2.getX(), this->getY() + p2.getY());
	}*/

};

int Punto::puntosCreados = 0;

// Sobrecarga como función global
Punto operator+(const Punto& p1, const Punto& p2)
{
	return Punto(p1.getX() + p2.getX(), p1.getY() + p2.getY());
}

Punto operator-(const Punto& p1, const Punto& p2)
{
	return Punto(p1.getX() - p2.getX(), p1.getY() - p2.getY());
}

float operator*(const Punto& p1, const Punto& p2)
{
	return p1.getX() * p2.getX() + p1.getY() * p2.getY();
}

ostream& operator<<(ostream& out, const Punto& punto)
{
	out << punto.toString();
	return out;
}

