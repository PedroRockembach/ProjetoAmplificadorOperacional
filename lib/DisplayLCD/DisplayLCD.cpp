#include "DisplayLCD.h"
#include <iostream>
#include <string>
#include <limits> 
#include <algorithm> 
#include <cctype>

using namespace std;

DisplayLCD::DisplayLCD() {
}

DisplayLCD::~DisplayLCD() {
}

int DisplayLCD::obterCodigo() {
    int codigo;
    
    while (true) {
        cout << "\nCodigo (Apenas numeros inteiros positivos. Digite '0' para CANCELAR o cadastro): ";
        
        if (cin >> codigo) {
            
            if (codigo == 0) {
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                return 0;
            }
            
            if (codigo > 0) {
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                return codigo;
            } else {
                cout << "ERRO: O codigo deve ser um numero positivo." << endl;
            }
        
        } else {
            cout << "ERRO: Entrada invalida. Por favor, digite apenas numeros." << endl;
            cin.clear();
        }
        
        cin.ignore(numeric_limits<streamsize>::max(),'\n'); 
    }
}

double DisplayLCD::obterValor() {
    double valor;
    
    while (true) {
        cout << "\nValor (Tensao de operacao em Volts. Digite '-1' para CANCELAR o cadastro): ";
        
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
        }
        
        cin.ignore(numeric_limits<streamsize>::max(),'\n'); 
    }
}

std::string DisplayLCD::obterBacklight(){
    string resp;
    
    while (true) {
        cout << "\nPossui Luz de Fundo (Backlight)? (S/N). Digite 'C' para CANCELAR o cadastro: ";
        getline(cin, resp);

        transform(resp.begin(), resp.end(), resp.begin(), ::toupper);
        
        if (resp == "C") {
            return "";
        }
        
        if (resp == "S" || resp == "SIM") {
            return "Sim"; 
        } else if (resp == "N" || resp == "NAO") {
            return "Nao";
        } else {
            cout << "ERRO: Resposta invalida. Digite 'S' (Sim) ou 'N' (Nao)." << endl;
        }
    }
}

std::string DisplayLCD::obterColunas(){
    int colunas;

    while (true) {
        cout << "\nNumero de Colunas (Ex: 16 ou 20. Digite '0' para CANCELAR o cadastro): ";
        
        if (cin >> colunas) {
            
            if (colunas == 0) {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                return "";
            }
            
            if (colunas > 0) {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                return to_string(colunas);
            } else {
                cout << "ERRO: O numero de Colunas deve ser positivo." << endl;
            }
        
        } else {
            cout << "ERRO: Entrada invalida. Por favor, digite apenas numeros inteiros." << endl;
            cin.clear();
        }
        
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    }
}

std::string DisplayLCD::obterDimensoes(){
    string dimensoes;
    
    while (true) {
        cout << "\nDimensoes (Ex: 16x2, 20x4. Digite 'C' para CANCELAR o cadastro): ";
        getline(cin, dimensoes);
        
        string dim_lower = dimensoes;
        transform(dim_lower.begin(), dim_lower.end(), dim_lower.begin(), ::tolower);

        if (dim_lower == "c") {
            return "";
        }
        
        if (!dimensoes.empty() && dimensoes.find_first_not_of(" ") != string::npos) {
            return dimensoes;
        } else {
            cout << "ERRO: Dimensoes nao podem ser vazias." << endl;
        }
    }
}

dadosCSV DisplayLCD::Cadastrar() {
    cout << "\n === Cadastro de Display LCD ===" << endl;

    int codigoTemp = obterCodigo(); 
    if (codigoTemp == 0) { 
        cout << "Cadastro de Display LCD cancelado." << endl;
        dados.codigo = "";
        return dados; 
    } 
    dados.codigo = to_string(codigoTemp);

    double valorTemp = obterValor(); 
    if (valorTemp == -1.0) { 
        cout << "Cadastro de Display LCD cancelado." << endl;
        dados.codigo = "";
        return dados; 
    }
    dados.valor = to_string(valorTemp);

    dados.tipoComponente = "Display"; 
    dados.modelo = "LCD";

    dados.atributo1 = obterBacklight(); 
    if (dados.atributo1.empty()) { 
        cout << "Cadastro de Display LCD cancelado." << endl;
        dados.codigo = "";
        return dados; 
    } 

    dados.atributo2 = obterColunas();
    if (dados.atributo2.empty()) { 
        cout << "Cadastro de Display LCD cancelado." << endl;
        dados.codigo = "";
        return dados; 
    }

    dados.atributo3 = obterDimensoes();
    if (dados.atributo3.empty()) { 
        cout << "Cadastro de Display LCD cancelado." << endl;
        dados.codigo = "";
        return dados; 
    } 

    cout << "Display LCD cadastrado com sucesso!" << endl;
    return dados;
}

dadosCSV DisplayLCD::Mostrar(){
   cout << "\n---DADOS DO DISPLAY LCD CADASTRADO---" << endl;
   cout << " Codigo: " << dados.codigo << endl;
   cout << " Tipo: " << dados.tipoComponente << endl;
   cout << " Modelo: " << dados.modelo << endl;
   cout << " Tensao de Operacao: " << dados.valor << " Volts" << endl;
   cout << " Backlight: " << dados.atributo1 << endl;
   cout << " Colunas: " << dados.atributo2 << endl;
   cout << " Dimensoes: " << dados.atributo3 << endl;
   cout << "-----------------------------------------" << endl; 
   
    return dados;
}