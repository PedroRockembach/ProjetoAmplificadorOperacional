#ifndef AMPLIFICADOR_DIFERENCIAL_H
#define AMPLIFICADOR_DIFERENCIAL_H

#include "../Dados.h"
#include "../AmplificadorOperacional/AmplificadorOperacional.h"

class AmplificadorDiferencial : public AmplificadorOperacional {
    public:
        AmplificadorDiferencial();
        ~AmplificadorDiferencial();
        dadosCSV Cadastrar();
        dadosCSV Mostrar();
};

#endif