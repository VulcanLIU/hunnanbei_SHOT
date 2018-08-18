 #include<Servo.h>
 #include<Wire.h>
 Servo myservo;
 Servo servol1;
 int button=2 ;
 int kai;
 void setup()

{ Serial.begin(9600);
   pinMode(6,OUTPUT); // Enable: EN可以使用单片机端口控制，也可以直接连接GND使能

  pinMode(5,OUTPUT); // steps:脉冲个数

  pinMode(4,OUTPUT); // dir:为方向控制
  pinMode(2,INPUT);
  digitalWrite(2,HIGH);
   kai=digitalRead(2);
       
 
   
   /*while(1){
    
     digitalWrite(4,HIGH);
      digitalWrite(5,HIGH);
      delayMicroseconds(800);
  digitalWrite(5,LOW); // Output low

      delayMicroseconds(800);
    
       kai=digitalRead(2);
       
      if(kai==1)
       
         break;
      }
       digitalWrite(4,HIGH);
      digitalWrite(5,LOW);*/
  myservo.attach(10);
  servol1.attach(9);
  myservo.writeMicroseconds(2000);
  servol1.writeMicroseconds(2000);
  
  delay(3500);
  myservo.writeMicroseconds(1000);
  servol1.writeMicroseconds(1000);
  delay(2000);
    pinMode(A4,INPUT);//SDA数据线
  pinMode(A5,INPUT);//SCL时钟线
   Wire.begin();        // join i2cbus (主机，不用写IIC地址)
Serial.begin(9600);

   

}

 

void loop(){
  float val=0;
  float val2=0;
  float old_pos = 0;
  float new_pos = 0;
  float pos = 0;
 
  
  
  
  delay(5500);
   myservo.writeMicroseconds(1000);
  servol1.writeMicroseconds(1000);
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
    if (1937.5 >= val2 &&val2> 0)
    {
      digitalWrite(4, HIGH);
      for (int s = 0; s <= val;s++ )
      {
        
        digitalWrite(5, HIGH);
        delayMicroseconds(800);
        digitalWrite(5, LOW); // Output low

        delayMicroseconds(800);
 
      }
    }
    else if (-1937.5 <= val2 && val2< 0)
    {

      digitalWrite(4, LOW);
      for (int t = 0; t <= val;t++)
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

  myservo.writeMicroseconds(1100);
  servol1.writeMicroseconds(1100);
  delay(2000);
  
  myservo.writeMicroseconds(1000);
  servol1.writeMicroseconds(1000);
   
     //digitalWrite(4,HIGH);
      //digitalWrite(5,LOW);
 delay(2000);
     
   
  }
  }

 
  
     
