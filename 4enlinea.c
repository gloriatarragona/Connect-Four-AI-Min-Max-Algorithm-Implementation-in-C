#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Minimax.h"
#include "4enlinea.h"
#define ROJO_T     "\x1b[31m"
#define CYAN_T     "\x1b[36m"
#define AZUL_T     "\x1b[34m"
#define RESET_COLOR    "\x1b[0m"


int comprovarFila(char tauler[N][N],char jugador){ //Verifica si hi ha un 4 en linea horitzontal

     for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
                if(tauler[i][j]==jugador){
    if(j<N-3){
        if(tauler[i][j]==tauler[i][j+1]&&tauler[i][j]==tauler[i][j+2]&&tauler[i][j]==tauler[i][j+3]){
            return 1;
        }
        }
        }
     }
    }
        return 0;

}
int comprovarColumna(char tauler[N][N],char jugador){ //Verfica si hi ha un 4 en linea vertical

     for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
                if(tauler[i][j]==jugador){
    if(i<N-3){
        if(tauler[i][j]==tauler[i+1][j]&&tauler[i][j]==tauler[i+2][j]&&tauler[i][j]==tauler[i+3][j]){
            return 1;
        }
        }
        }
     }
    }
    return 0;
}
int comprovarDiagonal(char tauler[N][N],char jugador){ //Verifica si hi ha un 4 en linea en una diagonal d'esquerra a dreta

     for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
                if(tauler[i][j]==jugador){
    if(i<N-3&&j<N-3){
        if(tauler[i][j]==tauler[i+1][j+1]&&tauler[i][j]==tauler[i+2][j+2]&&tauler[i][j]==tauler[i+3][j+3]){
            return 1;
        }
        }
        }
     }
    }
    return 0;
}
int comprovarDiagonal2(char tauler[N][N],char jugador){ //verifica si hi ha un 4 en linea en una diagonal de dreta a esquerra

     for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
                if(tauler[i][j]==jugador){
    if(i<N-3&&j>2){
        if(tauler[i][j]==tauler[i+1][j-1]&&tauler[i][j]==tauler[i+2][j-2]&&tauler[i][j]==tauler[i+3][j-3]){
            return 1;
        }
        }
        }
        }
    }
    return 0;
}
int comprovarLinies(char tauler[N][N],char jugador){ //Comprova si hi ha un 4 en linea en general

    if(comprovarFila(tauler,jugador)==1||comprovarColumna(tauler,jugador)==1||comprovarDiagonal(tauler,jugador)==1 || comprovarDiagonal2(tauler,jugador)==1){
        return 1;
    }
return 0;

}
 int humaAordinador(int col){ //Pasem de una columna (1-8) a una columna (0-7)
 return col-1;
 }
 int ordinadorAhuma(int col){ //Inversa de la funció anterior
 return col+1;
 }
