#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#define MAX_ITENS 100

typedef struct {
    char login[30];
    char senha[30];
} pessoa;

pessoa p[1];
int autenticarUsuario(const char *login, const char *senha) {
    FILE *userFile = fopen("usuario.txt", "r");
    if (userFile == NULL) {
        printf("Erro ao abrir o arquivo de usuários.\n");
        return 0;
    }

    char linha[256];
    while (fgets(linha, sizeof(linha), userFile)) {
        char fileLogin[30], fileSenha[30];
        // Procurar pelo par LOGIN e SENHA
        if (strncmp(linha, "LOGIN:", 6) == 0) {
            sscanf(linha, "LOGIN: %s", fileLogin);
            fgets(linha, sizeof(linha), userFile); // Pula para a linha da senha
            if (strncmp(linha, "SENHA:", 6) == 0) {
                sscanf(linha, "SENHA: %s", fileSenha);
                if (strcmp(fileLogin, login) == 0 && strcmp(fileSenha, senha) == 0) {
                    fclose(userFile);
                    return 1; // Autenticação bem-sucedida
                }
            }
        }
    }
    fclose(userFile);
    return 0; // Falha na autenticação
}
typedef struct {
    char codigo[50];
    char nome[50];
    float preco;
    float quantidade;
    float totalItem;
} ItemVenda;

ItemVenda itens[MAX_ITENS];
int numeroItens = 0; // Número de itens no carrinho
float totalVenda = 0; // Total acumulado da venda

