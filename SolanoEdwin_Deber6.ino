/*
 * UTN-FICA-CITEL
 * sistemas embebidos 
 * deber 6
 * Nombre: Solano Edwin
 *  objetivo: Realizar un reloj con alarma ingresada por comunicación serial.  
 *            Los números sean vistos en displays.
 *            
 */
 #include<MsTimer2.h>
 #include<LiquidCrystal.h>
 const int btnh=4;//boton horas
 const int btnm=5;//boton minutos
 const int led1=6;//encendido de led
 int horas=0;//variable inciio horas
 int minutos=0;//varibale inicio minutos 
 int segundos=0;//variable inicio segundos
 int on=0;//variable interrupciones 
 String datoH;//variable recibir dato de horas CX
 String datoM;//variable recibir dato de minutos CX
 int HH=0;
 int MM=0;
 LiquidCrystal lcd(13,12,11,10,9,8);//asignacion de pines para display
 
 void setup(){
 lcd.begin(16,4);//tamapo del lcd
 Serial.begin(9600);//CX
 pinMode(led1,OUTPUT);//led 1 como salida
 pinMode(btnh,INPUT);//boton horas como entrada
 pinMode(btnm,INPUT);//boton minutos como entrada
 MsTimer2::set(1000,reloj);//contador del reloj
 MsTimer2::start();//inciar el reloj
 attachInterrupt(0,activacion,LOW); //interrupciones
 }

 void loop(){
  if(on==1){//interrupcion uno pedir horas 
    if(Serial.available()>0){//ver si existe dato
      datoH=Serial.readString();//leer el dato
      HH=datoH.toInt();//guardar el dato en la variable
    }
  }
  if(on==2){//interrupcion para pedir minutos 
    if(Serial.available()>0){//ver si existe dato
      datoM=Serial.readString();//leer el dato
      MM=datoM.toInt();//guardar el dato en la variable
    }
  }
  if(on==3){//interrucpcion para mostrar alarma
     lcd.setCursor(0,2);//posisicon del cursor
     lcd.print(String(HH)+String(":")+String(MM));//impresion de alarma
  }
alarma();//metodo donde activa la alarma
 }

 void reloj(){//reloj contador
  if(segundos<60){
    segundos++;
  }
  else{
    segundos=0;
    if(minutos<60)
      minutos++;
    else{
      minutos=0;
      if(horas<24)
      horas++;
      if(horas==24){   
      }
      else
      horas=0;
    }
  }
  if(digitalRead(btnh)==HIGH){//boton para aumentar horas
    horas++;//incremento
  }
  if(digitalRead(btnm)==HIGH){//boton para aumentar minutos 
    minutos++;//incremento
  }
  lcd.clear();//limpiar lcd
  lcd.setCursor(0,0);//posicion del cursor
  lcd.print("la hora es: ");//imprecion en la lcd
  lcd.setCursor(0,1);//posicion del cursor
  lcd.print(String(horas)+String(":")+String(minutos)+String(":")+String(segundos));//impresion de la hora en la lcd
 }

 void activacion(){//metodo para las interrcupciones
  switch(on){
    case 0://mostrar en pantalla
    Serial.println("UTN-FICA-CITEL");
    Serial.println("reloj con alarma");
    Serial.println("ingrese horas de 0 a 24");
    on++;
    break;
    case 1://mostrar en CX
    Serial.println("reloj con alarma");
    Serial.println("ingrese minutos de 0 a 59");
    on++;
    break;
    case 2://mostrar en lcd
     on++;
    break;
    case 3://reinciar variables
    Serial.println("configurar nueva alarma");
    HH=0;
    MM=0;
    on=0;
    break;
  }
 }

 void alarma(){//metodo para alarma
  if(HH==horas && MM==minutos){//comparacion de datos
    for(int i=0;i<10;i++){//ciclo repetitivo para encer el led simulando alarma encendida 
      digitalWrite(led1,HIGH);//led encendido
      delay(300);//temporizador
      digitalWrite(led1,LOW);//led apagado
      delay(300);//temporizador
    }
  }
 }
 
 
