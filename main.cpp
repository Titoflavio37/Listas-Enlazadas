#include <iostream>
#include <string>
using namespace std;

struct nodo{
	int dato;
	struct nodo * siguiente;
};

typedef struct nodo * TLista;

void addNodo(TLista & lista, int dato){
	TLista nuevo;
	nuevo = new (struct nodo);
	nuevo->dato = dato;
	nuevo->siguiente = NULL;
	if(lista == NULL){
		lista = nuevo;	
	}
	else{
		struct nodo * valor1 , *valor2 = NULL;
		valor1 = lista;
		while(valor1->siguiente != NULL && nuevo->dato > valor1->dato){
			valor2 = valor1;
			valor1 = valor1->siguiente;
		}
		if(nuevo->dato <= valor1->dato){
			if(valor1 == lista){
				nuevo->siguiente = valor1;
				lista = nuevo;
			}
			else{
				nuevo->siguiente = valor1;
				valor2->siguiente = nuevo;
			}
		}
		else{
			valor1->siguiente = nuevo;
		}

	}
}

void listarNodo(TLista lista){
	int i = 0;
	
	while(lista != NULL){
		cout << "[" << lista->dato << "]->";
		lista = lista->siguiente;
		i++;
	}
	cout << "NULL" << endl;
	cout << "El tamano de la lista es " << i << endl;
}



int main(){

	TLista lista = NULL;

	addNodo(lista,5);
	addNodo(lista,2);
	addNodo(lista,3);
	addNodo(lista,4);
	addNodo(lista,6);
	addNodo(lista,1);
	listarNodo(lista);

	return 0;
}

