#pragma once
#include"Punto.h"
#include"ObjetoBase.h"

class Linea : public ObjetoBase
{
private:
	Punto* p1;
	Punto* p2;

public:
	Linea(float x1, float y1, float x2, float y2)
	{
		this->p1 = new Punto(x1, y1);
		this->p2 = new Punto(x2, y2);
	}

	Linea(const Linea& source)
	{
		this->deepCopy(source);
	}

	Linea& operator=(const Linea& source)
	{
		if (this != &source)
		{
			delete p1;
			delete p2;
			this->deepCopy(source);
		}

		return *this;
	}

	string toString()
	{
		stringstream s;
		s << "Linea va de " << *this->p1 << " hasta " << *this->p2;
		return s.str();
	}

	~Linea()
	{
		delete this->p1;
		delete this->p2;
	}

private:
	void deepCopy(const Linea& source)
	{
		this->p1 = new Punto(*source.p1);
		this->p2 = new Punto(*source.p2);
	}

public:
    Punto* getP1() const { return p1; }
    void setP1(Punto* p1) { this->p1 = p1; }

    Punto* getP2() const { return p2; }
    void setP2(Punto* p2) { this->p2 = p2; }

};