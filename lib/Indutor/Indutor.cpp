#include "Indutor.h"
#include "../IndutorEntrada/Entrada.h"
#include "../Validador/Validador.h"
#include <iostream>
#include <algorithm>
#include <cctype>

using namespace std;

string Indutor::solicitarString(const string &mensagem, int tamanhoMinimo) {
    Entrada entrada;
    while (true) {
        string s = entrada.lerComMensagem(mensagem);
        if (s.empty()) {
            cout << "Campo nao pode ficar vazio\n";
            continue;
        }
        if (static_cast<int>(s.size()) < tamanhoMinimo) {
            cout << "Minimo de " << tamanhoMinimo << " caracteres\n";
            continue;
        }
        return s;
    }
}

int Indutor::solicitarIntRange(const string &mensagem, int minVal, int maxVal) {
    Entrada entrada;
    while (true) {
        string s = entrada.lerComMensagem(mensagem);
        try {
            int v = stoi(s);
            if (v < minVal || v > maxVal) {
                cout << "Valor fora da faixa (" << minVal << " a " << maxVal << ")!\n";
                continue;
            }
            return v;
        } catch (...) {
            cout << "Digite um numero inteiro valido\n";
        }
    }
}

double Indutor::solicitarDoubleRange(const string &mensagem, double minVal, double maxVal) {
    Entrada entrada;
    while (true) {
        string s = entrada.lerComMensagem(mensagem);
        try {
            double v = stod(s);
            if (v < minVal || v > maxVal) {
                cout << "Valor fora da faixa (" << minVal << " a " << maxVal << ")!\n";
                continue;
            }
            return v;
        } catch (...) {
            cout << "Digite um numero decimal valido\n";
        }
    }
}

string Indutor::solicitarMaterial(const string &mensagem, const vector<string> &permitidos) {
    Entrada entrada;
    while (true) {
        string s = entrada.lerComMensagem(mensagem);
        string sl = s;
        transform(sl.begin(), sl.end(), sl.begin(), [](unsigned char c){ return tolower(c); });
        for (const auto &p : permitidos) {
            string pl = p;
            transform(pl.begin(), pl.end(), pl.begin(), [](unsigned char c){ return tolower(c); });
            if (sl == pl) return p;
        }
        cout << "Material invalido. Opcoes: ";
        for (size_t i = 0; i < permitidos.size(); ++i) {
            cout << permitidos[i];
            if (i + 1 < permitidos.size()) cout << ", ";
        }
        cout << ".\n";
    }
}