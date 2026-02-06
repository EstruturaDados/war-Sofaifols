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

// declaração das funções
Territorio* alocarMapa();                   //aloca dinamicamente o mapa
void inicializarTerritorios(Territorio *mapa);               // inicializa os territórios
void liberarMemoria(Territorio *mapa);  //Libera memória alocada
void exibirMenuPrincipal();             //exibe o menu principal
void exibirMapa(const Territorio *mapa);    //exibe o mapa( só pra leitura)
void exibirMissao(int idMissao);        // exibe a missão do jogador
void faseDeAtaque(Territorio *mapa);    //controla a fase de ataque
void simularAtaque(Territorio *mapa, int origem, int destino); //simula a batalha
int sortearMisssao();       //sorteia a missão
int verificarVitorias(const Territorio *mapa, int idMissao, const char *corJogador); //verifica a vitória
void limparBufferEntrada(); //limpa o buffer do teclado      


Territorio* alocarMapa(){
    return(Territorio *) calloc (TOTAL_TERRITORIOS, sizeof(Territorio)); 
}













int main() {
    
    return 0;
}

