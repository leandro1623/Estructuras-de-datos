
struct Nodo{//-------------------------estructura nodo---------------------------------------
	int dato;
	Nodo *siguiente=NULL;
	Nodo *izq,*der,*padre;
};

//-----------------------------------------clases--------------------------------------------

//---------------------------------------pilas------------------------------------------------
class Pila{
	private:
		int dato;
		Nodo *pila;
		//funciones
		void sacar_pila();
	public:
		Pila(){//constructor
			dato=0;
			pila=NULL;
		}
		
		//set and get
		void set_dato(int);//set
		int get_dato();//get
		
		//atributes
		void agg_nodo();
		void show();
};//---------------------------------------fin pilas------------------------------------------

//----------------------------------------colas-----------------------------------------------
class Cola{
	private:
		int dato;
		Nodo *frente,*fin;
		//funciones
		void sacar_nodo();
	public:
	//constructor
		Cola();
	//set and get
		void set_dato(int);
		int get_dato();
		
	//atributes
		void agg_nodo();
		void show();
	
};//---------------------------------------fin colas------------------------------------------

//---------------------------------------listas-----------------------------------------------
class Lista{
	private:
		int dato;
		Nodo *lista=NULL;
	public:
		Lista();//constructor
		//set and get
		void set_dato(int dato1);//set
		int get_dato();//get
		//atributes
		
		//agrega un nodo a la lista
		void agg_nodo();
		//muestra la lista
		void show();
		
};//---------------------------------------------fin lista------------------------------------

//--------------------------------------------arboles-----------------------------------------
class Arbol{
	private:
		
		int dato;
		Nodo *arbol;
		
		//funciones
		Nodo *crear_nodo_en_heap(int dato,Nodo *padre){//crea un nodo en la memoria dinamica
			Nodo *nuevo_nodo=new Nodo();
			nuevo_nodo->dato=dato;
			nuevo_nodo->izq=NULL;
			nuevo_nodo->der=NULL;
			nuevo_nodo->padre=padre;
			return nuevo_nodo;
		}//fin memoria dinamica
		void agg_nodo(Nodo *&arbol,int dato,Nodo *padre);//agrega un nodo al arbol
		void show_arbol(Nodo *arbol,int cont);//muerta el arbol
		
	public:
	 
	Arbol();//constructor
	//set and get
	void set_dato(int dato1);//set
	int get_dato();//get
	//atributes
	void agg();//agrega un nodo al arbol //funcion pra ser llamada	
	void show();//muestra el arbol //funcion para ser llamada
};//-----------------------------------fin arboles--------------------------------------------