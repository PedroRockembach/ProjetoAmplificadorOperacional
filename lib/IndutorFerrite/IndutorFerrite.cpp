#include "IndutorFerrite.h"
#include <iostream>
#include <vector>

using namespace std;

string IndutorFerrite::lerCodigo() {
    Entrada entrada;
    string codigoRegistro;
    do {
        codigoRegistro = entrada.lerComMensagem("Codigo: ");
    } while (codigoRegistro.empty());
    return codigoRegistro;
}

double IndutorFerrite::lerIndutancia() {
    UnidadeIndutancia unidade;
    Entrada entrada;
    while (true) {
        ResultadoIndutancia x = unidade.interpretar(entrada.lerComMensagem("Indutancia: "));
        if (x.valido && x.valor > 0)
            return x.valor;
        cout << "Valor invalido.\n";
    }
}

dadosCSV IndutorFerrite::Cadastrar() {
    cout << "\n=== Cadastro Indutor Ferrite ===\n";
    
    codigo = lerCodigo();
    valorH = lerIndutancia();
    
    const vector<string> permitidos = {"Duro", "Macio", "Ferrite"};
    tipoFerrite = solicitarMaterial("Tipo de ferrite (Duro/Macio/Ferrite): ", permitidos);

    double ValorPermeabilidade = solicitarDoubleRange("Permeabilidade relativa (k): ", 10.0, 20000.0);
    permeabilidade = to_string(ValorPermeabilidade);

    double Corrente = solicitarDoubleRange("Corrente de saturacao (A): ", 0.01, 100.0);
    correnteSat = to_string(Corrente);
    
    UnidadeIndutancia unidade;
    dadosCSV dados;
    dados.codigo = codigo;
    dados.tipoComponente = "Indutor";
    dados.modelo = "Ferrite";
    dados.valor = unidade.formatar(valorH);
    dados.atributo1 = tipoFerrite;
    dados.atributo2 = permeabilidade;
    dados.atributo3 = correnteSat;
    
    cout << "[SUCESSO] Indutor Ferrite cadastrado!\n";
    return dados;
}

dadosCSV IndutorFerrite::Mostrar() const {
    UnidadeIndutancia unidade;
    dadosCSV dados;
    dados.codigo = codigo;
    dados.tipoComponente = "Indutor";
    dados.modelo = "Ferrite";
    dados.valor = unidade.formatar(valorH);
    dados.atributo1 = tipoFerrite;
    dados.atributo2 = permeabilidade;
    dados.atributo3 = correnteSat;
    
    cout << "\n--- INDUTOR FERRITE ---\n";
    cout << "Codigo: " << codigo << endl;
    cout << "Indutancia: " << dados.valor << "\n";
    cout << "Tipo de Ferrite: " << tipoFerrite << endl;
    cout << "Permeabilidade: " << permeabilidade << endl;
    cout << "Corrente de Saturacao: " << correnteSat << " A\n";
    
    return dados;
}