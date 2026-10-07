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

template<class T>
ListaDE<T>::ListaDE(const ListaDE<T> &orig) {       //Comprobamos si la lista está vacía
    if (orig.cabecera == nullptr) {
        this->cabecera = nullptr;
        this->cola = nullptr;

    } else if (orig.cabecera == orig.cola) {            //Comprobamos si hay un solo elemento en la lista
        this->cabecera = new Nodo(orig.cabecera->dato,0,0);
        this->cola = cabecera;

    } else {
        this->cabecera = new Nodo(orig.cabecera->dato,0,0);
        this->cola = cabecera;
        Iterador i = orig.cabecera->sig;

        while (i.haySiguiente()) {      //La condicion deja fuera al ultimo dato
            insertaFin(i.dato());
            i.siguiente();
        }
        insertaFin(i.dato());       //El ultmo dato hay que hacerlo aparte
    }
}

template<class T>
ListaDE<T> &ListaDE<T>::operator=(const ListaDE &lista) {
    if (this != &lista) {
        while (this->cola != nullptr) {       //Borramos toda la lista que queremos sustituir
            this->borraInicio();
        }

        if (lista.cabecera == nullptr) {
            this->cabecera = nullptr;
            this->cola = nullptr;

        } else if (lista.cabecera == lista.cola) {            //Comprobamos si hay un solo elemento en la lista
            this->cabecera = new Nodo(lista.cabecera->dato,0,0);
            this->cola = cabecera;

        } else {
            this->cabecera = new Nodo(lista.cabecera->dato,0,0);
            this->cola = cabecera;
            Iterador i = lista.cabecera->sig;

            while (i.haySiguiente()) {      //La condicion deja fuera al ultimo dato
                insertaFin(i.dato());
                i.siguiente();
            }
            insertaFin(i.dato());       //El ultmo dato hay que hacerlo aparte
        }

    }
    return *this;
}

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

    if (cola==nullptr) {        //Comprobar si la lista esta vacia
        cabecera = p;
        cola=p;
    } else {                    //Insertar por la cabecera
        p->sig=cabecera;
        cabecera->ant=p;
        cabecera=p;
        p=nullptr;
    }

}

template<typename T>
void ListaDE<T>::insertaFin(const T &dato) {
    Nodo *p = new Nodo(dato,0,0);

    if (cola==nullptr) {       //Comprobar si la lista esta vacia
        cabecera = p;
        cola=p;
    } else {                   //Insertar por la cola
        p->ant=cola;
        cola->sig=p;
        cola=p;
    }
}

template<typename T>
void ListaDE<T>::inserta(const Iterador &i, const T &dato) {
    if (i.nodo==nullptr) {
        throw invalid_argument("[ListaDE::inserta]: Parametro no valido");
    }
    Nodo *p = new Nodo(dato,0,0);
    if (cabecera==nullptr) {            //Comprobar si la lista esta vacia
        cabecera=p;
        cola=p;

    } else if (i.nodo==cabecera) {      //Comprobar si el iterador apunta a la cabecera
        cabecera->ant=p;
        p->sig=cabecera;
        cabecera=p;

        } else if (i.nodo==cola) {      //Comprobar si el iterador apunta a la cola
            Nodo *t = cola->ant;
            cola->ant=p;
            p->sig=cola;
            p->ant=t;
            t->sig=p;

            } else {                    //Posicion intermedia en lista con varios elementos
                Nodo *t = i.nodo->ant;
                i.nodo->ant=p;
                p->sig=i.nodo;
                p->ant=t;
                t->sig=p;
            }
}

template<typename T>
void ListaDE<T>::borraInicio() {
    if (cabecera == nullptr) {      //Comprobamos si la lista esta vacia
        throw out_of_range("[ListaDE::borraInicio]: No hay elementos para borrar en la lista");
    }

    Nodo *p = cabecera;
    if (cabecera==cola) {           //Comprobamos si solo hay un elemento en la lista
        cabecera=nullptr;
        cola=nullptr;

    } else {                        //Hay mas de un elemento en la lista
        cabecera=cabecera->sig;
        cabecera->ant=nullptr;
    }

    delete p;
}

template<typename T>
void ListaDE<T>::borraFinal() {
    if (cabecera == nullptr) {      //Comprobamos si la lista esta vacia
        throw out_of_range("[ListaDE::borraFinal]: No hay elementos para borrar en la lista");
    }

    Nodo *p = cola;
    if (cabecera == cola) {         //Comprobamos si solo hay un elemento en la lista
        cabecera=nullptr;
        cola=nullptr;

    } else {                        //Hay mas de un elemento en la lista
        cola=cola->ant;
        cola->sig=nullptr;
    }

    delete p;
}

template<class T>
void ListaDE<T>::borra(const Iterador &i) {
    if (i.nodo == nullptr) {        //Comprobamos que el iterador apunte a un nodo
        throw invalid_argument("[ListaDE::borra]: No hay elementos para borrar en la lista");
    }
    if (cabecera == nullptr) {      //Comprobamos si la lista esta vacia
        throw out_of_range("[ListaDE::borra]: Iterador invalido");
    }

    Nodo *p = i.nodo->sig;
    Nodo *t = i.nodo->ant;
    if (cabecera == cola) {         //Comprobamos si solo hay un elemento en la lista
        cabecera = nullptr;
        cola = nullptr;

    } else if (i.nodo == cabecera) {
        cabecera=p;
        cabecera->ant=nullptr;

    } else if (i.nodo == cola) {
        cola = t;
        cola->sig = nullptr;

    } else {
        t->sig = p;
        p->ant = t;
    }

    delete i.nodo;
}

template<class T>
int ListaDE<T>::tam() {
    int num=0;
    if (cabecera != nullptr) {          //Comprobar si la lista está vacía
        Iterador i = cabecera;

        while (i.haySiguiente() != nullptr) {
            i.siguiente();
            num++;
        }
        num++;
    }
    return num;
}

template<class T>
ListaDE<T>::~ListaDE() {
    while (cabecera != nullptr) {
        borraFinal();
    }
}

template<class T>
ListaDE<T> ListaDE<T>::operator+(const ListaDE<T> &lista) {
    ListaDE<T> listaNueva(*this);                       //Creamos una lista nueva por copia que contenga a la primera
    Iterador i = lista.cabecera;
    while (i.nodo != nullptr) {                 //Añadimos a esta nueva lista, la segunda
        listaNueva.insertaFin(i.dato());
        i.siguiente();
    }
    return listaNueva;     //Devolvemos una nueva lista con los contenidos tanto de la primera como de la segunda juntos
}

template<class T>
ListaDE<T> ListaDE<T>::concatena(const ListaDE<T> &lista) {     //Es lo mismo que un += (this = this + lista)
    //Se modifica la lista this
    //Con la otra no se que leches hay q hacer
    //No se si se devuelve la lista this o qué
}

#endif //PRACTICA2_EEDD_LISTADE_H