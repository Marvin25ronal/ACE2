#include "Abecedario.h"
#include "Arduino.h"
void Abecedario::Llenar(){
  Letra *b=new Letra();
  b->let='b';
  Serial.println(b->let);
}
