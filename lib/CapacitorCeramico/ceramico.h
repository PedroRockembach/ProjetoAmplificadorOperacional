#ifndef CERAMICO_H
#define CERAMICO_H

#include "../Capacitor/Capacitor.h"
#include "../Dados.h"

class Ceramico : public Capacitor {
private:
    string dieletrico;

public:
    Ceramico();
    ~Ceramico();

    dadosCSV Cadastrar() override;
    dadosCSV Mostrar() const override;
};

#endif