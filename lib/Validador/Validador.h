#ifndef VALIDADOR_H
#define VALIDADOR_H

#include <string>
#include <iostream>

using namespace std;

class Validador {
    public:
        static bool validarCodigoNaoVazio(string codigo);
        static bool validarNumeroPositivo(string valor);
        static bool validarCampoNaoVazio(string campo, string nome);
        static bool validarIntervalo(double valor, double minimo, double maximo);
};

#endif