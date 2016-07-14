/*
  This is a simple code to test BH1750FVI Light senosr
  communicate using I2C Protocol 
  this library enable 2 slave device address
  Main address  0x23 
  secondary address 0x5C 
  connect this sensor as following :
  VCC >>> 3.3V
  SDA >>> A4 
  SCL >>> A5
  addr >> A3
  Gnd >>>Gnd
  Written By : Mohannad Rawashdeh
  
 */
 
 // First define the library :

#include <Wire.h>
#include <BH1750FVI.h>

BH1750FVI LightSensor;

// NOTE: These pines cannont be used as digital outs.
int lightSensorSelectorPin0 = 26; // Arduino Nano v3.0 pin A7.
int lightSensorSelectorPin1 = 25; // Arduino Nano v3.0 pin A6.

uint16_t nivelesLuminososObtenidos[4];

String out;

void setup() {   // put your setup code here, to run once:
  Serial.begin(9600);

  // pinMode(lightSensorSelectorPin0, OUTPUT); 
  // pinMode(lightSensorSelectorPin1, OUTPUT);

  // digitalWrite(lightSensorSelectorPin0, HIGH);
  // digitalWrite(lightSensorSelectorPin1, LOW);

  configurarLuxometros();
  
  Serial.println("Running...");
}

void loop() {
  // put your main code here, to run repeatedly: 
  // uint16_t lux = LightSensor.GetLightIntensity();// Get Lux value
  
  leerLuxometros();

  // out = "";

  // for (int contador = 1; contador <= 4; contador++) {
    // out += "Sensor ";
  //   out += String(contador);
  //   out += ": ";
  //   out += String(nivelesLuminososObtenidos[contador - 1]);
  //   out += " ";
  // }

  // out += "\n";

  // Serial.println(out);

  out = "Sensor value: ";
  out += String(nivelesLuminososObtenidos[0]);
  out += " lux";

  Serial.println(out);

  delay(1000);
}

void configurarLuxometros() {
  // for (int contador = 0; contador < 4; contador++) {
    // seleccionarSensor(contador);
    Serial.println("Configurando sensor");
    LightSensor.begin();
    LightSensor.SetAddress(Device_Address_L);
    LightSensor.SetMode(Continuous_H_resolution_Mode);
    // delay(100);
  // }
}

void leerLuxometros() {
  // for (int contador = 0; contador < 4; contador++) {
    // seleccionarSensor(contador);
    Serial.print("Reading Side ");
    // Serial.print(contador);
    // nivelesLuminososObtenidos[contador] = LightSensor.GetLightIntensity();  // Get Lux value
    nivelesLuminososObtenidos[0] = LightSensor.GetLightIntensity();  // Get Lux value
    // Serial.print(" - ");
    // Serial.println(LightSensor.GetLightIntensity());
  // }
}

// void seleccionarSensor(int sensorId) {
//   switch (sensorId) {
//     case 0:
//       Serial.println("Getting Side 1 ligth intensity value.");
//       // Getting Side 1 ligth intensity value.
//       digitalWrite(lightSensorSelectorPin0, LOW);
//       digitalWrite(lightSensorSelectorPin1, LOW);
//       delay(100);
//       break;
//     case 1:
//       Serial.println("Getting Side 2 ligth intensity value.");
//       // Getting Side 2 ligth intensity value.
//       digitalWrite(lightSensorSelectorPin0, HIGH);
//       digitalWrite(lightSensorSelectorPin1, LOW);
//       delay(100);
//       break;
//     case 2:
//       Serial.println("Getting Side 3 ligth intensity value.");
//       // Getting Side 3 ligth intensity value.
//       digitalWrite(lightSensorSelectorPin0, LOW);
//       digitalWrite(lightSensorSelectorPin1, HIGH);
//       delay(100);
//       break;
//     case 3:
//       Serial.println("Getting Side 4 ligth intensity value.");
//       // Getting Side 4 ligth intensity value.
//       digitalWrite(lightSensorSelectorPin0, HIGH);
//       digitalWrite(lightSensorSelectorPin1, HIGH);
//       delay(100);
//       break;
//   }
// }
