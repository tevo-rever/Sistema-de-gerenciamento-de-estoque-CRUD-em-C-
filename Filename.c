#include <stdio.h> // bibliotecas usadas
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>
struct produto{ 
	int id;//id do produto
	int qtd; //quantidade
	float preco; //preço
	char nome[50]; //nome do produto
};
struct produto estoque[500];

int proxima_vaga = 0; // variável global para comparativo do estoque

void limpa_buffer() {
    int c;
	while ((c = getchar()) != '\n' && c != EOF); // funcao que limpa buffer (memoria do teclado) para evitar problemas com entradas anteriores
}
void pesq_produto() {
    system("cls");
    int sair = 0;
    int pesquisa;
    do {
        int i;
        printf("Digite o id do produto: ");
        if (scanf_s("%d", &pesquisa) != 1) {
			printf("\nEntrada invalida. Tente novamente.\n"); //verifica se o id digitado é um numero, se nao for, ele avisa e pede para digitar novamente
            limpa_buffer();//limpa buffer
            continue;
        }
        int found = 0;
		for (i = 0; i < proxima_vaga; i++) { //teste para verificar se o produto existe, comparando o id digitado com os ids do estoque
            if (estoque[i].id == pesquisa) {
                printf("\nProduto encontrado!");
                printf("\nID: %d", estoque[i].id);
                printf("\nNome:%s", estoque[i].nome);
                printf("\nQuantidade: %d", estoque[i].qtd);
                printf("\nPreco: %0.2f", estoque[i].preco);
                found = 1;
                break;
            }
        }
        if (!found) {
            printf("\nProduto nao encontrado!");
        }
        printf("\nDeseja sair? (1-Sim, 0-Nao): ");
		while ((scanf_s("%d", &sair) != 1) || (sair > 1 || sair < 0)) { //condicao de saida, verificando se a entrada é valida (1 ou 0)
            printf("Entrada invalida. Tente novamente.");
            limpa_buffer();
            printf("\nDeseja sair? (1-Sim, 0-Nao): ");
        }
    } while (sair == 0);
}

