#include <WiFi.h>

const char* rede = "IFAL-Informatica";
const char* senha = "somostodosifal";

const int porta = 3000; 

const char* servidor = "172.61.4.1"; 

const int ledServidor = 2; 
const int alarme = 23;
const int ledGas = 32;
const int sensor = 34; 
const int vazamento = 930;

void setup() {
Serial.begin(9600);
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
Serial.println(leituraSensor);

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
return;
}

digitalWrite(ledServidor, HIGH); 
client.println(leituraSensor); 

delay(1300);
}