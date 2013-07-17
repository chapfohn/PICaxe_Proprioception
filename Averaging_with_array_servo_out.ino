#include <Servo.h>
Servo servoMain; // Define Servo
//git TEST test
const  int  xIn = 2;                  //set pin to read Xaxis accelerometer
const  int  yIn = 4;                  //set pin to read Yaxis accelerometer
const  int  LED = 13;                 //set pin to LED flag

const  int  n   = 10;

int         score = 0; 
int         angle = 0;

void setup() {
  Serial.begin(9600);                      //set baud rate for serial communication with Serial Monitor (debug)
  //servoMain.attach(10);                    //identify pin to servo
  //servoMain.write(0);                      //initialise servo to 0c
  delay(20);                               //pause to allow servo initialisation
}

void loop() {
  pinMode(LED, OUTPUT);                   //set LED pin to output 
  
  word pulseXT =0, pulseYT = 0;           //variable declaration and initalisation, word size for summation
  
  int  pulseXa, pulseYa;                  //variable declaration, axis average 
  int  pulseX[n], pulseY[n];              //variable declaration, array type for idividual axis readings
  int  i, j;                              //index declarations
  
  for (i = 0; i < n; i = i + 1) {          //read axis pulses into respective arrays
    pulseX[i] = pulseIn (xIn, HIGH);  
    pulseY[i] = pulseIn (yIn, HIGH);
    delay (1);
  }
  
   for (j = 0; j < n; j = j + 1) {        //summation of respective axis pulses
    pulseXT = pulseXT+pulseX[j];
    pulseYT = pulseYT+pulseY[j];
  }
  pulseXa = pulseXT/n;                    //average Xaxis
  
  pulseYa = pulseYT/n;                    //average Xaxis
  
  if (pulseXa < 5000 && pulseXa >4900 && pulseYa < 5000 && pulseYa >4900 ){  //Set stability limits for comparison
    Serial.print ("STABLE ");
    Serial.print ("\t");                  //tab
    Serial.print ("\t");
    Serial.print ("Xaxis = ");            
    //Serial.print ("\t");
    Serial.print (pulseXa);                //print Xaxis value
    Serial.print ("\t");
    Serial.print ("Yaxis = ");
    //Serial.print ("\t");
    Serial.print (pulseYa);                //print Yaxis value
    Serial.print ("\t");
    score = score + 1;                     //update score
    Serial.print ("Score = ");
    Serial.println (score);                //print score
    if (score == 4) {
      servoMain.write(angle);              //move servo
      digitalWrite(LED, 1);
      delay (1000);
      digitalWrite(LED, 0);
      delay(20);
      //angle = angle + 15;                //increment servo
      score = 0;                           //reset score
    }
  }
  else {
    Serial.print ("UNSTABLE ");
    Serial.print ("\t");
    //Serial.print ("\t");
    Serial.print ("Xaxis = ");
    //Serial.print ("\t");
    Serial.print (pulseXa);                //print Xaxis value
    Serial.print ("\t");
    Serial.print ("Yaxis = ");
    //Serial.print ("\t");
    Serial.print (pulseYa);                //print Yaxis value
    Serial.print ("\t");
    score = 0;                             //reset score
    Serial.print ("Score = ");
    Serial.println (score);                //print score
  }
  delay (100);
}