void colorirTexto(char* textoCor) {
    printf("%s", textoCor);
}
void cadastrocliente() {

                                            system("cls");
                                            printf("-------------------------------------------------------------------------------|\n");
                                            printf("                                 CADASTRO DE CLIENTE                            \n");
                                            printf("-------------------------------------------------------------------------------|\n");
                                            FILE *client;
                                            char cliente[50];
                                            char cpf[20];
                                            char endereco[50];
                                            char Email1[50];
                                            char telefone1[20];
                                            client = fopen("cliente.txt", "a+");
                                            if (client == NULL) {
                                                printf("ERRO! Arquivo não foi aberto\n");
                                                return 1;
                                            }

                                            printf("Cadastre o cliente\n ");
                                            printf("-------------------------------------------------------------------------------|\n");
                                            printf("NOME CLIENTE: ");
                                            getchar(); // Limpa o buffer
                                            fgets(cliente, sizeof(cliente), stdin);
                                            cliente[strcspn(cliente, "\n")] = '\0'; // Remove a nova linha
                                             printf("-------------------------------------------------------------------------------|\n");
                                            printf("CPF: ");
                                            fgets(cpf, sizeof(cpf), stdin);
                                            cpf[strcspn(cpf, "\n")] = '\0'; // Remove a nova linha
                                             printf("-------------------------------------------------------------------------------|\n");
                                            printf("ENDEREÇO: ");
                                            fgets(endereco, sizeof(endereco), stdin);
                                            endereco[strcspn(endereco, "\n")] = '\0'; // Remove a nova linha
                                             printf("-------------------------------------------------------------------------------|\n");
                                            printf("EMAIL: ");
                                            fgets(Email1, sizeof(Email1), stdin);
                                            Email1[strcspn(Email1, "\n")] = '\0'; // Remove a nova linha
                                             printf("-------------------------------------------------------------------------------|\n");
                                            printf("TELEFONE: ");
                                            fgets(telefone1, sizeof(telefone1), stdin);
                                            telefone1[strcspn(telefone1, "\n")] = '\0'; // Remove a nova linha
                                            fprintf(client, "----------------------------------------------------------------- \n");
                                            fprintf(client, "NOME: %s \n", cliente);
                                            fprintf(client, "CPF: %s \n", cpf);
                                            fprintf(client, "ENDEREÇO: %s \n", endereco);
                                            fprintf(client, "EMAIL: %s \n", Email1);
                                            fprintf(client, "TELEFONE: %s \n", telefone1);
                                            fprintf(client, "----------------------------------------------------------------- \n");
                                            fclose(client);
                                            printf("Dados gravados com sucesso!");
                                            printf("VOLTANDO AO MENU DE CADASTRO AO PRESSIONAR ENTER!");
                                            getch();
                                            system("cls");
}
void cadastroproduto(){
                                                system("cls");
                                                printf("|========================BEM VINDO AO CADASTRO DE PRODUTOS!====================|\n");
                                                FILE *prod;
                                                char Nproduto[50];
                                                float valor;
                                                char codigo[50];
                                                prod = fopen("produtos.txt", "a+");
                                                if (prod == NULL) {
                                                    printf("ERRO! Arquivo não foi aberto\n");
                                                    return 1;
                                                }
                                                printf("\n\n|===================== DIGITE AS INFORMAÇÕES A BAIXO! ==========================|\n ");
                                                printf("-------------------------------------------------------------------------------|\n");
                                                printf("CÓDIGO: ");
                                                scanf("%s", codigo);
                                                printf("-------------------------------------------------------------------------------|\n");
                                                printf("NOME DO PRODUTO: ");
                                                getchar(); // Limpa o buffer
                                                fgets(Nproduto, sizeof(Nproduto), stdin);
                                                Nproduto[strcspn(Nproduto, "\n")] = '\0'; // Remove a nova linha
                                                printf("-------------------------------------------------------------------------------|\n");
                                                printf("VALOR: ");

                                                // Lê o valor como string
                                                char valorStr[20];
                                                scanf("%s", valorStr);

                                                // Substitui a vírgula por ponto para garantir que seja lido corretamente como float
                                                for (int i = 0; valorStr[i] != '\0'; i++) {
                                                    if (valorStr[i] == ',') {
                                                        valorStr[i] = '.'; // Substitui a vírgula por ponto
                                                    }
                                                }

                                                // Converte a string para float
                                                sscanf(valorStr, "%f", &valor);

                                                // Verifica se a conversão foi bem-sucedida
                                                if (valor <= 0) {
                                                    printf("Valor inválido. Tente novamente.\n");
                                                    fclose(prod);
                                                    return 1;
                                                }

                                                fprintf(prod, "----------------------------------------------------------------- \n");
                                                fprintf(prod, "CÓDIGO: %s \n", codigo);
                                                fprintf(prod, "NOME PRODUTO: %s \n", Nproduto);
                                                fprintf(prod, "VALOR: %.2f \n", valor);
                                                fprintf(prod, "----------------------------------------------------------------- \n");
                                                fclose(prod);
                                                printf("Dados gravados com sucesso!");
                                                printf("VOLTANDO AO MENU DE CADASTRO AO PRESSIONAR ENTER!");
                                                getch();
                                                system("cls");
}
void cadastrofornecedor() {
                                            system("cls");
                                            printf("|----------------BEM VINDO AO CADASTRO DE FORNECEDORES-----------|\n");
                                            FILE *file;
                                            char fornecedores1[50];
                                            char nomefantasia[50];
                                            char cnpj[20];
                                            char email[50];
                                            char telefone[20];
                                            file = fopen("fornecedores.txt", "a+");
                                            if (file == NULL) {
                                                printf("ERRO! Arquivo não foi aberto\n");
                                                return 1;
                                            }
                                            printf("\n\n|----------------INSIRA OS DADOS A BAIXO-------------------------|\n ");
                                            printf("-------------------------------------------------------------------------------|\n");
                                            printf("CNPJ: ");
                                            getchar(); // Limpa o buffer
                                            fgets(cnpj, sizeof(cnpj), stdin);
                                            cnpj[strcspn(cnpj, "\n")] = '\0'; // Remove a nova linha
                                            printf("-------------------------------------------------------------------------------|\n");
                                            printf("NOME FANTASIA: ");
                                            fgets(nomefantasia, sizeof(nomefantasia), stdin);
                                            nomefantasia[strcspn(nomefantasia, "\n")] = '\0'; // Remove a nova linha
                                            printf("-------------------------------------------------------------------------------|\n");
                                            printf("NOME FORNECEDOR: ");
                                            fgets(fornecedores1, sizeof(fornecedores1), stdin);
                                            fornecedores1[strcspn(fornecedores1, "\n")] = '\0'; // Remove a nova linha
                                            printf("-------------------------------------------------------------------------------|\n");
                                            printf("EMAIL: ");
                                            fgets(email, sizeof(email), stdin);
                                            email[strcspn(email, "\n")] = '\0'; // Remove a nova linha
                                            printf("-------------------------------------------------------------------------------|\n");
                                            printf("TELEFONE: ");
                                            fgets(telefone, sizeof(telefone), stdin);
                                            telefone[strcspn(telefone, "\n")] = '\0'; // Remove a nova linha
                                            printf("-------------------------------------------------------------------------------|\n");
                                            fprintf(file, "----------------------------------------------------------------- \n");
                                            fprintf(file, "CNPJ: %s \n", cnpj);
                                            fprintf(file, "NOME FANTASIA: %s \n", nomefantasia);
                                            fprintf(file, "FORNECEDOR: %s \n", fornecedores1);
                                            fprintf(file, "EMAIL: %s \n", email);
                                            fprintf(file, "TELEFONE: %s \n", telefone);
                                            fprintf(file, "----------------------------------------------------------------- \n");
                                            fclose(file);
                                            printf("Dados gravados com sucesso!");
                                            printf("VOLTANDO AO MENU DE CADASTRO AO PRESSIONAR ENTER!");
                                            getch();
                                            system("cls");
}

