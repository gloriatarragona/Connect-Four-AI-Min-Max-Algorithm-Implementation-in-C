# Connecta 4 en C 

Aquest projecte implementa una versió en C del joc clàssic **Connecta 4**, jugable des de la terminal.  
Permet jugar contra una IA (implementada amb l'algorisme **Minimax**) i mostra el tauler en format text amb colors ANSI.

---

## Estructura del projecte

El codi està modularitzat en 5 fitxers:

| Fitxer           | Descripció                                                  |
|------------------|--------------------------------------------------------------|
| `main.c`         | Punt d'entrada del programa i bucle principal del joc        |
| `4enlinea.c`     | Lògica del joc: moviment, comprovació de victòria, etc.      |
| `4enlinea.h`     | Capçalera amb constants, estructures i prototips             |
| `Minimax.c`      | Algorisme Minimax per a la IA                                |
| `Minimax.h`      | Capçalera del Minimax                                        |
| `run.sh`         | Script Bash per compilar i executar el joc                   |

---

## Exemple de sortida

```
Jugador:  O
Consola:  X

0  0  0  0  0  0  0  0
0  0  0  0  0  0  0  0
0  0  0  0  0  0  0  0
0  X  0  0  0  0  0  0
0  O  O  X  0  0  0  0
------------------------
1  2  3  4  5  6  7  8

Selecciona una columna: 
```

>  El caràcter `O` es mostra en **blau** i la `X` en **vermell** si la terminal suporta colors ANSI.

---

##  Compilació

### Opció ràpida (amb script bash)

Assegura’t que tens permisos d’execució i executa:

```bash
chmod +x executar.sh
./executar.sh
```

### Opció manual

Si prefereixes compilar manualment:

```bash
gcc main.c 4enlinea.c Minimax.c -o connecta4
```

---

## Execució

Un cop compilat, pots executar el joc amb:

```bash
./connecta4
```
---

## Requisits

- Sistema Linux/macOS amb `gcc` instal·lat
- Terminal compatible amb seqüències ANSI (per veure els colors)
- 
---
