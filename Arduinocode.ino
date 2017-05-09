*Arduino Code*

//String bluetoothdata;

//String compare="on";
//String compare2="off";
//int ledpin=13;
//#include<SoftwareSerial.h>
//SoftwareSerial Genotronex(11,12);
int motor1pin1=9;
int motor1pin2=8;
int motor2pin1=7;
int motor2pin2=6;
int enable1=10;
int enable2=5;
char state;
int flag;
void setup() {
   pinMode(motor1pin1,OUTPUT);
   
  pinMode(motor1pin2,OUTPUT);
  pinMode(motor2pin1,OUTPUT);
  pinMode(motor2pin2,OUTPUT);
  pinMode(enable1,OUTPUT);
  pinMode(enable2,OUTPUT);
  Serial.begin(9600);
  Serial.println("sacgtwdgc");
 // pinMode(ledpin,OUTPUT);
//  digitalWrite(ledpin,HIGH);//
}
  // put your setup code here, to run once:


void loop() {
 if(Serial.available())
  {
 state=Serial.read();
    //Serial.println("lkdsf");
    //Serial.println(bluetoothdata);
   // if (bluetoothdata==compare)
  //  {
    //  digitalWrite(ledpin,HIGH);
    //  Serial.println("high") ;
     // delay(1000);}
     //if(bluetoothdata==compare2)
      //{ digitalWrite(ledpin,LOW);
      //Serial.println("low") ;
     // delay(1000);}
  //}delay(100);//
  // put your main code here, to run repeatedly:


     flag=0;
  
  }

  if(state == 'F')
  {
    forward();
    if(flag == 0){ Serial.println( "forward");flag=1;}
  }
    else if(state == 'R')
  {
    right();
   if(flag == 0){ Serial.println( "right");flag=1;}
   
  }
    else if(state == 'L')
  {
    left();
    if(flag == 0){Serial.println("left");flag=1;}
  
  }
    else if(state == 'B')
  {
    reverse();
   if(flag == 0){ Serial.println( "back");flag=1;}
  }
    else if(state == 'S')
  {
     stop();
     
    if(flag == 0){ Serial.println( "stop");flag=1;}
  }
  



}
void  reverse()
{
  digitalWrite(motor1pin1,HIGH);
  digitalWrite(motor1pin2,LOW);
  digitalWrite(motor2pin1,LOW);
  digitalWrite(motor2pin2,HIGH);
  digitalWrite(enable1,HIGH);
  digitalWrite(enable2,HIGH);
}
void forward()
{
 digitalWrite(motor1pin1,LOW);
  digitalWrite(motor1pin2,HIGH);
  digitalWrite(motor2pin1,HIGH);
  digitalWrite(motor2pin2,LOW);
  digitalWrite(enable1,HIGH);
  digitalWrite(enable2,HIGH);
}
void left()
{
   digitalWrite(enable1,HIGH);
  digitalWrite(enable2,HIGH);
   digitalWrite(motor1pin1,HIGH);
   delay(200);
  digitalWrite(motor1pin2,HIGH);
  digitalWrite(motor2pin1,HIGH);
  delay(200);
  digitalWrite(motor2pin2,HIGH);
  
}
void right()
{
   digitalWrite(motor1pin1,HIGH);
  digitalWrite(motor1pin2,HIGH);
  delay(200);
  digitalWrite(motor2pin1,HIGH);
  digitalWrite(motor2pin2,HIGH);
  delay(200);
  digitalWrite(enable1,HIGH);
  digitalWrite(enable2,HIGH);
  
}
void stop()
{
  digitalWrite(motor1pin1,LOW);
  digitalWrite(motor1pin2,LOW);
  digitalWrite(motor2pin1,LOW);
  digitalWrite(motor2pin2,LOW);
  digitalWrite(enable1,LOW);
  digitalWrite(enable2,LOW);
}
