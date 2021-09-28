int sensor = 5; // Módulo Sensor De Luminosidade
int pinoBuzz = 4;
int sensorRead;

void setup() {
  Serial.begin(9600);
  pinMode (sensor, INPUT);
  pinMode (pinoBuzz, OUTPUT);
}

void loop() {
  sensorRead = digitalRead(sensor);
  Serial.print(" - Valor : ");
  Serial.println(sensorRead);
  
  if(sensorRead == 1) {
    tone(pinoBuzz,500);
  } 
//  else
//  {
//    noTone(pinoBuzz);
//  }  
}
