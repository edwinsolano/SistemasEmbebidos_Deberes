/*
 * UTN_FICA-CITEL
 * sitemas embebdios 
 * deber 5
 * Nombre: Solano Edwin
 * 
 * objetivo: Realizar un programa que mediante interrupciones tenga 3 modos: 
 *           Inicio del sistema
 *           giro de motor y fin de programa. 
 *           El giro debe ser ingresado por comunicación serial. 
 *           
 */
 #include<Servo.h>//llamar a la libreria para controlar servo
 Servo servo;//inicio del objeto servo
 String dato;//variable para el dato ingresado por comunicacion serial
 int giro; //varibale para guardar el giro
 int on=0;//inicio para las interruociones 
 int inicio=0;//inicio del servo
 
 void setup(){
  servo.attach(6);//pin de arranque del servomotor
  Serial.begin(9600);//comunicacion serial
  attachInterrupt(0,activacion,LOW);//interrupciones
 }

 void loop(){
  if(on==1){//condicion de arranque
    servo.write(inicio);
    if(Serial.available()>0){//si existe algun dato 
      dato=Serial.readString();//leer el dato ingresado en CX
      giro=dato.toInt();//en la variable giro guardar el dato 
    }
    if(giro<180){//si el valor ingresado esta entre las codiciones
      servo.write(giro);//valor que toma el servo
    }
    else{
      Serial.println("ERROR! dato ingresado no corresposnde");//mensaje de error
    }
    delay(100);//temporizador
  }
 }
 void activacion(){//metodo para las interrupciones
  switch(on){//menu de interrupciones
    case 0://imprimir en la primera interricicion
    Serial.println("UTN_FICA_CITEL");
    Serial.println("inicio sistema servo");
    Serial.println("ingrese valores correspondidos entre 0 y 180");
    on++;//aumento en la variable
    break;
    case 1://imprimir en la segunda interrucpcion
    Serial.println("giro del servo");//mensaje
    Serial.println(String("grados ")+String(giro));//impresion de los grados
    on++;//aumento de variable 
    break;
    case 2://apagar el sistema reinciar todas las variables
    Serial.println("POWER OFF");
    servo.write(inicio);//reinicio del servo 
    on=0;//reinicio de las interrupciones
    break;
  }
 }
