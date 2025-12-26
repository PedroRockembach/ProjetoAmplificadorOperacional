#include "ExibidorComponente.h"

ExibidorComponente::ExibidorComponente() {
    // Construtor
}

ExibidorComponente::~ExibidorComponente() {
    // Destrutor
}

void ExibidorComponente::exibirLinha() {
    cout << "===================================================\n";
}

void ExibidorComponente::exibirCabecalho() {
    exibirLinha();
    cout << "     DETALHES DO COMPONENTE CADASTRADO             \n";
    exibirLinha();
}

void ExibidorComponente::exibirDetalhes(dadosCSV dados) {
    cout << "Codigo:    " << dados.codigo << endl;
    cout << "Tipo:      " << dados.tipoComponente << endl;
    cout << "Modelo:    " << dados.modelo << endl;
    cout << "Valor:     " << dados.valor << endl;
    cout << "---------------------------------------------------\n";
    cout << "Atributo 1 (Banda Passante):      " << dados.atributo1 << endl;
    cout << "Atributo 2 (Impedancia Entrada):  " << dados.atributo2 << endl;
    cout << "Atributo 3 (Tensao Offset):       " << dados.atributo3 << endl;
    cout << "---------------------------------------------------\n";
}

void ExibidorComponente::exibir(dadosCSV dados) {
    exibirCabecalho();
    exibirDetalhes(dados);
    exibirLinha();
}