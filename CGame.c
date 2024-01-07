#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define R 20
#define C 30
 
char nemico = '\2';
char giocatore = 254;
char arrivo = '\3';
char mostro = '\1';
char punto1 = '\5', punto2 = '\5', punto3 = '\5', punto4 = '\5';
char a1 = 201, a2 = 187, o = 205, v = 186, a3= 200, a4 = 188;
int gameEnd, score;

void titolo() {
    char b = 92;
    printf("\n\t  _____        _____    _____          ____");
    printf("\n\t |            |        |     | |%c  /| |", b);
    printf("\n\t |      ____  |    ___ |_____| | %c/ | |____", b);
    printf("\n\t |            |     |  |     | |    | |");
    printf("\n\t |_____       |_____|  |     | |    | |____");
    printf("\n\n");
    //system("PAUSE");
}

void intro() {
    printf("\n\t============= \3 \1 C - GAME \2 \5 =============\n");
    printf("\n\t       Realizzato da: Alessio De Nicola \n");
    printf("\n\t        Linguaggio di programmazione: C \n");
    printf("\n\t                Versione 1.4        \n");
    printf("\n\t            Sviluppato per Windows  \n");
    printf("\n\t============================================\n");
    printf("\n\tCOMANDI DEL GIOCO:\n");
    printf("\tPremere 'w' per muoversi in alto,\n");
    printf("\tPremere 's' per muoversi in basso,\n");
    printf("\tPremere 'd' per muoversi a destra,\n");
    printf("\tPremere 'a' per muoversi a sinistra.\n");
    printf("\n\tPrima di iniziare seleziona il livello di difficolta'. Premi w per spostare la freccia in alto, premi s per");
    printf("\n\tspostare la freccia in basso e premi k per confermare la tua scelta!.");
    printf("\n\tBuon divertimento!!!");
    //system("PAUSE");
    //system("cls");
}

void difficolta(char selezione[][15]) {
    printf("\n\n");
    int i, j;
    for(i = 0; i < 3; ++i) {
        for(j = 0; j < 15; ++j) {
            printf("%c", selezione[i][j]);
        }
        printf("\n");
    }
}

void draw(char mappa[][C], int* r, int* c, int* rm, int* cm, int* gameEnd) {
    int i, j;
    for(i = 0; i < R; ++i) {
        printf("\t"); // Per spostare la mappa piu' al centro
        for(j = 0; j < C; ++j) {
            printf("%c", mappa[i][j]);
        }
        printf("\n");
    }
    if((*gameEnd == 1) && (*r) == 1 && (*c) == 29) {
        printf("\n\n\tCOMPLIMENTI HAI FINITO IL GIOCO!!!\n\n");
        system("PAUSE");
        printf("\n\tGrazie per aver giocato, spero ti sia divertito!\n\n");
        system("PAUSE");
    }
    else if((*gameEnd == 1) && (*r) != 1 && (*c) != 29) {
        printf("\n\n\tSEI STATO MANGIATO DA UN NEMICO!!!\n\n");
        system("PAUSE");
        printf("\n\tRiprova e fai piu' attenzione!\n\n");
        system("PAUSE");
    }
    else if((*gameEnd == 1) && (*r) == 1 && (*c) == 27 && (*rm) == 1 && (*cm) == 27) {
        printf("\n\n\tSEI STATO MANGIATO DAL MOSTRO!!!\n\n");
        system("PAUSE");
        printf("\n\tDevi prima prendere tutti i punti nella mappa per sbloccare il passaggio!\n\n");
        system("PAUSE");
    }
    system("cls");
}

