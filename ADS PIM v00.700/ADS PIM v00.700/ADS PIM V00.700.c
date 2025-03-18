#include <io.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
typedef struct Produto
{
    char cvNome[500];
    char cvValidade[100];
    float fValor;
    int iQtdEstoque;
    int iEstoqSeguranca;
    char cvCodigo[50];
    char cvSetor[200];
    int iCodigoFornecedor;
    struct Produto *pProximo;
} Produto;
typedef struct Fornecedor
{
    char cvNome[101];
    char cvNomeFantasia[101];
    char cvEndereco[101];
    char cvCnpj[20];
    char cvEmail[101];
    char cvTelefone[101];
    char cvCelular[101];
    int iCodigoProduto;
    struct Fornecedor *fProximo;
} Fornecedor;
typedef struct Cliente
{
    char cvNomeCli[200];
    char cvCpf[15];
    char cvData_nascimento[101];
    char cvEmail[101];
    char cvTelefone[101];
    char cvCelular[101];
    char cvEndereco[101];
    struct Cliente *cProximo;
} Cliente;
typedef struct Funcionario
{
    char cvNomeFunc[101];
    char cvCargo[101];
    char cvCpf[15];
    char cvData_nascimento[101];
    char cvEmail[101];
    char cvTelefone[101];
    char cvCelular[101];
    char cvEndereco[101];
    char cvLogin[20];
    char cvSenha[07];
    struct Funcionario *funProximo;
} Funcionario;
typedef struct Venda
{
 int iDia;
 int iMes;
 int iAno;
 int iCodVenda;
 float dTotalCompra;
    struct Venda *vendaProximo;
} Venda;
typedef struct itemVenda{
 char cvNomeItem[201];
 float fValorItem;
 struct ItemVenda *iItemProximo;
}ItemVenda;
/* DECLARACAO DE STRUCTS */
Produto *pProdutoInicial = NULL;
Fornecedor *fFornecedorInicial = NULL;
Cliente *cClienteInicial = NULL;
Funcionario *fFuncionarioInicial = NULL;
Venda *vVendaInicial = NULL;
ItemVenda *iItemVendaInicial = NULL;
char cvAdm [10];
int iHaveLogin = 0;
char cvNFuncionario[200];
char cvCargoFunc[200];
char cvNomeCli[200];
/* DECLARACAO DE  FUNCOES */
void sair();
void defaultMessage();
void removidoSucesso(char cvNomeFuncao[], char cvNomeItem[]);
void editMessage(char cvFunction[]);
void alteradoSucesso(char cvContext[]);
void nullList();
void notFound(char cvName[]);
void nullDelete();
void listarProdutos();
void removeProduto();
void listarFornecedor();
void alteraFornecedor();
void removeFornecedor();
void listarCliente();
void alteraCliente();
void removeCliente();
void listarFuncionario();
void alteraFuncionario();
void removeFuncionario();
void CadastroLogin(char cvCadastroLogin[],char cvCadastroSenha[]);
void VerificarLogin();
void tela(char tela[]);
void listarVenda();
void listaItemVenda(float fTotalVenda);
void listarEstoque(char Nome[]);
void verificaEstoqueSegurancao();
/* DECLARACAO DE FUNCOES QUE RETORNAM VALOR */
int menuPrincipal();
int menu();
int menuCaixa();
int menuListar();
int menuAlterar();
int menuRemover();
void menuVenda();
int menuEstoque();
char escolhaRegistro();
int menuCadastro();
int cadastrarProduto();
int alteraCodigoProduto();
int alteraNomeProduto();
int alteraValorProduto();
int alteraQtdProduto();
int alteraEstoqueSeg();
void listarEstoque();
int cadastrarFornecedor();
int cadastrarCliente();
int cadastrarFuncionario();
int venda();
float addItemVenda();
int addVenda(float totalVenda);
void addStructVenda(Venda *vNovaVenda);
void tiraEstoque();
void vendaRealizada(char mensagem[]);
int pesqVendaData();
int verificaCliente();
/* CHAR FUNCTIONS */
float pegaValorProd();
int FormatarData();
int FormatarTelefone();
int FormatarCelular();
int FormatarCPF();
int Nome();
/* Arquivos Functions */
int gravarProduto();
int gravarFuncionario();
int gravarLogin();
int gravarCliente();
int gravarFornecedor();
int gravarItemVenda();
int gravarVenda();
int gravarAdm(char adm[]);
int lerProduto();
int lerFuncionario();
int lerLogin();
int lerCliente();
int lerFornecedor();
int lerItemVenda();
int lerVenda();
int lerAdm(char adm[]);
int main(){
 //ler dados dos arquivos
 lerAdm(cvAdm);
 lerProduto();
 lerFuncionario();
 lerFornecedor();
 lerCliente();
 //lerItemVenda();
 lerVenda();
 VerificarLogin();
    return 0;
}
void sair(){
 gravarProduto();
    printf("\nObrigado por utilizar o programa!!!\n");
}
void defaultMessage(){
    printf("\nPor favor, entre com uma opcao valida!\n");
}
void editMessage(char cvFunction[]){
    printf("\nEntre com o nome do %s a ser alterado: ", cvFunction);
}
void alteradoSucesso(char cvContext[]){
 printf("\n\t\t\t%s foi alterado(a) com sucesso!!!\n", cvContext);
}
void removidoSucesso(char cvNomeFuncao[], char cvNomeItem[]){
 printf("\n\t\t\tO %s %s foi removido com sucesso!!\n", cvNomeFuncao, cvNomeItem);
}
void nullList(){
    printf("\nNao ha registros para serem listados!!!\n");
    printf("\n\t\t\t\t   PRESSIONE QUALQUER TECLA PARA VOLTAR!");
}
void notFound(char cvName[]){
 printf("\n%s nao encontrado(a)!", cvName);
}
void nullDelete(){
    printf("\nNao ha registros para serem removidos!!\n");
}
char escolhaRegistro(){
    char cEscolha = 's';
    do{
     printf("\nDeseja cadastrar um novo registro?(s/n) \n");
     scanf(" %c", &cEscolha);
     if(cEscolha == 's' || cEscolha == 'S' || cEscolha == 'n' || cEscolha == 'N') break;
 }while(cEscolha != 's' || cEscolha == 'S' || cEscolha != 'n' || cEscolha != 'N');
    return cEscolha;
}
void verificaEstoqueSegurancao(){
 Produto *pAux = pProdutoInicial;
 while(pAux != NULL){
  if(pAux->iQtdEstoque < pAux->iEstoqSeguranca){
    printf("\n\n================================================================================================================================================================================================================================================\n");
   printf("%s precisa que seu estoque seja reabastecido!!!\n", pAux->cvNome);
    printf("================================================================================================================================================================================================================================================\n\n");
  }
  pAux = pAux->pProximo;
 }
}
int menuPrincipal()
{
    int iOp;
     Funcionario *fAux = fFuncionarioInicial;
    system("cls || clear");
                 printf("================================================================================================================================================================================================================================================");
        printf("\t\t\t  v00.700\n\n");
        printf("\t\t\t\t*********************************************\n");
        printf("\t\t\t\t\t\t   MENU\n");
        printf("\t\t\t\t*********************************************\n");
                 printf("   %s: ", cvCargoFunc);
                 printf("%s ", cvNFuncionario);
        printf("\n\t\t\t\t\t\t\t\t\t\t\t\tADS PIZZARIA\n");
        printf("================================================================================================================================================================================================================================================\n");
 verificaEstoqueSegurancao();
 	printf("========================================================================================================================\n");
    printf("========================================================================================================================\n");
    printf("===============================|  0 - Fazer Logof	|===============================================================\n");
    printf("===============================|  1 - Cadastros		|===============================================================\n");
    printf("===============================|  2 - Caixa		|===============================================================\n");
    printf("===============================|  3 - Controle de Vendas|===============================================================\n");
    printf("===============================|  4 - Estoque		|===============================================================\n");
    printf("=======================================================================================================================\n");
    printf("=======================================================================================================================\n");
    printf("============================== |      DIGITE UMA OPCAO        | =======================================================\n");
    printf("==================================== |	");
    	scanf("%d", &iOp);
    return iOp;
}
int menu()
{
    int iOp;
    do
    {
        iOp = menuPrincipal();
        switch (iOp)
        {
        case 0:
         system("cls || clear");
            VerificarLogin();
            break;
        case 1:
            system("cls || clear");
            menuCadastro();
            break;
        case 2:
            system("cls || clear");
   			venda ();
            break;
        case 3:
            system("cls || clear");
            menuVenda();
            break;
        case 4:
            system("cls || clear");
            menuEstoque();
            break;
        default: defaultMessage(); break;
        }
    } while (iOp != 0);
}
int menuCaixa()
{
    int iOp;
    do
    {
         Funcionario *fAux = fFuncionarioInicial;
    system("cls || clear");
                 printf("================================================================================================================================================================================================================================================");
        printf("\t\t\t    v00.700\n\n");
        printf("\t\t\t\t*********************************************\n");
        printf("\t\t\t\t\t\t   MENU\n");
        printf("\t\t\t\t*********************************************\n");
                 printf("   %s: ", cvCargoFunc);
                 printf("%s ", cvNFuncionario);
        printf("\n\t\t\t\t\t\t\t\t\t\t\t\tADS PIZZARIA\n");
        printf("================================================================================================================================================================================================================================================\n");
      	printf("========================================================================================================================\n");
    printf("===============================|  0 - Fazer Logof	|===============================================================\n");
    printf("===============================|  1 - Venda		|===============================================================\n");
    printf("===============================|  2 - Cardapio		|===============================================================\n");
    printf("=======================================================================================================================\n");
    printf("=======================================================================================================================\n");
    printf("============================== |      DIGITE UMA OPCAO        | ========================================================\n");
    printf("==================================== |	");
     scanf("%d", &iOp);
     switch(iOp){
      case 0: VerificarLogin(); break;
      case 1: venda(); break;
      case 2: listarCestoque ("Cardapio"); break;
      
  }
    } while (iOp != 0);
}
int menuCadastro()
{
    int iOp;
    do
    {
     tela("\t MENU CADASTROS ");
 	printf("========================================================================================================================\n");
    printf("========================================================================================================================\n");
    printf("===============================|  0 - Voltar 		   	|=======================================================\n");
    printf("===============================|  1 - Cadastrar Funcionario	|=======================================================\n");
    printf("===============================|  2 - Cadastrar Cliente    	|=======================================================\n");
    printf("===============================|  3 - Cadastrar Produto    	|=======================================================\n");
    printf("===============================|  4 - Cadastrar Cardapio   	|=======================================================\n");
    printf("===============================|  5 - Cadastrar Fornecedor 	|=======================================================\n");
    printf("===============================|  6 - Listar		   	|=======================================================\n");
    printf("===============================|  7 - Alterar		   	|=======================================================\n");
    printf("===============================|  8 - Remover 		   	|=======================================================\n");
    printf("=======================================================================================================================\n");
    printf("========================================================================================================================\n");
    printf("============================== |      DIGITE UMA OPCAO        | ========================================================\n");
    printf("==================================== |	");
        scanf("%d", &iOp);
        switch (iOp)
        {
        case 0:
         system("cls || clear");
            break;
        case 1:
            cadastrarFuncionario();
            break;
        case 2:
            cadastrarCliente();
            break;
        case 3:
            cadastrarProduto();
            break;
        case 4:
            cadastroPizza ();	
            break;
        case 5:
            cadastrarFornecedor();
            break;
        case 6:
            menuListar();
            break;
        case 7:
            menuAlterar();
            break;
        case 8:
            menuRemover();
            break;
        default:
            defaultMessage();
            break;
        }
    } while (iOp != 0);
}
int menuListar(){
    int iOp;
    do{
        tela("\t    LISTAR CADASTROS");
        
 	printf("========================================================================================================================\n");
    printf("========================================================================================================================\n");
    printf("===============================|  0 - Voltar 		|==============================================================\n");
    printf("===============================|  1 - Listar Funcionario|==============================================================\n");
    printf("===============================|  2 - Listar Cliente    |===============================================================\n");
    printf("===============================|  3 - Listar Produto    |==============================================================\n");
    printf("===============================|  4 - Listar Fornecedor |==============================================================\n");
    printf("===============================|  5 - Listar Cardapio   |==============================================================\n");
    printf("=======================================================================================================================\n");
    printf("=======================================================================================================================\n");
    printf("============================== |      DIGITE UMA OPCAO        | =======================================================\n");
    printf("==================================== |	");
    scanf("%d", &iOp);
        switch(iOp){
            case 0: system("cls || clear");break;
            case 1: listarFuncionario(); break;
            case 2: listarCliente();break;
            case 3: listarProdutos();break;
            case 4: listarFornecedor();break;
            case 5: listarProdutos("Cardapio");break;
            default: defaultMessage();break;
        }
    }while(iOp != 0);
}
int menuAlterar()
{
    int iOp;
    do
    {
        tela("\t    ALTERAR CADASTROS");
	printf("========================================================================================================================\n");
    printf("========================================================================================================================\n");
    printf("===============================|  0 - Voltar 		 |==============================================================\n");
    printf("===============================|  1 - Alterar Funcionario|==============================================================\n");
    printf("===============================|  2 - Alterar Cliente    |==============================================================\n");
    printf("===============================|  3 - Alterar Produto    |==============================================================\n");
    printf("===============================|  4 - Alterar Fornecedor |==============================================================\n");
    printf("=======================================================================================================================\n");
    printf("=======================================================================================================================\n");
    printf("============================== |      DIGITE UMA OPCAO        | =======================================================\n");
    printf("==================================== |	");
        scanf("%d", &iOp);
        switch (iOp)
        {
        case 0:
            menuCadastro();
            break;
        case 1:
            alteraFuncionario();
            break;
        case 2:
            alteraCliente();
            break;
        case 3:
            alteraProduto();
            break;
        case 4:
            alteraFornecedor();
            break;
        default:
            defaultMessage();
            break;
        }
    } while (iOp < 0 || iOp > 4);
}
int menuRemover(){
 int iOp;
 do{
  tela("\t    REMOVER CADASTROS");
    printf("========================================================================================================================\n");
    printf("========================================================================================================================\n");
    printf("===============================|  0 - Voltar 		 |==============================================================\n");
    printf("===============================|  1 - Remover Funcionario|==============================================================\n");
    printf("===============================|  2 - Remover Cliente    |==============================================================\n");
    printf("===============================|  3 - Remover Produto    |==============================================================\n");
    printf("===============================|  4 - Remover Fornecedor |==============================================================\n");
    printf("=======================================================================================================================\n");
    printf("=======================================================================================================================\n");
    printf("============================== |      DIGITE UMA OPCAO        | =======================================================\n");
    printf("==================================== |	");
        scanf("%d", &iOp);
        switch(iOp){
         case 0:
          menuCadastro();
          break;
         case 1:
          removeFuncionario();
          break;
         case 2:
          removeCliente();
          break;
         case 3:
          removeProduto();
          break;
         case 4:
          removeFornecedor();
          break;
         default:
          defaultMessage();
          break;
  }
 }while(iOp < 0 || iOp > 4);
}

