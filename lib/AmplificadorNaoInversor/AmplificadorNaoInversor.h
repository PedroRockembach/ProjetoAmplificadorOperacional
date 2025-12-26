#ifndef AMPLIFICADOR_NAO_INVERSOR_H
#define AMPLIFICADOR_NAO_INVERSOR_H

#include "../Dados.h"
#include "../AmplificadorOperacional/AmplificadorOperacional.h"

class AmplificadorNaoInversor : public AmplificadorOperacional {
    public:
        AmplificadorNaoInversor();
        ~AmplificadorNaoInversor();
        dadosCSV Cadastrar();
        dadosCSV Mostrar();
};

#endif