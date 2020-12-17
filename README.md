# Proyecto para Carlos Tapia
## Elements
- CBB8 proximity sensor
- CT6S counter
- 2 ESP8266
- MySQL database

## ESP8266
one for time tracking
other for database update

## Database structure (MySQL)

| printDate     | cards         |machine|
| ------------- |:-------------:| -----:|
| 0000-00-00    | 380           | 1     |
| 0000-00-00    | 365           | 2     |
| 0000-00-00    | 380           | 3     |

printDate (DATE)
cards(INT)
machine(TINYINT)
