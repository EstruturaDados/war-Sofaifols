#include <stdio.h>
#include <stdlib.h>     //alocação dinamica
#include <string.h>
#include <locale.h>     //usado para aceitar ABNT2
#include <time.h>       // usado para que o modo aleátorio não se repita, ou seja, não inicialize sempre igual.

#define TOTAL_TERRITORIOS 5  //nome da constante com o valor, #define faz troca de texto


// struct dos territorios do jogo

typedef struct{    
    char nome [50]; //nome doe territorio
    char cor [10];  //cor do exercito 
    int tropas;     //quantidade de tropas

} Territorio;

// declaração das funções mas ainda sem implementar, vou fazer isso depois da main. usando ponteiro em mapa
Territorio* alocarMapa();                   //aloca dinamicamente o mapa
void inicializarTerritorios(Territorio *mapa);               // inicializa os territórios
void liberarMemoria(Territorio *mapa);  //Libera memória alocada
void exibirMenuPrincipal();             //exibe o menu principal
void exibirMapa(const Territorio *mapa);    //exibe o mapa( só pra leitura)
void exibirMissao(int idMissao);        // exibe a missão do jogador
void faseDeAtaque(Territorio *mapa);    //controla a fase de ataque
void simularAtaque(Territorio *mapa, int origem, int destino); //simula a batalha
int sortearMisssao();       //sorteia a missão
int verificarVitoria(const Territorio *mapa, int idMissao, const char *corJogador); //verifica a vitória
void limparBufferEntrada(); //limpa o buffer do teclado      


int main() {

    setlocale(LC_ALL, "portuguese");  //define o idioma pro portuguesssss
    srand(time(NULL));                // inicializa número aleatorio com o tempo atual, ou seja, ele sempre vai definir LITERALMENTE um numero aleátorio. pq ele parte de algum numero e para não partir do mesmo, isso eh usado assi
    
    Territorio *mapa = alocarMapa();  // aloca memoria pro mapa

    if(mapa == NULL) {              //verifica falha na alocação
        print("Erro ao alocar memória.\n");
    }
    return 1; // como no C não existe boolean, vou usar assim.
    inicializarTerritorios(mapa); //cadastro do territorios

    int missao = sortearMisssao();  //sorteia a missao 
    int opcao;

    do {
        exibirMenuPrincipal();  //mostra menu
        scanf("%d", opcao);     // le a opcao do usuario e limpa o buffer
        limparBufferEntrada();

        switch (opcao) {
            case 1: 
                exibirMapa(mapa); //exibe mapa
                break;
            case 2: 
                exibirMissao(missao); //exibe missão
                break;
            case 3:
                if (verificarVitoria(mapa, missao)){        //verifica a vitoria
                    printf("\n Missão cumprida, você venceu!\n");
                    opcao = 0; //encerra o jogo
                } else {
                    printf("\n Missão ainda não concluída.\n");
                }
                break;
            case 0:
                printf("\n Encerrando o jogo...\n");
                break;
            default:
                printf("\n Opção inválida!\n");
        }
    } while (opcao != 0);
    
    liberarMemoria(mapa); //libera memoria antes de encerrar
    return 0;
}

//aqui vai ser a implementação dessas funções que declarei antes da main

Territorio* alocarMapa(){
    return(Territorio*) calloc(TOTAL_TERRITORIOS, sizeof(Territorio));
}

void inicializarTerritorios(Territorio *mapa) {
    for ( int i = 0; i <TOTAL_TERRITORIOS; i++) {

        printf("\n------- CADASTRO DO TERRITÓTIO %d -------\n", i +1);

        printf(" Nome do território: ");
        fgets(mapa[i].nome, sizeof(mapa[i].nome), stdin)                             //parametro do fgets: onde eu desejo salvar o texto q vai ser lido, o tamanho e o stdin padrao
// usar o sizeof ajuda caso o código seja alterado e o tamanho estabelecido pelo vetor seja trocado.
    }
}

