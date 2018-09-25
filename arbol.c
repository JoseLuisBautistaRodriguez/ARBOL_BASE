#include <stdio.h>
#include <stdlib.h>

	/*Estructura autoreferenciada*/
struct TipoPunto
{
	char x;
	char y;
	int nombre;
	int valor;
} auxiliar ;

struct nodoArbol
{
	struct nodoArbol *_ptrIzq;		// Apuntador de arbol izquierdo
	struct TipoPunto dato;						// Valor del  nodo
	struct nodoArbol *_ptrDer;		// Apuntador del arbol derecha
};


	/* Fin de la estructura nodoArbol*/

typedef struct nodoArbol nodoArbol; // Sinonimo de la estructura nodoARbol
typedef nodoArbol *ptrNodoArbol;   // Sinonimo de nodoArbol**

/* Protoripado de funciones */

void insertarNodo( ptrNodoArbol * ptrArbol, struct TipoPunto TDA_Valor);
void inOrden( ptrNodoArbol ptrArbol );

int main()
{
	int i, j, quitar = 0; 							// Contador para el ciclo de 1 a 10.
	int elemento;
	unsigned int numeroDeElementos; 					//Variable para almacenar valores al azar.
	ptrNodoArbol ptrRaiz = NULL; 	// Arbol inicialmente vacio.

	printf("\n\t Ingresa el numero de elementos a evaluar:");
	scanf("%i", &numeroDeElementos);
	struct TipoPunto *puntos = (struct TipoPunto*)malloc(numeroDeElementos*sizeof( struct TipoPunto));
	fflush( stdin );

	for ( i = 0 ; i < numeroDeElementos ; i++ )
	{
		printf("\n\tIngresa los puntos del elemento %d : ", (i+1) );
		(puntos+i)->nombre = (i+1);
		printf("Magnitud: ");
		scanf("%i", &(puntos+i)->valor);
		fflush( stdin );
		printf("\t\tValor en X: ");
		scanf("%c", &(puntos+i)->x);
		fflush( stdin );
		printf("\t\tValor en Y: ");
		scanf("%c", &(puntos+i)->y);
		fflush( stdin );
		//valores[i] = (puntos+i)->valor;
		//printf("Valores = %i ", valores[i]);
	}

	for ( i = 0 ; i < numeroDeElementos; i++ )
	{
		for ( j = 0 ; j < (numeroDeElementos-1) ; j++)
		{
			if ( (puntos + j)->valor > (puntos + (j+1))->valor )
			{
				auxiliar.valor = (puntos+j)-> valor ;
				auxiliar.x = (puntos+j)-> x ;
				auxiliar.y = (puntos+j)-> y ;
				(puntos+j)-> valor = (puntos + (j+1))->valor ;
				(puntos+j)-> x = (puntos + (j+1))->x ;
				(puntos+j)-> y = (puntos + (j+1))->y ;
				(puntos + (j+1))->valor = auxiliar.valor ;
				(puntos + (j+1))->x = auxiliar.x ;
				(puntos + (j+1))->y = auxiliar.y ;
			}
		}
	}
	/**/ 
	// comentario de línea

	/*for ( i = 0 ; i < numeroDeElementos; i++ )
	{
		for ( j = 0 ; j < (numeroDeElementos-1) ; j++)
		{
			if ( (puntos + j)-> x == (puntos + (j+1))-> x && (puntos + j)-> y == (puntos + (j+1))-> y )
			{
				auxiliar.valor = (puntos+j)-> valor ;
				auxiliar.x = (puntos+j)-> x ;
				auxiliar.y = (puntos+j)-> y ;
				(puntos+j)-> valor = (puntos + (j+1))->valor ;
				(puntos+j)-> x = (puntos + (j+1))->x ;
				(puntos+j)-> y = (puntos + (j+1))->y ;
				(puntos + (j+1))->valor = auxiliar.valor ;
				(puntos + (j+1))->x = auxiliar.x ;
				(puntos + (j+1))->y = auxiliar.y ;
				quitar++;
				printf("\n Se ha quitado un elemento %i x= %c y = %c ", quitar, (puntos+j)->x, (puntos+i)->y);
			}else if ( (puntos + j)-> x == (puntos + (j+1))-> y && (puntos + j)-> y == (puntos + (j+1))-> x )
			{
				auxiliar.valor = (puntos+j)-> valor ;
				auxiliar.x = (puntos+j)-> x ;
				auxiliar.y = (puntos+j)-> y ;
				(puntos+j)-> valor = (puntos + (j+1))->valor ;
				(puntos+j)-> x = (puntos + (j+1))->x ;
				(puntos+j)-> y = (puntos + (j+1))->y ;
				(puntos + (j+1))->valor = auxiliar.valor ;
				(puntos + (j+1))->x = auxiliar.x ;
				(puntos + (j+1))->y = auxiliar.y ;
				quitar++;
				printf("\n Se ha quitado un elemento %i x= %c y = %c ", quitar, (puntos+j)->x, (puntos+i)->y);
			}
		}
	}
	if ( quitar != 0 ) numeroDeElementos = numeroDeElementos - quitar ;*/

	for ( i = 0; i  < numeroDeElementos ; i++) printf("\n  %d:(%c,%c)= %2d", (puntos+i)->nombre,(puntos+i)->x,(puntos+i)->y,(puntos+i)->valor);
		printf("\n\n");
	
	for( i = 0 ; i < numeroDeElementos ; i++)
	{
		struct TipoPunto TDA_Valor = puntos[i];
		insertarNodo( &ptrRaiz, TDA_Valor);
	}
	inOrden(ptrRaiz);

	printf("\n\n\n\a");
	free(puntos);
	free(ptrRaiz);
	return 0;
}

