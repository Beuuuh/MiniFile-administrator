#include <stdio.h>
#include <stdlib.h>

int addText() { 
			//Criando o arquivo em texto.
			//Criando o ponteiro para o texto, e criando a string para o texto.
    FILE *arquivo;
    char texto[200];
    
    //Abrindo o arquivo para escrita(fopen - w)
    arquivo = fopen("texto.txt", "w");
    
    //Pedindo para o usuário escrever seu texto e lendo toda a string de texto
    printf("Digite o texto que deseja salvar como arquivo de texto:\n");
    fgets(texto, sizeof(texto), stdin);
	
	//Salvando o texto dentro do arquivo
	fprintf(arquivo, "%s", texto);
	
	//Fechando o arquivo
	fclose(arquivo);
	
	printf("Arquivo 'texto.txt' salvo com sucesso!\n");
	return 0;

		//Caso o usuário, após escrever seu texto e salvar, desejar alterá-lo
		//Mostrará o que ele já escreveu e perguntará se ele quer mesmo alterar

char c;
arquivo = fopen("texto.txt", "r");
while ((c = fgetc(arquivo)) != EOF) {
    printf("%s", c);
}
fclose(arquivo);

		//Agora, adicionando texto ao final, sem apagar o que já está feito
char novo_texto[200];

//Anexando no final
arquivo = fopen("texto.txt", "a");

printf("Digite o texto adicional para o arquivo:\n");
fgets(novo_texto, sizeof(novo_texto), stdin);

//Escrevendo no final do arquivo existente
fprintf(arquivo, "%s", novo_texto);
fclose(arquivo);
printf("Texto adicionado com sucesso!\n");

return 0;
}

