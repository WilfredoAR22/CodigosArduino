// C++ code
//
int AWrandom = random(1,1023);
int num,valor,intentos=3;
int pulsador = 4;
void setup()
{
  pinMode(pulsador,INPUT);
  Serial.begin(9600);
}

void loop()
{
  Serial.println(AWrandom);
  delay(2000);
  while(digitalRead(pulsador)==1){
    valor = analogRead(A0);
    Serial.println(valor);
  }
  if(AWrandom-valor>=-10 && AWrandom-valor <=10){
    Serial.println("Adivinaste el numero. Alfredo y Wilfredo");
    intentos=3;
  }
  else if(intentos>1){
    intentos--;
    Serial.print("Te quedan ");
    Serial.print(intentos);
    Serial.println(" intento(s)");
    delay(1000);
  }
  else{
    intentos=3;
    AWrandom = random(0,carne());
  }
  delay(500);
}

int carne()
{
  int carne1;
    int carne2;
    int numc,fnum;
    Serial.println("Ingrese el primer numero de carne: ");
    while(Serial.available()==0){}
    carne1 = Serial.parseInt();
    Serial.println("Ingrese el segundo numero de carne: ");
    while(Serial.available()==0){}
    delay(5000);j
    carne2 = Serial.parseInt();
    if(carne2>carne1){
        numc = carne2 - carne1;
    }
    else{
      numc = carne1 - carne2;
    }
    Serial.println(numc);
    if(numc>0&&numc<1023){
      fnum = numc/2;
    }
    else if(numc>1023&&numc<3000){
      fnum = numc/3;
    }
    else if(numc>3001&&numc<5000){
      fnum = numc/5;
    }
    else if(numc>5001&&numc<8000){
      fnum = numc/8;
    }
    else if(numc>8001&&numc<100000){
      fnum = numc/10;
    }
    Serial.println(fnum);
    delay(2000);
    return fnum;
}