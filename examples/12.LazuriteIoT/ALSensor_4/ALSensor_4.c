#include "ALSensor_4_ide.h"		// Additional Header

/* FILE NAME: ALSensor_4.c
 * The MIT License (MIT)
 *
 * Copyright (c) 2018  Lapis Semiconductor Co.,Ltd.
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

/*
 * initializaing function
 * this function is called in initalizing process
 * return filename
 */
char* sensor_init() {
	static char filename[] = __FILE__;
	Wire.begin();
	rpr0521rs.init();
	return filename;
}

/*
 * callback function of activation
 * return  true : sensor_meas is called after interval
 *         false: sensor_meas is called immidialtely
 */
bool sensor_activate(void) {
	return false;
}
/*
 * callback function of deactivation
 */
void sensor_deactivate(void) {
	return;
}

/*
 * function of sensor measurement
 *
 * s[]: Array of SensorState is passed. If single sensor type, array size is always '1'.
 *
 * val->data is settled depends on data type
 * data type is set into val->type
 * val->digit shows digit of floating number.
 * 
 * val->data.uint8_val=xxx;   val->type = UINT8_VAL;
 * val->data.int8_val=xxx;    val->type = INT8_VAL;
 * val->data.uint16_val=xxx;  val->type = UINT16_VAL;
 * val->data.int16_val=xxx;   val->type = INT16_VAL;
 * val->data.uint32_val=xxx;  val->type = UINT32_VAL;
 * val->data.int32_val=xxx;   val->type = UINT32_VAL;
 * val->data.float_val=xxx;   val->type = FLOAT_VAL;  val->digit = d;
 * val->data.double_val=xxx;  val->type = DOUBLE_VAL; val->digit = d;
 */
void sensor_meas(SensorState s[]) {
	SENSOR_VAL *val = &(s[0].sensor_val);
	float als_val;
	uint8_t reg = 0x86, data[6];
	uint16_t rawals[2];

	rpr0521rs.write(RPR0521RS_MODE_CONTROL, &reg, sizeof(reg));
	sleep(100);			// measurement time

	rpr0521rs.get_rawpsalsval(data);
	
	rawals[0] = ((unsigned short)data[3] << 8) | data[2];
	rawals[1] = ((unsigned short)data[5] << 8) | data[4];

	als_val = rpr0521rs.convert_lux(rawals);

	reg = 0;
	rpr0521rs.write(RPR0521RS_MODE_CONTROL, &reg, sizeof(reg));
	val->data.double_val=als_val;  val->type = DOUBLE_VAL; val->digit = 2;
	
	return;
}
