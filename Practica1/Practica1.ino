//#include "Abecedario.h"
//Abecedario abc;
int frecuencia = 500;
int pin = 22;
#include <ArduinoJson.h>
#include "LedControl.h"


int auxm1 = 0;
int auxm2 = 0;
int tMorse = 450;
int eMorse = 0;
//VARIABLE PARA EL MODO, MODO 1 POR DEFECTO
volatile unsigned char modo = 1;

LedControl lc = LedControl(12, 11, 10, 1); //se cambian los pines despues :D

int cambiar(int x) {
  return (x - 7) * -1;    //para probar en la vida real
  //return x;             //para probar en proteus
}

unsigned char matrix[8][8];
const char mensaje[13] = "holagrupo15";
int posMat = 0;
int movLetrero = 20;
int auxmovLetrero = 100;

const unsigned char
la[6][8] = {{0, 0, 0, 0, 0, 0, 0, 0}, {0, 1, 1, 1, 1, 1, 1, 1}, {1, 0, 0, 0, 1, 0, 0, 0}, {1, 0, 0, 0, 1, 0, 0, 0}, {0, 1, 1, 1, 1, 1, 1, 1}, {0, 0, 0, 0, 0, 0, 0, 0}}
, lb[6][8] = {{1, 1, 1, 1, 1, 1, 1, 1}, {1, 0, 0, 0, 0, 0, 0, 1}, {1, 0, 0, 0, 0, 0, 0, 1}, {1, 0, 0, 0, 0, 0, 0, 1}, {1, 0, 0, 0, 1, 0, 0, 1}, {0, 1, 1, 1, 0, 1, 1, 0}}
, lcc [6][8] = {{0, 0, 0, 0, 0, 0, 0, 0}, {0, 1, 1, 1, 1, 1, 1, 0}, {1, 0, 0, 0, 0, 0, 0, 1}, {1, 0, 0, 0, 0, 0, 0, 1}, {1, 0, 0, 0, 0, 0, 0, 1}, {0, 0, 0, 0, 0, 0, 0, 0}}
, ld[6][8] = {{1, 1, 1, 1, 1, 1, 1, 1}, {1, 0, 0, 0, 0, 0, 0, 1}, {1, 0, 0, 0, 0, 0, 0, 1}, {1, 0, 0, 0, 0, 0, 0, 1}, {1, 1, 0, 0, 0, 0, 1, 1}, {0, 1, 1, 1, 1, 1, 1, 0}}
, le[6][8] = {{0, 0, 0, 0, 0, 0, 0, 0}, {1, 1, 1, 1, 1, 1, 1, 1}, {1, 0, 0, 1, 0, 0, 0, 1}, {1, 0, 0, 1, 0, 0, 0, 1}, {1, 0, 0, 1, 0, 0, 0, 1}, {0, 0, 0, 0, 0, 0, 0, 0}}
, lf[6][8] = {{1, 1, 1, 1, 1, 1, 1, 1}, {1, 0, 0, 1, 0, 0, 0, 0}, {1, 0, 0, 1, 0, 0, 0, 0}, {1, 0, 0, 1, 0, 0, 0, 0}, {1, 0, 0, 1, 0, 0, 0, 0}, {1, 0, 0, 0, 0, 0, 0, 0}}
, lg[6][8] = {{0, 0, 0, 0, 0, 0, 0, 0}, {0, 1, 1, 1, 1, 1, 1, 0}, {1, 0, 0, 0, 0, 0, 0, 1}, {1, 0, 0, 0, 1, 0, 0, 1}, {0, 1, 0, 0, 1, 1, 1, 0}, {0, 0, 0, 0, 0, 0, 0, 0}}
, lh[6][8] = {{1, 1, 1, 1, 1, 1, 1, 1}, {0, 0, 0, 1, 1, 0, 0, 0}, {0, 0, 0, 1, 1, 0, 0, 0}, {0, 0, 0, 1, 1, 0, 0, 0}, {0, 0, 0, 1, 1, 0, 0, 0}, {1, 1, 1, 1, 1, 1, 1, 1}}
, li[6][8] = {{0, 0, 0, 0, 0, 0, 0, 0}, {1, 0, 0, 0, 0, 0, 0, 1}, {1, 1, 1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1, 1, 1}, {1, 0, 0, 0, 0, 0, 0, 1}, {0, 0, 0, 0, 0, 0, 0, 0}}
, lj[6][8] = {{1, 0, 0, 0, 0, 0, 1, 0}, {1, 0, 0, 0, 0, 0, 0, 1}, {1, 1, 1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1, 1, 1}, {1, 0, 0, 0, 0, 0, 0, 0}, {1, 0, 0, 0, 0, 0, 0, 0}}
, lk[6][8] = {{1, 1, 1, 1, 1, 1, 1, 1}, {0, 0, 0, 0, 1, 0, 0, 0}, {0, 0, 0, 1, 1, 0, 0, 0}, {0, 0, 1, 0, 0, 1, 0, 0}, {0, 1, 0, 0, 0, 0, 1, 0}, {1, 0, 0, 0, 0, 0, 0, 1}}
, ll[6][8] = {{1, 1, 1, 1, 1, 1, 1, 1}, {0, 0, 0, 0, 0, 0, 0, 1}, {0, 0, 0, 0, 0, 0, 0, 1}, {0, 0, 0, 0, 0, 0, 0, 1}, {0, 0, 0, 0, 0, 0, 0, 1}, {0, 0, 0, 0, 0, 0, 0, 1}}
, lm[6][8] = {{1, 1, 1, 1, 1, 1, 1, 1}, {0, 1, 1, 0, 0, 0, 0, 0}, {0, 0, 1, 1, 1, 0, 0, 0}, {0, 0, 1, 1, 1, 0, 0, 0}, {0, 1, 1, 0, 0, 0, 0, 0}, {1, 1, 1, 1, 1, 1, 1, 1}}
, ln[6][8] = {{0, 0, 0, 0, 0, 0, 0, 0}, {1, 1, 1, 1, 1, 1, 1, 1}, {0, 0, 1, 0, 0, 0, 0, 0}, {0, 0, 0, 1, 1, 0, 0, 0}, {1, 1, 1, 1, 1, 1, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0}}
, lp[6][8] = {{0, 0, 0, 0, 0, 0, 0, 0}, {1, 1, 1, 1, 1, 1, 1, 1}, {1, 0, 0, 1, 0, 0, 0, 0}, {1, 0, 0, 1, 0, 0, 0, 0}, {1, 1, 1, 1, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0}}
, lq[6][8] = {{0, 1, 1, 1, 1, 1, 1, 0}, {1, 0, 0, 0, 0, 0, 0, 1}, {1, 0, 0, 0, 1, 0, 0, 1}, {1, 0, 0, 0, 0, 1, 0, 1}, {1, 0, 0, 0, 0, 0, 1, 0}, {0, 1, 1, 1, 1, 1, 0, 1}}
, lr[6][8] = {{0, 0, 0, 0, 0, 0, 0, 0}, {1, 1, 1, 1, 1, 1, 1, 1}, {1, 0, 0, 1, 1, 0, 0, 0}, {1, 0, 0, 1, 0, 1, 0, 0}, {1, 1, 1, 1, 0, 0, 1, 1}, {0, 0, 0, 0, 0, 0, 0, 0}}
, ls[6][8] = {{0, 0, 0, 0, 0, 0, 0, 0}, {0, 1, 1, 0, 0, 0, 1, 0}, {1, 0, 0, 1, 0, 0, 0, 1}, {1, 0, 0, 1, 0, 0, 0, 1}, {0, 1, 0, 0, 1, 1, 1, 0}, {0, 0, 0, 0, 0, 0, 0, 0}}
, lt[6][8] = {{0, 0, 0, 0, 0, 0, 0, 0}, {1, 1, 0, 0, 0, 0, 0, 0}, {1, 1, 1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1, 1, 1}, {1, 1, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0}}
, lu[6][8] = {{0, 0, 0, 0, 0, 0, 0, 0}, {1, 1, 1, 1, 1, 1, 1, 0}, {0, 0, 0, 0, 0, 0, 0, 1}, {0, 0, 0, 0, 0, 0, 0, 1}, {1, 1, 1, 1, 1, 1, 1, 0}, {0, 0, 0, 0, 0, 0, 0, 0}}
, lv[6][8] = {{1, 1, 1, 1, 0, 0, 0, 0}, {0, 0, 0, 0, 1, 1, 0, 0}, {0, 0, 0, 0, 0, 0, 1, 1}, {0, 0, 0, 0, 0, 0, 1, 1}, {0, 0, 0, 0, 1, 1, 0, 0}, {1, 1, 1, 1, 0, 0, 0, 0}}
, lw[6][8] = {{1, 1, 1, 1, 1, 1, 1, 1}, {0, 0, 0, 0, 0, 0, 1, 0}, {0, 0, 1, 1, 1, 1, 0, 0}, {0, 0, 1, 1, 1, 1, 0, 0}, {0, 0, 0, 0, 0, 0, 1, 0}, {1, 1, 1, 1, 1, 1, 1, 1}}
, lx[6][8] = {{1, 0, 0, 0, 0, 0, 0, 1}, {0, 1, 1, 0, 0, 1, 1, 0}, {0, 0, 0, 1, 1, 0, 0, 0}, {0, 0, 0, 1, 1, 0, 0, 0}, {0, 1, 1, 0, 0, 1, 1, 0}, {1, 0, 0, 0, 0, 0, 0, 1}}
, ly[6][8] = {{1, 0, 0, 0, 0, 0, 0, 0}, {0, 1, 1, 0, 0, 0, 0, 0}, {0, 0, 0, 1, 1, 1, 1, 1}, {0, 0, 0, 1, 1, 1, 1, 1}, {0, 1, 1, 0, 0, 0, 0, 0}, {1, 0, 0, 0, 0, 0, 0, 0}}
, lz[6][8] = {{1, 0, 0, 0, 0, 1, 1, 1}, {1, 0, 0, 0, 1, 1, 1, 1}, {1, 0, 0, 1, 1, 0, 0, 1}, {1, 0, 1, 1, 0, 0, 0, 1}, {1, 1, 1, 0, 0, 0, 0, 1}, {1, 1, 0, 0, 0, 0, 0, 1}}

