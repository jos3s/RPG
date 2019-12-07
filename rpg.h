#ifndef RPG.H
#define RPG.H

#include <stdio.h>
#include <stdlib.h>

typedef struct personagem{      //Struct que cria a variave PL que serve como base para o personagem
    char nome[20];
    int vida;
    int defesa;
    int forca;
    int velocidade;
}PL;

int ataque(int f, int v){
    int at=f*(v/2);
    return at;
}
int defesa(int d,int o){
    d*=o;
    return d;
 }
int esquivar(int v,int o){
    int es= v*(o*2);
    return es;
 }
int combo(int d, int v){
    d*=v;
    return d;
}

PL criar(PL j){
    int a=0;
    j.vida=1000;
    do{     //cAtribuição dos pontos dos personagens
        puts("Você possui 60 pontos defina a categoria deles.");
        printf("Pontos de defesa:");
        scanf("%d", &j.defesa);
        printf("Pontos de força:");
        scanf("%d", &j.forca);
        printf("Pontos de velocidade:");
        scanf("%d", &j.velocidade);
        a=j.velocidade+j.forca+j.defesa;
        if(a>60)
            puts("Você ultrapassou o limite permitido, repita novamente");
    }while(a>60);
return j;
}

void habilidades(){         //Visualize as informações de habilidades dos personagens
    int h;
    printf("\nDeseja ver a suas habilidades:\n Digite 1 para visualizar, 2 para não exibir. ");
    scanf("%d", &h);
    if(h==1){
        puts("\nHabilidades");
        printf("Nome:\t%s \t %s\n", j1.nome, j2.nome);
        printf("Vida:\t%d \t %d\n", j1.vida,j2.vida);
        printf("Defesa:\t%d \t %d\n", j1.defesa,j2.defesa);
        printf("Força:\t%d \t %d\n", j1.forca, j2.forca);
        printf("Vel.:\t%d \t %d\n", j1.velocidade, j2.velocidade);
        puts("");
    }
}

#endif