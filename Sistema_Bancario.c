// Atividade MAPA - Linguagens e Técnicas de Programação
// O sistema permite o cadastro de 100 clientes, o que pode ser alterado modificando a constante MAX_CLIENTES.
// Codificação de página: Western (Windows 1252).
#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>

#define MAX_CLIENTES 100
#define msg_cad_vazio "Nenhum cadastro registrado.\n\n"
#define msg_opc_inv "Opção inválida, tente novamente.\a\n\n"

// Registro cliente
struct cliente{
    char nome[80];
    char cpf[15];
    char setor[35];
};

// Vetor para armazenar os registros de clientes, com tamanho máximo de 100 por padrão.
struct cliente clientes[MAX_CLIENTES];

// Contador para o número de usuários já cadastrados.
int num_usu = 0;

// Função para realizar cadastro de clientes.
void CadCli();
// Função para listar todos os cadastros.
void ListAtenTudo();
// Função para listar os cadastros filtrados por setor.
void ListAtenSetor();
// Função para obter e formatar o CPF.
void ObterFormatarCPF(char cpf[]);

int main(){
    setlocale(LC_ALL, "Portuguese");
    int escolha_aten = 0;
    while (escolha_aten != 4) {
        system("cls");
        printf("------------- MENU INICIAL -------------\n");
        printf("\n----------------------------------------\n");
        printf("Bem vindo(a) ao sistema de atendimento\n\n");
        printf("1 - Solicitar Atendimento\n");
        printf("2 - Listar Atendimentos Registrados\n");
        printf("3 - Listar Atendimentos por Setor\n");
        printf("4 - Sair\n");
        printf("----------------------------------------\n");
        printf("\nEscolha sua opção: ");
        fflush(stdin);
        scanf("%d", &escolha_aten);
        switch (escolha_aten) {
            case 1: CadCli(); break;
            case 2: ListAtenTudo(); break;
            case 3: ListAtenSetor(); break;
            case 4: break;
            default: 
                system("cls");
                printf("------------- MENU INICIAL -------------\n\n");
                printf(msg_opc_inv);
                system("pause");
                break;
        }
        system("cls");
    }
    return 0;
}

void CadCli(){
    int efet_cad = 1; // Variável de decisão para o usuário. (1)Efetuar ou (0)Não efetuar outro cadastro.
    while (efet_cad == 1) {
        if (num_usu < MAX_CLIENTES) {
            int escolha_setor = 0;
            system("cls");
            printf("----------------- CADASTRO DE CLIENTE -----------------\n");
            fflush(stdin);
            printf("\nDigite seu nome: ");
            fgets(clientes[num_usu].nome, sizeof(clientes[num_usu].nome), stdin);
            clientes[num_usu].nome[strcspn(clientes[num_usu].nome, "\n")] = '\0';
            ObterFormatarCPF(clientes[num_usu].cpf);
            while (escolha_setor != 1 && escolha_setor != 2 && escolha_setor != 3 && escolha_setor != 4) {
                system("cls");
                printf("----------------- CADASTRO DE CLIENTE -----------------\n");
                printf("\n-------------------------------------------------------\n");
                printf("Escolha o setor de atendimento desejado: \n\n");
                printf("1 - Abertura de Conta\n");
                printf("2 - Caixa\n");
                printf("3 - Gerente Pessoa Física\n");
                printf("4 - Gerente Pessoa Jurídica\n");
                printf("-------------------------------------------------------\n");
                printf("\nSetor desejado: ");
                fflush(stdin);
                scanf("%d", &escolha_setor);
                switch (escolha_setor) {
                    case 1: strcpy(clientes[num_usu].setor, "1 - Abertura de Conta"); break;
                    case 2: strcpy(clientes[num_usu].setor, "2 - Caixa"); break;
                    case 3: strcpy(clientes[num_usu].setor, "3 - Gerente Pessoa Física"); break;
                    case 4: strcpy(clientes[num_usu].setor, "4 - Gerente Pessoa Jurídica"); break;
                    default: 
                        system("cls");
                        printf("----------------- CADASTRO DE CLIENTE -----------------\n\n");    
                        printf(msg_opc_inv);
                        system("pause");
                        break;
                }
            }
            system("cls");
            printf("----------------- CADASTRO DE CLIENTE -----------------\n\n");
            printf("Cadastro realizado com sucesso!\n");
            printf("\n=======================================================\n");
            printf("Nome: %s.\nCPF: %s.\nSetor: %s.", clientes[num_usu].nome, clientes[num_usu].cpf, clientes[num_usu].setor);
            printf("\n=======================================================\n\n");
            printf("Deseja realizar outro cadastro?\n\n| Se SIM digite 1           |\n| Se NÃO digite outra tecla |\n\n");
            num_usu++;
            efet_cad = 0;
            printf("Sua resposta: ");
            fflush(stdin);
            scanf("%d", &efet_cad);
        } else {
            system("cls");
            printf("----------------- CADASTRO DE CLIENTE -----------------\n\n");
            printf("Número máximo de clientes atingido. \nNão é possível realizar outro cadastro.\n\n");
            system("pause");
            return;
        }
    }
}

