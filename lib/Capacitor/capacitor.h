#ifndef CAPACITOR_H
#define CAPACITOR_H

#include <string>
#include "../Dados.h"

using namespace std;

class Capacitor {
protected:
    string codigo;
    string capacitancia;
    string tensao;
    string temperatura;
    string tipoComponente;
    string modelo;

public:
    Capacitor() : capacitancia("0"), tensao("0"), temperatura("0") {}
    virtual ~Capacitor() {}

    // Métodos polimórficos
    virtual dadosCSV Cadastrar() = 0;
    virtual dadosCSV Mostrar() const = 0;
};

#endif