#include <stdio.h> // biblioteca de comunicação com o usuario
#include <stdlib.h> // biblioteca de aloção de espaço em memoria
#include <locale.h> // biblioteca de aloção de texto por regiao
#include <string.h> // biblioteca resonsavel por cuidar das strings

int registro(){ // cadastrar usuarios
    // inicio criação de variaveis/strings
    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    // final criação de variaveis/strings
    printf("Digite o CPF a ser cadastrado: "); // coletando informação do usuario
    scanf("%s", cpf); // %s se refere a string

    strcpy(arquivo, cpf); // responsavel por copiar os valores da string
    FILE *file; // cria o arquivo
    file = fopen(arquivo, "w"); // cria o arquivo e o "w" significa write = escrever
    fprintf(file, cpf); // salvo o valor da variavel
    fclose(file); //fecha o arquivo

    file = fopen(arquivo, "a");
    fprintf(file,",");
    fclose(file);

    printf("digite o nome a ser cadastrado: ");
    scanf("%s", nome);

    file = fopen(arquivo, "a");
    fprintf(file, nome);
    fclose(file);

    file = fopen(arquivo, "a");
    fprintf(file,",");
    fclose(file);

    printf("digite o sobrenome a ser cadastrado: ");
    scanf("%s", sobrenome);

    file = fopen(arquivo, "a");
    fprintf(file, sobrenome);
    fclose(file);

    file = fopen(arquivo, "a");
    fprintf(file,",");
    fclose(file);

    printf("digite o cargo a ser cadastrado: ");
    scanf("%s", cargo);

    file = fopen(arquivo, "a");
    fprintf(file, cargo);
    fclose(file);

    system("pause");
}

int consulta(){
    setlocale(LC_ALL, "Portuguese");

    char cpf[40];
    char conteudo[200];
    printf("digite o CPF a ser consultado: ");
    scanf("%s", cpf);
    FILE *file;
    file = fopen(cpf, "r");

    if (file == NULL){
        printf("não foi possivel localizar o arquivo\n");
    }

    while(fgets(conteudo, 200, file) != NULL){
        printf("\nessas são as informações do usuario: ");
        printf("%s", conteudo);
        printf("\n\n");
    }

    system("pause");

}

int deletar(){
    char cpf[40];
    printf("digite o CPF do usuario ser deletado: ");
    scanf("%s", cpf);
    remove(cpf);
    FILE *file;
    file = fopen(cpf, "r");
    if(file == NULL){
        printf("O usuario não se encontra no sistema\n");
        system("pause");
    }
}
int main(){
    
    int opcao=0; // definindo as variaveis
    int laco=1;
    for(laco=1; laco=1;){

        system("cls");

        setlocale(LC_ALL, "Portuguese"); // colocando em portugues

        printf("### cartório do EBAC ###\n\n"); // inicio do menu
        printf("escolha as opção desejadas pro menu:\n\n");
        printf("\t1- registrar nomes\n");
        printf("\t2- consultar nomes\n");
        printf("\t3- deletar nomes\n"); // final do menu
        printf("\t4- sair do sistema\n\n");
        printf("Opção: ");
        
        scanf("%d", &opcao); // armazenando a escolha do usuario

        system("cls"); // limpa a tela

        switch(opcao){
            case 1:
            registro(); // chamada de funções
            break;

            case 2:
            consulta();
            break;

            case 3:
            deletar();
            break;

            case 4:
            printf("obrigado por utilizar o sistema\n");
            return 0;
            break;

            default:
            printf("essa opção n está disponivel\n");
            system("pause");
            break;
        }

    }
}