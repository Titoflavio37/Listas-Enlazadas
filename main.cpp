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

void deletePrimero(TLista &lista){
	lista = lista->siguiente;  //Elimina el primer elemento
}

void deleteUltimo(TLista &lista){
	struct nodo * anterior,*actual;
	anterior = lista;
	actual = lista;
	
	while(actual->siguiente != NULL){
		anterior = actual;
		actual = actual->siguiente;
	}
	anterior->siguiente = NULL;
}

void deletePosicionNodo(TLista & lista, int p){
	struct nodo * anterior,*actual;
	anterior = lista;
	actual = lista;
	int dato =0;
	if(p>0){
		while(dato != p && actual->siguiente != NULL){
			anterior = actual;
			actual = actual->siguiente;
			dato++;
		}
		anterior->siguiente = actual->siguiente;
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


nodo * buscar(TLista &lista, int n){
	struct nodo *p;
	p = lista;
	if(p == NULL){
		cout << "LA lista no tiene datos" << endl;
	}
	else{
		while(p->siguiente != NULL || p->siguiente == NULL){
			if(p->dato == n){
				return p;
			}
			else if(p->siguiente == NULL){
				return NULL;		
			}
			p = p->siguiente;	
		}
	}
	return NULL;
}

void sustituir(TLista & lista, int orig,int nuevo){
	struct nodo * pos;
	pos = buscar(lista,orig);
	if(pos != NULL || pos == NULL){
		pos->dato = nuevo;
	}
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

	//deletePosicionNodo(lista,2);

	listarNodo(lista);
	
	if(buscar(lista,586) == NULL) cout << "El dato no existe" << endl;
	else cout << "El dato existe" << endl;

	sustituir(lista,3,7);
	listarNodo(lista);


	return 0;
}