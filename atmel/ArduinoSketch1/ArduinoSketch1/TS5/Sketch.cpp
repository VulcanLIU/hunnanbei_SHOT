/*Begining of Auto generated code by Atmel studio */
#include <Arduino.h>

/*End of auto generated code by Atmel studio */

#include<Servo.h>
#include<Wire.h>
//Beginning of Auto generated function prototypes by Atmel Studio
//End of Auto generated function prototypes by Atmel Studio



Servo ESC1;//两个电调
Servo ESC2;

const int Zero_pos = A3 ;//零位

//步进电机
const int steps_pin = 5;
const int dir_pin = 4;
const int en_pin = 6;

int kai;

void setup()
{
	Serial.begin(9600);
	Serial.println("77777777");
	/*步进电机上电初始化*/
	//引脚配置
	pinMode(en_pin, OUTPUT); // Enable: EN可以使用单片机端口控制，也可以直接连接GND使能
	pinMode(steps_pin, OUTPUT); // steps:脉冲个数
	pinMode(dir_pin, OUTPUT); // dir:为方向控制
	
	//上电寻找限位
	pinMode(Zero_pos, INPUT);
	
	while(1){
		digitalWrite(4,HIGH);
		digitalWrite(5,HIGH);
		delayMicroseconds(800);
		digitalWrite(5,LOW); // Output low
		delayMicroseconds(800);
		int Zero_pos_val = analogRead(Zero_pos);
	}
	
	digitalWrite(4,HIGH);
	digitalWrite(5,LOW);
	ESC1.attach(10);
	ESC2.attach(9);
	ESC1.writeMicroseconds(2000);
	ESC2.writeMicroseconds(2000);

	delay(3500);
	ESC1.writeMicroseconds(1000);
	ESC2.writeMicroseconds(1000);
	delay(2000);
	pinMode(A4, INPUT); //SDA数据线
	pinMode(A5, INPUT); //SCL时钟线
	Wire.begin();        // join i2cbus (主机，不用写IIC地址)
	Serial.begin(9600);
}

void loop() {
	float val = 0;
	float val2 = 0;
	float old_pos = 0;
	float new_pos = 0;
	float pos = 0;
	
	delay(5500);
	ESC1.writeMicroseconds(1000);
	ESC2.writeMicroseconds(1000);
	while (1)
	{
		new_pos = random(-180, 180);
		if (new_pos == 0)
		{
			digitalWrite(4, HIGH);
			digitalWrite(5, LOW);
		}
		pos = new_pos - old_pos;
		val2 = pos * 155 / 16 / 1.8;
		old_pos = new_pos;
		if (val2 < 0)
		{
			val = -val2;
			} else {
			val = val2;
		}//

		Serial.println(val);
		Serial.println(new_pos);
		Serial.println(pos);
		Serial.println(old_pos);
		if (1937.5 >= val2 && val2 > 0)
		{
			digitalWrite(4, HIGH);
			for (int s = 0; s <= val; s++ )
			{

				digitalWrite(5, HIGH);
				delayMicroseconds(800);
				digitalWrite(5, LOW); // Output low

				delayMicroseconds(800);

			}
		}
		else if (-1937.5 <= val2 && val2 < 0)
		{

			digitalWrite(4, LOW);
			for (int t = 0; t <= val; t++)
			{
				digitalWrite(5, HIGH);
				delayMicroseconds(800);
				digitalWrite(5, LOW); // Output low

				delayMicroseconds(800);

			}
		}
		else
		{
			digitalWrite(5, LOW);

		}

		ESC1.writeMicroseconds(1100);
		ESC2.writeMicroseconds(1100);
		delay(2000);

		ESC1.writeMicroseconds(1000);
		ESC2.writeMicroseconds(1000);

		//digitalWrite(4,HIGH);
		//digitalWrite(5,LOW);
		delay(2000);
	}
}

