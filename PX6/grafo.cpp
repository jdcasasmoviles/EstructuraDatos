/***********************************
/Curso: Estructura de datos /
/Practica N-2 /
/Alumno: Tomas j. Casas Rodriguez /
***********************************/
#include <cstdlib>
#include <iostream>
#include <string.h>
/*GRAFOS*/
struct nodoa{double peso;
              int visitado;
            struct nodoD *destino;
            struct nodoa *enlace;
            };
typedef struct nodoa *Lista;
            
struct nodoD{char x[30];
             int visto;
            Lista lista;
            struct nodoD *enlace;
            };
typedef struct nodoD *grafo;
/*COLAS*/
struct nodoc{char nro[30];
             grafo vital;
            struct nodoc *sgte;
            };
            
struct cola{struct nodoc *delante;
            struct nodoc* atras;     
           };
typedef struct cola kola;
/*PILAS*/
struct nodo{char valor[30];
            grafo vitaly;
            struct nodo*sgte;          
           };
typedef struct nodo *ppila;

using namespace std;
/*PROTOTIPOS*/
void push(ppila &,grafo n,char dato[]);
grafo pop(ppila &);
void imprimir(ppila);
void inicializar(kola &q);
void encola(kola &q,grafo n,char dato[]);
grafo desencolar(kola &q);
void vercola(kola q);

void nuevoV(char dato[],grafo &g){
grafo nuevo=new(struct nodoD);
strcpy(nuevo->x,dato);
nuevo->visto=0;
nuevo->lista=NULL;
nuevo->enlace=g;
g=nuevo;
                                  }

grafo direccion(grafo g,char l[]){
grafo  n;
for (n=g;n!=NULL; ){ if (strcmp(n->x,l)==0)return n;
                     else n=n->enlace;
                   }
return NULL;       
                                  }

void arista(char org[],char des[],double dato,grafo &g){
grafo v1,v2;
Lista ady=new(struct nodoa);
v1=direccion(g,org);
v2=direccion(g,des);
if(v1 && v2){
            ady->destino=v2;
            ady->enlace=v1->lista;
            ady->peso=dato;
            v1->lista=ady;
            }
else{ if(v1==NULL)cout<<"\nNo existe el vertice "<<org;
      if(v2==NULL)cout<<"\nNo existe el vertice "<<des;
   }
                                                        }        

void mostrar(grafo g){
while(g!=NULL){ 
cout<<"\nVERTICE :"<<g->x<<endl;
Lista a=g->lista;
   while(a!=NULL){
         cout<<"\t\t"<<g->x<<"->"<<a->destino->x<<" con peso "<<a->peso<<endl;
         a=a->enlace;
                }
g=g->enlace;
               }
cout<<endl;
                      }
                
int anchura(grafo g,kola &q,char clave[])
{
encola(q,g,g->x);
while(q.delante!=NULL)
{ vercola(q);
g=desencolar(q);
cout<<"\n\t\tVertice visitado : "<<g->x<<endl;
g->visto=1;
Lista a=g->lista;
   while(a!=NULL){
                  if(a->destino->visto==0){if(strcmp(a->destino->x,clave)==0)
                                           return 1;
                                           encola(q,a->destino,a->destino->x);
                                           }
                   a=a->enlace;
                 }
}
cout<<endl;
return 0;

}

int profundidad(grafo g,ppila p,char clave[])
{
push(p,g,g->x);
while(p!=NULL)
{imprimir(p);
g=pop(p);
cout<<"\n\t\tVertice visitado : "<<g->x<<endl;
g->visto=1;
Lista a=g->lista;
   while(a!=NULL){
                  if(a->destino->visto==0){if(strcmp(a->destino->x,clave)==0)
                                           return 1;
                                           push(p,a->destino,a->destino->x);
                                           }
                   a=a->enlace;
                 }
}
cout<<endl;
return 0;

}

int main(int argc, char *argv[])
{   ppila p=NULL;kola q;
    inicializar(q);
    grafo grafo1=NULL;
    nuevoV("A",grafo1);
	nuevoV("B",grafo1);
    nuevoV("C",grafo1);
    nuevoV("D",grafo1);
    nuevoV("H",grafo1);
    nuevoV("R",grafo1);
    nuevoV("T",grafo1);
    nuevoV("D",grafo1);
    arista("H","T",9,grafo1);
    arista("H","A",22,grafo1);
    arista("R","H",23,grafo1);
    arista("C","R",14,grafo1);
    arista("D","C",3,grafo1);
    arista("D","B",5,grafo1);
    arista("B","H",4,grafo1);
    cout<<"**** G   R   A   F   O ****\n";
    cout<<"---------------------------\n";
    mostrar(grafo1);
    cout<<"**** BUSQUEDA DE UN GRAFO EN ANCHURA ****\n";
    cout<<"------------------------------------------\n";
    if( anchura(grafo1,q,"Q")) cout<<"\nSE ENCUENTRA EN EL GRAFO\n";
    else  cout<<"NO ESTA EN EL GRAFO\n";
    /*cout<<"**** BUSQUEDA DE UN GRAFO EN PROFUNDIDAD ****\n";
    cout<<"---------------------------------------------\n";
    if(profundidad(grafo1,p,"R")) cout<<"\nSE ENCUENTRA EN EL GRAFO\n";
    else  cout<<"NO ESTA EN EL GRAFO\n";*/
    system("PAUSE");
    return EXIT_SUCCESS;
}

void inicializar(kola &q){
q.delante=NULL;
q.atras=NULL;
                         }
                                
void encola(kola &q,grafo n,char dato[]){
struct nodoc *p;
p=new(struct nodoc);
strcpy(p->nro,dato);
p->vital=n;
p->sgte=NULL;
if(q.delante==NULL)q.delante=p;
else (q.atras)->sgte=p;
q.atras=p;
                                         }
                                
grafo desencolar(kola &q){
struct nodoc *p;
p=q.delante;
grafo auxiliar=p->vital;
q.delante=(q.delante)->sgte;
delete(p);
return auxiliar;
                          }
             
void vercola(kola q){
struct nodoc *p;
p=q.delante;
while(p!=NULL){
cout<<p->nro<<"->";
p=p->sgte;
               }
                    }

void push(ppila &p,grafo n,char dato[]){
ppila q=new (struct nodo);
strcpy(q->valor,dato);
q->vitaly=n;
q->sgte=p;
p=q; 
                                        }

grafo pop(ppila &p){
 grafo aux=p->vitaly;
 ppila q=p; 
 p=p->sgte;
 delete(q);
 return aux;     
                   }
                   
 void imprimir(ppila p){
 while(p!=NULL){
 cout<<p->valor<<"->";
 p=p->sgte;
                }
 cout<<endl;
                       }
               

