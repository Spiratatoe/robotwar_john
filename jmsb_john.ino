//define constants 
//aka pins

//motor A
//values are the pins in ard...
const int motorA_1 = 1; //in1 
const int motorA_2 = 2; //in2 
const int motorA_en = 3;

//motor B
const int motorB_1 = 4; //in1 
const int motorB_2 = 5; //in2 
const int motorB_en = 6;

//infrared sensors
const int IR1pin = A0; //keep in an analog port since it didnt work in the other ones 
const int IR2pin = A1; 


//reflectance sensor 
const int rs_top_right = A2;
const int rs_top_left = A3;
const int rs_bottom_right = A4;
const int rs_bottom_left = A5;

//button
const int button = 50;
int button_not_pressed = true;




void setup() {

  // put your setup code here, to run once:
  Serial.begin(9600);

  //button
  pinMode(button, INPUT);

  //infrared stuff
  pinMode(IR1pin, INPUT); // IR Sensor pin INPUT
  pinMode(IR2pin, INPUT); // IR Sensor pin INPUT

  // //motor A setup
  pinMode(motorA_en, OUTPUT); //motor speed 0 to 255, however max it at 100 to not fry 
  pinMode(motorA_1, OUTPUT);
  pinMode(motorA_2, OUTPUT);
  // // Set initial rotation direction
  // //to go in a direction they have to be opposing, swithcing which one is high and low makes it go forward or backward 
  digitalWrite(motorA_1, LOW);
  digitalWrite(motorA_2, HIGH);


  //motor B setup

  //reflexive stuff
  pinMode(rs_top_right, INPUT); //gives a number from 0 to 1023, lower means closer to white, higher means closer to black
  pinMode(rs_top_left, INPUT); //gives a number from 0 to 1023, lower means closer to white, higher means closer to black
  pinMode(rs_bottom_right, INPUT); //gives a number from 0 to 1023, lower means closer to white, higher means closer to black
  pinMode(rs_bottom_right, INPUT); //gives a number from 0 to 1023, lower means closer to white, higher means closer to black


  //


}

void loop() {
  // put your main code here, to run repeatedly:
  
  //button code
  //on initial boot, make it wait 3 seconds for start-up
  boolean current = digitalRead(button);
  if(current && button_not_pressed){
    delay(3000); 
    button_not_pressed = false;
  }
  

  //infrared
  //this gets me a distance for which we can judge or next move 
  float distanceRight = analogRead(IR1pin);
  float distanceLeft = analogRead(IR2pin);  
  Serial.println(distanceRight);  
  Serial.println(distanceLeft);    
  //delay(1000); 

  
  //reflexive
  float light_tr = analogRead(rs_top_right);
  float light_tl = analogRead(rs_top_left);
  float light_br = analogRead(rs_bottom_right);
  float light_bl = analogRead(rs_bottom_left);
  Serial.println(light_tr);
  Serial.println(light_tl);
  Serial.println(light_br);
  Serial.println(light_bl);
  //delay(250); 


  //logic loop

  if(rs_top_right < 400 && rs_top_left < 400){
    //if both top hit white, go backward
    goBackward();
  }
  else if(rs_bottom_right < 400 && rs_bottom_left < 400){
    //if both back hit white go forward
    //maybe max out the speed !!!
    goForward();
  }
  else if(rs_bottom_right < 400 && rs_top_right < 400){
    //right side on white go left while moving forward
    goLeftForward();
  }
  else if(rs_bottom_left < 400 && rs_top_left < 400){
    //left side on white go right while moving forward
    goRightForward();
  }
  else if(rs_top_right < 400){
    //this means it hit a white 
    goRightBackward();
  }
  else if(rs_top_left < 400){
    //this means it hit a white 
    goLeftBackward();
  }
  else if(rs_bottom_right < 400){
    //this means it hit a white 
    goRightForward();
  }
   else if(rs_bottom_left < 400){
    //this means it hit a white 
    goLeftForward();
  }
  else if (distanceRight < 31 && distanceLeft<31) {
    goForward();
  }
  else if(distanceRight < 31 && distanceLeft > 31){
    //nothing on left side 
    //however we see it to the right
    goRightForward();

  }
  else if(distanceRight > 31 && distanceLeft < 31){
    //nothing on left side 
    //however we see it to the right
    goLeftForward();

  }
  else{
    //both scanners see nothing
    //colors see nothing
    //we can't not move for long so pivot
    goLeftPivot();
  }


}





void goLeftForward(){
  digitalWrite(motorA_1, HIGH);  
  digitalWrite(motorA_2, HIGH);
  analogWrite(motorA_en, 100);

  digitalWrite(motorB_1, HIGH);
  digitalWrite(motorB_2, HIGH);
  analogWrite(motorB_en, 50);
}
void goLeftBackward(){
  digitalWrite(motorA_1, LOW);  
  digitalWrite(motorA_2, LOW);
  analogWrite(motorA_en, 100);

  digitalWrite(motorB_1, LOW);
  digitalWrite(motorB_2, LOW);
  analogWrite(motorB_en, 50);
}

void goLeftPivot(){
  digitalWrite(motorA_1, LOW);
  digitalWrite(motorA_2, LOW);
  analogWrite(motorA_en, 100);

  digitalWrite(motorB_1, HIGH);
  digitalWrite(motorB_2, HIGH);
  analogWrite(motorB_en, 100);
}

void goRightForward(){
  digitalWrite(motorA_1, HIGH);  
  digitalWrite(motorA_2, HIGH);
  analogWrite(motorA_en, 50);

  digitalWrite(motorB_1, HIGH);
  digitalWrite(motorB_2, HIGH);
  analogWrite(motorB_en, 100);
}

void goRightBackward(){
  digitalWrite(motorA_1, LOW);  
  digitalWrite(motorA_2, LOW);
  analogWrite(motorA_en, 50);

  digitalWrite(motorB_1, LOW);
  digitalWrite(motorB_2, LOW);
  analogWrite(motorB_en, 100);
}

void goRightPivot(){
  digitalWrite(motorA_1, HIGH);
  digitalWrite(motorA_2, HIGH);
  analogWrite(motorA_en, 100);

  digitalWrite(motorB_1, LOW);
  digitalWrite(motorB_2, LOW);
  analogWrite(motorB_en, 100);
}

void goForward(){
  //both motors should go forward

  digitalWrite(motorA_1, HIGH);
  digitalWrite(motorA_2, HIGH);
  analogWrite(motorA_en, 100);

  digitalWrite(motorB_1, HIGH);
  digitalWrite(motorB_2, HIGH);
  analogWrite(motorB_en, 100);

  Serial.println("Straight");

}
void goBackward(){
  //both motors should go forward

  digitalWrite(motorA_1, LOW);
  digitalWrite(motorA_2, LOW);
  analogWrite(motorA_en, 100);

  digitalWrite(motorB_1, LOW);
  digitalWrite(motorB_2, LOW);
  analogWrite(motorB_en, 100);

  Serial.println("Backwards");

}
void goNowhere(){
  analogWrite(motorA_en, 0);
  analogWrite(motorB_en, 0);
  Serial.println("Nowhere");
}

