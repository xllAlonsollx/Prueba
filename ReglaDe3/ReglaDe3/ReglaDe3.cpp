// ReglaDe3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include"Linea.h"
#include"Canvas.h"

int main()
{
	Linea* l1 = new Linea(1, 10, 1, 4);
	Linea* l2 = new Linea(4, 4, 8, 8);
	Linea* l3 = new Linea(*l2);

	cout << "Despues de copia:" << endl;
	cout << l1->toString() << endl;
	cout << l2->toString() << endl;
	cout << l3->toString() << endl << endl;

	*l3 = *l1;
	cout << "Despues de asignacion:" << endl;
	cout << l1->toString() << endl;
	cout << l2->toString() << endl;
	cout << l3->toString() << endl << endl;

	// Creando un canvas
	Canvas* canvas = new Canvas("Canvas1");
	canvas->agregarLinea(l1);
	canvas->agregarLinea(l2);
	canvas->agregarLinea(l3);
	cout << canvas->toString() << endl;

	Canvas* canvas2 = new Canvas(*canvas);
	cout << canvas2->toString() << endl;

	delete canvas;
	delete canvas2;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
