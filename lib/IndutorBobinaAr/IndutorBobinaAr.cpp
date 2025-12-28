#include "IndutorBobinaAr.h"
#include <iostream>

using namespace std;

string IndutorBobinaAr::lerCodigo() {
    Entrada entrada;
    string codigoRegistro;
    do {
        codigoRegistro = entrada.lerComMensagem("Codigo: ");
    } while (codigoRegistro.empty());
    return codigoRegistro;
}

double IndutorBobinaAr::lerIndutancia() {
    UnidadeIndutancia unidade;
    Entrada entrada;
    while (true) {
        ResultadoIndutancia x = unidade.interpretar(entrada.lerComMensagem("Indutancia: "));
        if (x.valido && x.valor > 0)
            return x.valor;
        cout << "Valor invalido.\n";
    }
}

dadosCSV IndutorBobinaAr::Cadastrar() {
    cout << "\n=== Cadastro Indutor Bobina Ar ===\n";
    
    codigo = lerCodigo();
    valorH = lerIndutancia();

    int nEspiras = solicitarIntRange("Numero de espiras: ", 1, 1000000);
    espiras = to_string(nEspiras);

    double dFio = solicitarDoubleRange("Diametro do fio (mm): ", 0.05, 5.0);
    diametroFio = to_string(dFio);

    double comp = solicitarDoubleRange("Comprimento (mm): ", 0.5, 2000.0);
    comprimento = to_string(comp);
    
    UnidadeIndutancia unidade;
    dadosCSV dados;
    dados.codigo = codigo;
    dados.tipoComponente = "Indutor";
    dados.modelo = "BobinaAr";
    dados.valor = unidade.formatar(valorH);
    dados.atributo1 = espiras;
    dados.atributo2 = diametroFio;
    dados.atributo3 = comprimento;
    
    cout << "[SUCESSO] Indutor Bobina Ar cadastrado!\n";
    return dados;
}

dadosCSV IndutorBobinaAr::Mostrar() const {
    UnidadeIndutancia unidade;
    dadosCSV dados;
    dados.codigo = codigo;
    dados.tipoComponente = "Indutor";
    dados.modelo = "BobinaAr";
    dados.valor = unidade.formatar(valorH);
    dados.atributo1 = espiras;
    dados.atributo2 = diametroFio;
    dados.atributo3 = comprimento;
    
    cout << "\n--- INDUTOR BOBINA AR ---\n";
    cout << "Codigo: " << codigo << endl;
    cout << "Indutancia: " << dados.valor << "\n";
    cout << "Espiras: " << espiras << endl;
    cout << "Diametro do Fio: " << diametroFio << " mm\n";
    cout << "Comprimento: " << comprimento << " mm\n";
    
    return dados;
}