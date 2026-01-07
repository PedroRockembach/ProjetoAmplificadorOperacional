#include "SistemaComponentes.h"
#include "../AmplificadorInversor/AmplificadorInversor.h"
#include "../AmplificadorNaoInversor/AmplificadorNaoInversor.h"
#include "../AmplificadorDiferencial/AmplificadorDiferencial.h"
#include "../Display7s/Display7.h"
#include "../DisplayLCD/DisplayLCD.h"
#include "../DisplayOLED/DisplayOLED.h"
#include "../CapacitorCeramico/Ceramico.h"
#include "../CapacitorEletrolitico/Eletrolitico.h"
#include "../CapacitorTantalum/Tantalum.h"
#include "../IndutorFerrite/IndutorFerrite.h"
#include "../IndutorToroidal/IndutorToroidal.h"
#include "../IndutorBobinaAr/IndutorBobinaAr.h"

SistemaComponentes::SistemaComponentes() : gerenciador("componentes.csv") {
    // Construtor
}

SistemaComponentes::~SistemaComponentes() {
    // Destrutor
}

void SistemaComponentes::exibirMenuPrincipal() {
    cout << "\n=======================================\n";
    cout << "SISTEMA DE GERENCIAMENTO DE COMPONENTES\n";
    cout << "=======================================\n";
    cout << "Componentes cadastrados: " << gerenciador.obterTamanho() << "\n";
    cout << "=======================================\n";
    cout << "1. AMPLIFICADORES OPERACIONAIS\n";
    cout << "2. CAPACITORES\n";
    cout << "3. INDUTORES\n";
    cout << "4. DISPLAYS\n";
    cout << "5. GERENCIAR COMPONENTES\n";
    cout << "6. Salvar e Sair\n";
    cout << "0. Sair sem Salvar\n";
    cout << "=======================================\n";
    cout << "Opcao: ";
}

void SistemaComponentes::exibirMenuAmplificadores() {
    cout << "\n=======================================\n";
    cout << "     AMPLIFICADORES OPERACIONAIS     \n";
    cout << "=======================================\n";
    cout << "1. Amplificador INVERSOR\n";
    cout << "2. Amplificador NÃO-INVERSOR\n";
    cout << "3. Amplificador DIFERENCIAL\n";
    cout << "0. Voltar\n";
    cout << "=======================================\n";
    cout << "Opcao: ";
}

void SistemaComponentes::exibirMenuDisplays() {
    cout << "\n=======================================\n";
    cout << "           DISPLAYS                   \n";
    cout << "=======================================\n";
    cout << "1. Display de SETE SEGMENTOS\n";
    cout << "2. Display LCD\n";
    cout << "3. Display OLED\n";
    cout << "0. Voltar\n";
    cout << "=======================================\n";
    cout << "Opcao: ";
}

void SistemaComponentes::exibirMenuCapacitores() {
    cout << "\n=======================================\n";
    cout << "           CAPACITORES               \n";
    cout << "=======================================\n";
    cout << "1. Capacitor CERAMICO\n";
    cout << "2. Capacitor ELETROLITICO\n";
    cout << "3. Capacitor de TANTALUM\n";
    cout << "0. Voltar\n";
    cout << "=======================================\n";
    cout << "Opcao: ";
}

void SistemaComponentes::exibirMenuIndutores() {
    cout << "\n=======================================\n";
    cout << "           INDUTORES                 \n";
    cout << "=======================================\n";
    cout << "1. Indutor FERRITE\n";
    cout << "2. Indutor TOROIDAL\n";
    cout << "3. Indutor BOBINA AR\n";
    cout << "0. Voltar\n";
    cout << "──────────────────────────────────────\n";
    cout << "Opcao: ";
}

void SistemaComponentes::exibirMenuCRUD() {
    cout << "\n=======================================\n";
    cout << "     GERENCIAR COMPONENTES            \n";
    cout << "=======================================\n";
    cout << "1. LISTAR / VISUALIZAR\n";
    cout << "2. EDITAR\n";
    cout << "3. REMOVER\n";
    cout << "4. BUSCAR por Tipo\n";
    cout << "5. BUSCAR por Código\n";
    cout << "0. Voltar\n";
    cout << "=======================================\n";
    cout << "Opcao: ";
}

void SistemaComponentes::menuAmplificadores() {
    int opcao;
    
    do {
        exibirMenuAmplificadores();
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
                    cout << "\n[SUCESSO] Amplificador Inversor cadastrado!\n";
                }
                break;
            }
            case 2: {
                AmplificadorNaoInversor amp;
                resultado = amp.Cadastrar();
                if (!resultado.codigo.empty()) {
                    gerenciador.adicionar(resultado);
                    cout << "\n[SUCESSO] Amplificador Não-Inversor cadastrado!\n";
                }
                break;
            }
            case 3: {
                AmplificadorDiferencial amp;
                resultado = amp.Cadastrar();
                if (!resultado.codigo.empty()) {
                    gerenciador.adicionar(resultado);
                    cout << "\n[SUCESSO] Amplificador Diferencial cadastrado!\n";
                }
                break;
            }
            case 0: break;
            default: cout << "[ERRO] Opcao invalida.\n";
        }
        
    } while (opcao != 0);
}

