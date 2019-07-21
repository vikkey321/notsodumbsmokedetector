#include <ESP8266WiFi.h>

const char* ssid = "Your wifi username";
const char* password = "Your wifi password";

// Create an instance of the server
// specify the port to listen on as an argument
WiFiServer server(80);
int flag=0;
int sensorValue=0;
void setup() {
  Serial.begin(115200);
  delay(10);

  pinMode(D0, OUTPUT);
  digitalWrite(D0, 0);
  
  // Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  
  // Start the server
  server.begin();
  Serial.println("Server started");

  // Print the IP address
  Serial.println(WiFi.localIP());
  delay(2000);
}
void loop() {
  // Check if a client has connected
  WiFiClient client = server.available();
  if (!client) {
     sensorValue = analogRead(A0);
    Serial.println(sensorValue);
    if(sensorValue > 400 || flag == 1){
      flag = 1;
       digitalWrite(D0, HIGH);   // turn the LED on (HIGH is the voltage level)
        delay(500);                       // wait for a second
        digitalWrite(D0, LOW);    // turn the LED off by making the voltage LOW
        delay(500);                       //
        digitalWrite(D0, HIGH);   // turn the LED on (HIGH is the voltage level)
        delay(500);                       // wait for a second
        digitalWrite(D0, LOW);    // turn the LED off by making the voltage LOW
        delay(500);             
    }
    return;
  }
  
  // Wait until the client sends some data
  Serial.println("new client");
  while(!client.available()){
    delay(1);
  }
  
  // Read the first line of the request
  String req = client.readStringUntil('\r');
  Serial.println(req);
  client.flush();
  
  // Match the request
  int val;
  String m;
  if (req.indexOf("/D0/0") != -1){
    m = "D1 is Low";
    digitalWrite(D0, 0);
    flag = 0;
  }
  else if (req.indexOf("/D0/1") != -1){
    m = "D1 is High";
    digitalWrite(D0, 1);
  }
  else {
    Serial.println("invalid request");
    client.stop();
    return;
  }


  
  client.flush();

  // Prepare the response
  String s = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<!DOCTYPE HTML>\r\n<head><meta http-equiv=\"Access-Control-Allow-Origin\" content=\"*\"></head>\n<html>\r\n" +m;
  s += "</html>\n";

  // Send the response to the client
  client.print(s);
  delay(1);
  Serial.println("Client disonnected");

  // The client will actually be disconnected 
  // when the function returns and 'client' object is detroyed
}
