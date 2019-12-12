#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
		LinkedList* this; 											//creo un puntero a la LL
	    this = (LinkedList *)malloc(sizeof(LinkedList));
	    if(this != NULL)
	    {
	        this->size=0;
	        this->pFirstNode = NULL;
	    }
	    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Ret (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
	 int ret = -1;
	    if(this != NULL)
	    {
	        ret = this->size;
	    }
	    return ret;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *recorro los distintos nodos de la LL hasta llegar al que sea igual al indice buscado, retorno su DDM
 */

static Node* getNode(LinkedList* this, int nodeIndex)
{
		Node* pNode = NULL;
	    int i;
	    if(this != NULL && ll_len(this) > 0 && nodeIndex < ll_len(this) && nodeIndex >= 0)
	    {
	        pNode = this->pFirstNode;
	        for(i=0;i< nodeIndex;i++)
	        {
	            pNode = pNode -> pNextNode;
	        }
	    }
	    return pNode;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
	return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 *1-creo con malloc un nuevo nodo
 *2-le asigno la DDM del elemento que quiero agregar
 *3-le asigno al NextNode del nodo anterior la DDM del nuevo nodo.
 *
 */

static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
	int returnAux = -1;
	    Node* newNode;
	    Node* prev;
	    Node* next;

	    if (this != NULL){
	       if (nodeIndex <= ll_len(this) && nodeIndex >= 0){
	        newNode = (Node*)malloc(sizeof(Node));
	        if (newNode != NULL){
	            newNode->pElement = pElement;
	            newNode->pNextNode = NULL;
	            if (nodeIndex == 0){
	                newNode->pNextNode = this->pFirstNode;
	                this->pFirstNode = newNode;
	            }
	            else
	            {
	            	prev=getNode(this,nodeIndex-1);				//obtengo la DDM del nodo anterio
	            	prev->pNextNode=newNode;					//Guardo la DDM del nuevo Nodo en el NextNode del nodo Anterior.
	            }
	           this->size++;
	           returnAux = 0;
	        }
	     }
	    }
	    return returnAux;
}
/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
	return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
		int returnAux = -1;
	    int len = ll_len(this);
	    if(this!= NULL)
	    {
	        addNode(this,len,pElement);
	        returnAux = 0;
	    }
	    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
		void* returnAux = NULL;
	    Node* auxNode;
	    int len = ll_len(this);
	    if(this != NULL && index >= 0 && index < len && len > 0)
	    {
	        auxNode = getNode(this,index);
	        returnAux = auxNode->pElement;
	    }
	    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int cant;
    int returnAux = -1;
    Node* auxNode;
    cant = ll_len(this);
    if(this != NULL && index >= 0 && index < cant && cant > 0)
    {
        auxNode = getNode(this,index);
        auxNode->pElement = pElement;
        returnAux = 0;
    }

    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
	  	int cant;
	    int returnAux = -1;
	    Node* auxNode;
	    Node* prev;
	    Node* next;
	    cant = ll_len(this);											// tomo el largo actual de la LinkendList
	    if(this != NULL && index >= 0 && index < cant && cant > 0)
	    {
	        if (index == 0){											//si es el primero nodo el que quiero eliminar
	            auxNode = getNode(this,index);							//auxNode es el que quiero eliminar. debo saber a donde apunta el proximo para guardarma la DDM
	            this->pFirstNode = auxNode->pNextNode;
	            free(auxNode);
	            this->size--;
	            returnAux = 0;
	        }
	        else if(index>=1){
	            auxNode = getNode(this,index);							//obtengo la DDM del anterio y del si
	            prev = getNode(this,index-1);
	            next = getNode(this,index+1);
	            prev->pNextNode = next;
	            free(auxNode);
	            this->size--;
	            returnAux = 0;
	        }
	    }
	    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    int i,cant;
    cant = ll_len(this);
    if (this!=NULL){
        for(i=0;i<cant;i++){
            ll_remove(this,i);
        }
        returnAux = 0;
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *recorro la linkedlist y elimino cada uno de los nodos.
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
	int returnAux = -1;
	int i,cant;
	Node* nodeAux;
	cant = ll_len(this);
	if (this!=NULL){
	for(i=0;i<cant;i++){
		nodeAux = getNode(this,0);
		free(nodeAux);
		this->size--;
		}
	        returnAux = 0;
	    }
	    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
	int returnAux = -1;
    int i,cant;
    Node* nodeAux;
    cant = ll_len(this);
    if (this!=NULL){
        nodeAux = this->pFirstNode;
            for(i=0;i<cant;i++){
                if (nodeAux->pElement == pElement){
                    returnAux = i;
                    break;
                }
                else{
                	nodeAux = getNode(this,i+1);
                    //nodeAux = nodeAux->pNextNode; correcto
                }
            }
    }
    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
   int returnAux;

    if(this==NULL){
    	returnAux= -1;
    }else if(this->size>0){
    	returnAux =0;
    }else if(this->size==0)
    	returnAux=1;


    return returnAux;



}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1,cant;
    cant = ll_len(this);
    if ((this != NULL)&& (index>=0 && index <=cant)){
        returnAux = addNode(this,index,pElement);
    }

    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;
    void* auxNode;
    int cant;
    cant = ll_len(this);
    if ((this != NULL) && (index>=0 && index <=cant)){
        auxNode = ll_get(this,index);
        ll_remove(this,index);
        returnAux = auxNode;
    }
    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int i,cant,bandera = 0;
    Node* current;
    cant = ll_len(this);
    if (this != NULL){
        for (i=0;i<cant;i++){
            current = getNode(this,i);
            if (current->pElement == pElement){
                returnAux = 1;
                bandera = 1;
                break;
            }
        }
        if (bandera == 0){
            returnAux = 0;
        }
    }
    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)

