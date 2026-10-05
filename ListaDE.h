//
// Created by almar on 05/10/2026.
//

#ifndef PRACTICA2_EEDD_LISTADE_H
#define PRACTICA2_EEDD_LISTADE_H

template<class T>
class ListaDE {
private:
    template<class X>       //Cambiar la letra del template
    class Nodo {            //Meter la clase nodo dentro de la clase listaDE
    public:
        X dato;
        Nodo *ant, *sig;
        Nodo(const X &dato, Nodo *ant, Nodo *sig);
        ~Nodo();
    };
public:
    template<class Y>
    class Iterador {



    };

};


#endif //PRACTICA2_EEDD_LISTADE_H