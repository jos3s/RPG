#ifndef RPG.H
#define RPG.H

#include <stdio.h>
#include <stdlib.h>

typedef struct personagem{
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
    do{     //personagem 1
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

#endif