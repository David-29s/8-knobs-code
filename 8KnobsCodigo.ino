//Codigo para 8 encoder que emulan teclas y atajos del teclado para sacarle provecho en ableton live

 
#include <Encoder.h> 
#include <HID-Project.h> 
#include <HID-Settings.h> 
 
// Encoder 1: Flechas izquierda/derecha (Pins 2, 3) 
Encoder miEncoder(2, 3); 
long posicionAnterior = 0; 
long pasosAcumulados = 0; 
 
// Encoder 2: Flechas arriba/abajo (Pins 4, 5) 
Encoder encoderUpDown(4, 5); 
long posicionAnteriorUpDown = 0; 
long pasosAcumuladosUpDown = 0; 
 
// Encoder 3: Shift + Flechas izquierda/derecha (Pins 6, 7) 
Encoder encoderShift(6, 7); 
long posicionAnteriorShift = 0; 
long pasosAcumuladosShift = 0; 
 
// Encoder 4: Shift + Flechas arriba/abajo (Pins 8, 9) 
Encoder encoderShiftUpDown(8, 9); 
long posicionAnteriorShiftUpDown = 0; 
long pasosAcumuladosShiftUpDown = 0; 
 
// Encoder 5: Alt + Flechas izquierda/derecha (Pins 10, 14) 
Encoder encoderAlt(10, 14); 
long posicionAnteriorAlt = 0; 
long pasosAcumuladosAlt = 0; 

// Encoder 6: Alt + Flechas arriba/abajo (Pins 15, 16) 
Encoder encoderAltUpDown(15, 16); 
long posicionAnteriorAltUpDown = 0; 
long pasosAcumuladosAltUpDown = 0; 
 
// Encoder 7: Ctrl + E / Ctrl + J (Pins A0, A1 == 18, 19) 
Encoder encoderEJ(A0, A1); 
long posicionAnteriorEJ = 0; 
long pasosAcumuladosEJ = 0; 
 
// Encoder 8: Ctrl + 1 / Ctrl + 2 (Pins A2, A3 == 16, 17) 
Encoder encoderCtrl(A2, A3); 
long posicionAnteriorCtrl = 0; 
long pasosAcumuladosCtrl = 0; 
 

 
void setup() { 
  BootKeyboard.begin(); 
} 
 
