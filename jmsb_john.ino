//define constants 
//aka pins

//motor A
//values are the pins in ard...
const int motorA_1 = 1; //in1 
const int motorA_2 = 2; //in2 
const int motorA_en = 3;

//infrared sensor
const int IRpin = 4; 





void setup() {

  // put your setup code here, to run once:
  Serial.begin(9600);


  //infrared stuff
  

  //motor A setup
  pinMode(motorA_en, OUTPUT); //motor speed 0 to 255
  pinMode(motorA_1, OUTPUT);
  pinMode(motorA_2, OUTPUT);
  // Set initial rotation direction
  //to go in a direction they have to be opposing, swithcing which one is high and low makes it go forward or backward 
  digitalWrite(motorA_1, LOW);
  digitalWrite(motorA_2, HIGH);


   




  //


}

void loop() {
  // put your main code here, to run repeatedly:


  //infrared
  //this gets me a distance for which we can judge or next move 
  float volts = analogRead(IRpin)*0.0048828125;   
  float distance = 65*pow(volts, -1.10);   
  Serial.print(distance);     
  Serial.println(" cm");
  delay(100); 

  //wheel dirrection
  //If button is pressed - change rotation direction
  //make it work with sensors instead 
  if (pressed == true  & rotDirection == 0) {
    digitalWrite(motorA_1, HIGH);
    digitalWrite(motorA_2, LOW);
    rotDirection = 1;
    delay(20);
  }
  // If button is pressed - change rotation direction
  if (pressed == false & rotDirection == 1) {
    digitalWrite(motorA_1, LOW);
    digitalWrite(motorA_2, HIGH);
    rotDirection = 0;
    delay(20);
  }



}

