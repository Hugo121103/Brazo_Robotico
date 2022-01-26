#include<Servo.h> //libreria
Servo base; //servo base
Servo escalera; //escalera
Servo hombro; //hombro
Servo gripper; //gripper
char valor; //variable para indicar que llega una orden 
int contador=0;
int pos = 0; //posicion
int pos2 = 0; //posicion 

int valorPot = 0; //valor del potenciometro
int valorPot2 = 0; //valor del potenciometro
int valorPotA = 0; //valor del potenciometro
int valorPot2A = 0; //valor del potenciometro


int estadoPush=0; //bariable donde guardamos el estado 
int inicioBase=90;
int inicioEscalera=80;
int inicioHombro=180;
void setup() 
{
  Serial.begin (9600);
  base.attach(7); //servo en pin 9
  escalera.attach(8); //servo en pin 9
  hombro.attach(9); //servo en pin 9
  gripper.attach(10); //griper en pin 10
   
  
  ////posicion inicial
  base.write(90); 
  escalera.write(80); 
  hombro.write(180); 
  gripper.write(150); 
 
}

void loop()
{
  
  if (Serial.available()) //si el puerto serie bloethoot esta disponible 
  {
    
   valor = Serial.read(); //lee el dato entrante via bloettoth
   ////////////////////////////////////////////////////////////////
   if (valor == 'C') // si el doto que llego es C
  {
  estadoPush=digitalRead('C'); //leemos el boton del estado automatico 
  delay(200); //siempre

  
  ////***************rutina boton*********************////
  if (estadoPush==LOW) //si boton automatico fue presionado
  {
    contador++; //contador +1
  }
  if (contador==1)
  {
    gripper.write(10);
   
  }
  if (contador==2)
  {
    gripper.write(150);
    contador=0;
    }
    } 
  //pot eje x y base
  if (valor == 'E','D') // si el doto que llego es e o d
  {
    
  valorPot2=analogRead('E');
  pos2=map(valorPot2,0,1023,-10,10);// establecer un rango 0=-10 y 1023=10
  Serial.print(pos2);//imprime posicion del pot
  ////////////////////////////////////////////////////////////////////
  valorPot2A=analogRead('D');
  pos2=map(valorPot2A,0,1023,-10,10);// establecer un rango 0=-10 y 1023=10
  Serial.print(pos2);//imprime posicion del pot
 ////
 if (valor == 'D') // si el doto que llego es e 
 {
 
 inicioBase=inicioBase+3;
    base.write(inicioBase); //escribe la posicion angular 
    }
  else
  {
  if (valor == 'E') // si el doto que llego es e
  {
    inicioBase=inicioBase-3;
    base.write(inicioBase); //escribe la posicion angular 
  }
  }
  }
  //pot eje y (escalera y hombrp
  if (valor == 'A','B') // si el doto que llego es e
  {
  valorPot=analogRead('A');
  pos=map(valorPot,0,1023,-10,10);
  Serial.print(" ,"); //imprimimos posicion del pot
  Serial.print(pos);//imprime posicion del pot
  //////////////////////////////////////////////////////////////////
  valorPotA=analogRead('B');
  pos=map(valorPotA,0,1023,-10,10);
  Serial.print(" ,"); //imprimimos posicion del pot
  Serial.print(pos);//imprime posicion del pot
  ///// condicional hombro y escalera 
  if (valor == 'A') // si el doto que llego es e 
  {
    inicioEscalera=inicioEscalera-3;
    inicioHombro=inicioHombro+3;
    escalera.write(inicioEscalera); //escribe la posicion angular 
    hombro.write(inicioHombro); //escribe la posicion angular 
   }
  else
  {
  if (valor == 'B') // si el doto que llego es e
    {
     inicioEscalera=inicioEscalera+3;
    inicioHombro=inicioHombro-3;
    escalera.write(inicioEscalera); //escribe la posicion angular 
    hombro.write(inicioHombro); //escribe la posicion angular 
    }
  }
  }
  ///////////rutina estatica
 if(pos>=-1 && pos<=1 && pos2>=-1 && pos2<=1 )
 {
 escalera.write(inicioEscalera);              // escribe la posicion angular
 hombro.write(inicioHombro);              // escribe la posicion angular
 base.write(inicioBase);              // escribe la posicion angular
 }
  
  }
 
}