void menuVenda(){
 int iDia, iMes, iAno, iNaoEncontrado=0;
 int iOp;
 do{
  Venda *vAux = vVendaInicial;
  tela("\t    LISTA DE VENDAS");
    printf("========================================================================================================================\n");
    printf("========================================================================================================================\n");
    printf("===============================|  0 - Voltar		      |======================================================\n");
    printf("===============================|  1 - Listar todas as vendas  |=========================================================\n");
    printf("===============================|  2 - Pesquisar Venda por Data|=========================================================\n");
    printf("===============================|  3 - Pesquisar por dia       |=========================================================\n");
    printf("===============================|  4 - Pesquisar por mes       |=========================================================\n");
    printf("=======================================================================================================================\n");
    printf("=======================================================================================================================\n");
    printf("============================== |      DIGITE UMA OPCAO        | =======================================================\n");
    printf("==================================== |	");
  scanf("%d", &iOp);
  switch(iOp){
   case 0: system("cls || clear"); break;
   case 1: listarVenda(); break;
   case 2: pesqVendaData();break;
   case 3: system("cls || clear");
   tela("\tLISTA DE VENDAS POR DIA");
   if(vVendaInicial == NULL){
            nullList();
       }else{
    printf("============================== |      ENTRE COM O DIA DESEJADO        | ===============================================\n");
    printf("==================================== |	");
     scanf("%d", &iDia);
     while(vAux != NULL)
     {
      if(vAux->iDia == iDia)
      {
       printf("Data: %d/%d/%d\t|\tCodigo Venda: %d\t|\t Total da Venda: R$%.2f\n", vAux->iDia, vAux->iMes, vAux->iAno,vAux->iCodVenda, vAux->dTotalCompra);
       printf("\n========================================================================================================================\n");
      }else{
       notFound("Venda");
      }
      vAux = vAux->vendaProximo;
     printf("\n\t\t\t\t   PRESSIONE QUALQUER TECLA PARA VOLTAR!");
     }
    }
    fflush(stdin);
        getchar();
     break;
   case 4: tela("\tLISTA DE VENDAS POR MES");
     if(vVendaInicial == NULL){
            nullList();
       }else{
    printf("============================== |      ENTRE COM O MES DESEJADO        | ==============================================\n");
    printf("==================================== |	");
     scanf("%d", &iMes);
     while(vAux != NULL)
     {
      if(vAux->iMes == iMes)
      {
       printf("Data: %d/%d/%d\t|\tCodigo Venda: %d\t|\t Total da Venda: R$%.2f\n", vAux->iDia, vAux->iMes, vAux->iAno,vAux->iCodVenda, vAux->dTotalCompra);
       printf("\n========================================================================================================================\n");
      }else{
       notFound("Venda");
      }
      vAux = vAux->vendaProximo;
     printf("\n\t\t\t\t   PRESSIONE QUALQUER TECLA PARA VOLTAR!");
     }
    }
    fflush(stdin);
        getchar();
     break;
  }
 }while(iOp != 0);
}
int menuEstoque(){
 int op;
 do{
    tela("\t  CONTROLE DE ESTOQUE");
 	printf("========================================================================================================================\n");
    printf("========================================================================================================================\n");
    printf("===============================|  0 - Voltar		|===============================================================\n");
    printf("===============================|  1 - ACOUGUE E AVES	|===============================================================\n");
    printf("===============================|  2 - ADEGA DE BEBIDAS	|===============================================================\n");
    printf("===============================|  3 - FRIOS E LATICINIOS|===============================================================\n");
    printf("===============================|  4 - HORTIFRUTI 	|===============================================================\n");
    printf("===============================|  5 - PESCADO	 	|===============================================================\n");
    printf("=======================================================================================================================\n");
    printf("=======================================================================================================================\n");
    printf("============================== |      DIGITE UMA OPCAO        | =======================================================\n");
    printf("==================================== |	");
          scanf("%d",&op);
          switch(op){
           case 0: 
         system("cls || clear");
            break;
        case 1: listarEstoque("Acougue e Aves"); break;
        case 2: listarEstoque("Adega e Bebidas"); break;
     	case 3: listarEstoque("Frios e Laticinios"); break;
     	case 4: listarEstoque("Hortifruti"); break;
     	case 5: listarEstoque("Pescado"); break;
       default: defaultMessage();break;
   }
  }while((op<0) || (op>5));
}
int menupizza(){
 
   
   listarEstoque("Cardapio");
    defaultMessage();
}
int menuEstoquista(){
 int op;
 do{
    tela("\t  CONTROLE DE ESTOQUE");
 	printf("========================================================================================================================\n");
    printf("========================================================================================================================\n");
    printf("===============================|  0 - Fazer Logof	|===============================================================\n");
    printf("===============================|  1 - ACOUGUE E AVES	|===============================================================\n");
    printf("===============================|  2 - ADEGA DE BEBIDAS	|===============================================================\n");
    printf("===============================|  3 - FRIOS E LATICINIOS|===============================================================\n");
    printf("===============================|  4 - HORTIFRUTI 	|===============================================================\n");
    printf("===============================|  5 - PESCADO	 	|===============================================================\n");
    printf("=======================================================================================================================\n");
    printf("=======================================================================================================================\n");
    printf("============================== |      DIGITE UMA OPCAO        | =======================================================\n");
    printf("==================================== |	");
          scanf("%d",&op);
          switch(op){
           case 0: 
         system("cls || clear");
         VerificarLogin ();
            break;
        case 1: listarEstoquista("Acougue e Aves"); break;
        case 2: listarEstoquista("Adega e Bebidas"); break;
     	case 3: listarEstoquista("Frios e Laticinios"); break;
     	case 4: listarEstoquista("Hortifruti"); break;
     	case 5: listarEstoquista("Pescado"); break;
       default: defaultMessage();break;
   }
  }while((op<0) || (op>5));
}
void tela(char tela[])
{
 system("cls || clear");
    printf("================================================================================================================================================================================================================================================");
    printf("\t\t\t v00.700\n\n");
    printf("\t\t\t\t*******************************************************\n");
    printf("\t\t\t\t\t%s\n", tela);
    printf("\t\t\t\t*******************************************************\n");
    printf("\n\t\t\t\t\t\t\t\t\t\t\t\t\tADS PIZZARIA\n");
    printf("================================================================================================================================================================================================================================================\n");
}
void CadastroLogin(char cvCadastroLogin[], char cvCadastroSenha[])
{
    char cCaracter;
    char cvSenhaIgual[07];
    int iQtdCaracter;
    int iSenhaIgual = 0, z = 0;
    do
    {
        printf("\nDigite o login: ");
        fflush(stdin); //Limpando o buffer do teclado
        strcpy(cvCadastroLogin,Nome());
        printf("\nDigite a senha: ");
        iQtdCaracter = 0;
        do
        {
   z=0;
            cCaracter = getch();
            if (isprint(cCaracter) && (iQtdCaracter != 6))
            {                                              //Analisa se o valor da vari?vel c ? imprimivel
                cvCadastroSenha[iQtdCaracter] = cCaracter; //Se for, armazena o caractere
                iQtdCaracter++;
                printf("*"); //imprime o * Anterisco
            }
            else if (cCaracter == 8 && iQtdCaracter)
            { //8 ? o caractere BackSpace na tabela ASCII, && a analisa se a ? diferente de 0
                cvCadastroSenha[iQtdCaracter] = '\0';
                iQtdCaracter--;
                printf("\b \b"); //Apagando o caractere digitado
            }else if(cCaracter==13 && iQtdCaracter!=0){
             z=1;
   }
        } while (z != 1); //13 ? o valor de ENTER na tabela ASCII
        cvCadastroSenha[iQtdCaracter] = '\0';
        printf("\nConfirmacao da senha: ");
        iQtdCaracter = 0;
        z = 0;
        do
        {
            cCaracter = getch();
            if (isprint(cCaracter) && (iQtdCaracter != 6))
            { //Analisa se o valor de c ? imprim?vel
                cvSenhaIgual[iQtdCaracter] = cCaracter;
                iQtdCaracter++;
                printf("*"); //Imprimindo apenas o asterisco *
            }
            else if (cCaracter == 8 && iQtdCaracter)
            {
                cvSenhaIgual[iQtdCaracter] = '\0';
                iQtdCaracter--;
                printf("\b \b"); //Apagando os caracteres digitados
            }else if(cCaracter==13 && iQtdCaracter!=0){
             z=1;
   }
        } while (z != 1); //13 ? o valor de ENTER na tabela ASCII
        cvSenhaIgual[iQtdCaracter] = '\0';
        if (!strcmp(cvCadastroSenha, cvSenhaIgual))
        {
            //strcmp retorna 0 se as vari?veis forem iguais. !strcmp ? o mesmo que strcmp==0
            printf("\n\n\t\t\tCADASTRO EFETUADO COM SUCESSO...\n\n");
            iSenhaIgual = 1;
        }
        else
        {
            printf("\n\n\t\a\tSENHAS DIFERENTES - DIGITE NOVAMENTE...\n\n");
        }
    } while (iSenhaIgual != 1); //Enquanto b e d forem diferente de zero 0
}
void VerificarLogin()
{
    char cCaracter;
    char cTecla;
    char cvAcessoLogin[50];
    char cvAcessoSenha[07];
    int iQtdCaracter;
    int iSenhaIgual = 0, z = 0;
    char *t="SEJA BEM VINDO, FACA SEU LOGIN!!";
 tela(t);
 /****** 1 SOLUCAO PARA CASO NAO TENHA LOGIN ********/
 //verifica se tem Login
 if(!strcmp(cvAdm, "sim")){
 	printf("========================================================================================================================\n");
    printf("========================================================================================================================\n");
    printf("=======================================================================================================================\n");
    printf("============================== |     					       | ======================================\n");
    printf("============================== |     Pressione ENTER para fazer o Login        | ======================================\n");
    printf("============================== |     					       | ======================================\n");
    printf("============================== |     					       | ======================================\n");
    printf("=======================================================================================================================\n");
    printf("=======================================================================================================================\n");
    printf("=======================================================================================================================\n");
 cTecla = getch();
  if(cTecla == NULL){
     cTecla = getch();
     switch(cTecla){
     case 60:
      return 0;
  break;
  }
 }
 }
 else{
 tela("\tBEM VINDO VINDO");
 
 	printf("========================================================================================================================\n");
    printf("========================================================================================================================\n");
    printf("=======================================================================================================================\n");
    printf("============================== |     					       			| ======================\n");
    printf("============================== |     Pressione F2 para sair ou ENTER para fazer Cadastro!!!	| =====================\n");
    printf("============================== |     					      		 	| ======================\n");
    printf("============================== |     					      		 	| ======================\n");
    printf("=======================================================================================================================\n");
    printf("=======================================================================================================================\n");
    printf("=======================================================================================================================\n");
    if(cTecla == NULL){
     cTecla = getch();
     switch(cTecla){
     case 60:
      return 0;
  break;
  }
 getchar();
 }
 cadastrarFuncionario();
}
 t="SEJA BEM VINDO, FACA SEU LOGIN!!";
 tela(t);
 do
    {
        printf("\nEntre com o login: ");
        fflush(stdin); //Limpando o buffer do teclado
        strcpy(cvAcessoLogin,Nome());
        printf("\nEntre com a senha: ");
        iQtdCaracter = 0;
        do
        {
            cCaracter = getch();
            if (isprint(cCaracter) && (iQtdCaracter != 6))
            { //Analisa se o valor de c ? imprim?vel
                cvAcessoSenha[iQtdCaracter] = cCaracter;
                iQtdCaracter++;
                printf("*"); //Imprimindo apenas o asterisco *
            }
            else if (cCaracter == 8 && iQtdCaracter)
            {
                cvAcessoSenha[iQtdCaracter] = '\0';
                iQtdCaracter--;
                printf("\b \b"); //Apagando os caracteres digitados
            }else if(cCaracter==13 && iQtdCaracter!=0){
             z=1;
   }
        } while (z != 1); //13 ? o valor de ENTER na tabela ASCII
        cvAcessoSenha[iQtdCaracter] = '\0';
        Funcionario *fAux = fFuncionarioInicial;
        while (fAux != NULL)
        {
            if( (!strcmp(fAux->cvLogin, cvAcessoLogin)) && (!strcmp(fAux->cvSenha,cvAcessoSenha))){
                if(!strcmp(fAux->cvCargo, "ADMINISTRADOR")){
                 iSenhaIgual = 1;
                 strcpy(cvNFuncionario, fAux->cvNomeFunc);
                 strcpy(cvCargoFunc, fAux->cvCargo);
                 menu();
    }else if(!strcmp(fAux->cvCargo, "CAIXA")){
                 iSenhaIgual = 1;
                 strcpy(cvNFuncionario, fAux->cvNomeFunc);
                 strcpy(cvCargoFunc, fAux->cvCargo);
                 menuCaixa();
    }else if(!strcmp(fAux->cvCargo, "ESTOQUISTA")){
                 iSenhaIgual = 1;
                 strcpy(cvNFuncionario, fAux->cvNomeFunc);
                 strcpy(cvCargoFunc, fAux->cvCargo);
                 menuEstoquista();
    }
            }
            fAux = fAux->funProximo;
        }
        if(iSenhaIgual == 0){
         z=0;
         printf("\n\n\t\t\tUSUARIO NAO CADASTRADO... TENTE NOVAMENTE! \n\n");
  }
    } while (iSenhaIgual != 1);
}
int cadastrarProduto(){
 int op;
        tela("\tCADASTRO DE PRODUTO");
    char cEscolha;
    do{
        Produto *pNovoProduto = (Produto*) malloc(sizeof(Produto));
        pNovoProduto->pProximo = NULL;
  fflush(stdin);
  printf("\nCodigo do Produto: ");
        strcpy(pNovoProduto->cvCodigo,Nome());
        printf("\nNome do produto: ");
        strcpy(pNovoProduto->cvNome,Nome());
        fflush(stdin);
        printf("\nData de Validade: ");
        strcpy(pNovoProduto->cvValidade, FormatarData());
        pNovoProduto->cvValidade[strcspn(pNovoProduto->cvValidade, "\n")] = '\0';
        fflush(stdin);
        printf("\nQuantidade no Estoque(APENAS NUMEROS): ");
        scanf("%d", &pNovoProduto->iQtdEstoque);
        printf("\nEstoque de Seguranca(APENAS NUMEROS): ");
        scanf("%d", &pNovoProduto->iEstoqSeguranca);
        printf("\nCodigo do Fornecedor(APENAS NUMEROS): ");
        scanf("%d", &pNovoProduto->iCodigoFornecedor);
        fflush(stdin);
        do{ 
        tela("SETOR DO PRODUTO");
 	printf("========================================================================================================================\n");
    printf("========================================================================================================================\n");
    printf("===============================|  1 - ACOUGUE E AVES	|===============================================================\n");
    printf("===============================|  2 - ADEGA DE BEBIDAS	|===============================================================\n");
    printf("===============================|  3 - FRIOS E LATICINIOS|===============================================================\n");
    printf("===============================|  4 - HORTIFRUTI 	|===============================================================\n");
    printf("===============================|  5 - PESCADO	 	|===============================================================\n");
    printf("=======================================================================================================================\n");
    printf("=======================================================================================================================\n");
    printf("============================== |      DIGITE UMA OPCAO        | =======================================================\n");
    printf("==================================== |	");
          scanf("%d",&op);
          switch(op){
           case 1:
      strcpy(pNovoProduto->cvSetor, "Acougue e Aves");
            pNovoProduto->cvSetor[strcspn(pNovoProduto->cvSetor, "\n")] = '\0';
     break;
           case 2:
      strcpy(pNovoProduto->cvSetor, "Adega e Bebidas");
            pNovoProduto->cvSetor[strcspn(pNovoProduto->cvSetor, "\n")] = '\0';
     break;
     case 3:
      strcpy(pNovoProduto->cvSetor, "Frios e Laticinios");
         pNovoProduto->cvSetor[strcspn(pNovoProduto->cvSetor, "\n")] = '\0';
     break;
     case 4:
      strcpy(pNovoProduto->cvSetor, "Hortifruti");
         pNovoProduto->cvSetor[strcspn(pNovoProduto->cvSetor, "\n")] = '\0';
     break;
     case 5:
      strcpy(pNovoProduto->cvSetor, "Pescado");
         pNovoProduto->cvSetor[strcspn(pNovoProduto->cvSetor, "\n")] = '\0';
     break;
       default:
        defaultMessage();
        fflush(stdin);
                break;
   }
  }while((op<1) || (op>5));
        if(pProdutoInicial == NULL){
            pProdutoInicial = pNovoProduto;
        }else{
            Produto *pAux = pProdutoInicial;
            while(pAux->pProximo != NULL){
                pAux = pAux->pProximo;
            }
            pAux->pProximo = pNovoProduto;
        }

  cEscolha = escolhaRegistro();
        system("cls || clear");
        tela("\tCADASTRO DE PRODUTO");
    }while(cEscolha != 'n');
    gravarProduto();
}
int cadastroPizza(){
 int op;
        tela("\tCADASTRO PIZZAS E BEBIDAS");
    char cEscolha;
    do{
        Produto *pNovoProduto = (Produto*) malloc(sizeof(Produto));
        pNovoProduto->pProximo = NULL;
  fflush(stdin);
  printf("\nCodigo do Produto: ");
        strcpy(pNovoProduto->cvCodigo,Nome());
        printf("\nNome do produto: ");
        strcpy(pNovoProduto->cvNome,Nome());
        fflush(stdin);
        printf("\nValor do Produto: ");
        pNovoProduto->fValor = pegaValorProd();
        printf("\nQuantidade no Estoque(APENAS NUMEROS): ");
        scanf("%d", &pNovoProduto->iQtdEstoque);
        printf("\nEstoque de Seguranca(APENAS NUMEROS): ");
        scanf("%d", &pNovoProduto->iEstoqSeguranca);
        
      strcpy(pNovoProduto->cvSetor, "Cardapio");
            pNovoProduto->cvSetor[strcspn(pNovoProduto->cvSetor, "\n")] = '\0';
            
        if(pProdutoInicial == NULL){
            pProdutoInicial = pNovoProduto;
        }else{
            Produto *pAux = pProdutoInicial;
            while(pAux->pProximo != NULL){
                pAux = pAux->pProximo;
            }
            pAux->pProximo = pNovoProduto;
        }

  cEscolha = escolhaRegistro();
        system("cls || clear");
        tela("\tCADASTRO DE PRODUTO");
    }while(cEscolha != 'n');
    gravarProduto();
}
float pegaValorProd(){
 char cCaracter;
   int iMax=100;
    char cValor[iMax],c[iMax];
    int iQtdCaracter=0, x=0, z, w;
    char cPonto = 46;
    float fValor = 0;
        do
        {
         fflush(stdin);
         if(x<iMax){
          c[x]='\b';
          x++;
   }
            cCaracter = getch();
            if (isprint(cCaracter))
            { //Analisa se o valor de c ? imprim?vel
            if(cCaracter=='0'|| cCaracter=='1'|| cCaracter=='2'||cCaracter=='3' || cCaracter=='4'||cCaracter=='5' || cCaracter=='6'||cCaracter=='7' || cCaracter=='8'||cCaracter=='9'){
                iQtdCaracter++;
                if(iQtdCaracter==1){
                 cValor[0] = 48;
                 cValor[1]=46;
                 cValor[2]=48;
                 cValor[3]=cCaracter;
                printf("%s",cValor); //Imprimindo valor
   }else if(iQtdCaracter==2){
    printf("\b\b\b\b");
     cValor[0] = 48;
     cValor[1] = 46;
                 cValor[2]=cValor[3];
                 cValor[3]=cCaracter;
                printf("%s",cValor); //Imprimindo valor*
   }else if(iQtdCaracter==3){
    printf("\b\b\b\b");
     cValor[0] = cValor[2];
     cValor[1] = 46;
                 cValor[2]=cValor[3];
                 cValor[3]=cCaracter;
                printf("%s",cValor); //Imprimindo valor *
        }else if(iQtdCaracter>3){
         z=iQtdCaracter-2;
         w=iQtdCaracter-3;
   printf("%s",c);
   //numero antes do ponto final
   cValor[w]=cValor[z];
   //ponto final
   cValor[z]=46;
   cValor[x]=cCaracter;
            printf("%s",cValor); //Imprimindo valor *
   }
  }
        }else if (cCaracter == 8 && iQtdCaracter)
            {
                cValor[iQtdCaracter] = '\0';
                iQtdCaracter--;
                x--;
                printf("\b \b"); //Apagando os caracteres digitados
   }
        } while (cCaracter != 13); //13 ? o valor de ENTER na tabela ASCII
        iQtdCaracter+=1;
        cValor[iQtdCaracter] = '\0';
        fValor = atof(cValor);
        return fValor;
}
int FormatarCPF(){
  char cCaracter;
    char cCpf[14];
    int iQtdCaracter,x, z=0;
        iQtdCaracter = 0;
        do
        {
         fflush(stdin);
            cCaracter = getch();
            if (isprint(cCaracter) && (iQtdCaracter != 14))
            { //Analisa se o valor de c ? imprim?vel
            if(cCaracter=='0'|| cCaracter=='1'|| cCaracter=='2'||cCaracter=='3' || cCaracter=='4'||cCaracter=='5' || cCaracter=='6'||cCaracter=='7' || cCaracter=='8'||cCaracter=='9'){
                cCpf[iQtdCaracter] = cCaracter;
                iQtdCaracter++;
                x++;
                printf("%c",cCaracter); //Imprimindo apenas o asterisco *
                if(iQtdCaracter==3){
                 printf("\b\b\b");
                 cCpf[3] = '.';
                 printf("%s",cCpf);
                 iQtdCaracter++;
    }else if(iQtdCaracter==7){
    printf("\b\b\b\b\b\b\b");
                 cCpf[7] = '.';
                 printf("%s",cCpf);
                 iQtdCaracter++;
   }else if(iQtdCaracter==11){
    printf("\b\b\b\b\b\b\b\b\b\b\b\b");
                 cCpf[11] = '-';
                 printf("%s",cCpf);
                 iQtdCaracter++;
   }
   }
  }
            else if (cCaracter == 8 && iQtdCaracter)
            {
                cCpf[iQtdCaracter] = '\0';
                iQtdCaracter--;
                printf("\b \b"); //Apagando os caracteres digitados
                fflush(stdin);
   }else if(cCaracter==13 && iQtdCaracter==14){
    z=1;
   }
        } while (z != 1); //13 ? o valor de ENTER na tabela ASCII
        cCpf[iQtdCaracter] = '\0';
     return cCpf;
}
int FormatarData(){
 fflush(stdin);
  char cDataBase;
    char data[8];
    int iQtdDataBase,x, z=0;
        iQtdDataBase = 0;
        do
        {
         fflush(stdin);
            cDataBase = getch();
            if (isprint(cDataBase) && (iQtdDataBase != 8))
            { //Analisa se o valor de c ? imprim?vel
            if(cDataBase=='0'|| cDataBase=='1'|| cDataBase=='2'||cDataBase=='3' || cDataBase=='4'||cDataBase=='5' || cDataBase=='6'||cDataBase=='7' || cDataBase=='8' || cDataBase=='9'){
                data[iQtdDataBase] = cDataBase;
                iQtdDataBase++;
                x++;
                printf("%c",cDataBase);
                if(iQtdDataBase==2){
                 /*printf("\b\b");
                 data[2] = '/';
                 printf("%s",data);
                 iQtdDataBase++;
    }else if(iQtdDataBase==5){
    printf("\b\b\b\b\b\b");
                 data[5] = '/';
                 printf("%s",data);
                 iQtdDataBase++;*/
   }
   }
  }
            else if (cDataBase == 8 && iQtdDataBase)
            {
                data[iQtdDataBase] = '\0';
                iQtdDataBase--;
                printf("\b \b"); //Apagando os caracteres digitados
   }else if(cDataBase==13 && iQtdDataBase==8){
    z=1;
   }
        } while (z != 1); //13 ? o valor de ENTER na tabela ASCII
        data[iQtdDataBase] = '\0';
     return data;
}
int FormatarTelefone(){
  char cCaracter;
    char fTelefone[13];
    int iQtdCaracter,x, z=0;
        iQtdCaracter = 1;
        printf("(");
        do
        {
         fflush(stdin);
            cCaracter = getch();
            if (isprint(cCaracter) && (iQtdCaracter != 13))
            { //Analisa se o valor de c ? imprim?vel
            if(cCaracter=='0'|| cCaracter=='1'|| cCaracter=='2'||cCaracter=='3' || cCaracter=='4'||cCaracter=='5' || cCaracter=='6'||cCaracter=='7' || cCaracter=='8'||cCaracter=='9'){
    fTelefone[iQtdCaracter] = cCaracter;
                iQtdCaracter++;
                fTelefone[0] ='(';
                x++;
                printf("%c",cCaracter);
                if(iQtdCaracter==3){
                 printf("\b\b\b");
                 fTelefone[3] = ')';
                 printf("%s",fTelefone);
                 iQtdCaracter++;
    }else if(iQtdCaracter==8){
    printf("\b\b\b\b\b\b\b\b");
                 fTelefone[8] = '-';
                 printf("%c%c%c%c%c%c%c%c%c",fTelefone[0],fTelefone[1],fTelefone[2],fTelefone[3],fTelefone[4],fTelefone[5],fTelefone[6],fTelefone[7],fTelefone[8],fTelefone[9]);
                 iQtdCaracter++;
   }
   }
  }
            else if (cCaracter == 8 && iQtdCaracter!=1)
            {fTelefone[0] = '\0';
                fTelefone[iQtdCaracter] = '\0';
                iQtdCaracter--;
                printf("\b \b"); //Apagando os caracteres digitados
   }else if(cCaracter==13 && iQtdCaracter==13){
    z=1;
   }
        } while (z!=1); //13 ? o valor de ENTER na tabela ASCII
        fTelefone[iQtdCaracter] = '\0';
     return fTelefone;
}
int FormatarCelular(){
  char cCaracter;
    char cCelular[14];
    int iQtdCaracter,x, z=0;
        iQtdCaracter = 1;
        printf("(");
        do
        {
         fflush(stdin);
            cCaracter = getch();
            if (isprint(cCaracter) && (iQtdCaracter != 14))
            { //Analisa se o valor de c ? imprim?vel
            if(cCaracter=='0'|| cCaracter=='1'|| cCaracter=='2'||cCaracter=='3' || cCaracter=='4'||cCaracter=='5' || cCaracter=='6'||cCaracter=='7' || cCaracter=='8'||cCaracter=='9'){
    cCelular[iQtdCaracter] = cCaracter;
                iQtdCaracter++;
                cCelular[0] ='(';
                x++;
                printf("%c",cCaracter);
                if(iQtdCaracter==3){
                 printf("\b\b\b");
                 cCelular[3] = ')';
                 printf("%s",cCelular);
                 iQtdCaracter++;
    }else if(iQtdCaracter==9){
    printf("\b\b\b\b\b\b\b\b\b");
                 cCelular[9] = '-';
                 printf("%c%c%c%c%c%c%c%c%c%c",cCelular[0],cCelular[1],cCelular[2],cCelular[3],cCelular[4],cCelular[5],cCelular[6],cCelular[7],cCelular[8],cCelular[9],cCelular[10]);
                 iQtdCaracter++;
   }
   }
  }
            else if (cCaracter == 8 && iQtdCaracter!=1)
            {cCelular[0] = '\0';
                cCelular[iQtdCaracter] = '\0';
                iQtdCaracter--;
                printf("\b \b"); //Apagando os caracteres digitados
   }else if(cCaracter==13 && iQtdCaracter==14){
    z=1;
   }
        } while (z != 1); //13 ? o valor de ENTER na tabela ASCII
        cCelular[iQtdCaracter] = '\0';
        fflush(stdin);
     return cCelular;
}

