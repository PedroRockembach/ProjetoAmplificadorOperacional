#include <iostream>
#include "AmplificadorInversor.h"
#include "../Validador/Validador.h"

AmplificadorInversor::AmplificadorInversor() {
    tipoComponente = "Amplificador Inversor";
    modelo = "Inversor";
}

AmplificadorInversor::~AmplificadorInversor() {
    // Destrutor
}

dadosCSV AmplificadorInversor::Cadastrar() {
    cout << "\n=== Cadastro: Amplificador Inversor ===\n";
    
    // Validar Codigo
    while (true) {
        cout << "Codigo: "; 
        getline(cin, codigo);
        if (Validador::validarCodigoNaoVazio(codigo)) break;
    }
    
    // Validar Ganho (AV)
    while (true) {
        cout << "Ganho (AV): "; 
        getline(cin, valor);
        if (Validador::validarNumeroPositivo(valor)) break;
    }
    
    // Validar Banda Passante
    while (true) {
        cout << "Banda passante (Hz): "; 
        getline(cin, bandaPassante);
        if (Validador::validarNumeroPositivo(bandaPassante)) break;
    }
    
    // Validar Impedância de Entrada
    while (true) {
        cout << "Impedancia de entrada (Ohms): "; 
        getline(cin, impedanciaEntrada);
        if (Validador::validarNumeroPositivo(impedanciaEntrada)) break;
    }
    
    // Validar Tensão de Offset
    while (true) {
        cout << "Tensao de offset (mV): "; 
        getline(cin, tensaoOffSet);
        if (Validador::validarNumeroPositivo(tensaoOffSet)) break;
    }

    return Mostrar();
}

dadosCSV AmplificadorInversor::Mostrar() {
    dadosCSV dados;
    dados.codigo = codigo;
    dados.tipoComponente = tipoComponente;
    dados.modelo = modelo;
    dados.valor = valor;
    dados.atributo1 = bandaPassante;
    dados.atributo2 = impedanciaEntrada;
    dados.atributo3 = tensaoOffSet;
    
    return dados;
}