// C++ code
//

/*
Tu abuelito tiene un cultivo de grandes y verdes lechugas, este cultivo tiene 3 aspersores de agua 
y tu abuelito quiere prender estos aspersores desde su computador solo escribiendo unos valores 
por teclado, los aspersores tienen un estado digital (Valor 0 es apagado y valor 1 es prendido). 
Debes realizar un programa que lea una cadena de tres valores, para este ejercicio 
los aspersores los vamos a simular con tres LED 1, 2 y 3 por ejemplo:
Si tu abuelito escribe 000 : Todos los aspersores de agua deben estar apagados
Si tu abuelito escribe 101 : El aspersor 1 y 3 se prenden pero el dos debe estar apagado
Si tu abuelito escribe 001 : El aspersor 1 y 2 se apagan pero el tres debe estar prendido
*/


String valores = "";
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
  Serial.println("Ingrese los valores: ");
  while(Serial.available()==0){}
  valores = Serial.readString();
  if(valores[0] == '1'){
    digitalWrite(led1,HIGH);
  }
  else{
  	digitalWrite(led1,LOW);
  }
     
  if(valores[1] == '1'){
    digitalWrite(led2,HIGH);
  }
  else{
  	digitalWrite(led2,LOW);
  }
             
  if(valores[2] == '1'){
    digitalWrite(led3,HIGH);
  }
  else{
  	digitalWrite(led3,LOW);
  }
  delay(1000);
}
