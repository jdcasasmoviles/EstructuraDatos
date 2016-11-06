#include <stdlib.h>
#include <iostream>
#include <time.h>

struct nodo{int x;
             struct nodo *siguiente;};
typedef struct nodo *plista;
void insertar_inicio(plista &lista,int valor);
void mostrar(plista lista);
void invertir(plista &lista);
 void suma(plista lista);
void insertarposicion(plista &lista,int valor,int posicion);
 int eliminar(plista &lista,int valor);

using namespace std;

int main(){ plista lista=NULL;
             int n,i,valor,op,elimina,aux,posicion;
do{cout<<endl;
             cout<<"***MENU***"<<endl;
cout<<"1--->1iniciar lista:"<<endl;
cout<<"2--->mostrar lista:"<<endl;
cout<<"3--->inveritr lista"<<endl;
cout<<"4--->sumar elementos"<<endl;
cout<<"5--->mover"<<endl;
cout<<"6--->salir"<<endl;
cout<<"Ingrese la opcion"<<endl;
cin>>op;
switch(op){
case 1:{
     cout<<"Numero de datos:";
             cin>>n;
             srand(unsigned(time(NULL)));
             for(i=0;i<n;i++){
                              valor=rand()%100;
                              insertar_inicio(lista,valor);
                              }
                              break;
         }
case 2:{cout<<"Lista inicial:"<<endl;mostrar(lista);
        break;
       }
case 3:{invertir(lista);
         cout<<"Lista invertida"<<endl;
          mostrar(lista);
        break;}
case 4:{suma(lista);break;}
case 5:{
     cout<<"Ingrese el valor a mover:";
     cin>>valor;aux=valor;
     cout<<"Mover n posiciones:";
     cin>>n;
     elimina=eliminar(lista,valor);
     posicion=elimina+n;
     insertarposicion(lista,aux,posicion);
      mostrar(lista);
     break;}
           }
             }while(op!=6);

    system("PAUSE");
    return 0;
}
void insertar_inicio(plista &lista,int valor){
     plista q;
     q=new (struct nodo);
     q->x=valor;
     q->siguiente=lista;
     lista=q;                
                           }
              
void mostrar(plista lista){
while(lista!=NULL){
cout<<lista->x<<endl;
lista=lista->siguiente;
                   }
cout<<endl;
                    } 
                    
 void suma(plista lista){int s=0;
while(lista!=NULL){
s=s+(lista->x);
lista=lista->siguiente;
                   }
cout<<"La suma de elementos de la lista es:"<<s<<endl;
cout<<endl;
                    }   
                    
void invertir(plista &lista){
plista a,b,t;
if(lista==NULL)return;
a=lista;
b=lista->siguiente;
lista->siguiente=NULL;
while(b!=NULL){
t=b->siguiente;
b->siguiente=a;
a=b;
b=t;
               }
lista=a;
                        }
                        
void insertarposicion(plista &lista,int valor,int posicion){
plista r,t;int i;
r=new(struct nodo);
r->x=valor;
if(posicion==1){r->siguiente=lista;lista=r;}
 else{t=lista;
 for(i=1;t!=NULL;i++)
 { if(i==posicion-1){r->siguiente=t->siguiente;
                    t->siguiente=r;
                     return;}
            t=t->siguiente;                    
                      }
      }             
 cout<<"Error posicion equivocada"<<endl;    
                       }
                       
 int eliminar(plista &lista,int valor){
 plista p,ant;int eli=0;
 p=lista;
 while(p!=NULL){eli++;
 if(p->x==valor){
                 if(p==lista)
                 lista=lista->siguiente;
                 else
                  ant->siguiente=p->siguiente;
                  delete(p);
                  return eli;
                 }
 ant=p;
 p=p->siguiente;
                }
      }
