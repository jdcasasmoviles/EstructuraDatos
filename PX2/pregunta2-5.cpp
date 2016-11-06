#include <stdlib.h>
#include <iostream>
#include <time.h>

struct nodo{int x;
             struct nodo *siguiente;};
typedef struct nodo *plista;
void insertar_inicio(plista &lista,int valor);
void mostrar(plista lista);
void invertir(plista &lista);
void suma(plista p1,plista p2,plista &p3);
int posicion(plista lista,int c);

using namespace std;

int main(){ plista l1,l2,l3,ls,lp;
             l1=l2=l3=ls=lp=NULL;
             int m,n,i,j,a,b,valor,acarreo,digito;
    cout<<"Numero de cifras1  :";
             cin>>m;
             srand(unsigned(time(NULL)));
             for(i=0;i<m;i++){ 
                              valor=rand()%10;
                              cout<<valor;
                              insertar_inicio(l1,valor);
                              }cout<<endl;cout<<endl;
      cout<<"Numero de cifras2  :";
             cin>>n;
             srand(unsigned(time(NULL)));
             for(i=0;i<n;i++){
                              valor=rand()%10;
                              cout<<valor;
                              insertar_inicio(l2,valor);
                              }cout<<endl;cout<<endl;

      insertar_inicio(ls,0);
for(a=0;a<m;a++){if(a!=0){l3=NULL;
                          for(j=0;j<a;j++){
                                            insertar_inicio(l3,0);
                                           }
                          }
                 acarreo=0;
                 for(b=0;b<n;b++){
                                  digito=posicion(l1,a)*posicion(l2,b)+acarreo;
                                  insertar_inicio(l3,digito%10);
                                  acarreo=digito/10;
                                  }
                 if(acarreo!=0){insertar_inicio(l3,acarreo);}
                 invertir(l3);
                 suma(ls,l3,lp);ls=NULL;
                 ls=lp;lp=NULL;
                 invertir(ls); 
                 }
cout<<"El producto de los numeros:"<<endl;
invertir(ls);mostrar(ls);
cout<<endl;
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
cout<<lista->x;
lista=lista->siguiente;
                   }
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
                        
void suma(plista p1,plista p2,plista &p3){
  int n,d1,d2,acarreo=0;
  while(p1!=NULL||p2!=NULL){
  if(p1==NULL)d1=0;
  else d1=p1->x;
  if(p2==NULL)d2=0;
  else d2=p2->x;
  n=d1+d2+acarreo;
  insertar_inicio(p3,n%10);
  acarreo=n/10;
  if(p1!=NULL)p1=p1->siguiente;
  if(p2!=NULL)p2=p2->siguiente;
                            }   
  if(acarreo!=0) insertar_inicio(p3,acarreo);
                                          }
                                          
  int posicion(plista lista,int c){
plista indice;int i=0;
for(indice=lista;i<c;indice=indice->siguiente)
{
i++;
}
return (indice->x);
                             }
                        
                       
