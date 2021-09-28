int pinoAnalogicoSolo = A0;
int contSolo;
float mediaSolo;

void setup()
{
  pinMode(pinoAnalogicoSolo, INPUT);
  Serial.begin(9600);
}
void loop()
{
  pinoAnalogicoSolo = analogRead(pinoAnalogicoSolo);
  mediaSolo = pinoAnalogicoSolo + mediaSolo;
  contSolo++;

  if (contSolo == 50)
  {
      mediaSolo = mediaSolo / 500;
      //Serial.print(" - Media : ");
      //Serial.println(mediaSolo);
      delay(100);
    
      if (mediaSolo < 40)
      {
        Serial.print(" - Umidade do Solo → Molhado\n");
      }
      else
      {
          if (mediaSolo > 45)
          {
            Serial.print(" - Umidade do Solo → Seco\n");
          }
      }
    contSolo = 0;
    mediaSolo = 0;
  }
}
