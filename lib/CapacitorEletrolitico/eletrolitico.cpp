#include "Eletrolitico.h"
#include "../Validador/Validador.h"
#include <iostream>
#include <algorithm>    
#include <cctype>    
using namespace std;

Eletrolitico::Eletrolitico() {
    tipoComponente = "Capacitor";
    modelo = "Eletrolitico";
    polarizado = "Nao";
}

Eletrolitico::~Eletrolitico() {
}

dadosCSV Eletrolitico::Cadastrar() {
    dadosCSV dados;
    
    cout << "\n=== Cadastro Capacitor Eletrolitico ===\n";

    // Validar Codigo
    while (true) {
        cout << "Codigo: ";
        getline(cin, codigo);
        if (Validador::validarCodigoNaoVazio(codigo)) break;
    }

    // Validar Capacitancia
    while (true) {
        cout << "Capacitancia (uF): ";
        getline(cin, capacitancia);
        if (Validador::validarNumeroPositivo(capacitancia)) break;
    }

    // Validar Tensao
    while (true) {
        cout << "Tensao (V): ";
        getline(cin, tensao);
        if (Validador::validarNumeroPositivo(tensao)) break;
    }

    // Validar Temperatura
    while (true) {
        cout << "Temperatura (°C): ";
        getline(cin, temperatura);
        if (Validador::validarNumeroPositivo(temperatura)) break;
    }

    // Validar Polarizado
    while (true) {
        cout << "E polarizado? (Sim/Nao): ";
        getline(cin, polarizado);
        string polar_lower = polarizado;
        transform(polar_lower.begin(), polar_lower.end(), polar_lower.begin(), ::tolower);
        
        if (polar_lower == "sim" || polar_lower == "s") {
            polarizado = "Sim";
            break;
        } else if (polar_lower == "nao" || polar_lower == "n") {
            polarizado = "Nao";
            break;
        } else {
            cout << "[ERRO] Digite 'Sim' ou 'Nao'.\n";
        }
    }

    dados.codigo = codigo;
    dados.tipoComponente = tipoComponente;
    dados.modelo = modelo;
    dados.valor = capacitancia;
    dados.atributo1 = tensao;
    dados.atributo2 = temperatura;
    dados.atributo3 = polarizado;

    cout << "[SUCESSO] Capacitor Eletrolitico cadastrado!\n";
    return dados;
}

dadosCSV Eletrolitico::Mostrar() const {
    dadosCSV dados;
    dados.codigo = codigo;
    dados.tipoComponente = tipoComponente;
    dados.modelo = modelo;
    dados.valor = capacitancia;
    dados.atributo1 = tensao;
    dados.atributo2 = temperatura;
    dados.atributo3 = polarizado;

    cout << "\n--- CAPACITOR ELETROLITICO ---\n";
    cout << "Codigo: " << codigo << endl;
    cout << "Capacitancia: " << capacitancia << " uF\n";
    cout << "Tensao: " << tensao << " V\n";
    cout << "Temperatura: " << temperatura << " °C\n";
    cout << "Polarizado: " << polarizado << endl;

    return dados;
}