, n0[6][8] = {{0, 0, 0, 0, 0, 0, 0, 0}, {1, 1, 1, 1, 1, 1, 1, 1}, {1, 0, 0, 0, 0, 0, 0, 1}, {1, 0, 0, 0, 0, 0, 0, 1}, {1, 1, 1, 1, 1, 1, 1, 1}, {0, 0, 0, 0, 0, 0, 0, 0}}
, n1[6][8] = {{0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 1, 0, 0, 0, 0, 0}, {0, 1, 1, 0, 0, 0, 0, 0}, {1, 1, 1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1, 1, 1}, {0, 0, 0, 0, 0, 0, 0, 0}}
, n2[6][8] = {{0, 0, 0, 0, 0, 0, 0, 0}, {0, 1, 1, 0, 0, 0, 1, 1}, {1, 0, 0, 0, 0, 1, 0, 1}, {1, 0, 0, 0, 1, 0, 0, 1}, {0, 1, 1, 1, 0, 0, 1, 1}, {0, 0, 0, 0, 0, 0, 0, 0}}
, n3[6][8] = {{0, 0, 0, 0, 0, 0, 0, 0}, {0, 1, 0, 0, 0, 0, 1, 0}, {1, 0, 0, 1, 0, 0, 0, 1}, {1, 0, 1, 0, 1, 0, 0, 1}, {0, 1, 0, 0, 0, 1, 1, 0}, {0, 0, 0, 0, 0, 0, 0, 0}}
, n4[6][8] = {{0, 0, 0, 0, 0, 0, 0, 0}, {1, 1, 1, 1, 0, 0, 0, 0}, {0, 0, 0, 1, 0, 0, 0, 0}, {1, 1, 1, 1, 1, 1, 1, 1}, {0, 0, 0, 1, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0}}
, n5[6][8] = {{1, 1, 1, 1, 0, 0, 1, 0}, {1, 0, 0, 1, 0, 0, 0, 1}, {1, 0, 0, 1, 0, 0, 0, 1}, {1, 0, 0, 1, 0, 0, 0, 1}, {1, 0, 0, 0, 1, 0, 0, 1}, {1, 0, 0, 0, 0, 1, 1, 0}}
, n6[6][8] = {{0, 1, 1, 1, 1, 1, 1, 0}, {1, 0, 0, 0, 1, 0, 0, 1}, {1, 0, 0, 0, 1, 0, 0, 1}, {1, 0, 0, 0, 1, 0, 0, 1}, {0, 1, 0, 0, 1, 0, 0, 1}, {0, 0, 1, 0, 0, 1, 1, 0}}
, n7[6][8] = {{1, 1, 0, 0, 0, 0, 0, 0}, {1, 0, 0, 0, 0, 0, 0, 0}, {1, 0, 0, 0, 0, 0, 0, 0}, {1, 0, 0, 1, 1, 1, 1, 1}, {1, 0, 1, 0, 0, 0, 0, 0}, {1, 1, 0, 0, 0, 0, 0, 0}}
, n8[6][8] = {{0, 1, 1, 0, 1, 1, 1, 0}, {1, 0, 0, 1, 0, 0, 0, 1}, {1, 0, 0, 1, 0, 0, 0, 1}, {1, 0, 0, 1, 0, 0, 0, 1}, {1, 0, 0, 1, 0, 0, 0, 1}, {0, 1, 1, 0, 1, 1, 1, 0}}
, n9[6][8] = {{0, 1, 1, 0, 0, 0, 1, 0}, {1, 0, 0, 1, 0, 0, 0, 1}, {1, 0, 0, 1, 0, 0, 0, 1}, {1, 0, 0, 1, 0, 0, 0, 1}, {1, 0, 0, 1, 0, 0, 0, 1}, {0, 1, 1, 1, 1, 1, 1, 0}}

