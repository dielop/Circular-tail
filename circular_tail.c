#include <stdio.h>
#include <stdlib.h>

#define MAX 7
#define FALSE 0
#define TRUE 1


typedef struct {

       int inicio;
       int final; 
       int CIRCULO[MAX];

}ccircular;

void Start(ccircular *);//Indica los inicios
int IsEmpty(ccircular *);//Corrobora si hay lugar vacio
int IsFull(ccircular *);//Indica si la cola esta llena
int Tamanio(ccircular *);//Indica el tamanio de la cola
void Add(ccircular *, int);//Agrega elementos a la cola
void Delete(ccircular *);//Elimina elementos de la cola


int main (){

    ccircular cola;

    Start(&cola);
    Add(&cola, 11);
    Add(&cola, 12);
    Add(&cola, 13);
    Add(&cola, 14);
    Add(&cola, 15);
    Add(&cola, 16);
    Add(&cola, 17);
    //Imprimo el tamanio de la cola
    printf("\nEl tamanio de la cola es: %d\n", Tamanio(&cola));

    //Elimino dos elementos
    Delete(&cola);
    Delete(&cola);
    //Imprimo el tamanio de la cola
    printf("\nEl tamanio de la cola es: %d\n", Tamanio(&cola));
    //Agrego dos elementos donde habia eliminado los anteriores
    Add(&cola, 100);
    Add(&cola, 200);
    printf("\nEl elemento inicial: %d y el final: %d", cola.CIRCULO[cola.inicio], cola.CIRCULO[cola.final]);

    //Intento agregar otro elemento pero la cola esta llena entonces me lo va a indicar
    Add(&cola, 300);

    //Imprimo el tamanio de la cola
    printf("\nEl tamanio de la cola es: %d\n", Tamanio(&cola));


    return 0;
}

void Start(ccircular *cola){
    cola->inicio = -1;
    cola->final = -1;
}

void Add(ccircular *cola, int element){
    if(!IsFull(cola)){
        if(IsEmpty(cola)){
           cola->inicio = 0;
        }
        if(cola->final == MAX - 1){
            cola->final = 0;
        }else{
             cola->final++;
        }
     cola->CIRCULO[cola->final] = element;
     printf("Inicio actual: %d\n", cola->inicio);
     printf("Agrego: %d en el final %d\n", cola->CIRCULO[cola->final], cola->final);
    }else{
        printf("\nLa cola esta llena\n");
    }
}

void Delete(ccircular *cola){
    if(!IsEmpty(cola)){
        int temp = cola->CIRCULO[cola->inicio];
        if(Tamanio(cola) == 1){
          Start(cola); 
        }else{
            cola->inicio++;
        }
        printf("Borra: %d\n", temp);
        printf("Inicia nuevamente en %d con valor %d y final es %d\n", cola->inicio,cola->CIRCULO[cola->inicio], cola->final);
    }else{
        printf("La cola esta vacia\n");
    }
}


int IsEmpty(ccircular *cola){
    if(cola->final == -1){
        return TRUE;
    }

    return FALSE;
}

int IsFull(ccircular *cola){
    if(Tamanio(cola) == MAX){
        
        return TRUE;
    }
    
    return FALSE;
}

int Tamanio(ccircular *cola){
    if(IsEmpty(cola)){
        return 0;
    }else{
        if(cola->inicio <= cola->final){
            return cola->final - cola->inicio + 1;
        }else{
            return MAX - cola->inicio + cola->final + 1;
        }
    }
}
