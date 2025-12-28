#ifndef TANTALUM_H
#define TANTALUM_H

#include "../Capacitor/Capacitor.h"
#include "../Dados.h"

class Tantalum : public Capacitor {
private:
    string encapsulamento;

public:
    Tantalum();
    ~Tantalum();

    dadosCSV Cadastrar() override;
    dadosCSV Mostrar() const override;
};

#endif