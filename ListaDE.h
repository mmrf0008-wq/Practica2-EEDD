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
        Nodo(T &dato, Nodo *ant, Nodo *sig):
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

    //No me acuerdo de cual era la diferencia de ambos xd
    ListaDE<T> concatena(const ListaDE<T> &lista);
    ListaDE<T> operator+(const ListaDE<T> &lista);

    /**
     * @brief Destructor de la clase ListaDE
     */
    ~ListaDE();
};



/*  Metodo borrar,orden corecto
 *if p.nodo!=0 && cabecera !=0
 *  else if Cabecera==cola
 *      else if p.nodo==cabecera
 *          else if p.nodo==cola
 *              else
 */

//
#endif //PRACTICA2_EEDD_LISTADE_H