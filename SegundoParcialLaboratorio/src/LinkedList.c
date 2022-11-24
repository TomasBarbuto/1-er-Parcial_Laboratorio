#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/**
 * \brief : Crea un nuevo LinkedList en memoria de manera dinamica
 * \param : void
 * \return: LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
			o el puntero al espacio reservado
**/
LinkedList* ll_newLinkedList(void){

    LinkedList* this = (LinkedList*) malloc(sizeof(LinkedList*));

    if(this != NULL){

        this->pFirstNode = NULL;
        this->size = 0;
    }

    return this;
}

/**
 * \brief Retorna la cantidad de elementos de la lista.
 * \param this LinkedList*
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
**/
int ll_len(LinkedList* this){

    int retorno = -1;

    if(this != NULL){

        retorno = this->size;
    }
    return retorno;
}

/**
 * \brief : Obtiene un nodo de la lista
 * \param : this LinkedList*, nodeindex int
 * \return: Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o  (pNode) Si funciono correctamente
**/
static Node* getNode(LinkedList* this, int nodeIndex){

    Node* auxNode = NULL;

    if(this != NULL && nodeIndex >= 0 && nodeIndex < ll_len(this)){

        auxNode = this->pFirstNode;

        for(int i = 0; i < nodeIndex; i++){

            auxNode = auxNode->pNextNode;
        }
    }
    return auxNode;
}

/**
 * \brief : Agrega y enlaza un nuevo nodo a la lista
 * \param : LinkedList* this, int nodeIndex,void* pElement.
 * \return: int Retorna -1 Error , 0 Si funciono correctamente
**/
static int addNode(LinkedList* this, int nodeIndex,void* pElement){

   int retorno = -1;

   Node* auxNode = (Node*)malloc(sizeof(Node*));
   Node* auxPrevNode = NULL;

    if(auxNode != NULL && this != NULL && nodeIndex >= 0 && pElement != NULL && nodeIndex <= ll_len(this)){

    	auxNode->pElement = pElement;

        if(nodeIndex == 0){

            auxNode->pNextNode = this->pFirstNode;
            this->pFirstNode = auxNode;
            this->size++;
            retorno = 0;

        }else{

           auxPrevNode = getNode(this, nodeIndex-1);

           if(auxPrevNode != NULL){

               auxNode->pNextNode = auxPrevNode->pNextNode;
               auxPrevNode->pNextNode = auxNode;
               this->size++;
               retorno = 0;
           }
        }
    }
    return retorno;
}

/**
 * \brief : Agrega un elemento a la lista.
 * \param : LinkedList* this, void* pElement.
 * \return: Retorna -1 Error, 0 Si funciono correctamente
**/
int ll_add(LinkedList* this, void* pElement){

    int retorno=-1;

    if(this != NULL && pElement != NULL){

        if(addNode(this, ll_len(this), pElement) == 0){

            retorno=0;

        }
    }
    return retorno;
}

/**
 * \brief : trae un Nodo segun el indice que se le pase por parametro.
 * \param : LinkedList* this, int index
 * \return: retorna NULL, si no se encontro, si funciono retorna el nodo*.
**/
void* ll_get(LinkedList* this, int index){

    Node* auxNode = NULL;
    void* pRetorno = NULL;

    if(this != NULL && index >= 0 && index < ll_len(this)){

       auxNode = getNode(this, index); //Validar.

       if(auxNode != NULL){

    	   pRetorno = auxNode->pElement;
       }
    }
    return pRetorno;
}

/**
 * \brief : Modifica un elemento de la lista
 * \param : LinkedList* this, int index, void* pElement
 * \return: Retorna -1 Error , retorna 0 si funciono correctamente.
**/
int ll_set(LinkedList* this, int index, void* pElement){

    int retorno = -1;
    Node* auxNode = NULL;

    if(this != NULL && pElement != NULL && index >= 0 && index < ll_len(this)){

        auxNode = getNode(this, index);
        auxNode->pElement = pElement;
        retorno = 0;
    }

    return retorno;
}


/**
 * \brief : Elimina un elemento de la lista
 * \param : LinkedList* this, int index
 * \return: Retorna -1 Error , retorna 0 si funciono correctamente.
**/
int ll_remove(LinkedList* this, int index){

    int retorno = -1;
    Node* auxNode = NULL;
    Node* auxPrevNode = NULL;

    if(this != NULL && index >= 0 && index < ll_len(this)){

        auxNode = getNode(this, index);

        if(index==0){

            this->pFirstNode = auxNode->pNextNode;
            this->size--;


        }else{

            auxPrevNode = getNode(this, index-1);
            auxPrevNode->pNextNode = auxNode->pNextNode;
            this->size--;

        }
        free(auxNode);
        retorno = 0;

    }
    return retorno;
}

