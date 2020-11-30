/*
* UNIVERSIDAD TECNICA DEL NORTE
* FICA_CITEL
* SISTEMAS EMBEBIDOS
* Nombre: solano Edwin
* Deber3
* objetivo: desarrollar un codigo el cual sea un juego de 8 preguntas pero al momento de 
*           de imprimir le aparesca aleatoriamete 5 de las cuales en un display le de 
*           el resultado de las preguntas corectas. 
*funciones: randomSeed()
*           random();
*           millis()
 */
 
const int A=2; //pin 2 conectado a decodificador 7447
const int B=3; //pin 3 conectado a decodificador 7447
const int C=4; //pin 4 conectado a decodificador 7447
const int D=5; //pin 5 conectado a decodificador 7447
int item0 =0;  //variable para almacenar valor si acerto a la respuesta en pregunta 0
int item1 =0;  //variable para almacenar valor si acerto a la respuesta en pregunta 1
int item2 =0;  //variable para almacenar valor si acerto a la respuesta en pregunta 2
int item3 =0;  //variable para almacenar valor si acerto a la respuesta en pregunta 3
int item4 =0;  //variable para almacenar valor si acerto a la respuesta en pregunta 4
int item5 =0;  //variable para almacenar valor si acerto a la respuesta en pregunta 5
int item6 =0;  //variable para almacenar valor si acerto a la respuesta en pregunta 6
int item7 =0;  //variable para almacenar valor si acerto a la respuesta en pregunta 7
int item8 =0;  //variable para almacenar valor si acerto a la respuesta en pregunta 8
String valor;  //variable para almacenar la respuesta en la pregunta 
String valor0; //variable para almacenar la respuesta en la pregunta 
String valor1;  //variable para almacenar la respuesta en la pregunta 
String valor2;  //variable para almacenar la respuesta en la pregunta 
String valor3;  //variable para almacenar la respuesta en la pregunta 
String valor4;  //variable para almacenar la respuesta en la pregunta 
String valor5;  //variable para almacenar la respuesta en la pregunta 
String valor6;  //variable para almacenar la respuesta en la pregunta 
String valor7;  //variable para almacenar la respuesta en la pregunta 
String valor8;  //variable para almacenar la respuesta en la pregunta 
int conteo=0;   //variable para almacenar la respuesta en la pregunta 
int inicio=1;   //variable para iniciar el juego
 int preg;
 int i;
void setup() {
  pinMode(A,OUTPUT); //pin 8 como salida
  pinMode(B,OUTPUT); //pin 9 como salida
  pinMode(C,OUTPUT); //pin 10 como salida
  pinMode(D,OUTPUT); //pin 11 como salida
  Serial.begin(9600);
  Serial.println("UTN_FICA_CITEL");
  Serial.println("SISTEMAS EMBEBIDOS");
  Serial.println("Solano Edwin Deber 3");
  Serial.println("Juego de Preguntas");
  Serial.println();
  }