void SistemaComponentes::menuDisplays() {
    int opcao;
    
    do {
        exibirMenuDisplays();
        cin >> opcao;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
        dadosCSV resultado;
        resultado.codigo = "";
        
        switch(opcao) {
            case 1: {
                Display7 display;
                resultado = display.Cadastrar();
                if (!resultado.codigo.empty()) {
                    gerenciador.adicionar(resultado);
                    cout << "\n[SUCESSO] Display de Sete Segmentos cadastrado!\n";
                }
                break;
            }
            case 2: {
                DisplayLCD display;
                resultado = display.Cadastrar();
                if (!resultado.codigo.empty()) {
                    gerenciador.adicionar(resultado);
                    cout << "\n[SUCESSO] Display LCD cadastrado!\n";
                }
                break;
            }
            case 3: {
                DisplayOLED display;
                resultado = display.Cadastrar();
                if (!resultado.codigo.empty()) {
                    gerenciador.adicionar(resultado);
                    cout << "\n[SUCESSO] Display OLED cadastrado!\n";
                }
                break;
            }
            case 0: break;
            default: cout << "[ERRO] Opcao invalida.\n";
        }
        
    } while (opcao != 0);
}

void SistemaComponentes::menuCapacitores() {
    int opcao;
    
    do {
        exibirMenuCapacitores();
        cin >> opcao;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
        dadosCSV resultado;
        resultado.codigo = "";
        
        switch(opcao) {
            case 1: {
                Ceramico cap;
                resultado = cap.Cadastrar();
                if (!resultado.codigo.empty()) {
                    gerenciador.adicionar(resultado);
                    cout << "\n[SUCESSO] Capacitor Ceramico cadastrado!\n";
                }
                break;
            }
            case 2: {
                Eletrolitico cap;
                resultado = cap.Cadastrar();
                if (!resultado.codigo.empty()) {
                    gerenciador.adicionar(resultado);
                    cout << "\n[SUCESSO] Capacitor Eletrolitico cadastrado!\n";
                }
                break;
            }
            case 3: {
                Tantalum cap;
                resultado = cap.Cadastrar();
                if (!resultado.codigo.empty()) {
                    gerenciador.adicionar(resultado);
                    cout << "\n[SUCESSO] Capacitor de Tantalum cadastrado!\n";
                }
                break;
            }
            case 0: break;
            default: cout << "[ERRO] Opcao invalida.\n";
        }
        
    } while (opcao != 0);
}

void SistemaComponentes::menuIndutores() {
    int opcao;
    
    do {
        exibirMenuIndutores();
        cin >> opcao;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
        dadosCSV resultado;
        resultado.codigo = "";
        
        switch(opcao) {
            case 1: {
                IndutorFerrite ind;
                resultado = ind.Cadastrar();
                if (!resultado.codigo.empty()) {
                    gerenciador.adicionar(resultado);
                    cout << "\n[SUCESSO] Indutor Ferrite cadastrado!\n";
                }
                break;
            }
            case 2: {
                IndutorToroidal ind;
                resultado = ind.Cadastrar();
                if (!resultado.codigo.empty()) {
                    gerenciador.adicionar(resultado);
                    cout << "\n[SUCESSO] Indutor Toroidal cadastrado!\n";
                }
                break;
            }
            case 3: {
                IndutorBobinaAr ind;
                resultado = ind.Cadastrar();
                if (!resultado.codigo.empty()) {
                    gerenciador.adicionar(resultado);
                    cout << "\n[SUCESSO] Indutor Bobina Ar cadastrado!\n";
                }
                break;
            }
            case 0: break;
            default: cout << "[ERRO] Opcao invalida.\n";
        }
        
    } while (opcao != 0);
}

