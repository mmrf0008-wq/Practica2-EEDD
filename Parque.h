//
// Created by almar on 05/10/2026.
//

#ifndef PRACTICA2_EEDD_PARQUE_H
#define PRACTICA2_EEDD_PARQUE_H
#include <iostream>
#include "Especie.h"
using namespace std;

class Parque {
private:
    int codigo_parque;
    string nombre_parque;
    VDinamico<Especie*> contenedor;
public:
    Parque();
    Parque(int codigo,const string &nombre);
    ~Parque();

    int getCodigoParque()const;
    void setCodigoParque(int codigo);
    string getNombreParque()const;
    void setNombreParque(const string &nombre);

    void insertarEspecie(const Especie& esp);
    bool existeNComun(const string &nombre);
    bool existeNCientifico(const string &nombre);
};


#endif //PRACTICA2_EEDD_PARQUE_H