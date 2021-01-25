/*
 * UTN-FICA-CITEL
 * SISTEMAS EMBEBIDOS 
 * DEBER 12 
 * Nombre: Solano Edwin
 * 
*/
//******************LOGICA************************
/*
   CLASIFICADOR BAYESIANO
   --> saber cuantas etiquetas tiene el conjunto de datos
   -->el #filas y el #columnas

   etiquetas: 1,2,3,4
   P(1)-->sumatoria de elementos con etiqueta 1 y dividir para total de filas
   P(2)-->sumatoria de elementos con etiqueta 2 y dividir para total de filas
   P(3)-->sumatoria de elementos con etiqueta 3 y dividir para total de filas
   P(4)-->sumatoria de elementos con etiqueta 4 y dividir para total de filas

   P(X)-->sumatoria de elementos de circunferencia y dividor para el total de filas
 *        *Encontrar la circunferencia: se debe encontrar la distancia entre el nuevo dato y la base da datos
                                        se encuentra el mayor dato y divido para el resto de datos
                                        definir el radio de la circunferencia (0,1)
   P(X/1)-->sumatoria de todos los elementos que se encuentran el la circunferencia con etiqueta 1 y
            dividir para las instancias de la misma etiqueta
   P(X/2)-->sumatoria de todos los elementos que se encuentran el la circunferencia con etiqueta 2 y
            dividir para las instancias de la misma etiqueta
   P(X/3)-->sumatoria de todos los elementos que se encuentran el la circunferencia con etiqueta 3 y
            dividir para las instancias de la misma etiqueta
   P(X/4)-->sumatoria de todos los elementos que se encuentran el la circunferencia con etiqueta 4 y
            dividir para las instancias de la misma etiqueta
   P(1/X)=[P(1)*P(X/1)]/P(X)
   P(2/X)=[P(2)*P(X/2)]/P(X)
   P(3/X)=[P(3)*P(X/3)]/P(X)
   P(4/X)=[P(4)*P(X/4)]/P(X)

   -->Encontrar el mayor valor

*/
//******************sumatoria***************
#include "datos.h"
#include "ListLib.h"
List<int> list;
char respuesta;
float sumatoria;
float distancia;
float distanciaMayor = 0.1;
float normalizador;
float p_x;
float aux = 0.0;
float resultado;
float datos_prueba[5] = {616.00,544.00,0.00,0.00,4.00};
void setup() {
  Serial.begin(9600);
  bayes(4, 35, 5, 0.1);
}

void loop() {
}

void bayes(int tags, int filas, int columnas, float r) {
  float sum1, sum2, sum3, sumatoria = 0, distancia_menor = 3000, distancia;
  int cont1 = 0, cont2 = 0, cont3 = 0, drain = 0, source = 0, tag;

  float prob[5][tags];
  //******************encerar matriz de probabilidades***************
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < tags; j++) {
      prob[i][j] = 0;
    }
  }
  //*******************asiganr etiquetas a matriz************
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < tags; j++) {
      prob[i][j] = 0;
      if (i == 0)
        prob[i][j] = j + 1;
    }
  }
  //********************valores a:  P(X/1),P(X/2),P(X/3),P(X/4)******************
  for (int t = 0; t < 5; t++) {
    for (int i = 0; i < filas; i++) {
      if (matriz[i][columnas - 1] == t + 1) {
        prob[1][t]++;
      }
    }
  }

  for (int i = 0; i < filas; i++) {
    for (int j = 0; j < columnas; j++) {
      sumatoria = sumatoria + pow(matriz[i][j] - datos_prueba[j], 2);
    }
    distancia = sqrt(sumatoria);
    sumatoria = 0;
    if (distancia > distanciaMayor)
      distanciaMayor = distancia;
  }

  distancia = 0;

  for (int i = 0; i < filas; i++) {
    for (int j = 0; j < columnas; j++) {
      sumatoria = sumatoria + pow(matriz[i][j] - datos_prueba[j], 2);
    }
    distancia = sqrt(sumatoria);
    normalizador = distancia / distanciaMayor;
    sumatoria = 0;
    if (normalizador < r) {
      list.Add(i);
    }
  }

  for (int i = 0; i < list.Count(); i++) {
    for (int j = 0; j < tags; j++) {
      if (matriz[list[i]][columnas - 1] == prob[0][j])
        prob[2][j]++;
    }
  }
  p_x = list.Count() / float(filas);
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < tags ; j++) {
      prob[4][j] = ((prob[1][j] / filas) * (prob[2][j] / prob[1][j])) / p_x;
    }
  }
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < tags ; j++) {
      if (prob[4][j] > aux) {
        resultado = int (prob[0][j]);
        aux = prob[4][j];
      }
    }
  }
  for (int i = 0; i < 5 - 4; i++) {
    for (int j = 0; j < tags; j++) {
      Serial.print("   ");
      Serial.print(prob[i][j], 0);
      Serial.print("     ");
    }
    Serial.println(" ");
  }
  for (int i = 1; i < 5 - 3; i++) {
    for (int j = 0; j < tags; j++) {
      Serial.print("  ");
      Serial.print(prob[i][j], 0);
      Serial.print("     ");
    }
    Serial.println(" ");
  }
  for (int i = 2; i < 5 - 2; i++) {
    for (int j = 0; j < tags; j++) {
      Serial.print("   ");
      Serial.print(prob[i][j], 0);
      Serial.print("     ");
    }
    Serial.println(" ");
  }
    for (int i = 3; i < 5 - 1; i++) {
    for (int j = 0; j < tags; j++) {
      Serial.print("   ");
      Serial.print(prob[i][j], 0);
      Serial.print("     ");
    }
    Serial.println(" ");
  }
  for (int i = 4; i < 5; i++) {
    for (int j = 0; j < tags; j++) {
      Serial.print(" ");
      Serial.print(prob[i][j], 5);
      Serial.print(" ");
    }
    Serial.println(" ");
  }
  Serial.print("La Etiqueta es: ");
  Serial.print(resultado,0);
}
