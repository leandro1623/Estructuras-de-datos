#include<iostream>
#include<iomanip>
#include<stdlib.h>										/*programa finalizado*/
#include<conio.h>									/*By Leandro Brito Contreras*/							
#include<string.h>								/*Este programa trata sobre los algoritmos */
#include"Estructuras de datos.h"	/*de estructura de datos como los son pilas, colas, listas y arboles*/

//prototipos de funcion
//menu
void menu();
//pilas
void insertar_pilas();
void mostrar_pila();
//colas
void insertar_cola();
void mostrar_cola();
//listas
void insertar_lista();
void mostrar_lista();
//arboles
void agg_al_arbol();
void mostrar_el_arbol();

Pila pila1;//objeto para pila
Cola cola1;//objeto para cola
Lista lista1;//objeto para lista
Arbol arbol1;//objeto para arbol

int main() {//-------main----
	system("color 8f");
	menu();
	
	return 0;
}//-------fin main-----------

//--------------------------------------menu principal----------------------------------------
void menu(){
	char opc;
	do{
		std::cout<<"1. Colas  \n";
		std::cout<<"2. Pilas  \n";
		std::cout<<"3. Listas \n";
		std::cout<<"4. Arboles\n";
		std::cout<<"5. Salir  \n";
		std::cout<<"Digite su opcion: ";std::cin>>opc;
		
		system("cls");
		switch(opc){
			case '1': std::cout<<".:COLASS:.\n1. Agregar\n2. Mostrar\nOpcion: ";std::cin>>opc;
					if(opc=='1'){
						insertar_pilas();
					}
					else if(opc=='2'){
						mostrar_pila();
					}
					else{
						std::cout<<"**Opcion invalida regresando a menu principal**";
						system("pause");
					}
					break;
			case '2': std::cout<<".:PILAS:.\n1. Agregar\n2. Mostrar\nOpcion: ";std::cin>>opc;
					if(opc=='1'){
						insertar_cola();
					}
					else if(opc=='2'){
						mostrar_cola();
					}
					else{
						std::cout<<"**Opcion invalida regresando a menu principal**";
						system("pause");
					}
					break;
			case '3': std::cout<<".:LISTAS:.\n1. Agregar\n2. Mostrar\nOpcion: ";std::cin>>opc;
					if(opc=='1'){
						insertar_lista();
					}
					else if(opc=='2'){
						mostrar_lista();
					}
					else{
						std::cout<<"**Opcion invalida regresando a menu principal**";
						system("pause");
					}
					break;
			case '4': std::cout<<".:ARBOLES:.\n1. Agregar\n2. Mostrar\nOpcion: ";std::cin>>opc;
					if(opc=='1'){
						agg_al_arbol();
					}
					else if(opc=='2'){
						mostrar_el_arbol();
					}
					else{
						std::cout<<"**Opcion invalida regresando a menu principal**";
						system("pause");
					}
					break;
			case '5': std::cout<<"\nPROGRAMA FINALIZADO\n\n";system("pause");break;
			default:std::cout<<"**OPCION INVALIDA**";break;
		}
		system("cls");
	}while(opc<'5');
}//-----------------------------------------fin del menu--------------------------------------

//-----------------------------------------------pilas----------------------------------------
void insertar_pilas(){
	int dato;
	char opc;
	do{
		std::cout<<"\nDigite un numero: ";std::cin>>dato;
		pila1.set_dato(dato);
		pila1.agg_nodo();
		
		std::cout<<"\n\nOtro(1.si/2.no): ";std::cin>>opc;
		system("cls");
	}while(opc!='2');
	
}
void mostrar_pila(){
	pila1.show();
	system("pause");
}
//-------------------------------------------------fin pilas-----------------------------------

//----------------------------------------------colas------------------------------------------
void insertar_cola(){
	int dato;
	char opc;
	do{
		std::cout<<"\nDigite un numero: ";std::cin>>dato;
		cola1.set_dato(dato);
		cola1.agg_nodo();
		
		std::cout<<"\n\nOtro(1.si/2.no): ";std::cin>>opc;
		system("cls");
	}while(opc!='2');
	
}

void mostrar_cola(){
	cola1.show();
	system("pause");
}//--------------------------------------------------fin colas---------------------------------

//-------------------------------------------------listas--------------------------------------
void insertar_lista(){
	char opc;
	int dato;
	do{
		std::cout<<"\nDigite un numero: ";std::cin>>dato;
		lista1.set_dato(dato);
		lista1.agg_nodo();
		std::cout<<"\nOtro(1.si|2.no): ";std::cin>>opc;
		system("cls");
	}while(opc!='2');
}

void mostrar_lista(){
	std::cout<<"\nLista: ";
	lista1.show();
	system("pause");
}//-----------------------------------------------fin listas----------------------------------

//------------------------------------------------arboles-------------------------------------
void agg_al_arbol(){//agrega un nodo al arbol
	char opc;
	int dato;
	do{
		std::cout<<"\nDigite un numero: ";std::cin>>dato;
		arbol1.set_dato(dato);
		arbol1.agg();
		std::cout<<"\nOtro(1.si|2.no): ";std::cin>>opc;
		system("cls");
	}while(opc!='2');
}

void mostrar_el_arbol(){//muestra el arbol
	arbol1.show();
	system("pause");
}