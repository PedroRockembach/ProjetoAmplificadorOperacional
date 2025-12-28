#ifndef ELETROLITICO_H
#define ELETROLITICO_H

#include "../Capacitor/Capacitor.h"
#include "../Dados.h"

class Eletrolitico : public Capacitor {
private:
    string polarizado;

public:
    Eletrolitico();
    ~Eletrolitico();

    dadosCSV Cadastrar() override;
    dadosCSV Mostrar() const override;
};

#endif