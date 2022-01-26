#include <Servo.h> //libreria
Servo base;
Servo escalera;
Servo hombro;
Servo pinza;
int posbase=10;
int posescalera=50;
int poshombro=170;
int pospinza=100;
void setup() 
{
  base.attach(7);
    escalera.attach(8);
  hombro.attach(9);
    pinza.attach(10);
    base.write(posbase);
    escalera.write(posescalera);
    hombro.write(poshombro);
    pinza.write(pospinza);
    
}

void loop() 
{
  //base gira//
  for(posbase=10; posbase<=160; posbase++)
  {
    base.write(posbase);
    delay(10);
  }
for(posbase=160; posbase>=10; posbase--)
  {
    base.write(posbase);
    delay(10);
  }

//girar escalera//
for(posescalera=50; posescalera<=120; posescalera++)
  {
    escalera.write(posescalera);
    delay(10);
  }
    for(posescalera=120; posescalera>=50; posescalera--)
  {
    escalera.write(posescalera);
    delay(10);
  }
  //girar hombro//

  for(poshombro=170; poshombro<=130; poshombro++)
  {
   hombro.write(poshombro);
    delay(10);
  }
  
for(poshombro=130; poshombro>=170; poshombro--)
  {
    hombro.write(poshombro);
    delay(10);
  }
  //girar pinza//
for(pospinza=100; pospinza>=50; pospinza--)
  {
  pinza.write(pospinza);
    delay(10);
  }
  
for(pospinza=50; pospinza<=100; pospinza++)
  {
    pinza.write(pospinza);
    delay(10);
  }
}