void cadastrofuncionario(){

                                            system("cls");
                                            printf("|---------------CADASTRO DE FUNCIONÁRIO-----------|\n");
                                            printf("\n\n");
                                            FILE *func;
                                            char NomeFunc[101], Cargo[101], Cpf[15], Data_nascimento[101], Email[101], Telefone[101], Celular[101], LOGIN[20], SENHA[7];
                                            func = fopen("funcionario.txt", "a+");
                                            if (func == NULL) {
                                                printf("ERRO! Arquivo não foi aberto\n");
                                                return 1;
                                            }
                                            printf("-------------------------------------------------------------------------------|\n");
                                            printf("Cadastre o funcionário\n ");
                                            printf("-------------------------------------------------------------------------------|\n");
                                            printf("\nnome Funcionario: ");
                                            getchar(); // Limpa o buffer
                                            fgets(NomeFunc, sizeof(NomeFunc), stdin);
                                            NomeFunc[strcspn(NomeFunc, "\n")] = '\0'; // Remove a nova linha
                                            printf("-------------------------------------------------------------------------------|\n");
                                            printf("CARGO: ");
                                            fgets(Cargo, sizeof(Cargo), stdin);
                                            Cargo[strcspn(Cargo, "\n")] = '\0'; // Remove a nova linha
                                            printf("-------------------------------------------------------------------------------|\n");
                                            printf("CPF: ");
                                            fgets(Cpf, sizeof(Cpf), stdin);
                                            Cpf[strcspn(Cpf, "\n")] = '\0'; // Remove a nova linha
                                            printf("-------------------------------------------------------------------------------|\n");
                                            printf("DATA DE NASCIMENTO: ");
                                            fgets(Data_nascimento, sizeof(Data_nascimento), stdin);
                                            Data_nascimento[strcspn(Data_nascimento, "\n")] = '\0'; // Remove a nova linha
                                            printf("-------------------------------------------------------------------------------|\n");
                                            printf("EMAIL: ");
                                            fgets(Email, sizeof(Email), stdin);
                                            Email[strcspn(Email, "\n")] = '\0'; // Remove a nova linha
                                            printf("-------------------------------------------------------------------------------|\n");
                                            printf("TELEFONE: ");
                                            fgets(Telefone, sizeof(Telefone), stdin);
                                            Telefone[strcspn(Telefone, "\n")] = '\0'; // Remove a nova linha
                                            printf("-------------------------------------------------------------------------------|\n");
                                            printf("CELULAR: ");
                                            fgets(Celular, sizeof(Celular), stdin);
                                            Celular[strcspn(Celular, "\n")] = '\0'; // Remove a nova linha
                                            printf("-------------------------------------------------------------------------------|\n");
                                            fprintf(func, "-----------------------------------------------------------------\n");
                                            fprintf(func, "NOME FUNCIONARIO: %s\n", NomeFunc);
                                            fprintf(func, "CARGO: %s\n", Cargo);
                                            fprintf(func, "CPF: %s\n", Cpf);
                                            fprintf(func, "DATA DE NASCIMENTO: %s\n", Data_nascimento);
                                            fprintf(func, "EMAIL: %s\n", Email);
                                            fprintf(func, "TELEFONE: %s\n", Telefone);
                                            fprintf(func, "CELULAR: %s\n", Celular);
                                            fprintf(func, "-----------------------------------------------------------------\n");
                                            fclose(func);
                                            printf("Dados gravados com sucesso!");
                                            printf("VOLTANDO AO MENU DE CADASTRO AO PRESSIONAR ENTER!");
                                            getch();
                                            system("cls");
}

void cadastrousuario(){

                                            system("cls");
                                            printf("|---------------CADASTRO DE USUÁRIO-----------|\n");
                                            FILE *user;
                                            char login2[50];
                                            char senha2[50];
                                            user = fopen("usuario.txt", "a+");
                                            if (user == NULL) {
                                                printf("ERRO! Arquivo não foi aberto\n");
                                                return 1;
                                            }
                                            printf("Cadastre o usuário\n ");
                                            printf("-------------------------------------------------------------------------------|\n");
                                            printf("\nLOGIN: ");
                                            getchar(); // Limpa o buffer
                                            fgets(login2, sizeof(login2), stdin);
                                            login2[strcspn(login2, "\n")] = '\0'; // Remove a nova linha
                                            printf("-------------------------------------------------------------------------------|\n");
                                            printf("SENHA: ");
                                            fgets(senha2, sizeof(senha2), stdin);
                                            senha2[strcspn(senha2, "\n")] = '\0'; // Remove a nova linha

                                            fprintf(user, "----------------------------------------------------------------- \n");
                                            fprintf(user, "LOGIN: %s \n", login2);
                                            fprintf(user, "SENHA: %s \n", senha2);
                                            fprintf(user, "----------------------------------------------------------------- \n");
                                            fclose(user);
                                            printf("Dados gravados com sucesso!");
                                            printf("VOLTANDO AO MENU DE CADASTRO AO PRESSIONAR ENTER!");
                                            getch();
                                            system("cls");
}

