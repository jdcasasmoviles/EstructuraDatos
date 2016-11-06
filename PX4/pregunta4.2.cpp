#include <cstdlib>
#include <iostream>
#include <math.h>

using namespace std;
struct nodol{int x;
              int ind;
             struct nodol *siguiente; };
typedef struct nodol *plista;
struct nodo{int valor;
            struct nodo*izq;
            struct nodo*der;
            };
typedef struct nodo*abb;
void insertar_inicio(plista &, int, int);
void mostrar(plista lista);
void sumar_listas(plista, plista, plista &);
void invertir(plista &);
void convertir_lista_arbol(plista, abb &, int);
void convertir_arbol_lista(plista &,abb,int);

void insertar_inicio(plista &lista,int valor, int idx){
     plista q;
     q=new (struct nodol);
     q->x=valor;
     q->ind=idx;
     q->siguiente=lista;
     lista=q;                
                           }
              
void mostrar(plista lista){
while(lista!=NULL){
cout<<lista->x<<"\t";
cout<<lista->ind<<endl;
lista=lista->siguiente;
                   }
cout<<endl;
                    } 

void insertar(abb &arbol,int x){
     if(arbol==NULL){
                     arbol=new (struct nodo);
                     arbol->valor=x;
                     arbol->izq=NULL;
                     arbol->der=NULL;
                     }
     else if(x<arbol->valor)insertar(arbol->izq,x);
     else if(x>arbol->valor)insertar(arbol->der,x);
     }
    
 void verarbol(abb arbol,int nro){
     int i;
     if(arbol==NULL)return;                                
     verarbol(arbol->der,nro+1);                   
     for(i=0;i<nro;i++)cout<<"   ";
     cout<<arbol->valor<<endl;
     verarbol(arbol->izq,nro+1);   
     }
                                  
void bnrecursiva(plista &indice, plista lista,int idx){
for(indice=lista;indice!=NULL;indice=indice->siguiente)
{
         if(idx==indice->ind){
     return;        }
}
           
        indice=NULL;   
        }

int m,n;int glob=0;
int main() {
             int x,i;
abb arbol1=NULL,arbol2=NULL;
srand(unsigned(time(NULL)));
cout<<"cantidad de elementos del arbol 1:";
cin>>m;
for(i=0;i<m;i++){
        insertar(arbol1,1+rand()%25);
        }
       
cout<<"cantidad de elementos del arbol 2:";
cin>>n;
for(i=0;i<n;i++){
        insertar(arbol2,1+rand()%25);
        }
cout<<"Arbol 1"<<endl;
verarbol(arbol1,0);
cout<<"Arbol 2"<<endl;
verarbol(arbol2,0);
    plista lista1, lista2,listaS;
    lista1=lista2=listaS=NULL;
    int idx=0;
convertir_arbol_lista(lista1, arbol1, idx); idx=0;
convertir_arbol_lista(lista2, arbol2, idx);
cout<<"Arbol 1"<<endl;
mostrar(lista1);   cout<<endl; 
cout<<endl<<"Arbol 2"<<endl;
mostrar(lista2);
sumar_listas(lista1,lista2,listaS);
cout<<"Arbol 3"<<endl;
mostrar(listaS);
system("pause");
    }

void convertir_arbol_lista(plista &lista, abb arbol, int idx) {
         if(arbol==NULL) return;
         abb arboltemp = arbol;
         insertar_inicio(lista, arboltemp->valor, idx);
         convertir_arbol_lista(lista, arboltemp->izq, idx*2+1);
         convertir_arbol_lista(lista, arboltemp->der, idx*2+2);
}


void sumar_listas(plista lista1,plista lista2, plista &listaS) {
     plista listatemp1 = lista1;
     plista listatemp2 = lista2;
     int valor1=0, valor2=0;
     int i=0;
     plista nodo1, nodo2;
     for(i=0; i<1000000; i++) {
              bnrecursiva(nodo1, listatemp1, i);
              bnrecursiva(nodo2, listatemp2, i);
              if(nodo1==NULL && nodo2==NULL) {
                                    continue;}
              else {
                   if(nodo1==NULL) {valor1=0;valor2=nodo2->x;} 
                   else if(nodo2==NULL) {valor2=0;valor1=nodo1->x;}
                   else {
                        valor1=nodo1->x;
                        valor2=nodo2->x;
                        }
                   insertar_inicio(listaS, valor1+valor2, i);
                   }
              
              }
     }




