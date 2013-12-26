int rowPins[8] = {9,3,2,12,15,11,7,6};         // matrix rows connected to the Arduino
int colPins[8] = {13,8,17,10,5,16,4,14};       // matrix columns connected to the Arduino

int sensorPin = A6;    // select the input pin for the sensor
int sensorValue = 0;  // variable to store the value coming from the sensor

int smilyFace[8][8]={                              // the image displayed on the matrix : 1 = LED on, 0 = LED off
{0,0,0,0,0,0,0,0},  
{0,1,1,0,0,1,1,0},
{0,1,1,0,0,1,1,0},
{0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0},
{1,0,0,0,0,0,0,1},
{0,1,1,1,1,1,1,0},
{0,0,0,0,0,0,0,0}
                }; 

int dashFace[8][8]={                              // the image displayed on the matrix : 1 = LED on, 0 = LED off
{0,0,0,0,0,0,0,0},  
{0,1,1,0,0,1,1,0},
{0,1,1,0,0,1,1,0},
{0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0},
{1,1,1,1,1,1,1,1},
{0,0,0,0,0,0,0,0}
                }; 

int sadFace[8][8]={                              // the image displayed on the matrix : 1 = LED on, 0 = LED off
{0,0,0,0,0,0,0,0},  
{0,1,1,0,0,1,1,0},
{0,1,1,0,0,1,1,0},
{0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0},
{0,1,1,1,1,1,1,0},
{1,0,0,0,0,0,0,1}
                };                      

void setup(){
  Serial.begin(9600);
  
  for (int i=0; i<8; i++){                       // all pins are declared as outputs 
    pinMode(rowPins[i],OUTPUT);
    pinMode(colPins[i],OUTPUT);
  }
}

void smile()
{
  for (int y=0; y<8; y++){                       
    // rowwise 
    for (int x=0; x<8; x++){                     
      // check all entries of the array from left to right 
      if (smilyFace[x][y]==1){                       
        // is the entry 1
        digitalWrite(colPins[x],HIGH);           
        // switch on column pin
      } else {                                   
        // else
        digitalWrite(colPins[x],LOW);            
        // switch it off
      }
    }
    
    digitalWrite(rowPins[y],LOW);                
    // switch the row pin to LOW (because it is the cathode of the LED; LOW means ON)
    delayMicroseconds(100);                      
    // stop the program for 100 milliseconds
    digitalWrite(rowPins[y],HIGH);               
    // switch the row pin to HIGH (this means OFF)
  }
}

void dash()
{
  for (int m=0; m<8; m++){                       
    // rowwise 
    for (int n=0; n<8; n++){                     
      // check all entries of the array from left to right 
      if (dashFace[n][m]==1){                       
        // is the entry 1
        digitalWrite(colPins[n],HIGH);           
        // switch on column pin
      } else {                                   
        // else
        digitalWrite(colPins[n],LOW);            
        // switch it off
      }
    }
    
    digitalWrite(rowPins[m],LOW);                
    // switch the row pin to LOW (because it is the cathode of the LED; LOW means ON)
    delayMicroseconds(100);                      
    // stop the program for 100 milliseconds
    digitalWrite(rowPins[m],HIGH);               
    // switch the row pin to HIGH (this means OFF)
  }
}

void sad()
{
  for (int p=0; p<8; p++){                       
    // rowwise 
    for (int q=0; q<8; q++){                     
      // check all entries of the array from left to right 
      if (sadFace[q][p]==1){                       
        // is the entry 1
        digitalWrite(colPins[q],HIGH);           
        // switch on column pin
      } else {                                   
        // else
        digitalWrite(colPins[q],LOW);            
        // switch it off
      }
    }
    
    digitalWrite(rowPins[p],LOW);                
    // switch the row pin to LOW (because it is the cathode of the LED; LOW means ON)
    delayMicroseconds(100);                      
    // stop the program for 100 milliseconds
    digitalWrite(rowPins[p],HIGH);               
    // switch the row pin to HIGH (this means OFF)
  }
  
}


void loop()
{
  sensorValue = analogRead(sensorPin);// reading sensor value
  //delay(2000);
  //#############for serial debugging
  //Serial.print("Moisture param: ");
  //Serial.println(sensorValue);
  //#############
  
       if (sensorValue <= 100){      
        sad();
       }else if(sensorValue >= 600){
        smile();
       }else if((sensorValue < 600) && (sensorValue > 100)){
        dash();
       }
       
       //sad();
       //delay(5000);
       //smile();
       //delay(5000);
       //dash();
       //delay(5000);
   }
  
