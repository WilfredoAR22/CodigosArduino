// C++ code
//

/*
Avisos luminosos S.A. te ha contratado para que realices un programa que tiene 
la característica de recibir datos, porque la idea es que el aviso de luces 
se ubique en el piso 130 del Edificio Bulli y tu lo puedas controlar desde el piso 1, 
así que por cada letra que le escribas por teclado a la Consola serial el programa 
debe hacer determinada rutina con tres LEDs, si le escribes:
-Letra A: Prende los tres LED

-Letra B: Prende el LED1 por un segundo y lo apaga, luego prende el LED2 por un segundo y lo apaga y finalmente prende el LED3 por un segundo y lo apaga, y vuelve a comenzar. Esta rutina genera una sensación de movimiento.

-Letra C: Apaga los tres LED
*/


String letra = "";
int led1 = 13;
int led2 = 12;
int led3 = 10;
void setup()
{
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  Serial.println("Ingrese una rutina: ");
  while(Serial.available()==0){
    if(letra == "B" || letra == "b")
      RutinaB();
  }
  letra = Serial.readString();
  if(letra == "A" || letra == "a"){
    RutinaA();
  }
  else if(letra == "B" || letra == "b"){
  	RutinaB();
  }
  else if(letra == "C" || letra == "c"){
  	RutinaC();
  }
  else{
  	Serial.println("Error: Rutina no reconocida");
  }
}

void RutinaA(){
	digitalWrite(led1,HIGH);
  	digitalWrite(led2,HIGH);
  	digitalWrite(led3,HIGH);
}

void RutinaB(){
	digitalWrite(led1,HIGH);
  	delay(1000);
  	digitalWrite(led1,LOW);
  	digitalWrite(led2,HIGH);
  	delay(1000);
  	digitalWrite(led2,LOW);
  	digitalWrite(led3,HIGH);
  	delay(1000);
  	digitalWrite(led3,LOW);
}

void RutinaC(){
	digitalWrite(led1,LOW);
  	digitalWrite(led2,LOW);
  	digitalWrite(led3,LOW);
}