# 13/Feb/2024
### Comunicación con el grupo:
Via grupo de facebook:
https://www.facebook.com/groups/771173494918373
## Evaluación
- Prácticas 70%
	- Se realizan de 8 a 11 Practicas por semestre
- Examen 30%
	- Se realizan de 1 a 3 por semestre según lo requiera el grupo

## Método de trabajo
- Equipos de 1 a 3 integrantes
- Cada equipo creará una carpeta en algún medio remoto y la compartirá como ASIGNADO PERMISO DE LECTURA Y ESCRITURA PARA ANOTACIONES 
- Deberá abrirse una carpeta por cada practica, un informe en formato abierto de lo que se hizo
- Evaluación de practicas y exámenes es de forma oral. Si algún alumno no contesta la pregunta, disminuye la calificación individual, no la del equipo

## Herramienta
ESP32

----
# 21/02/2024
![[SoC210224.excalidraw]]

# PRACTICA CANCIÓN EN TIMERS
## Cumbia sobre el río - Celso Piña


### Índice
#### Bajo(Verde)
Verde[]={ (MUTE,7) , (Básicox12,16) ,(MUTE,5) , (Básicox23,29) (V1x9,21) ,(V2x5,13) , (Básicox23,27) , (V2x8,18) ,(Básicox58,75) ,(V2x8,19) , (Básicox43,52) , (MUTE,2) ,(Básicox7,10) , (V2x18?,39) , (Básicox11,14) }

