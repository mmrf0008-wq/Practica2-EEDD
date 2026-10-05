//
// Created by Maitena on 19/9/2026.
//

#ifndef ESPECIE_H
#define ESPECIE_H
#include <string>
#include <VDinamico.h>

using namespace std;

class Especie {
private:
	string codigoEspecie;
	string nombreComun;
	string nombreCientifico;
	string tipoPlanta;

public:
	/**
	 *
	 * @return
	 */
	string get_codigo_especie() const;

	/**
	 *
	 * @param codigo_especie
	 */
	void set_codigo_especie(const string &codigo_especie);
	
	string get_nombre_comun() const;

	void set_nombre_comun(const string &nombre_comun);

	string get_nombre_cientifico() const;

	void set_nombre_cientifico(const string &nombre_cientifico);

	string get_tipo_planta() const;

	void set_tipo_planta(const string &tipo_planta);

	bool operator==(const Especie &arr);
	bool operator<(const Especie &arr);


	Especie(const string &cod, const string &nombreComun, const string &nombreCientifico, const string &tipoPlanta);

	Especie();

	void mostrarInfo();



};



#endif //ESPECIE_H
