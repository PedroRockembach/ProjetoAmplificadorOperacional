#include <iostream>
#include <limits>
#include <vector> 

#include "lib/AmplificadorOperacional/AmplificadorOperacional.h"
#include "lib/AmplificadorInversor/AmplificadorInversor.h"
#include "lib/AmplificadorNaoInversor/AmplificadorNaoInversor.h"
#include "lib/AmplificadorDiferencial/AmplificadorDiferencial.h"
#include "lib/ExibidorComponente/ExibidorComponente.h"
#include "lib/GerenciadorComponentes/GerenciadorComponentes.h"

using namespace std;

int main() {
    GerenciadorComponentes gerenciador("componentes.csv");
    ExibidorComponente exibidor;
    
    int opcao;
    
    do {
        cout << "\n=== SISTEMA AMPLIFICADORES ===\n";
        cout << "Componentes na memoria: " << gerenciador.obterTamanho() << "\n";
        cout << "------------------------------\n";
        cout << "1. Novo Amplificador Inversor\n";
        cout << "2. Novo Amplificador Nao Inversor\n";
        cout << "3. Novo Amplificador Diferencial\n";
        cout << "4. LISTAR / BUSCAR SALVOS\n";
        cout << "5. EDITAR Componente\n";
        cout << "6. REMOVER Componente\n";
        cout << "7. BUSCAR por Tipo\n";
        cout << "8. BUSCAR por Codigo\n";
        cout << "9. Salvar e Sair\n";
        cout << "0. Sair sem Salvar\n";
        cout << "Opcao: ";
        cin >> opcao;
        
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
        dadosCSV resultado;
        resultado.codigo = ""; 

        switch(opcao) {
            case 1: {
                AmplificadorInversor amp;
                resultado = amp.Cadastrar();
                if (!resultado.codigo.empty()) {
                    gerenciador.adicionar(resultado);
                    cout << "\n[SUCESSO] Componente salvo na memoria na posicao " 
                         << gerenciador.obterTamanho() - 1 << "!\n";
                }
                break;
            }
            case 2: {
                AmplificadorNaoInversor amp;
                resultado = amp.Cadastrar();
                if (!resultado.codigo.empty()) {
                    gerenciador.adicionar(resultado);
                    cout << "\n[SUCESSO] Componente salvo na memoria na posicao " 
                         << gerenciador.obterTamanho() - 1 << "!\n";
                }
                break;
            }
            case 3: {
                AmplificadorDiferencial amp;
                resultado = amp.Cadastrar();
                if (!resultado.codigo.empty()) {
                    gerenciador.adicionar(resultado);
                    cout << "\n[SUCESSO] Componente salvo na memoria na posicao " 
                         << gerenciador.obterTamanho() - 1 << "!\n";
                }
                break;
            }
            case 4: {
                if (gerenciador.obterTamanho() == 0) {
                    cout << ">> Nenhum componente cadastrado ainda!\n";
                } else {
                    cout << "\n--- LISTA DE COMPONENTES ---\n";
                    for (int i = 0; i < gerenciador.obterTamanho(); i++) {
                        dadosCSV comp = gerenciador.obterPorIndice(i);
                        cout << "Indice [" << i << "] - " 
                             << comp.modelo << " (Cod: " 
                             << comp.codigo << ")\n";
                    }
                    
                    int indice;
                    cout << "\nDigite o INDICE para ver detalhes (-1 para voltar): ";
                    cin >> indice;
                    
                    if (indice >= 0 && indice < gerenciador.obterTamanho()) {
                        exibidor.exibir(gerenciador.obterPorIndice(indice));
                    }
                }
                break;
            }
            case 5: {
                if (gerenciador.obterTamanho() == 0) {
                    cout << ">> Nenhum componente para editar!\n";
                } else {
                    cout << "\n--- LISTA DE COMPONENTES ---\n";
                    for (int i = 0; i < gerenciador.obterTamanho(); i++) {
                        dadosCSV comp = gerenciador.obterPorIndice(i);
                        cout << "Indice [" << i << "] - " << comp.modelo << "\n";
                    }
                    
                    int indice;
                    cout << "\nDigite o INDICE para editar: ";
                    cin >> indice;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    
                    if (indice >= 0 && indice < gerenciador.obterTamanho()) {
                        dadosCSV comp = gerenciador.obterPorIndice(indice);
                        cout << "\n=== EDITANDO: " << comp.modelo << " ===\n";
                        cout << "Novo Codigo [" << comp.codigo << "]: ";
                        string novoCodig;
                        getline(cin, novoCodig);
                        if (!novoCodig.empty()) comp.codigo = novoCodig;
                        
                        cout << "Novo Valor [" << comp.valor << "]: ";
                        string novoValor;
                        getline(cin, novoValor);
                        if (!novoValor.empty()) comp.valor = novoValor;
                        
                        cout << "Novo Atributo1 [" << comp.atributo1 << "]: ";
                        string novoAtr1;
                        getline(cin, novoAtr1);
                        if (!novoAtr1.empty()) comp.atributo1 = novoAtr1;
                        
                        cout << "Novo Atributo2 [" << comp.atributo2 << "]: ";
                        string novoAtr2;
                        getline(cin, novoAtr2);
                        if (!novoAtr2.empty()) comp.atributo2 = novoAtr2;
                        
                        cout << "Novo Atributo3 [" << comp.atributo3 << "]: ";
                        string novoAtr3;
                        getline(cin, novoAtr3);
                        if (!novoAtr3.empty()) comp.atributo3 = novoAtr3;
                        
                        gerenciador.editar(indice, comp);
                    }
                }
                break;
            }
            case 6: {
                if (gerenciador.obterTamanho() == 0) {
                    cout << ">> Nenhum componente para remover!\n";
                } else {
                    cout << "\n--- LISTA DE COMPONENTES ---\n";
                    for (int i = 0; i < gerenciador.obterTamanho(); i++) {
                        dadosCSV comp = gerenciador.obterPorIndice(i);
                        cout << "Indice [" << i << "] - " << comp.modelo << "\n";
                    }
                    
                    int indice;
                    cout << "\nDigite o INDICE para remover: ";
                    cin >> indice;
                    
                    gerenciador.remover(indice);
                }
                break;
            }
            case 7: {
                cout << "\nDigite o tipo a buscar (ex: Amplificador Inversor): ";
                string tipo;
                getline(cin, tipo);
                
                vector<dadosCSV> resultados = gerenciador.buscarPorTipo(tipo);
                
                if (resultados.empty()) {
                    cout << "[INFO] Nenhum componente encontrado com tipo: " << tipo << "\n";
                } else {
                    cout << "\n--- RESULTADOS DA BUSCA ---\n";
                    for (size_t i = 0; i < resultados.size(); i++) {
                        cout << "[" << i << "] " << resultados[i].modelo 
                             << " (Cod: " << resultados[i].codigo << ")\n";
                    }
                }
                break;
            }
            case 8: {
                cout << "\nDigite o codigo a buscar: ";
                string codigo;
                getline(cin, codigo);
                
                vector<dadosCSV> resultados = gerenciador.buscarPorCodigo(codigo);
                
                if (resultados.empty()) {
                    cout << "[INFO] Nenhum componente encontrado com codigo: " << codigo << "\n";
                } else {
                    cout << "\n--- RESULTADOS DA BUSCA ---\n";
                    for (size_t i = 0; i < resultados.size(); i++) {
                        exibidor.exibir(resultados[i]);
                    }
                }
                break;
            }
            case 9: {
                gerenciador.salvarEmArquivo();
                cout << "[INFO] Encerrando sistema...\n";
                opcao = 0;
                break;
            }
            case 0: {
                cout << "[INFO] Saindo sem salvar...\n";
                break;
            }
            default: cout << "Opcao invalida.\n";
        }

    } while (opcao != 0);

    return 0;
}