- B= {[G1,1],[D1,1]}
- V1={[A#1,1],[A1,1],[D1,1],[G1,1]} 583 o 
- V2={[D2,1],[G1,1],[D1,1],[G1,1]} 650 o 562 o 593 o 541 = 586
#### Percusión(Amarillo)
- Básico: [MUTE, .5seg], [A#3,.05seg],[D4,.05], [G4,.05seg], [MUTE, 1/6 seg], [A#3, D4,G4, 1/6 seg]
#### Acordeón(Morado)
F4 , D4, A3, C4, D4, G3 x8
D4,A#4,A4,A4,C5,A4,G4,D4,A#4,D4,A#4,A4,A4,C5,G4,G4
293,466,440,440,523,440,392,293,466,293,466,440,440,523,392,392
#### Teclado(Naranja)
Dame un codigo para esp32 que reproduzca estas notas con su respectiva duración
Acordeon [][2] = {[F4,0.2], [D4,0.2],[A3,0.2],[C4,0.2],[D4,0.2],[G3,0.2]}

### Canción (347seg)
## Acordeon
0:00 a 0:40 silencio
0:47 a 0:57 ocurre 8 veces el basico
0:57 a 1:17  V1 x4 
1:17 a  1:25 nota G5

1:25 a 1:47 silencio 
1;47 a 1:58 Basico x8 
1:58 a 2:18 V1 x4
2:18 2:24 nota g5 y remate

2:23 a 3:20 silencio
3:20 a 3:30 Basico x8
3:30 a 3:50 V1x4
3:50 a 3:55 G5 y remate de D4,A#4,G4 ... rojos

3:55 a 4:45 silencio
4:45 a 4:54 Basico x4
4:54 a 5:34 V1x10
5:34 a 4:41 G5 

Amarillo: |0:07 a 4:42 (Base) |  4:42 a 4:44 (MUTE) | 4:44  5:47 (Base)




BAJO[]={ [MUTE,7], 
[G1,1],[D1,1],[G1,1],[D1,1],[G1,1],[D1,1],[G1,1],[D1,1],[G1,1],[D1,1],[G1,1],[D1,1],[G1,1],[D1,1],[G1,1],[D1,1],

[MUTE, 5],

[G1,1],[D1,1],[G1,1],[D1,1],[G1,1],[D1,1],[G1,1],[D1,1],[G1,1],[D1,1],[G1,1],[D1,1],[G1,1],[D1,1],[G1,1],[D1,1],[G1,1],[D1,1],[G1,1],[D1,1],[G1,1],[D1,1],[G1,1],[D1,1],[G1,1],[D1,1],[G1,1],[D1,1],[G1,1],

[Ab1,1],[A1,1],[D1,1],[G1,1],[Ab1,1],[A1,1],[D1,1],[G1,1],[Ab1,1],[A1,1],[D1,1],[G1,1],[Ab1,1],[A1,1],
[D1,1],[G1,1],[Ab1,1],[A1,1],[D1,1],[G1,1],[Ab1,1],

[D2,1],[G1,1],[D1,1],[G1,1], [D2,1],[G1,1],[D1,1],[G1,1],[D2,1],[G1,1],[D1,1],[G1,1],[D2,1],

[G1,1],[D1,1],[G1,1],[D1,1],[G1,1],[D1,1],[G1,1],[D1,1],[G1,1],[D1,1],[G1,1],[D1,1],[G1,1],[D1,1],[G1,1],[D1,1],[G1,1],[D1,1],[G1,1],[D1,1],[G1,1],[D1,1],[G1,1],[D1,1],[G1,1],[D1,1],[G1,1],

[D2,1],[G1,1],[D1,1],[G1,1],[D2,1],[G1,1],[D1,1],[G1,1],[D2,1],[G1,1],[D1,1],[G1,1],[D2,1],[G1,1],[D1,1],[G1,1],[D2,1],[G1,1],

[G1,1],[D1,1],[G1,1],[D1,1],[G1,1],[D1,1],[G1,1],[D1,1],[G1,1],[D1,1],[G1,1],[D1,1],[G1,1],[D1,1],[G1,1],[D1,1],[G1,1],[D1,1],[G1,1],[D1,1],[G1,1],[D1,1],[G1,1],[D1,1],[G1,1],[D1,1],[G1,1],[D1,1],[G1,1],[D1,1],[G1,1],[D1,1],[G1,1],[D1,1],[G1,1],[D1,1],[G1,1],[D1,1],[G1,1],[D1,1],[G1,1],[D1,1],[G1,1],[D1,1],[G1,1],[D1,1],[G1,1],[D1,1],[G1,1],[D1,1],[G1,1],[D1,1],[G1,1],[D1,1],[G1,1],[D1,1],[G1,1],[D1,1],[G1,1],[D1,1],[G1,1],[D1,1],[G1,1],[D1,1],[G1,1],[D1,1],[G1,1],[D1,1],[G1,1],[D1,1],[G1,1],[D1,1],[G1,1],[D1,1],[G1,1],

[D2,1],[G1,1],[D1,1],[G1,1],[D2,1],[G1,1],[D1,1],[G1,1],[D2,1],[G1,1],[D1,1],[G1,1],[D2,1],[G1,1],[D1,1],[G1,1],[D2,1],[G1,1],[D1,1],

[G1,1],[D1,1],[G1,1],[D1,1],[G1,1],[D1,1],[G1,1],[D1,1],[G1,1],[D1,1],[G1,1],[D1,1],[G1,1],[D1,1],[G1,1],[D1,1],[G1,1],[D1,1],[G1,1],[D1,1],[G1,1],[D1,1],[G1,1],[D1,1],[G1,1],[D1,1],[G1,1],[D1,1],[G1,1],[D1,1],[G1,1],[D1,1],[G1,1],[D1,1],[G1,1],[D1,1],[G1,1],[D1,1],[G1,1],[D1,1],[G1,1],[D1,1],[G1,1],[D1,1],[G1,1],[D1,1],[G1,1],[D1,1],[G1,1],[D1,1],[G1,1],[D1,1],

[MUTE,2],

[G1,1],[D1,1],[G1,1],[D1,1],[G1,1],[D1,1],[G1,1],[D1,1],[G1,1],[D1,1],

[D2,1],[G1,1],[D1,1],[G1,1],[D2,1],[G1,1],[D1,1],[G1,1],[D2,1],[G1,1],[D1,1],[G1,1],[D2,1],[G1,1],[D1,1],[G1,1],[D2,1],[G1,1],[D1,1],[G1,1],[D2,1],[G1,1],[D1,1],[G1,1],[D2,1],[G1,1],[D1,1],[G1,1],[D2,1],[G1,1],[D1,1],[G1,1],[D2,1],[G1,1],[D1,1],[G1,1],[D2,1],[G1,1],[D1,1],

[G1,1],[D1,1],[G1,1],[D1,1],[G1,1],[D1,1],[G1,1],[D1,1],[G1,1],[D1,1],[G1,1],[D1,1],[G1,1],[D1,1]
}




```cpp
#include <Arduino.h>

// Definir las frecuencias de las notas musicales en Hz
#define NOTE_C4  261.63
#define NOTE_D4  293.66
#define NOTE_E4  329.63
#define F4  349.23
#define NOTE_G4  392.00
#define NOTE_A4  440.00
#define NOTE_B4  493.88
#define NOTE_C5  523.25
#define Fb4 369
#define Db4 311
#define Gb4 415

// Estructura para representar una nota con su duración
struct NoteWithDuration {
    double note;
    uint64_t duration;
};

// Arreglo de notas con duración
NoteWithDuration melody[] = {
    {Fb4, 500000}, {Fb4, 500000}, {Db4, 500000}, {Fb4, 500000}, {Fb4, 500000}, {Db4, 500000}, {Fb4, 500000}, {Db4, 500000}, {Fb4, 500000}, {Gb4, 800000}, {Gb4, 2000000},
    {Fb4, 500000}, {Gb4, 500000}, {Gb4, 500000}, {Fb4, 500000}, {Gb4, 500000}, {Gb4, 500000}, {Fb4, 500000}, {Gb4, 500000}, {Gb4, 500000}, {Fb4, 500000}, {Gb4, 500000}, {Gb4, 500000},
    {Fb4, 500000}, {Gb4, 500000}, {Db4, 1200000}, {Fb4, 500000}, {Fb4, 500000}, {Fb4, 500000}, {F4, 500000}, {F4, 500000}, {F4, 500000}, {Db4, 1200000}
};

// Función para configurar un timer
void setupTimer(hw_timer_t* timer, void (*callback)(), uint64_t period_us) {
    timer = timerBegin(0, 80, true); // Timer 0, prescaler 80, cuenta hacia arriba
    timerAttachInterrupt(timer, callback, true); // Attach the callback
    timerAlarmWrite(timer, period_us, true); // Establecer el período y habilitar el autoreload
    timerAlarmEnable(timer); // Habilitar la alarma del timer
}

// Función para apagar el timer
void stopTimer(hw_timer_t* timer) {
    timerAlarmDisable(timer);
}

// Función para tocar una nota con una duración específica
void playNote(double frequency, uint64_t duration_us) {
    if (frequency == 0) {
        delayMicroseconds(duration_us); // Pausa
    } else {
        tone(23, frequency, duration_us / 1000); // Tocar la nota en el pin 17
    }
}

// Función para tocar una canción
void playSong() {
    // Tocar cada nota
    for (int i = 0; i < sizeof(melody) / sizeof(melody[0]); i++) {
        playNote(melody[i].note, melody[i].duration);
        delay(800); // Pequeña pausa entre cada nota
    }
}

// Función de interrupción del timer para cambiar de nota
void IRAM_ATTR onTimer() {
    static int currentNoteIndex = 0;

    playNote(0, 0); // Detener la nota actual
    currentNoteIndex++;

    if (currentNoteIndex >= sizeof(melody) / sizeof(melody[0])) {
        stopTimer(timer0); // Detener el timer cuando se hayan reproducido todas las notas
    }
}

void setup() {
    pinMode(23, OUTPUT); // Configurar el pin 17 como salida

    setupTimer(timer0, &onTimer, 500000); // Configurar el timer para cambiar de nota cada 500 ms
}

void loop() {
    // Iniciar la reproducción de la canción cuando comienza el bucle
    playSong();
    delay(2000); // Esperar antes de volver a reproducir la canción
}

```