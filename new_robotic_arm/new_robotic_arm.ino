#include <Wire.h> 


// Motor NO.1
int PWM_1 = 9;
int IN1 = 46; // choose
int IN2 = 47; // choose


// Motor NO.2
int PWM_2 = 10;
int IN3 = 50; // choose
int IN4 = 51; // choose


int con1 = 28; // ขา28
int con2 = 30; // ขา30
int con3 = 32; // ขา32

int a,b ; // for controlling the robotic arm


void setup() {
 // put your setup code here, to run once:
 // myservo.attach(servo);
  
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(PWM_1,OUTPUT);

  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);

  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  pinMode(PWM_2,OUTPUT);

  digitalWrite(IN3,LOW);
  digitalWrite(IN4,LOW);
  
  //Control Pin
  pinMode(con1,INPUT); 
  pinMode(con2,INPUT);
  pinMode(con3,INPUT);
 
  Serial.begin(9600);
  
}

void loop() {
  digitalRead(con1);
  digitalRead(con2);
  digitalRead(con3);
   
  if(digitalRead(con1) == HIGH && digitalRead(con2)  == HIGH && digitalRead(con3) == LOW ) // <---
       {
        a = 1;
       }
  else if(digitalRead(con1)== HIGH && digitalRead(con2)  == LOW && digitalRead(con3) == LOW ) //--->
        {
          a = 2;
        }
  else if(digitalRead(con1)== LOW && digitalRead(con2)  == HIGH && digitalRead(con3) == HIGH) //down
        {
          a = 3;         
        }
  else if(digitalRead(con1) == LOW && digitalRead(con2)  == LOW && digitalRead(con3) == HIGH)   //up
        {
          a = 4;       
        }
     
  else if(digitalRead(con1)== LOW && digitalRead(con2)  == LOW && digitalRead(con3) == LOW)
        {
          a = 0;
        }
  else if(digitalRead(con1)== HIGH && digitalRead(con2)  == HIGH && digitalRead(con3) == HIGH)
        {
          a = 0;
        }
  else if(digitalRead(con1) == LOW && digitalRead(con2)  == HIGH && digitalRead(con3) == LOW)   
        {
          a = 0;       
        }
  else if(digitalRead(con1) == HIGH && digitalRead(con2)  == LOW && digitalRead(con3) == HIGH)   
        {
          a = 0;       
        }
  else
  {
    a = b;
  }
  Serial.println(a);
  //delay(500);
  switch(a)
  {
    case 1:
     digitalWrite(IN1,HIGH);
     digitalWrite(IN2,LOW);
     analogWrite(PWM_1,255);
     b = 1;
     break;
    case 2:
     digitalWrite(IN1,LOW);
     digitalWrite(IN2,HIGH);
     analogWrite(PWM_1,255);
     b = 2;
     break;
    case 3:
     digitalWrite(IN3,HIGH);
     digitalWrite(IN4,LOW);
     analogWrite(PWM_2,255);
     b = 3;
     break;
    case 4:
     digitalWrite(IN3,LOW); 
     digitalWrite(IN4,HIGH);
     analogWrite(PWM_2,255);
     b = 4;
     break;
    default:
     digitalWrite(IN1,LOW); 
     digitalWrite(IN2,LOW);
     digitalWrite(IN3,LOW); 
     digitalWrite(IN4,LOW);

     b = 0;
     break;
  }
  
}

   
