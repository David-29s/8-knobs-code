# 8 Encoders MIDI para Ableton Live

Este proyecto de Arduino utiliza **8 encoders rotativos** para emular teclas y atajos del teclado, permitiendo controlar Ableton Live de manera más rápida y precisa. Cada encoder está configurado para enviar combinaciones de teclas específicas según la dirección de giro.

---

## Características

- **Encoder 1:** Flechas izquierda/derecha  
- **Encoder 2:** Flechas arriba/abajo  
- **Encoder 3:** Shift + Flechas izquierda/derecha  
- **Encoder 4:** Shift + Flechas arriba/abajo  
- **Encoder 5:** Alt + Flechas izquierda/derecha  
- **Encoder 6:** Alt + Flechas arriba/abajo  
- **Encoder 7:** Ctrl + E / Ctrl + J  
- **Encoder 8:** Ctrl + 1 / Ctrl + 2  

Compatible con Arduino que soporte la librería **HID-Project**, como Arduino Leonardo, Micro o Pro Micro.

---

## Librerías necesarias

- [Encoder](https://www.pjrc.com/teensy/td_libs_Encoder.html)  
- [HID-Project](https://github.com/NicoHood/HID)  

Instálalas desde el Administrador de Librerías del IDE de Arduino.

---

## Conexión de los encoders

| Encoder | Pines |
|---------|------|
| 1       | 2, 3  |
| 2       | 4, 5  |
| 3       | 6, 7  |
| 4       | 8, 9  |
| 5       | 10, 14 |
| 6       | 15, 16 |
| 7       | A0, A1 |
| 8       | A2, A3 |

---

## Uso

1. Conecta los encoders a los pines especificados.  
2. Abre el IDE de Arduino y selecciona tu placa compatible con HID.  
3. Sube el sketch al Arduino.  
4. ¡Gira los encoders para enviar los atajos a Ableton Live!

---

## Nota

Este código emula **presión de teclas** mediante USB HID, por lo que tu Arduino debe ser detectado como un teclado por el sistema operativo. No funciona en placas que no soporten HID.

---

## Licencia

MIT License

Copyright (c) 2025 David Sanchez

