int pinoAnalogico = A5;
int valorpino;
int cont;
float media;

void setup()
{
  pinMode(pinoAnalogico, INPUT);
  Serial.begin(9600);
}
void loop()
{
  pinoAnalogico = analogRead(pinoAnalogico);
  //Serial.print(" - Valor analogico : ");
  //Serial.println(pinoAnalogico);
  cont++;
  media = pinoAnalogico + media;

  if (cont == 50)
  {
      media = media / 500;
      //Serial.print(" - Media : ");
      //Serial.println(media);
      delay(100);
    
      if (media < 25)
      {
        Serial.print(" - Molhado\n");
      }
      else
      {
          if (media > 50)
          {
            Serial.print(" - Seco\n");
          }
      }
    cont = 0;
    media = 0;
  }
}

