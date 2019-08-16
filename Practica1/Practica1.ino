//#include "Abecedario.h"
//Abecedario abc;
#include <ArduinoJson.h>

#include "LedControl.h"
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

, dot[6][8] = {{0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 1, 1, 0, 0, 0}, {0, 0, 0, 1, 1, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0}}
, dash[6][8] = {{0, 0, 0, 1, 1, 0, 0, 0}, {0, 0, 0, 1, 1, 0, 0, 0}, {0, 0, 0, 1, 1, 0, 0, 0}, {0, 0, 0, 1, 1, 0, 0, 0}, {0, 0, 0, 1, 1, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0}};

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


//setea cada letra en su lugar
void setMat(int x) {
  for (int a = 0; a < 8; a++) {
    for (int b = 0; b < 8; b++) {
      matrix[a][b] = 0;
    }
  }
  for (int a = 0; a < 12; a++) {
    setArr(x, mensaje[a]);
    x += 6;
  }
}

//VARIABLE PARA EL MODO, MODO 1 POR DEFECTO
volatile unsigned char modo = 1;

void setup() {
  // put your setup code here, to run once:
  Serial1.begin(9600);
 Serial.begin(115200);

  //Activar el boton para el cambio de modos
  attachInterrupt(digitalPinToInterrupt(2), cambiarModo, HIGH);


  lc.shutdown(0, false);
  lc.setIntensity(0, 10);
  lc.clearDisplay(0);

}

void imprimirMorse(int x, const unsigned char morse[5]) {
  for (int i = 0; i < 5; i++) {
    if (morse[i] == 0)
      prueba(x, dot);
    else if (morse[i] == 1)
      prueba(x, dash);
    else
      break;
  }
}

void setMorse(int x, char c) {
  if (x < -6 || 17 < x) {
    return;
  }
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

void loop() {
  // put your main code here, to run repeatedly:
  //abc.Llenar();

  while(Serial1.available()>0){
     String data = Serial1.readStringUntil('\n');
     Serial.println(data);
     DynamicJsonBuffer jsonBuffer;
     JsonObject&root=jsonBuffer.parseObject(data);
     int modo=root[String("modo")];
     String texto=root[String("texto")];
     if(modo==1){

     }else if(modo==2){

     }else if(modo==3){

     }

     //aqui lo mando
  }
  delay(100);

  if (modo == 1 || true) {
    auxmovLetrero++;
    if (auxmovLetrero >= movLetrero) {
      auxmovLetrero = 0;
      setMat(posMat);
      posMat -= 1;
      //n letras de la frase * 6 hola grupo, se cambia si no agarra jaja
      if (posMat == - 64) { //para que sea circular el retrero
        posMat = 9;
      }
      for (int b = 0; b < 8; b++) {
        for (int a = 0; a < 8; a++) {
          lc.setLed(0 , b, cambiar(a) , matrix[b][a]); // se colocan los pines de la matriz con driver
        }
      }
    }
  } else if (modo == 2) {



  }
  delay(10);
}
void Modo2(String texto){

}
void Modo1(String texto){

}

//Metodo llamada en la interrupcion para el cambio de modo
void cambiarModo() {
  modo++;
  if (modo > 3)
    modo = 3;
}
