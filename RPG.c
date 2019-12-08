#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

typedef struct personagem{
    char nome[20];
    int vida;
    int defesa;
    int forca;
    int velocidade;
}PL;    //PL - Player

PL j,j1,j2,bot;

void habilidades(PL j1,PL j2, int h){
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
PL criar(PL j){
    int a=0;
    do{     //personagem 1
        puts("Você possui 60 pontos defina a categoria deles.");
        printf("Pontos de defesa:");
        scanf("%d", &j.defesa);
        printf("Pontos de força:");
        scanf("%d", &j.forca);
        printf("Pontos de velocidade:");
        scanf("%d", &j.velocidade);
        j.vida=1000;
        a=j.velocidade+j.forca+j.defesa;
        if(a>60)
            puts("Você ultrapassou o limite permitido, repita novamente");
    }while(a>60);
return j;
}

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

int main(){
    setlocale(LC_ALL,"");
    srand(time(NULL));

    int dano;
    int at, es, com, def;
    int esc,dado;
    char p,pt;
    printf("Digite I para iniciar o jogo, M para menu e E para finalizar: ");
    scanf("%s", &pt);
    do{
        if(pt=='I'){
            puts("\nJogador nº1");
            printf("Digite o nome do seu personagem:");
            scanf(" %19[^\n]s", &j1.nome);
            j1=criar(j1);
            puts("\nJogador nº2");
            printf("Digite o nome do seu personagem:");
            scanf(" %19[^\n]s", &j2.nome);
            j2=criar(j2);

            int h;
            printf("\nDeseja ver a suas habilidades, digite 1 para visualizar, 2 para não exibir: ");
            scanf("%d", &h);
            habilidades(j1,j2, h);
            do{     //executando a luta
                printf("\nO octaedro vai ser jogado.");
                int v=1+(rand()%8);
                if(v%2==1){     //jogador um inicia
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
                        printf("\n\nDigite 'A' para jogar novamente ou qualquer tecla para encerrar: ");
                        scanf("%s",&p);

                }else{       //jogaodor dois inicia
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
                        printf("\n\nDigite 'A' para jogar novamente ou qualquer tecla para encerrar essa partida: ");
                        scanf("%s",&p);
                }
            }while(p=='A');
        }else if(pt=='M'){
            puts("\nManual do jogo\n");
        }
        puts("\nDigite I para reiniciar iniciar o jogo, M para menu e E para finalizar: ");
        scanf("%s", &pt);
    }while(pt=='M'||pt=='I');

return 0;
}
