// Lista Doble Circular.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
using namespace std;

//Estructura del nodo, este debe de poseer tres atributos: valor(entero) 
//y dos punteros(anterior y siguiente) a nodos.
struct nodo {
	int valor;
	nodo* anterior;
	nodo* siguiente;
} *primero, *ultimo;

void insertarNodo();
void buscarNodo();
void modificarNodo();
void eliminarNodo();
void mostrarDePrimeroUltimo();
void mostrarDeUltimoPrimero();


void insertarNodo() {
	nodo* nuevo = new nodo();
	std::cout << endl << "inserte el dato que contendra el nuevo nodo: " << endl;
	std::cin >> nuevo->valor;//Guardamos el valor leido en la instancia de nodo del metodo insertarNodo.
	if (primero == NULL) {
		primero = nuevo;//Debe de apuntar al primer elemento de la lista.
		ultimo = nuevo;//Aunta al primero de la lista para poder mostrar el efecto circular.
		primero->siguiente = primero;//Ejemplo  (67)->(67)
		primero->anterior = ultimo;//Ejemplo (67) <- (67)
		//Osea que al final queda de la siguiente forma: (67) <- (67) -> (67)
	}
	else {
		ultimo->siguiente = nuevo;//Se quiere ingresar un valor a una lista ya existente con valores.
		//Entonces queda de la siguiente manera   (67) <- (67) -> (23)
		nuevo->anterior = ultimo; // (67) <- (67) <- (23)
		nuevo->siguiente = primero;// (67)A -> (67) -> (23) -> (67)A | En otras palabras la lista es 67,23.
		ultimo = nuevo;//Acomodo la lista para que el ultimo sea el valor de nuevo.
		primero->anterior = ultimo;//Que el primero apunte al nuevo ultimo.
	}
	std::cout << "Nodo ingresado" << endl;
}

void buscarNodo() {
	nodo* actual = new nodo();//Se crea un nodo para recorrer la lista.
	actual = primero;
	bool check = false;
	int valorBuscar = 0;
	std::cout << endl << "Ingrese el valor que desea buscar dentro de la lista:";
	std::cin >> valorBuscar;
	if (primero != NULL && check != true) {
		do {
			if (actual->valor == valorBuscar) {
				check = true;
				std::cout << "Nodo encontrado" << endl;
			}
			actual = actual->siguiente;
		} while (actual != primero);//mientras el nodo actual sea diferente de primero, entre al ciclo.
		if (!check) {
			std::cout << "Nodo no encontrado" << endl;
		}
	}
	else {
		std::cout << "La lista no posee ningun valor." << endl;
	}
}

void modificarNodo() {
	nodo* actual = new nodo();//Se crea un nodo para recorrer la lista.
	actual = primero;
	bool check = false;
	int valorBuscar = 0;
	int valorModificar = 0;
	std::cout << endl << "Ingrese el valor que desea buscar dentro de la lista:";
	std::cin >> valorBuscar;
	std::cout << endl << "Ingrese el valor que desea modificar dentro de la lista:";
	std::cin >> valorModificar;
	if (primero != NULL && check != true) {
		do {
			if (actual->valor == valorBuscar) {
				check = true;
				std::cout << "Nodo modificado" << endl;
				actual->valor = valorModificar;
			}
			actual = actual->siguiente;
		} while (actual != primero && check == false);//mientras el nodo actual sea diferente de primero, entre al ciclo.
		if (!check) {
			std::cout << "Nodo no encontrado" << endl;
		}
	}
	else {
		std::cout << "La lista no posee ningun valor." << endl;
	}
}

void eliminarNodo() {
	nodo* actual = new nodo();//Se crea un nodo para recorrer la lista.
	actual = primero;
	bool check = false;
	int valorBuscar = 0;
	std::cout << endl << "Ingrese el valor que desea eliminar dentro de la lista:";
	std::cin >> valorBuscar;
	if (primero != NULL && check != true) {
		do {
			if (actual->valor == valorBuscar) {
				check = true;
				std::cout << "Nodo eliminado" << endl;
				(actual->anterior)->siguiente = actual->siguiente;
			}
			actual = actual->siguiente;
		} while (actual != primero && check == false);//mientras el nodo actual sea diferente de primero, entre al ciclo.
		if (!check) {
			std::cout << "Nodo no encontrado" << endl;
		}
	}
	else {
		std::cout << "La lista no posee ningun valor." << endl;
	}
}

void mostrarDePrimeroUltimo() {
	nodo* actual = new nodo();//Se crea un nodo para recorrer la lista.
	actual = primero;
	if (primero != NULL) {
		do {
			std::cout << actual->valor << endl;
			actual = actual->siguiente;
		} while (actual != primero);//mientras el nodo actual sea diferente de primero, entre al ciclo.
	}
	else {
		std::cout << "La lista no posee ningun valor." << endl;
	}
}


void mostrarDeUltimoPrimero() {
	nodo* actual = new nodo();//Se crea un nodo para recorrer la lista.
	actual = ultimo;
	if (primero != NULL) {
		do {
			std::cout << actual->valor << endl;
			actual = actual->anterior;
		} while (actual != ultimo);//mientras el nodo actual sea diferente de primero, entre al ciclo.
	}
	else {
		std::cout << "La lista no posee ningun valor." << endl;
	}
}





/*
Main, desde aqui se muestra la lista circula doblemente enlazada y sus metodos.
*/

int main()
{
	std::cout << endl << "Lista Circular Doble enlazada." << endl << endl;
	int breakerMenu = 0;
	do {
		int lectura = 0;
		std::cout << endl;
		std::cout << "1)Insertar." << endl;
		std::cout << "2)Buscar." << endl;
		std::cout << "3)Modificar." << endl;
		std::cout << "4)Eliminar." << endl;
		std::cout << "5)Mostrar de primero a ultimo." << endl;
		std::cout << "6)Mostrar de ultimo a primero." << endl;
		std::cout << "7)Salir." << endl;
		std::cin >> lectura;
		switch (lectura) {
		case 1:
			insertarNodo();
			break;
		case 2:
			buscarNodo();
			break;
		case 3:
			modificarNodo();
			break;
		case 4:
			eliminarNodo();
			break;
		case 5:
			std::cout << endl << "LCDE de primero a ultimo" << endl;
			mostrarDePrimeroUltimo();
			break;
		case 6:
			std::cout << endl << "LCDE de ultimo a primero" << endl;
			mostrarDeUltimoPrimero();
			break;
		case 7:
			breakerMenu = 1;
			break;
		}

	} while (breakerMenu == 0);

}