, dot[6][8] =  {{0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 1, 1, 0, 0, 0}, {0, 0, 0, 1, 1, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0}}
, dash[6][8] = {{0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 1, 1, 0, 0, 0}, {0, 0, 0, 1, 1, 0, 0, 0}, { 0, 0, 0, 1, 1, 0, 0, 0}, {0, 0, 0, 1, 1, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0}};

const unsigned char
ma[5] = {0, 1, 2, 2, 2},
        mb[5] = {1, 0, 0, 0, 2},
                mc[5] = {1, 0, 1, 0, 2},
                        md[5] = {1, 0, 0, 2, 2},
                                me[5] = {0, 2, 2, 2, 2},
                                        mf[5] = {0, 0, 1, 0, 2},
                                            mg[5] = {1, 1, 0, 2, 2},
                                                mh[5] = {0, 0, 0, 0, 2},
                                                    mi[5] = {0, 0, 2, 2, 2},
                                                        mj[5] = {0, 1, 1, 1, 2},
                                                            mk[5] = {1, 0, 1, 2, 2},
                                                                ml[5] = {0, 1, 0, 0, 2},
                                                                    mm[5] = {1, 1, 2, 2, 2},
                                                                        mn[5] = {1, 0, 2, 2, 2},
                                                                            mo[5] = {1, 1, 1, 2, 2},
                                                                                mp[5] = {0, 1, 1, 0, 2},
                                                                                    mq[5] = {1, 1, 0, 1, 2},
                                                                                        mr[5] = {0, 1, 0, 2, 2},
                                                                                            ms[5] = {0, 0, 0, 2, 2},
                                                                                                mt[5] = {1, 2, 2, 2, 2},
                                                                                                    mu[5] = {0, 0, 1, 2, 2},
                                                                                                        mv[5] = {0, 0, 0, 1, 2},
                                                                                                            mw[5] = {0, 1, 1, 2, 2},
                                                                                                                mx[5] = {1, 0, 0, 1, 2},
                                                                                                                    my[5] = {1, 0, 1, 1, 2},
                                                                                                                        mz[5] = {1, 1, 0, 0, 2},
                                                                                                                            m1[5] = {0, 1, 1, 1, 1},
                                                                                                                                m2[5] = {0, 0, 1, 1, 1},
                                                                                                                                    m3[5] = {0, 0, 0, 1, 1},
                                                                                                                                        m4[5] = {0, 0, 0, 0, 1},
                                                                                                                                            m5[5] = {0, 0, 0, 0, 0},
                                                                                                                                                m6[5] = {1, 0, 0, 0, 0},
                                                                                                                                                    m7[5] = {1, 1, 0, 0, 0},
                                                                                                                                                        m8[5] = {1, 1, 1, 0, 0},
                                                                                                                                                            m9[5] = {1, 1, 1, 1, 0},
                                                                                                                                                                m0[5] = {1, 1, 1, 1, 1};