void SistemaComponentes::menuCRUD() {
    int opcao;
    
    do {
        exibirMenuCRUD();
        cin >> opcao;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
        switch(opcao) {
            case 1: {
                if (gerenciador.obterTamanho() == 0) {
                    cout << "[INFO] Nenhum componente cadastrado.\n";
                } else {
                    cout << "\n--- COMPONENTES CADASTRADOS ---\n";
                    for (int i = 0; i < gerenciador.obterTamanho(); i++) {
                        dadosCSV comp = gerenciador.obterPorIndice(i);
                        cout << "[" << i << "] " << comp.tipoComponente 
                             << " - " << comp.modelo 
                             << " (Cod: " << comp.codigo << ")\n";
                    }
                    
                    int indice;
                    cout << "\nDigite INDICE para ver detalhes (-1 para voltar): ";
                    cin >> indice;
                    
                    if (indice >= 0 && indice < gerenciador.obterTamanho()) {
                        cout << "\n";
                        exibidor.exibir(gerenciador.obterPorIndice(indice));
                    }
                }
                break;
            }
            case 2: {
                if (gerenciador.obterTamanho() == 0) {
                    cout << "[INFO] Nenhum componente para editar.\n";
                } else {
                    cout << "\n--- COMPONENTES ---\n";
                    for (int i = 0; i < gerenciador.obterTamanho(); i++) {
                        cout << "[" << i << "] " << gerenciador.obterPorIndice(i).modelo << "\n";
                    }
                    
                    int indice;
                    cout << "\nIndice: ";
                    cin >> indice;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    
                    if (indice >= 0 && indice < gerenciador.obterTamanho()) {
                        dadosCSV comp = gerenciador.obterPorIndice(indice);
                        cout << "\n=== EDITANDO: " << comp.modelo << " ===\n";
                        
                        cout << "Novo Codigo [" << comp.codigo << "]: ";
                        string temp;
                        getline(cin, temp);
                        if (!temp.empty()) comp.codigo = temp;
                        
                        cout << "Novo Valor [" << comp.valor << "]: ";
                        getline(cin, temp);
                        if (!temp.empty()) comp.valor = temp;
                        
                        cout << "Novo Atributo1 [" << comp.atributo1 << "]: ";
                        getline(cin, temp);
                        if (!temp.empty()) comp.atributo1 = temp;
                        
                        cout << "Novo Atributo2 [" << comp.atributo2 << "]: ";
                        getline(cin, temp);
                        if (!temp.empty()) comp.atributo2 = temp;
                        
                        cout << "Novo Atributo3 [" << comp.atributo3 << "]: ";
                        getline(cin, temp);
                        if (!temp.empty()) comp.atributo3 = temp;
                        
                        gerenciador.editar(indice, comp);
                    }
                }
                break;
            }
            case 3: {
                if (gerenciador.obterTamanho() == 0) {
                    cout << "[INFO] Nenhum componente para remover.\n";
                } else {
                    cout << "\n--- COMPONENTES ---\n";
                    for (int i = 0; i < gerenciador.obterTamanho(); i++) {
                        cout << "[" << i << "] " << gerenciador.obterPorIndice(i).modelo << "\n";
                    }
                    
                    int indice;
                    cout << "\nIndice: ";
                    cin >> indice;
                    
                    gerenciador.remover(indice);
                }
                break;
            }
            case 4: {
                cout << "\nTipo a buscar: ";
                string tipo;
                getline(cin, tipo);
                
                vector<dadosCSV> resultados = gerenciador.buscarPorTipo(tipo);
                
                if (resultados.empty()) {
                    cout << "[INFO] Nenhum componente encontrado.\n";
                } else {
                    cout << "\n--- RESULTADOS ---\n";
                    for (size_t i = 0; i < resultados.size(); i++) {
                        cout << "[" << i << "] " << resultados[i].modelo 
                             << " (Cod: " << resultados[i].codigo << ")\n";
                    }
                }
                break;
            }
            case 5: {
                cout << "\nCodigo a buscar: ";
                string codigo;
                getline(cin, codigo);
                
                vector<dadosCSV> resultados = gerenciador.buscarPorCodigo(codigo);
                
                if (resultados.empty()) {
                    cout << "[INFO] Nenhum componente encontrado.\n";
                } else {
                    cout << "\n--- RESULTADO ---\n";
                    exibidor.exibir(resultados[0]);
                }
                break;
            }
            case 0: break;
            default: cout << "[ERRO] Opcao invalida.\n";
        }
        
    } while (opcao != 0);
}

void SistemaComponentes::executar() {
    int opcao;
    
    do {
        exibirMenuPrincipal();
        cin >> opcao;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
        switch(opcao) {
            case 1: {
                menuAmplificadores();
                break;
            }
            case 2: {
                menuCapacitores();
                break;
            }
            case 3: {
                menuIndutores();
                break;
            }
            case 4: {
                menuDisplays();
                break;
            }
            case 5: {
                menuCRUD();
                break;
            }
            case 6: {
                gerenciador.salvarEmArquivo();
                cout << "[INFO] Dados salvos. Encerrando...\n";
                opcao = 0;
                break;
            }
            case 0: {
                cout << "[INFO] Saindo sem salvar...\n";
                break;
            }
            default: cout << "[ERRO] Opcao invalida.\n";
        }
        
    } while (opcao != 0);
}