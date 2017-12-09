//Constants (declaration of PINs in Arduino)
const int readBoxPin = A0; //Pressure Sensor 1
const int focusBoxPin = A1; //Pressure Sensor 2

const int redColorPin = 6; //Red
const int blueColorPin = 5; //Blue
const int greenColorPin = 4; //Green

const int laptopLightPin = A3; 

const int bookLightPin = A4; 
const int readLedPin = 7;

//Variables:
int valueReadBox, valueFocusBox, valueLaptopLight, valueBookBox;     

void setup(){  
  pinMode(redColorPin, OUTPUT);
  pinMode(blueColorPin, OUTPUT);
  pinMode(greenColorPin, OUTPUT);
  pinMode(readLedPin, OUTPUT);
  Serial.begin(9600);       
}

void loop(){
  
  valueReadBox = analogRead(readBoxPin);          //Read and save analog value from press sensor for read mode  - red color
  valueFocusBox = analogRead(focusBoxPin);         //Read and save analog value from press sensor for focus mode - white color
  valueLaptopLight = analogRead(laptopLightPin) / 4;  //Read and save analog value from photoresistor for turning of the lights - white color
  
  valueBookBox = analogRead(bookLightPin) / 4;     //Read and save analog value from photoresistor in book storage box
  
  printSensorValues();
  setMainLight();                               //checking the press sensor from boxes and laptop sensor, and setting the color of light or turning off the light
  setReadingLight();                            //checking the sensor in storage box for book and setting reading light
  delay(500);                               //Small delay
  
}

void setColor(int R, int G, int B){
  analogWrite(redColorPin, R); 
  analogWrite(greenColorPin, G); 
  analogWrite(blueColorPin, B); 
}

void printSensorValues(){
  Serial.print("ReadSensor: ");
  Serial.print(valueReadBox);              
  Serial.print("\tFocusSensor 2: ");
  Serial.print(valueFocusBox);
  Serial.print("\tLaptopSensor: ");
  Serial.print(valueLaptopLight);
  Serial.print("\tBookSensor: ");
  Serial.println(valueBookBox);
}

void setMainLight(){  
  if(valueLaptopLight < 20){    //if laptop screen is closed - the light is turned off - POTENTIAL UPGRADE - add timer for letting the light turned on for next 30-60 secs
    setColor(0,0,0); 
  } else if(valueReadBox > 100){
    setColor(255,0,0);        //red chilly mode
  } else if(valueFocusBox > 100){
    setColor(255,255,255);    //white focus mode
  } else{
     setColor(0,0,0);          //turn off the light
  }    
}

void setReadingLight(){
  if(valueBookBox > 50){                     //if book is present in the storage book
      digitalWrite(readLedPin, HIGH);       //turn on the LED diod
  } else {
      digitalWrite(readLedPin, LOW);        //turn off the LED diod
  }
}

