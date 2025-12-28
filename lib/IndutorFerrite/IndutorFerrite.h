#ifndef INDUTORFERRITE_H
#define INDUTORFERRITE_H

#include "../Indutor/Indutor.h"
#include "../IndutorEntrada/Entrada.h"
#include "../UnidadeIndutancia/UnidadeIndutancia.h"
#include "../Dados.h"

class IndutorFerrite : public Indutor {
private:
    string codigo;
    double valorH;
    string tipoFerrite;
    string permeabilidade;
    string correnteSat;

    string lerCodigo();
    double lerIndutancia();

public:
    dadosCSV Cadastrar() override;
    dadosCSV Mostrar() const override;
};
#endif