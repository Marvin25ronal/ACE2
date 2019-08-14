#include "Abecedario.h"
Abecedario abc;

const unsigned char 
 la[6][8] = {{0, 0, 0, 0, 0, 0, 0, 0}, {0, 1, 1, 1, 1, 1, 1, 1}, {1, 0, 0, 0, 1, 0, 0, 0}, {1, 0, 0, 0, 1, 0, 0, 0}, {0, 1, 1, 1, 1, 1, 1, 1}, {0, 0, 0, 0, 0, 0, 0, 0}}
,lb[6][8] = {{1, 1, 1, 1, 1, 1, 1, 1}, {1, 0, 0, 0, 0, 0, 0, 1}, {1, 0, 0, 0, 0, 0, 0, 1}, {1, 0, 0, 0, 0, 0, 0, 1}, {1, 0, 0, 0, 1, 0, 0, 1}, {0, 1, 1, 1, 0, 1, 1, 0}}
,lc[6][8] = {{0, 0, 0, 0, 0, 0, 0, 0}, {0, 1, 1, 1, 1, 1, 1, 0}, {1, 0, 0, 0, 0, 0, 0, 1}, {1, 0, 0, 0, 0, 0, 0, 1}, {1, 0, 0, 0, 0, 0, 0, 1}, {0, 0, 0, 0, 0, 0, 0, 0}}
,ld[6][8] = {{1, 1, 1, 1, 1, 1, 1, 1}, {1, 0, 0, 0, 0, 0, 0, 1}, {1, 0, 0, 0, 0, 0, 0, 1}, {1, 0, 0, 0, 0, 0, 0, 1}, {1, 1, 0, 0, 0, 0, 1, 1}, {0, 1, 1, 1, 1, 1, 1, 0}}
,le[6][8] = {{0, 0, 0, 0, 0, 0, 0, 0}, {1, 1, 1, 1, 1, 1, 1, 1}, {1, 0, 0, 1, 0, 0, 0, 1}, {1, 0, 0, 1, 0, 0, 0, 1}, {1, 0, 0, 1, 0, 0, 0, 1}, {0, 0, 0, 0, 0, 0, 0, 0}}
,lf[6][8] = {{1, 1, 1, 1, 1, 1, 1, 1}, {1, 0, 0, 1, 0, 0, 0, 0}, {1, 0, 0, 1, 0, 0, 0, 0}, {1, 0, 0, 1, 0, 0, 0, 0}, {1, 0, 0, 1, 0, 0, 0, 0}, {1, 0, 0, 0, 0, 0, 0, 0}}
,lg[6][8] = {{0, 0, 0, 0, 0, 0, 0, 0}, {0, 1, 1, 1, 1, 1, 1, 0}, {1, 0, 0, 0, 0, 0, 0, 1}, {1, 0, 0, 0, 1, 0, 0, 1}, {0, 1, 0, 0, 1, 1, 1, 0}, {0, 0, 0, 0, 0, 0, 0, 0}}
,lh[6][8] = {{1, 1, 1, 1, 1, 1, 1, 1}, {0, 0, 0, 1, 1, 0, 0, 0}, {0, 0, 0, 1, 1, 0, 0, 0}, {0, 0, 0, 1, 1, 0, 0, 0}, {0, 0, 0, 1, 1, 0, 0, 0}, {1, 1, 1, 1, 1, 1, 1, 1}}
,li[6][8] = {{0, 0, 0, 0, 0, 0, 0, 0}, {1, 0, 0, 0, 0, 0, 0, 1}, {1, 1, 1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1, 1, 1}, {1, 0, 0, 0, 0, 0, 0, 1}, {0, 0, 0, 0, 0, 0, 0, 0}}
,lj[6][8] = {{1, 0, 0, 0, 0, 0, 1, 0}, {1, 0, 0, 0, 0, 0, 0, 1}, {1, 1, 1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1, 1, 1}, {1, 0, 0, 0, 0, 0, 0, 0}, {1, 0, 0, 0, 0, 0, 0, 0}}
,lk[6][8] = {{1, 1, 1, 1, 1, 1, 1, 1}, {0, 0, 0, 0, 1, 0, 0, 0}, {0, 0, 0, 1, 1, 0, 0, 0}, {0, 0, 1, 0, 0, 1, 0, 0}, {0, 1, 0, 0, 0, 0, 1, 0}, {1, 0, 0, 0, 0, 0, 0, 1}}
,lm[6][8] = {{1, 1, 1, 1, 1, 1, 1, 1}, {0, 1, 1, 0, 0, 0, 0, 0}, {0, 0, 1, 1, 1, 0, 0, 0}, {0, 0, 1, 1, 1, 0, 0, 0}, {0, 1, 1, 0, 0, 0, 0, 0}, {1, 1, 1, 1, 1, 1, 1, 1}}
,ln[6][8] = {{0, 0, 0, 0, 0, 0, 0, 0}, {1, 1, 1, 1, 1, 1, 1, 1}, {0, 0, 1, 0, 0, 0, 0, 0}, {0, 0, 0, 1, 1, 0, 0, 0}, {1, 1, 1, 1, 1, 1, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0}}
,lo[6][8] = {{0, 0, 0, 0, 0, 0, 0, 0}, {1, 1, 1, 1, 1, 1, 1, 1}, {1, 0, 0, 0, 0, 0, 0, 1}, {1, 0, 0, 0, 0, 0, 0, 1}, {1, 1, 1, 1, 1, 1, 1, 1}, {0, 0, 0, 0, 0, 0, 0, 0}}
,lp[6][8] = {{0, 0, 0, 0, 0, 0, 0, 0}, {1, 1, 1, 1, 1, 1, 1, 1}, {1, 0, 0, 1, 0, 0, 0, 0}, {1, 0, 0, 1, 0, 0, 0, 0}, {1, 1, 1, 1, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0}}
,lq[6][8] = {{0, 1, 1, 1, 1, 1, 1, 0}, {1, 0, 0, 0, 0, 0, 0, 1}, {1, 0, 0, 0, 1, 0, 0, 1}, {1, 0, 0, 0, 0, 1, 0, 1}, {1, 0, 0, 0, 0, 0, 1, 0}, {0, 1, 1, 1, 1, 1, 0, 1}}
,lr[6][8] = {{0, 0, 0, 0, 0, 0, 0, 0}, {1, 1, 1, 1, 1, 1, 1, 1}, {1, 0, 0, 1, 1, 0, 0, 0}, {1, 0, 0, 1, 0, 1, 0, 0}, {1, 1, 1, 1, 0, 0, 1, 1}, {0, 0, 0, 0, 0, 0, 0, 0}}
,ls[6][8] = {{0, 0, 0, 0, 0, 0, 0, 0}, {0, 1, 1, 0, 0, 0, 1, 0}, {1, 0, 0, 1, 0, 0, 0, 1}, {1, 0, 0, 1, 0, 0, 0, 1}, {0, 1, 0, 0, 1, 1, 1, 0}, {0, 0, 0, 0, 0, 0, 0, 0}}
,lt[6][8] = {{0, 0, 0, 0, 0, 0, 0, 0}, {1, 1, 0, 0, 0, 0, 0, 0}, {1, 1, 1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1, 1, 1}, {1, 1, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0}}
,lu[6][8] = {{0, 0, 0, 0, 0, 0, 0, 0}, {1, 1, 1, 1, 1, 1, 1, 0}, {0, 0, 0, 0, 0, 0, 0, 1}, {0, 0, 0, 0, 0, 0, 0, 1}, {1, 1, 1, 1, 1, 1, 1, 0}, {0, 0, 0, 0, 0, 0, 0, 0}}
,lv[6][8] = {{1, 1, 1, 1, 0, 0, 0, 0}, {0, 0, 0, 0, 1, 1, 0, 0}, {0, 0, 0, 0, 0, 0, 1, 1}, {0, 0, 0, 0, 0, 0, 1, 1}, {0, 0, 0, 0, 1, 1, 0, 0}, {1, 1, 1, 1, 0, 0, 0, 0}}
,lw[6][8] = {{1, 1, 1, 1, 1, 1, 1, 1}, {0, 0, 0, 0, 0, 0, 1, 0}, {0, 0, 1, 1, 1, 1, 0, 0}, {0, 0, 1, 1, 1, 1, 0, 0}, {0, 0, 0, 0, 0, 0, 1, 0}, {1, 1, 1, 1, 1, 1, 1, 1}}
,lx[6][8] = {{1, 0, 0, 0, 0, 0, 0, 1}, {0, 1, 1, 0, 0, 1, 1, 0}, {0, 0, 0, 1, 1, 0, 0, 0}, {0, 0, 0, 1, 1, 0, 0, 0}, {0, 1, 1, 0, 0, 1, 1, 0}, {1, 0, 0, 0, 0, 0, 0, 1}}
,ly[6][8] = {{1, 0, 0, 0, 0, 0, 0, 0}, {0, 1, 1, 0, 0, 0, 0, 0}, {0, 0, 0, 1, 1, 1, 1, 1}, {0, 0, 0, 1, 1, 1, 1, 1}, {0, 1, 1, 0, 0, 0, 0, 0}, {1, 0, 0, 0, 0, 0, 0, 0}}
,lz[6][8] = {{1, 0, 0, 0, 0, 1, 1, 1}, {1, 0, 0, 0, 1, 1, 1, 1}, {1, 0, 0, 1, 1, 0, 0, 1}, {1, 0, 1, 1, 0, 0, 0, 1}, {1, 1, 1, 0, 0, 0, 0, 1}, {1, 1, 0, 0, 0, 0, 0, 1}}

