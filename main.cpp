/******************************************************************************
Trabalho – Implementação de um Sistema de
Registro e Gestão de Contas Bancárias (ETAPA 2)
*******************************************************************************/
#include <iostream>
#include <string>
using namespace std;

int main()
{
    // Variáveis
    const int MAX_CONTAS = 100;
    
    int opcao;
    int numeroConta [MAX_CONTAS];
    string nomeCliente [MAX_CONTAS];
    string cpf [MAX_CONTAS];
    double saldo [MAX_CONTAS];
    bool contaAtiva [MAX_CONTAS];
    int tipoConta [MAX_CONTAS];
    int numeroBusca;
    int indice;
    int numeroOrigem;
    int numeroDestino;
    int indiceOrigem;
    int indiceDestino;
    bool temMovimentacao;
    
    int quantidadeContas = 0;
    
    const int MAX_MOVIMENTACOES = 500;
    
    int contaMovimentacao [MAX_MOVIMENTACOES];  
    char tipoMovimentacao [MAX_MOVIMENTACOES];
    double valorMovimentacao [MAX_MOVIMENTACOES];
    int quantidadeMovimentacoes = 0;
    double valor;
    
    do {
        cout << "-----------------------" << endl;
        cout << "1-Cadastrar" << endl;
        cout << "2-Listar" << endl;
        cout << "3-Consultar" << endl;
        cout << "4-Depositar" << endl;
        cout << "5-Sacar" << endl;
        cout << "6-Transferir" << endl;
        cout << "7-Extrato" << endl;
        cout << "0-Sair" << endl;
        cout << "-----------------------" << endl;
        cout << "Escolha: ";
        cin >> opcao;
    
        switch(opcao) {
            case 1: 
                cout << "--- Cadastro de Conta ---" << endl;
                // Verificar se ainda cabe uma Conta
                if (quantidadeContas >= MAX_CONTAS) {
                    cout << "Limite de Contas atingido!" << endl;
                }
                else {
                    cout << "Numero da Conta: " << endl;
                    cin >> numeroBusca;
                    
                    if (numeroBusca <= 0) {
                        cout << "Número Inválido!" << endl;
                    }
                    else {
                        // Verifica se o número já existe
                        bool existe = false;
                        for (int i = 0; i < quantidadeContas; i++) {
                            if (numeroConta[i] == numeroBusca) {
                                existe = true;
                            }
                        }
                        if (existe) {
                            cout << "Conta já Cadastrada!" << endl;
                        }
                        else {
                            numeroConta[quantidadeContas] = numeroBusca;
                            
                            cout << "Nome do Cliente: ";
                            cin  >> nomeCliente[quantidadeContas];
                            
                            cout << "CPF: ";
                            cin  >> cpf[quantidadeContas];
                            
                            do {
                                cout << "Tipo da conta (1-Corrente, 2-Poupança): ";
                                cin  >> tipoConta[quantidadeContas];
                        } while (tipoConta[quantidadeContas] != 1 && tipoConta[quantidadeContas] !=
                        2);
                        
                        do {
                            cout << "Saldo inicial: ";
                            cin  >> saldo[quantidadeContas];
                        } while (saldo[quantidadeContas] < 0);
                        
                        contaAtiva[quantidadeContas] = true;
                        quantidadeContas++;
                        
                        cout << "Conta cadastrada com sucesso!" << endl;
                        }
                    }
                }
                
                break;
                
            case 2:
                cout << "--- Lista de Contas Cadastradas ---" << endl;
                
                // Se não tem conta vai avisar
                if (quantidadeContas == 0) {
                    cout << "Nenhuma conta cadastrada." << endl;
                }
                else {
                    //Percorre todas as contas Cadastradas
                    for (int i = 0; i < quantidadeContas; i++) {
                    
                    cout << "Conta: "   << numeroConta[i] << endl;
                    cout << "Cliente: " << nomeCliente[i] << endl;
                    cout << "CPF: "     << cpf[i]         << endl;
                    cout << "Tipo: "    << tipoConta[i]   << endl;
                    cout << "Saldo: R$" << saldo[i]       << endl;
                    
                    if (contaAtiva[i]) {
                        cout << "Situação: Ativa" << endl;
                    }
                    else {
                        cout << "Situação : Inativa" << endl;
                    }
                    cout << "--------------" << endl;
                    }   
                }
                break;
                
            case 3: 
                cout << "--- Consulta de Conta  ---" << endl;
                
                cout << "Numero da conta: ";
                cin  >> numeroBusca;
                
                // -1 significa não encontrado
                indice = -1;
                
                // Vai percorrer as contas procurando o numero
                for (int i = 0; i < quantidadeContas; i++) {
                    if (numeroConta[i] == numeroBusca) {
                        indice = i;
                    }
                }
                
                if (indice == -1) {
                    cout << "Conta não encontrada." << endl;
                }
                else {
                    cout << "Conta: " << numeroConta[indice] << endl;
                    cout << "Cliente: " << nomeCliente[indice] << endl;
                    cout << "CPF: " << cpf[indice] << endl;
                    cout << "Tipo: " << tipoConta[indice] << endl;
                    cout << "Saldo: R$ " << saldo[indice] << endl;
                    
                    if (contaAtiva[indice]) {
                        cout << "Situação: Ativa " << endl;
                    }
                    else {
                        cout << "Situação: Inativa " << endl;
                    }
                }
                
                break;
                
            case 4:
                cout << "--- Depósito ---" << endl;
                
                cout << "Número da conta: ";
                cin  >> numeroBusca;
                
                // Procura a conta (-1 = a não encontrada)
                indice = -1;
                for (int i = 0; i < quantidadeContas; i++) {
                    if (numeroConta[i] == numeroBusca) {
                        indice = i;
                    }
                }
                
                if (indice == -1) {
                    cout << "Conta não encontrada." << endl;
                }
                else if (!contaAtiva[indice]) {
                    cout << "Conta inativa." << endl;
                }
                else if (quantidadeMovimentacoes >= MAX_MOVIMENTACOES) {
                    cout << "Histórico de movimentações cheio." << endl;
                } 
                else {
                    // Vai ler o valor do Depósito
                    cout << "Valor do depósito: R$ ";
                    cin  >> valor;
                    
                    if (valor <= 0) {
                        cout << "Valor inválido." << endl;
                    }
                    else {
                        // Atualiza o saldo
                        saldo[indice] = saldo[indice] + valor;
                        
                        // Registra as movimentações
                        contaMovimentacao[quantidadeMovimentacoes] = numeroConta[indice];
                        tipoMovimentacao[quantidadeMovimentacoes] = 'D';
                        valorMovimentacao[quantidadeMovimentacoes] = valor;
                        quantidadeMovimentacoes++;

                        cout << "Deposito realizado!" << endl;
                        cout << "Novo saldo: R$ " << saldo[indice] << endl;
                    }
                }
                
                break;
                
            case 5:
                cout << "--- Saque ---" << endl;
                
                cout << "Numero da conta: ";
                cin  >> numeroBusca;
                
                indice = -1;
                for (int i = 0; i < quantidadeContas; i++) {
                    if (numeroConta[i] == numeroBusca) {
                        indice = i;
                    }
                }
                
                if (indice == -1) {
                    cout << "Conta não encontrada." << endl;
                }
                else if (!contaAtiva[indice]) {
                    cout << "Conta inativa." << endl;
                }
                else if (quantidadeMovimentacoes >= MAX_MOVIMENTACOES) {
                    cout << "Histórico de movimentações cheio." << endl;
                }
                else {
                    cout << "Valor de saque: R$ ";
                    cin  >> valor;
                    
                    if (valor <= 0) {
                        cout << "Valor inválido." << endl;
                    }
                    else if (valor > saldo[indice]) {
                        cout << "Saldo insuficiente." << endl;
                    }
                    else {
                        // Atualiza o saldo
                        saldo[indice] = saldo[indice] - valor;
                        
                        // Registra a movimentação
                        contaMovimentacao[quantidadeMovimentacoes] = numeroConta [indice];
                        tipoMovimentacao[quantidadeMovimentacoes] = 'S';
                        valorMovimentacao[quantidadeMovimentacoes] = valor;
                        quantidadeMovimentacoes++;
                        
                        cout << "saque realizado!" << endl;
                        cout << "Novo saldo: R$ "  << saldo[indice] << endl;
                    }
                }
                
                break;
                
            case 6: 
                cout << "--- Transferência ---" << endl;
                
                cout << "Número da conta de origem.";
                cin  >> numeroOrigem;
                
                cout << "Numero da conta destino: ";
                cin  >> numeroDestino;
                
                // Procura as duas contas 
                indiceOrigem = -1;
                indiceDestino = -1;
                for (int i = 0; i < quantidadeContas; i++) {
                    if (numeroConta[i] == numeroOrigem) {
                        indiceOrigem = i;
                    }
                    if (numeroConta[i] == numeroDestino) {
                        indiceDestino = i;
                    }
                }
                
                if (indiceOrigem == -1 || indiceDestino == -1) {
                    cout << "Conta de origem ou destino não encontrada." << endl;
                }
                else if (indiceOrigem == indiceDestino) {
                    cout << "Origem e destino devem ser contas diferentes." << endl;
                }
                else if (!contaAtiva[indiceOrigem] || !contaAtiva[indiceDestino]) {
                    cout << "Uma das contas está inativa." << endl;
                }
                else if (quantidadeMovimentacoes + 2 > MAX_MOVIMENTACOES) {
                    cout << "Histórico de movimentações cheio." << endl;
                }
                else {
                    cout << "Valor da transferência: R$";
                    cin  >> valor;
                    
                    if (valor <= 0) {
                        cout << "Valor inválido." << endl;
                    }
                    else if (valor > saldo[indiceOrigem]) {
                        cout << "Saldo insuficiente." << endl;
                    }
                    else {
                        // Atualiza os dois lados
                        saldo[indiceOrigem] = saldo[indiceOrigem] - valor;
                        saldo[indiceDestino] = saldo[indiceDestino] + valor;
                        
                        // Registro 1: saida da conta de origem
                        contaMovimentacao[quantidadeMovimentacoes] = numeroConta[indiceOrigem];
                        tipoMovimentacao[quantidadeMovimentacoes] ='S';
                        valorMovimentacao[quantidadeMovimentacoes] = valor;
                        quantidadeMovimentacoes++;
                        
                        // Registro 2: entrada na conta de destino
                        contaMovimentacao[quantidadeMovimentacoes] = numeroConta[indiceDestino];
                        tipoMovimentacao[quantidadeMovimentacoes] = 'D';
                        valorMovimentacao[quantidadeMovimentacoes] = valor;
                        quantidadeMovimentacoes++;
                        
                        cout << "transferência realizada!" << endl;
                        cout << "Saldo origem: R$ " << saldo[indiceOrigem] << endl;
                        cout << "Saldo destino : R$ " << saldo[indiceDestino] << endl;
                    }
                }
                
                break;
                
            case 7:
                cout << "--- Extrato ---" << endl;
                
                cout << "Número da conta: ";
                cin  >> numeroBusca;
                
                indice = -1;
                for (int i = 0; i < quantidadeContas; i++) {
                    if (numeroConta[i] == numeroBusca) {
                        indice = i;
                    }
                }
                
                if (indice == -1) {
                    cout << "Conta não encontrada." << endl;
                }
                else {
                    cout << "Conta: " << numeroConta[indice] << " - " << nomeCliente[indice] << endl;
                    
                    // Começa assumindo que não há movimentações
                    temMovimentacao = false;
                    
                    // Percorre o histórico e mostra só as movimentações dessa conta
                    for (int i = 0; i < quantidadeMovimentacoes; i++) {
                        if (contaMovimentacao[i] == numeroBusca) {
                            if (tipoMovimentacao[i] == 'D') {
                                cout << "Depósito: R$ " << valorMovimentacao[i] << endl;
                            }
                            else if (tipoMovimentacao[i] == 'S') {
                                cout << "Saque: R$ " << valorMovimentacao[i] << endl;
                            }
                            temMovimentacao = true;
                        }
                    }
                    
                    if (!temMovimentacao) {
                        cout << "Sem movimentações." << endl;
                    }
                    
                    cout << "Saldo atual: R$ " << saldo[indice] << endl;
                }
                
                break;
                
            case 0:
                cout << "Encerrando..." << endl;
                break;
                
            default:
                cout << "Opção Inválida!" << endl;
                break;
                
        }
    // Vai repetir o menu até o usuário digitar 0.
    } while (opcao != 0);

    return 0;
}