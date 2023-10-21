#include <WiFi.h>

const char* rede = "IFAL-Informatica";
const char* senha = "somostodosifal";

const uint16_t porta = 3000; 
const char* servidor = "172.61.3.150";

const int ledServidor = 2; 
const int alarme = 23;
const int ledGas = 32;
const int sensor = 34; 
const int vazamento = 1000;

unsigned long int last_time = millis();

void setup() {
pinMode(ledServidor, OUTPUT); 
pinMode(ledGas, OUTPUT);
pinMode(alarme, OUTPUT);
pinMode(sensor, INPUT); 

WiFi.begin(rede, senha); 
while (WiFi.status() != WL_CONNECTED) {
delay(80);
}
}

void loop() {
int leituraSensor = analogRead(sensor); 

if (leituraSensor >= (vazamento)){
  digitalWrite(alarme, HIGH);
  digitalWrite(ledGas, HIGH);
} else {
  digitalWrite(alarme, LOW);
  digitalWrite(ledGas, LOW);
}

WiFiClient client;
if (!client.connect(servidor, porta)) {
digitalWrite(ledServidor, LOW);
delay(1000);
return;
}

digitalWrite(ledServidor, HIGH); 
client.println(leituraSensor); 

if (millis() - last_time >= 5000){
  last_time = millis();
}

last_time = millis();
delay(1500);
}
