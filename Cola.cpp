//COLA CON DOS STRUCT 'NODO' Y 'COLA'

#include <iostream>


struct nodo{
	int dato;
	nodo *siguiente;
};

struct cola{
	nodo *frente;
	nodo *fin;
};

void iniciar(cola &c);
bool esvacia(cola c);
void encolar(cola &c, int dato);
void desencolar(cola &c);
void mostrar(cola &c);

void iniciar(cola &c){
	c.frente = NULL;
	c.fin = NULL;
	std::cout<<"---Se creo exitosamente la cola---"<<std::endl;
}

bool esvacia(cola c){
	return c.frente==NULL;
}

void encolar(cola &c, int dato){
	
	nodo *nuevo_nodo = new nodo();
	nuevo_nodo->dato = dato;
	nuevo_nodo->siguiente = NULL;
	
	if (esvacia(c)){
		c.frente = nuevo_nodo;
	}
	else{
		c.fin->siguiente = nuevo_nodo;
	}
	
	c.fin = nuevo_nodo;	//YA CUMPLA LA UNA O LA OTRA, EL NUEVO NODO SIEMPRE TIENE QUE SER APUNTADO POR FIN
	std::cout<<"Se creo un nuevo espacio que almacena: "<<nuevo_nodo->dato<<std::endl;

}

void desencolar(cola &c){
	if(esvacia(c)){
		std::cout<<"ERROR(COLA VACIA): No es posible desencolar.";
		return;
	}
	
	nodo *aux = c.frente;
	
	std::cout<<"Se desencolo: "<<aux->dato<<std::endl;
	
	c.frente = c.frente->siguiente;
	delete aux;
	
	if (c.frente == NULL ){
		c.fin = NULL;
	}
	
}


void mostrar(cola &c){
	if(esvacia(c)){
		std::cout<<"No se muestra nada. Esta vacio";
		return;
	}
	nodo *aux = c.frente;
	std::cout<<"se desencola y se muestra: ";
	while (aux != NULL){
		std::cout<<aux->dato<<", ";
		aux = aux->siguiente;
	}
	std::cout<<"NULL"<<std::endl;
}


int main(){
	
	cola c;
	int n;
	
	//Luego le haré un menu con 'switch'
	std::cout<<"Ingresa un numero para usarlo de dato: "; std::cin>>n;
	iniciar(c);
	encolar(c,n);
	desencolar(c);
	std::cout<<"Ingresa un numero para usarlo de dato: "; std::cin>>n;
	encolar(c,n);
	std::cout<<"Ingresa un numero para usarlo de dato: "; std::cin>>n;
	encolar(c,n);
	mostrar(c);
	
	return 0;
}
