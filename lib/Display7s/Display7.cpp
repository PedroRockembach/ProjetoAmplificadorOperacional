#include "Display7.h"
#include <iostream>
#include <limits>
#include <algorithm> 
#include <cctype>
#include <string>

using namespace std;

Display7::Display7() {
    dados.modelo = "SeteSegmentos";
}

Display7::~Display7() {
}

int Display7::obterCodigo() {
    int codigo;
    bool entradaValida = false;
    while (!entradaValida) {
        cout << "\nCodigo (Apenas numeros inteiros positivos. Digite '0' para CANCELAR o cadastro): ";
        if (cin >> codigo) {
            if (codigo == 0) {
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                return 0; 
            }
            if (codigo > 0) {
                entradaValida = true; 
            } else {
                cout << "ERRO: O codigo deve ser um numero positivo." << endl;
            }
        } else {
            cout << "ERRO: Entrada invalida. Por favor, digite apenas numeros." << endl;
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
        }
    }
    cin.ignore(numeric_limits<streamsize>::max(),'\n'); 
    return codigo; 
}

double Display7::obterValor() {
    double valor;
    while (true) {
        cout << "\nValor (Geralmente 0.0 para displays. Digite '-1' para CANCELAR o cadastro): ";
        if (cin >> valor) {
            if (valor == -1.0) {
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                return -1.0; 
            }
            if (valor >= 0.0) {
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                return valor; 
            } else {
                cout << "ERRO: O Valor deve ser um numero nao negativo." << endl;
            }
        } else {
            cout << "ERRO: Entrada invalida. Por favor, digite apenas numeros." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
        }
    }
}

std::string Display7::obterPadrao(){
    string padrao;
    while (true) {
        cout << "\nPadrao (Anodo Comum ou Catodo Comum. Digite 'C' para CANCELAR o cadastro): ";
        getline(cin, padrao);
        string padrao_lower = padrao;
        transform(padrao_lower.begin(), padrao_lower.end(), padrao_lower.begin(), ::tolower);

        if (padrao_lower == "c") return ""; 
        
        if (padrao_lower.find("anodo") != string::npos) return "Anodo Comum"; 
        else if (padrao_lower.find("catodo") != string::npos) return "Catodo Comum";
        else cout << "ERRO: Padrao invalido. Digite 'Anodo Comum' ou 'Catodo Comum'." << endl;
    }
}

std::string Display7::obterCor(){
    string cor;
    while (true) {
        cout << "\nCor (Ex: Vermelho, Verde, Amarelo. Digite 'C' para CANCELAR o cadastro): ";
        getline(cin, cor);
        string cor_lower = cor;
        transform(cor_lower.begin(), cor_lower.end(), cor_lower.begin(), ::tolower);

        if (cor_lower == "c") return "";

        if (!cor.empty() && cor.find_first_not_of(" ") != string::npos) return cor; 
        else cout << "ERRO: Cor nao pode ser vazia." << endl;
    }
}

std::string Display7::obterDigitos(){
    int num_digitos;
    while (true) {
        cout << "\nNumero de Digitos (Ex: 1, 2, 4. Digite '0' para CANCELAR o cadastro): ";
        if (cin >> num_digitos) {
            if (num_digitos == 0) {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                return ""; 
            }
            if (num_digitos > 0) {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                return to_string(num_digitos); 
            } else {
                cout << "ERRO: O numero de Digitos deve ser positivo." << endl;
            }
        } else {
            cout << "ERRO: Entrada invalida. Por favor, digite apenas numeros inteiros." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

dadosCSV Display7::Cadastrar() {
    cout << "\n === Cadastro de Display de Sete Segmentos ===" << endl;

    int codigoTemp = obterCodigo(); 
    if (codigoTemp <= 0) { 
        cout << "Cadastro de Display Sete Segmentos cancelado." << endl;
        dados.codigo = "";
        return dados; 
    } 
    dados.codigo = to_string(codigoTemp);

    double valorTemp = obterValor(); 
    if (valorTemp < 0.0) { 
        cout << "Cadastro de Display Sete Segmentos cancelado." << endl;
        dados.codigo = "";
        return dados; 
    }
    dados.valor = to_string(valorTemp);
    
    dados.tipoComponente = "Display"; 
    dados.modelo = "SeteSegmentos"; 
    
    dados.atributo1 = obterPadrao(); 
    if (dados.atributo1.empty()) { 
        cout << "Cadastro de Display Sete Segmentos cancelado." << endl;
        dados.codigo = "";
        return dados; 
    } 
    
    dados.atributo2 = obterCor();
    if (dados.atributo2.empty()) { 
        cout << "Cadastro de Display Sete Segmentos cancelado." << endl;
        dados.codigo = "";
        return dados; 
    } 
    
    dados.atributo3 = obterDigitos();
    if (dados.atributo3.empty()) { 
        cout << "Cadastro de Display Sete Segmentos cancelado." << endl;
        dados.codigo = "";
        return dados; 
    } 
    
    cout << "Display de Sete Segmentos cadastrado com sucesso!" << endl;
    return dados;
}

dadosCSV Display7::Mostrar(){
    cout << "\n---DADOS DO DISPLAY SETE SEGMENTOS CADASTRADO---" << endl;
    cout << " Codigo: " << dados.codigo << endl;
    cout << " Tipo: " << dados.tipoComponente << endl;
    cout << " Modelo: " << dados.modelo << endl;
    cout << " Tensao de Operacao: " << dados.valor << " Volts" << endl;
    cout << " Padrao: " << dados.atributo1 << endl;
    cout << " Cor: " << dados.atributo2 << endl;
    cout << " Digitos: " << dados.atributo3 << endl;
    cout << "-----------------------------------------" << endl; 
    
    return dados;
}