void loop() {
  delay(1000); //temporizador
  if(inicio==1){ //valor inicial 
    inicio=0;  //resetear valor 
    for (i=0;i<5;i++){ //ciclo para las 5 preguntas
      delay(100);
      randomSeed(millis()); //generador de numeros pseudoaleatorios
        preg=random(0,8);//generador de numeros aleatorios valores entre 0 y 8
          Serial.print(preg); //lectura en la terminal comucnicacion raduial 
          
        if(preg==0){//si el numero aleatorio es 0 aparece la pregunta
          delay(1000);  //temporizador
            Serial.println("...4+4 es igual a 8"); //impresión de la pregunta
          delay(4000);  //temporizador
        if(Serial.available()>0){ //lectura de la comunciacion serial 
          valor0=Serial.readString();//almacena el dato ingresado en la variable
          if(valor0=="si"){//hace la comparativa de la respuesta 
            item0=1; //aumenta el valor en la suma
            Serial.println("su respuesta es correcta");//si el valor ingresado es correcto
          }else Serial.println("su respuesta es incorrecta");//caso contrario si no es correcto
        }
        Serial.println(""); //espacio en blanco
        }
        if(preg==1){ //si el numero aleatorio es 1 aparece la pregunta
        delay(1000); //temporizador
        Serial.println("...una resitencia almacena energia ?"); //impresión de la pregunta
        delay(4000); //temporizador
        if(Serial.available()>0){ //lectura de la comunciacion serial 
          valor1=Serial.readString(); //almacena el dato ingresado en la variable
          if(valor1=="no"){ //hace la comparativa de la respuesta 
            item1=1;  //aumenta el valor en la suma
            Serial.println("su respuesta es correcta");
          }else Serial.println("su respuesta es Incorrecta");
        }
        Serial.println(""); 
        }
        if(preg==2){ //si el numero aleatorio es 2 aparece la pregunta
        delay(1000); //temporizador
        Serial.println("...un capacitor almacena energia?"); //impresión de la pregunta
        delay(4000); //temporizador
        if(Serial.available()>0){ //lectura de la comunciacion serial 
          valor2=Serial.readString(); //almacena el dato ingresado en la variable
          if(valor2=="si"){ //hace la comparativa de la respuesta 
            item2=1;  //aumenta el valor en la suma
            Serial.println("su respuesta es correcta");
          }else Serial.println("su respuesta es Incorrecta");
        }
        Serial.println(""); 
        }
        if(preg==3){ //si el numero aleatorio es 3 aparece la pregunta
        delay(1000);  //temporizador
        Serial.println("...el planeta es plano"); //impresión de la pregunta
        delay(4000); //temporizador
        if(Serial.available()>0){ //lectura de la comunciacion serial 
          valor3=Serial.readString(); //almacena el dato ingresado en la variable
          if(valor3=="no"){ //hace la comparativa de la respuesta 
            item3=1;  //aumenta el valor en la suma
            Serial.println("su respuesta es correcta");
          }else Serial.println("su respuesta es Incorrecta"); //impresión de la pregunta
        }
        Serial.println(""); 
        }
        if(preg==4){ //si el numero aleatorio es 4 aparece la pregunta
        delay(1000); //temporizador
        Serial.println("...Albert Einsten aun vive"); //impresión de la pregunta
        delay(4000); //temporizador
        if(Serial.available()>0){ //lectura de la comunciacion serial 
          valor4=Serial.readString(); //almacena el dato ingresado en la variable
          if(valor4=="no"){ //hace la comparativa de la respuesta 
            item4=1;  //aumenta el valor en la suma
            Serial.println("su respuesta es correcta");
          }else Serial.println("su respuesta es Incorrecta");
        }
        Serial.println(""); 
        }
        if(preg==5){ //si el numero aleatorio es 5 aparece la pregunta
        delay(1000); //temporizador
        Serial.println("...la formula quimica del agua es c02"); //impresión de la pregunta
        delay(4000); //temporizador
        if(Serial.available()>0){ //lectura de la comunciacion serial 
          valor5=Serial.readString(); //almacena el dato ingresado en la variable
          if(valor5=="no"){ //hace la comparativa de la respuesta 
            item5=1;  //aumenta el valor en la suma
            Serial.println("su respuesta es correcta");
          }else Serial.println("su respuesta es Incorrecta");
        }
        Serial.println(""); 
        }
        if(preg==6){ //si el numero aleatorio es 6 aparece la pregunta
        delay(1000); //temporizador
        Serial.println("...la medicina arregla electrodomesticos"); //impresión de la pregunta
        delay(4000);  //temporizador
        if(Serial.available()>0){ //lectura de la comunciacion serial 
          valor6=Serial.readString(); //almacena el dato ingresado en la variable
          if(valor6=="no"){ //hace la comparativa de la respuesta 
            item6=1;  //aumenta el valor en la suma
            Serial.println("su respuesta es correcta");
          }else Serial.println("su respuesta es Incorrecta");
        }
        Serial.println(""); 
        }
        if(preg==7){  //si el numero aleatorio es 7 aparece la pregunta
        delay(1000); //temporizador
        Serial.println("...windows es un Hatware"); //impresión de la pregunta
        delay(4000); //temporizador
        if(Serial.available()>0){ //lectura de la comunciacion serial 
          valor7=Serial.readString(); //almacena el dato ingresado en la variable
          if(valor7=="no"){ //hace la comparativa de la respuesta 
            item7=1;  //aumenta el valor en la suma
            Serial.println("su respuesta es correcta");
          }else Serial.println("su respuesta es Incorrecta");
        }
        Serial.println(""); 
        }
        if(preg==8){ //si el numero aleatorio es 8 aparece la pregunta
        delay(1000); //temporizador
        Serial.println("...un robot piensa con alma"); //impresión de la pregunta
        delay(4000); //temporizador
        if(Serial.available()>0){ //lectura de la comunciacion serial 
          valor8=Serial.readString(); //almacena el dato ingresado en la variable
             if(valor8=="no"){ //hace la comparativa de la respuesta
            item8=1;  //aumenta el valor en la suma
            Serial.println("su respuesta es correcta");
          }else Serial.println("su respuesta es Incorrecta");
        }
        Serial.println(""); 
        }       
    conteo = item0+item1+item2+item3+item4+item5+item6+item7+item8;//suma de las respuestas correctas
           if(conteo==0){ //condicion si la suma es 0 activa en vinario el numero 0
        digitalWrite(A,LOW);
        digitalWrite(B,LOW);
        digitalWrite(C,LOW);
        digitalWrite(D,LOW);
                        }
           if(conteo==1){ //condicion si la suma es 1 activa en vinario el numero 1
        digitalWrite(A,HIGH);
        digitalWrite(B,LOW);
        digitalWrite(C,LOW);
        digitalWrite(D,LOW);
                        }
          if(conteo==2){ //condicion si la suma es 2 activa en vinario el numero 2
        digitalWrite(A,LOW);
        digitalWrite(B,HIGH);
        digitalWrite(C,LOW);
        digitalWrite(D,LOW);
                        }
           if(conteo==3){ //condicion si la suma es 3 activa en vinario el numero 3
        digitalWrite(A,HIGH);
        digitalWrite(B,HIGH);
        digitalWrite(C,LOW);
        digitalWrite(D,LOW);
                        }
           if(conteo==4){ //condicion si la suma es 4 activa en vinario el numero 4
        digitalWrite(A,LOW);
        digitalWrite(B,LOW);
        digitalWrite(C,HIGH);
        digitalWrite(D,LOW);
                        }
           if(conteo==5){ //condicion si la suma es 5 activa en vinario el numero 5
        digitalWrite(A,HIGH);
        digitalWrite(B,LOW);
        digitalWrite(C,HIGH);
        digitalWrite(D,LOW);
          }
       }
    }
}