void movimentoNemico1(char mappa[][C], int* r1, int* c1) {
    if((*r1) == 16 && (*c1) == 6) {
        mappa[*r1][*c1] = ' ';
        mappa[(*r1)+1][*c1] = nemico;
        (*r1)++;
    }
    else if((*r1) == 17 && (*c1) == 6) {
        mappa[*r1][*c1] = ' ';
        mappa[(*r1)+1][*c1] = nemico;
        (*r1)++;
    }
    else if((*r1) == 18 && (*c1) == 6) {
        mappa[*r1][*c1] = ' ';
        mappa[(*r1)][(*c1)+1] = nemico;
        (*c1)++;
    }
    else if((*r1) == 18 && (*c1) == 7) {
        mappa[*r1][*c1] = ' ';
        mappa[*r1][(*c1)+1] = nemico;
        (*c1)++;
    }
    else if((*r1) == 18 && (*c1) == 8) {
        mappa[*r1][*c1] = ' ';
        mappa[(*r1)-1][*c1] = nemico;
        (*r1)--;
    }
    else if((*r1) == 17 && (*c1) == 8) {
        mappa[*r1][*c1] = ' ';
        mappa[(*r1)-1][*c1] = nemico;
        (*r1)--;
    }
    else if((*r1) == 16 && (*c1) == 8) {
        mappa[*r1][*c1] = ' ';
        mappa[*r1][(*c1)-1] = nemico;
        (*c1)--;
    }
    else if((*r1) == 16 && (*c1) == 7) {
        mappa[*r1][*c1] = ' ';
        mappa[*r1][(*c1)-1] = nemico;
        (*c1)--;
    }
}

void movimentoNemico2(char mappa[][C], int* r2, int* c2) {
    if((*r2) == 15 && (*c2) == 20) {
        mappa[*r2][*c2] = ' ';
        mappa[*r2][(*c2)+1] = nemico;
        (*c2)++;
    }
    else if((*r2) == 15 && (*c2) == 21) {
        mappa[*r2][*c2] = ' ';
        mappa[*r2][(*c2)+1] = nemico;
        (*c2)++;
    }
    else if((*r2) == 15 && (*c2) == 22) {
        mappa[*r2][*c2] = ' ';
        mappa[(*r2)-1][*c2] = nemico;
        (*r2)--;
    }
    else if((*r2) == 14 && (*c2) == 22) {
        mappa[*r2][*c2] = ' ';
        mappa[(*r2)-1][*c2] = nemico;
        (*r2)--;
    }
    else if((*r2) == 13 && (*c2) == 22) {
        mappa[*r2][*c2] = ' ';
        mappa[*r2][(*c2)-1] = nemico;
        (*c2)--;
    }
    else if((*r2) == 13 && (*c2) == 21) {
        mappa[*r2][*c2] = ' ';
        mappa[*r2][(*c2)-1] = nemico;
        (*c2)--;
    }
    else if((*r2) == 13 && (*c2) == 20) {
        mappa[*r2][*c2] = ' ';
        mappa[(*r2)+1][*c2] = nemico;
        (*r2)++;
    }
    else if((*r2) == 14 && (*c2) == 20) {
        mappa[*r2][*c2] = ' ';
        mappa[(*r2)+1][*c2] = nemico;
        (*r2)++;
    }
}

void movimentoNemico3(char mappa[][C], int* r3, int* c3) {
    if((*r3) == 7 && (*c3) == 18) {
        mappa[*r3][*c3] = ' ';
        mappa[*r3][(*c3)+1] = nemico;
        (*c3)++;
    }
    else if((*r3) == 7 && (*c3) == 19) {
        mappa[*r3][*c3] = ' ';
        mappa[*r3][(*c3)+1] = nemico;
        (*c3)++;
    }
    else if((*r3) == 7 && (*c3) == 20) {
        mappa[*r3][*c3] = ' ';
        mappa[(*r3)-1][*c3] = nemico;
        (*r3)--;
    }
    else if((*r3) == 6 && (*c3) == 20) {
        mappa[*r3][*c3] = ' ';
        mappa[(*r3)-1][*c3] = nemico;
        (*r3)--;
    }
    else if((*r3) == 5 && (*c3) == 20) {
        mappa[*r3][*c3] = ' ';
        mappa[*r3][(*c3)-1] = nemico;
        (*c3)--;
    }
    else if((*r3) == 5 && (*c3) == 19) {
        mappa[*r3][*c3] = ' ';
        mappa[*r3][(*c3)-1] = nemico;
        (*c3)--;
    }
    else if((*r3) == 5 && (*c3) == 18) {
        mappa[*r3][*c3] = ' ';
        mappa[(*r3)+1][*c3] = nemico;
        (*r3)++;
    }
    else if((*r3) == 6 && (*c3) == 18) {
        mappa[*r3][*c3] = ' ';
        mappa[(*r3)+1][*c3] = nemico;
        (*r3)++;
    }
}

