int diaenoite = 2;
int sensorGLP = 3;
int pinoBUZZ  = 4;
int sensorLDR = 5;
int pinoLEDs  = 6;

int pinoLEDQuarto01 = 10;
int pinoLEDQuarto02 = 11;
int pinoLEDSala     = 12;
int pinoLEDBanheiro = 13;

int pinoAnalogicoChuva = A5;
int pinoAnalogicoSolo = A0;

int valorpinoChuva;
int sensorReadLDR;
int sensorReadGLP;
int diaenoiteRead;
int contChuva;
int contSolo;
float mediaSolo;
float mediaChuva;
float pinoAnalogicoChuvaRead;
float pinoAnalogicoSoloRead;

void setup()
{
  pinMode(pinoAnalogicoChuva, INPUT);
  pinMode(pinoAnalogicoSolo, INPUT);
  pinMode(sensorLDR, INPUT);
  pinMode(sensorGLP, INPUT);
  pinMode(diaenoite, INPUT);
  pinMode(pinoBUZZ, OUTPUT);
  pinMode(pinoLEDs, OUTPUT);
  pinMode(pinoLEDQuarto01, OUTPUT);
  pinMode(pinoLEDQuarto02, OUTPUT);
  pinMode(pinoLEDSala, OUTPUT);
  pinMode(pinoLEDBanheiro, OUTPUT);

  Serial.begin(9600);
}

void loop()
{
  sensorReadLDR = digitalRead(sensorLDR);
  sensorReadGLP = digitalRead(sensorGLP);
  diaenoiteRead = digitalRead(diaenoite);
  pinoAnalogicoChuvaRead = analogRead(pinoAnalogicoChuva);
  pinoAnalogicoSoloRead = analogRead(pinoAnalogicoSolo);
  mediaChuva = pinoAnalogicoChuvaRead + mediaChuva;
  mediaSolo = pinoAnalogicoSoloRead + mediaSolo;
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



// ===================== SENSOR GLP ===================== //
  
  if (sensorReadGLP == 0)
  {
    tone(pinoBUZZ,500);
  }
  else
  {
    noTone(pinoBUZZ);
  }

// ================ SENSOR DIA / NOITE ================== //

   if (diaenoiteRead == 1)
   {     
    digitalWrite(pinoLEDQuarto01, HIGH);
    digitalWrite(pinoLEDQuarto02, HIGH);
    digitalWrite(pinoLEDBanheiro, HIGH);
    digitalWrite(pinoLEDSala, HIGH);
   }
   else
   {
    digitalWrite(pinoLEDQuarto01, LOW);
    digitalWrite(pinoLEDQuarto02, LOW);
    digitalWrite(pinoLEDBanheiro, LOW);
    digitalWrite(pinoLEDSala, LOW); 
   }

   Serial.println(diaenoiteRead);
   
 // ===================== SENSOR LUMINOSIDADE ===================== //

  // if (sensorReadLDR == 1)
  // {
  //   tone(pinoBUZZ,500);
  //   delay(50000);
  // } 
  // else
  // {
  //    noTone(pinoBUZZ);
  // }  

}
