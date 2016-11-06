#include <stdlib.h>
#include <iostream>
#include <time.h>

struct nodo{int x;
             struct nodo *siguiente;
             struct nodo *anterior;};
typedef struct nodo *plista;
void insertar_inicio(plista &lista,int valor);
void mostrar(plista lista);
void burbuja(plista lista);
using namespace std;

int main(){ plista lista=NULL;
             int n,i,valor;
             cout<<"Numero de datos:";
             cin>>n;
             srand(unsigned(time(NULL)));
             for(i=0;i<n;i++){
                              valor=rand()%100;
                              insertar_inicio(lista,valor);
                              }
cout<<"Lista inicial:"<<endl;mostrar(lista);
burbuja(lista);
cout<<"Lista ordenada"<<endl;
mostrar(lista);
    system("PAUSE");
    return 0;
}
void insertar_inicio(plista &lista,int valor){
     plista q;
     q=new (struct nodo);
     q->x=valor;
     q->siguiente=lista;
     q->anterior=NULL;
     if(lista!=NULL)
          lista->anterior=q;
     lista=q;                
                           }
              
void mostrar(plista lista){
while(lista!=NULL){
cout<<lista->x<<endl;
lista=lista->siguiente;
                   }
cout<<endl;
                    }   
                    
void burbuja(plista lista){
plista actual,sgte,marca;
int i;marca=NULL;
while(marca!=lista->siguiente){
   actual=lista;
   sgte=actual->siguiente;
      while(sgte!=marca){
       if(actual->x > sgte->x)
         {i=sgte->x;
           sgte->x=actual->x;
           actual->x=i;
          }
   actual=actual->siguiente;
   sgte=actual->siguiente; 
                         }
marca=actual;
                             }
                          }        
                           
