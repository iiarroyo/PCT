//    Este código funciona con la siguiente configuración:
//    Board support API esp8266 (by ESP8266 Community) version 2.5.2
//    Software Library --> ArduinoJSON v5.13.1

//#include <ESP8266WiFi.h>
//#include <WiFiClient.h>
//#include <MySQL_Connection.h>
//#include <MySQL_Cursor.h>

// #define WIFI_SSID ""
// #define WIFI_PASSWORD ""
//
// WiFiClient client;
// MySQL_Connection conn((Client *)&client);
// IPAddress server_addr(192, 168 ,1, 77);  // MySQL server IP
// char user[] = "cliente1";                  // MySQL user
// char password[] = "HolaMundo";              // MySQL password
//
// char insertSTMT[]="INSERT into TC1004B.Sensores (nodeID,sensorID,sensorValue) VALUES(1,1,%d)";
// char query[128];
//
// #define SENSOR_A0 A0
// #define LED1 D0 //R-Rojo  ... IMPORTANTE: Validar si el LED es de ánodo o de cátodo común
// #define LED2 D1 //G-Verde
// #define LED3 D2 //B-Azul
//
// int lecturaSensorA0=0;
//
void setup() {
//     Serial.begin(9600);
//     pinMode(LED1, OUTPUT);
//     pinMode(LED2, OUTPUT);
//     pinMode(LED3, OUTPUT);
//     delay(2000);
//     Serial.println('\n');
//
//     wifiConnect();
//
//     Serial.println("Conectando con la base de datos ");
//
//     while (conn.connect(server_addr, 3306, user, password) != true) {
//         delay(200);
//         Serial.print ( "." );
//     }
//
//     Serial.println("");
//     Serial.println("Conectado al servidor SQL!!!");
//     delay(10);
}  //End setup()
//
void loop() {
//     lecturaSensorA0=analogRead(SENSOR_A0);
//     delay(10);
//
//     sprintf(query,insertSTMT,lecturaSensorA0);
//     Serial.println("Registrando datos.");
//     Serial.println(query);
//
//     MySQL_Cursor *cur_mem = new MySQL_Cursor(&conn);
//     cur_mem->execute(query);
//     delete cur_mem;
//
//     if(WiFi.status() != WL_CONNECTED) {
//         wifiConnect();
//     }
//     delay(1000);
}
//
// void wifiConnect() {
//     WiFi.begin(WIFI_SSID, WIFI_PASSWORD);  //Conexión a la red WiFi
//     Serial.print("Conectado a WiFi --> ");
//     Serial.print(WIFI_SSID); Serial.println(" ...");
//
//     int teller = 0;
//     while (WiFi.status() != WL_CONNECTED) {  //Esperar a establecer conexión WiFi
//         delay(1000);
//         Serial.print(++teller); Serial.print(' ');
//     }
//
//     Serial.println('\n');
//     Serial.println("WiFi conectado!");
//     Serial.print("IP address:\t");
//     Serial.println(WiFi.localIP());         // Send the IP address of the ESP8266 to the computer
// }