/**
 * \brief : Elimina todos los Nodos de la lista
 * \param : LinkedList* this
 * \return: Retorna -1 Error , retorna 0 si funciono correctamente.
**/
int ll_clear(LinkedList* this) {

    int retorno = -1;
    int longitudLinkedList = ll_len(this);

    if (this != NULL && longitudLinkedList > 0) {

        for (int i = 0; i < longitudLinkedList; i++) {

            if(ll_remove(this, 0)){

				retorno = 0;
            }
        }
    }
    return retorno;
}


/**
 * \brief : Elimina la linkedList.
 * \param : LinkedList* this
 * \return: Retorna -1 Error , retorna 0 si funciono correctamente.
**/
int ll_deleteLinkedList(LinkedList* this) {

    int retorno = -1;

    if (this != NULL) {

        if(ll_clear(this) == 0){

			free(this);
			retorno = 0;
        }
    }
    return retorno;
}

/**
 * \brief : Busca el indice de la primer ocurrencia del elemento pasado como parametro
 * \param : LinkedList* this, void* pElement
 * \return: retorna -1 si no hallo coincidencia, si la hayo retorna el indice del elemento.
**/
int ll_indexOf(LinkedList* this, void* pElement) {

    int retorno = -1;
    int longitudLinkedlist = ll_len(this);
    Node* auxNode;

    if (this != NULL && pElement != NULL && longitudLinkedlist > 0) {

        for (int i = 0; i < longitudLinkedlist; i++) {

            auxNode = getNode(this, i);

            if (auxNode != NULL && auxNode->pElement == pElement) {

                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

/**
 * \brief : Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param : LinkedList* this, int (*pFunc)(void* ,void*), int order.
 * \return: Retorna -1 Error , retorna 0 si funciono correctamente.
**/
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order){

    int returnAux =-1;
    int estaOrdenado;
    int longitudThis;
    void* pAuxElement = NULL;
    void* pAuxElementDos = NULL;
    int retornoPFunc;

    if(this != NULL && pFunc!= NULL && (order == 0 || order == 1) ){

    	longitudThis = ll_len(this);

    	do{

    		estaOrdenado = 1;
    		longitudThis--;

    		for(int i = 0; i < longitudThis; i++){

    			pAuxElement = ll_get(this, i);
    			pAuxElementDos = ll_get(this, i+1);
    			retornoPFunc = pFunc(pAuxElement, pAuxElementDos);

    			if((retornoPFunc > 0 && order == 1) || (retornoPFunc < 0 && order == 0)){

    				if(ll_set(this, i, pAuxElementDos) == 0 && ll_set(this, i+1, pAuxElement) == 0){

						estaOrdenado = 0;
    				}
    			}
    		}
    	}while(estaOrdenado == 0);

    	returnAux = 0;
    }
    return returnAux;
}

/**
 * \brief : Indica si la lista esta o no vacia
 * \param : LinkedList* this
 * \return: 0 Si la lista NO esta vacia, 1 Si la lista esta vacia.
**/
int ll_isEmpty(LinkedList* this){

    int retorno = -1;

    if(this != NULL){

        if(ll_len(this) > 0){

            retorno = 0; //ocupado

        }else{

            retorno = 1; //vacio
        }
    }
    return retorno;
}

/**
 * \brief : Inserta un nuevo elemento en la lista en la posicion indicada
 * \param : LinkedList* this, int index, void* pElement
 * \return: Retorna -1 Error , retorna 0 si funciono correctamente.
**/
int ll_push(LinkedList* this, int index, void* pElement){

    int retorno = -1;

    if(this != NULL && index >= 0 && index <= ll_len(this) && pElement != NULL){

        if(addNode(this, index, pElement) == 0){

			retorno = 0;
        }
    }
    return retorno;
}

/**
 * \brief : extrae el elemento de la posicion indicada y retorna su puntero.
 * \param : LinkedList* this, int index
 * \return: Retorna void* o (NULL) Error
**/
void* ll_pop(LinkedList* this, int index){

    void* retorno = NULL;
    void * auxPElement = NULL;

    if(this != NULL && index >= 0 && index < ll_len(this)){

    	auxPElement = ll_get(this, index);

        if(auxPElement != NULL){

            retorno = auxPElement;
            ll_remove(this, index);
        }
    }
    return retorno;

}

/**
 * \brief : Determina si la lista contiene o no el elemento pasado como parametro
 * \param : LinkedList* this, void* pElement
 * \return: 1 Si contiene el elemento, 0 si No contiene el elemento
**/
int ll_contains(LinkedList* this, void* pElement){

    int retorno=-1;//null

    if(this!=NULL && pElement!=NULL){

        if(ll_indexOf(this,pElement) != -1){

            retorno = 1; //si contiene

        }else{

            retorno = 0; //no contiene
        }
    }
    return retorno;
}

/**
 * \brief : Determina si todos los elementos de la lista (this2) estan contenidos en la lista (this)
 * \param : LinkedList* this, LinkedList* this2
 * \return: Retorna  (-1) Error, 1 Si los elementos estan contenidos, 0 si los elementos no estan contenidos.
**/
int ll_containsAll(LinkedList* this, LinkedList* this2){

    int retorno = -1;
    int longitudThis2;

    if(this!=NULL && this2!=NULL){  //ver si hay que validar que una list2 sea menor que list

    	longitudThis2 = ll_len(this2);

        if(longitudThis2 == 0){

            retorno = 0;
        }else{

            for(int i = 0; i < longitudThis2; i++){

                if(ll_contains(this, ll_get(this2, i)) == 0){

                    retorno=0;//no contiene
                    break;

                }else{

                    retorno = 1;//contiene
                }
            }
        }
    }
    return retorno;
}

/**
 * \brief : Crea y retorna una nueva lista con los elementos indicados.
 * \param : LinkedList* this, int from, int to.
 * \return: retorna un nuevo linkedlist*, o NULL si no cumple las condiciones.
**/
LinkedList* ll_subList(LinkedList* this, int from, int to) {

    LinkedList* subList = NULL;
    void* pAuxElemento;

    if(this != NULL && to > from && to <= ll_len(this) && from >= 0 && from < ll_len(this)){
        subList = ll_newLinkedList();

        if(subList != NULL){

            for(int i = from ; i < to ; i++){

            	pAuxElemento = ll_get(this,i);

                if(pAuxElemento != NULL){

                    ll_add(subList, pAuxElemento);
                }
            }
        }
    }
    return subList;
}

/**
 * \brief : Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 * \param : LinkedList* this
 * \return: retorna un nuevo linkedlist*, o NULL si no cumple las condiciones.
**/
LinkedList* ll_clone(LinkedList* this) {

    LinkedList* cloneList = NULL;

    if(this != NULL) {

        cloneList = ll_subList(this, 0, ll_len(this));
    }
    return cloneList;
}

/**
 * \brief : acumula la cantidad de elementos que cumplen con el critero pasado por la funcion que recibe como paramentro.
 * \param : LinkedList* this, int (*fn)(void* element)
 * \return: retorna acumulador.
**/
int ll_count(LinkedList* this, int (*fn)(void* element)){

	int acumulador = 0;
    void* pAuxElemento;
    int longitudThis;

    if(this!=NULL){

    	longitudThis = ll_len(this);

        for(int i = 0; i < longitudThis; i++){

        	pAuxElemento = ll_get(this, i);

        	if(pAuxElemento != NULL){

        		acumulador += fn(pAuxElemento);
        	}
        }
    }
	return acumulador;
}

/**
 * \brief : crea una listra filtrada segun el critero de la funcion pasada por parametro.
 * \param : LinkedList* this, int (*fn)(void* element)
 * \return: retorna nueva LinkedList* o LinkedList* NULL.
**/
LinkedList* ll_filter(LinkedList* this, int (*fn)(void* element)){

    LinkedList* filterList = NULL;
    int lenList;
    void* auxElement;

    if(this != NULL && fn != NULL){

        filterList = ll_newLinkedList();
        lenList = ll_len(this);

        if(filterList != NULL && lenList > 0){

        	for(int i = 0; i < lenList; i++){

            auxElement = ll_get(this,i);

            	if(auxElement != NULL && fn(auxElement) == 1){

            		ll_add(filterList, auxElement);
            	}
        	}
        }
    }
    return filterList;
}

/**
 * \brief : Modifica todos los elementos que cumplan con la funcion pasada por parametro.
 * \param : LinkedList* this, void (*fn)(void* element)
 * \return: retorna la misma LinkedList* con o sin los cambios realizados.
**/
LinkedList* ll_map(LinkedList* this, void (*fn)(void* element)){

    int lenList;
    void *auxElement;

    if(this != NULL && fn != NULL){

        lenList=ll_len(this);//INDEX DE ULTIMO ELEMENTO VA A SER MENOR AL TOTAL DE LOS ELEMENTOS.N-1

        if(lenList > 0){

        	for(int i = 0; i < lenList; i++){

            auxElement = ll_get(this,i);

            	if(auxElement != NULL){

            		fn(auxElement);
            	}
        	}
        }
    }
    return this;
}
