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
├───Capacitor
├───CapacitorCeramico
├───CapacitorEletrolitico
├───CapacitorTantalum
├───Display
├───Display7s
├───DisplayLCD
├───DisplayOLED
├───Indutor
├───IndutorBobinaAr
├───IndutorEntrada
├───IndutorFerrite
├───IndutorToroidal
├───SistemaComponentes
├───UnidadeIndutancia
```

## 🔧 Compilação

```bash
cd ProjetoAmplificadorOperacional
        "-fdiagnostics-color=always",
        "-g",
        "main.cpp",
        "lib/AmplificadorOperacional/AmplificadorOperacional.cpp",
        "lib/AmplificadorInversor/AmplificadorInversor.cpp",
        "lib/AmplificadorNaoInversor/AmplificadorNaoInversor.cpp",
        "lib/AmplificadorDiferencial/AmplificadorDiferencial.cpp",
        "lib/ExibidorComponente/ExibidorComponente.cpp",
        "lib/GerenciadorComponentes/GerenciadorComponentes.cpp",
        "lib/SistemaComponentes/SistemaComponentes.cpp",
        "lib/Validador/Validador.cpp",
        "lib/Display/Display.cpp",
        "lib/Display7s/Display7.cpp",
        "lib/DisplayLCD/DisplayLCD.cpp",
        "lib/DisplayOLED/DisplayOLED.cpp",
        "lib/CapacitorCeramico/ceramico.cpp",
        "lib/CapacitorEletrolitico/eletrolitico.cpp",
        "lib/CapacitorTantalum/tantalum.cpp",
        "lib/Indutor/Indutor.cpp",
        "lib/IndutorEntrada/Entrada.cpp",
        "lib/UnidadeIndutancia/UnidadeIndutancia.cpp",
        "lib/IndutorFerrite/IndutorFerrite.cpp",
        "lib/IndutorBobinaAr/IndutorBobinaAr.cpp",
        "lib/IndutorToroidal/IndutorToroidal.cpp",
        "-o",
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

-  [Indutores]
-  [Capacitores]
-  [Displays]


## .\main.exe pra rodar
## ctrl+shift+b pra compilar
---

**Última atualização:** 26 de dezembro de 2025