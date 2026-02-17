# 📦 Sistema de Gerenciamento de Estoque (CRUD em C)

Este é um projeto de gerenciamento de estoque robusto desenvolvido em **Linguagem C**. O sistema foi projetado para rodar em ambiente Windows, oferecendo uma solução completa para controle de mercadorias com persistência de dados.



## 🚀 Funcionalidades

O programa oferece uma interface de console intuitiva com as seguintes operações:

* **Cadastrar Produto:** Registro de nome, ID, preço e quantidade.
* **Validação de ID Único:** Lógica de busca que impede a duplicidade de IDs, garantindo a integridade do estoque.
* **Pesquisa por ID:** Localização instantânea de produtos cadastrados.
* **Listagem Completa:** Exibição organizada de todos os itens em estoque.
* **Edição Dinâmica:** Atualização de preços e níveis de quantidade.
* **Exclusão com Realocação:** Remoção de itens utilizando a técnica de *shifting* para evitar "buracos" na memória do array.
* **Persistência de Dados:** Carregamento automático e salvamento em arquivo local (`estoque.txt`).

## 🛠️ Detalhes Técnicos e Conceitos Aplicados

Este projeto demonstra o domínio de conceitos fundamentais da programação em baixo nível:

1.  **Manipulação de Structs:** Organização de dados heterogêneos.
2.  **Gerenciamento de Memória:** Controle de arrays estáticos e índices globais.
3.  **Lógica de Shifting:** Reorganização de elementos no array durante a exclusão.
4.  **Tratamento de Entrada (Buffer):** Implementação de limpeza manual do `stdin` para evitar falhas no `scanf`.
5.  **I/O de Arquivos:** Manipulação de arquivos (`fopen`, `fprintf`, `fscanf`) para armazenamento persistente.
6.  **Interface Windows:** Uso da API `windows.h` para controle de tela e temporização.



## 📂 Como Compilar e Rodar

> **Nota:** Este projeto utiliza a biblioteca `<windows.h>`, portanto, é destinado ao sistema operacional **Windows**.

1. Clone o repositório:
   ```bash
   git clone [https://github.com/tevo-rever/Sitema-de-gerenciamento-CRUD-em-C.git](https://github.com/tevo-rever/Sitema-de-gerenciamento-CRUD-em-C.git)
2- Bash:
gcc main.c -o sistema_estoque.exe

Execute:
./sistema_estoque.exe

