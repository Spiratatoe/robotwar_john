//define constants 
//aka pins

//motor A
//values are the pins in ard...
const int motorA_1 = 1; //in1 
const int motorA_2 = 2; //in2 
const int motorA_en =3;

//motor B
const int motorB_1 = 4; //in1 
const int motorB_2 = 5; //in2 
const int motorB_en = 6;

//infrared sensors
const int IR1pin = A0; //keep in an analog port since it didnt work in the other ones 
const int IR2pin = A1; 



//reflectance sensor 
const int rs_1 = A2;
const int rs_2 = A3;
const int rs_3 = A4;
const int rs_4 = A5;





void setup() {

  // put your setup code here, to run once:
  Serial.begin(9600);


  //infrared stuff
  pinMode(IRpin, INPUT); // IR Sensor pin INPUT


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
  pinMode(rs_1, INPUT); //gives a number from 0 to 1023, lower means closer to white, higher means closer to black
  pinMode(control_rs_1, OUTPUT); //if high it turns on the led to get the reflexive info




  //


}

void loop() {
  // put your main code here, to run repeatedly:


  //infrared

  //this gets me a distance for which we can judge or next move 
  float distance = analogRead(IRpin);   
  Serial.println(distance);     
  delay(1000); 

  
  //reflexive
  digitalWrite(control_rs_1, HIGH);
  float light = analogRead(rs_1);
  Serial.println(light);     
  delay(250); 



  //wheel dirrection
  //make it work with sensors instead 
  if (true) {
    digitalWrite(motorA_1, HIGH);
    digitalWrite(motorA_2, LOW);
    analogWrite(motorA_en, 100);
    //rotDirection = 1;
    delay(20);
    Serial.println("rotated true");
  }


  // If button is pressed - change rotation direction
  if (false) {
    digitalWrite(motorA_1, LOW);
    digitalWrite(motorA_2, HIGH);
    analogWrite(motorA_en, 100);
    //rotDirection = 0;
    delay(20);
    Serial.println("rotated false");
  }



}

