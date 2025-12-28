#ifndef INDUTOR_H
#define INDUTOR_H

#include "../Dados.h"
#include <string>
#include <vector>

using namespace std;

class Indutor {
public:
    virtual ~Indutor() {}
    virtual dadosCSV Cadastrar() = 0;
    virtual dadosCSV Mostrar() const = 0;
    
protected:
    string solicitarString(const string &mensagem, int tamanhoMinimo = 1);
    int solicitarIntRange(const string &mensagem, int minVal, int maxVal);
    double solicitarDoubleRange(const string &mensagem, double minVal, double maxVal);
    string solicitarMaterial(const string &mensagem, const vector<string> &permitidos);
};

#endif