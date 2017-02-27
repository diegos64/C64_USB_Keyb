# C64_USB_Keyb
Commodore 64 Keyboard to USB

Permite conectar el teclado de una Commodore 64 a una PC
a través del puesto USB, para su uso en el emulador VICE
Para ello utiliza una placa ARDUINO LEONARDO, y el simple código C64_USB_char4.ino
que emplea las librerías keypad.h y keyboard.h
En el pin 13 se conecta el POWER LED a través de una resistencia mayor a 330 Ohms
También hay que preveer un botón pulsador externo para la tecla ALT,
que se ubicará en alguna ranura posterior del gabinete del Commodore 64, al alcance de la mano.

Esquema de conexión del conector de teclado del Commodore 64 a los pines de la placa Arduino LEONARDO:

Matriz         Pin        Pin
Teclado C=64   Conector   Arduino

I              1          A1     ==> al pulsador tecla ALT
NC             NC         -
8              3          A2
NC             NC         -
7              5          A3     ==> al pulsador tecla ALT
6              6          A4
5              7          A5
4              8          0
3              9          1
2              10         2
1              11         3
0              12         4
H              13         5
G              14         6
F              15         7
E              16         8
D              17         9
C              18         10
B              19         11
A              20         12

