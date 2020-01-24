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

//**********************************************************************************************

int shuffle(Buffer *buf){
    size_t rnd, tmp;
    for(size_t i=buf->words-1; i>0; --i){
        rnd=rand()%i;
        tmp=buf->index[rnd];
        buf->index[rnd]=buf->index[i];
        buf->index[i]=tmp;
    }
}

//**********************************************************************************************

int main(void){
    Buffer text=readwords("slowa.txt");
    Game gra={0,{[0 ... 6]= 0}};
    int ch;
    srand(time(NULL));
    shuffle(&text);
    size_t slowo=0;
    char *zagadka=NULL;
    title();
    menu();
    getch();
    
//**********************************     MAIN      ******************************************
    do{
        char *nieznany=text.buffer+text.index[slowo];
        size_t len=strlen(nieznany);
        zagadka=realloc(zagadka, len);
        for(int i=0; i<len; ++i) zagadka[i]='_';
        zagadka[len]=0;
        do{
            display(&gra, zagadka);

            ch=getch();
            if(strchr(nieznany, ch))
            for(size_t i=0; i<len; ++i){
                if(ch==nieznany[i]) zagadka[i]=ch;
            }
            else if(!strchr(gra.ws, ch)){ 
                gra.ws[gra.wg++]=ch;
            }
        }while(strcmp(nieznany, zagadka)&& ch!=('d' & 0x1f) && ch!=EOF && gra.wg<6);
//**********************************     MAIN      ******************************************        
        display(&gra, nieznany);
        if(strcmp(nieznany, zagadka)) printf("\nPrzegrałeś.\n");
        else printf("\x1b[42m\x1b[1m BRAWO Wygrałeś! Z %d pudłem :P.\x1b[22m\x1b[0m\n",gra.wg);
        if(ch==EOF || ch==('d' & 0x1f)) break;
        printf("Spróbować ponownie (T/N)? \n");
        ch=getch();
        gra.wg=0;
        for(size_t i=0; i<7; ++i) gra.ws[i]=0;
        ++slowo;
        slowo %= text.words;
    }while(tolower(ch)!='n');          
}



