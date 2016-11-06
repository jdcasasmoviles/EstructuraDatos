#include <cstdlib>
#include <iostream>
#include <time.h>
struct nodoc{int nro;
            struct nodoc *sgte;
            };
            
struct cola{struct nodoc *delante;
            struct nodoc* atras;     
           };
typedef struct cola kola;

struct nodo{kola x;
            struct nodo *siguiente;};
typedef struct nodo *plista;

void desen_i_cola(plista lista,int c);
void en_i_cola(plista lista,int c);
void elim_i_cola(plista lista,int c);
void insertar_inicio(plista &lista,kola valor);
void mostrar(plista lista);
void eliminar(plista &lista,kola valor);
void inicializar(kola &q);
void encola(kola &q,int n);
int desencolar(kola &q);
void vercola(kola q);
void vaciarcola(kola &q);

using namespace std;

main()
{ 
 plista lista=NULL;int op,n,i,j,k;
 /*INICIALIZANDO LA LISTA*/
 cout<<"Numero de colas :";cin>>n;
 srand(unsigned(time(NULL)));
 for(i=0;i<n;i++){kola  q;
                  inicializar(q);
                  for(j=0;j<1+rand()%7;j++){
                  encola(q,rand()%14);
                                          }
                  insertar_inicio(lista,q);
                  }
 mostrar(lista);
                              
    do{cout<<endl<<"***MENU***"<<endl;
  cout<<"1--->Encolar eligiendo la i-esima cola"<<endl;
  cout<<"2--->Desencolar eligiendo la i-esima cola"<<endl;
  cout<<"3--->Insertar una nueva cola"<<endl;
  cout<<"4--->Eliminar una cola"<<endl;
  cout<<"5--->Salir"<<endl;
  cout<<endl<<"Ingrese la opcion:";cin>>op;
  
  switch(op){
  case 1:{cout<<endl<<"i-esima cola:";
         cin>>n;
         en_i_cola(lista,n);
          mostrar(lista);
         break;}
   case 2:{
          cout<<endl<<"i-esima cola:";
           cin>>n;
           desen_i_cola(lista,n);
            mostrar(lista);
           break;
         }
   case 3:{kola  q;
           inicializar(q);
           for(j=0;j<1+rand()%7;j++){
           encola(q,rand()%14);     }
            insertar_inicio(lista,q);
             mostrar(lista);
           break;
           }
   case 4:{ cout<<endl<<"i-esima cola:";
           cin>>n;
           elim_i_cola(lista,n);
            mostrar(lista);
           break;
           }
           }
   }while(op!=5);
    system("PAUSE");
    return EXIT_SUCCESS;
}

void desen_i_cola(plista lista,int c){
plista indice;int i=0,m;
for(indice=lista;i<c;indice=indice->siguiente)
{i++;}
if((indice->x).delante!=NULL){
m=desencolar(indice->x);
cout<<endl<<"Desencolado elemento :"<<m<<endl;
                             }
else cout<<endl<<"No hay elementos en cola"<<endl;
                                       }
                             
void en_i_cola(plista lista,int c){
plista indice;int i=0,valor;
for(indice=lista;i<c;indice=indice->siguiente)
{i++;}
cout<<"Encolar elemento:";cin>>valor;
encola(indice->x,valor);
                                   }
                                   
void elim_i_cola(plista lista,int c){
plista indice;int i=0,valor;
for(indice=lista;i<c;indice=indice->siguiente)
{i++;}
eliminar(lista,indice->x);
                                   }
                             
void insertar_inicio(plista &lista,kola valor){
     plista q;
     q=new (struct nodo);
     q->x=valor;
     q->siguiente=lista;
     lista=q;                
                           }
     
void mostrar(plista lista){
while(lista!=NULL){
vercola(lista->x);
cout<<endl;
lista=lista->siguiente;
                   }
cout<<endl;
                    } 

 void eliminar(plista &lista,kola valor){
 plista p,ant;
 p=lista;
 while(p!=NULL){
 if(&(p->x)==&valor){
                 if(p==lista)
                 lista=lista->siguiente;
                 else
                  ant->siguiente=p->siguiente;
                  delete(p);
                  return ;
                 }
 ant=p;
 p=p->siguiente;
                }
      }
 


void inicializar(kola &q){
q.delante=NULL;
q.atras=NULL;
                                }

void encola(kola &q,int n){
struct nodoc *p;
p=new(struct nodoc);
p->nro=n;
p->sgte=NULL;
if(q.delante==NULL)q.delante=p;
else (q.atras)->sgte=p;
q.atras=p;
                                }
                                
int desencolar(kola &q){
struct nodoc *p;
p=q.delante;
int dato=p->nro;
q.delante=(q.delante)->sgte;
delete(p);
return dato;
                              }


               
void vercola(kola q){
struct nodoc *p;
p=q.delante;
while(p!=NULL){
cout<<p->nro<<"->";
p=p->sgte;
               }
cout<<endl;
                          }
                          
void vaciarcola(kola &q){
struct nodoc *p,*r;
p=q.delante;
while(p!=NULL){
r=p;
p=p->sgte;
delete(r);
             } 
q.delante=NULL;
q.atras=NULL;
                                }
                               

