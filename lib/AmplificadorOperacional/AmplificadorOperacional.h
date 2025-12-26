#ifndef AMPLIFICADOR_OPERACIONAL_H
#define AMPLIFICADOR_OPERACIONAL_H

#include <string>
#include "../Dados.h" 

using namespace std;

class AmplificadorOperacional {
    protected:
        string codigo;
        string tipoComponente;
        string modelo;
        string valor;           
        string bandaPassante;   
        string impedanciaEntrada; 
        string tensaoOffSet;    

    public:
        AmplificadorOperacional();
        virtual ~AmplificadorOperacional();

        virtual dadosCSV Cadastrar() = 0;
        virtual dadosCSV Mostrar() = 0;
};

#endif