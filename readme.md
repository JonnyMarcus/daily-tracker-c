# 🚀 Daily Tracker — Gerenciador de Tarefas em C

Sistema de gerenciamento de tarefas desenvolvido em linguagem C, com foco em organização pessoal, produtividade e aplicação prática de estruturas de dados.

> 💡 Projeto criado para resolver um problema real: organizar tarefas do dia a dia diretamente no terminal, de forma rápida e eficiente.

---

## 🎯 Objetivo

Construir um sistema completo de controle de tarefas utilizando apenas C, aplicando conceitos fundamentais de:

- Estruturas de dados
- Manipulação de arquivos
- Organização modular de código
- Lógica de negócios aplicada

---

## ⚙️ Funcionalidades

### 📝 Gerenciamento de tarefas
- Adicionar tarefas com descrição, prioridade e data
- Listar tarefas organizadas automaticamente
- Marcar tarefas como concluídas
- Remover tarefas

### 🧠 Inteligência do sistema
- 🔥 Ordenação automática por prioridade e data
- ⏰ Detecção de tarefas atrasadas em tempo real
- 📅 Busca por tarefas em uma data específica

### 📊 Feedback visual
- Barra de progresso de conclusão
- Interface com cores no terminal (ANSI)
- Status dinâmico:
  - 🟢 Concluída
  - 🔴 Atrasada
  - 🟡 Pendente

### 💾 Persistência
- Salvamento automático em arquivo
- Carregamento ao iniciar o programa

---

## 🧱 Arquitetura do Projeto

O projeto foi estruturado de forma modular para facilitar manutenção e escalabilidade:
├── main.c # fluxo principal do programa
├── tarefa.c/h # lógica de tarefas (lista encadeada)
├── arquivo.c/h # persistência em arquivo
├── UI.c/h # interface do usuário
├── data/ # armazenamento dos dados
├── Makefile # automação de build
└── README.md

---

## 🧠 Conceitos Aplicados

Este projeto demonstra domínio prático de:

- ✔ Ponteiros e alocação dinâmica (`malloc`, `free`)
- ✔ Lista encadeada (inserção ordenada)
- ✔ Ordenação customizada (prioridade + data)
- ✔ Manipulação de strings (`strcpy`, `strncpy`, `strtok`)
- ✔ Manipulação de arquivos (`fopen`, `fprintf`, `fgets`)
- ✔ Manipulação de tempo (`time.h`)
- ✔ Modularização com `.h` e `.c`
- ✔ Boas práticas de organização em C

---

## 🚀 Como executar

### 🔧 Compilar

taskkill /F /IM tracker.exe
del tracker.exe
gcc SRC\main.c SRC\tarefa.c SRC\arquivo.c SRC\UI.c -IInclude -o tracker.exe
.\tracker.exe

Exemplo de uso:
===== DAILY TRACKER =====
1 - Adicionar tarefa
2 - Listar tarefas
3 - Concluir tarefa
4 - Remover tarefa
5 - Progresso
6 - Buscar por data
0 - Sair

## 👨‍💻 Autor

Jonny Marcus  

🔗 LinkedIn: https://www.linkedin.com/in/jonny-marcus-3a02512ab/  
💻 GitHub: https://github.com/JonnyMarcus
