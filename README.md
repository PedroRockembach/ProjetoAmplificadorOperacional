# Sistema de Gerenciamento de Componentes Eletrônicos

## 📋 Descrição
Sistema em C++ para cadastro, edição, remoção e busca de componentes eletrônicos com persistência em CSV.

## 🏗️ Arquitetura

### Estrutura de Pastas
```
lib/
├── Dados.h                          # Estrutura genérica de dados
├── AmplificadorOperacional/         # Classe base para amplificadores
│   ├── AmplificadorOperacional.h
│   └── AmplificadorOperacional.cpp
├── Amplificadores/
│   ├── AmplificadorInversor/
│   ├── AmplificadorNaoInversor/
│   └── AmplificadorDiferencial/
├── ExibidorComponente/              # Exibição de dados
├── GerenciadorComponentes/          # Gerenciamento CRUD + CSV
└── Validador/                       # Validação de entrada
```

## 🔧 Compilação

```bash
cd ProjetoAmplificadorOperacional
g++ -fdiagnostics-color=always -g main.cpp \
    lib/AmplificadorOperacional/AmplificadorOperacional.cpp \
    lib/AmplificadorInversor/AmplificadorInversor.cpp \
    lib/AmplificadorNaoInversor/AmplificadorNaoInversor.cpp \
    lib/AmplificadorDiferencial/AmplificadorDiferencial.cpp \
    lib/ExibidorComponente/ExibidorComponente.cpp \
    lib/GerenciadorComponentes/GerenciadorComponentes.cpp \
    lib/Validador/Validador.cpp \
    -o main.exe

./main.exe
```

## 📝 Dados (CSV)

Formato: `Codigo,Tipo,Modelo,Valor,BandaPassante,ImpedanciaEntrada,TensaoOffset`

## 📋 Funcionalidades

✅ Cadastro de componentes
✅ Edição de componentes
✅ Remoção de componentes
✅ Busca por tipo
✅ Busca por código
✅ Persistência em CSV
✅ Validação de entrada

## 👨‍💼 Autores

- Pedro e Matheus - Amplificadores Operacionais
## Componentes já implementados

-  [Tipo de componente]
-  [Tipo de componente]
-  [Tipo de componente]
-  [Tipo de componente]
-  [Tipo de componente]


## .\main.exe pra rodar
## ctrl+shift+b pra compilar
---

**Última atualização:** 26 de dezembro de 2025