/*
* UNIVERSIDAD TECNICA DEL NORTE
* FICA_CITEL
* SISTEMAS EMBEBIDOS
* Nombre: Solano Edwin
* Deber 4 esclavo
* Objetivo: enviar un dato al esclavo por comunicacion i2c y cambiar las vocales por caracteres 
 */
          #include <Wire.h> //libreria para i2c7
           char valor;  //variable para valor ingresado
           String letra; //variable para asiganr a la letra
           String rece;  //variable para dato recibido
void setup() {
  Wire.begin(4);//cx i2c
  Serial.begin(9600);//cx serial
  Wire.onReceive(receiveEvent); //evento de recepcion de mensajes
  Wire.onRequest(requestEvent);//evendo de envio de mensajes
}
void loop() {
  delay(100);    //temporizador
}
void receiveEvent(int bytes){ //metodo para recepcion de datos
            while(Wire.available()){//verifica si existe dato
                char frase=Wire.read(); //asigna dato leido a la variable 
                    switch(frase){//valor del dato para hacer una comparativa 
                    case 'a':
                        letra=letra+"@"; //caso uno cambiar a por @
                    break;
                    case 'e':
                        letra=letra+"#"; // caso dos cambiar e por  #
                    break;
                    case 'i':
                        letra=letra+"!"; //caso tres cambiar i por !
                    break;
                    case 'o':
                        letra=letra+"*"; //caso cuatro cambiar o por *
                    break;
                    case 'u':
                        letra=letra+"$"; //caso cinco cambiar u por $
                    break;
                    //asignacion de cada consonante correspondiente en su lugar y del mismo valor
                    case 'b':
                        letra=letra+"b"; 
                    break;
                    case 'c':
                        letra=letra+"c";
                    break;
                    case 'd':
                        letra=letra+"d";
                    break;
                    case 'f':
                        letra=letra+"f";
                    break;
                    case 'g':
                        letra=letra+"g";
                    break;
                    case 'h':
                        letra=letra+"h";
                    break;
                    case 'j':
                        letra=letra+"j";
                    break;
                    case 'k':
                        letra=letra+"k";
                    break;
                    case 'l':
                        letra=letra+"l";
                    break;
                    case 'm':
                        letra=letra+"m";
                    break;
                    case 'n':
                        letra=letra+"n";
                    break;
                    case 'p':
                        letra=letra+"p";
                    break;
                    case 'q':
                        letra=letra+"q";
                    break;
                    case 'r':
                        letra=letra+"r";
                    break;
                    case 's':
                        letra=letra+"s";
                    break;
                    case 't':
                        letra=letra+"t";
                    break;
                    case 'v':
                        letra=letra+"v";
                    break;
                    case 'w':
                        letra=letra+"w";
                    break;
                    case 'x':
                        letra=letra+"x";
                    break;
                    case 'y':
                        letra=letra+"y";
                    break;
                    case 'z':
                        letra=letra+"z";
                    break;
    }
    
   }
      Serial.println(letra);//impresion del la palabra
          while(Serial.available()>0) {//verifica si existe dato
            rece=Serial.read();//lo asigna a una variable el dato ledio 
                                    }
}

void requestEvent() {//metodo para enviar dato
  while(Serial.available()>0){//verifica si existe dato
    valor=Serial.read(); //asigna a una variable el dato
    Serial.println("dato enviado");  //impreison de mensaje enviado
        Wire.beginTransmission(4); //enviar informacion al master con id 4
        Wire.write(valor); //valor a enviar
        Wire.endTransmission();  //fin de la trasmision
  }
}
