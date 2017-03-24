#include <iostream>
#include <cstdio>
#include <vector>
#include <ctime>
#include <iomanip>
#include "Separador.h"
#include "Leitura.h"
#include "Escrita.h"
using namespace std;
#define V -1
#define F 9999
#define E 999
#define ER 122
#define QTD_ESTADOS 143
#define B 0
#define QTD_SIMBOLOS 57
#define FLAG "flag"

int main() {
    cout << fixed;
    cout << setprecision(3);
    unsigned int estadoMaquina;
    unsigned int cabecaFita;
    unsigned int posicaoSimboloLido;
    char alfabeto[QTD_SIMBOLOS] = {'\0','a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '=', '+', '-', '*', '/', '%', '^', '>', '<', '!', '(', ')', '[', ']', ':', '.', ';', '_', '#'};


    ///                            TABELA DE TRANSICAO
    ///                                                B  a   b  c  d   e   f   g  h  i  j  k  l   m   n   o   p   q  r   s   t   u    v   w   x   y  z  0    1    2    3    4    5    6    7    8    9    =   +    -    *    /    %    ^    >   <   !   (   )   [   ]   :   .   ;   _  @ 
    int tabelaTransicao[QTD_ESTADOS][QTD_SIMBOLOS] = {
                                                /*0*/ {F, 35, 4, 7, 10, 43, 48, F, F, 1, F, F, 73, 90, 32, 37, 20, F, 69, 15, 51, 100, 85, 57, 38, F, F, 135, 127, 127, 127, 127, 127, 127, 127, 127, 127, 28, 123, 123, 124, 124, 125, 126, 29, 29, 31, 68, 68, 68, 68, 72, 72, 72, F, ER},
///                                                    B  a  b  c  d  e  f   g  h  i  j  k  l  m  n  o  p  q  r  s  t  u  v  w  x  y  z  0  1  2  3  4  5  6  7  8  9  =  +  -  *  /  %  ^  >  <  ! (   )  [  ]  :  .  ;
                                                /*1*/ {F, F, F, F, F, F, 42, F, F, F, F, F, F, F, 2, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, ER},
        ///                                            B  a  b  c  d  e  f  g  h  i  j  k  l  m  n  o  p   q  r  s  t  u  v  w  x  y  z  0  1  2  3  4  5  6  7  8  9  =  +  -  *  /  %  ^  >  <  ! (   )  [  ]  :  .  ;
                                                /*2*/ {F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, 25, F, F, F, 3, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, ER},
        ///                                            B  a  b  c  d  e  f  g  h  i  j  k  l  m  n  o  p  q  r  s  t  u  v  w  x  y  z  0  1  2  3  4  5  6  7  8  9  =  +  -  *  /  %  ^  >  <  ! (   )  [  ]  :  .  ;
                                                /*3*/ {V, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, ER}, /// Fim de indentificador de tipos
        ///                                            B  a  b  c  d  e   f  g  h  i  j  k  l  m  n  o  p  q  r    s  t  u  v  w  x  y  z  0  1  2  3  4  5  6  7  8  9  =  +  -  *  /  %  ^  >  <  ! (   )  [  ]  :  .  ;
                                                /*4*/ {F, F, F, F, F, 53, F, F, F, F, F, F, F, F, F, 5, F, F, 104, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, ER},
        ///                                            B  a  b  c  d  e  f  g  h  i  j  k  l  m  n  o  p  q  r  s  t  u  v  w  x  y  z  0  1  2  3  4  5  6  7  8  9  =  +  -  *  /  %  ^  >  <  ! (   )  [  ]  :  .  ;
                                                /*5*/ {F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, 6, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, ER},
        ///                                            B  a  b  c  d  e  f  g  h  i  j  k  l  m  n  o  p  q  r  s  t  u  v  w  x  y  z  0  1  2  3  4  5  6  7  8  9  =  +  -  *  /  %  ^  >  <  ! (   )  [  ]  :  .  ;
                                                /*6*/ {F, F, F, F, F, F, F, F, F, F, F, F, 3, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, ER},
        ///                                            B  a   b  c  d  e  f  g  h  i  j  k  l  m  n  o   p  q  r   s  t  u  v  w  x  y  z  0  1  2  3  4  5  6  7  8  9  =  +  -  *  /  %  ^  >  <  ! (   )  [  ]  :  .  ;
                                                /*7*/ {F, 66, F, F, F, F, F, F, 8, F, F, F, F, F, F, 87, F, F, 72, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, ER},
        ///                                            B  a  b  c  d  e  f  g  h  i  j  k  l  m  n  o  p  q  r  s  t  u  v  w  x  y  z  0  1  2  3  4  5  6  7  8  9  =  +  -  *  /  %  ^  >  <  ! (   )  [  ]  :  .  ;
                                                /*8*/ {F, 9, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, ER},
        ///                                            B  a  b  c  d  e  f  g  h  i  j  k  l  m  n  o  p  q  r  s  t  u  v  w  x  y  z  0  1  2  3  4  5  6  7  8  9  =  +  -  *  /  %  ^  >  <  ! (   )  [  ]  :  .  ;
                                                /*9*/ {F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, 3, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, ER},
        ///                                            B  a  b  c  d  e  f  g  h  i  j  k  l  m  n  o   p  q  r  s  t  u  v  w  x  y  z  0  1  2  3  4  5  6  7  8  9  =  +  -  *  /  %  ^  >  <  ! (   )  [  ]  :  .  ;
                                               /*10*/ {F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, 11, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, ER},
        ///                                            B  a  b  c  d  e  f  g  h  i  j  k  l  m  n  o  p  q  r  s  t  u   v  w  x  y  z  0  1  2  3  4  5  6  7  8  9  =  +  -  *  /  %  ^  >  <  ! (   )  [  ]  :  .  ;
                                               /*11*/ {50, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, 12, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, ER},
        ///                                            B  a  b   c  d  e  f  g  h  i  j  k  l  m  n  o  p  q  r  s  t  u  v  w  x  y  z  0  1  2  3  4  5  6  7  8  9  =  +  -  *  /  %  ^  >  <  ! (   )  [  ]  :  .  ;
                                               /*12*/ {F, F, 13, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, ER},
        ///                                            B  a  b  c  d  e  f  g  h  i  j  k  l   m  n  o  p  q  r  s  t  u  v  w  x  y  z  0  1  2  3  4  5  6  7  8  9  =  +  -  *  /  %  ^  >  <  ! (   )  [  ]  :  .  ;
                                               /*13*/ {F, F, F, F, F, F, F, F, F, F, F, F, 14, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, ER},
        ///                                            B  a  b  c  d  e  f  g  h  i  j  k  l  m  n  o  p  q  r  s  t  u  v  w  x  y  z  0  1  2  3  4  5  6  7  8  9  =  +  -  *  /  %  ^  >  <  ! (   )  [  ]  :  .  ;
                                               /*14*/ {F, F, F, F, F, 3, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, ER},
        ///                                            B  a  b  c  d  e  f  g  h  i  j  k  l  m  n  o  p  q  r  s  t   u  v  w   x  y  z  0  1  2  3  4  5  6  7  8  9  =  +  -  *  /  %  ^  >  <  ! (   )  [  ]  :  .  ;
                                               /*15*/ {F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, 16, F, F, 61, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, ER},
        ///                                            B  a  b  c  d  e   f  g  h  i  j  k  l  m  n  o  p  q  r   s  t  u  v  w  x  y  z  0  1  2  3  4  5  6  7  8  9  =  +  -  *  /  %  ^  >  <  ! (   )  [  ]  :  .  ;
                                               /*16*/ {F, F, F, F, F, 52, F, F, F, F, F, F, F, F, F, F, F, F, 17, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, ER},
        ///                                            B  a  b  c  d  e  f  g  h  i   j  k  l  m  n  o  p  q  r  s  t  u  v  w  x  y  z  0  1  2  3  4  5  6  7  8  9  =  +  -  *  /  %  ^  >  <  ! (   )  [  ]  :  .  ;
                                               /*17*/ {F, F, F, F, F, F, F, F, F, 18, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, ER},
        ///                                            B  a  b  c  d  e  f  g  h  i  j  k  l  m  n   o  p  q  r  s  t  u  v  w  x  y  z  0  1  2  3  4  5  6  7  8  9  =  +  -  *  /  %  ^  >  <  ! (   )  [  ]  :  .  ;
                                               /*18*/ {F, F, F, F, F, F, F, F, F, F, F, F, F, F, 19, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, ER},
        ///                                            B  a  b  c  d  e  f  g  h  i  j  k  l  m  n  o  p  q  r  s  t  u  v  w  x  y  z  0  1  2  3  4  5  6  7  8  9  =  +  -  *  /  %  ^  >  <  ! (   )  [  ]  :  .  ;
                                               /*19*/ {F, F, F, F, F, F, F, 3, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, ER},
        ///                                            B  a   b  c  d  e  f  g  h  i  j  k  l  m  n  o  p  q  r   s  t  u  v  w  x  y  z  0  1  2  3  4  5  6  7  8  9  =  +  -  *  /  %  ^  >  <  ! (   )  [  ]  :  .  ;
                                               /*20*/ {F, 81, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, 21, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, ER},
        ///                                            B  a  b  c  d  e  f  g  h  i   j  k  l  m  n  o  p  q  r  s  t  u  v  w  x  y  z  0  1  2  3  4  5  6  7  8  9  =  +  -  *  /  %  ^  >  <  ! (   )  [  ]  :  .  ;
                                               /*21*/ {F, F, F, F, F, F, F, F, F, 22, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, ER},
        ///                                            B  a  b  c  d  e  f  g  h  i  j  k  l  m  n   o  p  q  r  s  t  u  v  w  x  y  z  0  1  2  3  4  5  6  7  8  9  =  +  -  *  /  %  ^  >  <  ! (   )  [  ]  :  .  ;
                                               /*22*/ {F, F, F, F, F, F, F, F, F, F, F, F, F, F, 23, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, ER},
        ///                                            B  a  b  c  d  e  f  g  h  i  j  k  l  m  n  o  p  q  r  s  t   u  v  w  x  y  z  0  1  2  3  4  5  6  7  8  9  =  +  -  *  /  %  ^  >  <  ! (   )  [  ]  :  .  ;
                                               /*23*/ {F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, 24, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, ER},
        ///                                            B  a  b  c  d  e  f  g  h  i  j  k  l  m  n  o  p  q  r  s  t  u  v  w  x  y  z  0  1  2  3  4  5  6  7  8  9  =  +  -  *  /  %  ^  >  <  ! (   )  [  ]  :  .  ;
                                               /*24*/ {V, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, ER}, // Saida
        ///                                            B  a  b  c  d  e  f  g  h  i  j  k  l  m  n  o  p  q  r  s  t  u   v  w  x  y  z  0  1  2  3  4  5  6  7  8  9  =  +  -  *  /  %  ^  >  <  ! (   )  [  ]  :  .  ;
                                               /*25*/ {F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, 26, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, ER},
        ///                                            B  a  b  c  d  e  f  g  h  i  j  k  l  m  n  o  p  q  r  s  t   u  v  w  x  y  z  0  1  2  3  4  5  6  7  8  9  =  +  -  *  /  %  ^  >  <  ! (   )  [  ]  :  .  ;
                                               /*26*/ {F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, 27, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, ER},
        ///                                            B  a  b  c  d  e  f  g  h  i  j  k  l  m  n  o  p  q  r  s  t  u  v  w  x  y  z  0  1  2  3  4  5  6  7  8  9  =  +  -  *  /  %  ^  >  <  ! (   )  [  ]  :  .  ;
                                               /*27*/ {V, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, ER}, // Entrada
        ///                                            B  a  b  c  d  e  f  g  h  i  j  k  l  m  n  o  p  q  r  s  t  u  v  w  x  y  z  0  1  2  3  4  5  6  7  8  9  =  +  -  *  /  %  ^  >  <  ! (   )  [  ]  :  .  ;
                                               /*28*/ {V, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, 29, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, ER}, // Atribuicao
        ///                                            B  a  b  c  d  e  f  g  h  i  j  k  l  m  n  o  p  q  r  s  t  u  v  w  x  y  z  0  1  2  3  4  5  6  7  8  9  =  +  -  *  /  %  ^  >  <  ! (   )  [  ]  :  .  ;
                                               /*29*/ {V, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, 30, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, ER}, // operadores relacionais
        ///                                            B  a  b  c  d  e  f  g  h  i  j  k  l  m  n  o  p  q  r  s  t  u  v  w  x  y  z  0  1  2  3  4  5  6  7  8  9  =  +  -  *  /  %  ^  >  <  ! (   )  [  ]  :  .  ;
                                               /*30*/ {V, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, ER}, // operadores relacionais com =
        ///                                            B  a  b  c  d  e  f  g  h  i  j  k  l  m  n  o  p  q  r  s  t  u  v  w  x  y  z  0  1  2  3  4  5  6  7  8  9  =   +  -  *  /  %  ^  >  <  ! (   )  [  ]  :  .  ;
                                               /*31*/ {V, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, 30, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, ER}, // Negacao
        ///                                            B  a   b  c  d  e  f  g  h  i  j  k  l  m  n  o   p  q  r  s  t  u  v  w  x  y  z  0  1  2  3  4  5  6  7  8  9  =  +  -  *  /  %  ^  >  <  ! (   )  [  ]  :  .  ;
                                               /*32*/ {F, 40, F, F, F, F, F, F, F, F, F, F, F, F, F, 33, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, ER},
        ///                                            B  a  b  c  d  e  f  g  h  i  j  k  l  m  n  o  p  q  r  s  t   u  v  w  x  y  z  0  1  2  3  4  5  6  7  8  9  =  +  -  *  /  %  ^  >  <  ! (   )  [  ]  :  .  ;
                                               /*33*/ {F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, 34, F, 34, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, ER},
        ///                                            B  a  b  c  d  e  f  g  h  i  j  k  l  m  n  o  p  q  r  s  t  u  v  w  x  y  z  0  1  2  3  4  5  6  7  8  9  =  +  -  *  /  %  ^  >  <  ! (   )  [  ]  :  .  ;
                                               /*34*/ {V, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, ER}, // operadores lógicos
        ///                                            B  a  b  c  d  e  f  g  h  i  j  k  l  m  n   o  p  q  r  s  t  u  v  w  x  y  z  0  1  2  3  4  5  6  7  8  9  =  +  -  *  /  %  ^  >  <  ! (   )  [  ]  :  .  ;
                                               /*35*/ {F, F, F, F, F, F, F, F, F, F, F, F, F, F, 36, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, ER},
        ///                                            B  a  b  c  d   e  f  g  h  i  j  k  l  m  n  o  p  q  r  s  t  u  v  w  x  y  z  0  1  2  3  4  5  6  7  8  9  =  +  -  *  /  %  ^  >  <  ! (   )  [  ]  :  .  ;
                                               /*36*/ {F, F, F, F, 34, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, ER},
        ///                                            B  a  b  c  d  e  f  g  h  i  j  k  l  m  n  o  p  q  r   s  t  u  v  w  x  y  z  0  1  2  3  4  5  6  7  8  9  =  +  -  *  /  %  ^  >  <  ! (   )  [  ]  :  .  ;
                                               /*37*/ {F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, 34, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, ER},
        ///                                            B  a  b  c  d  e  f  g  h  i  j  k  l  m  n  o   p  q  r  s  t  u  v  w  x  y  z  0  1  2  3  4  5  6  7  8  9  =  +  -  *  /  %  ^  >  <  ! (   )  [  ]  :  .  ;
                                               /*38*/ {F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, 39, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, ER},
        ///                                            B  a  b  c  d  e  f  g  h  i  j  k  l  m  n  o  p  q  r   s  t  u  v  w  x  y  z  0  1  2  3  4  5  6  7  8  9  =  +  -  *  /  %  ^  >  <  ! (   )  [  ]  :  .  ;
                                               /*39*/ {F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, 34, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, ER},
        ///                                            B  a  b  c  d  e  f  g  h  i  j  k  l  m  n   o  p  q  r  s  t  u  v  w  x  y  z  0  1  2  3  4  5  6  7  8  9  =  +  -  *  /  %  ^  >  <  ! (   )  [  ]  :  .  ;
                                               /*40*/ {F, F, F, F, F, F, F, F, F, F, F, F, F, F, 41, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, ER},
        ///                                            B  a  b  c  d   e  f  g  h  i  j  k  l  m  n  o  p  q  r  s  t  u  v  w  x  y  z  0  1  2  3  4  5  6  7  8  9  =  +  -  *  /  %  ^  >  <  ! (   )  [  ]  :  .  ;
                                               /*41*/ {F, F, F, F, 34, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, ER},
        ///                                            B  a  b  c  d  e  f  g  h  i  j  k  l  m  n  o  p  q  r  s  t  u  v  w  x  y  z  0  1  2  3  4  5  6  7  8  9  =  +  -  *  /  %  ^  >  <  ! (   )  [  ]  :  .  ;
                                               /*42*/ {V, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, ER}, // desvio condicional
        ///                                            B  a  b  c  d  e  f  g  h  i  j  k  l   m  n   o  p  q  r  s  t  u  v  w  x  y  z  0  1  2  3  4  5  6  7  8  9  =  +  -  *  /  %  ^  >  <  ! (   )  [  ]  :  .  ;
                                               /*43*/ {F, F, F, F, F, F, F, F, F, F, F, F, 44, F, 56, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, ER},
    ///                                                B  a  b  c  d  e  f  g  h  i  j  k  l  m  n  o  p  q  r  s   t  u  v  w  x  y  z  0  1  2  3  4  5  6  7  8  9  =  +  -  *  /  %  ^  >  <  ! (   )  [  ]  :  .  ;
                                               /*44*/ {F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, 45, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, ER},
    ///                                                B  a  b  c  d  e   f  g  h  i  j  k  l  m  n  o  p  q  r  s  t  u  v  w  x  y  z  0  1  2  3  4  5  6  7  8  9  =  +  -  *  /  %  ^  >  <  ! (   )  [  ]  :  .  ;
                                               /*45*/ {F, F, F, F, F, 46, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, ER},
    ///                                                B  a  b  c  d  e  f  g  h  i   j  k  l  m  n  o  p  q  r  s  t  u  v  w  x  y  z  0  1  2  3  4  5  6  7  8  9  =  +  -  *  /  %  ^  >  <  ! (   )  [  ]  :  .  ;
                                               /*46*/ {V, F, F, F, F, F, F, F, F, 47, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, ER}, // desvio condicional
    ///                                                B  a  b  c  d  e  f  g  h  i  j  k  l  m  n  o  p  q  r  s  t  u  v  w  x  y  z  0  1  2  3  4  5  6  7  8  9  =  +  -  *  /  %  ^  >  <  ! (   )  [  ]  :  .  ;
                                               /*47*/ {V, F, F, F, F, F, 42, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, ER}, // desvio condicional
    ///                                                B  a    b  c  d  e  f  g  h  i    j  k  l  m  n  o   p  q  r  s  t  u  v  w  x  y  z  0  1  2  3  4  5  6  7  8  9  =  +  -  *  /  %  ^  >  <  ! (   )  [  ]  :  .  ;
                                               /*48*/ {F, 119, F, F, F, F, F, F, F, 115, F, F, F, F, F, 49, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, ER},
    ///                                                B  a  b  c  d  e  f  g  h  i  j  k  l  m  n  o  p  q  r   s  t  u  v  w  x  y  z  0  1  2  3  4  5  6  7  8  9  =  +  -  *  /  %  ^  >  <  ! (   )  [  ]  :  .  ;
                                               /*49*/ {F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, 50, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, ER},
    ///                                                B  a  b  c  d  e  f  g  h  i  j  k  l  m  n  o  p  q  r  s  t  u  v  w  x  y  z  0  1  2  3  4  5  6  7  8  9  =  +  -  *  /  %  ^  >  <  ! (   )  [  ]  :  .  ;
                                               /*50*/ {V, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, ER}, // repetição com controle de iteração
    ///                                                B  a  b  c  d  e  f  g  h  i  j  k  l  m  n  o   p  q  r    s  t  u  v  w  x  y  z  0  1  2  3  4  5  6  7  8  9  =  +  -  *  /  %  ^  >  <  ! (   )  [  ]  :  .  ;
                                               /*51*/ {F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, 50, F, F, 117, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, ER},
    ///                                                B  a  b  c  d  e  f  g  h  i  j  k  l  m  n  o  p  q  r  s  t  u  v  w  x  y  z  0  1  2  3  4  5  6  7  8  9  =  +  -  *  /  %  ^  >  <  ! (   )  [  ]  :  .  ;
                                               /*52*/ {F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, 50, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, ER},
    ///                                                B  a  b  c  d  e  f  g   h  i  j  k  l  m  n  o  p  q  r  s  t  u  v  w  x  y  z  0  1  2  3  4  5  6  7  8  9  =  +  -  *  /  %  ^  >  <  ! (   )  [  ]  :  .  ;
                                               /*53*/ {F, F, F, F, F, F, F, 54, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, ER},
    ///                                                B  a  b  c  d  e  f  g  h  i   j  k  l  m  n  o  p  q  r  s  t  u  v  w  x  y  z  0  1  2  3  4  5  6  7  8  9  =  +  -  *  /  %  ^  >  <  ! (   )  [  ]  :  .  ;
                                               /*54*/ {F, F, F, F, F, F, F, F, F, 55, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, ER},
    ///                                                B  a  b  c  d  e  f  g  h  i  j  k  l  m   n  o  p  q  r  s  t  u  v  w  x  y  z  0  1  2  3  4  5  6  7  8  9  =  +  -  *  /  %  ^  >  <  ! (   )  [  ]  :  .  ;
                                               /*55*/ {F, F, F, F, F, F, F, F, F, F, F, F, F, F, 50, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, ER},
    ///                                                B  a  b  c  d    e  f  g  h  i  j  k  l  m  n  o  p  q  r  s  t  u  v  w  x  y  z  0  1  2  3  4  5  6  7  8  9  =  +  -  *  /  %  ^  >  <  ! (   )  [  ]  :  .  ;
                                               /*56*/ {F, F, F, F, 103, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, ER},
    ///                                                B  a  b  c  d  e  f  g  h   i  j  k  l  m  n  o  p  q  r  s  t  u  v  w  x  y  z  0  1  2  3  4  5  6  7  8  9  =  +  -  *  /  %  ^  >  <  ! (   )  [  ]  :  .  ;
                                               /*57*/ {F, F, F, F, F, F, F, F, 58, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, ER},
    ///                                                B  a  b  c  d  e  f  g  h  i   j  k  l  m  n  o  p  q  r  s  t  u  v  w  x  y  z  0  1  2  3  4  5  6  7  8  9  =  +  -  *  /  %  ^  >  <  ! (   )  [  ]  :  .  ;
                                               /*58*/ {F, F, F, F, F, F, F, F, F, 59, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, ER},
    ///                                                B  a  b  c  d  e  f  g  h  i  j  k  l   m  n  o  p  q  r  s  t  u  v  w  x  y  z  0  1  2  3  4  5  6  7  8  9  =  +  -  *  /  %  ^  >  <  ! (   )  [  ]  :  .  ;
                                               /*59*/ {F, F, F, F, F, F, F, F, F, F, F, F, 60, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, ER},
    ///                                                B  a  b  c  d  e  f  g  h  i  j  k  l  m  n  o  p  q  r  s  t  u  v  w  x  y  z  0  1  2  3  4  5  6  7  8  9  =  +  -  *  /  %  ^  >  <  ! (   )  [  ]  :  .  ;
                                               /*60*/ {F, F, F, F, F, 50, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, ER},
    ///                                                B  a   b  c  d  e  f  g  h  i   j  k  l  m  n  o  p  q  r  s  t  u  v  w  x  y  z  0  1  2  3  4  5  6  7  8  9  =  +  -  *  /  %  ^  >  <  ! (   )  [  ]  :  .  ;
                                               /*61*/ {F, 84, F, F, F, F, F, F, F, 62, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, ER},
    ///                                                B  a  b  c  d  e  f  g  h  i  j  k  l  m  n  o  p  q  r  s  t   u  v  w  x  y  z  0  1  2  3  4  5  6  7  8  9  =  +  -  *  /  %  ^  >  <  ! (   )  [  ]  :  .  ;
                                               /*62*/ {F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, 63, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, ER},
    ///                                                B  a  b  c   d  e  f  g  h  i  j  k  l  m  n  o  p  q  r  s  t  u  v  w  x  y  z  0  1  2  3  4  5  6  7  8  9  =  +  -  *  /  %  ^  >  <  ! (   )  [  ]  :  .  ;
                                               /*63*/ {F, F, F, 64, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, ER},
    ///                                                B  a  b  c  d  e  f  g  h   i  j  k  l  m  n  o  p  q  r  s  t  u  v  w  x  y  z  0  1  2  3  4  5  6  7  8  9  =  +  -  *  /  %  ^  >  <  ! (   )  [  ]  :  .  ;
                                               /*64*/ {F, F, F, F, F, F, F, F, 65, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, ER},
        ///                                            B  a  b  c  d  e  f  g  h   i  j  k  l  m  n  o  p  q  r  s  t  u  v  w  x  y  z  0  1  2  3  4  5  6  7  8  9  =  +  -  *  /  %  ^  >  <  ! (   )  [  ]  :  .  ;
                                               /*65*/ {V, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, ER}, // estrutura condicional aninhada
            ///                                        B  a  b  c  d  e  f  g  h  i  j  k  l  m  n  o  p  q  r  s  t  u  v  w  x  y  z  0  1  2  3  4  5  6  7  8  9  =  +  -  *  /  %  ^  >  <  ! (   )  [  ]  :  .  ;
                                               /*66*/ {F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, 67, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, ER},
            ///                                        B  a  b  c  d  e  f  g  h   i  j  k  l  m  n  o  p  q  r  s  t  u  v  w  x  y  z  0  1  2  3  4  5  6  7  8  9  =  +  -  *  /  %  ^  >  <  ! (   )  [  ]  :  .  ;
                                               /*67*/ {F, F, F, F, F, 65, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, ER},
            ///                                        B  a  b  c  d  e  f  g  h   i  j  k  l  m  n  o  p  q  r  s  t  u  v  w  x  y  z  0  1  2  3  4  5  6  7  8  9  =  +  -  *  /  %  ^  >  <  ! (   )  [  ]  :  .  ;
                                               /*68*/ {V, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, ER},// Fim de [ ] ( )
            ///                                        B  a    b  c  d  e   f  g  h  i  j  k  l  m  n  o   p  q  r  s  t  u  v  w  x  y  z  0  1  2  3  4  5  6  7  8  9  =  +  -  *  /  %  ^  >  <  ! (   )  [  ]  :  .  ;
                                               /*69*/ {F, 111, F, F, F, 93, F, F, F, F, F, F, F, F, F, 70, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, ER}, 
            ///                                        B  a  b  c  d  e  f  g  h  i  j  k  l  m  n  o   p  q  r  s  t  u  v  w  x  y  z  0  1  2  3  4  5  6  7  8  9  =  +  -  *  /  %  ^  >  <  ! (   )  [  ]  :  .  ;
                                               /*70*/ {F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, 71, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, ER},
    ///                                                B  a  b  c  d  e  f  g  h  i  j  k  l  m  n  o  p  q  r  s  t   u  v  w  x  y  z  0  1  2  3  4  5  6  7  8  9  =  +  -  *  /  %  ^  >  <  ! (   )  [  ]  :  .  ;
                                               /*71*/ {F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, 72, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, ER},
    ///                                                B  a  b  c  d  e  f  g  h  i  j  k  l  m  n  o  p  q  r  s  t  u  v  w  x  y  z  0  1  2  3  4  5  6  7  8  9  =  +  -  *  /  %  ^  >  <  ! (   )  [  ]  :  .  ;
                                               /*72*/ {V, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, ER}, //outros tokens
    ///                                                B  a  b  c  d  e  f  g  h  i  j  k  l  m  n  o   p  q  r  s  t  u  v  w  x  y  z  0  1  2  3  4  5  6  7  8  9  =  +  -  *  /  %  ^  >  <  ! (   )  [  ]  :  .  ;
                                               /*73*/ {F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, 74, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, ER},
    ///                                                B  a  b  c  d  e  f  g   h  i  j  k  l  m  n  o  p  q  r  s  t  u  v  w  x  y  z  0  1  2  3  4  5  6  7  8  9  =  +  -  *  /  %  ^  >  <  ! (   )  [  ]  :  .  ;
                                               /*74*/ {F, F, F, F, F, F, F, 75, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, ER},
    ///                                                B  a   b  c  d  e  f  g  h  i  j  k  l  m  n  o  p  q  r  s  t  u  v  w  x  y  z  0  1  2  3  4  5  6  7  8  9  =  +  -  *  /  %  ^  >  <  ! (   )  [  ]  :  .  ;
                                               /*75*/ {F, 76, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, ER},
    ///                                                B  a  b  c  d  e  f  g  h  i  j  k  l  m  n  o  p  q  r   s  t  u  v  w  x  y  z  0  1  2  3  4  5  6  7  8  9  =  +  -  *  /  %  ^  >  <  ! (   )  [  ]  :  .  ;
                                               /*76*/ {F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, 77, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, ER},
    ///                                                B  a  b  c  d  e  f  g  h  i   j  k  l  m  n  o  p  q  r  s  t  u  v  w  x  y  z  0  1  2  3  4  5  6  7  8  9  =  +  -  *  /  %  ^  >  <  ! (   )  [  ]  :  .  ;
                                               /*77*/ {F, F, F, F, F, F, F, F, F, 78, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, ER},
    ///                                                B  a  b  c  d  e  f  g  h  i  j  k  l  m  n  o  p  q  r  s  t   u  v  w  x  y  z  0  1  2  3  4  5  6  7  8  9  =  +  -  *  /  %  ^  >  <  ! (   )  [  ]  :  .  ;
                                               /*78*/ {F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, 79, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, ER},
    ///                                                B  a  b  c  d  e  f  g  h   i  j  k  l  m  n  o  p  q  r  s  t  u  v  w  x  y  z  0  1  2  3  4  5  6  7  8  9  =  +  -  *  /  %  ^  >  <  ! (   )  [  ]  :  .  ;
                                               /*79*/ {F, F, F, F, F, F, F, F, 80, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, ER},
    ///                                                B  a  b  c  d  e  f  g  h  i  j  k  l  m   n  o  p  q  r  s  t  u  v  w  x  y  z  0  1  2  3  4  5  6  7  8  9  =  +  -  *  /  %  ^  >  <  ! (   )  [  ]  :  .  ;
                                               /*80*/ {F, F, F, F, F, F, F, F, F, F, F, F, F, 72, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, ER},
    ///                                                B  a  b  c  d  e  f  g  h  i  j  k  l  m  n  o  p  q  r   s  t  u   v  w  x  y  z  0  1  2  3  4  5  6  7  8  9  =  +  -  *  /  %  ^  >  <  ! (   )  [  ]  :  .  ;
                                               /*81*/ {F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, 82, F, F, 97, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, ER},
    ///                                                B  a  b  c  d  e  f  g  h  i  j  k  l  m  n  o  p  q  r  s   t  u  v  w  x  y  z  0  1  2  3  4  5  6  7  8  9  =  +  -  *  /  %  ^  >  <  ! (   )  [  ]  :  .  ;
                                               /*82*/ {F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, 83, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, ER},
    ///                                                B  a  b  c  d  e   f  g  h  i  j  k  l  m  n  o  p  q  r  s  t  u  v  w  x  y  z  0  1  2  3  4  5  6  7  8  9  =  +  -  *  /  %  ^  >  <  ! (   )  [  ]  :  .  ;
                                               /*83*/ {F, F, F, F, F, 72, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, ER},
    ///                                                B  a  b  c  d  e  f  g  h  i  j  k  l  m  n  o  p   q  r  s  t  u  v  w  x  y  z  0  1  2  3  4  5  6  7  8  9  =  +  -  *  /  %  ^  >  <  ! (   )  [  ]  :  .  ;
                                               /*84*/ {F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, 72, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, ER},
    ///                                                B  a   b  c  d  e  f  g  h  i  j  k  l  m  n  o  p  q  r  s  t  u  v  w  x  y  z  0  1  2  3  4  5  6  7  8  9  =  +  -  *  /  %  ^  >  <  ! (   )  [  ]  :  .  ;
                                               /*85*/ {F, 86, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, ER},
    ///                                                B  a  b  c  d  e  f  g  h  i  j  k  l  m  n  o  p  q  r   s  t  u  v  w  x  y  z  0  1  2  3  4  5  6  7  8  9  =  +  -  *  /  %  ^  >  <  ! (   )  [  ]  :  .  ;
                                               /*86*/ {F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, 72, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, ER},
    ///                                                B  a  b  c  d  e  f  g  h  i  j  k  l  m  n   o  p  q  r  s  t  u  v  w  x  y  z  0  1  2  3  4  5  6  7  8  9  =  +  -  *  /  %  ^  >  <  ! (   )  [  ]  :  .  ;
                                               /*87*/ {F, F, F, F, F, F, F, F, F, F, F, F, F, F, 88, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, ER},
    ///                                                B  a  b  c  d  e  f  g  h  i  j  k  l  m  n  o  p  q  r  s   t    u  v  w  x  y  z  0  1  2  3  4  5  6  7  8  9  =  +  -  *  /  %  ^  >  <  ! (   )  [  ]  :  .  ;
                                               /*88*/ {F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, 89, 107, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, ER},
    ///                                                B  a  b  c  d  e  f  g  h  i  j  k  l  m  n  o  p  q  r  s  t   u  v  w  x  y  z  0  1  2  3  4  5  6  7  8  9  =  +  -  *  /  %  ^  >  <  ! (   )  [  ]  :  .  ;
                                               /*89*/ {F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, 72, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, ER},
    ///                                                B  a   b  c  d  e  f  g  h  i  j  k  l  m  n  o  p  q  r  s  t  u  v  w  x  y  z  0  1  2  3  4  5  6  7  8  9  =  +  -  *  /  %  ^  >  <  ! (   )  [  ]  :  .  ;
                                               /*90*/ {F, 91, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, ER},
    ///                                                B  a  b  c  d  e  f  g  h  i   j  k  l  m  n  o  p  q  r  s  t  u  v  w  x  y  z  0  1  2  3  4  5  6  7  8  9  =  +  -  *  /  %  ^  >  <  ! (   )  [  ]  :  .  ;
                                               /*91*/ {F, F, F, F, F, F, F, F, F, 92, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, ER},
    ///                                                B  a  b  c  d  e  f  g  h  i  j  k  l  m  n   o  p  q  r  s  t  u  v  w  x  y  z  0  1  2  3  4  5  6  7  8  9  =  +  -  *  /  %  ^  >  <  ! (   )  [  ]  :  .  ;
                                               /*92*/ {F, F, F, F, F, F, F, F, F, F, F, F, F, F, 72, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, ER},
    ///                                                B  a  b  c  d  e  f  g  h  i  j  k  l  m  n  o  p  q  r  s   t   u  v  w  x  y  z  0  1  2  3  4  5  6  7  8  9  =  +  -  *  /  %  ^  >  <  ! (   )  [  ]  :  .  ;
                                               /*93*/ {F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, 99, 94, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, ER},
    ///                                                B  a  b  c  d  e  f  g  h  i  j  k  l  m  n  o  p  q  r  s  t  u   v  w  x  y  z  0  1  2  3  4  5  6  7  8  9  =  +  -  *  /  %  ^  >  <  ! (   )  [  ]  :  .  ;
                                               /*94*/ {F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, 95, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, ER},
      ///                                              B  a  b  c  d  e  f  g  h  i  j  k  l  m  n  o  p  q  r   s  t  u  v  w  x  y  z  0  1  2  3  4  5  6  7  8  9  =  +  -  *  /  %  ^  >  <  ! (   )  [  ]  :  .  ;
                                               /*95*/ {F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, 96, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, ER},
      ///                                              B  a  b  c  d  e  f  g  h  i  j  k  l  m  n  o  p  q  r  s  t  u  v  w  x  y  z  0  1  2  3  4  5  6  7  8  9  =  +  -  *  /  %  ^  >  <  ! (   )  [  ]  :  .  ;
                                               /*96*/ {F, F, F, F, F, F, F, F, F, F, F, F, F, F, 72, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, ER},
    ///                                                B  a  b  c  d  e  f  g  h  i  j  k  l  m  n  o  p  q  r  s   t  u  v  w  x  y  z  0  1  2  3  4  5  6  7  8  9  =  +  -  *  /  %  ^  >  <  ! (   )  [  ]  :  .  ;
                                               /*97*/ {F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, 98, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, ER},
    ///                                                B  a  b  c  d  e  f  g  h  i  j  k  l  m  n  o  p  q  r  s  t  u  v  w  x  y  z  0  1  2  3  4  5  6  7  8  9  =  +  -  *  /  %  ^  >  <  ! (   )  [  ]  :  .  ;
                                               /*98*/ {F, F, F, F, F, 72, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, ER},
    ///                                                B  a  b  c  d  e  f  g  h  i  j  k  l  m  n  o  p  q  r  s  t  u  v  w  x  y  z  0  1  2  3  4  5  6  7  8  9  =  +  -  *  /  %  ^  >  <  ! (   )  [  ]  :  .  ;
                                               /*99*/ {F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, 72, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, ER},
    ///                                                B  a  b  c  d  e  f  g  h  i  j  k  l  m  n  o  p  q  r  s    t  u  v  w  x  y  z  0  1  2  3  4  5  6  7  8  9  =  +  -  *  /  %  ^  >  <  ! (   )  [  ]  :  .  ;
                                              /*100*/ {F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, 101, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, ER},
    ///                                                B  a  b  c  d  e    f  g  h  i  j  k  l  m  n  o  p  q  r  s  t  u  v  w  x  y  z  0  1  2  3  4  5  6  7  8  9  =  +  -  *  /  %  ^  >  <  ! (   )  [  ]  :  .  ;
                                              /*101*/ {F, F, F, F, F, 102, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, ER},
    ///                                                B  a  b  c  d  e  f  g  h  i  j  k  l  m  n  o  p  q  r  s   t  u  v  w  x  y  z  0  1  2  3  4  5  6  7  8  9  =  +  -  *  /  %  ^  >  <  ! (   )  [  ]  :  .  ;
                                              /*102*/ {F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, 72, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, ER},
    ///                                                B  a  b  c  d  e  f  g  h  i  j  k  l   m  n  o  p  q  r  s  t  u  v  w  x  y  z  0  1  2  3  4  5  6  7  8  9  =  +  -  *  /  %  ^  >  <  ! (   )  [  ]  :  .  ;
                                              /*103*/ {V, F, F, F, F, F, F, F, F, F, F, F, 72, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, ER}, // repetição com controle de iteração
    ///                                                B  a  b  c  d  e    f  g  h  i  j  k  l  m  n  o  p  q  r  s  t  u  v  w  x  y  z  0  1  2  3  4  5  6  7  8  9  =  +  -  *  /  %  ^  >  <  ! (   )  [  ]  :  .  ;
                                              /*104*/ {F, F, F, F, F, 105, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, ER},
    ///                                                B  a    b  c  d  e  f  g  h  i  j  k  l  m  n  o  p  q  r  s  t  u  v  w  x  y  z  0  1  2  3  4  5  6  7  8  9  =  +  -  *  /  %  ^  >  <  ! (   )  [  ]  :  .  ;
                                              /*105*/ {F, 106, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, ER},
    ///                                                B  a  b  c  d  e  f  g  h  i  j  k   l  m  n  o  p  q  r  s  t  u  v  w  x  y  z  0  1  2  3  4  5  6  7  8  9  =  +  -  *  /  %  ^  >  <  ! (   )  [  ]  :  .  ;
                                              /*106*/ {F, F, F, F, F, F, F, F, F, F, F, 72, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, ER},
    ///                                                B  a  b  c  d  e  f  g  h  i    j  k  l  m  n  o  p  q  r  s  t  u  v  w  x  y  z  0  1  2  3  4  5  6  7  8  9  =  +  -  *  /  %  ^  >  <  ! (   )  [  ]  :  .  ;
                                              /*107*/ {F, F, F, F, F, F, F, F, F, 108, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, ER},
    ///                                                B  a  b  c  d  e  f  g  h  i  j  k  l  m  n    o  p  q  r  s  t  u  v  w  x  y  z  0  1  2  3  4  5  6  7  8  9  =  +  -  *  /  %  ^  >  <  ! (   )  [  ]  :  .  ;
                                              /*108*/ {F, F, F, F, F, F, F, F, F, F, F, F, F, F, 109, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, ER},
    ///                                                B  a  b  c  d  e  f  g  h  i  j  k  l  m  n  o  p  q  r  s  t  u    v  w  x  y  z  0  1  2  3  4  5  6  7  8  9  =  +  -  *  /  %  ^  >  <  ! (   )  [  ]  :  .  ;
                                              /*109*/ {F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, 110, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, ER},
    ///                                                B  a  b  c  d  e   f  g  h  i  j  k  l  m  n  o  p  q  r  s  t  u  v  w  x  y  z  0  1  2  3  4  5  6  7  8  9  =  +  -  *  /  %  ^  >  <  ! (   )  [  ]  :  .  ;
                                              /*110*/ {F, F, F, F, F, 72, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, ER},
    ///                                                B  a  b  c  d  e  f  g  h  i  j  k  l  m  n    o  p  q  r  s  t  u  v  w  x  y  z  0  1  2  3  4  5  6  7  8  9  =  +  -  *  /  %  ^  >  <  ! (   )  [  ]  :  .  ;
                                              /*111*/ {F, F, F, F, F, F, F, F, F, F, F, F, F, F, 112, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, ER},
    ///                                                B  a  b  c  d    e  f  g  h  i  j  k  l  m  n  o  p  q  r  s  t  u  v  w  x  y  z  0  1  2  3  4  5  6  7  8  9  =  +  -  *  /  %  ^  >  <  ! (   )  [  ]  :  .  ;
                                              /*112*/ {F, F, F, F, 113, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, ER},
    ///                                                B  a  b  c  d  e  f  g  h  i  j  k  l  m  n  o    p  q  r  s  t  u  v  w  x  y  z  0  1  2  3  4  5  6  7  8  9  =  +  -  *  /  %  ^  >  <  ! (   )  [  ]  :  .  ;
                                              /*113*/ {F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, 114, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, ER},
    ///                                                B  a  b  c  d  e  f  g  h  i  j  k  l  m   n  o  p  q  r  s  t  u  v  w  x  y  z  0  1  2  3  4  5  6  7  8  9  =  +  -  *  /  %  ^  >  <  ! (   )  [  ]  :  .  ;
                                              /*114*/ {F, F, F, F, F, F, F, F, F, F, F, F, F, 72, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, ER},
    ///                                                B  a  b  c  d  e  f  g  h  i  j  k  l    m  n  o  p  q  r  s  t  u  v  w  x  y  z  0  1  2  3  4  5  6  7  8  9  =  +  -  *  /  %  ^  >  <  ! (   )  [  ]  :  .  ;
                                              /*115*/ {F, F, F, F, F, F, F, F, F, F, F, F, 116, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, ER},
    ///                                                B  a  b  c  d  e   f  g  h  i  j  k  l  m  n  o  p  q  r  s  t  u  v  w  x  y  z  0  1  2  3  4  5  6  7  8  9  =  +  -  *  /  %  ^  >  <  ! (   )  [  ]  :  .  ;
                                              /*116*/ {F, F, F, F, F, 72, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, ER},
    ///                                                B  a  b  c  d  e  f  g  h  i  j  k  l  m  n  o  p  q  r  s  t  u    v  w  x  y  z  0  1  2  3  4  5  6  7  8  9  =  +  -  *  /  %  ^  >  <  ! (   )  [  ]  :  .  ;
                                              /*117*/ {F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, 118, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, ER},
    ///                                                B  a  b  c  d  e   f  g  h  i  j  k  l  m  n  o  p  q  r  s  t  u  v  w  x  y  z  0  1  2  3  4  5  6  7  8  9  =  +  -  *  /  %  ^  >  <  ! (   )  [  ]  :  .  ;
                                              /*118*/ {F, F, F, F, F, 72, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, ER},
    ///                                                B  a  b  c  d  e  f  g  h  i  j  k  l    m  n  o  p  q  r  s  t  u  v  w  x  y  z  0  1  2  3  4  5  6  7  8  9  =  +  -  *  /  %  ^  >  <  ! (   )  [  ]  :  .  ;
                                              /*119*/ {F, F, F, F, F, F, F, F, F, F, F, F, 120, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, ER},
    ///                                                B  a  b  c  d  e  f  g  h  i  j  k  l  m  n  o  p  q  r  s    t  u  v  w  x  y  z  0  1  2  3  4  5  6  7  8  9  =  +  -  *  /  %  ^  >  <  ! (   )  [  ]  :  .  ;
                                              /*120*/ {F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, 121, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, ER},
    ///                                                B  a  b  c  d  e   f  g  h  i  j  k  l  m  n  o  p  q  r  s  t  u  v  w  x  y  z  0  1  2  3  4  5  6  7  8  9  =  +  -  *  /  %  ^  >  <  ! (   )  [  ]  :  .  ;
                                              /*121*/ {F, F, F, F, F, 72, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, ER}, /// ESTADO ERRO SIMBOLO NAO EXISTENTE
    ///                                                B  a  b  c  d  e  f  g  h  i  j  k  l  m  n  o  p  q  r  s  t  u  v  w  x  y  z  0  1  2  3  4  5  6  7  8  9  =  +  -  *  /  %  ^  >  <  ! (   )  [  ]  :  .  ;
                                              /*122*/ {E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E}, // Estado de erro de simbolo nao existente
    ///                                                B  a  b  c  d  e  f  g  h  i  j  k  l  m  n  o  p  q  r  s  t  u  v  w  x  y  z  0  1  2  3  4  5  6  7  8  9  =  +  -  *  /  %  ^  >  <  ! (   )  [  ]  :  .  ;
                                              /*123*/ {V, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, ER}, // op. Aritm. (preced. 4)
    ///                                                B  a  b  c  d  e  f  g  h  i  j  k  l  m  n  o  p  q  r  s  t  u  v  w  x  y  z  0  1  2  3  4  5  6  7  8  9  =  +  -  *  /  %  ^  >  <  ! (   )  [  ]  :  .  ;
                                              /*124*/ {V, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, ER},// op. Aritm. (preced. 3)
    ///                                                B  a  b  c  d  e  f  g  h  i  j  k  l  m  n  o  p  q  r  s  t  u  v  w  x  y  z  0  1  2  3  4  5  6  7  8  9  =  +  -  *  /  %  ^  >  <  ! (   )  [  ]  :  .  ;
                                              /*125*/ {V, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, ER}, // op. Aritm. (preced. 2)
    ///                                                B  a  b  c  d  e  f  g  h  i  j  k  l  m  n  o  p  q  r  s  t  u  v  w  x  y  z  0  1  2  3  4  5  6  7  8  9  =  +  -  *  /  %  ^  >  <  ! (   )  [  ]  :  .  ;
                                              /*126*/ {V, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, ER},// op. Aritm. (preced. 1)
    ///                                                B  a  b  c  d  e  f  g  h  i  j  k  l  m  n  o  p  q  r  s  t  u  v  w  x  y  z  0    1    2    3    4    5    6    7    8    9    =  +  -  *  /  %  ^  >  <  ! (   )  [  ]  :  .    ;
                                              /*127*/ {V, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, 131, F, F, ER},// literais numéricas
    ///                                                B  a  b  c  d  e  f  g  h  i  j  k  l  m  n  o  p  q  r  s  t  u  v  w  x  y  z  0    1    2    3    4    5    6    7    8    9    =  +  -  *  /  %  ^  >  <  ! (   )  [  ]  :  .    ;
                                              /*128*/ {V, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, 129, 129, 129, 129, 129, 129, 129, 129, 129, 129, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, 131, F, F, ER},// literais numéricas
    ///                                                B  a  b  c  d  e  f  g  h  i  j  k  l  m  n  o  p  q  r  s  t  u  v  w  x  y  z  0    1    2    3    4    5    6    7    8    9    =  +  -  *  /  %  ^  >  <  ! (   )  [  ]  :  .    ;
                                              /*129*/ {V, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, 131, F, F, ER},// literais numéricas
    ///                                                B  a  b  c  d  e  f  g  h  i  j  k  l  m  n  o  p  q  r  s  t  u  v  w  x  y  z  0  1  2  3  4  5  6  7  8  9  =  +  -  *  /  %  ^  >  <  ! (   )  [  ]  :  .    ;
                                              /*130*/ {V, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, 131, F, F, ER},// literais numéricas
        ///                                            B  a  b  c  d  e  f  g  h  i  j  k  l  m  n  o  p  q  r  s  t  u  v  w  x  y  z  0    1    2    3    4    5    6    7    8    9    =  +  -  *  /  %  ^  >  <  ! (   )  [  ]  :  .  ;
                                              /*131*/ {F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, 132, 132, 132, 132, 132, 132, 132, 132, 132, 132, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, ER},
        ///                                            B  a  b  c  d  e  f  g  h  i  j  k  l  m  n  o  p  q  r  s  t  u  v  w  x  y  z  0    1    2    3    4    5    6    7    8    9    =  +  -  *  /  %  ^  >  <  ! (   )  [  ]  :  .  ;
                                              /*132*/ {V, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, ER},// literais numéricas
        ///                                            B  a  b  c  d  e  f  g  h  i  j  k  l  m  n  o  p  q  r  s  t  u  v  w  x  y  z  0    1    2    3    4    5    6    7    8    9    =  +  -  *  /  %  ^  >  <  ! (   )  [  ]  :  .  ;
                                              /*133*/ {V, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, ER},// literais numéricas
        ///                                            B  a  b  c  d  e  f  g  h  i  j  k  l  m  n  o  p  q  r  s  t  u  v  w  x  y  z  0  1  2  3  4  5  6  7  8  9  =  +  -  *  /  %  ^  >  <  ! (   )  [  ]  :  .  ;
                                              /*134*/ {V, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, ER},// literais numéricas
        ///                                            B  a  b  c  d  e  f  g  h  i  j  k  l  m  n  o  p  q  r  s  t  u  v  w  x  y  z  0  1  2  3  4  5  6  7  8  9  =  +  -  *  /  %  ^  >  <  ! (   )  [  ]  :  .    ;
                                              /*135*/ {V, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, 136, F, F, ER}, // Fim literal numerica apenas 0
    ///                                                B  a  b  c  d  e  f  g  h  i  j  k  l  m  n  o  p  q  r  s  t  u  v  w  x  y  z  0    1    2    3    4    5    6    7    8    9    =  +  -  *  /  %  ^  >  <  ! (   )  [  ]  :  .  ;
                                              /*136*/ {F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, 137, 137, 137, 137, 137, 137, 137, 137, 137, 137, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, ER},
    ///                                                B  a  b  c  d  e  f  g  h  i  j  k  l  m  n  o  p  q  r  s  t  u  v  w  x  y  z  0    1    2    3    4    5    6    7    8    9    =  +  -  *  /  %  ^  >  <  ! (   )  [  ]  :  .  ;
                                              /*137*/ {V, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, 138, 138, 138, 138, 138, 138, 138, 138, 138, 138, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, ER},// literais numéricas
    ///                                                B  a  b  c  d  e  f  g  h  i  j  k  l  m  n  o  p  q  r  s  t  u  v  w  x  y  z  0    1    2    3    4    5    6    7    8    9    =  +  -  *  /  %  ^  >  <  ! (   )  [  ]  :  .  ;
                                              /*138*/ {V, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, 139, 139, 139, 139, 139, 139, 139, 139, 139, 139, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, ER},// literais numéricas
    ///                                                B  a  b  c  d  e  f  g  h  i  j  k  l  m  n  o  p  q  r  s  t  u  v  w  x  y  z  0  1  2  3  4  5  6  7  8  9  =  +  -  *  /  %  ^  >  <  ! (   )  [  ]  :  .  ;
                                              /*139*/ {V, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, ER},// literais numéricas
    ///                                                B  a  b  c  d  e  f  g  h  i  j  k  l  m  n  o  p  q  r  s  t  u  v  w  x  y  z  0  1  2  3  4  5  6  7  8  9  =  +  -  *  /  %  ^  >  <  ! (   )  [  ]  :  .  ;
                                              /*140*/ {F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, ER},
    ///                                                B  a  b  c  d  e  f  g  h  i  j  k  l  m  n  o  p  q  r  s  t  u  v  w  x  y  z  0  1  2  3  4  5  6  7  8  9  =  +  -  *  /  %  ^  >  <  ! (   )  [  ]  :  .  ;
                                              /*141*/ {F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, ER},
    ///                                                B  a  b  c  d  e  f  g  h  i  j  k  l  m  n  o  p  q  r  s  t  u  v  w  x  y  z  0  1  2  3  4  5  6  7  8  9  =  +  -  *  /  %  ^  >  <  ! (   )  [  ]  :  .  ;
                                              /*142*/ {F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, ER}}; 
    string entrada = leitura();
    // getline(cin, entrada);
    vector<string> entradas = split(entrada);
    entradas.pop_back();
    fflush(stdin);
    clock_t tStart = clock();
    bool simboloExiste[entrada.size()];
    int simbolosEmInt[entrada.size()];
    bool addSimboloFinal = true;

/// ---------------VERIFICA SE OS SIMBOLOS EXISTEM NO E OS TRANSFORMA CADA UM EM INT------------------------------------
    int last = 0;
    for (int ent = 0; ent < entradas.size(); ++ent){
        vector<int> saidas;
        saidas.push_back(0);
        for (int i = 0; i < entradas[ent].size(); ++i) {
            // if(entradas[ent][i] == '\n')
            //     entrada[ent][i] = "";
            simboloExiste[i] = false;
            for (int j = 0; j < QTD_SIMBOLOS ; ++j) {
                if(entradas[ent][i] == alfabeto[j]){
                    simboloExiste[i] = true;
                    // cout << entrada[i] << FLAG << endl;
                    simbolosEmInt[i] = j;
                    last = i;
                    break;
                }
            }
            
            for (int l = 0; l < entradas[ent].size(); ++l) {
                if(!simboloExiste[i]){
                    simbolosEmInt[i] = 55;
                    addSimboloFinal = false;
                    cout << "Simbolo nao existente no alfabeto." << endl;
                }
            }

        }
        /// --------------------------------------------------------------------------------------------
       if (addSimboloFinal){
         simbolosEmInt[++last] = 0;
       }
       // for (int i = 0; i < entradas[ent].size(); ++i){
       //     cout << simbolosEmInt[i] << endl;
       // }

    /// FAZ UMA BUSCA NA MATRIZ PELOS INTEIROS CORRESPONTENTES A CADA POSIÇÃO DOS SIMBOLOS LIDOS.
        bool mostador = true;
        int pi = 0;
        for (int s = 0; s < entradas[ent].size() + 1 ; ++s) {
            int atual = simbolosEmInt[s];
           // cout << "Simb atual " << simbolosEmInt[s] << endl;
            for (int i = pi; i < QTD_ESTADOS ; ++i){
                if(tabelaTransicao[i][atual] != F){

                    pi = tabelaTransicao[i][atual];
                    // cout << "Proximo linha: " << pi << endl;
                    saidas.push_back(pi);
                    if(pi == 122){
                      mostador = false;
                      break;
                    }
                    break;
                }
                if(tabelaTransicao[i][atual] == F){
                    saidas.push_back(F);
                    mostador = false;
                    //cout << "ERRO, NAO HA TRANSICAO PARA O SIMBOLO LIDO" << endl;
                    
                    break;
                }

            }

        }
        if(mostador){
            cout << "ENTRADA " << entradas[ent] << " ACEITA: ";
            for (int j = 0; j < entradas[ent].size() + 1; ++j) {
                if(saidas[j] >= 0){
                    cout << saidas[j];
                    cout << " ";
                }
            }
            // cout << endl;
            // cout << endl;
            //cout << "Tempo total para resolver a entrada: " << (double)(clock() - tStart)/CLOCKS_PER_SEC << endl;
                
        }
        escreve(entradas[ent], saidas);
        cout << endl;
        mostador = true;
        
        }
    
    /// --------------------------------------------------------------------------------------------


    return 0;

}