void ListAtenTudo(){
    system("cls");
    printf("-------- LISTAGEM DE ATENDIMENTOS REGISTRADOS --------\n\n");
    if (num_usu == 0) {
        printf(msg_cad_vazio);
    } else {
        printf("======================================================\n");
        printf("Total de cadastros no sistema: %d.\n\n", num_usu);
        printf("======================================================\n");
        for (int i = 0; i < num_usu; i++) {
            printf("Nome: %s.\nCPF: %s.\nTipo Atendimento: %s.\n", clientes[i].nome, clientes[i].cpf, clientes[i].setor);
            printf("======================================================\n");
        }
        printf("\n");
    }
    system("pause");
}

void ListAtenSetor(){
    int escolha_cat = 0;
    int setor_vazio = 1;
    while (escolha_cat != 1 && escolha_cat != 2 && escolha_cat != 3 && escolha_cat != 4) {
        system("cls");
        printf("----- LISTAGEM DE ATENDIMENTOS REGISTRADOS POR SETOR -----\n\n");
        printf("----------------------------------------------------------\n");
        printf("Selecione qual setor deseja ver os cadastros:\n\n");
        printf("1 - Abertura de Conta\n");
        printf("2 - Caixa\n");
        printf("3 - Gerente Pessoa Física\n");
        printf("4 - Gerente Pessoa Jurídica\n");
        printf("----------------------------------------------------------\n");
        printf("\nSetor desejado: ");
        fflush(stdin);
        scanf("%d", &escolha_cat);
        system("cls");
        printf("----- LISTAGEM DE ATENDIMENTOS REGISTRADOS POR SETOR -----\n\n");
        switch (escolha_cat) {
            case 1: 
                printf("Listando cadastros do setor 1 - Abertura de Conta:\n\n");
                printf("==========================================================\n");
                for (int i = 0; i < num_usu; i++) {
                    if (strcmp(clientes[i].setor, "1 - Abertura de Conta") == 0) {
                        printf("Nome: %s.\nCPF: %s.\n", clientes[i].nome, clientes[i].cpf);
                        printf("==========================================================\n");
                        setor_vazio = 0;
                    }
                }
                if (setor_vazio) printf(msg_cad_vazio);
                break;

            case 2: 
                printf("Listando cadastros do setor 2 - Caixa:\n\n");
                printf("==========================================================\n");
                for (int i = 0; i < num_usu; i++) {
                    if (strcmp(clientes[i].setor, "2 - Caixa") == 0) {
                        printf("Nome: %s.\nCPF: %s.\n", clientes[i].nome, clientes[i].cpf);
                        printf("==========================================================\n");
                        setor_vazio = 0;
                    }
                }
                if (setor_vazio) printf(msg_cad_vazio);
                break;
            
            case 3:
                printf("Listando cadastros do setor 3 - Gerente Pessoa Física:\n\n");
                printf("==========================================================\n");
                for (int i = 0; i < num_usu; i++) {
                    if (strcmp(clientes[i].setor, "3 - Gerente Pessoa Física") == 0) {
                        printf("Nome: %s.\nCPF: %s.\n", clientes[i].nome, clientes[i].cpf);
                        printf("==========================================================\n");
                        setor_vazio = 0;
                    }
                }
                if (setor_vazio) printf(msg_cad_vazio);
                break;
            
            case 4:
                printf("Listando cadastros do setor 4 - Gerente Pessoa Jurídica:\n\n");
                printf("==========================================================\n");
                for (int i = 0; i < num_usu; i++) {
                    if (strcmp(clientes[i].setor, "4 - Gerente Pessoa Jurídica") == 0) {
                        printf("Nome: %s.\nCPF: %s.\n", clientes[i].nome, clientes[i].cpf);
                        printf("==========================================================\n");
                        setor_vazio = 0;
                    }
                }
                if (setor_vazio) printf(msg_cad_vazio);
                break;

            default:
                printf(msg_opc_inv);
                system("pause");
                break;
        }
    }
    printf("\n");
    system("pause");
}

void ObterFormatarCPF(char cpf[]) {
    char cpfFormatado[15]; // Tamanho máximo de um CPF formatado: XXX.XXX.XXX-XX
    while (strlen(clientes[num_usu].cpf) != 11) {
        printf("Digite seu CPF (somente números): ");
        fflush(stdin);
        fgets(clientes[num_usu].cpf, sizeof(clientes[num_usu].cpf), stdin);
        clientes[num_usu].cpf[strcspn(clientes[num_usu].cpf, "\n")] = '\0';
        if (strlen(clientes[num_usu].cpf) != 11) {
            printf("\nErro. O CPF deve conter exatamente 11 números. Tente novamente.\n\n");
        } else {
            // Formatando o CPF com os pontos e o traço.
            snprintf(cpfFormatado, sizeof(cpfFormatado), "%.3s.%.3s.%.3s-%.2s", cpf, cpf + 3, cpf + 6, cpf + 9);
            strcpy(clientes[num_usu].cpf, cpfFormatado);
            return;
        }
    }
}
