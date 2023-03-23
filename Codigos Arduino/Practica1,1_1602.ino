// C++ code
//
int p1 = 2;
int p2 = 3;
int led = 13;

//Variable velocidad
int vel=0;
//Variable que guarda la velocidad hasta cargar
int aux=0;

void setup()
{
  pinMode(led,OUTPUT);
  pinMode(p1,INPUT);
  pinMode(p2,INPUT);
  Serial.begin(9600);
}

void loop()
{
  
  //Imprimir el valor de la variable
  Serial.println(aux);
  //Cuando S1 se presiona aumenta +20 la variable 'vel'
  if(digitalRead(p1)==0 && digitalRead(p2)==1){
    aux+=20;
  }
  //Cuando S2 se presiona se carga el 'aux' a 'vel'
  else if(digitalRead(p2)==0 && digitalRead(p1)==1){
    vel=aux;
  }
  //Reset
  else if(digitalRead(p1)==0 && digitalRead(p2)==0){   
  	vel=0;
    aux=0;
  }
  //Encender y apagar con el valor 'vel'
  digitalWrite(led,HIGH);
  delay(vel);
  digitalWrite(led,LOW);
  delay(vel);
}