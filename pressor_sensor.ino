/* How to use a Force sensitive resistor to fade an LED with Arduino
   More info: http://www.ardumotive.com/how-to-use-a-force-sensitive-resistor-en.html 
   Dev: Michalis Vasilakis // Date: 22/9/2015 // www.ardumotive.com  */
   

//Constants:
//const int ledPin = 3;     //pin 3 has PWM funtion
const int sensorPin1 = A0; //Pressure Sensor 1 - A0
const int sensorPin2 = A1; //Pressure Sensor 2 - A1

const int redColorPin = 6; //Red
const int blueColorPin = 5; //Blue
const int greenColorPin = 4; //Green

const int laptopLightPin = A3; //Green

//Variables:
int value1, value2, value3; //save analog value


void setup(){
  
  pinMode(redColorPin, OUTPUT);
  pinMode(blueColorPin, OUTPUT);
  pinMode(greenColorPin, OUTPUT);
  Serial.begin(9600);       //Begin serial communication

}

void loop(){
  
  value1 = analogRead(sensorPin1);       //Read and save analog value from potentiometer
  value2 = analogRead(sensorPin2);       //Read and save analog value from potentiometer 
  value3 = analogRead(laptopLightPin) / 4;
  Serial.print("Sensor 1: ");
  Serial.print(value1);               //Print value
  Serial.print("\tSensor 2: ");
  Serial.print(value2);
  Serial.print("\tPR: ");
  Serial.println(value3);
  //value = map(value, 0, 1023, 0, 255); //Map value 0-1023 to 0-255 (PWM)

  if(value3 < 20){
    setColor(0,0,0); 
  }
  else if(value1 > 100){
    setColor(255,0,0);        //red chilly mode
  }
  else if(value2 > 100){
    setColor(255,255,255);    //white focus mode
  } else{
    setColor(0,0,0);          //turn off the light
  }
  
  //  analogWrite(redColorPin, 100); 
  //analogWrite(greenColorPin, 100); 
  //analogWrite(blueColorPin, 100); 
   //setColor(255,0,0); 
        
  delay(500);                          //Small delay
  
}

void setColor(int R, int G, int B){
  analogWrite(redColorPin, R); 
  analogWrite(greenColorPin, G); 
  analogWrite(blueColorPin, B); 
}

