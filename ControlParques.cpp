//
// Created by almar on 05/10/2026.
//

#include "ControlParques.h"
#include "LectorCSV.h"

ControlParques::ControlParques(const string &nomFichEspecies, const string &nomFichParques) {
	if(nomFichEspecies.empty() || nomFichParques.empty()) {
		throw invalid_argument("[ControlParques]: parametros no validos ");
	}
	if(!LectorCSV::cargarParques(this->parques, nomFichParques)) {
		throw std::runtime_error("[ControlParques:cargaParques]: error al abrir fichero ");
	}
	if(!LectorCSV::cargarEspecies(this->variantes, nomFichEspecies)) {
		throw std::runtime_error("[ControlParques:cargaEspecies]: error al abrir fichero ");
	}

}

ControlParques::~ControlParques() {
	for(int i =0; i < this->variantes.getLogico(); i++) { //eliminamos las especies
		delete this->variantes[i];
	}
	//la eliminación de parque se gestiona dentro de la clase listaDE
}

void ControlParques::asignarEspecieParque(const Especie &e, const Parque &p) {
	if(e.get_codigo_especie().empty() || p.getCodigoParque()) {
		throw invalid_argument("[ControlParques:asignarEspecieParque] parametro no valido   ");
	}
}

int ControlParques::contarEspecieParque(const string &nombre) {
}

Parque & ControlParques::buscarParque(const string &nombre) {
}

VDinamico<Especie> & ControlParques::listadoEspecieSubNombre(const string &cadena) {
}