int contMorse = 0;




void prueba(int x , const unsigned char arr[6][8]) {
  for (int a = 0; a < 6; a++) {
    if (a + x < 0) {
      continue;
    }
    if (a + x > 7) {
      return;
    }
    for (int b = 0; b < 8; b++) {
      matrix[x + a][b] = arr[a][b];
    }
  }
}

void auxmorse2(int x, const unsigned char morse[5]) {
  if (x == 5) {
    delay(100);
  }
  if (morse[x] == 0) {
    SonarPunto();
    delay(90);
  } else if (morse[x] == 1) {
    SonarBarra();
    delay(25);
  }else{
    delay(100);
    }
}

void auxmorse1(int n , int p) {
  switch (n) {
    case  0:  auxmorse2(p , mh); break;
    case  1:  auxmorse2(p , mo); break;
    case  2:  auxmorse2(p , ml); break;
    case  3:  auxmorse2(p , ma); break;
    case  4:  auxmorse2(p , mg); break;
    case  5:  auxmorse2(p , mr); break;
    case  6:  auxmorse2(p , mu); break;
    case  7:  auxmorse2(p , mp); break;
    case  8:  auxmorse2(p , mo); break;
    case  9:  auxmorse2(p , m1); break;
    case  10:  auxmorse2(p , m5); break;
    default: delay(100); break;
  }
}


