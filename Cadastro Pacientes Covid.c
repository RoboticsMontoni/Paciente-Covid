#include <stdio.h>
#include <stdlib.h>
#include <string.h> //Biblioteca para usar a funçao strcmp
#include <conio.h>
#include <locale.h>

/* Começo Matriz*/

char name[50];
char email[50];
char cpf[11];
char birthDay[10];
char phoneNumber[15];
char street[50];
char streetNumber[10];
char neighborhood[30];
char city[30];
char state[2];
char cep[9];
char diagnosisDay[10];
char comorbidity[20];

// FUNÇÕES

int validate_password() {
    char login[20];
    char senha[20];
    int i, senha_ok;
    char c;

    do {
        system("CLS");
    printf(">>> Sistema de cadastro de pacientes diagnosticados com Covid-19 >>>\n\n\n\n\n");
    fflush(stdin);
    printf("Login: ");
    gets(login);
    printf("\nSenha: ");
    i = 0;
        while((c=getch())!=13){ //13 é o valor de ENTER na tabela ASCII
            senha[i]=c;
            i++;
            printf("*");      //imprime o * Anterisco
        }
        senha[i]='\0';

    senha_ok = strcmp(senha, "Covid");
    if(!senha_ok) return 1;
       } while (senha_ok);
}


int read_option(){ // Ler opções do programa
    int opcao, passagem = 0;

    do {
    system("cls");
        printf("Menu Principal\n");
        printf("--------------\n");
        printf("1- Cadastrar Paciente\n");
        printf("2- Consultar Paciente\n");
        printf("3- Pesquisar Paciente (Nome/CPF)\n");
        printf("0- Sair do Programa\n");
        if (passagem)
        printf("\n *** Opcao invalida!\n");
    printf ("Escolha uma das opcoes:\n");
        printf(">>> ");
        scanf("%d",&opcao);
    getchar();
        printf("\n");
    if (opcao != 0 && opcao != 1 && opcao != 2 && opcao != 3) passagem = 0;

       } while (opcao != 0 && opcao != 1 && opcao != 2 && opcao != 3);
    return opcao;
}


/*
void pause(char mensagem[]){
    printf("%s",mensagem);
    getch();
}
*/

int salvar(void) {
    FILE *fp;

    fp = fopen("arquivo.txt", "a");

    if (fp == NULL) {
    return 0;
    }

    fprintf(fp, "%s", name);
    fprintf(fp, "%s", email);
    fprintf(fp, "%s", cpf);
    fprintf(fp, "%s", birthDay);
    fprintf(fp, "%s", phoneNumber);
    fprintf(fp, "%s", street);
    fprintf(fp, "%s", streetNumber);
    fprintf(fp, "%s", neighborhood);
    fprintf(fp, "%s", city);
    fprintf(fp, "%s", state);
    fprintf(fp, "%s", cep);
    fprintf(fp, "%s", diagnosisDay);
    fprintf(fp, "%s", comorbidity);

    fclose(fp);
    return 1;
}

