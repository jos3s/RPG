#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include "rpg.h"

PL j1,j2;

int jogador1(PL j1, PL j2){
    int esc;

    printf("%s vai ser o primeiro", j1.nome);
    do{
        printf("\n\nJogador %s vai atacar\n", j1.nome);
        printf("Jogador %s escolha 1 para esquivar ou 2 para defender: ",j2.nome);
        scanf("%d", &esc);
        if(esc==1){
            j2.vida-=jesquivar(j1.forca, j1.velocidade, j2.velocidade);
            printf("\nA vida atual de %s é de: %d",j2.nome, j2.vida);
            if(j2.vida<=0)
                break;
        }else{
            j2.vida-=jdefesa(j1.forca,j1.velocidade,j2.defesa);
            printf("\nA vida atual de %s é de: %d",j2.nome, j2.vida);
            if(j2.vida<=0)
                break;
        }
        printf("\n\nJogador %s vai atacar",j2.nome);
        printf("\nJogador %s escolha 1 para esquivar ou 2 para defender: ",j1.nome);
        scanf("%d", &esc);
        if(esc==1){
            j1.vida-=jesquivar(j2.forca, j2.velocidade, j1.velocidade);
            printf("\nA vida atual de %s é de: %d",j1.nome, j1.vida);
            if(j1.vida<=0)
                break;
        }else{
            j1.vida-=jdefesa(j2.forca,j2.velocidade,j1.defesa);
            printf("\nA vida atual de %s é de: %d",j1.nome, j1.vida);
            if(j1.vida<=0)
                break;
        }
    }while(j1.vida>0 || j2.vida>0);
        return 0;
}

int jogador2(PL j1, PL j2){    
    int esc;

    printf("%s vai ser o primeiro", j2.nome);
    do{
        printf("\n\nJogador %s vai atacar", j2.nome);
        printf("\nJogador %s escolha 1 para esquivar ou 2 para defender: ",j1.nome);
        scanf("%d", &esc);
        if(esc==1){
            j1.vida-=jesquivar(j2.forca, j2.velocidade, j1.velocidade);
            printf("\nA vida atual de %s é de: %d",j1.nome, j1.vida);
            if(j1.vida<=0)
                break;
        }else{
            j1.vida-=jdefesa(j2.forca,j2.velocidade,j1.defesa);
            printf("\nA vida atual de %s é de: %d",j1.nome, j1.vida);
            if(j1.vida<=0)
                break;
        }
        printf("\n\nJogador %s vai atacar\n",j1.nome);
        printf("Jogador %s escolha 1 para esquivar ou 2 para defender: ",j2.nome);
        scanf("%d", &esc);
        if(esc==1){
            j2.vida-=jesquivar(j1.forca, j1.velocidade, j2.velocidade);
            printf("\nA vida atual de %s é de: %d",j2.nome, j2.vida);
            if(j2.vida<=0)
                break;
        }else{
            j2.vida-=jdefesa(j1.forca,j1.velocidade,j2.defesa);
            printf("\nA vida atual de %s é de: %d",j2.nome, j2.vida);
            if(j2.vida<=0)
                break;
        }
    }while(j1.vida>0 || j2.vida>0);
        return 0;
}

void jogadores(){
    j1=criar(j1);
    j2=criar(j2);
}

void jogar(){
    printf("\nO octaedro vai ser jogado.\n");
    int v=1+(rand()%8);
    if(v%2==1){ 
        jogador1(j1,j2);
    }else{          //jogador dois inicia
        jogador2(j1, j2);
    }
}

int main(){
    setlocale(LC_ALL,"");
    srand(time(NULL));

    jogadores();
    habilidades(j1,j2);
    
    jogar();
    
    puts("");
    puts("");
    puts("O jogo acabou.");
    puts("");
    system("pause");

return 0;
}