void mostrarVertical(int x , const unsigned char arr[6][8]) {
  int aux1 = 7;
  int aux2 = 1;
  for (int a = 0; a < 8; a++) {
    lc.clearDisplay(0);
    for (int b = 0; b < aux2; b++) {
      for (int c = 0; c < 6; c++) {
        lc.setLed(0 , c, cambiar(b + aux1) , arr[c][b] );
      }
    }
    delay(x);
    aux1--;
    aux2++;
  }
}

void setArr(int x , char c) {
  if (x < -6 || 17 < x) {
    return;
  }
  switch (c) {
    case  'a': prueba(x , la); break;
    case  'b': prueba(x , lb); break;
    case  'c': prueba(x , lcc); break;
    case  'd': prueba(x , ld); break;
    case  'e': prueba(x , le); break;
    case  'f': prueba(x , lf); break;
    case  'g': prueba(x , lg); break;
    case  'h': prueba(x , lh); break;
    case  'i': prueba(x , li); break;
    case  'j': prueba(x , lj); break;
    case  'k': prueba(x , lk); break;
    case  'l': prueba(x , ll); break;
    case  'm': prueba(x , lm); break;
    case  'n': prueba(x , ln); break;
    case  'o': prueba(x , n0); break;
    case  'p': prueba(x , lp); break;
    case  'q': prueba(x , lq); break;
    case  'r': prueba(x , lr); break;
    case  's': prueba(x , ls); break;
    case  't': prueba(x , lt); break;
    case  'u': prueba(x , lu); break;
    case  'v': prueba(x , lv); break;
    case  'w': prueba(x , lw); break;
    case  'x': prueba(x , lx); break;
    case  'y': prueba(x , ly); break;
    case  'z': prueba(x , lz); break;

    case  '0': prueba(x , n0); break;
    case  '1': prueba(x , n1); break;
    case  '2': prueba(x , n2); break;
    case  '3': prueba(x , n3); break;
    case  '4': prueba(x , n4); break;
    case  '5': prueba(x , n5); break;
    case  '6': prueba(x , n6); break;
    case  '7': prueba(x , n7); break;
    case  '8': prueba(x , n8); break;
    case  '9': prueba(x , n9); break;
  }
}

