#include <cstdlib>
#include <iostream>
#include<math.h>
struct nodo{double valor;
            struct nodo*sgte;          
           };
typedef struct nodo *ppila;
void imprimir(ppila);
void push(ppila &,double);
double pop(ppila &);
double epostfija(char[]);
using namespace std;

main()
{ char cad[100];
cout<<"EXPRESION EN POSTFIJA GENERICA:";cin>>cad;
cout<<"RESULTADO FINAL :"<<epostfija(cad)<<endl;
    system("PAUSE");
    return EXIT_SUCCESS;
}
void push(ppila &p,double x){
ppila q=new (struct nodo);
q->valor=x;
q->sgte=p;
p=q; 
                          }

double pop(ppila &p){
 double x=p->valor;
 ppila q=p; 
 p=p->sgte;
 delete(q);
 return x;     
                   }
                   
 void imprimir(ppila p){
 while(p!=NULL){
 cout<<p->valor<<" ";
 p=p->sgte;
                }
 cout<<endl;
                     }
                     
 double epostfija(char cad[]){
   ppila p=NULL;int i;
   char op;double a,b,r,valor;
   for(i=0;cad[i]!='\0';i++){
   op=cad[i];
   if(op=='+'||op=='-'||op=='*'||op=='/'||op=='@'){
   b=pop(p);
   a=pop(p);
   switch(op)
   {
    case '+':r=a+b;push(p,r);break; 
    case '-':r=a-b;push(p,r);break;   
    case '*':r=a*b;push(p,r);break;   
    case '/':r=a/b;push(p,r);break;   
    case '@':r=pow(a,b);push(p,r);break;          
   }
   cout<<"OPERRACION :"<<a<<op<<b<<"="<<r<<endl;
                                                   }
   else {
    cout<<"INGRESE VALOR DE "<<op<<":";cin>>valor;
    push(p,valor);
        }
    cout<<"PILA :";imprimir(p);cout<<endl;
           }  
    return pop(p);
                             }
 
 


