/*
 * UTN-FICA-CITEL
 * SISTEMAS EMBEBIDOS 
 * CODIGO: APRENDIZAJE DE MAQUINA-REGRESION EXPONENCIAL
 * DEBER 11
 * Nombre: Solano Edwin
 * OBJETIVO: generar modelo de regresion exponencial recibir datos por cx
 * 
 */
//matriz de datos
int matriz[14][2]={
  {170,67},
  {180,80},
  {170,65},
  {178,75},
  {160,55},
  {163,60},
  {165,63},
  {170,70},
  {164,62},
  {176,77},
  {164,60},
  {170,76},
  {170,56},
  {168,60},
};
int col=0;//moverse en columnas
int fil=0;//moverse en filas
float Elog_Y=0;//sumatoria del log de y
int Ex=0;//sumatoria de x
int Ey=0;//sumatoria de y
float logA;//log de del valor de A
float Exy=0;//sumatoria de xy
long int Ex2=0;//sumatoria de x^2
long int Ex_2=0;//sumatoria de sumatoria de x^2
int n=14;//tamaño de la muestra
float Bo;//ordenada en el origen
float A;//resultado
String dato;//recibir estatura
int estatura;//convertir dato
float peso;
float m1=0;//aux

void setup() {
  Serial.begin(9600);
  //creacion del modelo
  for(;fil<n;fil++){
    Ex=Ex+matriz[fil][0];
    Elog_Y=Elog_Y+log(matriz[fil][1]);//matriz con resultados logaritmicos
    Exy=Exy+(matriz[fil][0]*log(matriz[fil][1]));
    Ex2=Ex2+pow(matriz[fil][0],2);
  }
  Ex_2=pow(Ex,2);//elevar al cuaddrado la sumatoria de x
  Bo=(float(n*Exy)-float(Ex*Elog_Y))/(float(n*Ex2)-float(Ex_2));//calculo de ordenada en el origen con el dato obtenido
  m1=Bo*(Ex/n);//auxiliar de desborde
  logA=float(Elog_Y/n)-float(m1);
  A=float(exp(logA));
  Serial.println("El modelo es:");
  Serial.println(String("y = ")+String(A)+String("*")+String("e^(")+String(Bo)+String("*x)"));
  Serial.println("Ingrese su estatura: ");

}

void loop() {
  if(Serial.available()>0){
    dato=Serial.readString();
    estatura=dato.toInt();
    peso=A*exp(Bo*estatura);
    Serial.println(" ");
    Serial.println(String("SU PESO ES: ")+String(peso)+String("Kg"));
    Serial.println("Ingrese su estatura: ");
  }
}
