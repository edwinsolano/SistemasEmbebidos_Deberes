/*
*UNIVERSIDAD TECNICA DEL NORTE
*FICA-CITEL
*SISTEMAS EMBEBIDOS
*Nombre: Solano Edwin
*Deber 10 
* objetivo: interfaz que permita mover una esfera por toda la pantalla mediante teclas
*/

float radio=40.0; //radio de la esfera 
int y1=100;//movimeinto eje y
int x1=100;//movimeinto eje x

void setup(){
 size(1000,700); //tamaño de pantalla
 ellipseMode(RADIUS);//mostrar esfera
}
void draw(){
  background(127,1,0);//color de fondo 
  textSize(25);//tamaño de texto
  fill(0,255,0);//color de la esfera
  text("Solano Edwin",50,40);//texto y posicion
  ellipse(x1,y1,radio,radio);//creacion de esfera
  
  if(keyPressed){
     if(key=='8' || key=='w'){//movimeinto hacia arriba
        if(y1>100){//tamaño del movimeinto
          y1=y1-5;//saltos
        }
        }else if(key=='2' || key=='s'){//movimiento hacia abajo
         if(y1<980){//tamaño del movimeinto
            y1=y1+5; //saltos
          }
        }
     }  
   if(keyPressed){
     if(key=='6' || key=='d'){//movimeinto hacia la izquierda
        if(x1<980){//tamaño del movimeinto
          x1=x1+5;//saltos
        }
        }else if(key=='4' || key=='a'){//movieminto hacia la derecha
         if(x1>100){//tamaño del movimeinto
            x1=x1-5; //saltos
          }
        }
     }
  }