void movimentoNemico4(char mappa[][C], int* r4, int* c4) {
    if((*r4) == 4 && (*c4) == 3) {
        mappa[*r4][*c4] = ' ';
        mappa[*r4][(*c4)-1] = nemico;
        (*c4)--;
    }
    else if((*r4) == 4 && (*c4) == 2) {
        mappa[*r4][*c4] = ' ';
        mappa[(*r4)+1][*c4] = nemico;
        (*r4)++;
    }
    else if((*r4) == 5 && (*c4) == 2) {
        mappa[*r4][*c4] = ' ';
        mappa[(*r4)+1][*c4] = nemico;
        (*r4)++;
    }
    else if((*r4) == 6 && (*c4) == 2) {
        mappa[*r4][*c4] = ' ';
        mappa[*r4][(*c4)+1] = nemico;
        (*c4)++;
    }
    else if((*r4) == 6 && (*c4) == 3) {
        mappa[*r4][*c4] = ' ';
        mappa[*r4][(*c4)+1] = nemico;
        (*c4)++;
    }
    else if((*r4) == 6 && (*c4) == 4) {
        mappa[*r4][*c4] = ' ';
        mappa[(*r4)-1][*c4] = nemico;
        (*r4)--;
    }
    else if((*r4) == 5 && (*c4) == 4) {
        mappa[*r4][*c4] = ' ';
        mappa[(*r4)-1][*c4] = nemico;
        (*r4)--;
    }
    else if((*r4) == 4 && (*c4) == 4) {
        mappa[*r4][*c4] = ' ';
        mappa[*r4][(*c4)-1] = nemico;
        (*c4)--;
    }
}

void movimentoNemico5(char mappa[][C], int* r5, int* c5) {
    if((*r5) == 7 && (*c5) == 4) {
        mappa[*r5][*c5] = ' ';
        mappa[(*r5)+1][*c5] = nemico;
        (*r5)++;
    }
    else if((*r5) == 8 && (*c5) == 4) {
        mappa[*r5][*c5] = ' ';
        mappa[(*r5)+1][*c5] = nemico;
        (*r5)++;
    }
    else if((*r5) == 9 && (*c5) == 4) {
        mappa[*r5][*c5] = ' ';
        mappa[*r5][(*c5)+1] = nemico;
        (*c5)++;
    }
    else if((*r5) == 9 && (*c5) == 5) {
        mappa[*r5][*c5] = ' ';
        mappa[*r5][(*c5)+1] = nemico;
        (*c5)++;
    }
    else if((*r5) == 9 && (*c5) == 6) {
        mappa[*r5][*c5] = ' ';
        mappa[(*r5)-1][*c5] = nemico;
        (*r5)--;
    }
    else if((*r5) == 8 && (*c5) == 6) {
        mappa[*r5][*c5] = ' ';
        mappa[(*r5)-1][*c5] = nemico;
        (*r5)--;
    }
    else if((*r5) == 7 && (*c5) == 6) {
        mappa[*r5][*c5] = ' ';
        mappa[*r5][(*c5)-1] = nemico;
        (*c5)--;
    }
    else if((*r5) == 7 && (*c5) == 5) {
        mappa[*r5][*c5] = ' ';
        mappa[*r5][(*c5)-1] = nemico;
        (*c5)--;
    }
}

