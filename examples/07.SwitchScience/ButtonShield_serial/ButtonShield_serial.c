#include "ButtonShield_serial_ide.h"		// Additional Header

/* FILE NAME: ButtonShield_serial.c
 * The MIT License (MIT)
 * 
 * Copyright (c) 2017  Lapis Semiconductor Co.,Ltd.
 * All rights reserved.
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

bool button_pressed = false;

void isr_button(void)
{
  button_pressed = true;
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  SubGHz.init();			// SubGHz to enter standby mode after init

  pinMode(2, INPUT);
  attachInterrupt(0, isr_button, CHANGE);
}

void loop() {
  // put your main code here, to run repeatedly:
  wait_event(&button_pressed);
  sleep(1);					// for debounce

  if (digitalRead(2)) {
    Serial.println("Released");
  } else {
    Serial.println("Pressed");
  }
}