void setV(int x , char c) {
  switch (c) {
    case  'a': mostrarVertical(x , la); break;
    case  'b': mostrarVertical(x , lb); break;
    case  'c': mostrarVertical(x , lcc); break;
    case  'd': mostrarVertical(x , ld); break;
    case  'e': mostrarVertical(x , le); break;
    case  'f': mostrarVertical(x , lf); break;
    case  'g': mostrarVertical(x , lg); break;
    case  'h': mostrarVertical(x , lh); break;
    case  'i': mostrarVertical(x , li); break;
    case  'j': mostrarVertical(x , lj); break;
    case  'k': mostrarVertical(x , lk); break;
    case  'l': mostrarVertical(x , ll); break;
    case  'm': mostrarVertical(x , lm); break;
    case  'n': mostrarVertical(x , ln); break;
    case  'o': mostrarVertical(x , n0); break;
    case  'p': mostrarVertical(x , lp); break;
    case  'q': mostrarVertical(x , lq); break;
    case  'r': mostrarVertical(x , lr); break;
    case  's': mostrarVertical(x , ls); break;
    case  't': mostrarVertical(x , lt); break;
    case  'u': mostrarVertical(x , lu); break;
    case  'v': mostrarVertical(x , lv); break;
    case  'w': mostrarVertical(x , lw); break;
    case  'x': mostrarVertical(x , lx); break;
    case  'y': mostrarVertical(x , ly); break;
    case  'z': mostrarVertical(x , lz); break;

    case  '0': mostrarVertical(x , n0); break;
    case  '1': mostrarVertical(x , n1); break;
    case  '2': mostrarVertical(x , n2); break;
    case  '3': mostrarVertical(x , n3); break;
    case  '4': mostrarVertical(x , n4); break;
    case  '5': mostrarVertical(x , n5); break;
    case  '6': mostrarVertical(x , n6); break;
    case  '7': mostrarVertical(x , n7); break;
    case  '8': mostrarVertical(x , n8); break;
    case  '9': mostrarVertical(x , n9); break;
  }
}

void setMorse(int x, char c) {
  switch (c) {
    case  'a': imprimirMorse(x , ma); break;
    case  'b': imprimirMorse(x , mb); break;
    case  'c': imprimirMorse(x , mc); break;
    case  'd': imprimirMorse(x , md); break;
    case  'e': imprimirMorse(x , me); break;
    case  'f': imprimirMorse(x , mf); break;
    case  'g': imprimirMorse(x , mg); break;
    case  'h': imprimirMorse(x , mh); break;
    case  'i': imprimirMorse(x , mi); break;
    case  'j': imprimirMorse(x , mj); break;
    case  'k': imprimirMorse(x , mk); break;
    case  'l': imprimirMorse(x , ml); break;
    case  'm': imprimirMorse(x , mm); break;
    case  'n': imprimirMorse(x , mn); break;
    case  'o': imprimirMorse(x , m0); break;
    case  'p': imprimirMorse(x , mp); break;
    case  'q': imprimirMorse(x , mq); break;
    case  'r': imprimirMorse(x , mr); break;
    case  's': imprimirMorse(x , ms); break;
    case  't': imprimirMorse(x , mt); break;
    case  'u': imprimirMorse(x , mu); break;
    case  'v': imprimirMorse(x , mv); break;
    case  'w': imprimirMorse(x , mw); break;
    case  'x': imprimirMorse(x , mx); break;
    case  'y': imprimirMorse(x , my); break;
    case  'z': imprimirMorse(x , mz); break;

    case  '0': imprimirMorse(x , m0); break;
    case  '1': imprimirMorse(x , m1); break;
    case  '2': imprimirMorse(x , m2); break;
    case  '3': imprimirMorse(x , m3); break;
    case  '4': imprimirMorse(x , m4); break;
    case  '5': imprimirMorse(x , m5); break;
    case  '6': imprimirMorse(x , m6); break;
    case  '7': imprimirMorse(x , m7); break;
    case  '8': imprimirMorse(x , m8); break;
    case  '9': imprimirMorse(x , m9); break;
  }
}

