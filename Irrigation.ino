
#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>


char auth[] = "BLYNK_AUTH_TOKEN";
char ssid[] = "WIFI_NAME";
char pass[] = "WIFI_PASSWORD";


#define SOIL_ADC_PIN   A0     
#define RELAY_PIN     D1     


#define DRY_THRESHOLD     650    
#define SENSOR_INTERVAL  2000UL 


unsigned long lastSensorRead = 0;
int soilAdcValue = 0;
bool pumpState = false;


void pumpON(void);
void pumpOFF(void);

void setup() {
  Serial.begin(9600);
  delay(100);

  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, LOW);   

  Serial.println("Booting IoT Smart Irrigation System...");

  Blynk.begin(auth, ssid, pass);

  Serial.println("System Initialized Successfully");
}

void loop() {
  Blynk.run();

  unsigned long currentTime = millis();

  if (currentTime - lastSensorRead >= SENSOR_INTERVAL) {
    lastSensorRead = currentTime;

    soilAdcValue = analogRead(SOIL_ADC_PIN);

    Serial.print("Soil Moisture ADC Value: ");
    Serial.println(soilAdcValue);


    if (soilAdcValue > DRY_THRESHOLD) {
      pumpON();
    } else {
      pumpOFF();
    }

  
    Blynk.virtualWrite(V0, soilAdcValue); 
    Blynk.virtualWrite(V1, pumpState);    
  }
}


void pumpON(void) {
  digitalWrite(RELAY_PIN, HIGH);
  pumpState = true;
  Serial.println("Pump Status: ON");
}

void pumpOFF(void) {
  digitalWrite(RELAY_PIN, LOW);
  pumpState = false;
  Serial.println("Pump Status: OFF");
}


BLYNK_WRITE(V2) {
  int buttonState = param.asInt();

  if (buttonState == 1) {
    pumpON();
  } else {
    pumpOFF();
  }
}