int Nome(){
  char cCaracter;
    char cNome[200];
    int iQtdCaracter,x, z=0;
        iQtdCaracter = 0;
        do
        {
         fflush(stdin);
            cCaracter = getch();
            if (isprint(cCaracter))
            { //Analisa se o valor de c ? imprim?vel
            cNome[iQtdCaracter] = cCaracter;
                iQtdCaracter++;
                printf("%c",cCaracter); //Imprimindo apenas o asterisco *
  }
            else if (cCaracter == 8 && iQtdCaracter)
            {
                cNome[iQtdCaracter] = '\0';
                iQtdCaracter--;
                printf("\b \b"); //Apagando os caracteres digitados
   }else if(cCaracter==13 && iQtdCaracter!=0){
    z=1;
   }
        } while (z != 1); //13 ? o valor de ENTER na tabela ASCII
        cNome[iQtdCaracter] = '\0';
     return cNome;
}
void listarProdutos(){
 //variaveis auxiliares
 char c[200]="                                                  ";
 char a[200],b[200];
 int iA;
    tela("\tLISTA DE PRODUTOS");
    if(pProdutoInicial == NULL){
         nullList();
    }else{
        Produto *pAux = pProdutoInicial;
        while(pAux != NULL){
         //nome produto
         iA=54 - strlen(pAux->cvNome);
 strncat(pAux->cvNome,c,iA);
  sprintf(a, "%d", pAux->iQtdEstoque );
 iA=14 - strlen(a);
 strncat(a,c,iA);
 iA=14 - strlen(pAux->cvCodigo);
 strncat(pAux->cvCodigo,c,iA);
 sprintf(b, "%d", pAux->iEstoqSeguranca );
 iA=13 - strlen(b);
 strncat(b,c,iA);
            printf("Nome: %s| Validade: %s   | Valor: %.2f", pAux->cvNome, pAux->cvValidade,pAux->fValor);
            printf("\n------------------------------------------------------------------------------------------------------------------------");
   printf("\nQuantidade Est: %s| Est.Seguranca: %s| Codigo: %s | Cod.Fornecedor: %d",a ,b,pAux->cvCodigo, pAux->iCodigoFornecedor);
            printf("\n========================================================================================================================\n");
            pAux = pAux->pProximo;
        }
    }
    printf("\n\t\t\t\t   PRESSIONE QUALQUER TECLA PARA VOLTAR!");
    fflush(stdin);
    getchar();
}

