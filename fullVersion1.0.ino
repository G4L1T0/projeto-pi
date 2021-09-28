int pinoAnalogicoChuva = A5;
int pinoAnalogicoSolo = A0;
int sensorLDR = 5;
int pinoBUZZ = 4;

int valorpinoChuva;
int sensorReadLDR;
int contChuva;
int contSolo;
float mediaSolo;
float mediaChuva;

void setup()
{
  pinMode(pinoAnalogicoChuva, INPUT);
  pinMode(pinoAnalogicoSolo, INPUT);
  pinMode(sensorLDR, INPUT);
  pinMode(pinoBUZZ, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  sensorReadLDR = digitalRead(sensorLDR);
  pinoAnalogicoChuva = analogRead(pinoAnalogicoChuva);
  pinoAnalogicoSolo = analogRead(pinoAnalogicoSolo);
  mediaChuva = pinoAnalogicoChuva + mediaChuva;
  mediaSolo = pinoAnalogicoSolo + mediaSolo;
  contChuva++;
  contSolo++;

// ======================== SENSOR CHUVA ========================= //

  if (contChuva == 50)
  {
      mediaChuva = mediaChuva / 500;
      //Serial.print(" - Media : ");
      //Serial.println(mediaChuva);
      delay(100);
    
      if (mediaChuva < 60)
      {
        Serial.print(" - Sensor Chuva → Molhado\n");
      }
      else
      {
          if (mediaChuva > 80)
          {
            Serial.print(" - Sensor Chuva → Seco\n");
          }
      }
    contChuva = 0;
    mediaChuva = 0;
  }

// ========================= SENSOR SOLO ========================= //

  if (contSolo == 50)
  {
      mediaSolo = mediaSolo / 500;
      //Serial.print(" - Media : ");
      //Serial.println(mediaSolo);
      delay(100);
    
      if (mediaSolo < 80)
      {
        Serial.print(" - Sensor Solo  → Molhado\n");
      }
      else
      {
          if (mediaSolo > 85)
          {
            Serial.print(" - Sensor Solo  → Seco\n");
          }
      }
    contSolo = 0;
    mediaSolo = 0;
  }

// ===================== SENSOR LUMINOSIDADE ===================== //

  if (sensorReadLDR == 1)
  {
      tone(pinoBUZZ,500);
  } 
  else
  {
      noTone(pinoBUZZ);
  }  
}
