#ifndef INDUTORBOBINAAR_H
#define INDUTORBOBINAAR_H

#include "../Indutor/Indutor.h"
#include "../IndutorEntrada/Entrada.h"
#include "../UnidadeIndutancia/UnidadeIndutancia.h"
#include "../Dados.h"

class IndutorBobinaAr : public Indutor {
private:
    string codigo;
    double valorH;
    string espiras;
    string diametroFio;
    string comprimento;

    string lerCodigo();
    double lerIndutancia();

public:
    dadosCSV Cadastrar() override;
    dadosCSV Mostrar() const override;
};

#endif