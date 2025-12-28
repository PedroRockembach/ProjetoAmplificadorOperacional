#include "Tantalum.h"
#include "../Validador/Validador.h"
#include <iostream>

using namespace std;

Tantalum::Tantalum() {
    tipoComponente = "Capacitor";
    modelo = "Tantalum";
}

Tantalum::~Tantalum() {
}

dadosCSV Tantalum::Cadastrar() {
    dadosCSV dados;
    
    cout << "\n=== Cadastro Capacitor de Tantalo ===\n";

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

    // Validar Encapsulamento
    while (true) {
        cout << "Encapsulamento: ";
        getline(cin, encapsulamento);
        if (Validador::validarCampoNaoVazio(encapsulamento, "Encapsulamento")) break;
    }

    dados.codigo = codigo;
    dados.tipoComponente = tipoComponente;
    dados.modelo = modelo;
    dados.valor = capacitancia;
    dados.atributo1 = tensao;
    dados.atributo2 = temperatura;
    dados.atributo3 = encapsulamento;

    cout << "[SUCESSO] Capacitor de Tantalo cadastrado!\n";
    return dados;
}

dadosCSV Tantalum::Mostrar() const {
    dadosCSV dados;
    dados.codigo = codigo;
    dados.tipoComponente = tipoComponente;
    dados.modelo = modelo;
    dados.valor = capacitancia;
    dados.atributo1 = tensao;
    dados.atributo2 = temperatura;
    dados.atributo3 = encapsulamento;

    cout << "\n--- CAPACITOR DE TANTALO ---\n";
    cout << "Codigo: " << codigo << endl;
    cout << "Capacitancia: " << capacitancia << " uF\n";
    cout << "Tensao: " << tensao << " V\n";
    cout << "Temperatura: " << temperatura << " °C\n";
    cout << "Encapsulamento: " << encapsulamento << endl;

    return dados;
}