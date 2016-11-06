#include <cstdlib>
#include <iostream>
#include <time.h>
using namespace std;
struct NODO_AVL{
  int  elemento;
   struct NODO_AVL *izqda;
   struct NODO_AVL *drcha;
   int altura;
};

typedef struct NODO_AVL *arbolAVL;
#define AVL_VACIO NULL
//#define maximo(a,b) ((a>b)?(a):(b))
#define alt(n) (n?n->altura:-1)
int maximo(int a,int b)
{return (a>b)?a:b;
}

void verarbol(arbolAVL arbol,int nro){
     int i;
     if(arbol==NULL)return;                                
     verarbol(arbol->drcha,nro+1);                   
     for(i=0;i<nro;i++)cout<<"   ";
     cout<<arbol->elemento<<endl;
     verarbol(arbol->izqda,nro+1);   
     }

arbolAVL Crear_AVL()
{
   return AVL_VACIO;
}

void Destruir_AVL(arbolAVL A)
{
  if (A) {
      Destruir_AVL(A->izqda);
      Destruir_AVL(A->drcha);
      free(A);
   }
}

int miembro_AVL(int e,arbolAVL A)
{
   if (A == NULL)
   	 return 0;
  
   if (e == A->elemento)
   	 return 1;
   else
   	if (e < A->elemento)
    	   return miembro_AVL(e,A->izqda);
   	else
    	   return miembro_AVL(e,A->drcha);
}

void simple_derecha(arbolAVL &A)
{
   arbolAVL p;
   p=A->izqda;
   A->izqda=p->drcha;
   p->drcha=A;
   A=p;
   /* Ajustamos las alturas */
   p=A->drcha;
   p->altura=maximo(alt(p->izqda),alt(p->drcha))+1;
   A->altura=maximo(alt(A->izqda),alt(A->drcha))+1;
}

void simple_izquierda(arbolAVL &A)
{
    arbolAVL p;
   p=A->drcha;
   A->drcha=p->izqda;
   p->izqda=A;
   A=p;
   /*Ajustamos las alturas */
   p=A->izqda;
   p->altura=maximo(alt(p->izqda),alt(p->drcha))+1;
   A->altura=maximo(alt(A->izqda),alt(A->drcha))+1;
}

void Doble_izquierda_derecha (arbolAVL &A)
{
   simple_izquierda(A->izqda);
   simple_derecha(A);
}

void Doble_derecha_izquierda (arbolAVL &A)
{
   simple_derecha(A->drcha);
   simple_izquierda(A);
}

void ajusta_avl(int e, arbolAVL &A)
{
   if (!A)
      return;
   if (e>A->elemento)
      ajusta_avl(e,A->drcha);
   else if (e <A->elemento)
           ajusta_avl(e,A->izqda);

   switch (alt(A->izqda)-alt(A->drcha)) {
   case 2:
      if(alt(A->izqda->izqda)>alt(A->izqda->drcha))
         simple_derecha(A);
      else Doble_izquierda_derecha(A);
      break;
   case -2:
      if (alt(A->drcha->drcha)>alt(A->drcha->izqda))
         simple_izquierda(A);
      else Doble_derecha_izquierda(A);
      break;
   default:
      A->altura = maximo(alt(A->izqda),alt(A->drcha))+1;
   }
}

void insertar(arbolAVL &arbol,int x){
     if(arbol==NULL){
                     arbol=new (struct NODO_AVL);
                     arbol->elemento=x;
                     arbol->izqda=NULL;
                     arbol->drcha=NULL;
                     }
     else if(x<arbol->elemento)insertar(arbol->izqda,x);
     else if(x>arbol->elemento)insertar(arbol->drcha,x);
     }
     
void insertarAVL(int e, arbolAVL &p)
{
   insertar(p,e);
   ajusta_avl(e,p);
}

void borrarAVL (int e, arbolAVL &A)
{
    arbolAVL p,aux,dest;
   int elem;

   p=A;
   elem=e;
   while (p->elemento!=e) {
      elem=p->elemento;
      if (p->elemento>e)
         p=p->izqda;
      else p=p->drcha;
   }

   if (p->izqda!=NULL && p->drcha!=NULL) {
      aux=p->drcha; 
      elem=p->elemento;
      while (aux->izqda) { 
         elem=aux->elemento;
         aux=aux->izqda;
      }
      p->elemento=aux->elemento;
      p=aux;
   }
   if(p->izqda==NULL && p->drcha==NULL) {
      delete(p);
      p=NULL;
   } else if(p->izqda == NULL) {
      dest=p;
      p= p->drcha;
      delete(dest);
   } else {
      dest=p;
      p=p->izqda;
      delete(dest);
   }
   ajusta_avl(elem,A);
}


     
int main(int argc, char *argv[])
{   
int m,i;
arbolAVL arbol1;
arbol1=Crear_AVL();
srand(unsigned(time(NULL)));
cout<<"cantidad de elementos del arbol 1:";
cin>>m;
for(i=0;i<m;i++){
        insertarAVL(1+rand()%25,arbol1);
        }
cout<<"Arbol AVL"<<endl;
verarbol(arbol1,0);
    system("PAUSE");
    return EXIT_SUCCESS;
}
