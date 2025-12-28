#ifndef INDUTORTOROIDAL_H
#define INDUTORTOROIDAL_H

#include "../Indutor/Indutor.h"
#include "../IndutorEntrada/Entrada.h"
#include "../UnidadeIndutancia/UnidadeIndutancia.h"
#include "../Dados.h"

class IndutorToroidal : public Indutor {
private:
    string codigo;
    double valorH;
    string material;
    string diametro;
    string corrente;

    string lerCodigo();
    double lerIndutancia();

public:
    dadosCSV Cadastrar() override;
    dadosCSV Mostrar() const override;
};

#endif