int alteraProduto()
{
    int iOp;
 do{
     tela("\tALTERAR PRODUTO");
	printf("========================================================================================================================\n");
    printf("========================================================================================================================\n");
    printf("===============================|  0 - Voltar 			|======================================================\n");
    printf("===============================|  1 - Alterar Codigo    	|=======================================================\n");
    printf("===============================|  2 - Alterar Nome      	|=======================================================\n");
    printf("===============================|  3 - Alterar Valor      	|=======================================================\n");
    printf("===============================|  4 - Alterar Quant. Estoque    |=====================================================\n");
    printf("===============================|  5 - Alterar Estoque Seguranca |=======================================================\n");
    printf("=======================================================================================================================\n");
    printf("=======================================================================================================================\n");
    printf("============================== |      DIGITE UMA OPCAO        | =======================================================\n");
    printf("==================================== |	");
     scanf("%d", &iOp);
     switch(iOp){
      case 0:
       menuAlterar();
       break;
      case 1:
       system("cls || clear");
       alteraCodigoProduto();
       break;
      case 2:
       system("cls || clear");
       alteraNomeProduto();
       break;
      case 3:
       system("cls || clear");
       alteraValorProduto();
       break;
      case 4:
       system("cls || clear");
       alteraQtdProduto();
       break;
      case 5:
     system("cls || clear");
     alteraEstoqueSeg();
       break;
      default:
       defaultMessage();
       break;
  }
 }while(iOp != 0);
}
int alteraCodigoProduto(){
 Produto *pAux = pProdutoInicial;
 char cvCodigoP[51];
 char cvNovoCod[51];
 int iNaoEncontrado = 0;
    fflush(stdin);
    printf("\nEntre com o codigo do produto a ser alterado: ");
    strcpy(cvCodigoP,Nome());

 while(pAux != NULL){
  if(!strcmp(pAux->cvCodigo, cvCodigoP)){
   printf("Codigo atual: %s\tProduto: %s\n", pAux->cvCodigo, pAux->cvNome);
   printf("Digite o novo codigo: ");
   strcpy(cvNovoCod,Nome());
   strcpy(pAux->cvCodigo, cvNovoCod);
   iNaoEncontrado++;
  }
  pAux = pAux->pProximo;
 }
 if(!iNaoEncontrado){
  notFound("Produto");
 }else{
  alteradoSucesso("O codigo do produto");
 }
}
int alteraNomeProduto(){
 Produto *pAux = pProdutoInicial;
 char cvCodigoP[51];
 char cvNovoNome[201];
 int iNaoEncontrado = 0;
 fflush(stdin);
    printf("\nEntre com o codigo do produto a ser alterado: ");
    strcpy(cvCodigoP,Nome());
 while(pAux != NULL){
  if(!strcmp(pAux->cvCodigo, cvCodigoP)){
   printf("Nome atual: %s\n", pAux->cvNome);
   printf("Digite o novo nome: ");
   strcpy(cvNovoNome,Nome());
   strcpy(pAux->cvNome,cvNovoNome);
   iNaoEncontrado++;
  }
  pAux = pAux->pProximo;
 }
 if(!iNaoEncontrado){
  notFound("Produto");
 }else{
  alteradoSucesso("O nome do produto");
 }
}
int alteraValorProduto(){
 Produto *pAux = pProdutoInicial;
 char cvCodigoP[51];
 int iNaoEncontrado = 0;
 float fNovoValor;
 fflush(stdin);
    printf("\nEntre com o codigo do produto a ser alterado: ");
    strcpy(cvCodigoP,Nome());
 while(pAux != NULL){
  if(!strcmp(pAux->cvCodigo, cvCodigoP)){
   printf("Valor atual: %.2f\tProduto: %s\n", pAux->fValor, pAux->cvNome);
   printf("Digite o novo valor: R$ ");
   pAux->fValor = pegaValorProd();
   iNaoEncontrado++;
  }
  pAux = pAux->pProximo;
 }
 if(!iNaoEncontrado){
  notFound("Produto");
 }else{
  alteradoSucesso("O valor do produto");
 }
}
int alteraQtdProduto(){
 Produto *pAux = pProdutoInicial;
 char cvCodigoP[51];
 int iNaoEncontrado = 0;
 int iNovoQtd;
 fflush(stdin);
    printf("\nEntre com o codigo do produto a ser alterado: ");
    strcpy(cvCodigoP,Nome());
 while(pAux != NULL){
  if(!strcmp(pAux->cvCodigo, cvCodigoP)){
   printf("Qtd. Estoque atual: %d\tProduto: %s\n", pAux->iQtdEstoque, pAux->cvNome);
   printf("Digite a nova quantidade: ");
   scanf("%d", &iNovoQtd);
   pAux->iQtdEstoque += iNovoQtd;
   iNaoEncontrado++;
  }
  pAux = pAux->pProximo;
 }
 if(!iNaoEncontrado){
  notFound("Produto");
 }else{
  alteradoSucesso("A quantidade do produto");
 }
}
int alteraEstoqueSeg(){
 Produto *pAux = pProdutoInicial;
 char cvCodigoP[51];
 int iNaoEncontrado = 0;
 int iNovoQtd;
 fflush(stdin);
    printf("\nEntre com o codigo do produto a ser alterado: ");
    strcpy(cvCodigoP,Nome());
 while(pAux != NULL){
  if(!strcmp(pAux->cvCodigo, cvCodigoP)){
   printf("Qtd. Estoque Seguranca atual: %d\tProduto: %s\n", pAux->iEstoqSeguranca, pAux->cvNome);
   printf("Digite a nova quantidade de seguranca: ");
   scanf("%d", &iNovoQtd);
   pAux->iEstoqSeguranca += iNovoQtd;
   iNaoEncontrado++;
  }
  pAux = pAux->pProximo;
 }
 if(!iNaoEncontrado){
  notFound("Produto");
 }else{
  alteradoSucesso("A quantidade do produto");
 }
}
void removeProduto()
{
 tela("REMOVER PRODUTO");
    Produto *pAux = pProdutoInicial;
    Produto *pAnterior;
    if (pProdutoInicial == NULL)
    {
        printf("\nA lista ja esta vazia!");
    }
    else
    {
        char cvCodigoP[51];
        char cvNomeTemp[200]; //Armazena o nome do item excluido temporariamente
        char cEscolha;
        int iNaoEncontrado = 0;
        printf("Entre com o codigo do produto que deseja remover: ");
        fflush(stdin);
        strcpy(cvCodigoP,Nome());
        while (pAux != NULL)
        {
            if (!strcmp(pAux->cvCodigo, cvCodigoP))
            {
                if (pProdutoInicial->pProximo == NULL)
                    pProdutoInicial = NULL; // se o inicial nao tiver proximo, deve receber nulo
                strcpy(cvNomeTemp, pAux->cvNome);
                if (pAux == pProdutoInicial)
                {
                    pAux = pAux->pProximo;
                    free(pProdutoInicial);
                    pProdutoInicial = NULL;
                    pProdutoInicial = pAux;
                    removidoSucesso("Produto", cvNomeTemp);
                }
                else
                {
                    pAnterior->pProximo = pAux->pProximo;
                    free(pAux);
                    pAux = NULL;
                    removidoSucesso("Produto", cvNomeTemp);
                    return 0;
                }
                iNaoEncontrado++;
            }
            pAnterior = pAux;
            pAux = pAux->pProximo;
        }
        if (iNaoEncontrado == 0)
            notFound("Produto");
    }
}
int cadastrarFornecedor(){
    char cEscolha;
    tela("\tCADASTRO DE FORNECEDOR");
    do{
        Fornecedor *novoFornecedor = (Fornecedor*) malloc(sizeof(Fornecedor));
        novoFornecedor->fProximo = NULL;
        printf("\nNome Fornecedor: ");
        fflush(stdin);
        strcpy(novoFornecedor->cvNome,Nome());
        printf("\nNome Fantasia: ");
        strcpy(novoFornecedor->cvNomeFantasia,Nome());
        printf("\nEndereco: ");
        strcpy(novoFornecedor->cvEndereco,Nome());
        printf("\nCNPJ: ");
        strcpy(novoFornecedor->cvCnpj,Nome());
        printf("\nEmail: ");
        strcpy(novoFornecedor->cvEmail,Nome());
        printf("\nTelefone: ");
        strcpy(novoFornecedor->cvTelefone, FormatarTelefone());
        fflush(stdin);
        printf("\nCelular: ");
        strcpy(novoFornecedor->cvCelular, FormatarCelular());
        printf("\nCodigo Produto(APENAS NUMEROS): ");
        scanf("%d", &novoFornecedor->iCodigoProduto);
        if(fFornecedorInicial == NULL) {
            fFornecedorInicial = novoFornecedor;
        }else{
            Fornecedor *fAux = fFornecedorInicial;
            while(fAux->fProximo != NULL){
                fAux = fAux->fProximo;
            }
            fAux->fProximo = novoFornecedor;
        }
        cEscolha = escolhaRegistro();
        system("cls || clear");
        tela("\tCADASTRO DE FORNECEDOR");
    }while(cEscolha != 'n');
    gravarFornecedor();
}
void listarFornecedor(){
 //variaveis auxiliares
 char c[200]="                                                  ";
 int iA;
    tela("\tLISTA DE FORNECEDORES");
    if(fFornecedorInicial == NULL){
        nullList();
    }else{
        Fornecedor *fAux = fFornecedorInicial;
        while(fAux != NULL){
         iA=39 - strlen(fAux->cvNome);
 strncat(fAux->cvNome,c,iA);
 iA=39 - strlen(fAux->cvNomeFantasia);
 strncat(fAux->cvNomeFantasia,c,iA);
            iA=49 - strlen(fAux->cvEmail);
 strncat(fAux->cvEmail,c,iA);
   printf("\n------------------------------------------------------------------------------------------------------------------------");
            printf("\nNome: %s| Empresa: %s | CNPJ: %s", fAux->cvNome, fAux->cvNomeFantasia, fAux->cvCnpj);
            printf("\n------------------------------------------------------------------------------------------------------------------------");
            printf("\nCelular: %s                                 |\tTelefone: %s", fAux->cvCelular, fAux->cvTelefone);
            printf("\n------------------------------------------------------------------------------------------------------------------------");
            printf("\nEmail: %s|\tEndereco: %s", fAux->cvEmail, fAux->cvEndereco);
            printf("\n========================================================================================================================\n");
            fAux = fAux->fProximo;
        }
        printf("\n\t\t\t\t   PRESSIONE QUALQUER TECLA PARA VOLTAR!");
    }
    char cListar;
    cListar = getchar();
    getchar();
}
void alteraFornecedor()
{
 tela("\tALTERAR FORNECEDOR");
    Fornecedor *fAux = fFornecedorInicial;
    char cvExNome[201];
    fflush(stdin);
    editMessage("fornecedor");
    strcpy(cvExNome,Nome());
    int iNaoEncontrado = 0;
    while (fAux != NULL)
    {
        if (!strcmp(fAux->cvNome, cvExNome) || !strcmp(fAux->cvNomeFantasia, cvExNome))
        {
            fflush(stdin);
            printf("\nNome do Fornecedor: ");
            strcpy(fAux->cvNome,Nome());
            printf("\nNome Fantasia: ");
            strcpy(fAux->cvNomeFantasia,Nome());
            printf("\nEndereco: ");
            strcpy(fAux->cvEndereco,Nome());
            printf("\CNPJ: ");
            strcpy(fAux->cvCnpj,Nome());
            printf("\nEmail: ");
            strcpy(fAux->cvEmail,Nome());
            printf("\nTelefone: ");
        strcpy(fAux->cvTelefone, FormatarTelefone());
        fflush(stdin);
        printf("\nCelular: ");
        strcpy(fAux->cvCelular, FormatarCelular());
            printf("\nCodigo Produto(APENAS NUMEROS): ");
            scanf("%d", &fAux->iCodigoProduto);
            iNaoEncontrado++;
            break;
        }
        fAux = fAux->fProximo;
    }
    if (iNaoEncontrado == 0)
    {
        nullList();
    }
}
void removeFornecedor(){
    tela("\tREMOVER FORNECEDOR");
    Fornecedor *fAux = fFornecedorInicial;
    Fornecedor *fAnterior;
    if(fFornecedorInicial == NULL){
        nullDelete();
    }else{
  char cvNomeP[201];
  char cvNomeTemp[200]; //Armazena o nome do item excluido temporariamente
  int iNaoEncontrado = 0;
        printf("Entre com o nome do fornecedor que deseja remover: ");
        fflush(stdin);
        strcpy(cvNomeP,Nome());
        while(fAux != NULL){
         if(!strcmp(fAux->cvNome, cvNomeP) || !strcmp(fAux->cvNomeFantasia, cvNomeP)){
          if(fFornecedorInicial->fProximo == NULL) fFornecedorInicial = NULL;
          strcpy(cvNomeTemp, fAux->cvNome);
          if(fAux == fFornecedorInicial){
           fAux = fAux->fProximo;
           free(fFornecedorInicial);
           fFornecedorInicial = NULL;
           fFornecedorInicial = fAux;
           removidoSucesso("Fornecedor", cvNomeTemp);
    }else{
     fAnterior->fProximo = fAux->fProximo;
     free(fAux);
     fAux = NULL;
     removidoSucesso("Fornecedor", cvNomeTemp);
     return 0;
    }
    iNaoEncontrado++;
   }
   fAnterior = fAux;
   fAux = fAux->fProximo;
  }
  if(iNaoEncontrado == 0 ) notFound("Fornecedor");
    }
}
int cadastrarCliente(){
    char cEscolha;
    tela("\tCADASTRO DE CLIENTE");
    do{
        Cliente *cNovocliente = (Cliente*) malloc(sizeof(Cliente));
        cNovocliente->cProximo = NULL;
        fflush(stdin);
        printf("\nNome: ");
        strcpy(cNovocliente->cvNomeCli,Nome());
        printf("\nCPF: ");
        fflush(stdin);
        strcpy(cNovocliente->cvCpf,FormatarCPF());
        fflush(stdin);
        printf("\nData de Nascimento: ");
        strcpy(cNovocliente->cvData_nascimento,FormatarData());
        printf("\nEmail: ");
        strcpy(cNovocliente->cvEmail,Nome());
        printf("\nTelefone: ");
        strcpy(cNovocliente->cvTelefone,FormatarTelefone());
        printf("\nCelular: ");
        strcpy(cNovocliente->cvCelular,FormatarCelular());
        printf("\nEndereco: ");
        strcpy(cNovocliente->cvEndereco,Nome());
        if(cClienteInicial == NULL){
            cClienteInicial = cNovocliente;
        }else{
            Cliente *cAux = cClienteInicial;
            while(cAux->cProximo != NULL){
                cAux = cAux->cProximo;
            }
            cAux->cProximo = cNovocliente;
        }
        cEscolha = escolhaRegistro();
        system("cls || clear");
        tela("\tCADASTRO DE CLIENTE");
    }while(cEscolha != 'n');
    gravarCliente();
}
void listarCliente(){
 //variaveis auxiliares
 char c[200]="                                                  ";
 int iA;
    tela("\tLISTA DE CLIENTES");
    if(cClienteInicial == NULL){
        nullList();
    }else{
        Cliente *cAux = cClienteInicial;
        while(cAux != NULL){
 iA=49 - strlen(cAux->cvEmail);
 strncat(cAux->cvEmail,c,iA);
   printf("\n------------------------------------------------------------------------------------------------------------------------");
            printf("Nome: %s", cAux->cvNomeCli);
            printf("\n------------------------------------------------------------------------------------------------------------------------");
            printf("\nCPF: %s                                     |\tData de Nascimento: %s", cAux->cvCpf, cAux->cvData_nascimento);
            printf("\n------------------------------------------------------------------------------------------------------------------------");
            printf("\nCelular: %s                                 |\tTelefone: %s", cAux->cvCelular, cAux->cvTelefone);
            printf("\n------------------------------------------------------------------------------------------------------------------------");
            printf("\nEmail: %s|\tEndereco: %s", cAux->cvEmail, cAux->cvEndereco);
            printf("\n========================================================================================================================\n");
            cAux = cAux->cProximo;
        }
        printf("\n\t\t\t\t   PRESSIONE QUALQUER TECLA PARA VOLTAR!");
    }
    fflush(stdin);
    getchar();
}
void alteraCliente()
{
 tela("\tALTERAR CLIENTE");
    Cliente *cAux = cClienteInicial;
    char cvCpfCli[201];
    fflush(stdin);
   printf("\nEntre com o CPF do cliente a ser alterado: ");
    strcpy(cvCpfCli,FormatarCPF());
    int iNaoEncontrado = 0;
    while (cAux != NULL)
    {
        if (!strcmp(cAux->cvCpf, cvCpfCli))
        {
            fflush(stdin);
            printf("\nNome: ");
            strcpy(cAux->cvNomeCli,Nome());
            printf("\nCPF: ");
            strcpy(cAux->cvCpf,FormatarCPF());
            printf("\nData de Nascimento: ");
            strcpy(cAux->cvData_nascimento,FormatarData());
            printf("\nEmail: ");
            strcpy(cAux->cvEmail,Nome());
            printf("\nTelefone: ");
            strcpy(cAux->cvTelefone,FormatarTelefone());
            printf("\nCelular: ");
            fflush(stdin);
            strcpy(cAux->cvCelular,FormatarCelular());
            printf("\nEndereco: ");
            strcpy(cAux->cvEndereco,Nome());
            iNaoEncontrado++;
            break;
        }
        cAux = cAux->cProximo;
    }
    if (iNaoEncontrado == 0)
    {
        nullList();
    }
}
void removeCliente(){
    tela("\tREMOVER CLIENTE");
    Cliente *cAux = cClienteInicial;
    Cliente *cAnterior;
    if(cClienteInicial == NULL){
        nullDelete();
    }else{
        char cvCpfCli[201];
        char cvNomeTemp[200]; //Armazena o nome do item excluido temporariamente
        int iNaoEncontrado = 0;
        fflush(stdin);
        printf("Entre com o CPF do cliente que deseja remover: ");
        strcpy(cvCpfCli,FormatarCPF());
        /*fgets(cvCpfCli, sizeof(cvCpfCli), stdin);
        cvCpfCli[strcspn(cvCpfCli, "\n")] = '\0';*/
        while(cAux != NULL){
         if(!strcmp(cAux->cvCpf, cvCpfCli)){
          if(cClienteInicial->cProximo == NULL) cClienteInicial = NULL;
          strcpy(cvNomeTemp, cAux->cvNomeCli);
          if(cAux == cClienteInicial){
           cAux = cAux->cProximo;
           free(cClienteInicial);
     cClienteInicial = NULL;
     cClienteInicial = cAux;
     removidoSucesso("Cliente", cvNomeTemp);
    }else{
     cAnterior->cProximo = cAux->cProximo;
     free(cAux);
     cAux = NULL;
     removidoSucesso("Cliente", cvNomeTemp);
     return 0;
    }
    iNaoEncontrado++;
   }
   cAnterior = cAux;
   cAux = cAux->cProximo;
  }
  if(iNaoEncontrado == 0) notFound("Cliente");
    }
}
int cadastrarFuncionario(){
    char cEscolha;
    int op;
    /*if(strcmp(cvAdm, "sim")){
     char *t="  SEJA BEM VINDO, CADASTRE SEU LOGIN ADM!!";
  tela(t);
        Funcionario *fNovoFuncionario = (Funcionario *) malloc(sizeof(Funcionario));
        fNovoFuncionario->funProximo = NULL;
        printf("\nNome: ");
        strcpy(fNovoFuncionario->cvNomeFunc,Nome());
        //passando nome para a variavel global
        strcpy(cvNFuncionario, fNovoFuncionario->cvNomeFunc);
        strcpy(fNovoFuncionario->cvCargo, "ADMINISTRADOR");
        //passando cargo para a variavel global
        strcpy(cvCargoFunc, "ADMINISTRADOR");
  CadastroLogin(fNovoFuncionario->cvLogin, fNovoFuncionario->cvSenha);
        if(fFuncionarioInicial == NULL) {
            fFuncionarioInicial = fNovoFuncionario;
        }
        gravarAdm(cvAdm);
        tela("\t ETAPA FINAL DO CADASTRO");
        fflush(stdin);
        printf("\nData de Nascimento: ");
        strcpy(fNovoFuncionario->cvData_nascimento,FormatarData());
        printf("\nCPF: ");
        fflush(stdin);
        strcpy(fNovoFuncionario->cvCpf,FormatarCPF());
        printf("\nEmail: ");
        strcpy(fNovoFuncionario->cvEmail,Nome());
        printf("\nTelefone: ");
        fflush(stdin);
        strcpy(fNovoFuncionario->cvTelefone,FormatarTelefone());
        printf("\nCelular: ");
        fflush(stdin);
        strcpy(fNovoFuncionario->cvCelular,FormatarCelular());
        printf("\nEndereco: ");
        strcpy(fNovoFuncionario->cvEndereco,Nome());
        printf("\n\t\tCADASTRO EFETUADO!!\n\t\tENTRANDO...\n");
        gravarFuncionario();
        menu();
 }else{*/
 if(strcmp(cvAdm, "sim")){
         tela("\t CADASTRO DO ADMINISTRADOR");
  }else{
     tela("\t CADASTRO DE FUNCIONARIO");
 }
     do{
         Funcionario *fNovoFuncionario = (Funcionario *) malloc(sizeof(Funcionario));
         fNovoFuncionario->funProximo = NULL;
         fflush(stdin);
         printf("\nNome: ");
         strcpy(fNovoFuncionario->cvNomeFunc,Nome());
         if(strcmp(cvAdm, "sim")){
         strcpy(fNovoFuncionario->cvCargo, "ADMINISTRADOR");
      fNovoFuncionario->cvCargo[strcspn(fNovoFuncionario->cvCargo, "\n")] = '\0';
  }else{
         do{
    printf("\nCargo: ");
          printf("\n1: ADMINISTRADOR \n2: CAIXA \n3: ESTOQUISTA\n");
          scanf("%d",&op);
          switch(op){
           case 1:
      strcpy(fNovoFuncionario->cvCargo, "ADMINISTRADOR");
            fNovoFuncionario->cvCargo[strcspn(fNovoFuncionario->cvCargo, "\n")] = '\0';
     break;
           case 2:
      strcpy(fNovoFuncionario->cvCargo, "CAIXA");
            fNovoFuncionario->cvCargo[strcspn(fNovoFuncionario->cvCargo, "\n")] = '\0';
     break;
           case 3:
      strcpy(fNovoFuncionario->cvCargo, "ESTOQUISTA");
         fNovoFuncionario->cvCargo[strcspn(fNovoFuncionario->cvCargo, "\n")] = '\0';
     break;
       default:
        printf("\nOpcao invalida");
        fflush(stdin);
                break;
   }
  }while((op<1) || (op>3));
 }
   fflush(stdin);
         printf("\nCPF: ");
         strcpy(fNovoFuncionario->cvCpf,FormatarCPF());
         printf("\nData de Nascimento: ");
         fflush(stdin);
         strcpy(fNovoFuncionario->cvData_nascimento,FormatarData());
         printf("\nEmail: ");
         strcpy(fNovoFuncionario->cvEmail,Nome());
         printf("\nTelefone: ");
         strcpy(fNovoFuncionario->cvTelefone,FormatarTelefone());
         printf("\nCelular: ");
         strcpy(fNovoFuncionario->cvCelular,FormatarCelular());
         printf("\nEndereco: ");
         strcpy(fNovoFuncionario->cvEndereco,Nome());
         CadastroLogin(fNovoFuncionario->cvLogin, fNovoFuncionario->cvSenha);
         if(fFuncionarioInicial == NULL) {
             fFuncionarioInicial = fNovoFuncionario;
         }else{
             Funcionario *fAux = fFuncionarioInicial;
             while(fAux->funProximo != NULL){
                 fAux = fAux->funProximo;
             }
             fAux->funProximo = fNovoFuncionario;
         }
  if(strcmp(cvAdm, "sim")){
   printf("\n\t\tCADASTRO EFETUADO, TESTE SEU LOGIN!!\n\t\t   ENTRANDO...\n");
   gravarAdm(cvAdm);
         gravarFuncionario();
         VerificarLogin();
  }else{
         cEscolha = escolhaRegistro();
         tela("\t CADASTRO DE FUNCIONARIO");
 }
     }while(cEscolha != 'n');
     gravarFuncionario();
}
void listarFuncionario(){
 char c[200]="                                                  ";
 int iA;
    tela("\tLISTA DE FUNCIONARIOS");
    if(fFuncionarioInicial == NULL){
        nullList();
    }else{
        Funcionario *fAux = fFuncionarioInicial;
        while(fAux != NULL){
    iA=50 - strlen(fAux->cvNomeFunc);
 strncat(fAux->cvNomeFunc,c,iA);
 iA=49 - strlen(fAux->cvEmail);
 strncat(fAux->cvEmail,c,iA);
   printf("\n------------------------------------------------------------------------------------------------------------------------");
            printf("Nome: %s|\tCargo: %s", fAux->cvNomeFunc, fAux->cvCargo);
            printf("\n------------------------------------------------------------------------------------------------------------------------");
            printf("\nCPF: %s                                     |\tData de Nascimento: %s", fAux->cvCpf, fAux->cvData_nascimento);
            printf("\n------------------------------------------------------------------------------------------------------------------------");
            printf("\nCelular: %s                                 |\tTelefone: %s", fAux->cvCelular, fAux->cvTelefone);
            printf("\n------------------------------------------------------------------------------------------------------------------------");
            printf("\nEmail: %s|\tEndereco: %s", fAux->cvEmail, fAux->cvEndereco);
            printf("\n========================================================================================================================\n");
            fAux = fAux->funProximo;
        }
    printf("\n\t\t\t\t   PRESSIONE QUALQUER TECLA PARA VOLTAR!");
 }
    char cListar;
    cListar = getchar();
    getchar();
}
void alteraFuncionario()
{
 tela("\tALTERAR FUNCIONARIO");
    Funcionario *fAux = fFuncionarioInicial;
    int iOp;
    char cvCpfFunc[201];
    fflush(stdin);
    printf("\nEntre com o CPF do funcionario a ser alterado: ");
    strcpy(cvCpfFunc,FormatarCPF());
    int iNaoEncontrado = 0;
    while (fAux != NULL)
    {
        if (!strcmp(fAux->cvCpf, cvCpfFunc))
        {
            fflush(stdin);
            printf("\nNome funcionario: ");
            strcpy(fAux->cvNomeFunc,Nome());
            do
            {
                printf("\nCargo: ");
                printf("\n1: ADMINISTRADOR \n2: CAIXA \n3: ESTOQUISTA\n");
                scanf("%d", &iOp);
                switch (iOp)
                {
                case 1:
                    strcpy(fAux->cvCargo, "ADMINISTRADOR");
                    fAux->cvCargo[strcspn(fAux->cvCargo, "\n")] = '\0';
                    break;
                case 2:
                    strcpy(fAux->cvCargo, "CAIXA");
                    fAux->cvCargo[strcspn(fAux->cvCargo, "\n")] = '\0';
                    break;
                case 3:
                    strcpy(fAux->cvCargo, "ESTOQUISTA");
                    fAux->cvCargo[strcspn(fAux->cvCargo, "\n")] = '\0';
                    break;
                default:
                    printf("\nOpcao invalida");
                    fflush(stdin);
                    break;
                }
            } while ((iOp < 1) || (iOp > 3));
            fflush(stdin);
            printf("\nCPF: ");
            strcpy(fAux->cvCpf,FormatarCPF());
            fflush(stdin);
            printf("\nData de Nascimento: ");
         strcpy(fAux->cvData_nascimento,FormatarData());
         printf("\nEmail: ");
         strcpy(fAux->cvEmail,Nome());
         printf("\nTelefone: ");
         strcpy(fAux->cvTelefone,FormatarTelefone());
         fflush(stdin);
         printf("\nCelular: ");
         strcpy(fAux->cvCelular,FormatarCelular());
            printf("\nEndereco: ");
            strcpy(fAux->cvEndereco,Nome());
            iNaoEncontrado++;
            break;
        }
        fAux = fAux->funProximo;
    }
    if (iNaoEncontrado == 0)
    {
        nullList();
    }
}
void removeFuncionario()
{
    tela("\tREMOVER FUNCIONARIO");
    Funcionario *fAux = fFuncionarioInicial;
    Funcionario *fAnterior;
    if (fFuncionarioInicial == NULL)
    {
        nullDelete();
    }
    else
    {
        char cvCpfFunc[201];
        char cvNomeTemp[200]; // Armazena o nome do item excluido temporariamente
        int iNaoEncontrado = 0;
        fflush(stdin);
        printf("Entre com o CPF do funcionario que deseja remover: ");
        strcpy(cvCpfFunc,FormatarCPF());
        while (fAux != NULL)
        {
            if (!strcmp(fAux->cvCpf, cvCpfFunc))
            {
                if (fFuncionarioInicial->funProximo == NULL){ //nao pode ser removido pois eh a chave para o sistema
     printf("\n\t\t\tESTE FUNCIONARIO NAO PODE SER REMOVIDO\n");
     return 0;
    }
                strcpy(cvNomeTemp, fAux->cvNomeFunc);
                if (fAux == fFuncionarioInicial)
                {
                    fAux = fAux->funProximo;
                    free(fFuncionarioInicial);
                    fFuncionarioInicial = NULL;
                    fFuncionarioInicial = fAux;
                    removidoSucesso("Funcionario", cvNomeTemp);
                }
                else
                {
                    fAnterior->funProximo = fAux->funProximo;
                    free(fAux);
                    fAux = NULL;
                    removidoSucesso("Funcionario", cvNomeTemp);
                    return 0;
                }
                iNaoEncontrado++;
            }
            fAnterior = fAux;
            fAux = fAux->funProximo;
        }
        if (iNaoEncontrado == 0)
            notFound("Funcionario");
    }
}
int venda(){
 int iFinalizar;
 char cvCpfCliente[201];
 char cvCodProduto[51];
// int iVerificaCli;
 int iQuantidade = 0;
 float totalItem = 0;
 float totalVenda = 0;
 tela("\t   EFETUAR VENDA");
 //verifica se o cliente esta cadastrado
// if(iVerificaCli == 0) system("cls");
 tela("\t   EFETUAR VENDA");
 fflush(stdin);
 //laco para item venda
 do{
  if(!iItemVendaInicial == NULL){
   tela("\t   EFETUAR VENDA");
   listaItemVenda(totalVenda);
  }
  //soma total da venda
  totalVenda += addItemVenda();
  printf("Adiconar novo produto? (1 - SIM) / (0 - NAO)");
  scanf("%d", &iFinalizar);
  fflush(stdin);
 }while(iFinalizar != 0);
 if(totalVenda==0.0){
     printf("\n\t\t\t\tVENDA CANCELADA POIS NAO HA PRODUTOS VENDIDOS\n\n\t\t\t\tPRESSIONE QUALQUER TECLA PARA RETORNAR AO MENU!!!");
     getchar();
     return 0;
 }
 if (iFinalizar==0){
  tela("\t   EFETUAR VENDA");
 }
 //laco para a venda
 do{
  iFinalizar = addVenda(totalVenda);
 }while(iFinalizar != 1);
 //limpar item venda
 	int enter;
 system ("cls");
 tela("ENTREGAR PEDIDO OU RETIRADA BALCAO!");
  	printf("===============================|  1 - ENTREGA 	|=======================================================================\n");
    printf("===============================|  2 - RETIRADA 	|=======================================================================\n");
    printf("========================================================================================================================\n");
    printf("============================== |      DIGITE UMA OPCAO        | ========================================================\n");
    printf("==================================== |	");
scanf("%d", &enter);
switch (enter){
	case 1:
		printf ("ENTREGA !!!");
		
		system ("Pause");
		break;
	case 2:
		printf("RETIRADA !!!");
		system ("Pause");
		break;
	system ("cls");
	
}
 gravarItemVenda();
 iItemVendaInicial = NULL;
 gravarVenda();
 return 0;
}
float addItemVenda(){
 //tela("\t   EFETUAR VENDA");
 //novo item
 ItemVenda *iNovoItem = (ItemVenda*) malloc(sizeof(ItemVenda));
 iNovoItem->iItemProximo = NULL;
 //Variaveis structs auxiliares
 Produto *pAux = pProdutoInicial;
 //variaveis auxiliares
 char cvCodigoBarra[201];
 int iQuantidade = 0;
 int iNaoEncontrado;
 float totalItem = 0;
 if(pProdutoInicial == NULL){
  printf("Nao ha produtos cadastrados!\n");
  printf("\n\t\t\t\t   PRESSIONE QUALQUER TECLA PARA VOLTAR!");
  fflush(stdin);
     getchar();
  return 0;
 }
 tela("FACA SEU PEDIDO");
	printf("Entre com o codigo de barras do produto: ");
 strcpy(cvCodigoBarra, Nome());
 while(pAux != NULL){
  if(!strcmp(pAux->cvCodigo, cvCodigoBarra)){
   iNaoEncontrado++;
   strcpy(iNovoItem->cvNomeItem, pAux->cvNome);
   printf("\n**************************************************\nProduto: %s\t Vl. Unitario: R$ %.2f\n**************************************************\n", pAux->cvNome, pAux->fValor);
   printf("Entre com a quantidade de compra: ");
   scanf("%d", &iQuantidade);
   totalItem = pAux->fValor * iQuantidade;
   iNovoItem->fValorItem = totalItem;
   if(pAux->iQtdEstoque < 0){
    printf("***********************************************************************************************************************\n");
    printf("\t\t\t\t\tO estoque de %s acabou! Avisar o Gerente!!\n", pAux->cvNome);
    printf("***********************************************************************************************************************\n");
    printf("\n\t\t\t\t   PRESSIONE QUALQUER TECLA PARA CONTINUAR!");
    fflush(stdin);
    getchar();
   }
   //adicionando na struct de item venda
   iNovoItem->iItemProximo = iItemVendaInicial;
   iItemVendaInicial = iNovoItem;
  }
  pAux = pAux->pProximo;
 }
 if(!iNaoEncontrado){
  printf("\n\t\t\t\tPRODUTO NAO ENCONTRADO!!!\n");
 }
 return totalItem;
}
int addVenda(float totalVenda){
 int iVerificaCli;
 //variaveis auxiliares
 int iFormaPag;
 float fDinheiroRecebido = 0;
 int iCancelaVenda;
 //colocar na struct de venda
  srand(time(NULL));
  time_t t = time(NULL);
  struct tm tm = *localtime(&t);
  Venda *vNovaVenda = (Venda*) malloc(sizeof(Venda));
  vNovaVenda->vendaProximo = NULL;
  //jogando valores para a nova venda
  vNovaVenda->iCodVenda = rand() % 900;
  vNovaVenda->dTotalCompra = totalVenda;
  vNovaVenda->iDia = tm.tm_mday;
  vNovaVenda->iMes = tm.tm_mon + 1;
  vNovaVenda->iAno = tm.tm_year + 1900;
  listaItemVenda(totalVenda);
 // printf("Valor Total: R$ %.2f\n", vNovaVenda->dTotalCompra);
  //adm podera alterar
  Cliente *cAux = cClienteInicial;
  iVerificaCli = verificaCliente();
  if(iVerificaCli == 1){
   printf("\nCLIENTE: %s", cvNomeCli);
   if(vNovaVenda->dTotalCompra >= 2){
    vNovaVenda->dTotalCompra = vNovaVenda->dTotalCompra - (vNovaVenda->dTotalCompra * 0.05);
    printf("\n*********************************************");
    printf("\nValor com desconto: R$ %.2f\n", vNovaVenda->dTotalCompra);
    printf("\n*********************************************\n");
   }else if(vNovaVenda->dTotalCompra >= 100){
    vNovaVenda->dTotalCompra = vNovaVenda->dTotalCompra - (vNovaVenda->dTotalCompra * 0.10);
    printf("\n*********************************************");
    printf("\nValor com desconto: R$ %.2f\n", vNovaVenda->dTotalCompra);
    printf("\n*********************************************\n");
   }
  }
  do{
   printf("Forma de pagamento?\n");
   printf("1 - Dinheiro\n");
   printf("2 - Cartao\n");
   scanf("%d", &iFormaPag);
   switch(iFormaPag){
    case 1:
     printf("Dinheiro recebido do cliente: R$ ");
     scanf("%f", &fDinheiroRecebido);
     //se nao for igual - ESTOU NEGANDO
     if(fDinheiroRecebido > vNovaVenda->dTotalCompra){
      float fTroco = 0;
      fTroco = fDinheiroRecebido - vNovaVenda->dTotalCompra;
      printf("TROCO: R$ %.2f\n", fTroco);
     }
     break;
    case 2: addStructVenda(vNovaVenda);
   iCancelaVenda = 1;
   //listaItemVenda(totalVenda);
   vendaRealizada("cadastrada no sistema");
   return iCancelaVenda;
   break;
    default:
     //system("cls");
     defaultMessage();
     break;
   }
  }while(iFormaPag != 1);
  printf("\nFinalizar venda? (1) | Cancelar Venda (0)\n");
  scanf("%d", &iCancelaVenda);
  if(iCancelaVenda == 0){
   printf("\n\t\t\t DESEJA REALMENTE CANCELAR A VENDA? (1) - SIM / (0) - NAO\n");
   scanf("%d", &iCancelaVenda);
   switch(iCancelaVenda){
    case 0:
     //realiza a venda
     addStructVenda(vNovaVenda);
     //recebe um para parar o loop
     iCancelaVenda = 1;
     vendaRealizada("realizada");
     return iCancelaVenda;
     break;
    case 1:
     //limpa a nova venda
     free(vNovaVenda);
     vNovaVenda = NULL;
     //recebe um para parar o loop
     iCancelaVenda = 1;
     vendaRealizada("cancelada");
     return iCancelaVenda;
     break;
   }
  }else{
   addStructVenda(vNovaVenda);
   iCancelaVenda = 1;
   //listaItemVenda(totalVenda);
   vendaRealizada("realizada");
   return iCancelaVenda;
  }
}
void addStructVenda(Venda *vNovaVenda){
 if(vVendaInicial == NULL){
  vVendaInicial = vNovaVenda;
 }else{
  Venda *vAux = vVendaInicial;
  while(vAux->vendaProximo != NULL){
   vAux = vAux->vendaProximo;
  }
  vAux->vendaProximo = vNovaVenda;
 }
}
void tiraEstoque(){
 Produto *pAux = pProdutoInicial;
 ItemVenda *iAux = iItemVendaInicial;
 while(pAux != NULL){
  while(iAux != NULL){
   if(!strcmp(pAux->cvNome, iAux->cvNomeItem)){
    printf("Equals\n");
   }
   iAux = iAux->iItemProximo;
  }
  pAux = pAux->pProximo;
 }
}
void listarVenda(){
 tela("\t    LISTA DE VENDAS");
  if(vVendaInicial == NULL){
         nullList();
     }else{
     printf("\nEntre com o dia desejado: ");
 Venda *vAux = vVendaInicial;
 while(vAux != NULL){
  printf("Data: %d/%d/%d\t| Codigo Venda: %d\t|  Total da Venda: R$%.2f\n", vAux->iDia, vAux->iMes, vAux->iAno,vAux->iCodVenda, vAux->dTotalCompra);
  printf("\n========================================================================================================================\n");
  vAux = vAux->vendaProximo;
 }
 printf("\n\t\t\t\t   PRESSIONE QUALQUER TECLA PARA CONTINUAR!");
}
 fflush(stdin);
 getchar();
}
void vendaRealizada(char mensagem[]){
 printf("***********************************************************************************************************************\n");
 printf("\t\t\t\t\tVenda %s com sucesso!!!\n", mensagem);
 printf("***********************************************************************************************************************\n");
 printf("\n\t\t\t\t   PRESSIONE QUALQUER TECLA PARA CONTINUAR!");
 fflush(stdin);
 getchar();
}
int pesqVendaData(){
 int iDia, iMes, iAno;
 int iNaoEncontrado = 0;
 tela("\tLISTA DE VENDAS POR DATA");
 if(vVendaInicial == NULL){
        nullList();
    }else{
 printf("Entre com a data desejada: ");
 scanf("%d/%d/%d", &iDia, &iMes, &iAno);
 //printf("Data: %d/%d/%d\n", iDia, iMes, iAno);
 Venda *vAux = vVendaInicial;
 while(vAux != NULL){
  if((vAux->iDia == iDia) && (vAux->iMes == iMes) && (vAux->iAno == iAno)){
   printf("\nData: %d/%d/%d\t| Codigo Venda: %d\t| Total da Venda: R$%.2f\n", vAux->iDia, vAux->iMes, vAux->iAno,vAux->iCodVenda, vAux->dTotalCompra);
   printf("\n========================================================================================================================\n");
  }else{
  notFound("Venda");
  }
  vAux = vAux->vendaProximo;
  printf("\n\t\t\t\t   PRESSIONE QUALQUER TECLA PARA VOLTAR!");
  }
  }
  fflush(stdin);
     getchar();
}

