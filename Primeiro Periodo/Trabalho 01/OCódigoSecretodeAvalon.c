//A ideia do trabalho eh dar uma entrada de uma string e passar pela funcao que verifica palindromo, palavras que ao contrario eh a mesma coisa,
//porem existe regras, nao eh permitido caracteres especiais como acentos e etc, e o programa ignora acentos.
#include "forms.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TAM 80

void verificar_palindromo(char str[],int num){
	
	int i, teste = 0, tam, j = 0;
	char straux[num];
	
	tam = num;
	
	for(i = tam - 1; i >= 0; i--){
		straux[j] = str[i]; //str auxiliar recebendo a str original ao contrario
		j++;
	}
	
	if(strcmp(straux, str) != 0){
		printf("False.\n");
		printf("A frase invertida eh: %s\n", straux);
	}else{
		printf("True\n");
		printf("A frase invertida eh: %s\n", straux);
	}
}

int main(){
	
	int i, teste = 0, j, esp = 0;
	char str[TAM];
	
	printf("Digite uma palavra. (Max = 80 caracteres!)\n");
	printf("Nao eh aceito palavras com caracteres!\n");
	
	fgets(str, TAM, stdin);
	str[strlen(str)-1] = '\0';

	for(i = 0; i < strlen(str); i++){
		if(alfabetoAZ(str[i]) == 0){
			str[i] = ' ';
		}else if(alfabetoaz(str[i]) == 0){
			str[i] = ' ';
		}else if(caracnumeros(str[i]) == 0){
			str[i] = ' ';
		}
	}
	
	for(i = 0; i < strlen(str); i++){
		str[i] = tolower(str[i]); //Altera todos os caracteres para minusculos
	}
	
	for(i = 0; i < strlen(str); i++){
		if(str[i] == ' '){ 
			for(j = i; j < strlen(str); j++){ //Traz todos os caracteres para a posicao anterior, excluindo o espaco e comprimindo a str
				str[j] = str[j+1];	
			}
		esp++;
		}
	}
	
	str[strlen(str) - esp + 1] = '\0'; //Limpando os espacos vazios
	
	printf("A string, conforme as regras, usada sera: %s\n", str);
	
	verificar_palindromo(str, strlen(str));
	
}