,n0[6][8] = {{0, 0, 0, 0, 0, 0, 0, 0}, {1, 1, 1, 1, 1, 1, 1, 1}, {1, 0, 0, 0, 0, 0, 0, 1}, {1, 0, 0, 0, 0, 0, 0, 1}, {1, 1, 1, 1, 1, 1, 1, 1}, {0, 0, 0, 0, 0, 0, 0, 0}}
,n1[6][8] = {{0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 1, 0, 0, 0, 0, 0}, {0, 1, 1, 0, 0, 0, 0, 0}, {1, 1, 1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1, 1, 1}, {0, 0, 0, 0, 0, 0, 0, 0}}
,n2[6][8] = {{0, 0, 0, 0, 0, 0, 0, 0}, {0, 1, 1, 0, 0, 0, 1, 1}, {1, 0, 0, 0, 0, 1, 0, 1}, {1, 0, 0, 0, 1, 0, 0, 1}, {0, 1, 1, 1, 0, 0, 1, 1}, {0, 0, 0, 0, 0, 0, 0, 0}}
,n3[6][8] = {{0, 0, 0, 0, 0, 0, 0, 0}, {0, 1, 0, 0, 0, 0, 1, 0}, {1, 0, 0, 1, 0, 0, 0, 1}, {1, 0, 1, 0, 1, 0, 0, 1}, {0, 1, 0, 0, 0, 1, 1, 0}, {0, 0, 0, 0, 0, 0, 0, 0}}
,n4[6][8] = {{0, 0, 0, 0, 0, 0, 0, 0}, {1, 1, 1, 1, 0, 0, 0, 0}, {0, 0, 0, 1, 0, 0, 0, 0}, {1, 1, 1, 1, 1, 1, 1, 1}, {0, 0, 0, 1, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0}}
,n5[6][8] = {{1, 1, 1, 1, 0, 0, 1, 0}, {1, 0, 0, 1, 0, 0, 0, 1}, {1, 0, 0, 1, 0, 0, 0, 1}, {1, 0, 0, 1, 0, 0, 0, 1}, {1, 0, 0, 0, 1, 0, 0, 1}, {1, 0, 0, 0, 0, 1, 1, 0}}
,n6[6][8] = {{0, 1, 1, 1, 1, 1, 1, 0}, {1, 0, 0, 0, 1, 0, 0, 1}, {1, 0, 0, 0, 1, 0, 0, 1}, {1, 0, 0, 0, 1, 0, 0, 1}, {0, 1, 0, 0, 1, 0, 0, 1}, {0, 0, 1, 0, 0, 1, 1, 0}}
,n7[6][8] = {{1, 1, 0, 0, 0, 0, 0, 0}, {1, 0, 0, 0, 0, 0, 0, 0}, {1, 0, 0, 0, 0, 0, 0, 0}, {1, 0, 0, 1, 1, 1, 1, 1}, {1, 0, 1, 0, 0, 0, 0, 0}, {1, 1, 0, 0, 0, 0, 0, 0}}
,n8[6][8] = {{0, 1, 1, 0, 1, 1, 1, 0}, {1, 0, 0, 1, 0, 0, 0, 1}, {1, 0, 0, 1, 0, 0, 0, 1}, {1, 0, 0, 1, 0, 0, 0, 1}, {1, 0, 0, 1, 0, 0, 0, 1}, {0, 1, 1, 0, 1, 1, 1, 0}}
,n9[6][8] = {{0, 1, 1, 0, 0, 0, 1, 0}, {1, 0, 0, 1, 0, 0, 0, 1}, {1, 0, 0, 1, 0, 0, 0, 1}, {1, 0, 0, 1, 0, 0, 0, 1}, {1, 0, 0, 1, 0, 0, 0, 1}, {0, 1, 1, 1, 1, 1, 1, 0}};

