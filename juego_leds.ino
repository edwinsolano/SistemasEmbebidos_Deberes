/*
 * UNIVERSIDAD TÉCNICA DEL NORTE
 * FICA-CITEL
 * Nombre: Solano Edwin
 * Materia: Sistemas Embebidos
 * DEBER #1: Realizar un programa que accione mediante 4 switchs a un juego de luces diferente
 * CÓDIGO: uso Arduino uno, leds, resistencias
 * Objetivo: hacer un 4 juegos diferentes con leds
 */

const int led6=0;
const int led5=1;
const int led4=2;
const int led3=3;
const int led2=4;
const int led1=5;
const int juego1=6;
const int juego2=7;
const int juego3=8;
const int juego4=9;
int i;

void setup() {
  pinMode(led6,OUTPUT); //pin 8 como salida
  pinMode(led5,OUTPUT); //pin 8 como salida
  pinMode(led4,OUTPUT); //pin 8 como salida
  pinMode(led3,OUTPUT); //pin 8 como salida
  pinMode(led2,OUTPUT); //pin 8 como salida
  pinMode(led1,OUTPUT); //pin 8 como salida
   pinMode(juego1,INPUT); //pin 8 como salida
   pinMode(juego2,INPUT); //pin 8 como entrada
   pinMode(juego3,INPUT); //pin 8 como entrada
   pinMode(juego4,INPUT); //pin 8 como entrada
}

void loop() { 
juegouno(); //llamar al metodo del juego 1
juegodos(); //llamar al metodo del juego 2
juegotres(); //llamar al metodo del juego 3
juegocuatro(); //llamar al metodo del juego 4
}
void juegouno(){  //metodo juego uno
   if(digitalRead(juego1)==HIGH){ // condición que detecte el boton en alto
    delay(200);                   //temporizador
    for(i=0;i<10;i++){            //ciclo repetitivo para contar 10 saltos
    digitalWrite(led2,HIGH);      //encendido led 2 par
    digitalWrite(led4,HIGH);      //encendido led 4 par
    digitalWrite(led6,HIGH);      //encendido led 6 par
    delay(500);
    digitalWrite(led2,LOW);       //apagado led 2 par
    digitalWrite(led4,LOW);       //apagado led 4 par
    digitalWrite(led6,LOW);       //apagado led 6 par
    delay(500);
    }
  }
}
  void juegodos(){  //metodo juego 2
   if(digitalRead(juego2)==HIGH){ // condición que detecte el boton en alto
    delay(200);                   //temporizador
    for(i=0;i<10;i++){            //ciclo repetitivo para contar 10 saltos
    digitalWrite(led1,HIGH);      //encendido led 1 impar
    digitalWrite(led3,HIGH);      //encendido led 3 impar
    digitalWrite(led5,HIGH);      //encendido led 5 impar
    delay(500);
    digitalWrite(led1,LOW);       //apagado led 1 impar
    digitalWrite(led3,LOW);       //apagado led 3 impar
    digitalWrite(led5,LOW);        //apagado led 5 impar
    delay(500);
    }
  }
}
void juegotres(){               //metodo juego tres
   if(digitalRead(juego3)==HIGH){  // condición que detecte el boton en alto
    delay(200);                    //temporizador
      for(i=0;i<10;i++){           //ciclo repetitivo para contar 10 saltos
   digitalWrite(led1,HIGH);        //encenido led 1 
   delay(50);                      //temporizador
   digitalWrite(led1,LOW);         //apagado led 1
   digitalWrite(led2,HIGH);        //encendido led 2
   delay(50);                      //temporizador
   digitalWrite(led2,LOW);         //apagado led 2
   digitalWrite(led3,HIGH);        //encendido led 3
   delay(50);                      //temporizador
   digitalWrite(led3,LOW);         //apagado led 3 
   digitalWrite(led4,HIGH);        //encendido led 4
   delay(50);                      //temporizador
   digitalWrite(led4,LOW);         //apagado led 4
   digitalWrite(led5,HIGH);        //encendio led 5
   delay(50);                      //temporizador
   digitalWrite(led5,LOW);         //apagado led 5
   digitalWrite(led6,HIGH);        //encendido led 6
   delay(50);                      //temporizador 
   digitalWrite(led6,LOW);         //apagado led 6
  }
   }
}
void juegocuatro(){   //metodo juego 4
   if(digitalRead(juego4)==HIGH){   // condición que detecte el boton en alto
    delay(200);                       //temporizador 
      for(i=0;i<10;i++){              //ciclo repetitivo para contar 10 saltos
        digitalWrite(led4,HIGH);      //encendido led 4
         digitalWrite(led3,HIGH);     //encendido led 3
         delay(150);                  //temporizador
          digitalWrite(led4,LOW);     //apagado led 4
         digitalWrite(led3,LOW);       //apagado led 3

          digitalWrite(led2,HIGH);    //encendido led 2
         digitalWrite(led5,HIGH);     //encendido led 5
         delay(150);                  //temporizador
           digitalWrite(led2,LOW);     //apagado led 2
         digitalWrite(led5,LOW);        //apagado led 5

          digitalWrite(led1,HIGH);    //encendido led 1
         digitalWrite(led6,HIGH);     //encendido led 6
         delay(150);                  //temporizador
           digitalWrite(led1,LOW);     //apagado led 1
         digitalWrite(led6,LOW);       //apagado led 6
         delay(150);                  //temporizador
      }     
      }
  }
    