void add_produto() {
    int sair = 0;
    system("cls");
    do {
		if (proxima_vaga >= 500) { //testa se o estoque está cheio, comparando a variavel global com o tamanho do array
            int i;
            printf("Estoque cheio!\n");
            for (i = 0; i <= 5; i++) {
                printf("%d...", i);
                Sleep(1000);
            }
            system("cls");
            return; //retorna ao main
        }
        printf("\--- Cadastro do produto %d ---\n", proxima_vaga + 1);
        printf("Digite o nome: ");
        // scanf_s para string precisa do tamanho do buffer
        scanf_s(" %[^\n]", estoque[proxima_vaga].nome, (unsigned)sizeof(estoque[proxima_vaga].nome));
        limpa_buffer();
        int validacao = 0;
        int idunico = 0;
		while (validacao == 0 || idunico == 0) { //valida se os dados foram digitados corretamente e se o id é unico, caso contrario, ele pede para digitar novamente
			int idrepetido = 0;
            printf("Digite o ID, Preco e Quantidade (separados por espaco): ");
            int i;
            // checando se os 3 valores foram lidos corretamente
            if (scanf_s("%d %f %d", &estoque[proxima_vaga].id, &estoque[proxima_vaga].preco, &estoque[proxima_vaga].qtd) == 3) {
                for (int i = 0; i < proxima_vaga; i++) {
                    if (estoque[i].id == estoque[proxima_vaga].id) {
                        idrepetido = 1;
                        break;
                    }
                }
                if (idrepetido) {
                    printf("Erro: ID ja existe! Digite um ID unico.\n");
                    idunico = 0;
                }
                else {
                    validacao = 1;
                    idunico = 1;
                }
            }
            else {
                printf("Erro: Digite valores numericos validos!\n");
                limpa_buffer(); // limpa buffer
            }
        }
        printf("\nProduto cadastrado com sucesso!");
        proxima_vaga++; // move para a próxima posição do array
        printf("\nDeseja sair? (1-Sim, 0-Nao): ");
        while ((scanf_s("%d", &sair) != 1) || (sair > 1 || sair < 0)) {
            printf("Entrada invalida. Tente novamente.");
            limpa_buffer();
            printf("\nDeseja sair? (1-Sim, 0-Nao): ");
        }

    } while (sair == 0);
}
void list_produt() {
    system("cls");
    int i;
	for (i = 0; i < proxima_vaga; i++) { //mesma lógica da pesquisa de produto, mas aqui ele lista todos os produtos do estoque, verificando se o id existe para evitar listar posições vazias
        if (estoque[i].id) {
            printf("\nProduto numero %d", i+1);
            printf("\nID:%d", estoque[i].id);
            printf("\nNome:%s", estoque[i].nome);
            printf("\nQuantidade:%d", estoque[i].qtd);
            printf("\nPreco: R$%0.2f\n", estoque[i].preco);
        }
    }   
    system("pause");
    system("cls");
}
void atualizar_produto() {
	system("cls");
    int sair = 0;
    int pesquisa;
    int indice;
    do {
        int i;
        printf("Digite o id do produto: ");
        if (scanf_s("%d", &pesquisa) != 1) {
            printf("\nEntrada invalida. Tente novamente.\n");
            limpa_buffer();
            pesquisa = 0;
            continue;
        }
        int found = 0;
		for (i = 0; i < proxima_vaga; i++) { //mesma lógica da pesquisa de produto
            if (estoque[i].id == pesquisa) {
                printf("\nProduto encontrado!");
                printf("\nID: %d", estoque[i].id);
                printf("\nNome:%s", estoque[i].nome);
                printf("\nQuantidade: %d", estoque[i].qtd);
                printf("\nPreco: R$%0.2f", estoque[i].preco);
                found = 1;
                indice = i;
                break;
            }
        }
        if (!found) {
            printf("\nProduto nao encontrado!");
            printf("Voltando ao menu...");
            Sleep(3000);
            system("cls");
            return;
        }
        int escolha;
        printf("\n\nO que deseja alterar?:\n1-Preco   2-Quantidade\nSua resposta:");

		while (scanf_s("%d", &escolha) != 1 || !(escolha >= 1 && escolha <= 2)) { //condicao para verificar se a escolha é valida (1 ou 2), caso contrario, ele avisa e pede para digitar novamente
            limpa_buffer();
            system("cls");
            printf("\nEntrada invalida. Tente novamente.");
            printf("\nO que deseja alterar?:\n1-Preco   2-Quantidade\nSua resposta:");
        }
		if (escolha == 1) { //caso escolha seja 1, ele pede para digitar o novo preço, verificando se a entrada é valida (um numero), caso contrario, ele avisa e pede para digitar novamente
            float  novo_preco;
            printf("\nQual o novo preco que voce deseja adicionar a %s?: ", estoque[indice].nome);
            while (scanf_s("%f", &novo_preco) != 1) {
                limpa_buffer();
                system("cls");
                printf("\nEntrada invalida. Tente novamente.");
                printf("\nQual o novo preco que voce deseja adicionar a %s?: ", estoque[indice].nome);
            }
            estoque[indice].preco = novo_preco;
            printf("\nPronto! O novo preco de %s: R$%0.2f.", estoque[indice].nome, novo_preco);
        }
		if (escolha == 2) { //caso seja 2, ele pede para digitar a nova quantidade, verificando se a entrada é valida (um numero), caso contrario, ele avisa e pede para digitar novamente
            int nova_qtd;
            system("cls");
            printf("\nQual a nova quantidade de %s?", estoque[indice].nome);
            while (scanf_s("%d", &nova_qtd) != 1) {
                limpa_buffer();
                system("cls");
                printf("\nEntrada invalida. Tente novamente.");
                printf("Qual a nova quantidade de %s?", estoque[indice].nome);
            }
            estoque[indice].qtd = nova_qtd;
            printf("\nPronto! A nova quantidade de %s: %d.", estoque[indice].nome, nova_qtd);
        }
        printf("\nDeseja sair? (1-Sim, 0-Nao): ");
        while ((scanf_s("%d", &sair) != 1) || (sair > 1 || sair < 0)) {
            printf("Entrada invalida. Tente novamente.");
            limpa_buffer();
            printf("\nDeseja sair? (1-Sim, 0-Nao): ");
        }
    } while (sair == 0);

}
void salvar() {
    //criando o ponteiro para o arquivo
    FILE* arquivo;

    // abrindo o arquivo para escrita (w).
    // se o arquivo não existir, ele cria. se existir, ele limpa e começa do zero.
    errno_t err = fopen_s(&arquivo, "estoque.txt", "w");//forma de escrita conforme os avisos de segurança microsoft

    if (err != 0) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }
    // percorrer o array e salvar cada produto
    int j;
    for (int j = 0; j < proxima_vaga; j++) {
        // fprintf funciona igual ao printf, mas o primeiro argumento é o arquivo
        fprintf(arquivo, "%d;%s;%d;%.2f\n",
            estoque[j].id,
            estoque[j].nome,
            estoque[j].qtd,
            estoque[j].preco);
    }
    fclose(arquivo); //fechando o arquivo
    printf("Dados salvos com sucesso no arquivo estoque.txt!\n");
}
void carregar() {
    FILE* arquivo;

	errno_t err = fopen_s(&arquivo, "estoque.txt", "r"); //abrindo o arquivo para leitura
	if (err != 0) {
        printf("Nenhum arquivo de estoque encontrado.\n");
        return;
    }
    while (fscanf_s(arquivo, "%d;%49[^;];%d;%f\n", 
        &estoque[proxima_vaga].id, 
		estoque[proxima_vaga].nome, (unsigned)sizeof(estoque[proxima_vaga].nome),
		&estoque[proxima_vaga].qtd, 
        &estoque[proxima_vaga].preco) == 4) {
        proxima_vaga++;
        if (proxima_vaga >= 500) {
            printf("Limite de estoque atingido ao carregar o arquivo!\n");
            break;
        }
	}
	fclose(arquivo);
	printf("Dados carregados com sucesso do arquivo estoque.txt!\n");
}
void delete() { //funcao de deletar
    int sair = 0;
    system("cls");
    do {
        printf("Digite o id do produto que queira deletar: ");
		int pesquisa; 
        if (scanf_s("%d", &pesquisa) != 1) { //validacao
            printf("\nEntrada invalida. Tente novamente.\n");
            limpa_buffer();
            pesquisa = 0;
            continue;
        }
		int found = 0;
        for (int i = 0; i < proxima_vaga; i++) { //se existir...
            if (estoque[i].id == pesquisa) {
                found = 1;
                for (int j = i; j < proxima_vaga - 1; j++) {
                    estoque[j] = estoque[j + 1]; //realoca o espaço da posição J (a desejada a ser apagaga) com a posição da frente de J
                }
                proxima_vaga--;
                printf("\nProduto deletado com sucesso!");
                break;
            }
        }
        if (!found) {
            printf("\nProduto nao encontrado!");
        }
        printf("\nDeseja sair? (1-Sim, 0-Nao): ");
        while ((scanf_s("%d", &sair) != 1) || (sair > 1 || sair < 0)) {
            printf("Entrada invalida. Tente novamente.");
            limpa_buffer();
            printf("\nDeseja sair? (1-Sim, 0-Nao): ");
		}
    } while (sair == 0);
	

}