void pesquisacliente (){

                                system("cls");
                                printf("Pesquisa de clientes! \n");

                                char clienteBusca[50];
                                printf("\nDigite o nome do cliente que deseja pesquisar: ");
                                scanf("%s", clienteBusca);

                                FILE *clientesFile;
                                clientesFile = fopen("cliente.txt", "r");
                                if (clientesFile == NULL) {
                                    printf("Erro ao abrir o arquivo de produtos.\n");
                                    getch();

                                }

                                char linha[256];
                                int encontrado = 0;
                                while (fgets(linha, sizeof(linha), clientesFile)) {
                                    if (strstr(linha, clienteBusca)) { // Verifica se a linha contém o código
                                        printf("%s", linha); // Imprime a linha encontrada
                                        encontrado = 1;
                                        // Lê as próximas linhas até a próxima linha de separação
                                        while (fgets(linha, sizeof(linha), clientesFile) && strcmp(linha, "----------------------------------------------------------------- \n") != 0) {
                                            printf("%s", linha);
                                        }
                                        printf("-----------------------------------------------------------------\n");
                                        break; // Para após encontrar o primeiro cliente correspondente
                                    }
                                }

                                if (!encontrado) {
                                    printf("Não encontramos um cliente com esse nome!!!\n", clienteBusca);
                                }

                                fclose(clientesFile);
                                char escolha3;
                                printf("\nDeseja realizar outra pesquisa? (S para sim, N para voltar ao menu principal): ");
                                getchar(); // Limpa o buffer de entrada
                                scanf("%c", &escolha3);

                                if (escolha3 == 'S' || escolha3 == 's') {
                                    pesquisacliente();
                                }else {
                                    printf("\npressione ENTER para voltar ao menu anterior");
                                getch();
                                }

}

void pesquisafornecedor (){

                                system("cls");
                                printf("Pesquisa de Fornecedores! \n");

                                char cnpjBusca[50];
                                printf("\nDigite o cnpj do fornecedor que deseja pesquisar: ");
                                scanf("%s", cnpjBusca);

                                FILE *fornecedoresFile;
                                fornecedoresFile = fopen("fornecedores.txt", "r");
                                if (fornecedoresFile == NULL) {
                                    printf("Erro ao abrir o arquivo de produtos.\n");
                                    getch();

                                }

                                char linha[256];
                                int encontrado = 0;
                                while (fgets(linha, sizeof(linha), fornecedoresFile)) {
                                    if (strstr(linha, cnpjBusca)) { // Verifica se a linha contém o código
                                        printf("%s", linha); // Imprime a linha encontrada
                                        encontrado = 1;
                                        // Lê as próximas linhas até a próxima linha de separação
                                        while (fgets(linha, sizeof(linha), fornecedoresFile) && strcmp(linha, "----------------------------------------------------------------- \n") != 0) {
                                            printf("%s", linha);
                                        }
                                        printf("-----------------------------------------------------------------\n");
                                        break; // Para após encontrar o primeiro CNPJ correspondente
                                    }
                                }

                                if (!encontrado) {
                                    printf("Fornecedor com CNPJ %s não encontrado.\n", cnpjBusca);
                                }

                                fclose(fornecedoresFile);
                                char escolha2;
                                printf("\nDeseja realizar outra pesquisa? (S para sim, N para voltar ao menu principal): ");
                                getchar(); // Limpa o buffer de entrada
                                scanf("%c", &escolha2);

                                if (escolha2 == 'S' || escolha2 == 's') {
                                    pesquisafornecedor();
                                }
                                printf("pressione ENTER para voltar ao menu anterior");
                                getch();

}

void pesquisaproduto() {

    system("cls");
    printf("=========================== PESQUISA DE PRODUTOS ===========================\n");
    printf("|==========================================================================|\n");

    char codigoBusca[50];
    printf("Digite o código do produto que deseja pesquisar: ");
    scanf("%s", codigoBusca);  // Lê o código de busca

    FILE *produtosFile;
    produtosFile = fopen("produtos.txt", "r");
    if (produtosFile == NULL) {
        printf("Erro ao abrir o arquivo de produtos.\n");
        getch();
        return;
    }

    char linha[256];
    int encontrado = 0;

    // Lê linha por linha do arquivo
    while (fgets(linha, sizeof(linha), produtosFile)) {
        char codigo[50];
        // Verifica se a linha contém o código exato
        if (strstr(linha, "CÓDIGO: ") != NULL) {
            sscanf(linha, "CÓDIGO: %s", codigo);  // Extraímos o código da linha

            // Verifica se o código lido é igual ao código de busca
            if (strcmp(codigo, codigoBusca) == 0) {
                encontrado = 1;
                printf("|==========================================================================|\n");
                printf("                PRODUTO ENCONTRADO!                                      \n");
                printf("|==========================================================================|\n");
                // Imprime o produto completo
                while (fgets(linha, sizeof(linha), produtosFile) && strcmp(linha, "----------------------------------------------------------------- \n") != 0) {
                    printf("%s", linha);
                }
                break;
            }
        }
    }

    if (!encontrado) {
        printf("|==========================================================================|\n");
        printf("Produto com código %s não encontrado.\n", codigoBusca);
        printf("|==========================================================================|\n");
    }

    fclose(produtosFile);
    printf("\n\n========   PRESSIONE ENTER PARA VOLTAR  ================");
    getch();
}

