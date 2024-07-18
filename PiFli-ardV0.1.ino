// Note to Arcade Reviewers, this program was AI-assisted by ChatGPT (Worked on setting up AP as little documentation exists for the pico/ardunio IDE)

#include <WiFi.h>

// Replace with your desired network credentials
const char* ssid = "PiFli";
const char* password = "raspberry";

WiFiServer server(80);

void setup() {
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);


  // Start the access point
  Serial.print("Starting PiFli");
  if (WiFi.softAP(ssid, password)) {
    Serial.println("Access Point Started");
      digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  } else {
    Serial.println("Failed to start AP");
    digitalWrite(LED_BUILTIN, HIGH);
     delay(100);                       // wait for a second
     digitalWrite(LED_BUILTIN, LOW);
    while (true);

  }

  Serial.print("IP address: ");
  Serial.println(WiFi.softAPIP());

  // Start the server
  server.begin();
  digitalWrite(LED_BUILTIN, LOW);  

}


void loop() {
  WiFiClient client = server.available();
  if (client) {
    Serial.println("New client");
    String currentLine = "";

    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        Serial.write(c);
        if (c == '\n') {
          if (currentLine.length() == 0) {
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println();

            // Web Page Content
            client.println("<!DOCTYPE html><html>");
            client.println("<head>");
            client.println("<title>PiFli NetController</title>");
            client.println("<style>");
            client.println("body { font-family: Arial, sans-serif; background-color: #f0f0f0; text-align: center; padding: 50px; }");
            client.println("h1 { color: #333; }");
            client.println("</style>");
            client.println("</head>");
            client.println("<body><h1>Welcome!</h1></body>");
            client.println("<body><h1>MFPV PiFli Web Portal</h1></body>");
            client.println("<body><h2>Authorized Access ONLY</h2></body>");
            client.println("</html>");
            
            break;
          } else {
            currentLine = "";
          }
        } else if (c != '\r') {
          currentLine += c;
        }
      }
    }
    client.stop();
    Serial.println("Client disconnected");
  }
}
