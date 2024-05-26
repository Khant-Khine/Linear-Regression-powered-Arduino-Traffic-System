//Name: Khant Khine
//Course: CS-470
//Brief: Arduino file to be uploaded to Arduino for Serial communication with Python file.

  #define ECHO_TOP 2
  #define TRIG_TOP 3
  #define ECHO_RIGHT 4
  #define TRIG_RIGHT 5
  #define RED_TOP 6
  #define YELLOW_TOP 7
  #define GREEN_TOP 8
  #define RED_RIGHT 9
  #define YELLOW_RIGHT 10
  #define GREEN_RIGHT 11
  #define TRAFFIC_CAM_TOP 12
  #define TRAFFIC_CAM_RIGHT 13
  #define PEDESTRIAN_TOP A0
  #define PEDESTRIAN_RIGHT A1
  String incomingDecision;

void setup() 
{
  Serial.begin(9600);
  pinMode(ECHO_TOP, INPUT);
  pinMode(TRIG_TOP, OUTPUT);
  pinMode(ECHO_RIGHT, INPUT);
  pinMode(TRIG_RIGHT, OUTPUT);
  pinMode(RED_TOP, OUTPUT);
  pinMode(YELLOW_TOP, OUTPUT);
  pinMode(GREEN_TOP, OUTPUT);
  pinMode(RED_RIGHT, OUTPUT);
  pinMode(YELLOW_RIGHT, OUTPUT);
  pinMode(GREEN_RIGHT, OUTPUT);
  pinMode(TRAFFIC_CAM_TOP, OUTPUT);
  pinMode(TRAFFIC_CAM_RIGHT, OUTPUT);
  pinMode(PEDESTRIAN_TOP, OUTPUT);
  pinMode(PEDESTRIAN_RIGHT, OUTPUT);
}

void loop() 
{
  //North South
  TrafficLight(RED_TOP, RED_RIGHT, YELLOW_TOP, GREEN_TOP, PEDESTRIAN_TOP, PEDESTRIAN_RIGHT, TRAFFIC_CAM_TOP, TRIG_TOP, ECHO_TOP, 0, 0);

  //East West
  TrafficLight(RED_TOP, RED_RIGHT, YELLOW_RIGHT, GREEN_RIGHT, PEDESTRIAN_TOP, PEDESTRIAN_RIGHT, TRAFFIC_CAM_RIGHT, TRIG_RIGHT, ECHO_RIGHT, 1, 1);
}

void TrafficLight(int red_top, int red_right, int yellow, int green, int pedestrian_top, int pedestrian_right, int traffic_cam, int trig, int echo, int direction, int turn)
{
  //Traffic Intersection makes all lights red.
  digitalWrite(red_top, HIGH);
  digitalWrite(red_right, HIGH);
  delay(500);

  //Pedestrian Lights for pedestrian crossing turn on and off.
  digitalWrite(pedestrian_top,HIGH);
  digitalWrite(pedestrian_right,HIGH);
  delay(1000);
  digitalWrite(pedestrian_top,LOW);
  digitalWrite(pedestrian_right,LOW);

  //Red Light turns off.
  delay(500);
  if(direction == 0)
  {
    digitalWrite(red_top, LOW);
  }

  else
  {
    digitalWrite(red_right, LOW);
  }

  //Green Light turns on and off.
  digitalWrite(green, HIGH);
  delay(2000);
  digitalWrite(green, LOW);

  //Yellow Light turns on and off.
  digitalWrite(yellow, HIGH);
  delay(1500);
  readSpeed(trig, echo, yellow, traffic_cam, turn);
  delay(500);
  digitalWrite(yellow, LOW);
}

void readSpeed(int trig, int echo, int yellow, int traffic_cam, int turn)
{
  //Distance 1 trigger
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  //Distance 1 Measurement
  int duration1 = pulseIn(echo, HIGH);
  Serial.println(duration1);
  float distanceMeters1=(duration1*343.0)/20000.0;
  Serial.println(distanceMeters1);
  //Eliminate Interference
  delay(100);

  //Distance 2 trigger
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  //Distance 2 measurement
  int duration2 = pulseIn(echo, HIGH);
   //Serial.println(duration2);
  float distanceMeters2=(duration2*343.0)/20000.0;
  //Serial.println(distanceMeters2);

  //Measure speed
  float avgDistanceMiles = (distanceMeters1 + distanceMeters2) / 2.0;
  float timeHours = 0.1;
  float speed=(avgDistanceMiles/timeHours)*20.0;
  Serial.print(speed);
  
  if(turn==1)
  {
     digitalWrite(traffic_cam, HIGH);
      delay(900);
      digitalWrite(traffic_cam, LOW);
  }
  //Read Serial
  delay(1000);
 if (Serial.available()) 
 {
    incomingDecision = Serial.read();

     //If Yellow light extension is activated
    if (incomingDecision == 1)
    {
  
      //Speed camera turned on.
    }
  }
}