void listaItemVenda(float fTotalVenda){
 ItemVenda *iAux = iItemVendaInicial;
 printf("\n\t\t\tProdutos Comprados\n");
 printf("\t\t\t************************************************************\n");
 while(iAux != NULL){
  printf("\t\t\tNome Produto: %s\t Valor: %.2f\n", iAux->cvNomeItem, iAux->fValorItem);
  iAux = iAux->iItemProximo;
 }
 printf("\n\t\t\t\t\t\t TOTAL: %.2f\n", fTotalVenda);
 printf("\t\t\t************************************************************\n");
}
int verificaCliente(){
 int iNaoEncontrado = 0;
 int iJaCliente= 0;
 char cvCpfCli[201];
 //desconto para clientes
 fflush(stdin);
// printf("\t\t\t***** DESCONTO PARA CLIENTES CADASTRADOS!!******\n\n");
 printf("\nPossui cadastro? (1 - Sim) / (0 - NAO)");
 scanf("%d", &iJaCliente);
 if(iJaCliente == 1){
  fflush(stdin);
  printf("Entre com o CPF do cliente: ");
  strcpy(cvCpfCli, FormatarCPF());
  Cliente *cAux = cClienteInicial;
  while(cAux != NULL){
   if(!strcmp(cAux->cvCpf, cvCpfCli)){
    iNaoEncontrado=1;
   strcpy(cvNomeCli, cAux->cvNomeCli);
   }
   cAux = cAux->cProximo;
  }
 }
  return iNaoEncontrado;
}
/******* GRAVAR ARQUIVOS *******/
int gravarProduto(){
 FILE *arq;
 arq = fopen("produto.txt", "wb");
 if(arq == NULL){
  printf("Problemas na criacao do arquivo\n");
  return 1;
 }
 Produto *pAux = pProdutoInicial;
 while(pAux != NULL){
  fwrite(pAux, sizeof(Produto),1,arq);
  pAux = pAux->pProximo;
 }
 fclose(arq);
}
int gravarFuncionario(){
 FILE *arq;
 arq = fopen("funcionario.txt", "wb");
 if(arq == NULL){
  printf("\nProblemas na criacao do arquivo");
  return 1;
 }
 Funcionario *fAux = fFuncionarioInicial;
 while(fAux != NULL){
  fwrite(fAux, sizeof(Funcionario),1,arq);
  fAux = fAux->funProximo;
 }
 fclose(arq);
}
int gravarLogin(){
 FILE *arq;
 arq = fopen("login.txt", "wb");
 if(arq == NULL){
  printf("\nProblemas na criacao do arquivo");
  return 1;
 }
 fwrite(iHaveLogin, sizeof(int), 1,arq);
 fclose(arq);
}
int gravarCliente(){
 printf("Entrou aqui\n");
 FILE *arq;
 arq = fopen("cliente.txt", "wb");
 if(arq == NULL){
  printf("\nProblemas na criacao do arquivo");
  return 1;
 }
 Cliente *fAux = cClienteInicial;
 while(fAux != NULL){
        fwrite(fAux, sizeof(Cliente), 1,arq);
        fAux = fAux->cProximo;
 }
 fclose(arq);
}
int gravarItemVenda(){
 FILE *arq;
 arq = fopen("item_venda.txt", "ab");
 if(arq == NULL){
  printf("\nProblemas na criacao do arquivo");
  return 1;
 }
    ItemVenda *fAux = iItemVendaInicial;
 while(fAux != NULL){
        fwrite(fAux, sizeof(ItemVenda), 1,arq);
        fAux = fAux->iItemProximo;
 }
 fclose(arq);
}
int gravarVenda(){
 FILE *arq;
 arq = fopen("venda.txt", "wb");
 if(arq == NULL){
  printf("\nProblemas na criacao do arquivo");
  return 1;
 }
    Venda *fAux = vVendaInicial;
 while(fAux != NULL){
        fwrite(fAux, sizeof(Venda), 1,arq);
        fAux = fAux->vendaProximo;
 }
    fclose(arq);
}
int gravarFornecedor(){
 FILE *arq;
 arq = fopen("fornecedor.txt", "wb");
 if(arq == NULL){
  printf("\nProblemas na criacao do arquivo");
  return 1;
 }
 Fornecedor *fAux = fFornecedorInicial;
 while(fAux != NULL){
        fwrite(fAux, sizeof(Fornecedor), 1,arq);
        fAux = fAux->fProximo;
 }
 fclose(arq);
}

