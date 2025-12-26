#ifndef AMPLIFICADOR_INVERSOR_H
#define AMPLIFICADOR_INVERSOR_H

#include "../Dados.h"
#include "../AmplificadorOperacional/AmplificadorOperacional.h"

class AmplificadorInversor : public AmplificadorOperacional {
    public:
        AmplificadorInversor();
        ~AmplificadorInversor();
        dadosCSV Cadastrar();
        dadosCSV Mostrar();
};

#endif