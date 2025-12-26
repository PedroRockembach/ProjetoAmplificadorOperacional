#ifndef GERENCIADOR_COMPONENTES_H
#define GERENCIADOR_COMPONENTES_H

#include "../Dados.h"
#include <vector>
#include <string>
#include <fstream>

using namespace std;

class GerenciadorComponentes {
    private:
        vector<dadosCSV> componentes;
        string nomeArquivo;
        
        void escreverCabecalho(ofstream& arquivo);
        
    public:
        GerenciadorComponentes(string nomeArq = "componentes.csv");
        ~GerenciadorComponentes();
        
        void adicionar(dadosCSV dados);
        void salvarEmArquivo();
        void carregarDoArquivo();
        
        void editar(int indice, dadosCSV novosDados);
        void remover(int indice);
        vector<dadosCSV> buscarPorTipo(string tipo);
        vector<dadosCSV> buscarPorCodigo(string codigo);

        vector<dadosCSV> obterComponentes();
        int obterTamanho();
        dadosCSV obterPorIndice(int indice);
};

#endif