void loop() { 
  // --- Encoder 1 --- 
  long nuevaPosicion = miEncoder.read(); 
  long diferencia = nuevaPosicion - posicionAnterior; 
  if (diferencia != 0) { 
    pasosAcumulados += diferencia; 
    posicionAnterior = nuevaPosicion; 
 
    if (pasosAcumulados >= 4) { 
      BootKeyboard.press(KEY_RIGHT_ARROW); 
      delay(10); 
      BootKeyboard.release(KEY_RIGHT_ARROW); 
      pasosAcumulados = 0; 
    } else if (pasosAcumulados <= -4) { 
      BootKeyboard.press(KEY_LEFT_ARROW); 
      delay(10); 
      BootKeyboard.release(KEY_LEFT_ARROW); 
      pasosAcumulados = 0; 
    } 
  } 
 
  // --- Encoder 2 (Flechas Arriba / Abajo) --- 
  long nuevaPosicionUpDown = encoderUpDown.read(); 
  long diferenciaUpDown = nuevaPosicionUpDown - posicionAnteriorUpDown; 
  if (diferenciaUpDown != 0) { 
    pasosAcumuladosUpDown += diferenciaUpDown; 
    posicionAnteriorUpDown = nuevaPosicionUpDown; 
 
    if (pasosAcumuladosUpDown >= 4) { 
      BootKeyboard.press(KEY_DOWN_ARROW); 
      delay(10); 
      BootKeyboard.release(KEY_DOWN_ARROW); 
      pasosAcumuladosUpDown = 0; 
    } else if (pasosAcumuladosUpDown <= -4) { 
      BootKeyboard.press(KEY_UP_ARROW); 
      delay(10); 
      BootKeyboard.release(KEY_UP_ARROW); 
      pasosAcumuladosUpDown = 0; 
    } 
  } 
 
  // --- Encoder 3 (Shift + Flechas izquierda/derecha) --- 
  long nuevaPosicionShift = encoderShift.read(); 
  long diferenciaShift = nuevaPosicionShift - posicionAnteriorShift; 
  if (diferenciaShift != 0) { 
    pasosAcumuladosShift += diferenciaShift; 
    posicionAnteriorShift = nuevaPosicionShift; 
 
    if (pasosAcumuladosShift >= 4) { 
      BootKeyboard.press(KEY_LEFT_SHIFT); 
      BootKeyboard.press(KEY_RIGHT_ARROW); 
      delay(10); 
      BootKeyboard.release(KEY_RIGHT_ARROW); 
      BootKeyboard.release(KEY_LEFT_SHIFT); 
      pasosAcumuladosShift = 0; 
    } else if (pasosAcumuladosShift <= -4) { 
      BootKeyboard.press(KEY_LEFT_SHIFT); 
      BootKeyboard.press(KEY_LEFT_ARROW); 
      delay(10); 
      BootKeyboard.release(KEY_LEFT_ARROW); 
      BootKeyboard.release(KEY_LEFT_SHIFT); 
      pasosAcumuladosShift = 0; 
    } 
  } 
 
  // --- Encoder 4 (Shift + Flechas arriba/abajo) --- 
  long nuevaPosicionShiftUpDown = encoderShiftUpDown.read(); 
  long diferenciaShiftUpDown = nuevaPosicionShiftUpDown - 
posicionAnteriorShiftUpDown; 
  if (diferenciaShiftUpDown != 0) { 
    pasosAcumuladosShiftUpDown += diferenciaShiftUpDown; 
    posicionAnteriorShiftUpDown = nuevaPosicionShiftUpDown; 
 
    if (pasosAcumuladosShiftUpDown >= 4) { 
      BootKeyboard.press(KEY_LEFT_SHIFT); 
      BootKeyboard.press(KEY_DOWN_ARROW); 
      delay(10); 
      BootKeyboard.release(KEY_DOWN_ARROW); 
      BootKeyboard.release(KEY_LEFT_SHIFT); 
      pasosAcumuladosShiftUpDown = 0; 
    } else if (pasosAcumuladosShiftUpDown <= -4) { 
      BootKeyboard.press(KEY_LEFT_SHIFT); 
      BootKeyboard.press(KEY_UP_ARROW); 
      delay(10); 
      BootKeyboard.release(KEY_UP_ARROW); 
      BootKeyboard.release(KEY_LEFT_SHIFT); 
      pasosAcumuladosShiftUpDown = 0; 
    } 
  } 
 
  // --- Encoder 5 (Alt + Flechas izquierda/derecha) --- 
  long nuevaPosicionAlt = encoderAlt.read(); 
  long diferenciaAlt = nuevaPosicionAlt - posicionAnteriorAlt; 
  if (diferenciaAlt != 0) { 
    pasosAcumuladosAlt += diferenciaAlt; 
    posicionAnteriorAlt = nuevaPosicionAlt; 
 
    if (pasosAcumuladosAlt >= 4) { 
      BootKeyboard.press(KEY_LEFT_ALT); 
      BootKeyboard.press(KEY_RIGHT_ARROW); 
      delay(10); 
      BootKeyboard.release(KEY_RIGHT_ARROW); 
      BootKeyboard.release(KEY_LEFT_ALT); 
      pasosAcumuladosAlt = 0; 
    } else if (pasosAcumuladosAlt <= -4) { 
      BootKeyboard.press(KEY_LEFT_ALT); 
      BootKeyboard.press(KEY_LEFT_ARROW); 
      delay(10); 
      BootKeyboard.release(KEY_LEFT_ARROW); 
      BootKeyboard.release(KEY_LEFT_ALT); 
      pasosAcumuladosAlt = 0; 
    } 
  } 

    // --- Encoder 6 (Alt + Flechas arriba/abajo) --- 
  long nuevaPosicionAltUpDown = encoderAltUpDown.read(); 
  long diferenciaAltUpDown = nuevaPosicionAltUpDown - 
posicionAnteriorAltUpDown; 
  if (diferenciaAltUpDown != 0) { 
    pasosAcumuladosAltUpDown += diferenciaAltUpDown; 
    posicionAnteriorAltUpDown = nuevaPosicionAltUpDown; 
 
    if (pasosAcumuladosAltUpDown >= 4) { 
      BootKeyboard.press(KEY_LEFT_ALT); 
      BootKeyboard.press(KEY_DOWN_ARROW); 
      delay(10); 
      BootKeyboard.release(KEY_DOWN_ARROW); 
      BootKeyboard.release(KEY_LEFT_ALT); 
      pasosAcumuladosAltUpDown = 0; 
    } else if (pasosAcumuladosAltUpDown <= -4) { 
      BootKeyboard.press(KEY_LEFT_ALT); 
      BootKeyboard.press(KEY_UP_ARROW); 
      delay(10); 
      BootKeyboard.release(KEY_UP_ARROW); 
BootKeyboard.release(KEY_LEFT_ALT); 
pasosAcumuladosAltUpDown = 0; 
  } 
} 
 
  // --- Encoder 7 (Ctrl + E / Ctrl + J) --- 
  long nuevaPosicionEJ = encoderEJ.read(); 
  long diferenciaEJ = nuevaPosicionEJ - posicionAnteriorEJ; 
  if (diferenciaEJ != 0) { 
    pasosAcumuladosEJ += diferenciaEJ; 
    posicionAnteriorEJ = nuevaPosicionEJ; 
 
    if (pasosAcumuladosEJ >= 4) { 
      BootKeyboard.press(KEY_LEFT_CTRL); 
      BootKeyboard.press('j'); 
      delay(10); 
      BootKeyboard.release('j'); 
      BootKeyboard.release(KEY_LEFT_CTRL); 
      pasosAcumuladosEJ = 0; 
    } else if (pasosAcumuladosEJ <= -4) { 
      BootKeyboard.press(KEY_LEFT_CTRL); 
      BootKeyboard.press('e'); 
      delay(10); 
      BootKeyboard.release('e'); 
      BootKeyboard.release(KEY_LEFT_CTRL); 
      pasosAcumuladosEJ = 0; 
    } 
  } 
 
  // --- Encoder 8 (Ctrl + 1 / Ctrl + 2) --- 
  long nuevaPosicionCtrl = encoderCtrl.read(); 
  long diferenciaCtrl = nuevaPosicionCtrl - posicionAnteriorCtrl; 
  if (diferenciaCtrl != 0) { 
    pasosAcumuladosCtrl += diferenciaCtrl; 
    posicionAnteriorCtrl = nuevaPosicionCtrl; 
 
    if (pasosAcumuladosCtrl >= 4) { 
      BootKeyboard.press(KEY_LEFT_CTRL); 
      BootKeyboard.press('2'); 
      delay(10); 
      BootKeyboard.release('2'); 
      BootKeyboard.release(KEY_LEFT_CTRL); 
      pasosAcumuladosCtrl = 0; 
    } else if (pasosAcumuladosCtrl <= -4) { 
      BootKeyboard.press(KEY_LEFT_CTRL); 
      BootKeyboard.press('1'); 
      delay(10); 
      BootKeyboard.release('1'); 
      BootKeyboard.release(KEY_LEFT_CTRL); 
      pasosAcumuladosCtrl = 0; 
    } 
  } 
 


delay(1); 
}

