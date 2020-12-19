//    Este código funciona con la siguiente configuración:
//    Board support API esp8266 (by ESP8266 Community) version 2.5.2
//    Software Library --> ArduinoJSON v5.13.1

#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <MySQL_Connection.h>
#include <MySQL_Cursor.h>

#define WIFI_SSID "INFINITUM430D_2.4"
#define WIFI_PASSWORD "Y33kRq6cfN"

WiFiClient client;
MySQL_Connection conn((Client *)&client);
IPAddress server_addr(192,168,1,91);// MySQL server IP
char user[] = "client1";                  // MySQL user
char password[] = "HolaMundo";              // MySQL password
char sqlSTMT[100];
char query[128];

int lecturaSensorA0=0;

void setup()
{
    Serial.begin(9600);
    delay(2000);
    Serial.println('\n');

    wifiConnect();

    Serial.println("Conectando con la base de datos ");

    while (conn.connect(server_addr, 3306, user, password) != true)
    {
        delay(200);
        Serial.print ( "." );
    }

    Serial.println("");
    Serial.println("Conectado al servidor SQL!!!");
    updateDB(1);// 1 = add entry
    delay(10);
}

void loop()
{
    updateDB(0);// 0 = sum to cards counter

    if(WiFi.status() != WL_CONNECTED)
    {
        wifiConnect();
    }
    delay(1000);
}

void updateDB(int option)
{
  // 0 update
  // 1 insert new entry
  
  if(option == 1)
    char sqlSTMT[]="INSERT into PCT.Registros (printDate,cards,machine) VALUES(CURDATE(),0,1)";
  else
    char sqlSTMT[]="UPDATE Registros SET cards=cards+1 WHERE printDate=CURDATE()";

  sprintf(query,sqlSTMT,0);
  Serial.println("Registrando datos.");
  Serial.println(query);

  MySQL_Cursor *cur_mem = new MySQL_Cursor(&conn);
  cur_mem->execute(query);
  delete cur_mem;
}
void wifiConnect()
{
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);  // wiifi connection
    Serial.print("Conectado a WiFi --> ");
    Serial.print(WIFI_SSID); Serial.println(" ...");

    int teller = 0;
    while (WiFi.status() != WL_CONNECTED)
    {  //await wifi conection
        delay(1000);
        Serial.print(++teller); Serial.print(' ');
    }

    Serial.println('\n');
    Serial.println("WiFi conectado!");
    Serial.print("IP address:\t");
    Serial.println(WiFi.localIP());         // Send the IP address of the ESP8266 to the computer
}
