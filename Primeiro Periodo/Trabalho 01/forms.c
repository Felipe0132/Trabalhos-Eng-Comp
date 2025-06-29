#include "forms.h"

int primo(int num){ //Se for primo returno 1, se não ele retorna 0

    int i;

    if(num == 1 || num == 2){
        return 0;
    }

    for(i = 0; i < num; i++){

        if(num%i == 0){
            return 0;
        }

    }

    return 1;
}

int alfabetoAZ(char letra){ //Confere se o caracte é de A a Z. Se for de A a Z retorna 1, se nao, 0

    if(letra == 'A' || letra == 'B' || letra == 'C' || letra == 'D' || letra == 'E' || letra == 'F' || letra == 'G' || letra == 'H' || letra == 'I' || letra == 'J' || letra == 'K' || letra == 'L' || letra == 'M' || letra == 'N' || letra == 'O' || letra == 'P' || letra == 'Q' || letra == 'R' || letra == 'S' || letra == 'T' || letra == 'U' || letra == 'V' || letra == 'W' || letra == 'X' || letra == 'Y' || letra == 'Z'){

        return 1;
    }

    return 0;

}

int alfabetoaz(char letra){ //Confere se o caracte é de A a Z. Se for de a a z retorna 1, se nao, 0

    if(letra == 'a' || letra == 'b' || letra == 'c' || letra == 'd' || letra == 'e' || letra == 'f' || letra == 'g' || letra == 'h' || letra == 'i' || letra == 'j' || letra == 'k' || letra == 'l' || letra == 'm' || letra == 'n' || letra == 'o' || letra == 'p' || letra == 'q' || letra == 'r' || letra == 's' || letra == 't' || letra == 'u' || letra == 'v' || letra == 'w' || letra == 'x' || letra == 'y' || letra == 'z'){

        return 1;
    }

    return 0;

}
    
int caracnumeros(char num){ //Confere se é número. Se for numero retorna 1, se nao, 0

    if(num >= '0' && num <= '9'){

        return 1;
    }

    return 0;
}