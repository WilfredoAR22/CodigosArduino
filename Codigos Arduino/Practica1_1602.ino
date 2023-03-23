/*
Una empresa de gaseosas tiene un sistema con dos sensores, 
uno de ellos indica si la botella se ha llena- do con el líquido y el 
otro sensor indica si la botella ya tiene la tapa. Para este caso simularemos 
los dos sensores por medio de dos pulsadores (S1 y S2). La rutina se describe de esta manera: 
si la botella se llena de manera adecuada (se debe activar S1 y mostrar por consola ―Gaseosa llena) 
luego de ello si tiene la tapa colocada (se debe activar S2 y mostrar por consola ―Gaseosa tapada), 
al finalizar el proceso se debe encender un LED que indica que el proceso terminó bien y 
además se debe mostrar un mensaje por la consola ―Gaseosa bien empacada. 
Recuerde que primero se debe activar S1 y luego S2 para que le proceso sea válido.
*/

int pulsador1 = 2;
int pulsador2 = 3;
int led = 13;

/*Variables auxiliares para verificar
  que sensores se han activado
*/
int aux1=0,aux2=0;

void setup()
{
  pinMode(led,OUTPUT);
  pinMode(pulsador1,INPUT);
  pinMode(pulsador2,INPUT);
  Serial.begin(9600);
}

void loop()
{
  //Cuando el S1 se active y muestre solo 1 vez el mensaje
  if(digitalRead(pulsador1)==0 && aux1==0){
    Serial.println("Gaseosa llena");
    aux1=1;
  }
  //Cuando S2 se active después de S1 y muestre 1 vez el mensaje
  else if(digitalRead(pulsador2)==0 && aux1==1 && aux2==0){
    Serial.println("Gaseosa tapada");
    aux2=1;
  }
  //Cuanso S1 y S2 se hayan activado
  else if(aux1==1 && aux2==1){
    digitalWrite(led,HIGH);
  	Serial.println("Gaseosa bien empacada");
    aux1=0;
    aux2=0;
  }
  delay(1000);
}