#include "MeMCore.h"

MeDCMotor left_motor(M1); // left motor

MeDCMotor right_motor(M2); // right motor

MeRGBLed led(PORT_7); // led

MeUltrasonicSensor ultraSensor(PORT_3);

MeLineFollower lineFinder(PORT_2);

MeIR ir;

int distance;

uint8_t motorSpeed = 200;

struct my_color {
  uint8_t r;
  uint8_t g;
  uint8_t b;
};

struct my_color blue = {
  0, 0, 255
};

struct my_color red = {
  255, 0, 0
};

struct my_color green = {
  0, 255, 0
};


void setup() {
  ir.begin();
  set_color(green);
  // while(1) {
    // if (ir.keyPressed(IR_BUTTON_A)) {
    //   set_color(blue);
    // }
    
  // }
}

void loop() {
//  distance = ultraSensor.distanceCm();
//  if (distance < 10)
//  {
//    set_color(red);
//    /* code */
//  }
//  else
//  {
//    set_color(blue);
//    /* code */
//  }
  
  // int sensorState = lineFinder.readSensors();
  // switch(sensorState)
  // {
  //   case S1_IN_S2_IN: set_color(red); break;
  //   case S1_IN_S2_OUT: set_color(blue); break;
  //   case S1_OUT_S2_IN: go_forward(motorSpeed); break;
  //   case S1_OUT_S2_OUT: go_forward(motorSpeed); break;
  //   default: break;
  // }
  // delay(200);

}

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