void movimentoNemico6(char mappa[][C], int* r6, int* c6) {
    if((*r6) == 12 && (*c6) == 3) {
        mappa[*r6][*c6] = ' ';
        mappa[*r6][(*c6)-1] = nemico;
        (*c6)--;
    }
    else if((*r6) == 12 && (*c6) == 2) {
        mappa[*r6][*c6] = ' ';
        mappa[(*r6)+1][*c6] = nemico;
        (*r6)++;
    }
    else if((*r6) == 13 && (*c6) == 2) {
        mappa[*r6][*c6] = ' ';
        mappa[(*r6)+1][*c6] = nemico;
        (*r6)++;
    }
    else if((*r6) == 14 && (*c6) == 2) {
        mappa[*r6][*c6] = ' ';
        mappa[*r6][(*c6)+1] = nemico;
        (*c6)++;
    }
    else if((*r6) == 14 && (*c6) == 3) {
        mappa[*r6][*c6] = ' ';
        mappa[*r6][(*c6)+1] = nemico;
        (*c6)++;
    }
    else if((*r6) == 14 && (*c6) == 4) {
        mappa[*r6][*c6] = ' ';
        mappa[(*r6)-1][*c6] = nemico;
        (*r6)--;
    }
    else if((*r6) == 13 && (*c6) == 4) {
        mappa[*r6][*c6] = ' ';
        mappa[(*r6)-1][*c6] = nemico;
        (*r6)--;
    }
    else if((*r6) == 12 && (*c6) == 4) {
        mappa[*r6][*c6] = ' ';
        mappa[*r6][(*c6)-1] = nemico;
        (*c6)--;
    }
}

void movimentoNemico7(char mappa[][C], int* r7, int* c7) {
    if((*r7) == 16 && (*c7) == 16) {
        mappa[*r7][*c7] = ' ';
        mappa[*r7][(*c7)-1] = nemico;
        (*c7)--;
    }
    else if((*r7) == 16 && (*c7) == 15) {
        mappa[*r7][*c7] = ' ';
        mappa[(*r7)+1][*c7] = nemico;
        (*r7)++;
    }
    else if((*r7) == 17 && (*c7) == 15) {
        mappa[*r7][*c7] = ' ';
        mappa[(*r7)+1][*c7] = nemico;
        (*r7)++;
    }
    else if((*r7) == 18 && (*c7) == 15) {
        mappa[*r7][*c7] = ' ';
        mappa[*r7][(*c7)+1] = nemico;
        (*c7)++;
    }
    else if((*r7) == 18 && (*c7) == 16) {
        mappa[*r7][*c7] = ' ';
        mappa[*r7][(*c7)+1] = nemico;
        (*c7)++;
    }
    else if((*r7) == 18 && (*c7) == 17) {
        mappa[*r7][*c7] = ' ';
        mappa[(*r7)-1][*c7] = nemico;
        (*r7)--;
    }
    else if((*r7) == 17 && (*c7) == 17) {
        mappa[*r7][*c7] = ' ';
        mappa[(*r7)-1][*c7] = nemico;
        (*r7)--;
    }
    else if((*r7) == 16 && (*c7) == 17) {
        mappa[*r7][*c7] = ' ';
        mappa[*r7][(*c7)-1] = nemico;
        (*c7)--;
    }
}

