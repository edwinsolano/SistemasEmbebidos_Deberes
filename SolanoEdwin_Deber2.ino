/*
 * UNIVERSIDAD TÉCNICA DEL NORTE
 * FICA-CITEL
 * Nombre: Solano Edwin
 * Materia: Sistemas Embebidos
 * DEBER #2: contador de números primos de 0 a 99
 * CÓDIGO: uso Arduino uno, display 7 segmentos, multiplexor 7447, pull down.
 * Objetivo: se obtiene un numero primo contando de 0 a 99 accionando un botón.
 */


 const int A= 8; // pin 8 conectado al decodificador 7447
 const int B= 9; // pin 9 conectado al decodificador 7447
 const int C=10; // pin 10 conectado al decodificador 7447
 const int D=11; // pin 11 conectado al decodificador 7447
 const int display1=12; // pin de activación display unidades
 const int display2=13; // pin de activación display decenas
 const int boton=7; //pin 7 configurado como entrada
 int uni=0; //variable unidades
 int dec=0;  //variable decenas
 int cont=1; //variable de conteo
 int decenas=13;
  int unidades=12;
  int i;
  bool primo;

void setup(){
  pinMode(A,OUTPUT); // pin 8 salida
  pinMode(B,OUTPUT); // pin 9 salida
  pinMode(C,OUTPUT); // pin 10 salida
  pinMode(D,OUTPUT); // pin 11 salida
  pinMode(display1,OUTPUT); // pin 12 salida
  pinMode(display2,OUTPUT); // pin 13 salida
  pinMode(boton,INPUT); // pin 7 entrada
}

void loop(){
if (digitalRead (boton)==HIGH){// condición que detecte el boton en alto
  delay(100);
    cont++;
    primo = true; //detecta el valor en boleano si es primo
    for (i=2; i<cont; i++){ //ciclo repetitivo contador 
    if (cont%i == 0){ //condicionante con el residuo detencta si el nuemro no es primo
    primo = false;//condicion que cumple la anterior
    }
        }if(primo){ //si el condicionate es verdadero cuenta
            dec=cont/10; 
            uni=cont-(dec*10);              
    }
      digitalWrite(decenas,HIGH); //activa el pin 13 
      digitalWrite(unidades,LOW); //apaga el pin 12
      segmentos(dec);             //llamar al metodo
      delay(100);                 //temporizador
      digitalWrite(decenas,LOW);   //apaga el pin 13
      digitalWrite(unidades,HIGH);  //activa el pin 12
      segmentos(uni);               //llama al metodo
      delay(100);                   //temporizador
  }
}
void segmentos (int i){             //metodo
   switch(i){  //casos para los binarios
        case 0: //binario numero 0
          digitalWrite(A,LOW); 
          digitalWrite(B,LOW); 
          digitalWrite(C,LOW); 
          digitalWrite(D,LOW); 
        break;
        case 1://binario numero 1
          digitalWrite(A,HIGH); 
          digitalWrite(B,LOW);  
          digitalWrite(C,LOW);  
          digitalWrite(D,LOW);  
        break;
        case 2: //binario numero 2
          digitalWrite(A,LOW);  
          digitalWrite(B,HIGH); 
          digitalWrite(C,LOW);  
          digitalWrite(D,LOW);  
        break;
        case 3: //binario numero 3
          digitalWrite(A,HIGH); 
          digitalWrite(B,HIGH); 
          digitalWrite(C,LOW);  
          digitalWrite(D,LOW);  
        break;
        case 4: //binario numero 4
          digitalWrite(A,LOW);  
          digitalWrite(B,LOW);  
          digitalWrite(C,HIGH);
          digitalWrite(D,LOW);  
        break;
        case 5: //binario numero 5
          digitalWrite(A,HIGH); 
          digitalWrite(B,LOW);  
          digitalWrite(C,HIGH); 
          digitalWrite(D,LOW); 
        break;
        case 6: //binario numero 6
          digitalWrite(A,LOW);  
          digitalWrite(B,HIGH); 
          digitalWrite(C,HIGH); 
          digitalWrite(D,LOW);  
        break;
        case 7: //binario numero 7
          digitalWrite(A,HIGH); 
          digitalWrite(B,HIGH); 
          digitalWrite(C,HIGH);
          digitalWrite(D,LOW);  
        break;
        case 8: //binario numero 8
          digitalWrite(A,LOW); 
          digitalWrite(B,LOW); 
          digitalWrite(C,LOW); 
          digitalWrite(D,HIGH); 
        break;
        case 9: //binario numero 9
          digitalWrite(A,HIGH); 
          digitalWrite(B,LOW);  
          digitalWrite(C,LOW);  
          digitalWrite(D,HIGH); 
        break;
      }
  }

  
   
  