/******* LER ARQUIVOS *******/
int lerProduto(){
 Produto pProduto;
 FILE *arq;
 arq = fopen("produto.txt", "rb");
 if(arq == NULL){
  printf("Problemas na criacao do arquivo\n");
  return 1;
 }
 while(!feof(arq)){
  int lido = fread(&pProduto, sizeof(Produto),1,arq);
  if(lido == 1){
   Produto *pAux = (Produto*) malloc(sizeof(Produto));
   strcpy(pAux->cvNome, pProduto.cvNome);
   strcpy(pAux->cvValidade, pProduto.cvValidade);
   pAux->fValor = pProduto.fValor;
   pAux->iQtdEstoque = pProduto.iQtdEstoque;
   pAux->iEstoqSeguranca = pProduto.iEstoqSeguranca;
   strcpy(pAux->cvCodigo, pProduto.cvCodigo);
   strcpy(pAux->cvSetor, pProduto.cvSetor);
   pAux->iCodigoFornecedor = pProduto.iCodigoFornecedor;
   pAux->pProximo = pProdutoInicial;
   pProdutoInicial = pAux;
  }
 }
 fclose(arq);
}
int lerFuncionario(){
 Funcionario fun;
 FILE *arq;
 arq = fopen("funcionario.txt", "rb");
 if(arq == NULL){
  printf("\nProblemas na criacao do arquivo!\n");
  return 1;
 }
 while(!feof(arq)){
  int lido = fread(&fun, sizeof(Funcionario),1,arq);
  if(lido == 1){
   Funcionario *newFun = (Funcionario*) malloc(sizeof(Funcionario));
   //jogando dados do arquivo na struct
   strcpy(newFun->cvNomeFunc, fun.cvNomeFunc);
   strcpy(newFun->cvCargo, fun.cvCargo);
   strcpy(newFun->cvCpf, fun.cvCpf);
   strcpy(newFun->cvData_nascimento, fun.cvData_nascimento);
   strcpy(newFun->cvEmail, fun.cvEmail);
   strcpy(newFun->cvTelefone, fun.cvTelefone);
   strcpy(newFun->cvCelular, fun.cvCelular);
   strcpy(newFun->cvEndereco, fun.cvEndereco);
   strcpy(newFun->cvLogin, fun.cvLogin);
   strcpy(newFun->cvSenha, fun.cvSenha);
   newFun->funProximo = fFuncionarioInicial;
   fFuncionarioInicial = newFun;
  }
 }
 fclose(arq);
}
int lerLogin(){
 int iLogin;
 FILE *arq;
 arq = fopen("login.txt", "rb");
 if(arq == NULL){
  printf("\nProblemas na criacao do arquivo");
  return 1;
 }
 while(!feof(arq)){
  int lido = fread(iLogin, sizeof(int),1,arq);
  if(lido == 1){
   iHaveLogin = iLogin;
  }
 }
 fclose(arq);
}
int lerCliente(){
 Cliente cCliente;
 FILE *arq;
 arq = fopen("cliente.txt", "rb");
 if(arq == NULL){
  printf("Problemas na abertura do arquivo\n");
  return 1;
 }
 while(!feof(arq)){
  int lido = fread(&cCliente, sizeof(Cliente),1,arq);
  if(lido == 1){
   Cliente *pAux = (Cliente*) malloc(sizeof(Cliente));
   strcpy(pAux->cvNomeCli, cCliente.cvNomeCli);
   strcpy(pAux->cvCpf, cCliente.cvCpf);
   strcpy(pAux->cvData_nascimento, cCliente.cvData_nascimento);
   strcpy(pAux->cvEmail, cCliente.cvEmail);
   strcpy(pAux->cvTelefone, cCliente.cvTelefone);
   strcpy(pAux->cvCelular, cCliente.cvCelular);
   strcpy(pAux->cvEndereco, cCliente.cvEndereco);
   pAux->cProximo = cClienteInicial;
   cClienteInicial = pAux;
  }
 }
 fclose(arq);
}
int lerFornecedor(){
 Fornecedor fFornecedor;
 FILE *arq;
 arq = fopen("fornecedor.txt", "rb");
 if(arq == NULL){
  printf("Problemas na criacao do arquivo\n");
  return 1;
 }
 while(!feof(arq)){
  int lido = fread(&fFornecedor, sizeof(Fornecedor),1,arq);
  if(lido == 1){
   Fornecedor *pAux = (Fornecedor*) malloc(sizeof(Fornecedor));
   strcpy(pAux->cvNome, fFornecedor.cvNome);
   strcpy(pAux->cvNomeFantasia, fFornecedor.cvNomeFantasia);
   strcpy(pAux->cvEndereco, fFornecedor.cvEndereco);
   strcpy(pAux->cvCnpj, fFornecedor.cvCnpj);
   strcpy(pAux->cvEmail, fFornecedor.cvEmail);
   strcpy(pAux->cvTelefone, fFornecedor.cvTelefone);
   strcpy(pAux->cvCelular, fFornecedor.cvCelular);
   pAux->iCodigoProduto = fFornecedor.iCodigoProduto;
   pAux->fProximo = fFornecedorInicial;
            fFornecedorInicial= pAux;
  }
 }
 fclose(arq);
}