void movimentoNemico8(char mappa[][C], int* r8, int* c8) {
    if((*r8) == 8 && (*c8) == 25) {
        mappa[*r8][*c8] = ' ';
        mappa[*r8][(*c8)-1] = nemico;
        (*c8)--;
    }
    else if((*r8) == 8 && (*c8) == 24) {
        mappa[*r8][*c8] = ' ';
        mappa[(*r8)+1][*c8] = nemico;
        (*r8)++;
    }
    else if((*r8) == 9 && (*c8) == 24) {
        mappa[*r8][*c8] = ' ';
        mappa[(*r8)+1][*c8] = nemico;
        (*r8)++;
    }
    else if((*r8) == 10 && (*c8) == 24) {
        mappa[*r8][*c8] = ' ';
        mappa[*r8][(*c8)+1] = nemico;
        (*c8)++;
    }
    else if((*r8) == 10 && (*c8) == 25) {
        mappa[*r8][*c8] = ' ';
        mappa[*r8][(*c8)+1] = nemico;
        (*c8)++;
    }
    else if((*r8) == 10 && (*c8) == 26) {
        mappa[*r8][*c8] = ' ';
        mappa[(*r8)-1][*c8] = nemico;
        (*r8)--;
    }
    else if((*r8) == 9 && (*c8) == 26) {
        mappa[*r8][*c8] = ' ';
        mappa[(*r8)-1][*c8] = nemico;
        (*r8)--;
    }
    else if((*r8) == 8 && (*c8) == 26) {
        mappa[*r8][*c8] = ' ';
        mappa[*r8][(*c8)-1] = nemico;
        (*c8)--;
    }
}

void input(char mappa[][C], int* r, int* c) {
    if(kbhit()) {
        char dir = getch();
        switch(dir) {
            case 'w': // in alto
                if(mappa[(*r)-1][*c] != o && mappa[(*r)-1][*c] != v && mappa[(*r)-1][*c] != a1 && mappa[(*r)-1][*c] != a2 && mappa[(*r)-1][*c] != a3 && mappa[(*r)-1][*c] != a4) {
                    mappa[*r][*c] = ' ';
                    mappa[(*r)-1][*c] = giocatore;
                    (*r)--;
                }
                break;
            case 's': // in basso
                if(mappa[(*r)+1][*c] != o && mappa[(*r)+1][*c] != v && mappa[(*r)+1][*c] != a1 && mappa[(*r)+1][*c] != a2 && mappa[(*r)+1][*c] != a3 && mappa[(*r)+1][*c] != a4) {
                    mappa[*r][*c] = ' ';
                    mappa[(*r)+1][*c] = giocatore;
                    (*r)++;
                }
                break;
            case 'a': // a sinistra
                if(mappa[*r][(*c)-1] != o && mappa[*r][(*c)-1] != v && mappa[*r][(*c)-1] != a1 && mappa[*r][(*c)-1] != a2 && mappa[*r][(*c)-1] != a3 && mappa[*r][(*c)-1] != a4) {
                    mappa[*r][*c] = ' ';
                    mappa[*r][(*c)-1] = giocatore;
                    (*c)--;
                }
                break;
            case 'd': // a destra
                if(mappa[*r][(*c)+1] != o && mappa[*r][(*c)+1] != v && mappa[*r][(*c)+1] != a1 && mappa[*r][(*c)+1] != a2 && mappa[*r][(*c)+1] != a3 && mappa[*r][(*c)+1] != a4) {
                    mappa[*r][*c] = ' ';
                    mappa[*r][(*c)+1] = giocatore;
                    (*c)++;
                }
                break;
        }
    }
}

