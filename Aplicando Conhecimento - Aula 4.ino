#include <ESP8266WiFi.h> 
#include <PubSubClient.h>

#define pino1 14  //D5
#define pino1 12  //D6

//WiFi
const char* SSID = "OSCOREA";                // SSID / nome da rede WiFi que deseja se conectar
const char* PASSWORD = "Ecomex1234";   // Senha da rede WiFi que deseja se conectar
WiFiClient wifiClient;                        
 
//MQTT Server
const char* BROKER_MQTT = "broker.mqtt-dashboard.com"; //URL do broker MQTT que se deseja utilizar
int BROKER_PORT = 1883;                      // Porta do Broker MQTT

#define ID_MQTT  "NODEMCU_ART22"            //Informe um ID unico e seu. Caso sejam usados IDs repetidos a ultima conexão irá sobrepor a anterior. 
#define TOPIC_PUBLISH "ecg_ad8232_Art22"    //Informe um Tópico único. Caso sejam usados tópicos em duplicidade, o último irá eliminar o anterior.
PubSubClient MQTT(wifiClient);        // Instancia o Cliente MQTT passando o objeto espClient

//Declaração das Funções
void mantemConexoes();  //Garante que as conexoes com WiFi e MQTT Broker se mantenham ativas
void conectaWiFi();     //Faz conexão com WiFi
void conectaMQTT();     //Faz conexão com Broker MQTT
void enviaPacote();     //

void setup() {
  //pinMode(pinBotao1, INPUT_PULLUP);         

  Serial.begin(9600);

  pinMode(14, INPUT); // Configuração para detecção de derivações LO+
  pinMode(12, INPUT); // Configuração para detecção de leads off LO-

  conectaWiFi();
  MQTT.setServer(BROKER_MQTT, BROKER_PORT);   
}

void loop() {
  mantemConexoes();
  enviaValores();
  MQTT.loop();
}

void mantemConexoes() {
    if (!MQTT.connected()) {
       conectaMQTT(); 
    }
    
    conectaWiFi(); //se não há conexão com o WiFI, a conexão é refeita
}

void conectaWiFi() {

  Serial.print("Iniciando conexão Wifi na função conecta Wifi");

  if (WiFi.status() == WL_CONNECTED) {
     return;
  }
        
  Serial.print("Conectando-se na rede: ");
  Serial.print(SSID);
  Serial.println("  Aguarde!");

  WiFi.begin(SSID, PASSWORD); // Conecta na rede WI-FI  
  while (WiFi.status() != WL_CONNECTED) {
      delay(100);
      Serial.print(".");
  }
  
  Serial.println();
  Serial.print("Conectado com sucesso, na rede: ");
  Serial.print(SSID);  
  Serial.print("  IP obtido: ");
  Serial.println(WiFi.localIP()); 
}

void conectaMQTT() { 
    while (!MQTT.connected()) {
        Serial.print("Conectando ao Broker MQTT: ");
        Serial.println(BROKER_MQTT);
        if (MQTT.connect(ID_MQTT)) {
            Serial.println("Conectado ao Broker com sucesso!");
        } 
        else {
            Serial.println("No foi possivel se conectar ao broker.");
            Serial.println("Nova tentatica de conexao em 10s");
            delay(10000);
        }
    }
}

void enviaValores() {
// static bool estadoBotao1 = HIGH;
// static bool estadoBotao1Ant = HIGH;
// static unsigned long debounceBotao1;

//   estadoBotao1 = digitalRead(pinBotao1);
//   if (  (millis() - debounceBotao1) > 30 ) {  //Elimina efeito Bouncing
//      if (!estadoBotao1 && estadoBotao1Ant) {

//         //Botao Apertado     
//         MQTT.publish(TOPIC_PUBLISH, "1");
//         Serial.println("Botao1 APERTADO. Payload enviado.");
        
//         debounceBotao1 = millis();
//      } else if (estadoBotao1 && !estadoBotao1Ant) {

//         //Botao Solto
//         MQTT.publish(TOPIC_PUBLISH, "0");
//         Serial.println("Botao1 SOLTO. Payload enviado.");
        
//         debounceBotao1 = millis();
//      }
     
//   }
//   estadoBotao1Ant = estadoBotao1;

  //int num = 1;

  // MQTT.publish(TOPIC_PUBLISH, "Node MCU: Hello World!");
  // MQTT.publish(TOPIC_PUBLISH, "Node MCU: Hello World!");   
  // Serial.println("Mensagem enviada!");
  // delay(2000);

  int analog = analogRead(A0);
  char str[8];
  

  if((digitalRead(10) == 1)||(digitalRead(11) == 1)){
     MQTT.publish(TOPIC_PUBLISH, "!");
  }else{
    // envia o valor da entrada analógica 0:
    //Serial.println(analogRead(A0));
    //MQTT.publish(TOPIC_PUBLISH, analogRead(A0))
    MQTT.publish(TOPIC_PUBLISH, itoa(analogRead(A0), str, 10));  
    }
  // Espere um pouco para evitar que os dados seriais saturem
  delay(1);

}

