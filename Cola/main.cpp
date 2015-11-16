#include <iostream>

using namespace std;

struct nodo
{
    int nro;
    struct nodo *sgte;
};

class cola
{
public:
    nodo *delante;
    nodo *atras  ;
    cola(){
        delante = NULL;
         atras = NULL;
    }
    void encolar(int valor);
    void muestraCola();
};


void cola::encolar( int valor )
{
     struct nodo *aux = new(struct nodo);

     aux->nro = valor;
     aux->sgte = NULL;

     if( delante == NULL)
         delante = aux;
     else
         (atras)->sgte = aux;

     atras = aux;
}

int desencolar( struct cola &q )
{
     int num ;
     struct nodo *aux ;

     aux = q.delante;
     num = aux->nro;
     q.delante = (q.delante)->sgte;
     delete(aux);

     return num;
}

cola operator + (cola m, cola o) {
    nodo * aux;
    aux=m.delante;

    while( aux != NULL )
     {
            cout<<"   "<< aux->nro ;
            aux = aux->sgte;
     }
     aux=o.delante;
     while( aux != NULL )
     {
            cout<<"   "<< aux->nro ;
            aux = aux->sgte;
     }
}

void cola::muestraCola()
{
     struct nodo *aux;

     aux = delante;

     while( aux != NULL )
     {
            cout<<"   "<< aux->nro ;
            aux = aux->sgte;
     }
}


int main()
{
    cola cola1;
    cola cola2;
    cola1.encolar(2);
    cola1.encolar(3);
    cola1.encolar(4);

    cola2.encolar(6);
    cola2.encolar(7);
    cola2.encolar(8);

    cola cola3;
    cola3= cola1 + cola2;


    return 0;
}
