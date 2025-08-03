#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#include "Minimax.h"
#include "4enlinea.h"




Node * creaNode(Node *pare, int nivell, int numDeFill,int n_nivells){ //Crea un Node fill
    Node *p=malloc(sizeof(Node)); //Creo el node

    copiaTauler(p->tauler,pare->tauler); //Copio el tauler
   // imprimirTauler(complicacions->tauler);

    int columna=transformaFillAColumna(p->tauler,numDeFill); //Miro a quina columna haig de fer la tirada
    int jugador;
    if((nivell+1)%2==0){ //En funció de si estic a un nivell parell o senar tiraré una fitxa 1 o 2
        jugador=2;
    }
    else{
        jugador=1;
    }
    ferTirada(p->tauler,columna,jugador); //Faig la tirada
    p->n_fills=calculaNumFills(p->tauler); //Calculo el nombre de fills
    if(nivell<n_nivells && p->n_fills!=0){
            //Si no he arribat al max de nivells i el nombre de fills es diferent de 0
            //Creo l'array de fills
        p->fills=malloc((p->n_fills)*sizeof(Node*));

    }
    else{
        p->n_fills=0; //Si tenia fills el node li asigno el valor 0 doncs hem arribat al nombre maxim de nivells
        p->fills=NULL; //L'apuntador dels fills apunta a NULL
        p->valor=funcioHeuristica(p->tauler); //Asigno el valor de la funció heuristica a les fulles

    }
    return p;
}
void creaNivell(Node *pare,int nivell, int n_nivells){ //Crea un nivell d'un arbre

    pare->n_fills=calculaNumFills(pare->tauler);//Calculo el numero de fills del node
    for(int i=0;i<pare->n_fills;i++){
        pare->fills[i]=creaNode(pare,nivell,i,n_nivells); //Creo tants nodes com fills

    }

}
void creaArbre(Node *arrel, int n, int n_nivells){ //Crea l'arbre sencer creant els nivells recursivament

    if(n>n_nivells){
        return ;
    }
    creaNivell(arrel,n,n_nivells);

    if(arrel->n_fills!=0){
    for(int i=0;i<arrel->n_fills;i++){
    creaArbre(arrel->fills[i],n+1,n_nivells);
    }
    }
}
void esborrarArbre(Node*p,int n,int n_nivells){ //Esborra recursivament el node i l'array de fills
    for(int i=0;i<p->n_fills;i++){
        if(p->fills[i]->n_fills!=0 && n<=n_nivells){
        esborrarArbre(p->fills[i],n+1,n_nivells);
        }
    }
    if(n!=1){
    free(p->fills);
    free(p);
    }

}
void recorreArbre(Node *arrel){ //Crida la funció recorre nivell per cada nivell
    recorreNivell(arrel);
    for(int i=0;i<arrel->n_fills;i++){
        recorreNivell(arrel->fills[i]);
    }
}
void recorreNivell(Node*pare){ //Ens imprimeix els valors dels diferents nodes d'un nivell
    for(int i=0;i<pare->n_fills;i++){
        printf("%i \n",(int)pare->fills[i]->valor);
    }
}
int buscarMax(Node *arrel){ //Busca quin es el maxim dels valors dins d'un conjunt de fills
    int max=arrel->fills[0]->valor;
    int loc=0;
    for(int i=0;i<arrel->n_fills-1;i++){
    if(arrel->fills[i+1]->valor>max){
    max=arrel->fills[i+1]->valor;
    loc=i+1;
    }
    }
    return arrel->fills[loc]->valor;

}
int buscarMin(Node *arrel){ //Busca quin es el minim dels valors dins d'un conjunt de fills
    int min=arrel->fills[0]->valor;
    int loc=0;
    for(int i=0;i<arrel->n_fills-1;i++){
    if(arrel->fills[i+1]->valor<min){
    min=arrel->fills[i+1]->valor;
    loc=i+1;
    }
    }
   // printf("El minim es %d \n",arrel->fills[loc]->valor);
    return arrel->fills[loc]->valor;

}
void recorreArbreRecursiu(Node*p,int nivell){ //Recorre l'arbre de manera recursiva
    for(int j=0;j<nivell;j++){
        printf("  ");
    }
    printf("%i\n", (int)p->valor);
    for(int i=0;i<p->n_fills;i++){
        recorreArbreRecursiu(p->fills[i],nivell+1);

    }

}
int ferMinimaxRecursiu(Node*p,int n,int n_nivells){ //Fa el minimax recursivament
    for(int i=0;i<p->n_fills;i++){
        if(p->fills[i]->n_fills!=0 && n<=n_nivells){
        ferMinimaxRecursiu(p->fills[i],n+1,n_nivells); //Baixa fins les fulles
        }
    }
    if(n%2==0){ //Si el nivell es parell busca el minim
    p->valor=buscarMin(p);

   }
   if(n%2==1){ //Si el nivell és senar busca el maxim
    p->valor=buscarMax(p);
   }


}

int calculaNumFills(char tauler[N][N]){ //Mira quantes columnes hi ha plenes per calcualar el nombre de fills
    int nFills=0;
    if(comprovarLinies(tauler,'2')==1){ //Si hi ha un 4 en linea el node tindrà 0 fills
        return 0;
    }
    for(int i=0;i<N;i++){ //
        nFills=nFills+columnaNoPlena(tauler,i); //Hi ha tants fills com columnes no plenes
    }
    return nFills;
}
int transformaFillAColumna(char tauler[N][N],int numDeFill){ //Verifica segons la posicio dins l'array de fills a quina columna ha de fer la tirada
    int fill=-1;
    for(int i=0;i<N;i++){
        fill=fill+columnaNoPlena(tauler,i);
        if(fill==numDeFill){
            return i;
        }
    }

}
