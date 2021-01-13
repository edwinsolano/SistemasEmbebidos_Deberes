/*
 *UNIVERSIDAD TECNICA DEL NORTE
 *FICA-CITEL
 *SISTEMAS EMBEBIDOS
 *Nombre: Solano Edwin 
 *deber 8
 *objetivo: Realizar un código que el sistema se reinicia cada minuto, 
 *active el conversor análogo-digital realice una lectura y vuelve el sistema a un modo sleep.
 */
 #include<avr/power.h>
 #include<avr/sleep.h>
 #include<avr/wdt.h>
 #include<MsTimer2.h>

int on=0;
int tiempo=60;
int cont=0;

void setup() {
  Serial.begin(9600);//conexion con CX
  MsTimer2::set(200,reloj);//configuacuon de tiempo de relog
  attachInterrupt(0,activacion,LOW); //interrupciones 
}
void loop() {  
}
void activacion(){
  switch(on){//casos segun interrupcion 
    case 0://caso uno 
      Serial.println("Tiempo del CAD");//mensaje
      power_adc_disable();//perro guardian desacivado
      on++;//contador 
    break;
    case 1://caso dos
      Serial.println(String("Inicio en:")+String(tiempo)+String(" segundos"));
      MsTimer2::start();//inicio del relog
      on++;//contador 
    break;
    case 2://caso tres
      Serial.println("power OFF");
      tiempo=60;//inicia variable a condicion inicial
      on=0;//reinicio de modo
      MsTimer2::stop();//apagado del reloj
      power_adc_disable();//apagado del perro guardian
    break;
  }
}
void reloj(){
  cont++;//contador
  power_adc_disable();//perro guardian desactivado
  Serial.println(String("lectura: ")+String(tiempo-cont));
  if(cont==tiempo){//cuando el tiempo sea igual al contador
    power_adc_enable();//perro guardian se activa
    delay(20);//temporizador
    Serial.println(String("lectura poteciometro: ")+String(analogRead(0)));//mensaje y lectura del pin analogo
    delay(1000);//temporizador
    cont=0;//reinicio del contador
  }
}
