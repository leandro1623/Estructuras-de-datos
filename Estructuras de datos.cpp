#include<iostream>
#include<stdlib.h>
#include"Estructuras de datos.h"

//definicion de funciones miembro de las clases de "estructuras de datos"

//--------------------pilas--------------------------------------------------------------
//set and get
void Pila::set_dato(int dato2){//set
	dato=dato2;
}
int Pila::get_dato(){//get
	return dato;
}

//atributes
void Pila::agg_nodo(){
	Nodo *nuevo_nodo=new Nodo();
	nuevo_nodo->dato=dato;
	nuevo_nodo->siguiente=pila;
	pila=nuevo_nodo;
}

void Pila::sacar_pila(){
	Nodo *aux=pila;
	set_dato(aux->dato);
	pila=aux->siguiente;
	delete aux;
}

void Pila::show(){
	std::cout<<"Los datos son: ";
	while(pila!=NULL){
		sacar_pila();
		std::cout<<get_dato()<<" -> ";
	}
	if(pila==NULL){
		std::cout<<"NULL\n";
	}
}
//-------------------------fin pilas-----------------------------------------------------

//-----------------------------------------colas-----------------------------------------
//constructor
Cola::Cola(){
	frente=NULL;
	fin=NULL;
}
//set and get
void Cola::set_dato(int dato1){//set
	dato=dato1;
}
int Cola::get_dato(){//get
	return dato;
}

//atributes
void Cola::agg_nodo(){//agrega un nodo a la cola
	Nodo *nuevo_nodo=new Nodo();
	nuevo_nodo->dato=get_dato();
	nuevo_nodo->siguiente=NULL;
	
	if(frente==NULL){
		frente=nuevo_nodo;
		fin=nuevo_nodo;
	}
	else{
		fin->siguiente=nuevo_nodo;
	}
	fin=nuevo_nodo;
}

void Cola::sacar_nodo(){//saca nodos de la cola
	Nodo *aux=frente;
	set_dato(aux->dato);
	frente=aux->siguiente;
	delete aux;
}

void Cola::show(){
	std::cout<<"\nCola: ";
	if(frente==NULL){//si es el fin de la cola
			std::cout<<"NULL\n";
	}
	else{
		while(frente!=NULL){//mientras no sea el fin de la cola
			sacar_nodo();
			std::cout<<get_dato()<<" -> ";
			if(frente==NULL){//si es el fin de la cola
				std::cout<<"NULL\n";
			}	
		}
	}
}
//---------------------------------------fin colas---------------------------------------

//----------------------------------------listas-----------------------------------------
Lista::Lista(){//constructor
	dato=0;
	lista=NULL;
}

void Lista::set_dato(int dato1){//set
	dato=dato1;
}
int Lista::get_dato(){//get
	return dato;
}
//atributes

//agrega un nodo a la lista
void Lista::agg_nodo(){
	Nodo *nuevo_nodo=new Nodo();
	nuevo_nodo->dato=get_dato();
	
	Nodo *aux1=lista,*aux2=NULL;
	
	while((aux1!=NULL) && (aux1->dato < get_dato())){
		aux2=aux1;
		aux1=aux1->siguiente;
	}
	
	if(lista==aux1){
		lista=nuevo_nodo;
	}
	else{
		aux2->siguiente=nuevo_nodo;
	}
	nuevo_nodo->siguiente=aux1;
}

//muestra la lista
void Lista::show(){
	Nodo *actual=new Nodo();
	
	actual=lista;
	while(actual!=NULL){
		std::cout<<actual->dato<<" -> ";
		actual=actual->siguiente;
	}
	if(actual==NULL){
		std::cout<<" NULL\n";
	}
}
//------------------------------------fin lista------------------------------------------

//-----------------------------------arboles---------------------------------------------
Arbol::Arbol(){//constructor
	dato=0;
	arbol=NULL;
}

//set and get
void Arbol::set_dato(int dato1){//set :: public
	dato=dato1;
}

int Arbol::get_dato(){//get :: public
	return dato;
}

	//atributes

void Arbol::agg_nodo(Nodo *&arbol,int dato,Nodo *padre){//agrega un nodo al arbol :: private
	if(arbol==NULL){
		Nodo *nuevo_nodo=crear_nodo_en_heap(dato,padre);
		arbol=nuevo_nodo;
	}
	else{
		int pivote=arbol->dato;
		if(dato < pivote){
			agg_nodo(arbol->izq,dato,arbol);
		}
		else{
			agg_nodo(arbol->der,dato,arbol);
		}
	}
}
		
void Arbol::show_arbol(Nodo *arbol,int cont){//muestra el arbol :: private 
	if(arbol==NULL){
		return;
	}
	else{
		show_arbol(arbol->der,cont+1);
		for(int i=1;i<=cont;i++){
			std::cout<<"   ";
		}
		std::cout<<arbol->dato<<"\n";
		show_arbol(arbol->izq,cont+1);
	}
}	
		
void Arbol::agg(){//agrega un nodo al arbol :: public
	agg_nodo(arbol,get_dato(),NULL);
}

void Arbol::show(){//muestra el arbol :: public
	int cont=0;
	std::cout<<"\nArbol: \n";
	if(arbol==NULL){
		std::cout<<" NULL\n";
	}
	else{
		show_arbol(arbol,cont);
	}
}		