int main() {
    system("cls");
	carregar(); // carrega os dados do arquivo ao iniciar o programa
    char anima = 176;
    char anim = 219;
    int i;
    int resp;
    bool status; // variável para checar se a leitura deu certo
    system("cls");
    printf("-----Bem-vindo ao sistema de gerenciamento de produtos!-----\n");
    printf("                ---Por favor, aguarde---\n\n");
    for (i = 0; i <= 15; i++) { //animacao de carregamento..
        printf("%c", anima);
    }
    for (i = 0; i <= 15; i++) {
        printf("\r");
    }
    for (i = 0; i <= 15; i++) {
        printf("%c", anim);
        Sleep(200);
    }
    system("cls");
    do {
        system("cls");
        printf("---------Bem vindo!----------\n1-Adicionar\n2-Pesquisar\n3-Listar\n4-Editar\n5-Excluir\n6-Sair\nResposta: ");
        status = (scanf_s("%d", &resp) == 1);
		limpa_buffer(); // Limpa o buffer para evitar problemas com entradas anteriores
        if (!status) {
            system("cls");
            printf("Erro: Digite apenas numeros!\n");
            limpa_buffer();
            resp = 0;
            continue;
        }
        if (resp == 1) {
            add_produto();
        }
        else if (resp == 2) {
            pesq_produto();
        }
        else if (resp == 3) {
            list_produt();
        }
        else if (resp == 4) {
            atualizar_produto();
        }
        else if (resp == 5) {
            delete();
		}
        else if (resp == 6) { //repare que ao sair do arquivo, ele ja salva sozinho
            salvar();
            Sleep(3000);
        }
    } while (resp != 6); // condicao de saida
    printf("\nObrigado!");
}
