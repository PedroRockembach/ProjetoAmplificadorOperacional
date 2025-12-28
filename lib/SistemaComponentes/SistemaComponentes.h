#ifndef SISTEMA_COMPONENTES_H
#define SISTEMA_COMPONENTES_H

#include "../GerenciadorComponentes/GerenciadorComponentes.h"
#include "../ExibidorComponente/ExibidorComponente.h"
#include <iostream>
#include <limits>

using namespace std;

class SistemaComponentes {
    private:
        GerenciadorComponentes gerenciador;
        ExibidorComponente exibidor;
        
        void menuAmplificadores();
        void menuDisplays();
        void menuCapacitores();
        void menuIndutores();
        void menuCRUD();
        void exibirMenuPrincipal();
        void exibirMenuAmplificadores();
        void exibirMenuDisplays();
        void exibirMenuCapacitores();
        void exibirMenuIndutores();
        void exibirMenuCRUD();
        
    public:
        SistemaComponentes();
        ~SistemaComponentes();
        
        void executar();
};

#endif