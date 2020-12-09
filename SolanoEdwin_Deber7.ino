/*
 * UTN-FICA-CITEL
 * sistemas embebidos 
 * deber 7
 * Nombre: Solano Ediwn
 * 
 * objetivo: Realiza un programa que valide y actualice una contraseña almacenada en la memoria EEPROM. 
 *           Como estado inicial, la contraseña es de 4 dígitos que son: 4563. 
 *funciones: libreria EEPROM
 *           attachInterrupt(0,activacion,LOW)
 */
 #include<EEPROM.h>

int pw;//variable para el pw
int on=0;//inicio de interrupciones
int contra;//variable para guardar contraseña
String dato;//variable para pedir dato 
int pass=4563;//contraseñaattachInterrupt(0,activacion,LOW) inicial

void setup(){
  

  Serial.begin(9600);//CX
  EEPROM.get(0,pw);//inicio EEPROM
  attachInterrupt(0,activacion,LOW);//metodo para interrupciones
  
}
void loop(){
  

  if(on==1){//primera interrupcion
    
    if(Serial.available()>0){//verificar si existe dato
      dato=Serial.readString();//ler dato de CX
       contra=dato.toInt();//guardar el valor del dato en la variable contra
    }
    pw=contra;//comparacion
  }
  if(on==2){
    if(pw==pass){//si la contraseña ingresada coicide
      Serial.println("la contrasena es correcta");//mensaje
       delay(500);//temporizador 
    }
    
    if(pw!=pass){//si la contraseña ingresada no coincide
      Serial.println("la contrasena es incorrecta");//mensaje
       delay(500);//temporizador 
    }
  }
      if(on==3){//crear nueva contraseña
         if(Serial.available()>0){//verificar si existe dato
           dato=Serial.readString();//ler dato de CX
            contra=dato.toInt();//guardar el valor del dato en la variable contra
      }
      pw=contra;//comparacion 
      EEPROM.update(0,pw); //guardar la contraseña en la EEPROM 
      pass=pw;//contrasñea nueva
  }
}


void activacion(){//metodo para interrupcinoes
  
  switch(on){//menu
    
    case 0://interrupcion
      Serial.println("UTN_FICA_CITEL");//mensaje en CX
      Serial.println("Solano Edwin");//mensaje en CX
      Serial.println("INICIO DE SISTEMA");//mensaje en CX
      Serial.println("ingrese PASSWORD");//mensaje en CX
      on++;//contador
    break;
    
    case 1://interrupcion
    
      Serial.println("validando... ");//mensaje en CX
      Serial.println("su contraseña es: ");//mensaje en CX
      on++;//contador
    break;
    
    case 2://interrupcion
      Serial.println("cambiar PASSWORD");//mensaje en CX
      Serial.println("Ingrese nuevo PASSWORD");//mensaje en CX
      on++;//contador
    break;
    
    case 3://interrupcion reicnicio de sistema 
      Serial.println("se ha guardado el nuevo PASSWORD");//mensaje en CX
      Serial.println(" ");//mensaje en CX
      on=0;//reincio de variable 
      contra=0;//reincio de variable
      pw=0;//reincio de variable
    break;
  }
}
