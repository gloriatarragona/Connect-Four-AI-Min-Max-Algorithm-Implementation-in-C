
#define N 8
#define profunditat 6


typedef struct node {
struct node **fills; //array din�mic de pointers a Node
int n_fills; //tamany de l�array din�mic
char tauler[N][N];
double valor; //el valor del node (F. Heur�stica)
 } Node;



Node * creaNode(Node *pare, int nivell, int numDeFill,int n_nivells);
 void trobarTauler(Node*p);
void creaNivell(Node *pare,int nivell, int n_nivells);
void creaArbre(Node *arrel, int n, int n_nivells);
void esborrarArbre(Node*p,int n,int n_nivells);
void recorreArbre(Node *arrel);
void recorreNivell(Node*pare);
int buscarMax(Node *arrel);
int buscarMin(Node *arrel);
void recorreArbreRecursiu(Node*p,int nivell);
int ferMinimaxRecursiu(Node*p,int n,int n_nivells);
int calculaNumFills(char tauler[N][N]);
int transformaFillAColumna(char tauler[N][N],int numDeFill);