void cadastrar(){
    system("cls");
    printf("<<< Entrada de paciente >>>\n\n\n ");
    printf("\nDigite o Nome do Paciente: ");
    scanf ("%[^\n]s", &name);
    getchar();
    printf("\nDigite o Email do Paciente: ");
    scanf ("%[^\n]s", &email);
    getchar();
    printf("\nDigite o CPF do Paciente");
    scanf ("%[^\n]s", &cpf);
    getchar();

    float ForaGrupo, PertenceGrupoRisco;
        printf("\n\tDigite a idade do Paciente\n : ");
        scanf("%f", &ForaGrupo);

   if (ForaGrupo >= 64 && PertenceGrupoRisco <= 65 )
     printf("Pertence a Grupo de Risco \n");
   else
     printf("Fora do Grupo de Risco \n");




    printf("\nDigite o telefone do Paciente (Somente Numeros");
    scanf ("%[^\n]s", &phoneNumber);
    getchar();
    printf("\nEndereco:\nLogradouro (rua, avenida, alameda ou outro): ");
    scanf ("%[^\n]s", &street);
    getchar();
    printf("\nNumero: ");
    scanf ("%[^\n]s", &streetNumber);
    getchar();
    printf("\nBairro: ");
    scanf ("%[^\n]s", &neighborhood);
    getchar();
    printf("\nCidade: ");
    scanf ("%[^\n]s", &city);
    getchar();
    printf("\nEstado (sigla = XX): ");
    scanf ("%[^\n]s", &state);
    getchar();
    printf("\nCEP (no formato 99999-999): ");
    scanf ("%[^\n]s", &cep);
    getchar();
    printf("\nQual Dia do diagnostico?\nNo formato DD/MM/AAAA: ");
    scanf ("%[^\n]s", &diagnosisDay);
    getchar();
    printf("\n O paciente tem alguma comorbidade?");
    scanf ("%[^\n]s", &comorbidity);
    getchar();

    if (salvar()) printf ("\n\nDados do paciente salvo em arquivo!\n\n");
    else printf ("\n\nHouve um problema com a manipulação do arquivo.\n\n");

    system("pause");
}

/*
int comorbidity_option() { // ler tipos de comorbidades
    printf("Qual o tipo de comorbidade?\nEscolha entre as opções:\n");
    printf("1- Diabetes");
    printf("2- Obesidade\n");
    printf("3- Hipertensão\n");
    printf("4- Tuberculose\n");
    printf("Opção: ");
    scanf("%d",&x);
    printf("\n");
    return x;

}
*/

int consultar() {
    system("cls");
    FILE *fp;

    fp = fopen("arquivo.txt", "r");

    if (fp == NULL) {
    return 0;
    }

    fscanf(fp, "%s", &name);
    fscanf(fp, "%s", &email);
    fscanf(fp, "%s", &cpf);
    fscanf(fp, "%s", &birthDay);
    fscanf(fp, "%s", &phoneNumber);
    fscanf(fp, "%s", &street);
    fscanf(fp, "%s", &streetNumber);
    fscanf(fp, "%s", &neighborhood);
    fscanf(fp, "%s", &city);
    fscanf(fp, "%s", &state);
    fscanf(fp, "%s", &cep);
    fscanf(fp, "%s", &diagnosisDay);
    fscanf(fp, "%s", &comorbidity);

    fclose(fp);
    return 1;
}

int pesquisar() {
    system("cls");
    printf("*** Pesquisa sendo construída ***\n\n");
    system("pause");
}


void imprimir() {
    system("cls");
    printf ("*** Consulta de Paciente ***\n\n\n\n\n");
    printf ("Nome do Paciente: %s\n", name);
    printf ("E-mail: %s\n", email);
    printf ("Data de Nascimento: %s\n", birthDay);
    printf ("Telefone: %s\n", phoneNumber);
    printf ("Endereço:\n");
    printf ("%s número: %s bairro: %s\n", street, streetNumber, neighborhood);
    printf ("cidade: %s estado: %s CEP: %s\n", city, state, cep);
    printf ("Data do diagnóstico: %s\n", diagnosisDay);
    printf ("Comorbidade: %s\n", comorbidity);
    printf ("\n\n * Dados do paciente recuperados do arquivo *\n\n");
}

// FIM FUNÇÕES

int main()
{
    int opcao;
    setlocale(LC_ALL, "Portuguese");

    if(validate_password()) {
    do {
        opcao = read_option();
        switch(opcao)
        {
            case 0:
            system("cls");
            printf ("* Você acabou de sair do sistema *\n\n");
            system("pause");
            return 0;
            case 1:
            cadastrar();
            break;
            case 2:
            if (consultar()) imprimir();
                else printf ("\n\nHouve um problema com a manipulação do arquivo.\n\n");
            system ("pause");
            break;
            case 3:
            pesquisar();
            break;
        }
       } while (1);
    }
}