*/

/*
 * recorro todos los nodos de una de los dos LL y por cada nodo obtengo lo que contenga.
 * con la funcion ll_contains verifico si ese elemento obtenido se encuentra en el otro LL
 * repito esa operacion en cada nodo de la primer LL
 *
 */
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    int i,bandera = 1;
    void* auxElement;
    int cant2;
    cant2 = ll_len(this2);
    if (this != NULL && this2 != NULL){
        for(i=0;i<cant2;i++){
            auxElement = ll_get(this2,i);
            if(ll_contains(this,auxElement)==0){
                returnAux = 0;
                bandera = 0;
                break;
            }
        }
        if (bandera ==1){
            returnAux = 1;
        }
    }
    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;

    int i;
    void* auxElement;
    if ((this != NULL) && (from >= 0 && this->size >= to)){
        cloneArray = ll_newLinkedList();
        for(i=from;i<to;i++){
            auxElement = ll_get(this,i);
            ll_add(cloneArray,auxElement);
        }
    }
    else{
        cloneArray = NULL;
    }
    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;
    cloneArray = ll_newLinkedList();
    int cant,i;
    cant = ll_len(this);
    void* auxElement;
    if (this!=NULL && cloneArray!=NULL){
        for(i=0;i<cant;i++){
            auxElement = ll_get(this,i);
            addNode(cloneArray,i,auxElement);
        }
    }
    else{
        cloneArray = NULL;
    }
    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux = -1;
    int i;
    int bandera;
    Node* auxNode;																								// creo un nodo auxiliar
    if(this != NULL && ll_len(this)> 0 && pFunc != NULL && (order == 1 || order == 0))
    {
        do
        {
            i = 0;
            auxNode = getNode(this,i);
            bandera = 0;
            for(i=0;i<ll_len(this)-1;i++)
            {
                if(i!= 0)
                {
                    auxNode = auxNode->pNextNode;															//aumento la posicion del nodo.. o sea cambio al nodo siguiente.
                }
                if((order == 0 && auxNode->pElement != NULL && auxNode->pNextNode->pElement != NULL
                    && (*pFunc)(auxNode->pElement,auxNode->pNextNode->pElement)== -1)||
                   (order == 1 && auxNode->pElement != NULL && auxNode->pNextNode->pElement != NULL
                    && (*pFunc)(auxNode->pElement,auxNode->pNextNode->pElement)== 1))
                {
                   bandera = 1;
                   ll_orden(this,auxNode);
                }
            }
        }
        while(bandera == 1);
        returnAux = 0;
    }
    return returnAux;

}

/** \brief Algoritmo que reordena los nodos.
 * \param pList LinkedList* Puntero a la lista
 * \param pNodeActual Es el primer nodo que se va a intercambiar, el segundo lo obtenemos de su pNextNode
 * \return int Retorna (-1) Error: si el puntero a la lista es NULL o alguno de los nodos es NULL. (0) Si ok
 * la funcion efectua  un SWAP entre nodos.
 */

int ll_order(LinkedList* this, Node* pNodeActual)
{
    int returnAux = -1;
    Node* pNodeSiguiente = pNodeActual->pNextNode;
    void* auxElement = NULL;
    if(this != NULL && pNodeActual != NULL && pNodeSiguiente != NULL)
    {
        auxElement = pNodeActual->pElement;
        pNodeActual->pElement = pNodeSiguiente->pElement;
        pNodeSiguiente->pElement = auxElement;
        returnAux = 0;
    }
    return returnAux;
}


/** \brief recorre la lista y ejecuta la funcion que trae por parametro.
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc Es la funcion que se ejecutara.
 * \return int Retorna (-1) Error: si el puntero a la lista es NULL o alguno de los nodos es NULL. (0) Si ok
 * la funcion efectua  un SWAP entre nodos.
 */




int ll_map(LinkedList* this, void (*pFunc)(void*))
{
	printf("entro");
	int returnAux = -1;
	int i;
	void* pElement;

	if(this != NULL  && ll_len(this) > 0)
	{
		printf("\nEntro al if");
		for(i=0;i<ll_len(this);i++)
		{

			pElement = ll_get(this,i);
			pFunc(pElement);
			returnAux = 0;
		}
	}

	return returnAux;
}



LinkedList* ll_filter(LinkedList* this, int (*pFunc)(void*,int, int),int from, int to)
{
	LinkedList* listaFiltrada = NULL;
	int i;
	void* pElement;

	listaFiltrada = ll_newLinkedList();
	if(this != NULL && pFunc != NULL && ll_len(this) > 0 && listaFiltrada != NULL)
	{
		for(i=0;i<ll_len(this);i++)
		{
			pElement = ll_get(this,i);
			if(pFunc(pElement,from,to)==1)
			{
				ll_add(listaFiltrada,pElement);
			}
		}
	}

	return listaFiltrada;
}
