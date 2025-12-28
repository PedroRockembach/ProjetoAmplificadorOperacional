#include "IndutorToroidal.h"
#include <iostream>
#include <vector>

using namespace std;

string IndutorToroidal::lerCodigo() {
    Entrada entrada;
    string codigoRegistro;
    do {
        codigoRegistro = entrada.lerComMensagem("Codigo: ");
    } while (codigoRegistro.empty());
    return codigoRegistro;
}

double IndutorToroidal::lerIndutancia() {
    UnidadeIndutancia unidade;
    Entrada entrada;
    while (true) {
        ResultadoIndutancia x = unidade.interpretar(entrada.lerComMensagem("Indutancia: "));
        if (x.valido && x.valor > 0)
            return x.valor;
        cout << "Valor invalido.\n";
    }
}

dadosCSV IndutorToroidal::Cadastrar() {
    cout << "\n=== Cadastro Indutor Toroidal ===\n";
    
    codigo = lerCodigo();
    valorH = lerIndutancia();
    
    const vector<string> permitidos = {"Ferrite", "Po de ferro", "Ar"};
    material = solicitarMaterial("Material do nucleo (Ferrite/Po de ferro/Ar): ", permitidos);

    double d = solicitarDoubleRange("Diametro (mm): ", 1.0, 200.0);
    diametro = to_string(d);

    double i = solicitarDoubleRange("Corrente maxima (A): ", 0.01, 100.0);
    corrente = to_string(i);
    
    UnidadeIndutancia unidade;
    dadosCSV dados;
    dados.codigo = codigo;
    dados.tipoComponente = "Indutor";
    dados.modelo = "Toroidal";
    dados.valor = unidade.formatar(valorH);
    dados.atributo1 = material;
    dados.atributo2 = diametro;
    dados.atributo3 = corrente;
    
    cout << "[SUCESSO] Indutor Toroidal cadastrado!\n";
    return dados;
}

dadosCSV IndutorToroidal::Mostrar() const {
    UnidadeIndutancia unidade;
    dadosCSV dados;
    dados.codigo = codigo;
    dados.tipoComponente = "Indutor";
    dados.modelo = "Toroidal";
    dados.valor = unidade.formatar(valorH);
    dados.atributo1 = material;
    dados.atributo2 = diametro;
    dados.atributo3 = corrente;
    
    cout << "\n--- INDUTOR TOROIDAL ---\n";
    cout << "Codigo: " << codigo << endl;
    cout << "Indutancia: " << dados.valor << "\n";
    cout << "Material: " << material << endl;
    cout << "Diametro: " << diametro << " mm\n";
    cout << "Corrente Maxima: " << corrente << " A\n";
    
    return dados;
}