void controllo(int* r, int* c, int* r1, int* c1, int* r2, int* c2, int* r3, int* c3, int* r4, int* c4, int* r5, int* c5, int* r6, int* c6, int* r7, int* c7, int* r8, int* c8, int* rm, int* cm, int* gameEnd) {
    if(((*r) == (*r1) && (*c) == (*c1)) || ((*r) == 1 && (*c) == 29) || ((*r) == (*rm) && (*c) == (*cm))) {
        (*gameEnd) = 1;
    }
    if(((*r) == (*r2) && (*c) == (*c2)) || ((*r) == 1 && (*c) == 29) || ((*r) == (*rm) && (*c) == (*cm))) {
        (*gameEnd) = 1;
    }
    if(((*r) == (*r3) && (*c) == (*c3)) || ((*r) == 1 && (*c) == 29) || ((*r) == (*rm) && (*c) == (*cm))) {
        (*gameEnd) = 1;
    }
    if(((*r) == (*r4) && (*c) == (*c4)) || ((*r) == 1 && (*c) == 29) || ((*r) == (*rm) && (*c) == (*cm))) {
        (*gameEnd) = 1;
    }
    if(((*r) == (*r5) && (*c) == (*c5)) || ((*r) == 1 && (*c) == 29) || ((*r) == (*rm) && (*c) == (*cm))) {
        (*gameEnd) = 1;
    }
    if(((*r) == (*r6) && (*c) == (*c6)) || ((*r) == 1 && (*c) == 29) || ((*r) == (*rm) && (*c) == (*cm))) {
        (*gameEnd) = 1;
    }
    if(((*r) == (*r7) && (*c) == (*c7)) || ((*r) == 1 && (*c) == 29) || ((*r) == (*rm) && (*c) == (*cm))) {
        (*gameEnd) = 1;
    }
    if(((*r) == (*r8) && (*c) == (*c8)) || ((*r) == 1 && (*c) == 29) || ((*r) == (*rm) && (*c) == (*cm))) {
        (*gameEnd) = 1;
    }
}

void punteggio(char mappa[][C], int* r, int* c, int* rp1, int* cp1, int* rp2, int* cp2, int* rp3, int* cp3, int* rp4, int* cp4, int* rm, int* cm, int* score) {
    if((*r) == (*rp1) && (*c) == (*cp1)) {
        (*score) = (*score) + 10;
        (*rp1) = 0;
        (*cp1) = 0;
    }
    if((*r) == (*rp2) && (*c) == (*cp2)) {
        (*score) = (*score) + 10;
        (*rp2) = 0;
        (*cp2) = 0;
    }
    if((*r) == (*rp3) && (*c) == (*cp3)) {
        (*score) = (*score) + 10;
        (*rp3) = 0;
        (*cp3) = 0;
    }
    if((*r) == (*rp4) && (*c) == (*cp4)) {
        (*score) = (*score) + 10;
        (*rp4) = 0;
        (*cp4) = 0;
    }
    if((*score) == 40) {
        mappa[*rm][*cm] = ' ';  // Scomparsa mostro
        (*rm) = 18;
        (*cm) = 28;
    }
}

