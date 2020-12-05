#include "MeOrion.h"

MeDCMotor left_motor(M1); // left motor

MeDCMotor right_motor(M2); // right motor

MeRGBLed led(PORT_3); // led

uint8_t motorSpeed = 200;

float j, f, k;

struct color {
  uint8_t r;
  uint8_t g;
  uint8_t b;
}

red_color

void setup() {
  for(uint8_t i = 0; i < 1; i++) {
    set_random_color();
    go_forward(motorSpeed);
    set_random_color();
    go_backward(motorSpeed);
    set_random_color();
    turn_left(motorSpeed);
    set_random_color();
    turn_right(motorSpeed);
  }
  stop_motors();
}

void loop() {}

void go_forward(uint8_t speed) {
  left_motor.run(-speed);
  right_motor.run(speed);
  delay(2000);
}

void go_backward(uint8_t speed) {
  left_motor.run(speed);
  right_motor.run(-speed);
  delay(2000);
}

void stop_motors() {
  left_motor.stop();
  right_motor.stop();
  delay(2000);
}

void turn_left(uint8_t speed) {
  left_motor.run(speed * 2.3);
  right_motor.run(speed);
  delay(2000);
}

void turn_right(uint8_t speed) {
  left_motor.run(-speed);
  right_motor.run(-speed * 2.3);
  delay(2000);
}

void set_random_color() {
  for(uint8_t t = 1; t < 15; t++) {
    uint8_t red  = 64 * (1 + sin(t / 2.0 + j / 4.0) );
    uint8_t green = 64 * (1 + sin(t / 1.0 + f / 9.0 + 2.1) );
    uint8_t blue = 64 * (1 + sin(t / 3.0 + k / 14.0 + 4.2) );
    led.setColorAt(t, red, green, blue);
  }
  led.show();
  j += random(1, 6) / 6.0;
  f += random(1, 6) / 6.0;
  k += random(1, 6) / 6.0;
}
