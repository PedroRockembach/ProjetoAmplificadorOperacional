#include "Validador.h"

bool Validador::validarCodigoNaoVazio(string codigo) {
    if (codigo.empty()) {
        cout << "[ERRO] Codigo nao pode ser vazio!\n";
        return false;
    }
    if (codigo.length() < 3) {
        cout << "[ERRO] Codigo deve ter no minimo 3 caracteres!\n";
        return false;
    }
    return true;
}

bool Validador::validarNumeroPositivo(string valor) {
    if (valor.empty()) {
        cout << "[ERRO] Valor nao pode ser vazio!\n";
        return false;
    }
    
    try {
        double num = stod(valor);
        if (num <= 0) {
            cout << "[ERRO] Valor deve ser positivo!\n";
            return false;
        }
        return true;
    } catch (...) {
        cout << "[ERRO] Valor deve ser um numero valido!\n";
        return false;
    }
}

bool Validador::validarCampoNaoVazio(string campo, string nome) {
    if (campo.empty()) {
        cout << "[ERRO] " << nome << " nao pode ser vazio!\n";
        return false;
    }
    return true;
}

bool Validador::validarIntervalo(double valor, double minimo, double maximo) {
    if (valor < minimo || valor > maximo) {
        cout << "[ERRO] Valor deve estar entre " << minimo << " e " << maximo << "!\n";
        return false;
    }
    return true;
}