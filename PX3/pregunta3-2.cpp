#include <stdlib.h>
#include <iostream>
#include<string.h>
#include <time.h>
struct nodol{char xl[50];
             char yl[50];
             struct nodol *siguiente;};
typedef struct nodol *plista;

struct nodop{char xp[50];
            struct nodop*sgte;          
           };
typedef struct nodop *ppila;

struct nodon{char xn[50]; 
            char yn[50];
             struct nodon *se;};
typedef struct nodon *pln;

void push(ppila &p,char valor2[]);
char*  pop(ppila &p);
void insertar_listanueva(pln &nueva,char valor1[],char valor2[]);
void insertar_inicio(plista &lista,char valor1[],char valor2[]);
void imprimir(pln nueva);
int mostrar(plista lista);
void elirepetidos(plista lista);
using namespace std;

main()
{    plista lista=NULL; pln nueva=NULL;
      ppila p1=NULL;
int n,i,elem;
char valor1[50],valor2[50];
char nombre[15][50]={"JESUS CAMPOS","MARIA QUIROZ","MARTIN YARASCA","ANDRES QUISPE",
"ANDY CARDENAS","HELEN LOZANO","NINO ARA","ALEX DAGA","ALINA ENCISO","JULIA TORRE",
"MIGUEL MEJIA","HENNI RAMIREZ","JORGE PRADO","ANAIS SAMAN","ESTEFHANY YAURI"};
char cell[30][50]={"991318777","987052035","991234567","981234567","971232456","973454752",
      "9812347329","936784566","964675345","991338777","987852035","991234560","981234167",
      "971202456","973454752","9812349329","93678356","924675345","991315777","987059034",
      "991233367","981236562","971255456","973404752","9812347329","93678496","964673345",
      "9712347329","926784566","914675345"};
char regalo[18][50]={"TV","RADIO","PLANCHA","LAVADORA","TABLET","TOSTADOR","POLO",
                  "BICICLETA","LICUADORA","CAFETERA","CASACA","MESA","NOTEBOOK",
                  "RELOJ","EXTRACTOR","HORNO","SAMSUMG CS3"};
cout<<"Numero de datos:";
             cin>>n;
             srand(unsigned(time(NULL)));
             for(i=0;i<n;i++){
                              strcpy(valor1,nombre[rand()%15]);
                              //cout<<cell[i]<<"\t"<<i<<endl;
                              strcpy(valor2,cell[rand()%29]);
                              insertar_inicio(lista,valor1,valor2);
                              }
cout<<endl<<"LISTA ORIGINAL :"<<endl; mostrar(lista);

elirepetidos(lista);
cout<<endl<<"LISTA FINAL:"<<endl;
elem=mostrar(lista);

/*"REGALOS :"*/
for(i=0;i<elem;i++){ strcpy(valor2,regalo[rand()%17]);
                     push(p1,valor2);
                     }
/*LISTA DE PREMIADOS*/
for(i=0;i<elem && lista!=NULL;i++){strcpy(valor1,lista->xl);
                                   strcpy(valor2,pop(p1));   
                 insertar_listanueva(nueva,valor1,valor2);
                 lista=lista->siguiente;
                 }
                 
cout<<endl<<endl<<endl<<"\t****LISTA DE PREMIADOS****"<<endl;
imprimir(nueva);
    system("PAUSE");
    return EXIT_SUCCESS;
}

void push(ppila &p,char valor2[]){
ppila q=new (struct nodop);
strcpy(q->xp,valor2);
q->sgte=p;
p=q; 
                          }

char*  pop(ppila &p){
 char *cad;
 cad=new char[50];
 strcpy(cad,p->xp);
 ppila q=p; 
 p=p->sgte;
 delete(q);
 return cad;     
                   }
                   
void insertar_listanueva(pln &nueva,char valor1[],char valor2[]){
     pln q;
     q=new (struct nodon);
      strcpy(q->xn,valor1);
      strcpy(q->yn,valor2);
     q->se=nueva;
     nueva=q;                
                           }

void insertar_inicio(plista &lista,char valor1[],char valor2[]){
     plista q;
     q=new (struct nodol);
     strcpy(q->xl,valor1);
     strcpy(q->yl,valor2);
     q->siguiente=lista;
     lista=q;                
                           }
 
void imprimir(pln nueva){
while(nueva!=NULL){
cout<<nueva->xn<<"\t"<<nueva->yn<<endl;
nueva=nueva->se;
                   } 
 cout<<endl<<endl; 
                   }
                              
int mostrar(plista lista){int j=0;
while(lista!=NULL){
cout<<lista->xl<<"\t"<<lista->yl<<endl;
lista=lista->siguiente;
j++;
                   }
cout<<endl;
return j;
                    }
 
                  
void elirepetidos(plista lista){
 plista q,p,r,ant;
 char num[50];
 q=lista;
 while(q!=NULL){
 strcpy(num,q->xl);
 ant=q;
 r=q->siguiente;
        while(r!=NULL){
                       if(strcmp(num,r->xl)==0){  
                                     ant->siguiente=r->siguiente;
                                     p=r;
                                     r=r->siguiente;
                                     delete(p);
                                     }
                       else{
                            ant=r;
                            r=r->siguiente;
                            }
                       }
                q=q->siguiente;
                }    
                               }