void insertarNodo( ptrNodoArbol *ptrArbol, struct TipoPunto TDA_Valor)
{
	/*Si el arbol esta vacio*/
	if(*ptrArbol == NULL) 
	{
		*ptrArbol = malloc(sizeof(nodoArbol));
		/* Si la memoria esta asignada entonses se signa el dato:*/
		if ( ptrArbol != NULL )
		{
			//(*ptrArbol)->dato = valor ;
			(*ptrArbol)->dato.nombre = TDA_Valor.nombre;
			(*ptrArbol)->dato.valor = TDA_Valor.valor;
			(*ptrArbol)->dato.x = TDA_Valor.x;
			(*ptrArbol)->dato.y = TDA_Valor.y;
			(*ptrArbol)-> _ptrIzq = NULL ;
			(*ptrArbol)-> _ptrDer = NULL ; 
		}else
		{
			printf("\n No se inserto el nodo %d, no hay memoria disponible.", TDA_Valor . nombre );
		}
	}else /* Cuando el arbol no esta vacio*/
	{
		/* El dato a inserrtar ees menos que el dato en el  odo actual*/
		if ( TDA_Valor.nombre < (*ptrArbol)-> dato.nombre)
		{
			insertarNodo(&((*ptrArbol)->_ptrIzq), TDA_Valor );
		}
		/* El dato a insertar es mayor que eel dato en el nodo actual */
		else if ( TDA_Valor.nombre > (*ptrArbol)->dato.nombre)
		{
			insertarNodo(&((*ptrArbol)->_ptrDer), TDA_Valor);
		}else
		{
			/* Ignora el valor duplicado del dato*/
			//printf("S");
		}
	}
}

void inOrden( ptrNodoArbol ptrArbol )
{
	/* Si el arbol no esta vacio, entonces hay que reordenarlo */
	if ( ptrArbol != NULL )
	{
		inOrden ( ptrArbol -> _ptrIzq );
		printf("%c %3d : %c , %c = %2d %c" , 219, ptrArbol->dato.nombre, ptrArbol->dato.x, ptrArbol->dato.y, ptrArbol->dato.valor, 219 );
		inOrden(ptrArbol-> _ptrDer);
	}
}
