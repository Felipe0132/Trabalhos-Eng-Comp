#include <stdio.h>
#include <stdlib.h>

int busca_fibonacci(int numvez, int numdesejado){
	
	int numaux, meio, vez = 0, i;
	long *num;
	
	num = (long*) malloc(numvez * sizeof(long)); //Aqui ele pega o numero "enezimo" primeiro numero da sequencia que a pessoa deseja e faz um vetor desse tamanho
	
	num[0] = 0;
	num[1] = 1;
	
	for(i = 2; i < numvez; i++){
		num[i] = num[i-1] + num[i-2];	//Faz a sequencia de fibonnaci
	}
	

	
	meio = (numvez-1) / 2; // comeca a busca binaria, dividindo o vetor em 2
	
	
	while(meio >= 0 && vez <= numvez / 2){ //Ele para quando o meio for menor a 0, porque eh a ultima divisao aceitavel e o ele so vai rodar o numero de numeros que houve na sequencia divido por 2, pois so analisa uma metade
		if(num[meio] == numdesejado){ //Aqui ele comeca a analisar em quais partes ele esta, maior ou menos que a metade procurada
			free(num);
			return meio;
			break;
		}else if(num[meio] > numdesejado){ //Se for menor do que o meio selecionado ele divide por 2 novamente
				meio = meio / 2;
			}else if(num[meio] < numdesejado){
				meio = (numvez - meio)/2 + meio; //Se for maior que o numero do meio selecionado
		}
		vez++;
	}
	free(num);
	return -1;
}

int main(){
	
	int numvez, numdesejado, indice, i;
	long numaux, num1 = 0, num2 = 1;
	
	printf("Quantos numeros aparecera da sequencia?\n");
	scanf("%d", &numvez);
	
	printf("Digite o valor que deseja procurar:\n");
	scanf("%d", &numdesejado);
	
	for(i = 0; i < numvez; i++){
		printf("%ld ", num1);
		numaux = num2;
		num2 = num1 + num2;
		num1 = numaux;
	}
	
	printf("\n\nProcurando valor...\n");
	printf("...\n");
	printf("...\n");
	printf("...\n\n");
	
	indice = busca_fibonacci(numvez, numdesejado);
	
	printf("O indice do valor %d eh: %d\n", numdesejado, indice);
	
}
