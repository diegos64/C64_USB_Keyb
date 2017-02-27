#include <Keyboard.h>
#include <Keypad.h>

const byte ROWS = 9;
const byte COLS = 9;
byte keys[ROWS][COLS] = {
     {49,96,179,177,32,128,113,50,0},
     {51,119,97,129,122,115,101,52,0},
     {53,114,100,120,99,102,116,54,0},
     {55,121,103,118,98,104,117,56,0},
     {57,105,106,110,109,107,111,48,0},
     {45,112,108,44,46,59,91,61,0},
     {209,93,39,47,133,92,212,210,0},
     {178,176,215,217,194,196,198,200,0},
     {0,0,0,0,0,0,0,130,211}
     };
 byte rowPins[ROWS] = {12, 11, 10, 9, 8, 7, 6, 5, A1}; // Pines Fila del teclado Commodore
 byte colPins[COLS] = {4, 3, 2, 1, 0, A5, A4, A3, A2}; // Pines Columna del teclado Commodore

 byte estado; // el estado de la lectura de tecla
 byte tecla;  // el valor correspondiente a la tecla leida

 Keypad teclado = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup(){
  pinMode(13, OUTPUT);

  // Hace una serie de destellos del led de power
     for (int Cuenta = 1; Cuenta < 7; Cuenta++){
         digitalWrite(13, HIGH);
         delay(500);
         digitalWrite(13, LOW);
         delay(500);}
  
  digitalWrite(13, HIGH); // deja enciendido led de power del teclado
  
  teclado.setHoldTime(1000);        // Por defecto son 1000mS
  teclado.setDebounceTime(1);      // Por defecto son 50mS
  Keyboard.begin();
}

void loop(){

    if (teclado.getKeys()){
        for (int i=0; i<5; i++) {  // Escanea hasta 5 teclas (máximo 10)        
            if ( teclado.key[i].stateChanged ) {  // Solamente encuentra las teclas a las que les cambió el estado.
                switch (teclado.key[i].kstate) {  // Reporta el estado de la tecla activa: IDLE, PRESSED, HOLD, or RELEASED
                    case PRESSED:
                       Keyboard.press(teclado.key[i].kchar);
                       break;
                    case RELEASED:
                       Keyboard.release(teclado.key[i].kchar);
                       break; }}}}
}

