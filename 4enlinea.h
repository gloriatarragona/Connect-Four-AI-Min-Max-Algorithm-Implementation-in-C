

#define N 8


int comprovarFila(char tauler[N][N],char jugador);
int comprovarColumna(char tauler[N][N],char jugador);
int comprovarDiagonal(char tauler[N][N],char jugador);
int comprovarDiagonal2(char tauler[N][N],char jugador);
int comprovarLinies(char tauler[N][N],char jugador);
int humaAordinador(int col);
 int ordinadorAhuma(int col);
 void imprimirTauler(char tauler[N][N]);
 int columnaPlena(char tauler[N][N],int col);
 int columnaNoPlena(char tauler[N][N],int col);
 void ferTirada(char tauler[N][N],int col, int jugador);
 void inicialitzarTauler(char tauler[N][N]);
 int finalJoc(char tauler[N][N]);
 void copiaTauler(char taulerD[N][N],char taulerOr[N][N]);
 int funcioHeuristica(char tauler[N][N]);
 int funcioHeuristica2(char tauler[N][N]);
 void menu(void);
 void exitMenuGuanyador(void);
 void exitMenuPerdedor(void);
 void exitMenuEmpat(void);
 void ferPartida(void);