const unsigned char 
 ma[2] = {0,1},       mb[4] = {1,0,0,0},      mc[4] = {1,0,1,0},    md[3] = {1,0,0},      me[1] = {0} ,         mf[4] = {0,0,1,0}
,mg[3] = {1,1,0},     mh[4] = {0,0,0,0},      mi[2] = {0,0},        mj[4] = {0,1,1,1},    mk[3] = {1,0,1},      ml[4] = {0,1,0,0}
,mm[2] = {1,1},       mn[2] = {1,0},          mo[3] = {1,1,1},      mp[4] = {0,1,1,0},    mq[4] = {1,1,0,1},    mr[3] = {0,1,0}
,ms[3] = {0,0,0},     mt[1] = {1},            mu[3] = {0,0,1},      mv[4] = {0,0,0,1},    mw[3] = {0,1,1},      mx[4] = {1,0,0,1}
,my[4] = {1,0,1,1},   mz[4] = {1,1,0,0},      m1[5] = {0,1,1,1,1},  m2[5] = {0,0,1,1,1},  m3[5] = {0,0,0,1,1},  m4[5] = {0,0,0,0,1}
,m5[5] = {0,0,0,0,0}, m6[5] = {1,0,0,0,0},    m7[5] = {1,1,0,0,0},  m8[5] = {1,1,1,0,0},  m9[5] = {1,1,1,1,0},  m0[5] = {1,1,1,1,1};









//VARIABLE PARA EL MODO, MODO 1 POR DEFECTO
volatile unsigned char modo = 1;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  //Activar el boton para el cambio de modos
  attachInterrupt(digitalPinToInterrupt(2), cambiarModo, RISING);
}

void loop() {
  // put your main code here, to run repeatedly:
  abc.Llenar();
  delay(2000);
}

//Metodo llamada en la interrupcion para el cambio de modo
void cambiarModo(){
  modo++;
  if(modo>3)
      modo = 3;
}
