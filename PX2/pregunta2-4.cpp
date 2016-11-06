#include <iostream>
#define MAX 500
struct nodo{int x;
             struct nodo *siguiente;};
typedef struct nodo *plista;
void insertar_inicio(plista &lista,int valor);
void mostrar(plista lista);
void suma(plista p1,plista p2,plista &p3);
void invertir(plista &lista);
using namespace std;
int main()
{
  plista l1,l2,l3;
  l1=l2=l3=NULL;int n,i;
  cout<<"Cuantos terminos de la serie desea:";cin>>n;
  insertar_inicio(l1,0);
  insertar_inicio(l2,1);
  if(n==1)
  {cout<<"Termino "<<1<<":";mostrar(l1);}
  else if(n==2)
  {cout<<"Termino "<<1<<":";mostrar(l1);
  cout<<"Termino "<<2<<":";mostrar(l2);
                 }
  else{
  cout<<"Termino "<<1<<":";mostrar(l1);
  cout<<"Termino "<<2<<":";mostrar(l2);
  for(i=3;i<=n;i++){l3=NULL;
  invertir(l1);
  suma(l1,l2,l3);l1=NULL;
  cout<<"Termino "<<i<<":";mostrar(l3);
  l1=l2;l2=NULL;invertir(l1);
  l2=l3;invertir(l2);
}
}
 
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

