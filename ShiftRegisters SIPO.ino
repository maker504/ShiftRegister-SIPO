

//IOs
//Entradas
int IVel=3; //Lectura de la Velocidad del efecto
//Salidas
int OLatch=0; //Outputs Latch pin
int OClock=1; //Outputs Clock pin
int OData=2;  //Outputs Data pin

//Variables
int Pos=0; //Posicion del LED a encender
int Arreglo=1; //Arreglo de los 8 bits para el display
int Dir=1; //Direccion del efecto 0=Izq, 1=Der
//int Vel=0; //Velocidad del efecto
int DMove=200; //ms para hacer el cambio al sgte LED
unsigned long TMove=0; //Momento en que se hizo el cambio

//Valores en binario para la salida de cada bit

//int Estado[]={7,14,28,56,112,224};
//int Estado[]={1,2,4,8,16,32,64,128}; 
int Estado[]={3,6,12,24,48,96,192};
void setup() 
{
  //Salidas
  pinMode(OLatch, OUTPUT);
  pinMode(OClock, OUTPUT);
  pinMode(OData, OUTPUT);
}

void loop() 
{
  Pos=Pos+Dir; //Incrementamos la posicion
  if(Pos==6)Dir=-1; //Comenzamos a restar
  if(Pos==0)Dir=1; //Comenzamos a sumar
  
  digitalWrite(OLatch, LOW); //OLatch LOW para mantener los valores actuales
  shiftOut(OData, OClock, MSBFIRST, Estado[Pos]); //Salida de datos
  digitalWrite(OLatch, HIGH); //Actualizamos el valor

  DMove=map(analogRead(IVel),0,1023,20,200);
  delay(DMove);

}
