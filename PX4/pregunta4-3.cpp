#include <cstdlib>
#include <iostream>
#include<string.h>
#include <time.h>
struct nodop{int xp;
            struct nodop*sgte;          
           };
typedef struct nodop *ppila;
struct nodoa{int valor;
            struct nodoa*izq;
            struct nodoa*der;
            };
typedef struct nodoa*abb;

struct nodo{abb x;
            struct nodo *siguiente;
            struct nodo *anterior;
            };
typedef struct nodo *plista;

void insertar(abb &arbol,int x);
void verarbol(abb arbol,int nro);
void insertar_lista(plista &lista,abb valor);
void mostrar(plista lista);
void elimina_clave(plista &lista,int clave);
void eliminar(abb &arbol,int clave);
void arboles_similares(plista &lista);
void enorden(abb p,int k,ppila &p);
void push(ppila &p,int valor2);
int iguales(ppila p1,ppila p2);
void imprimir(ppila p);
using namespace std;

main()
{ 
 plista lista=NULL;int op,n,i,j,k=0;
/*INICIALIZANDO LA LISTA*/
 cout<<"Numero de arboles:";cin>>n;
 srand(unsigned(time(NULL)));
 for(i=0;i<n;i++){abb  q=NULL;
                  for(j=0;j<1+rand()%17;j++){
                     insertar(q,1+rand()%25);
                                            }
                  insertar_lista(lista,q);
                 }
 mostrar(lista);
                              
  do{cout<<endl<<endl<<"***MENU***"<<endl;
  cout<<"1--->Eliminar elemento"<<endl;
  cout<<"2--->Mostrar"<<endl;
  cout<<"3--->Insertar una nuevo arbol"<<endl;
  cout<<"4--->Arboles similares"<<endl;
  cout<<"5--->Salir"<<endl;
  cout<<endl<<"Ingrese la opcion:";cin>>op;
  switch(op){
  case 1:{cout<<endl<<"Ingrese numero:";
         cin>>n;
         elimina_clave(lista,n);
         mostrar(lista);
         break;}
   case 2:{
           cout<<endl<<"Lista de Arboles";
           mostrar(lista);
           break;
           }
   case 3:{abb  q;
           for(j=0;j<1+rand()%17;j++){
                                      insertar(q,rand()%14);
                                      }
           insertar_lista(lista,q);
           mostrar(lista);
           break;
           }
   case 4:{ arboles_similares(lista);
           break;
           }
           }
   }while(op!=5);
    system("PAUSE");
    return EXIT_SUCCESS;
}
                             
void insertar_lista(plista &lista,abb arbol){
     plista q;
     q=new (struct nodo);
     q->x=arbol;
     q->siguiente=lista;
     if(lista!=NULL)
          lista->anterior=q;
     lista=q;              
                                              }
     
void mostrar(plista lista){ int i=1;
while(lista!=NULL){
                   cout<<"ARBOL"<<i++<<":"<<endl<<endl;
                   verarbol(lista->x,0);
                   cout<<endl;
                   lista=lista->siguiente;
                   }
cout<<endl;
                          } 

void insertar(abb &arbol,int dato){
if(arbol==NULL){
                arbol=new (struct nodoa);
                arbol->valor=dato;
                arbol->izq=NULL;
                arbol->der=NULL;
                }
else if(dato<arbol->valor)insertar(arbol->izq,dato);
else if(dato>arbol->valor)insertar(arbol->der,dato);
                                   }
    
 void verarbol(abb arbol,int nro){
 int i;
 if(arbol==NULL)return;                                
 verarbol(arbol->der,nro+1);                   
 for(i=0;i<nro;i++)cout<<"   ";
 cout<<arbol->valor<<endl;
 verarbol(arbol->izq,nro+1);   
                                }
                                
 void elimina_clave(plista &lista,int clave){
 plista ind;
 for(ind=lista;ind!=NULL;ind=ind->siguiente){
                      eliminar(ind->x,clave);
                                            }
                                            }
                                            
void eliminar(abb &arbol,int clave){
     abb p1,p2;
     if(arbol==NULL)return;
     if(clave<arbol->valor)eliminar(arbol->izq,clave);
     else if(clave>arbol->valor)eliminar(arbol->der,clave);
     else if(arbol->izq==arbol->der){
                                    delete arbol;
                                    arbol=NULL;
                                    }
     else if(arbol->izq==NULL){p1=arbol;
                              arbol=arbol->der;
                              delete p1;
                              }
     else if(arbol->der==NULL){p1=arbol;
                              arbol=arbol->izq;
                              delete p1;
                              }
     else{
           p1=arbol->der;
           p2=arbol->der;
           while(p2->izq)
           p2=p2->izq;
           p2->izq=arbol->izq;
           delete(arbol);
           arbol=p1;
          }
     }
     
void arboles_similares(plista &lista){
plista ind,ind1,ind2;
int i=1,j;
ppila p1,p2;
for(ind=lista;ind!=NULL;ind=ind->siguiente){
ppila p3=NULL;
enorden(ind->x,0,p3);
imprimir(p3);
                                            }
cout<<"\t\tArboles similares "<<endl;
for(ind1=lista,i=1;ind1!=NULL;ind1=ind1->siguiente,i++){p1=NULL;int s=0;
                                                       enorden(ind1->x,0,p1);
                                                       cout<<endl<<"Arbol "<<i<<" : ";
    for(ind2=lista,j=1;ind2!=NULL;ind2=ind2->siguiente,j++){
                                                      p2=NULL;
                                                      enorden(ind2->x,0,p2);
                                                      if(iguales(p1,p2)&& i!=j){
                                                                          s++;
                                                                   cout<<j<<" ";
                                                                               }
                                                           }
cout<<"\n\t\tTotal : "<<s;
                                                       }
}
                                                 
void enorden(abb p,int k,ppila &pl)
{ abb Ai,Ad;
  if(p!= NULL )
  { Ai=p->izq;
    Ad=p->der;
    enorden(Ai,k,pl);
    k++;push(pl,k);
    enorden(Ad,k,pl);
  }
}

void push(ppila &p,int valor2){
ppila q=new (struct nodop);
q->xp=valor2;
q->sgte=p;
p=q; 
                              }
                          
int iguales(ppila p1,ppila p2){
int i=0,j=0,ok=0;
ppila aux1=p1,aux2=p2;
while(aux1!=NULL){i++;aux1=aux1->sgte;}
while(aux2!=NULL){j++;aux2=aux2->sgte;}
if(i!=j)return 0;
else{
       while(p1!=NULL){
                       if(p1->xp == p2->xp)ok=1;
                       else {ok=0;break;}
                       p1=p1->sgte;
                       p2=p2->sgte;
                      }  
      }       
return ok;       
}
    
 void imprimir(ppila p){
 while(p!=NULL){
 cout<<p->xp;
 p=p->sgte;
                }
 cout<<endl;
                      }
     
                           

