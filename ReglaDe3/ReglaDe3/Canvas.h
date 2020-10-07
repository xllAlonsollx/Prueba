#pragma once
#include "ObjetoBase.h"
#include"Linea.h"
#include"IList.h"
#include"ArrayList.h"
#include"IIterador.h"

class Canvas : public ObjetoBase
{
private:
	IList* lineas;
	string nombre;

public:
	Canvas(string nombre)
	{
		this->nombre = nombre;
		this->lineas = new ArrayList(16);
	}

	Canvas(const Canvas& source)
	{
		this->deepCopy(source);
	}

	Canvas& operator=(const Canvas& source)
	{
		if (this != &source)
		{
			this->liberarMemoria();
			this->deepCopy(source);
		}

		return *this;
	}

	void agregarLinea(Linea* linea)
	{
		this->lineas->insertarAlFinal(linea);
	}

	string toString()
	{
		stringstream s;
		s << "Las siguientes son las lineas del canvas " << this->nombre << endl;
		s << this->lineas->toString() << endl;
		return s.str();
	}

	~Canvas()
	{
		this->liberarMemoria();
	}

private:
	void deepCopy(const Canvas& source)
	{
		this->nombre = string(source.nombre) + " Copy";
		this->lineas = new ArrayList(source.lineas->getCantidad());
		IIterador* ite = source.lineas->obtenerIterador();
		while (ite->haySiguiente())
		{
			Linea* actual = dynamic_cast<Linea*>(ite->actual());
			this->lineas->insertarAlFinal(new Linea(*actual));
		}
		delete ite;
	}

	void liberarMemoria()
	{
		this->lineas->liberarDatosInternos();
		delete this->lineas;
	}

};