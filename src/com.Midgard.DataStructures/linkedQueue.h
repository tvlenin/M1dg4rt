/*
 * linkedQueue.h
 *
 *  Created on: May 6, 2015
 *      Author: fabian
 */

#ifndef SRC_COM_MIDGARD_DATASTRUCTURES_LINKEDQUEUE_H_
#define SRC_COM_MIDGARD_DATASTRUCTURES_LINKEDQUEUE_H_
#include <iostream>

#include "../com.Midgard.DataStructures/linkedNode.h"

using namespace std;

/**
 * Clase Lista Doblemente Enlazada
 */
template<class k>
class LinkedList{

private:
	int _length;
	Node<k>* _head;
	Node<k>* _tail;

public:
	LinkedList();
	//virtual ~LinkedList();
	//Node<k>* insertTail(k);
	void insertTail(k);
	void deleteData(k);
	void showData();
	void vaciar();
	Node<k>* getHead();
	Node<k>* getTail();
	int getLength();
	bool isEmpty();
};

template<class k>
Node<k>* LinkedList<k>::getHead(){ return _head; }

template<class k>
Node<k>* LinkedList<k>::getTail(){ return _tail; }

template<class k>
int LinkedList<k>::getLength(){ return _length; }

template<class k>
bool LinkedList<k>::isEmpty()
{
	if(_head != 0){return false;}
	return true;
}

/**
 * Constructor de la clase en el que se
 * definen el head y el tail como nulos, además
 * el tamaño inicial de la lista en 0.
 */
template<class k>
LinkedList<k>::LinkedList(){
	_length = 0;
	_head = 0;
	_tail = 0;
}

/**
 * Método que permite insertar al final
 * de la lista, haciendo las operaciones correspondientes
 * para el movimiento de los nodos doblemente enlazados.
 */
template<class k>
//Node<k>* LinkedList<k>::insertTail(k pData){
void LinkedList<k>::insertTail(k pData){
	Node<k>* tmp = new Node<k>(pData);

	if(_head == 0){
		_length++;
		_head = tmp;
		_tail = _head;
	}
	else{
		_length++;
		_tail->setNext(tmp);
		tmp->setPrevious(_tail);
		_tail = tmp;
		_tail->setNext(_head);
		_head->setPrevious(_tail);
	}
}

/**
 * Método que permite borrar un dato específico
 * de la lista.
 */
template<class k>
void LinkedList<k>::deleteData(k pData){
	if(_head == 0){
		cout << "Empty List" << endl;
		return;
	}
	if(_head->getData() == pData){
		Node<k>* pDelete = _head;	//Se guarda el puntero en una variable temporal
		_head = _head->getNext();
		_tail->setNext(_head);
		_length--;
		delete pDelete;				//Se libera la memoria de la variable temporal
		return;
	}

	Node<k>* tmpNode = _head;
	while(tmpNode->getNext()!= _head && tmpNode->getNext()->getData() != pData){
		tmpNode = tmpNode->getNext();
	}

	if(tmpNode->getNext() == _head){
		return;
	}
	else{
		if(tmpNode->getNext() == _tail){
			Node<k>* pDelete = _tail;	//Se guarda el puntero en una variable temporal
			_tail = tmpNode;
			_tail->setNext(_head);		//Se libera la memoria de la variable temporal
			_length--;
			delete pDelete;
			return;
		}
		else{
			Node<k>* pDelete = tmpNode->getNext();//Se guarda el puntero en una variable temporal
			tmpNode->setNext(tmpNode->getNext()->getNext());
			delete pDelete;						  //Se libera la memoria de la variable temporal
			_length--;
			return;
		}
	}
}

/**
 * Método que muestra todos los elementos
 * de la lista. Recorriendola desde el head
 * hasta el tail. Utilizando con condición de finalización
 * en el ciclo for, su largo (_length)
 */
template<class k>
void LinkedList<k>::showData(){
	if(_head == 0){
		cout << "Empty List" << endl;
	}
	Node<k>* tmpNode = _head;
	for(int i=0; i < _length; i++){
		cout << "Dato: " << tmpNode->getData() << endl;
		tmpNode = tmpNode->getNext();
	}
}

/**
 * Limpiar la lista por completo
 */
template<class k>
void LinkedList<k>::vaciar(){
	Node<k>* tmpNode = _head;
	for(int i=0; i < _length; i++){
		Node<k>* pDelete = tmpNode;
		tmpNode = tmpNode->getNext();
		delete pDelete;
	}
	delete tmpNode;
	this->_head = 0;
	this->_tail = 0;
	this->_length = 0;
}




#endif /* SRC_COM_MIDGARD_DATASTRUCTURES_LINKEDQUEUE_H_ */
