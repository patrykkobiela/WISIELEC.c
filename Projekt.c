#include "man.h"

void menu(void){
    int *id;
    printf("Menu programu\n\n");
    printf("Nowa gra (wybierz 1)\n");
    printf("Poprzedni stan gry (wybierz 2)\n");
    printf("Język gry (wybierz 3)\n");
    printf("Zamknij program (wybierz 4)\n");
    scanf("%d", *id);
}

//**********************************************************************************************
void display(const Game *gra, const char *zagadka){
    int wg=gra->wg;
    system("clear");
    title();
    printf("\x1b[31m \t\t\t ______\x1b[0m\n");
    printf("\x1b[31m \t\t\t |   |\x1b[0m\n");
    printf("\x1b[31m \t\t\t |\x1b[0m   %c\n",    wg<1?' ':'0');
    printf("\x1b[31m \t\t\t |\x1b[0m  %c%s%c\n", wg<3?' ':'/', wg<2?" ":"|", wg<4?' ':'\\');
    printf("\x1b[31m \t\t\t |\x1b[0m  %c %c\n", wg<5?' ':'/',               wg<6?' ':'\\');
    printf("\x1b[31m \t\t\t |\x1b[0m\n");
    printf("\x1b[31m\t\t\t_|_________\x1b[0m");
    printf("\t    złych odpowiedzi %d:\n \x1b[31m %s \x1b[0m \n", wg, gra->ws);
    printf("słowo: %s\n", zagadka);
}
