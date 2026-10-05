//
// Created by almar on 05/10/2026.
//

#ifndef PRACTICA2_EEDD_LISTADE_H
#define PRACTICA2_EEDD_LISTADE_H

#include <iostream>
using namespace std;

template<class T>
class ListaDE {

private:

    class Nodo {
    public:
        T dato;
        Nodo *ant,*sig;
        Nodo(const T &dato, Nodo *ant, Nodo *sig):
                dato(dato),ant(ant),sig(sig){}
    };

    Nodo *cabecera;
    Nodo *cola;

public:
    class Iterador {
        Nodo *nodo;
        friend class ListaDE<T>;
    public:
        Iterador(Nodo *nodo): nodo(nodo){}

        bool hayAnterior() {           //Comprobar si existe un nodo anterior
            if (nodo->ant != 0) {
                return true;
            } else {
                return false;
            }
        }

        bool haySiguiente() {               //Comprobar si existe un nodo siguiente
            if (nodo->sig != 0) {
                return true;
            } else {
                return false;
            }
        }

        void anterior() {               //Desplaza el iterador una posicion hacia atrás. Puntero nodo apunta al nodo anterior
            nodo = nodo->ant;
        }

        void siguiente() {              //Desplaza el iterador una posicion hacia delante. Puntero nodo apunta al nodo siguiente
            nodo = nodo->sig;
        }

        T &dato() {                    //Devuelve el contenido del nodo
            return nodo->dato;
        }
    };

    /**
     * @brief Constructor por defecto de una lista doblemente enlazada
     */
    ListaDE<T>():cabecera(0),cola(0){}

    /**
     * Constructor por copia de uan lista doblemente enlazada
     * @param orig
     */
    ListaDE<T>(const ListaDE<T>& orig);

    /**
     * Operador asignacion de lista doblemente enlazada
     * @param lista
     * @return Devuelve la nueva lista tras la asignacion
     */
    ListaDE<T>& operator=(const ListaDE &lista);

    /**
     * @brief Devuelve el primerdato de la lista
     * @return Devuelve el primer dato de la lista
     */
    T& inicio();

    /**
     * @brief Devuelve el ultimo dato de la lista
     * @return Devuelve el ultimo dato de la lsita
     */
    T& fin();

    /**
     * @brief Devuelve un objeto iterador para iterar sobre una lista bidireccionalmente
     * @return Un objeto iterador
     */
    Iterador iterador();

    /**
     * @brief Insertar un dato al principio de una lista
     * @param dato
     */
    void insertaInicio(const T &dato);

    /**
     * @brief Insertar un dato al final de una lista
     * @param dato
     */
    void insertaFin(const T &dato);

    /**
     * @brief Insertar un dato en la posicion anterior apuntada por un iterador
     * @param i
     * @param dato
     */
    void inserta(const Iterador &i,const T &dato);

    /**
     * @brief Borra el primer elemento de la lista
     */
    void borraInicio();

    /**
     * @brief Borra el ultimo elemento de la lista
     */
    void borraFinal();

    /**
     * @brief Borra el elemento de la lista referenciado por un iterador
     * @param i
     */
    void borra(const Iterador &i);

    /**
     * @brief Devuelve de forma eficiente el numero de elementos de la lista
     * @return numero de elementosde la lista
     */
    int tam();


    ListaDE<T> concatena(const ListaDE<T> &lista);      //Devuelve una copia de las dos listas unidas
    ListaDE<T> operator+(const ListaDE<T> &lista);      //A la primera lista le agrego la segunda lista

    /**
     * @brief Destructor de la clase ListaDE
     */
    ~ListaDE();
};

template<typename T>
T& ListaDE<T>::inicio() {
    if (cabecera==nullptr) {
        throw invalid_argument("[ListaDE::inicio]: La lista esta vacia");
    }
    return cabecera->dato;
}

template<typename T>
T& ListaDE<T>::fin() {
    if (cola==nullptr) {
        throw invalid_argument("[ListaDE::fin]: La lista esta vacia");
    }
    return cola->dato;
}

template<typename T>
void ListaDE<T>::insertaInicio(const T& dato) {
    Nodo *p = new Nodo(dato,0,0);

    if (cola==nullptr) {
        cabecera = p;
        cola=p;
    } else {
        p->sig=cabecera;
        cabecera->ant=p;
        cabecera=p;
        p=nullptr;
    }

}

template<typename T>
void ListaDE<T>::insertaFin(const T &dato) {
    Nodo *p = new Nodo(dato,0,0);

    if (cola==nullptr) {
        cabecera = p;
        cola=p;
    } else {
        p->ant=cola;
        cola->sig=p;
        cola=p;
        p=nullptr;
    }
}

template<typename T>
void ListaDE<T>::inserta(const Iterador &i, const T &dato) {
    Nodo *p = new Nodo(dato,0,0);
    if (i.nodo==nullptr) {
        throw invalid_argument("[ListaDE::inserta]: Parametro no valido");
    }
    if (cabecera==nullptr) {
        cabecera=p;
        cola=p;

    } else if (i.nodo==cabecera) {
        cabecera->ant=p;
        p->sig=cabecera;
        cabecera=p;

        } else if (i.nodo==cola) {
            Nodo *t = cola->ant;
            cola->ant=p;
            p->sig=cola;
            p->ant=t;
            t->sig=p;

            } else {
                Nodo *t = i.nodo->ant;
                i.nodo->ant=p;
                p->sig=i.nodo;
                p->ant=t;
                t->sig=p;
            }
}



/*  Metodo borrar,orden corecto
 *if p.nodo!=0 && cabecera !=0
 *  else if Cabecera==cola
 *      else if p.nodo==cabecera
 *          else if p.nodo==cola
 *              else
 */

//
#endif //PRACTICA2_EEDD_LISTADE_H