void imprimirTauler(char tauler[N][N]) { //Imprimeix el tauler d'un node
    printf("\n");
    printf(" Jugador:"AZUL_T " O\n" RESET_COLOR);
    printf(" Consola:"ROJO_T " X\n\n" RESET_COLOR);
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){

                if(tauler[i][j]=='1'){
            printf(AZUL_T " O " RESET_COLOR, tauler[i][j]);
                }
                if(tauler[i][j]=='2'){
            printf(ROJO_T " X " RESET_COLOR, tauler[i][j]);
                }
                if(tauler[i][j]=='0'){
                printf(" 0 " , tauler[i][j]);
                }


        }
        printf("\n");
    }
    printf(" ");
    for(int i=0;i<=21;i++){
        printf("-");
    }
    printf("\n");
    for(int j=1;j<=N;j++)
    printf(" %i ",j);


    printf("\n\n");

}
int columnaPlena(char tauler[N][N],int col){ //Verifica si la columna esta plena
    if(tauler[0][col]!='0'){
        return 1;
    }
    else return 0;
}
int columnaNoPlena(char tauler[N][N],int col){ //Verifica si la columna esta no plena
    if(tauler[0][col]=='0'){
        return 1;
    }
    else return 0;
}
void ferTirada(char tauler[N][N],int col, int jugador){ //Fa la tirada d'un jugador o del ordinador
    if(col>7 || col<0){ //Cas 1: Introduim una columna no valida (Error)
            while(col>7 || col<0){
        printf("Error: Selecciona una columna del 1 al 8 \n");
        scanf("%d",&col);
        col=humaAordinador(col);
            }
    }
    if(columnaPlena(tauler,col)){ //Cas 2: Introduim una columna que està plena (Error)
        while(columnaPlena(tauler,col)==1){
        printf("Error: la columna seleccionada esta plena, selecciona una altre columna\n");
        scanf("%d",&col);
        col=humaAordinador(col);
        }
    }
    if(!columnaPlena(tauler,col)){ //Cas 3: Introduim una columna valida i fem la tirada
    for(int i=N-1;i>=0;i--){
    if(tauler[i][col]=='0'){
        tauler[i][col]='0'+jugador;
        break;
    }
    }
}
}
void inicialitzarTauler(char tauler[N][N]){ //Crea el tauler buit
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            tauler[i][j]='0';
        }
    }
}
int finalJoc(char tauler[N][N]){ //Verifica quin jugador ha guanyat
    if (comprovarLinies(tauler, '1')==1){
            return 1;
    }
    if (comprovarLinies(tauler, '2')==1){
            return 2;
    }
    return 0;

}
void trobarTauler(Node*p){ //Busca quina és la millor tirada despres de fer el Minimax

    Node **aux=malloc(p->n_fills*sizeof(Node));
    int opcions=0;
    for(int i=0;i<p->n_fills;i++){

        if(p->fills[i]->valor==p->valor){
                if(comprovarLinies(p->fills[i]->tauler,'2')==1){
                copiaTauler(p->tauler,p->fills[i]->tauler);
                return ;
            }
            if(comprovarLinies(p->fills[i]->tauler,'1')==0){
            aux[opcions++]=p->fills[i];
            }
        }

    }
    copiaTauler(p->tauler,aux[rand()%(opcions)]->tauler); //Si dos taulers tenen la mateixa puntuació tria un aleatoriament
    return ;
}
void copiaTauler(char taulerD[N][N],char taulerOr[N][N]){ //Copia el tualer d'un node en el tauler d'un altre node
     for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            taulerD[i][j]=taulerOr[i][j];
        }
    }
}
int funcioHeuristica(char tauler[N][N]){ //Calcula els valors dels nodes
    int valor=0;

    if(comprovarLinies(tauler,'1')==1){ //Cas on ha guanyat la persona
            valor=-10e6;
            return valor;
    }
    if(comprovarLinies(tauler,'2')==1){ //Cas on ha guanyat l'ordinador
            valor=10e6;
            return valor;
    }

    for(int i=0;i<N;i++){ //Mira els diferents subconjunts de 4 on només un dels jugadors te fitxes
        for(int j=0;j<N;j++){

        if(j<N-3){
            if(tauler[i][j]!='2' && tauler[i][j+1]!='2' && tauler[i][j+2]!='2' && tauler[i][j+3]!='2'){
            for(int k=0;k<4;k++){
            if(tauler[i][j+k]=='1'){
                    valor=valor-profunditat; //Resta una quantitat per cada fitxa que té la persona
            }
            }
            }
            if(tauler[i][j]!='1' && tauler[i][j+1]!='1' && tauler[i][j+2]!='1' && tauler[i][j+3]!='1'){
            for(int k=0;k<4;k++){
            if(tauler[i][j+k]=='2'){
                    valor=valor+(profunditat/2); //Suma una quantita per cada fitxa que té l'ordinador
            }
            }
            }
            }


        if(i<N-3){
               if(tauler[i][j]!='2' && tauler[i+1][j]!='2' && tauler[i+2][j]!='2' && tauler[i+3][j]!='2'){
            for(int k=0;k<4;k++){
            if(tauler[i+k][j]=='1'){
                    valor=valor-profunditat;
            }
            }
            }
            if(tauler[i][j]!='1' && tauler[i+1][j]!='1' && tauler[i+2][j]!='1' && tauler[i+3][j]!='1'){
            for(int k=0;k<4;k++){
            if(tauler[i+k][j]=='2'){
                    valor=valor+(profunditat/2);
            }
            }
            }

        }

        if(i<N-3 && j<N-3){

            if(tauler[i][j]!='2' && tauler[i+1][j+1]!='2' && tauler[i+2][j+2]!='2' && tauler[i+3][j+3]!='2'){
            for(int k=0;k<4;k++){
            if(tauler[i+k][j+k]=='1'){
                    valor=valor-profunditat;
            }
            }
            }
            if(tauler[i][j]!='1' && tauler[i+1][j+1]!='1' && tauler[i+2][j+2]!='1' && tauler[i+3][j+3]!='1'){
            for(int k=0;k<4;k++){
            if(tauler[i+k][j+k]=='2'){
                    valor=valor+(profunditat/2);
            }
            }
            }
        }

        if(i<N-3 && j>2){

               if(tauler[i][j]!='2' && tauler[i+1][j-1]!='2' && tauler[i+2][j-2]!='2' && tauler[i+3][j-3]!='2'){
            for(int k=0;k<4;k++){
            if(tauler[i+k][j-k]=='1'){
                    valor=valor-profunditat;
            }
            }
            }
            if(tauler[i][j]!='1' && tauler[i+1][j-1]!='1' && tauler[i+2][j-2]!='1' && tauler[i+3][j-3]!='1'){
            for(int k=0;k<4;k++){
            if(tauler[i+k][j-k]=='2'){
                    valor=valor+(profunditat/2);
            }
            }
            }
        }
        }
    }
    return valor;
}
int funcioHeuristica2(char tauler[N][N]){ //Calcula els valors dels nodes
    int valor=0;
    if(comprovarLinies(tauler,'1')==1){ //Cas on ha guanyat la persona
            valor=-10e6;
            return valor;
    }
    if(comprovarLinies(tauler,'2')==1){ //Cas on ha guanyat l'ordinador
            valor=10e6;
            return valor;
    }


    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){

        if(j<N-3){
            if(tauler[i][j]!='2' && tauler[i][j+1]!='2' && tauler[i][j+2]!='2' && tauler[i][j+3]!='2'){
            for(int k=0;k<4;k++){
            if(tauler[i][j+k]=='1'){
                    valor=valor--;


            }
            }
            }
            if(tauler[i][j]!='1' && tauler[i][j+1]!='1' && tauler[i][j+2]!='1' && tauler[i][j+3]!='1'){
            for(int k=0;k<4;k++){
            if(tauler[i][j+k]=='2'){
                    valor++;
            }
            }
            }
            }


        if(i<N-3){
               if(tauler[i][j]!='2' && tauler[i+1][j]!='2' && tauler[i+2][j]!='2' && tauler[i+3][j]!='2'){
            for(int k=0;k<4;k++){
            if(tauler[i+k][j]=='1'){
                    valor=valor--;
                    //valor=valor-profunditat;
            }
            }
            }
            if(tauler[i][j]!='1' && tauler[i+1][j]!='1' && tauler[i+2][j]!='1' && tauler[i+3][j]!='1'){
            for(int k=0;k<4;k++){
            if(tauler[i+k][j]=='2'){
                    valor++;
            }
            }
            }

        }

        if(i<N-3 && j<N-3){

            if(tauler[i][j]!='2' && tauler[i+1][j+1]!='2' && tauler[i+2][j+2]!='2' && tauler[i+3][j+3]!='2'){
            for(int k=0;k<4;k++){
            if(tauler[i+k][j+k]=='1'){
                    valor=valor--;
                    //valor=valor-profunditat;
            }
            }
            }
            if(tauler[i][j]!='1' && tauler[i+1][j+1]!='1' && tauler[i+2][j+2]!='1' && tauler[i+3][j+3]!='1'){
            for(int k=0;k<4;k++){
            if(tauler[i+k][j+k]=='2'){
                    valor++;
            }
            }
            }
        }

        if(i<N-3 && j>2){

               if(tauler[i][j]!='2' && tauler[i+1][j-1]!='2' && tauler[i+2][j-2]!='2' && tauler[i+3][j-3]!='2'){
            for(int k=0;k<4;k++){
            if(tauler[i+k][j-k]=='1'){
                    valor=valor--;
                    //valor=valor-profunditat;
            }
            }
            }
            if(tauler[i][j]!='1' && tauler[i+1][j-1]!='1' && tauler[i+2][j-2]!='1' && tauler[i+3][j-3]!='1'){
            for(int k=0;k<4;k++){
            if(tauler[i+k][j-k]=='2'){
                    valor++;
            }
            }
            }
        }
        }
    }
    return valor;
}
void menu(void){ //Printeja el menú de benvinguda
    for(int i=0;i<50;i++){
    printf("+");
    }
    for(int i=0;i<15;i++){
             printf("\n");
        printf("+");
        for(int j=0;j<48;j++){
                if(i==3){
        for(int i=0;i<12;i++){
            printf(" ");
        }
        printf("BENVINGUT AL 4 EN LINIA ");
        for(int i=0;i<12;i++){
            printf(" ");
        }
            break;
        }
        if(i==4){
        for(int i=0;i<12;i++){
            printf(" ");
        }
        for(int i=0;i<23;i++){
        printf("-");
        }
        printf(" ");
        for(int i=0;i<12;i++){
            printf(" ");
        }
            break;
        }
        if(i==8){
                for(int i=0;i<8;i++){
            printf(" ");
        }
            printf("Prem ENTER per iniciar la partida");
         for(int i=0;i<7;i++){
            printf(" ");
        }
            break;
        }
            printf(" ");


        }
        printf("+");
    }
    printf("\n");
    for(int i=0;i<50;i++){
    printf("+");
    }
    printf("\n");
}
void exitMenuGuanyador(void){ //Printeja el menú de si guanya l'humà
    printf("\n");
     for(int i=0;i<50;i++){
    printf("+");
    }
    for(int i=0;i<15;i++){
             printf("\n");
        printf("+");
        for(int j=0;j<48;j++){
                if(i==3){
        for(int i=0;i<7;i++){
            printf(" ");
        }
        printf("ENHORABONA HAS GUNAYAT LA PARTIDA!");
        for(int i=0;i<7;i++){
            printf(" ");
        }
            break;
        }
        if(i==4){
        for(int i=0;i<7;i++){
            printf(" ");
        }
        for(int i=0;i<34;i++){
        printf("-");
        }
        printf(" ");
        for(int i=0;i<6;i++){
            printf(" ");
        }
            break;
        }
        if(i==8){
                for(int i=0;i<6;i++){
            printf(" ");
        }
            printf("Introdueix 1 per reiniciar la partida");
         for(int i=0;i<5;i++){
            printf(" ");
        }
            break;
        }
        if(i==10){
                for(int i=0;i<24;i++){
            printf(" ");
        }
            printf("o");
         for(int i=0;i<23;i++){
            printf(" ");
        }
            break;
        }

        if(i==12){
                for(int i=0;i<6;i++){
            printf(" ");
        }
            printf("Introdueix 2 per sortir del joc");
         for(int i=0;i<11;i++){
            printf(" ");
        }
            break;
        }
            printf(" ");


        }
        printf("+");
    }
    printf("\n");
    for(int i=0;i<50;i++){
    printf("+");
    }
    printf("\n");
}
void exitMenuPerdedor(void){ //printeja el menú de si perd l'humà
    printf("\n");
     for(int i=0;i<50;i++){
    printf("+");
    }
    for(int i=0;i<15;i++){
             printf("\n");
        printf("+");
        for(int j=0;j<48;j++){
                if(i==3){
        for(int i=0;i<14;i++){
            printf(" ");
        }
        printf("HAS PERDUT LA PARTIDA");
        for(int i=0;i<13;i++){
            printf(" ");
        }
            break;
        }
        if(i==4){
        for(int i=0;i<14;i++){
            printf(" ");
        }
        for(int i=0;i<21;i++){
        printf("-");
        }
        printf(" ");
        for(int i=0;i<12;i++){
            printf(" ");
        }
            break;
        }
        if(i==8){
                for(int i=0;i<6;i++){
            printf(" ");
        }
            printf("Introdueix 1 per reiniciar la partida");
         for(int i=0;i<5;i++){
            printf(" ");
        }
            break;
        }
        if(i==10){
                for(int i=0;i<24;i++){
            printf(" ");
        }
            printf("o");
         for(int i=0;i<23;i++){
            printf(" ");
        }
            break;
        }

        if(i==12){
                for(int i=0;i<6;i++){
            printf(" ");
        }
            printf("Introdueix 2 per sortir del joc");
         for(int i=0;i<11;i++){
            printf(" ");
        }
            break;
        }
            printf(" ");


        }
        printf("+");
    }
    printf("\n");
    for(int i=0;i<50;i++){
    printf("+");
    }
    printf("\n");
}
void exitMenuEmpat(void){ //Printeja el menú d'empat
    printf("\n");
     for(int i=0;i<50;i++){
    printf("+");
    }
    for(int i=0;i<15;i++){
             printf("\n");
        printf("+");
        for(int j=0;j<48;j++){
                if(i==3){
        for(int i=0;i<14;i++){
            printf(" ");
        }
        printf("HAS EMPATAT LA PARTIDA");
        for(int i=0;i<12;i++){
            printf(" ");
        }
            break;
        }
        if(i==4){
        for(int i=0;i<14;i++){
            printf(" ");
        }
        for(int i=0;i<22;i++){
        printf("-");
        }
        printf(" ");
        for(int i=0;i<11;i++){
            printf(" ");
        }
            break;
        }
        if(i==8){
                for(int i=0;i<6;i++){
            printf(" ");
        }
            printf("Introdueix 1 per reiniciar la partida");
         for(int i=0;i<5;i++){
            printf(" ");
        }
            break;
        }
        if(i==10){
                for(int i=0;i<24;i++){
            printf(" ");
        }
            printf("o");
         for(int i=0;i<23;i++){
            printf(" ");
        }
            break;
        }

        if(i==12){
                for(int i=0;i<6;i++){
            printf(" ");
        }
            printf("Introdueix 2 per sortir del joc");
         for(int i=0;i<11;i++){
            printf(" ");
        }
            break;
        }
            printf(" ");


        }
        printf("+");
    }
    printf("\n");
    for(int i=0;i<50;i++){
    printf("+");
    }
    printf("\n");
}


