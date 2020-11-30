/*
* UNIVERSIDAD TECNICA DEL NORTE
* FICA_CITEL
* SISTEMAS EMBEBIDOS
* Nombre: Solano Edwin
* Deber 4 Master
* Objetivo: enviar un dato al esclavo por comunicacion i2c y cambiar las vocales por caracteres 
 */
    #include <Wire.h>  //comunicacion por i2c
    #include<LiquidCrystal.h>//librecia para display 16x2
    LiquidCrystal lcd(13,12,11,10,9,8);  //variable y asisganicion de pines
    char valor;  //variable para valor ingresado
    String letra; //variable para asiganr a la letra
    String rece;  //variable para dato recibido

void setup() {
  Wire.begin();  //cx i2c
    Serial.begin(9600);  //cx serial
      lcd.begin(16,2); //lcd 
      lcd.setCursor(0,0);//posisiicon del cursor
         Wire.onReceive(receiveEvent);  //evento de recepcion de mensajes
}

void loop() {
  if(Serial.available()>0){//verifica si existe dato
    valor=Serial.read();  //lee el valor
        Wire.beginTransmission(4); //enviar informacion al esclavo con ide 4
        Wire.write(valor); //envio de dato
        Wire.endTransmission();  //fin de la treasmision
  }
    lcd.setCursor(2,1); //psoicion del cursor del lcd
    delay(100); //temporizador
    lcd.println(rece);//imprecion de dato recibido
    delay(1000);//temporizador
            }

void receiveEvent(){ //metodo de rececion
        while(Wire.available()){ //verifica si existe dato
          char frase=Wire.read(); //lee el valor del dato y lo asina a la varible
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
   Serial.println(letra);//iprsion del valor final de la palabra
    Wire.requestFrom(4,4);//solicitud de mensaje
   while(Serial.available()) {//verifica si existe dato
      Serial.println("mensaje recibido"); //mensaje de recibido
        char c=Wire.read(); //asignacion a una variable el mensaje
           Serial.println(c);//impreison en la comuinicacion serial
              lcd.clear();//limpiar el lcd
              lcd.setCursor(1,0); //posicion del lcd
              lcd.println(c);//impresion del lcd
                delay(1000);//temporizador
   }
}
