#include <stdio.h>
#include <stdlib.h>
#include<wchar.h>
#include<locale.h>
#include<time.h>
#include<unistd.h>
#include<string.h>
#include<conio.h>

struct Lista{
    int valor;

    struct Lista *sig;
};

struct Lista *Inicio = NULL;
struct Lista *Final = NULL;

int Vacia(){
    if(Inicio == NULL){
        return 1;
    }else{
        return 0;
    }
}

void agregarCola(int x){
    struct Lista *nuevo;

    nuevo = malloc(sizeof(struct Lista));
    nuevo->valor = x;
    nuevo->sig = NULL;

    if(Vacia()){
        Inicio = nuevo;
        Final = nuevo;
    }else{
        Final->sig = nuevo;
        Final = nuevo;
    }
}

void imprimirCola(){
    struct Lista *actual = Inicio;

    while(actual!=NULL){
        printf(" %d ->",actual->valor);

        actual = actual->sig;
    }
    printf("\n___________________________\n");
}

void invertirCola(){
    struct Lista *anterior = NULL;
    struct Lista *actual = Inicio;
    struct Lista *siguiente = NULL;

        while(actual!=NULL && !Vacia()){
            siguiente = actual->sig;
            actual->sig = anterior;
            anterior = actual;
            actual = siguiente;
        }

    Inicio = anterior;
}

int cantidadElementos(){
    struct Lista *actual = Inicio;

    int c = 0;

    if(Vacia()){
        return 1;
    }else{
        while(actual!=NULL){
            c = c + 1;

            actual = actual->sig;
        }
        return c;
    }
}

void insertarCola(int pos, int x){
    if(pos<=cantidadElementos()+1){
        struct Lista *nuevo;

        nuevo = malloc(sizeof(struct Lista));
        nuevo->valor = x;

        if(pos==1){ //Quiero ingresar un nodo en la primera posición
            nuevo->sig = Inicio;
            Inicio = nuevo;
        }else if(pos==cantidadElementos()+1){ //Quiero ingresar un nodo en la última posición
            struct  Lista *actual = Inicio;

            while(actual!=NULL){
                actual = actual->sig;
            }
            actual->sig = nuevo;
            nuevo->sig = NULL;
        }else{ //Quiero ingresarlo en cualquier lugar
            struct Lista *actual = Inicio;

            for(int f=1; f<=pos-2;f++){
                actual = actual->sig;
            }
            struct Lista *siguiente = actual->sig;
            actual->sig = nuevo;
            nuevo->sig = siguiente;
        }
    }

}

void borrarElemento(int pos){
    if(pos<=cantidadElementos()){
        struct Lista *borrar;

        if(pos==1){
            borrar = Inicio;
            Inicio = Inicio->sig;
        }else{
            struct Lista *actual = Inicio;

            for(int f=1;f<=pos-2;f++){
                actual = actual->sig;
            }
            struct Lista *prox = actual->sig;
            actual->sig = prox->sig;
            borrar = prox;

        }
        free(borrar);
    }
}

void intercambiarElementos(int x, int y){
    if(x<=cantidadElementos()&&y<=cantidadElementos()){
        struct Lista *pos1 = Inicio;
        for (int f=1;f<x;f++){
            pos1 = pos1->sig;
        }
        struct Lista *pos2 = Inicio;
        for (int f=1;f<y;f++){
            pos2 = pos2->sig;
        }

        int aux = pos1->valor;
        pos1->valor = pos2->valor;
        pos2->valor = aux;
    }
}

int mayor(){

    int mayor;

    if(!Vacia()){
        int posicion = 1;
        mayor = Inicio->valor;

        struct Lista *actual = Inicio;
        while(actual!=NULL){
            if(actual->valor>mayor){
                mayor = actual->valor;

                posicion ++;
            }
            actual = actual->sig;
        }
        return mayor;
    }else{
        return -1;
    }
}

int posicion(){

    int mayor;

    if(!Vacia()){
        int posicion = 1;
        mayor = Inicio;

        struct Lista *actual = Inicio;
        while(actual!=NULL){
            if(actual->valor>mayor){
                mayor = actual->valor;

                posicion ++;
            }
            actual = actual->sig;
        }
        return posicion;
    }else{
        return -1;
    }
}

int ordenada(){
    if(cantidadElementos()>1){
        struct Lista *tortuga = Inicio; //Tortuga empieza en el inicio
        struct Lista *liebre = Inicio->sig; //Liebre siempre va uno adelante que tortuga
        while(liebre!=NULL){
            if(liebre->valor < tortuga->valor){
                printf("¡La lista no está ordenada!");
                return 0;
            }
            liebre = liebre->sig;
            tortuga = tortuga->sig;
        }
        printf("¡La lista está ordenada!");
    }
}

int main()
{
    setlocale(LC_ALL, "");
    srand(time(NULL));

    int num,pos,pos1,pos2,pos4;

    agregarCola(1);
    agregarCola(5);
    agregarCola(10);
    agregarCola(50);
    printf("\nCola original: \n");
    imprimirCola();
    printf("¿La lista está ordenada (menor a mayor)?\n");
    imprimirCola();
    ordenada();
    printf("\n___________________________\n");
    printf("¿Y si invertimos la cola?\n");
    printf("\nCola invertida: \n");
    invertirCola();
    imprimirCola();
    printf("¿Cuantos elementos tiene la cola?\n");
    printf("\nCantidad de elementos: %d\n",cantidadElementos());
    printf("___________________________\n");
    num = 22, pos4 = 2;
    printf("¿Y si agregamos un %d la cola en la posición %d?\n",num,pos4);
    insertarCola(pos4,num);
    printf("\nNuevo elemento insertado: \n");
    imprimirCola();
    pos = 2;
    printf("¿Y si eliminamos el nodo %d?\n",pos);
    borrarElemento(pos);
    printf("\nNueva Cola: \n");
    imprimirCola();
    pos1 = 3, pos2 = 4;
    printf("¿Y si intercambiamos el nodo %d con el nodo %d?\n",pos1,pos2);
    intercambiarElementos(pos1,pos2);
    printf("\nNueva Cola: \n");
    imprimirCola();
    printf("¿Cual es el mayor de la cola?\n\n");
    printf("El mayor de la cola es: %d\n",mayor());
    printf("Se encuentra en la posición: %d\n",posicion());
    printf("___________________________\n");
    printf("¿La lista está ordenada (menor a mayor)?\n");
    imprimirCola();
    ordenada();
    printf("\n___________________________\n");
    return 0;
}