int lerItemVenda(){
 ItemVenda iItemVenda;
 FILE *arq;
 arq = fopen("item_venda.txt", "rb");
 if(arq == NULL){
  printf("Problemas na criacao do arquivo\n");
  return 1;
 }
 while(!feof(arq)){
  int lido = fread(&iItemVenda, sizeof(ItemVenda),1,arq);
  if(lido == 1){
   ItemVenda *pAux = (ItemVenda*) malloc(sizeof(ItemVenda));
   strcpy(pAux->cvNomeItem, iItemVenda.cvNomeItem);
   pAux->fValorItem = iItemVenda.fValorItem;
   pAux->iItemProximo = iItemVendaInicial;
   iItemVendaInicial = pAux;
  }
 }
 fclose(arq);
}
int lerVenda(){
 Venda vVenda;
 FILE *arq;
 arq = fopen("venda.txt", "rb");
 if(arq == NULL){
  printf("Problemas na criacao do arquivo\n");
  return 1;
 }
 while(!feof(arq)){
  int lido = fread(&vVenda, sizeof(Venda),1,arq);
  if(lido == 1){
   printf("Chegou aqui\n");
   Venda *pAux = (Venda*) malloc(sizeof(Venda));
   pAux->iDia = vVenda.iDia;
   pAux->iMes = vVenda.iMes;
   pAux->iAno = vVenda.iAno;
   pAux->iCodVenda = vVenda.iCodVenda;
   pAux->dTotalCompra = vVenda.dTotalCompra;
   pAux->vendaProximo = vVendaInicial;
   vVendaInicial = pAux;
  }
 }
 fclose(arq);
}
void listarEstoque(char nome[]){
    char c[200]="                                                            ";
    char a[200],b[200];
 int iA;
 char d[200]="LISTA DE PRODUTOS - ";
 lerProduto();
 strcat(d,nome);
    tela(d);
    if(pProdutoInicial == NULL){
         nullList();
    }else{
        Produto *pAux = pProdutoInicial;
        while(pAux != NULL){
        if (!strcmp(pAux->cvSetor, nome)){
    iA=54 - strlen(pAux->cvNome);
 strncat(pAux->cvNome,c,iA);
  sprintf(a, "%d", pAux->iQtdEstoque );
 iA=14 - strlen(a);
 strncat(a,c,iA);
 iA=14 - strlen(pAux->cvCodigo);
 strncat(pAux->cvCodigo,c,iA);
 sprintf(b, "%d", pAux->iEstoqSeguranca );
 iA=13 - strlen(b);
 strncat(b,c,iA);
            printf("Nome: %s| Validade: %s   | Valor: %.2f", pAux->cvNome, pAux->cvValidade,pAux->fValor);
            printf("\n------------------------------------------------------------------------------------------------------------------------");
   printf("\nQuantidade Est: %s| Est.Seguranca: %s| Codigo: %s | Cod.Fornecedor: %d",a ,b,pAux->cvCodigo, pAux->iCodigoFornecedor);
            printf("\n========================================================================================================================\n");
    }else{
 }
 pAux = pAux->pProximo;
}
    printf("\n\t\t\t\t   PRESSIONE QUALQUER TECLA PARA VOLTAR!");
}
    fflush(stdin);
    getchar();
    menuEstoque();
}
void listarEstoquista(char nome[]){
    char c[200]="                                                            ";
    char a[200],b[200];
 int iA;
 char d[200]="LISTA DE PRODUTOS - ";
 lerProduto();
 strcat(d,nome);
    tela(d);
    if(pProdutoInicial == NULL){
         nullList();
    }else{
        Produto *pAux = pProdutoInicial;
        while(pAux != NULL){
        if (!strcmp(pAux->cvSetor, nome)){
    iA=54 - strlen(pAux->cvNome);
 strncat(pAux->cvNome,c,iA);
  sprintf(a, "%d", pAux->iQtdEstoque );
 iA=14 - strlen(a);
 strncat(a,c,iA);
 iA=14 - strlen(pAux->cvCodigo);
 strncat(pAux->cvCodigo,c,iA);
 sprintf(b, "%d", pAux->iEstoqSeguranca );
 iA=13 - strlen(b);
 strncat(b,c,iA);
            printf("Nome: %s| Validade: %s   | Valor: %.2f", pAux->cvNome, pAux->cvValidade,pAux->fValor);
            printf("\n------------------------------------------------------------------------------------------------------------------------");
   printf("\nQuantidade Est: %s| Est.Seguranca: %s| Codigo: %s | Cod.Fornecedor: %d",a ,b,pAux->cvCodigo, pAux->iCodigoFornecedor);
            printf("\n========================================================================================================================\n");
    }else{
 }
 pAux = pAux->pProximo;
}
    printf("\n\t\t\t\t   PRESSIONE QUALQUER TECLA PARA VOLTAR!");
}
    fflush(stdin);
    getchar();
    return menuEstoquista();
}
void listarCestoque(char nome[]){
    char c[200]="                                                            ";
    char a[200],b[200];
 int iA;
 char d[200]="LISTA DE PRODUTOS - ";
 lerProduto();
 strcat(d,nome);
    tela(d);
    if(pProdutoInicial == NULL){
         nullList();
    }else{
        Produto *pAux = pProdutoInicial;
        while(pAux != NULL){
        if (!strcmp(pAux->cvSetor, nome)){
    iA=54 - strlen(pAux->cvNome);
 strncat(pAux->cvNome,c,iA);
  sprintf(a, "%d", pAux->iQtdEstoque );
 iA=14 - strlen(a);
 strncat(a,c,iA);
 iA=14 - strlen(pAux->cvCodigo);
 strncat(pAux->cvCodigo,c,iA);
 sprintf(b, "%d", pAux->iEstoqSeguranca );
 iA=13 - strlen(b);
 strncat(b,c,iA);
            printf("Nome: %s| Validade: %s   | Valor: %.2f", pAux->cvNome, pAux->cvValidade,pAux->fValor);
            printf("\n------------------------------------------------------------------------------------------------------------------------");
   printf("\nQuantidade Est: %s| Est.Seguranca: %s| Codigo: %s | Cod.Fornecedor: %d",a ,b,pAux->cvCodigo, pAux->iCodigoFornecedor);
            printf("\n========================================================================================================================\n");
    }else{
 }
 pAux = pAux->pProximo;
}
    printf("\n\t\t\t\t   PRESSIONE QUALQUER TECLA PARA VOLTAR!");
}
    fflush(stdin);
    getchar();
    system ("cls || clear");
}
int gravarAdm(char adm[])
{
  FILE *pont_arq; // cria vari�vel ponteiro para o arquivo
  // vari�vel do tipo string
  //abrindo o arquivo com tipo de abertura w
  pont_arq = fopen("adm.txt", "wb");
  //testando se o arquivo foi realmente criado
  if(pont_arq == NULL)
  {
  printf("Erro na abertura do arquivo!");
  return 1;
  }
  strcpy(adm,"sim");
  //usando fprintf para armazenar a string no arquivo
  fprintf(pont_arq, "%s", adm);
  //usando fclose para fechar o arquivo
  fclose(pont_arq);
  printf("Dados gravados com sucesso!");
}
int lerAdm(char adm[])
{
  FILE *pont_arq;
  //abrindo o arquivo_frase em modo "somente leitura"
  pont_arq = fopen("adm.txt", "rb");
  //enquanto n�o for fim de arquivo o looping ser� executado
  //e ser� impresso o texto
  while(fgets(adm, 20, pont_arq) != NULL)
  //fechando o arquivo
  fclose(pont_arq);
 return 0;
}