// Função que realiza a venda, com a lista de itens
void realizarVenda() {
    FILE *produtosFile;
    FILE *vendasFile;
    char codigoProduto[50], nomeProduto[50];
    float precoProduto, quantidade, totalItem;
    char continuar = 'S';
    int encontrado;

    // Limpar a lista de itens antes de iniciar a venda
    numeroItens = 0;
    totalVenda = 0;

    produtosFile = fopen("produtos.txt", "r");
    if (produtosFile == NULL) {
        printf("Erro ao abrir o arquivo de produtos.\n");
        return;
    }

    vendasFile = fopen("vendas.txt", "a"); // Abre o arquivo de vendas em modo "append"
    if (vendasFile == NULL) {
        printf("Erro ao abrir o arquivo de vendas.\n");
        fclose(produtosFile);
        return;
    }
    system("cls");
    printf("----------INICIANDO VENDA----------\n");

    while (continuar == 'S' || continuar == 's') {
        printf("-------------------------------------------------------------------------------|\n");
        printf("\nDigite o código do produto: ");
        scanf("%s", codigoProduto);

        encontrado = 0;
        char linha[256];
        fseek(produtosFile, 0, SEEK_SET); // Resetar a posição do arquivo para o início

        while (fgets(linha, sizeof(linha), produtosFile)) {
            if (strstr(linha, "CÓDIGO:") != NULL) {
                char codigoArmazenado[50];
                sscanf(linha, "CÓDIGO: %s", codigoArmazenado); // Ler o código do produto
                if (strcmp(codigoProduto, codigoArmazenado) == 0) { // Comparar o código digitado
                    encontrado = 1;

                    // Ler o nome do produto
                    fgets(linha, sizeof(linha), produtosFile);
                    sscanf(linha, "NOME PRODUTO: %[^\n]", nomeProduto);

                    // Ler o valor do produto
                    fgets(linha, sizeof(linha), produtosFile);
                    sscanf(linha, "VALOR: %f", &precoProduto);
                    break;
                }
            }
        }

        if (encontrado) {
            // Perguntar se o produto é vendido por unidade ou peso
            char tipoVenda;
            printf("Produto: %s\n", nomeProduto);
            printf("Valor unitário: %.2f\n", precoProduto);
            printf("O produto é vendido por:\n");
            printf("(1) Unidade\n");
            printf("(2) Peso\n");
            scanf(" %c", &tipoVenda);

            if (tipoVenda == '1') {
                // Venda por unidade
                printf("QUANTAS UNIDADES DESEJA INCLUIR? ");
                scanf("%f", &quantidade);
                totalItem = precoProduto * quantidade;
            } else if (tipoVenda == '2') {
                // Venda por peso
                printf("DIGITE O PESO? ");
                scanf("%f", &quantidade);
                totalItem = precoProduto * quantidade;
            } else {
                printf("Opção inválida para tipo de venda.\n");
                continue;
            }

            // Adicionando o produto à lista de itens
            strcpy(itens[numeroItens].codigo, codigoProduto);
            strcpy(itens[numeroItens].nome, nomeProduto);
            itens[numeroItens].preco = precoProduto;
            itens[numeroItens].quantidade = quantidade;
            itens[numeroItens].totalItem = totalItem;

            numeroItens++;  // Incrementa o número de itens
            totalVenda += totalItem;  // Atualiza o total da venda
        } else {
            printf("Produto não encontrado!\n");
        }

        system("cls");  // Limpa a tela

        // Exibe a lista de itens
        printf("\n---- ITENS ADICIONADOS ----\n");
        for (int i = 0; i < numeroItens; i++) {
            if (itens[i].quantidade > 1) {
                // Exibe peso quando for por peso
                printf("Código: %s | Produto: %s | PESO KG: %.2f | Preço: %.2f | Total: %.2f\n",
                    itens[i].codigo, itens[i].nome, itens[i].quantidade, itens[i].preco, itens[i].totalItem);
            } else {
                // Exibe quantidade normal quando for por unidade
                printf("Código: %s | Produto: %s | Quantidade: %.0f | Preço: %.2f | Total: %.2f\n",
                    itens[i].codigo, itens[i].nome, itens[i].quantidade, itens[i].preco, itens[i].totalItem);
            }
        }

        // Exibe o total da venda com cores ajustadas para contraste
        colorirTexto("\033[1;31m"); // Vermelho para o título "Total da venda"
        printf("\nTotal da venda: ");
        colorirTexto("\033[0m"); // Reseta a cor para o padrão
        colorirTexto("\033[1;32m"); // Verde para o valor total
        printf("%.2f\n", totalVenda);
        colorirTexto("\033[0m"); // Reseta a cor do texto

        // Pergunta se o usuário deseja adicionar mais produtos
        printf("\nDeseja adicionar mais produtos? (S para sim, N para não): ");
        getchar(); // Limpa o buffer de entrada
        scanf("%c", &continuar);
    }

    // Salva a venda no arquivo de vendas
    time_t now = time(NULL);
    struct tm *tm_info = localtime(&now);
    char data[26];
    strftime(data, 26, "%Y-%m-%d %H:%M:%S", tm_info); // Formata a data atual

    fprintf(vendasFile, "Data: %s\n", data);
    fprintf(vendasFile, "Total da venda: %.2f\n", totalVenda);
    fprintf(vendasFile, "----------------------------------------\n");

    fclose(produtosFile);
    fclose(vendasFile);

    // Pergunta pela forma de pagamento com validação
    char formaPagamento;
    int pagamentoValido = 0;
    while (!pagamentoValido) {
        printf("\nEscolha a forma de pagamento:\n");
        printf("-------------------------------------------------------------------------------|\n");
        printf("(1) Dinheiro\n");
        printf("-------------------------------------------------------------------------------|\n");
        printf("(2) Cartão\n");
        printf("-------------------------------------------------------------------------------|\n");
        printf("(3) Pix\n");
        printf("-------------------------------------------------------------------------------|\n");
        scanf(" %c", &formaPagamento);

        if (formaPagamento == '1' || formaPagamento == '2' || formaPagamento == '3') {
            pagamentoValido = 1; // Forma de pagamento válida
        } else {
            printf("Opção de pagamento incorreta! Tente novamente.\n");
        }
    }

    if (formaPagamento == '1') {
        system("cls");
        float valorPago;
        printf("-------------------------------------------------------------------------------|\n");
        printf("Digite o valor pago pelo cliente: ");
        scanf("%f", &valorPago);

        if (valorPago < totalVenda) {
            printf("Valor insuficiente! O pagamento não pode ser concluído.\n");
        } else {
            float troco = valorPago - totalVenda;
            printf("Troco: %.2f\n", troco);
        }
    } else if (formaPagamento == '2' || formaPagamento == '3') {
        printf("-------------------------------------------------------------------------------|\n");
        printf("Por favor, dirija-se à máquina para realizar o pagamento.\n");
        printf("-------------------------------------------------------------------------------|\n");
        printf("Digite qualquer tecla após o pagamento ser efetuado...\n");
        printf("-------------------------------------------------------------------------------|\n");
        getch();
    }

    // Pergunta se deseja realizar outra venda ou voltar ao menu principal
    char escolha;
    printf("\nDeseja realizar outra venda? (S para sim, N para voltar ao menu principal): ");
    getchar(); // Limpa o buffer de entrada
    scanf("%c", &escolha);

    if (escolha == 'S' || escolha == 's') {
        realizarVenda(); // Chama a função de venda novamente
    }
}
void totalVendas() {
    FILE *vendasFile;
    char linha[256];
    float totalVendasDia = 0;

    vendasFile = fopen("vendas.txt", "r");
    if (vendasFile == NULL) {
        printf("Erro ao abrir o arquivo de vendas.\n");
        return;
    }

    // Cabeçalho
    printf("\n========================================\n");
    printf("        RELATÓRIO DE VENDAS:\n");
    printf("========================================\n");

    while (fgets(linha, sizeof(linha), vendasFile)) {
        if (strstr(linha, "Data:") != NULL) {
            printf("\n%s", linha); // Exibe a data da venda
        }
        if (strstr(linha, "Total da venda:") != NULL) {
            float total;
            sscanf(linha, "Total da venda: %f", &total);
            printf("%s", linha); // Exibe o total da venda
            totalVendasDia += total;
        }
        if (strstr(linha, "Produtos vendidos:") != NULL) {
            printf("  Produtos vendidos:\n");
            while (fgets(linha, sizeof(linha), vendasFile) && strstr(linha, "----------------------------------------") == NULL) {
                printf("    - %s", linha); // Exibe os produtos vendidos com uma indentação
            }
        }
    }

    // Exibe o total acumulado com destaque
    printf("\n========================================\n");
    printf("    RELATÓRIO DE VENDAS: %.2f\n", totalVendasDia);
    printf("========================================\n");

    fclose(vendasFile);
}

