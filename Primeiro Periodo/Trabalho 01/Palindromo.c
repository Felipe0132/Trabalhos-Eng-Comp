//A ideia do trabalho eh dar uma entrada de uma string e passar pela funcao que verifica palindromo, palavras que ao contrario eh a mesma coisa,
//porem existe regras, nao eh permitido caracteres especiais como acentos e etc, e o programa ignora acentos.
#include "../../../Projetos-Pessoais/forms.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TAM 80

void testpalindromo(char str[], int num){

	int i;
	char straux[num];

	for(i = 0; i < num; i++){
		straux[i] = str[num-i-1]; 
	}

	straux[num] = '\0';

	printf("A frase invertida é: %s\n", straux);

	if(strcmp(str, straux)){
		printf("False\n");
	}else{
		printf("True\n");
	}

	//printf("strtam de %s : %d\n", str, strlen(str));
	//printf("strtam de %s : %d\n", straux, strlen(straux));
}

int main(){

	int i, strtam, j;
	char str[TAM];

	printf("Digite a frase que deseja testar:\n");
	fgets(str, TAM, stdin);
	str[strlen(str)-1] = '\0';

	strtam = strlen(str);

	for(i = 0; i < strtam; i++){
		if(alfabetoAZ(str[i]) != 1 && alfabetoaz(str[i]) != 1 && caracnumeros(str[i]) != 1){
			str[i] = ' ';
		}
	}

	for(i = 0; i < strtam; i++){
		while(str[i] == ' '){
			for(j = i; j < strtam; j++){
				str[j] = str[j+1]; 
			}
		}
		str[i] = tolower(str[i]);
	}


	printf("A palavra ignorando os caracteres especiais é: %s\n", str);

	testpalindromo(str, strlen(str));
}