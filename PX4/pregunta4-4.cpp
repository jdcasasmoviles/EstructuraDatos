#include <cstdlib>
#include <iostream>
#include<string.h>
struct nodoa{char pal[30];
            struct nodoa*izq;
            struct nodoa*der;
            };
typedef struct nodoa*abb;

struct nodo{char letra[1];
            abb x;
            struct nodo *siguiente;
            };
typedef struct nodo *plista;

void ins_lis(plista &dic,char lin[],int r,char alf[]);
void ins_arb(abb &arbol,char cad[]);
void verarbol(abb arbol,int nro);
void p_LlenaDic(plista &dic,char *);
void mostrar_lista(plista dic);
char* f_Traduce(plista dic,char esp[]);
char* bus_arb(abb arbol,char dato[]);
char* slash(char esp[]);
char* ingles(char esp[]);
void p_Elimina(plista &dic);
void eliminar_arbol(abb p);

using namespace std;

int main()
{  plista diccionario=NULL;
  char esp[30];
   p_LlenaDic(diccionario,"palabras.txt");
   mostrar_lista(diccionario);
   cout<<endl<<"Ingrese la palabra a traducir :";
   cin>>esp;
   strcpy(esp,f_Traduce(diccionario,esp));
   cout<<endl<<esp<<endl;
   p_Elimina(diccionario);
   //mostrar_lista(diccionario);
   system("PAUSE");
   return EXIT_SUCCESS;
}

void p_LlenaDic(plista &diccionario,char *arch){
FILE *pfich;int j;
char car;
pfich=fopen(arch,"rt");
if(pfich==NULL){
cout<<"\aImposible abrir el archivo"<<arch;
return;
                }

for(j=90;j>=65;j--){FILE *aux;int i=0,r=1;
                    char lin[30];
                    aux=pfich=fopen(arch,"rt");
                    car=getc(aux);
                    while(car!=EOF){ 
                                    if(car=='\n'){lin[i]='\0';i=0;
                                                  char alf[1];
                                                  alf[0]=(char)j;
                                                  if(strncmp(lin,alf,1)==0){
                                                  ins_lis(diccionario,lin,r,alf);
                                                  r++;
                                                                           }
                                                  }
                                   if(car!='\n'){lin[i]=car;i++;}
                                   car=getc(aux);
                                   if(car==EOF){lin[i]='\0';i=0;
                                                char alf[1];
                                                alf[0]=(char)j;
                                                if(strncmp(lin,alf,1)==0){
                                                ins_lis(diccionario,lin,r,alf);
                                                r++;
                                                                         } 
                                                }
                                   }
                    aux=NULL;
                    }
}
                           
void ins_lis(plista &dic,char lin[],int r,char alf[]){
if(r==1){abb arbol=NULL;
          ins_arb(arbol,lin);
          plista q;
          q=new (struct nodo);
          strcpy(q->letra,alf);
          q->x=arbol;
          q->siguiente=dic;
          dic=q;
          }
else{plista ind=dic;
     while(ind!=NULL){
                     if(strncmp(ind->letra,alf,1)==0){
                                                      ins_arb(ind->x,lin);
                                                      break;          
                                                     }
                     ind=ind->siguiente;      
                     }
     }
                       
}

void ins_arb(abb &arbol,char cad[]){
if(arbol==NULL){
                arbol=new (struct nodoa);
                strcpy(arbol->pal,cad);
                arbol->izq=NULL;
                arbol->der=NULL;
                }
else if(strcmp(cad,arbol->pal)<0)ins_arb(arbol->izq,cad);
else if(strcmp(cad,arbol->pal)>0)ins_arb(arbol->der,cad);
     }
    
 void verarbol(abb arbol,int nro){
     int i;
     if(arbol==NULL)return;                                
     verarbol(arbol->der,nro+1);                   
     for(i=0;i<nro;i++)cout<<"\t\t\t";
     cout<<arbol->pal<<endl;
     verarbol(arbol->izq,nro+1);   
                                }
                                
 void mostrar_lista(plista lista){
      while(lista!=NULL){
                         cout<<"LETRA : "<<lista->letra[0]<<endl;
                         verarbol(lista->x,0);
                         cout<<endl;
                         lista=lista->siguiente;
                        }
 cout<<endl<<endl<<endl<<endl;
                                 }
 
 char* f_Traduce(plista lista,char esp[]){
 char alf[1];alf[0]=esp[0];
 plista ind=lista;
 while(ind!=NULL){
                 if(strncmp(ind->letra,alf,1)==0){
                                                  strcpy(esp,bus_arb(ind->x,esp));
                                                  if(esp[0]!='\0')return esp;
                                                  else return esp;
                                                  break;          
                                                 }
                 ind=ind->siguiente;
                 }
 esp[0]='\0';
 return esp;
 }
       
 char* bus_arb(abb arbol,char dato[]){
 char *cad;
 cad=new char[30];
 while(arbol!=NULL){ 
                    if(strcmp(dato,slash(arbol->pal))<0)arbol=arbol->izq;
                    else if(strcmp(dato,slash(arbol->pal))>0)arbol=arbol->der;
                    else if(strcmp(dato,slash(arbol->pal))==0){
                                strcpy(cad,ingles(arbol->pal));
                                                    return cad;
                                                               }
                   } 
 cad[0]='\0';
 return cad;
 }
 
 char* slash(char esp[])
 {int i=0;char *cad;
  cad=new char[30];
  while(esp[i]!='\0'){cad[i]=esp[i];i++;
                      if(esp[i]=='/'){cad[i]='\0';
                                     return cad;
                                     break;
                                     }
                     }
 }
 
 char* ingles(char esp[]){
 int j,i=0,k=0; char *ingles;
 ingles=new char[30];
 while(esp[i]!='\0'){
                    if(esp[i]=='/'){k=1;i++;j=0;}
                    if(k==1){ingles[j]=esp[i];j++;}
                     i++;           
                    }
 ingles[j]='\0';
 return ingles;
               }
 
void p_Elimina(plista &lista){
while(lista!=NULL){
                   eliminar_arbol(lista->x);
                   lista=lista->siguiente;
                  }
delete(lista);
}
                                    
void eliminar_arbol(abb p){
  abb Ai,Ad;
  if ( p != NULL )
  { Ai=p->izq;
    Ad=p->der;
    eliminar_arbol(Ai);
    eliminar_arbol(Ad);
    delete p;
  }
                           }                                

                              
                                