int main()
{
    system("color B");
    // SELEZIONE LIVELLO DI DIFFICOLTA'
    char selezione[3][15] = {{' ', ' ', '-', '-', '>', ' ', 'F', 'A', 'C', 'I', 'L', 'E', ' ', ' ', ' '},
                             {' ', ' ', ' ', ' ', ' ', ' ', 'M', 'E', 'D', 'I', 'O', ' ', ' ', ' ', ' '},
                             {' ', ' ', ' ', ' ', ' ', ' ', 'D', 'I', 'F', 'F', 'I', 'C', 'I', 'L', 'E'}};
    char dif;
    int riga = 0, cl1 = 2, cl2 = 3, cl3 = 4;
    while(dif != 'k') {
        titolo();
        intro();
        difficolta(selezione);
        dif = getch();
        switch(dif) {
            case 's': // Muovo la freccia in basso
                if(riga != 2) {
                    selezione[riga][cl1] = ' ';
                    selezione[riga][cl2] = ' ';
                    selezione[riga][cl3] = ' ';
                    selezione[riga+1][cl1] = '-';
                    selezione[riga+1][cl2] = '-';
                    selezione[riga+1][cl3] = '>';
                    riga++;
                }
                system("cls");
                break;
            case 'w': // Muovo la freccia in alto
                if(riga != 0) {
                    selezione[riga][cl1] = ' ';
                    selezione[riga][cl2] = ' ';
                    selezione[riga][cl3] = ' ';
                    selezione[riga-1][cl1] = '-';
                    selezione[riga-1][cl2] = '-';
                    selezione[riga-1][cl3] = '>';
                    riga--;
                }
                system("cls");
                break;
            default:
                system("cls");
                break;
        }
    }
    // CAMPO DI GIOCO
    char mappa[R][C] = {{a1, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, a2}, 
                        {v, ' ', ' ', v, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\3'}, 
                        {v, ' ', ' ', v, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', a1, o, o, o, o, o, o, o, o, o, o, v}, 
                        {v, ' ', ' ', v, ' ', ' ', ' ', o, o, o, o, o, o, o, o, o, o, o, a4, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', v}, 
                        {v, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', v}, 
                        {v, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', v}, 
                        {v, ' ', ' ', ' ', ' ', ' ', ' ', a1, o, o, o, o, o, o, o, o, o, o, ' ', ' ', ' ', o, o, o, o, o, o, o, o, v}, 
                        {v, ' ', ' ', v, ' ', ' ', ' ', v, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', v}, 
                        {v, o, o, a4, ' ', ' ', ' ', a3, o, o, o, o, o, a2, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', v}, 
                        {v, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', v, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', v}, 
                        {v, o, o, o, o, o, o, o, o, o, o, a2, ' ', v, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', v}, 
                        {v, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', v, ' ', a3, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, v}, 
                        {v, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', v, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', v}, 
                        {v, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', v, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', v}, 
                        {v, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', v, ' ', a1, o, o, o, o, o, o, ' ', ' ', ' ', o, o, a2, ' ', ' ', ' ', v}, 
                        {v, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', v, ' ', v, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', v, ' ', ' ', ' ', v}, 
                        {v, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', v, ' ', v, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', v, ' ', ' ', ' ', v}, 
                        {v, o, o, o, o, o, ' ', ' ', ' ', o, o, a4, ' ', v, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', v, ' ', ' ', ' ', v}, 
                        {v, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', v, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', v, ' ', ' ', ' ', v}, 
                        {a3, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, a4}};

    // POSIZIONI INIZIALI
    int r = 18, c = 1;
    mappa[r][c] = giocatore;
    int r1 = 16, c1 = 6;
    int r2 = 15, c2 = 20;
    int r3 = 7, c3 = 18;
    int r4 = 4, c4 = 3;
    int r5 = 7, c5 = 4;
    int r6 = 12, c6 = 3;
    int r7 = 16, c7 = 16;
    int r8 = 8, c8 = 25;
    mappa[r1][c1] = nemico;
    mappa[r2][c2] = nemico;
    mappa[r3][c3] = nemico;
    mappa[r4][c4] = nemico;
    mappa[r5][c5] = nemico;
    mappa[r6][c6] = nemico;
    mappa[r7][c7] = nemico;
    mappa[r8][c8] = nemico;
    int rm = 1, cm = 27;
    mappa[rm][cm] = mostro;
    int rp1 = 13, cp1 = 3;
    mappa[rp1][cp1] = punto1;
    int rp2 = 17, cp2 = 16;
    mappa[rp2][cp2] = punto2;
    int rp3 = 9, cp3 = 25;
    mappa[rp3][cp3] = punto3;
    int rp4 = 2, cp4 = 1;
    mappa[rp4][cp4] = punto4;

    // INIZIO DEL GIOCO
    gameEnd = 0;
    score = 0;
    if(riga == 0) { // LIVELLO FACILE
        mappa[r5][c5] = ' ';
        mappa[r6][c6] = ' ';
        mappa[r7][c7] = ' ';
        mappa[r8][c8] = ' ';
        r5 = 0;
        c5 = 0;
        r6 = 0;
        c6 = 0;
        r7 = 0;
        c7 = 0;
        r8 = 0;
        c8 = 0;
        while(gameEnd == 0) {
            printf("\n\t\tGiocatore: %c\n", giocatore);
            printf("\t\tNemico: %c\n", nemico);
            printf("\t\tMostro: %c\n", mostro);
            printf("\t\tArrivo: %c\n", arrivo);
            printf("\t\tPUNTEGGIO: %d\n\n", score);
            input(mappa, &r, &c);
            movimentoNemico1(mappa, &r1, &c1);
            movimentoNemico2(mappa, &r2, &c2);
            movimentoNemico3(mappa, &r3, &c3);
            movimentoNemico4(mappa, &r4, &c4);
            controllo(&r, &c, &r1, &c1, &r2, &c2, &r3, &c3, &r4, &c4, &r5, &c5, &r6, &c6, &r7, &c7, &r8, &c8, &rm, &cm, &gameEnd);
            punteggio(mappa, &r, &c, &rp1, &cp1, &rp2, &cp2, &rp3, &cp3, &rp4, &cp4, &rm, &cm, &score);
            draw(mappa, &r, &c, &rm, &cm, &gameEnd);
        }
    }
    else if(riga == 1) { // LIVELLO MEDIO
        mappa[r7][c7] = ' ';
        mappa[r8][c8] = ' ';
        r7 = 0;
        c7 = 0;
        r8 = 0;
        c8 = 0;
        while(gameEnd == 0) {
            printf("\n\t\tGiocatore: %c\n", giocatore);
            printf("\t\tNemico: %c\n", nemico);
            printf("\t\tMostro: %c\n", mostro);
            printf("\t\tArrivo: %c\n", arrivo);
            printf("\t\tPUNTEGGIO: %d\n\n", score);
            input(mappa, &r, &c);
            movimentoNemico1(mappa, &r1, &c1);
            movimentoNemico2(mappa, &r2, &c2);
            movimentoNemico3(mappa, &r3, &c3);
            movimentoNemico4(mappa, &r4, &c4);
            movimentoNemico5(mappa, &r5, &c5);
            movimentoNemico6(mappa, &r6, &c6);
            controllo(&r, &c, &r1, &c1, &r2, &c2, &r3, &c3, &r4, &c4, &r5, &c5, &r6, &c6, &r7, &c7, &r8, &c8, &rm, &cm, &gameEnd);
            punteggio(mappa, &r, &c, &rp1, &cp1, &rp2, &cp2, &rp3, &cp3, &rp4, &cp4, &rm, &cm, &score);
            draw(mappa, &r, &c, &rm, &cm, &gameEnd);
        }
    }
    else if(riga == 2) { // LIVELLO DIFFICILE
        while(gameEnd == 0) {
            printf("\n\t\tGiocatore: %c\n", giocatore);
            printf("\t\tNemico: %c\n", nemico);
            printf("\t\tMostro: %c\n", mostro);
            printf("\t\tArrivo: %c\n", arrivo);
            printf("\t\tPUNTEGGIO: %d\n\n", score);
            input(mappa, &r, &c);
            movimentoNemico1(mappa, &r1, &c1);
            movimentoNemico2(mappa, &r2, &c2);
            movimentoNemico3(mappa, &r3, &c3);
            movimentoNemico4(mappa, &r4, &c4);
            movimentoNemico5(mappa, &r5, &c5);
            movimentoNemico6(mappa, &r6, &c6);
            movimentoNemico7(mappa, &r7, &c7);
            movimentoNemico8(mappa, &r8, &c8);
            controllo(&r, &c, &r1, &c1, &r2, &c2, &r3, &c3, &r4, &c4, &r5, &c5, &r6, &c6, &r7, &c7, &r8, &c8, &rm, &cm, &gameEnd);
            punteggio(mappa, &r, &c, &rp1, &cp1, &rp2, &cp2, &rp3, &cp3, &rp4, &cp4, &rm, &cm, &score);
            draw(mappa, &r, &c, &rm, &cm, &gameEnd);
        }
    }
    system("PAUSE");
	return 0;
}
