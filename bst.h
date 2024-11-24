/**Proyecto: Restaurant
 * Nombre: Shaula Suhail Paz Garay
 * Matricula: A01712013
 * Fecha: 18 de septiembre de 2024
 */

#ifndef BST_H_
#define BST_H_

//Librerias
#include <string>
#include <sstream>
#include <iostream>

/**BST
 * 
 * Complejidad Espacial O(n)
 * 
 * Complejidad Temporal:
 * 	  Promedio:
 * 		Acceso: Θ(log(n))
 * 		Busqueda: Θ(log(n))
 * 		Insercion: Θ(log(n))
 * 	  Peor:
 * 		Acceso: O(n)
 * 		Busqueda: O(n)
 * 		Insercion: O(n)
*/ 

template <class T> class BST;

template <class T>
class Node {
private:
	T value;
	Node *left, *right;
	std::string nombre;

public:
	Node(std::string, T);
	Node(std::string, T, Node<T>*, Node<T>*);
	void add(std::string, T);
	bool find(T);

	friend class BST<T>;
};

template <class T>
Node<T>::Node(std::string nom, T val) : nombre(nom), value(val), left(0), right(0) {}

template <class T>
Node<T>::Node(std::string nom, T val, Node<T> *le, Node<T> *ri)
	: nombre(nom), value(val), left(le), right(ri) {}

template <class T>
void Node<T>::add(std::string nom, T val) {
	if (val < value) {
		if (left != 0)
			left->add(nom, val);
		else
			left = new Node<T>(nom, val);
	} else {
		if (right != 0)
			right->add(nom, val);
		else
			right = new Node<T>(nom, val);
	}
}

template <class T>
bool Node<T>::find(T val){
	if (val == value){
		std::cout << "El articulo es: " << nombre << std::endl;
		return true;
	}
	else if (val < value)
		return (left != 0 && left->find(val));
	else if (val > value)
		return (right != 0 && right->find(val));
}

template <class T>
class BST {
private:
	Node<T> *root;

public:
	BST();
	bool empty() const;
	bool find(T) const;
	void add(std::string, T);
};

template <class T>
BST<T>::BST() : root(0) {}

template <class T>
bool BST<T>::empty() const {
	return (root == 0);
}

template <class T>
bool BST<T>::find(T val) const {
	if (root != 0)
		return root->find(val);
	else
		return false;
}

template<class T>
void BST<T>::add(std::string nom, T val) {
	if (root != 0)
		root->add(nom, val);
	else
		root = new Node<T>(nom, val);
}

#endif