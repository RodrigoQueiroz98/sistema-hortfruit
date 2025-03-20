# 🌱 Sistema de Cadastro e Vendas HortFruit  

Este é um sistema desenvolvido em **C** para gerenciar um hortifrúti, permitindo o cadastro de produtos, clientes, fornecedores, funcionários e usuários, além de realizar vendas com controle detalhado de caixa. *O ARQUIVO DE EXECUÇÃO SE CHAMA PIM.C*

## 🚀 Funcionalidades  

✔️ **Cadastro e gerenciamento** de produtos, clientes, fornecedores, funcionários e usuários  
✔️ **Sistema de login** com senha de administrador para funções restritas  
✔️ **Controle de vendas**, com registro detalhado de cada transação  
✔️ **Relatórios financeiros**, incluindo total de vendas do dia e histórico por data  
✔️ **Gerenciamento de caixa**, permitindo abertura, fechamento e listagem de itens vendidos  
✔️ **Armazenamento de dados em arquivos `.txt`** para persistência das informações  

## 🛠️ Bibliotecas Utilizadas  

O projeto foi desenvolvido utilizando as seguintes bibliotecas:  

```c
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#define MAX_ITENS 100 
