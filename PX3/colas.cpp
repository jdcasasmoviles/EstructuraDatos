#include <cstdlib>
#include <iostream>
void inicializar(struct cola &q);
void encola(struct cola &q,int n);
void vercola(struct cola q);
void vaciarcola(struct cola &q);
int desencolar(struct cola &q);
struct nodoc{int nro;
            struct nodoc *sgte;
            };
            
struct cola{struct nodoc *delante;
            struct nodoc* atras;     
           };
           

using namespace std;

int main()
{ int op,n;
struct cola q;
inicializar(q);
do{cout<<endl<<"***MENU***"<<endl;
  cout<<"1--->Encolar elemento"<<endl;
  cout<<"2--->Desencolar elemento"<<endl;
  cout<<"3--->Visualizar cola"<<endl;
  cout<<"4--->Vaciar cola"<<endl;
  cout<<"5--->Salir"<<endl;
  cout<<endl<<"Ingrese la opcion:";cin>>op;
  switch(op){
  case 1:{cout<<endl<<"Encolar elemento:";
         cin>>n;
         encola(q,n);
         break;}
   case 2:{if(q.delante!=NULL){
         n=desencolar(q);
         cout<<endl<<"Desencola Elemento:"<<n<<endl;
         break;
                               }
           
         else cout<<endl<<"No hay elementos en cola"<<endl;
         }
   case 3:{cout<<endl<<"Elementos de la cola:"<<endl;
           vercola(q);
           break;
           }
   case 4:{vaciarcola(q);
           break;
           }
           }
   }while(op!=5);
   
    system("PAUSE");
    return EXIT_SUCCESS;
}

void inicializar(struct cola &q){
q.delante=NULL;
q.atras=NULL;
                                }

void encola(struct cola &q,int n){
struct nodoc *p;
p=new(struct nodoc);
p->nro=n;
p->sgte=NULL;
if(q.delante==NULL)q.delante=p;
else (q.atras)->sgte=p;
q.atras=p;
                                }
                                
int desencolar(struct cola &q){
struct nodoc *p;
p=q.delante;
int dato=p->nro;
q.delante=(q.delante)->sgte;
delete(p);
return dato;
                              }

void vaciarcola(struct cola &q){
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
               
void vercola(struct cola q){
struct nodoc *p;
p=q.delante;
while(p!=NULL){
cout<<p->nro<<"->";
p=p->sgte;
               }
cout<<endl;
                          }
                               
