#include <stdio.h>
#include <stdlib.h>
#include <time.h>
	
#define L 17
#define A 17

char mapa[L][A];

int funcaocaminho(int x, int y, int res){
	
	int i=1, z;
	
	if(x < 0 || x >= L || y < 0 || y >= A){ // Checar os limites 
        return 0;
	}
	
	if(mapa[x][y] != ' ' && mapa[x][y] != 'H' && mapa[x][y] != 'Z'){ //Validando se essa coordenada eh robo ou asterisco
	 	return 0;	
	}
	
	if(mapa[x][y] != 'H'){ //Reservar o caractere H
		mapa[x][y] = '*';
	}
	
	if(res == 1){
		for(i = 0; i < L; i++){
			printf("||");
			for(z = 0; z < A; z++){
				printf("%c ", mapa[i][z]);
			}
			printf("||\n");
		}
	
		
		system("pause");
	}
	
	if(mapa[x+1][y] == 'Z' || mapa[x-1][y] == 'Z' || mapa[x][y+1] == 'Z' || mapa[x][y-1] == 'Z'){ //Verificar se as posicoes laterais sao o Z, para ele nao precisar passar em "em cima"
		return 1;
	}
	
	if(funcaocaminho(x+1, y, res) || funcaocaminho(x, y+1, res) || funcaocaminho(x, y-1, res) || funcaocaminho(x-1, y, res)){ //
        return 1;
    }
	
	if(mapa[x][y] != 'H'){
		mapa[x][y] = ' '; //Aqui caso a funcao da vez da funcao nao retorne 1 ele ira apagar seu processo, assim ele impre so a funcao que achar primeiro
	}
	return 0;
}

int main(){

	char achou = '0';
	int i, z, x, y, vzs = 0, nrobo, res;
	
	srand(time(NULL));
	
	for(i = 0; i < L; i++){
		for(z = 0; z < A; z++){
			mapa[i][z] = ' ';
		}
	}
	
	printf("Digite quantos robos deseja ter:\n");
	do{
		printf("Max: %d\n", A*L-2);
		scanf("%d", &nrobo);
	}while(nrobo > A*L - 2);
		
	for(i = 0; i < nrobo; i++){
		mapa[rand() % L][rand() % A] = 'R';
	}
	
	x = rand() % L;
	y = rand() % A; // Gerando posicoes aleatorias para Z e R como fez com os robos
	
	mapa[x][y] = 'Z';
	
	x = rand() % L;
	y = rand() % A;
	
	mapa[x][y] = 'H';
		
	printf("O humano esta na posicao [%d] [%d].\n", x, y);

	
	for(i = 0; i < L; i++){
		printf("||");
		for(z = 0; z < A; z++){
			printf("%c ", mapa[i][z]);
		}
		printf("||\n");
	}
	
	printf("Deseja olhar passo a passo?\n");
	printf("[1]SIM\n[2]NAO\n");
	scanf("%d", &res);
	
	printf("\nProcurando caminho...\n\n");
	
	if(funcaocaminho(x, y, res) == 1){
		printf("Achou!\n");
	}else{
		printf("Nao eh possivel achar caminho!\n");
	}
	
	for(i = 0; i < L; i++){
		printf("||");
		for(z = 0; z < A; z++){
			printf("%c ", mapa[i][z]);
		}
		printf("||\n");
	}
}
