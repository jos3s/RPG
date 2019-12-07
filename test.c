#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include "rpg.h"

PL j1,j2;

void habilidades(){
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

int jogador2(PL j1, PL j2){    
    int dano1,dano2;
    int dano;
    int at, es, com, def;
    int esc,dado;
    char p,pt;

    printf("%s vai ser o primeiro", j2.nome);
    do{
        printf("\n\nJogador %s vai atacar", j2.nome);
        printf("\nJogador %s escolha 1 para esquivar ou 2 para defender: ",j1.nome);
        scanf("%d", &esc);
            if(esc==1){
                dado=1+(rand()%8);
                at=ataque(j2.forca,j2.velocidade);
                es=esquivar(j1.velocidade, dado);
                dano=at-es;
                if(dano<0)
                    dano=0;
                printf("O ataque foi de %d e o esquivar evitou %d de dano, o dano final foi de %d.", at,es,dano);
                j1.vida-=dano;
                printf("\nA vida atual de %s é de: %d",j1.nome, j1.vida);
                if(j1.vida<=0)
                    break;
            }else{
                dado=1+(rand()%8);
                at=ataque(j2.forca,j2.velocidade);
                def=defesa(j1.defesa, dado);
                dano=at-def;
                if(dano<0)
                    dano=0;
                printf("O ataque foi de %d e a defesa evitou %d de dano, o dano final foi de %d.", at,def,dano);
                j1.vida-=dano;
                printf("\nA vida atual de %s é de: %d",j1.nome, j1.vida);
                if(j1.vida<=0)
                    break;
            }
            printf("\n\nJogador %s vai atacar\n",j1.nome);
            printf("Jogador %s escolha 1 para esquivar ou 2 para defender: ",j2.nome);
            scanf("%d", &esc);
            if(esc==1){
                dado=1+(rand()%8);
                at=ataque(j1.forca,j1.velocidade);
                es=esquivar(j2.velocidade, dado);
                dano=at-es;
                if(dano<0)
                    dano=0;
                printf("O ataque foi de %d e o esquivar evitou %d de dano, o dano final foi de %d.", at,es,dano);
                j2.vida-=dano;
                printf("\nA vida atual de %s é de: %d",j2.nome, j2.vida);
                if(j2.vida<=0)
                    break;
            }else{
                dado=1+(rand()%8);
                at=ataque(j1.forca,j1.velocidade);
                def=defesa(j2.defesa, dado);
                dano=at-def;
                if(dano<0)
                    dano=0;
                printf("O ataque foi de %d e a defesa evitou %d de dano, o dano final foi de %d.", at,def,dano);
                j2.vida-=dano;
                printf("\nA vida atual de %s é de: %d",j2.nome, j2.vida);
                if(j2.vida<=0)
                    break;
            }
        }while(j1.vida>0 || j2.vida>0);
        return 0;
}

int jogador1(PL j1, PL j2){
    int dano1,dano2;
    int dano;
    int at, es, com, def;
    int esc,dado;
    char p,pt;

    printf("%s vai ser o primeiro", j1.nome);
    do{
        printf("\n\nJogador %s ataca\n", j1.nome);
        printf("Jogador %s escolha 1 para esquivar ou 2 para defender: ",j2.nome);
        scanf("%d", &esc);
            if(esc==1){
                dado=1+(rand()%8);
                at=ataque(j1.forca,j1.velocidade);
                es=esquivar(j2.velocidade, dado);
                dano=at-es;
                if(dano<0)
                    dano=0;
                printf("O ataque foi de %d e o esquivar evitou %d de dano, o dano final foi de %d.", at,es,dano);
                j2.vida-=dano;
                printf("\nA vida atual de %s é de: %d",j2.nome, j2.vida);
                if(j2.vida<=0)
                    break;
            }else{
                dado=1+(rand()%8);
                at=ataque(j1.forca,j1.velocidade);
                def=defesa(j2.defesa, dado);
                dano=at-def;
                if(dano<0)
                    dano=0;
                printf("O ataque foi de %d e a defesa evitou %d de dano, o dano final foi de %d.", at,def,dano);
                j2.vida-=dano;
                printf("\nA vida atual de %s é de: %d",j2.nome, j2.vida);
                if(j2.vida<=0)
                    break;
            }
            printf("\n\nJogador %s vai atacar",j2.nome);
            printf("\nJogador %s escolha 1 para esquivar ou 2 para defender: ",j1.nome);
            scanf("%d", &esc);
            if(esc==1){
                dado=1+(rand()%8);
                at=ataque(j2.forca,j2.velocidade);
                es=esquivar(j1.velocidade, dado);
                dano=at-es;
                if(dano<0)
                    dano=0;
                printf("O ataque foi de %d e o esquivar evitou %d de dano, o dano final foi de %d.", at,es,dano);
                j1.vida-=dano;
                printf("\nA vida atual de %s é de: %d",j1.nome, j1.vida);
                if(j1.vida<=0)
                    break;
            }else{
                dado=1+(rand()%8);
                at=ataque(j2.forca,j2.velocidade);
                def=defesa(j1.defesa, dado);
                dano=at-def;
                if(dano<0)
                    dano=0;
                printf("O ataque foi de %d e a defesa evitou %d de dano, o dano final foi de %d.", at,def,dano);
                j1.vida-=dano;
                printf("\nA vida atual de %s é de: %d",j1.nome, j1.vida);
                if(j1.vida<=0)
                    break;
            }
    }while(j1.vida>0 || j2.vida>0);
        return 0;
}

void jogadores(){
    puts("\nJogador 1");
    printf("Digite o nome do seu personagem:");
    scanf(" %19[^\n]s", &j1.nome);
    j1=criar(j1);
    puts("\nJogador 2");
    printf("Digite o nome do seu personagem:");
    scanf(" %19[^\n]s", &j2.nome);
    j2=criar(j2);
}

int main(){
    setlocale(LC_ALL,"");
    srand(time(NULL));

    jogadores();
    habilidades();
    
    printf("\nO octaedro vai ser jogado.\n");
    int v=1+(rand()%8);
    if(v%2==1){     //jogador um inicia
        jogador1(j1,j2);
    }else{          //jogador dois inicia
        jogador2(j1, j2);
    }
    puts("");
    puts("");
    system("pause");

return 0;
}