//setea cada letra en su lugar
void setMat(int x) {
  for (int a = 0; a < 8; a++) {
    for (int b = 0; b < 8; b++) {
      matrix[a][b] = 0;
    }
  }
  for (int a = 0; a < 12; a++) {
    char letra = mensaje[a];
    setArr(x, letra);
    x += 6;
  }
}

void imprimirMorse(int x, const unsigned char morse[5]) {
  for (int i = 0; i < 5; i++) {
    if (morse[i] == 0) {
      mostrarVertical(x, dot);
      SonarPunto();
    }

    else if (morse[i] == 1) {
      mostrarVertical(x, dash);
      SonarBarra();
    }
    else
      break;
  }
}

void SonarPunto() {
  tone(pin, frecuencia); //activa un tono de frecuencia determinada en un pin dado
  delay(10);
  noTone(pin);
}
void SonarBarra() {
  tone(pin, frecuencia); //activa un tono de frecuencia determinada en un pin dado
  delay(75);
  noTone(pin);
}

void setup() {
  // put your setup code here, to run once:
  Serial1.begin(9600);
  Serial.begin(115200);

  //Activar el boton para el cambio de modos
  lc.shutdown(0, false);
  lc.setIntensity(0, 10);
  lc.clearDisplay(0);
}

void loop() {
  // put your main code here, to run repeatedly:
  //abc.Llenar();

  /*while(Serial1.available()>0){
     String data = Serial1.readStringUntil('\n');
     Serial.println(data);
     DynamicJsonBuffer jsonBuffer;
     JsonObject&root=jsonBuffer.parseObject(data);
     int modo=root[String("modo")];
     String texto=root[String("texto")];*/
  String texto = "hola nada";
  int modo = 2;
  texto.toLowerCase();
  if (modo == 1)
    Modo1();
  else if (modo == 2)
    Modo2(texto);
  else if (modo == 3) {
    /*for(int i=0;i<texto.length();i++){
      Serial.println(texto[i]);
      setV(0,(char)(texto[i]));

      }*/
    Modo3(0, texto);
    // setV(0 , 'a');
  }
  delay(10);

}

//setea cada letra y morse en su lugar
void Modo3(int x, String cadena) {
  for (int a = 0; a < 8; a++) {
    for (int b = 0; b < 8; b++) {
      matrix[a][b] = 0;
    }
  }
  for (int a = 0; a < cadena.length(); a++) {
    setV(200, (char)(cadena[a]));
    setMorse(75, (char)cadena[a]);
  }
}

void Modo2(String cadena) {
  Serial.println(cadena + "dd");
  for (int a = 0; a < 8; a++) {
    for (int b = 0; b < 8; b++) {
      matrix[a][b] = 0;
    }
  }
  for (int a = 0; a < cadena.length(); a++) {
    //setV(200,(char)(cadena[a]));
    setMorse(10, (char)cadena[a]);
  }
}
void Modo1() {

  if (auxm2 == 6) {
    auxm2 = 0;
    auxm1 ++;
    tMorse = 450;
    eMorse = 0;
  }
  setMat(posMat + 7);
  posMat -= 1;
  //n letras de la frase * 6 hola grupo, se cambia si no agarra jaja
  if (posMat == - 72) { //para que sea circular el retrero
    posMat = 0;
    auxm2 = 0;
    auxm1 = 0;
  }
  for (int b = 0; b < 8; b++) {
    for (int a = 0; a < 8; a++) {
      lc.setLed(0 , b, cambiar(a) , matrix[b][a]); // se colocan los pines de la matriz con driver
    }
  }

  auxmorse1(auxm1 , auxm2);
  auxm2++;

}

//Metodo llamada en la interrupcion para el cambio de modo
