#include "MeOrion.h"

MeDCMotor left_motor(M1); // left motor

MeDCMotor right_motor(M2); // right motor

MeRGBLed led(PORT_3); // led

uint8_t motorSpeed = 200;

struct my_color {
  uint8_t r;
  uint8_t g;
  uint8_t b;
};

void setup() {
  // dance();
}

void loop() {}

void go_forward(uint8_t speed) {
  left_motor.run(-speed);
  right_motor.run(speed);
  delay(700);
}

void go_backward(uint8_t speed) {
  left_motor.run(speed);
  right_motor.run(-speed);
  delay(700);
}

void stop_motors() {
  left_motor.stop();
  right_motor.stop();
  delay(700);
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

void set_color(my_color color) {
  led.setColor(color.r, color.g, color.b);
  led.show();
}

void dance() {
  struct my_color red;
  red.r = 255;
  red.g = 0;
  red.b = 0;
  
  struct my_color blue;
  blue.r = 0;
  blue.g = 0;
  blue.b = 255;

  for(uint8_t i = 0; i < 15; i++) {
    set_color(blue);
    go_forward(motorSpeed);
    set_color(red);
    go_backward(motorSpeed);
    set_color(blue);
    turn_left(motorSpeed);
    set_color(red);
    turn_right(motorSpeed);
  }
  stop_motors();
}
