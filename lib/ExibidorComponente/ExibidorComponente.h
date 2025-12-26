#ifndef EXIBIDOR_COMPONENTE_H
#define EXIBIDOR_COMPONENTE_H

#include "../Dados.h"
#include <iostream>

using namespace std;

class ExibidorComponente {
    private:
        void exibirLinha();
        void exibirCabecalho();
        void exibirDetalhes(dadosCSV dados);

    public:
        ExibidorComponente();
        ~ExibidorComponente();
        void exibir(dadosCSV dados);
};

#endif