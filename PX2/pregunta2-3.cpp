#include <cstdlib>
#include <iostream>
#include <time.h>

struct nodo{int x;
             struct nodo *siguiente;};
typedef struct nodo *plista;
void insertar_inicio(plista &lista,int valor);
void mostrar(plista lista);
int brecursiva(plista lista,int valor,int n,int inicio);
void bnrecursiva(plista lista,int valor);
void busquedaBinaria(int n, plista lista,int valor);
int posicion(plista lista,int c);

using namespace std;

int main(int argc, char *argv[])
{ 
plista lista=NULL;
             int n,i,valor,op,elimina,aux,posicion;
do{cout<<endl;
             cout<<"***MENU***"<<endl;
cout<<"1--->1iniciar lista:"<<endl;
cout<<"2--->mostrar lista:"<<endl;
cout<<"3--->Busqueda recursiva"<<endl;
cout<<"4--->Busqueda no recursiva"<<endl;
cout<<"5--->busqueda binaria"<<endl;
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
case 3:{cout<<"Ingrese el elemento a buscar:";
        cin>>valor;
         if(brecursiva(lista,valor,n,0)==-1)
         cout<<"no se encontro el elemento"<<endl;
          mostrar(lista);
          break;}
case 4:{ cout<<"Ingrese el elemento a buscar:";
          cin>>valor;
         bnrecursiva(lista,valor);
         break;}
case 5:{ 
      cout<<"Ingrese el elemento a buscar:";
       cin>>valor;
        busquedaBinaria(n,lista,valor);
        mostrar(lista);
     break;}
           }
             }while(op!=6);
    system("PAUSE");
    return EXIT_SUCCESS;
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
                          
void bnrecursiva(plista lista,int valor){
plista indice;int k=1;
for(indice=lista;indice!=NULL;indice=indice->siguiente)
{if(valor==indice->x){
     cout<<"El valor buscado esta en la posicion :"<<k<<endl;                
     return ;        }
  k++;
}
cout<<"no se encontro el elemento"<<endl;
                             }

int posicion(plista lista,int c){
plista indice;int i=0;
for(indice=lista;i<c;indice=indice->siguiente)
{
i++;
}
return (indice->x);
                             }
                             
void busquedaBinaria(int n, plista lista,int valor){
int p=0,u=n-1,c;
while(p<=u){
c=(p+u)/2;
if(posicion(lista,c)==valor){
cout<<"El valor buscado esta en la posicion :"<<c+1<<endl;
return ;                   }             
if(posicion(lista,c)>valor)
p=c+1;
else
u=c-1;         
   }
cout<<"no se encontro el elemento"<<endl;
} 

int brecursiva(plista lista,int valor,int n,int inicio){
if (inicio>=n) 
return -1;
else if (posicion(lista,inicio)==valor) {
cout<<"Encontrado en posicion:"<<inicio+1<<endl;
return 1;}
else return  brecursiva(lista,valor,n,inicio+1);
return -1;
                                                         }
