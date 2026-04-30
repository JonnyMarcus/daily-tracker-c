# 📌 Daily Tracker — Gerenciador de Tarefas em C

Sistema de gerenciamento de tarefas desenvolvido em linguagem C, com foco em organização pessoal, produtividade e aplicação prática de estruturas de dados.

Projeto criado para resolver um problema real: organizar tarefas do dia a dia diretamente no terminal, de forma rápida, eficiente e com persistência local de dados.

---

# 🎯 Objetivo

Construir um sistema completo de controle de tarefas utilizando linguagem C, aplicando conceitos fundamentais de programação e estruturas de dados em um projeto funcional de uso cotidiano.

## Conceitos centrais trabalhados

* estruturas de dados
* manipulação de arquivos
* organização modular de código
* lógica de negócios aplicada

---

# ⚙️ Funcionalidades

## 📝 Gerenciamento de tarefas

* adicionar tarefas com descrição, prioridade e data
* listar tarefas organizadas automaticamente
* marcar tarefas como concluídas
* remover tarefas

---

## 🧠 Inteligência do sistema

* 🔥 ordenação automática por prioridade e data
* ⏰ detecção de tarefas atrasadas em tempo real
* 📅 busca de tarefas por data específica

---

## 📊 Feedback visual

* barra de progresso de conclusão

* interface com cores no terminal (ANSI)

* status dinâmico de tarefas:

* 🟢 concluída

* 🔴 atrasada

* 🟡 pendente

---

## 💾 Persistência de dados

* salvamento automático em arquivo
* carregamento automático ao iniciar o programa

---

# 🧱 Arquitetura do Projeto

O projeto foi estruturado de forma modular para facilitar manutenção, organização e escalabilidade.

```text id="n8q4mx"
Daily_Tracker/
│
├── SRC/
│   ├── main.c
│   ├── tarefa.c
│   ├── arquivo.c
│   └── UI.c
│
├── Include/
│   ├── tarefa.h
│   ├── arquivo.h
│   └── UI.h
│
├── data/
│
├── Makefile
│
└── README.md
```

---

# 🧠 Conceitos Aplicados

Este projeto demonstra domínio prático de:

* ponteiros e alocação dinâmica (`malloc`, `free`)
* lista encadeada com inserção ordenada
* ordenação customizada por prioridade e data
* manipulação de strings (`strcpy`, `strncpy`, `strtok`)
* manipulação de arquivos (`fopen`, `fprintf`, `fgets`)
* manipulação de tempo com `time.h`
* modularização com arquivos `.c` e `.h`
* organização de código em múltiplos módulos

---

# 🚀 Como executar

## 🔧 Compilação

```bash id="r5m2tv"
gcc SRC\main.c SRC\tarefa.c SRC\arquivo.c SRC\UI.c -IInclude -o tracker.exe
```

---

## ▶️ Execução

```bash id="u7k3np"
.\tracker.exe
```

---

# 💻 Exemplo de uso

```text id="q4v8mn"
===== DAILY TRACKER =====

1 - Adicionar tarefa
2 - Listar tarefas
3 - Concluir tarefa
4 - Remover tarefa
5 - Progresso
6 - Buscar por data
0 - Sair
```

---

# 📈 Evolução Técnica Demonstrada

Este projeto representa um avanço importante no domínio de C por integrar:

* estrutura dinâmica de dados
* persistência local
* lógica de ordenação
* interface de terminal organizada

---

# 👨‍💻 Autor

**Jonny Marcus**

🔗 LinkedIn
💻 GitHub