void ferPartida(void){ //Estructura del joc

Node *arrel=malloc(sizeof(Node));
    arrel->valor=0;
    arrel->n_fills=calculaNumFills(arrel->tauler);
    arrel->fills=malloc(N*sizeof(Node*));
    inicialitzarTauler(arrel->tauler);
    srand(time(NULL));
    char inici;
    scanf("%c",&inici);
    if(inici=='\n'){
    system("cls");
    printf("\nSTART\n");
    imprimirTauler(arrel->tauler);
    int player;
    int col;
    for(int i=0;i<(N*N);i++){ //Triem el N*N doncs és el nombre màxim de movimients que es poden fer en una partida
        if(i>6){ //Comprova el 4 en linea només si hi ha ja 4 fitxes d'un jugador al tauler

        if(finalJoc(arrel->tauler)==1){ //Guanya la persona
        int tornar; //Variable per poder triar si repetir partides
        system("cls");
        imprimirTauler(arrel->tauler);

        exitMenuGuanyador();
        scanf("%i",&tornar);
        if(tornar==1){
            ferPartida();
            break;
        }
        if(tornar==2){
        break;
        }
        }

        if(finalJoc(arrel->tauler)==2){
        int tornar;
        exitMenuPerdedor();
        scanf("%i",&tornar);
        if(tornar==1){
            ferPartida();
            break;
        }
        if(tornar==2){ //Guanya l'ordinador
        break;
        }
        }
        }
        if(i%2==0){
            player=1;
            printf("Selecciona una columna: \n");
            scanf("%d",&col);
            ferTirada(arrel->tauler,humaAordinador(col),player);
        }
        if(i%2==1){
             player=2;
             creaArbre(arrel,1,profunditat);
             ferMinimaxRecursiu(arrel,1,profunditat);
             trobarTauler(arrel);

             system("cls");
             imprimirTauler(arrel->tauler);
             esborrarArbre(arrel,1,profunditat);



        }

    }

    if(finalJoc(arrel->tauler)==0){ //S'esgoten els iterats del bucle i no hi ha cap guanyador, per tant hi ha empat
        int tornar;
        system("cls");
        imprimirTauler(arrel->tauler);
        exitMenuEmpat();
        scanf("%i",&tornar);
        if(tornar==1){
            ferPartida();
        }
        if(tornar==2){
        }
        }

}


}
