#include "Ceramico.h"
#include "../Validador/Validador.h"
#include <iostream>

using namespace std;

Ceramico::Ceramico() {
    tipoComponente = "Capacitor";
    modelo = "Ceramico";
}

Ceramico::~Ceramico() {
}

dadosCSV Ceramico::Cadastrar() {
    dadosCSV dados;
    
    cout << "\n=== Cadastro Capacitor Ceramico ===\n";

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

    // Validar Dieletrico
    while (true) {
        cout << "Tipo de dieletrico: ";
        getline(cin, dieletrico);
        if (Validador::validarCampoNaoVazio(dieletrico, "Dieletrico")) break;
    }

    dados.codigo = codigo;
    dados.tipoComponente = tipoComponente;
    dados.modelo = modelo;
    dados.valor = capacitancia;
    dados.atributo1 = tensao;
    dados.atributo2 = temperatura;
    dados.atributo3 = dieletrico;

    cout << "[SUCESSO] Capacitor Ceramico cadastrado!\n";
    return dados;
}

dadosCSV Ceramico::Mostrar() const {
    dadosCSV dados;
    dados.codigo = codigo;
    dados.tipoComponente = tipoComponente;
    dados.modelo = modelo;
    dados.valor = capacitancia;
    dados.atributo1 = tensao;
    dados.atributo2 = temperatura;
    dados.atributo3 = dieletrico;

    cout << "\n--- CAPACITOR CERAMICO ---\n";
    cout << "Codigo: " << codigo << endl;
    cout << "Capacitancia: " << capacitancia << " uF\n";
    cout << "Tensao: " << tensao << " V\n";
    cout << "Temperatura: " << temperatura << " °C\n";
    cout << "Dieletrico: " << dieletrico << endl;

    return dados;
}