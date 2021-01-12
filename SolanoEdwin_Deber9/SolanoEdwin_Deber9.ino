/*
 *UNIVERSIDAD TECNICA DEL NORTE
 *FICA-CITEL
 *SISTEMAS EMBEBIDOS
 *Nombre: Solano Edwin 
 *deber 9
 *objetivo: Realizar un programa que mediante un conversor análogo-digital se configure el tiempo de reinicio del perro guardián 
 *(tiempos seleccionados por el usuario). Envíe mensajes por comunicación serial validando todo el proceso.
 */
#include <avr/wdt.h>
#include<MsTimer2.h>

int i=0;
int cont=0;
int on=0;
int btn1;
int reinicio;

void setup(){
  Serial.begin(9600);//coneccion con CX
  MsTimer2::set(1000,reloj);//reloj cada segundo
  attachInterrupt(0,activacion,LOW);//interrupcion para activacion
}
void loop() {
 if(on==2){//interrupcion 2 hacer 
  conversor();//llamar al metodo
 }
}
void activacion(){//interrupciones
  switch(on){//menu
    case 0://caso 1
      Serial.println("Tiempo de reinicio: ");
      on++;//contador
    break;
    case 1:
      Serial.println("Tiempo: ");//tiempo de reinicio
      on++;//contador
    break;
    case 2:
      MsTimer2::start();//inicia el relog
      on++;//contador
    break;
    case 3:
      Serial.println("power OFF");
      on=0;//reinicio de variables
      MsTimer2::stop();//reinicio del reloj
    break;
  }
  }
void reloj() {
  cont++;//contador 
 Serial.println(String("time: ")+String(cont));//mensaje del reloj
  if (cont>=reinicio){//cuando el tiempo de conteo sea igual que de reinicio hacer
  wdt_disable();//desactivar perro guardian
  wdt_enable(WDTO_500MS);//activar perro guardian en 4 segundos
  }
}
void conversor(){
       btn1=analogRead(0);//lectura del pin analogo
       btn1=map(btn1,0,1023,0,500);//conversor a segundos 
       reinicio=btn1;//guarda el dato en la variable reinicio
       Serial.println(String("Reinico en: ")+String(reinicio)+String(" segundos"));
       delay(2000);//temporizador   
}
