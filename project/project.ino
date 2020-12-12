#include "MeMCore.h"

/*************************************************
   Public Constants
 *************************************************/
MeDCMotor left_motor(M1); // left motor

MeDCMotor right_motor(M2); // right motor

MeRGBLed led(PORT_7, 2); // led

MeUltrasonicSensor ultraSensor(PORT_3);

MeLineFollower lineFollower(PORT_2);

//MeIR ir;

int distance;
uint8_t motorSpeed = 60;
uint8_t turnSpeed = 30;


/*************************************************
   Color Setup
 *************************************************/
struct my_color {
  uint8_t r;
  uint8_t g;
  uint8_t b;
};

struct my_color blue = {0, 0, 255};
struct my_color red = {255, 0, 0};
struct my_color green = {0, 255, 0};
struct my_color white = {255, 255, 255};
struct my_color yellow = {255, 255, 0};
struct my_color purple = {128, 0, 128};

my_color colors[] = {blue, red, green, white, yellow, purple};

/*************************************************
   Note Setup
 *************************************************/
#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978

MeBuzzer buzzer;
/*************************************************
   Song setup
 *************************************************/
int jingle_bells_notes[] = {
  NOTE_E4, NOTE_E4, NOTE_E4,
  NOTE_E4, NOTE_E4, NOTE_E4,
  NOTE_E4, NOTE_G4, NOTE_C4, NOTE_D4, NOTE_E4,
  NOTE_F4, NOTE_F4, NOTE_F4, NOTE_F4,
  NOTE_F4, NOTE_E4, NOTE_E4, NOTE_E4,
  NOTE_G4, NOTE_G4, NOTE_F4, NOTE_D4, NOTE_C4,
};

int jingle_bells_notes_durations[] = {
  8, 8, 4,
  8, 8, 4,
  8, 8, 8, 8, 4,
  8, 8, 8, 8,
  8, 8, 8, 8,
  8, 8, 8, 8, 4,
};

int jingle_bells_longer_notes[] = {

};

int jingle_bells_longer_notes_durations[] = {

};

int darude_notes[] = {
  NOTE_E4, NOTE_E4, NOTE_E4, NOTE_E4, NOTE_E4,
  NOTE_A4, NOTE_A4, NOTE_A4, NOTE_G4, NOTE_G4, NOTE_G4,
  NOTE_D4, NOTE_E4, NOTE_E4, NOTE_E4, NOTE_E4, NOTE_E4,
  NOTE_G5, NOTE_E4, NOTE_E4, NOTE_E4, NOTE_E4, NOTE_E4, NOTE_E4
};

int darude_notes_durations[] = {
  4, 4, 8, 8, 4,
  8, 8, 4, 8, 8, 4,
  2, 8, 4, 8, 8, 4,
  8, 8, 4, 8, 8, 16, 16
};
int songCounter = 0;

/*************************************************
   Main Functions
 *************************************************/
void setup() {

  while (1) {
    if (lineFollower.readSensors() == 0.000000) {

      move(1, 30 / 100.0 * 255);
      play_note();

    }
    if (lineFollower.readSensors() == 1.000000) {

      left_motor.run(-1 * 0 / 100.0 * 255);
      right_motor.run(30 / 100.0 * 255);
      play_note();
    }
    if (lineFollower.readSensors() == 2.000000) {

      left_motor.run(-1 * 30 / 100.0 * 255);
      right_motor.run(0 / 100.0 * 255);
      play_note();
    }
    if (lineFollower.readSensors() == 3.000000) {

      move(2, 30 / 100.0 * 255);
      play_note();
    }
    _loop();
  }
}

void _loop() {}

void loop() {
  _loop();
}

void move(int direction, int speed) {
  int leftSpeed = 0;
  int rightSpeed = 0;
  if (direction == 1) {
    leftSpeed = speed;
    rightSpeed = speed;
  } else if (direction == 2) {
    leftSpeed = -speed;
    rightSpeed = -speed;
  } else if (direction == 3) {
    leftSpeed = -speed;
    rightSpeed = speed;
  } else if (direction == 4) {
    leftSpeed = speed;
    rightSpeed = -speed;
  }
  left_motor.run((9) == M1 ? -(leftSpeed) : (leftSpeed));
  right_motor.run((10) == M1 ? -(rightSpeed) : (rightSpeed));
}






/*************************************************
   Movement functions
 *************************************************/
void go_forward(uint8_t speed) {
  left_motor.run(-speed / 100 * 255);
  right_motor.run(speed / 100 * 255);
}

void go_backward(uint8_t speed) {
  left_motor.run(-speed / 100 * 255);
  right_motor.run(-speed / 100 * 255);
}

void stop_motors() {
  left_motor.stop();
  right_motor.stop();
}

void turn_left(uint8_t speed) {
  left_motor.run(0);
  right_motor.run(speed / 100 * 255);
}

void turn_right(uint8_t speed) {
  left_motor.run(-1 * speed / 100 * 255);
  right_motor.run(0);
}

/*************************************************
   Color functions
 *************************************************/

void set_color(my_color color) {
  led.setColor(color.r, color.g, color.b);
  led.show();
}

/*************************************************
   Song functions
 *************************************************/
void play() {
  for (int thisNote = 0; thisNote < 24; thisNote++) {
    int noteDuration = 1000 / jingle_bells_notes_durations[thisNote];
    buzzer.tone(8, jingle_bells_notes[thisNote], noteDuration);
    my_color color = colors[random(0, 6)];
    //dance(random(0,4));
    led.setColor(1, color.r, color.g, color.b);
    led.show();
    color = colors[random(0, 6)];
    led.setColor(2, color.r, color.g, color.b);
    led.show();
    //int pause_between_notes = noteDuration * 0.5;
    //delay(pause_between_notes);
    buzzer.noTone(8);
  }
}

void play_note() {
  if (songCounter == 24) {
    songCounter = 0;
  }
  int noteDuration = 1000 / jingle_bells_notes_durations[songCounter];
  buzzer.tone(8, jingle_bells_notes[songCounter], noteDuration);
  int pause_between_notes = noteDuration * 1.50;
  delay(pause_between_notes);
  songCounter++;
}

/*************************************************
   Dance functions
 *************************************************/
void dance(uint8_t number) {
  switch (number) {
    case 1:
      go_forward(motorSpeed);
      break;
    case 2:
      go_backward(motorSpeed);
      break;
    case 3:
      turn_left(motorSpeed);
      break;
    case 4:
      turn_right(motorSpeed);
      break;
  }
}