void esconderSenha(char *senha) {
    char c;
    int i = 0;

    while (1) {
        c = getch(); // Captura o caractere sem exibi-lo
        if (c == '\r') { // Se a tecla Enter for pressionada
            senha[i] = '\0'; // Finaliza a string
            break;
        } else if (c == '\b') { // Se a tecla Backspace for pressionada
            if (i > 0) {
                i--;
                printf("\b \b"); // Remove o último asterisco
            }
        } else {
            senha[i++] = c; // Adiciona o caractere à string
            printf("*"); // Mostra um asterisco
        }
    }
}

void voltarMenuPrincipal() {
    printf("VOLTANDO AO MENU PRINCIPAL... Pressione Enter para continuar.");
    getch();
    system("cls");
}
int main() {
    setlocale(LC_ALL, "");

    strcpy(p[0].login, "admin");
    strcpy(p[0].senha, "admin");

    char login[30];
    char senha[30];
    int opcao, opcao1, opcao2, opcao3, opcao4;

                        printf("-------------------------------------------------------------------------------\n");
                        printf("-------------------------------------------------------------------------------\n");
                        printf("-------------------------------------------------------------------------------\n");
                        printf("--------------------BEM VINDO AO HORTFRUTI KUNG-FU MANGA!----------------------\n");
                        printf("-------------------------------------------------------------------------------\n");
                        printf("-------------------------------------------------------------------------------\n");
                        printf("-------------------------------------------------------------------------------\n");

    // Aguardar pressionamento de Enter
    printf("Pressione Enter para continuar...");
    getch();
    system("cls");

    while (1) { // Loop infinito até o usuário sair

            system("cls");
        printf("DIGITE A OPÇÃO QUE DESEJA ACESSAR!\n");
        printf("-------------------------------------------------------------------------------|\n");
        printf("(1) ADMINISTRATIVO\n");
        printf("-------------------------------------------------------------------------------|\n");
        printf("(2) CAIXA\n");
        printf("-------------------------------------------------------------------------------|\n");
        printf("(3) LISTA DE FORNECEDORES\n");
        printf("-------------------------------------------------------------------------------|\n");
        printf("(4) LISTA DE CLIENTES\n");
        printf("-------------------------------------------------------------------------------|\n");
        printf("(5) LISTA DE PRODUTOS\n");
        printf("-------------------------------------------------------------------------------|\n");
        printf("(6) SAIR DO PROGRAMA\n");
        printf("-------------------------------------------------------------------------------|\n");
        scanf("%d", &opcao);
        system("cls");

        if (opcao < 1 || opcao > 6) {
            printf("Opção inválida!\n");
            continue; // Retorna ao início do loop
        }

switch (opcao) {
            case 1:
                while (1) {
                    system("cls");
                    printf("------------------------------------------------------------\n");
                    printf("\n                  BEM VINDO ADMINISTRADOR!        \n");
                    printf("------------------------------------------------------------\n");
                    printf("|---DIGITE SUAS CREDÊNCIAS!---|\n");
                    printf("\nLogin: ");
                    scanf("%s", login);
                    printf("-------------|\n");
                    printf("\nSenha: ");
                    esconderSenha(senha);
                    printf("\n");

                    if ((strcmp(login, p[0].login) == 0) && (strcmp(senha, p[0].senha) == 0)) {
                        printf("\nUsuário logado!!!!\n");
                        system("cls");
                        while (1) {
                             system("cls");
                        printf("-------------------------------------------------------------------------------|\n");
                        printf("(1) CADASTRO\n");
                        printf("-------------------------------------------------------------------------------|\n");
                        printf("(2) PESQUISA\n");
                        printf("-------------------------------------------------------------------------------|\n");
                        printf("(3) TOTAL VENDIDO\n");
                        printf("-------------------------------------------------------------------------------|\n");
                        printf("(4) VOLTAR AO MENU ANTERIOR\n");
                        printf("-------------------------------------------------------------------------------|\n");
                        scanf("%d", &opcao1);
                        if (opcao1 == 4)break;


                          switch (opcao1) {
                                case 1:
                                  system("cls");
                                printf("-----------------------BEM VINDO AO MENU DE CADASTRO-------------------\n");
                                printf("-------------------------------------------------------------------------------|\n");
                                printf("(1) CADASTRAR USUARIO\n");
                                 printf("-------------------------------------------------------------------------------|\n");
                                printf("(2) CADASTRAR FUNCIONÁRIO\n");
                                printf("-------------------------------------------------------------------------------|\n");
                                printf("(3) CADASTRAR FORNECEDORES\n");
                                printf("-------------------------------------------------------------------------------|\n");
                                printf("(4) CADASTRAR PRODUTOS\n");
                                printf("-------------------------------------------------------------------------------|\n");
                                printf("(5) CADASTRAR CLIENTE\n");
                                printf("-------------------------------------------------------------------------------|\n");
                                printf("(6) VOLTAR AO MENU ANTERIOR\n");
                                printf("-------------------------------------------------------------------------------|\n");
                                scanf("%d", &opcao2);
                                if (opcao2 == 6) break;

                                    switch (opcao2) {
                                        case 1:
                                           cadastrousuario();
                                            break;

                                        case 2:
                                           cadastrofuncionario();
                                            break;
                                        case 3:
                                            cadastrofornecedor();
                                            break;

                                        case 4:
                                           cadastroproduto();
                                            break;


                                        case 5:
                                           cadastrocliente();
                                            break;


                                        default:
                                            printf("Opção inválida.\n");
                                            getch();
                                    }
                                    break;

                    case 2:
                        system("cls");
                        printf("-------------------------------------------------------------------------------\n");
                        printf("-------------------------------------------------------------------------------\n");
                        printf("-------------------------------------------------------------------------------\n");
                        printf("--------------------------BEM VINDO AO MENU DE PESQUISA!-----------------------\n");
                        printf("-------------------------------------------------------------------------------\n");
                        printf("-------------------------------------------------------------------------------\n");
                        printf("-------------------------------------------------------------------------------\n");
                        printf("SELECIONE A OPÇÃO QUE DESEJA PESQUISAR!!!\n");
                        printf("-------------------------------------------------------------------------------|\n");
                        printf("(1)FORNECEDORES\n");
                        printf("-------------------------------------------------------------------------------|\n");
                        printf("(2)PRODUTOS\n");
                        printf("-------------------------------------------------------------------------------|\n");
                        printf("(3)CLIENTE\n");
                        printf("-------------------------------------------------------------------------------|\n");
                        printf("(4) VOLTAR AO MENU ANTERIOR\n");
                        printf("-------------------------------------------------------------------------------|\n");
                                scanf("%d", &opcao3);
                          if (opcao3 == 1) {
                                    // Iniciar venda
                                    system ("cls");
                                    pesquisafornecedor();
                                    break; //
                                } else if (opcao3 == 2) {
                                    // pesquisa produto
                                    pesquisaproduto();
                                    break;
                                   } else if (opcao3 == 3) {
                                    // pesquisa cliente
                                    pesquisacliente();
                                    break;
                                } else {
                                    printf("VOLTANDO AO MENU ANTERIOR.\n");
                                    getch(); // Aguarda uma tecla para continuar
                                }

                            break;


                    case 3:
                        system("cls");
                                printf("VENDA TOTAL DO DIA.\n");
                                totalVendas();
                                printf("pressione ENTER para voltar ao menu anterior!");
                                getch();
                                system("cls");
                                break;

                            default:
                                printf("Opção inválida.\n");
                                getch();
                        }
                    }
                } else {
                    printf("Usuário ou senha inválidos!\n");
                    printf("PRESSIONE ENTER PARA VOLTAR AO MENU!\n");
                    getch();
                    system("cls");
                }
                break;

            case 2:

                            printf("BEM VINDO AO CAIXA.\n");

                            // Novo menu com opções de iniciar venda ou voltar
                            while (1) {
                                system("cls");
                                printf("------------------------------------------------------------|\n");
                                printf("---------------------MENU DE CAIXA--------------------------|\n");
                                printf("------------------------------------------------------------|\n\n\n");
                                char loginCaixa[30], senhaCaixa[30];
                                printf("\nDigite seu login: ");
                                scanf("%s", loginCaixa);
                                printf("Digite sua senha: ");
                                esconderSenha(senhaCaixa); // Função para esconder a senha enquanto digita
                                printf("\n");

                                // Autenticar o usuário
                                if (autenticarUsuario(loginCaixa, senhaCaixa)) {
                                system("cls");
                                printf("\nLogin bem-sucedido! Acesso autorizado ao Caixa.\n");
                                printf("-------------------------------------------------------------------------------|\n");
                                printf("(1) Iniciar Venda\n");
                                printf("-------------------------------------------------------------------------------|\n");
                                printf("(2) Voltar ao Menu Principal\n");
                                printf("-------------------------------------------------------------------------------|\n");
                                printf("Escolha a opção desejada: ");
                                scanf("%d", &opcao2);
                                printf("\n-------------------------------------------------------------------------------|\n");

                                if (opcao2 == 1) {
                                    // Iniciar venda
                                    system ("cls");
                                    realizarVenda();
                                    break; // Depois de realizar a venda, volta ao menu de caixa
                                } else if (opcao2 == 2) {
                                    // Voltar ao menu principal
                                    voltarMenuPrincipal();
                                    break;
                                } else {
                                    printf("\nUsuário ou senha inválidos! Tente novamente.\n");
                                    getch();  // Aguardar para o usuário ver a mensagem
                                }

                                } else {
                                    printf("Opção inválida! Tente novamente.\n");
                                    getch(); // Aguarda uma tecla para continuar
                                }
                            }
                            break;
            case 3:
                printf("--------------------------LISTA DE FORNECEDORES---------------------\n");
                     FILE *file;
                                        file = fopen("fornecedores.txt", "r");
                                        if (file == NULL) {
                                            printf("Erro ao abrir o arquivo de fornecedores.\n");
                                            getch();
                                            break;
                                        }

                                        char linha[256];
                                        while (fgets(linha, sizeof(linha), file)) {
                                            printf("%s", linha); // Imprime cada linha do arquivo
                                        }

                                        fclose(file);
                                        printf("\nPressione Enter para continuar...\n");
                                        getch();
                                        system("cls");
                                        break;

            case 4:
                printf("----------------LISTA DE CLIENTES----------------\n");

                                        FILE *client;
                                        client = fopen("cliente.txt", "r");
                                        if (client == NULL) {
                                            printf("Erro ao abrir o arquivo de clientes.\n");
                                            getch();
                                            break;
                                        }

                                        char linha2[256];
                                        while (fgets(linha2, sizeof(linha2), client)) {
                                            printf("%s", linha2); // Imprime cada linha do arquivo
                                        }

                                        fclose(client);
                                        printf("\nPressione Enter para continuar...");
                                        getch();
                                        system("cls");

                                        break;


            case 5:
                printf("-----------------LISTA DE PRODUTOS------------\n");

                                        FILE *produtosFile;
                                        produtosFile = fopen("produtos.txt", "r");
                                        if (produtosFile == NULL) {
                                            printf("Erro ao abrir o arquivo de produtos.\n");
                                            getch();
                                            break;
                                        }

                                        char linha1[256];
                                        while (fgets(linha1, sizeof(linha1), produtosFile)) {
                                            printf("%s", linha1); // Imprime cada linha do arquivo
                                        }

                                        fclose(produtosFile);
                                        printf("\nPressione Enter para continuar...");
                                        getch();
                                        system("cls");
                                        break;

            case 6:
                printf("SAINDO DO PROGRAMA...\n");
                exit(0);

            default:
                printf("Opção inválida!\n");
                getch();
        }
    }
 }
    return 0;
}
