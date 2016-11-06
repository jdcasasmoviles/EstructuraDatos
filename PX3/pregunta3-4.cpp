#include <cstdlib>
#include <iostream>
#include <time.h>
struct nodo{int valor;
            struct nodo*sgte;          
           };
typedef struct nodo *ppila;
void imprimir(ppila);
void push(ppila &,int);
int pop(ppila &);
void suma(ppila,ppila,ppila &);
void resta(ppila,ppila,ppila &);
using namespace std;

int main(int argc, char *argv[])
{
 ppila p1,p2,p3,p4;
             p1=p2=p3=p4=NULL;
             int m,n,i,j,a,b,dato,acarreo,digito;
    cout<<"Numero de cifras1  :";
             cin>>m;
             srand(unsigned(time(NULL)));
             for(i=0;i<m;i++){ 
                              dato=rand()%10;
                              cout<<dato;
                              push(p1,dato);
                              }cout<<endl;cout<<endl;
      cout<<"Numero de cifras2  :";
             cin>>n;
             srand(unsigned(time(NULL)));
             for(i=0;i<n;i++){
                              dato=rand()%10;
                              cout<<dato;
                              push(p2,dato);
                              }cout<<endl;cout<<endl;
 suma(p1,p2,p3);
cout<<"La suma de los numeros:"<<endl;
imprimir(p3);
resta(p1,p2,p4);
cout<<"La resta de los numeros:"<<endl;
imprimir(p4);
    system("PAUSE");
    return EXIT_SUCCESS;
}

void push(ppila &p,int x){
ppila q=new (struct nodo);
q->valor=x;
q->sgte=p;
p=q; 
                          }

int pop(ppila &p){
 int x=p->valor;
 ppila q=p; 
 p=p->sgte;
 delete(q);
 return x;     
                   }
                   
 void imprimir(ppila p){
 while(p!=NULL){
 cout<<p->valor;
 p=p->sgte;
                }
 cout<<endl;
                     }
                     
 void suma(ppila p1,ppila p2,ppila &p3){
  int n,d1,d2,acarreo=0;
  while(p1!=NULL||p2!=NULL){
  if(p1==NULL)d1=0;
  else d1=p1->valor;
  if(p2==NULL)d2=0;
  else d2=p2->valor;
  n=d1+d2+acarreo;
  push(p3,n%10);
  acarreo=n/10;
  if(p1!=NULL)p1=p1->sgte;
  if(p2!=NULL)p2=p2->sgte;
                            }   
  if(acarreo!=0) push(p3,acarreo);
                                          }
                                          
  void resta(ppila p1,ppila p2,ppila &p4){
  int n,d1,d2,acarreo=0,disminucion;
  while(p1!=NULL||p2!=NULL){
  if(p1==NULL)d1=0;
  else d1=p1->valor;
  if(p2==NULL)d2=0;
  else d2=p2->valor;
  if(d1>=d2){
  n=d1-d2+acarreo;
  push(p4,n%10);
  acarreo=n/10;
            }
  else{
       n=10+d1-d2+acarreo;
       push(p4,n%10);
        acarreo=n/10;
       disminucion=(p1->sgte)->valor;
       (p1->sgte)->valor=disminucion-1;
       }
  if(p1!=NULL)p1=p1->sgte;
  if(p2!=NULL)p2=p2->sgte;
                            }   
  if(acarreo!=0) push(p4,acarreo);
                                          }

