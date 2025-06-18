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
		straux[j] = str[i];
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
	
	do{
		teste = 0;
		
		fgets(str, TAM, stdin);
		str[strlen(str)-1] = '\0';

		for(i = 0; i < strlen(str); i++){
			if(!isalnum(str[i]) && str[i] != ' '){
				teste += 1;
			}
		}
	}while(teste > 0);
	
	for(i = 0; i < strlen(str); i++){
		str[i] = tolower(str[i]);
	}
	
	for(i = 0; i < strlen(str); i++){
		if(str[i] == ' '){
			for(j = i; j < strlen(str); j++){
				str[j] = str[j+1];	
			}
		esp++;
		}
	}
	
	str[strlen(str) - esp + 1] = '\0';
	
	printf("A string, conforme as regras, usada sera: %s\n", str);
	
	verificar_palindromo(str, strlen(str));
	
}
