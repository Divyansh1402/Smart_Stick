// defines pins numbers
const int trigPin = 9;
const int echoPin = 10;
const int buzzer = 12;
const int ledPin = 13;
const int viberator = 5;
const int set_dist = 60; // Distance can be changed accordingly
int dist;
// defines variables
long duration;
int distance;
int safetyDistance;
bool objectDetected = false;
void setup() {
 pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
 pinMode(echoPin, INPUT); // Sets the echoPin as an Input
 pinMode(buzzer, OUTPUT);
 pinMode(ledPin, OUTPUT);
 pinMode(viberator, OUTPUT);
 Serial.begin(9600); // Starts the serial communication
}
void sound_inte(int x, int pin) {
 if (x > 0.3 * set_dist) {
 dist = 255 - 3 * x; // Adjusting the buzzer intensity for distance 60
 } else {
 dist = 255;
 }
 analogWrite(pin, dist);
}
void loop() {
 // Clears the trigPin
 digitalWrite(trigPin, LOW);
 delayMicroseconds(2);
 // Sets the trigPin on HIGH state for 10 microseconds
 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10);
 digitalWrite(trigPin, LOW);
 // Reads the echoPin, returns the sound wave travel time in microseconds
 duration = pulseIn(echoPin, HIGH);
 // Calculating the distance
 distance = duration * 0.034 / 2;
 safetyDistance = distance;
 
 if (safetyDistance <= set_dist) {
 digitalWrite(ledPin, HIGH);
 sound_inte(distance, buzzer);
 sound_inte(distance, viberator);
 objectDetected = true;
 } else {
 digitalWrite(buzzer, LOW);
 digitalWrite(viberator, LOW);
 digitalWrite(ledPin, LOW);
 objectDetected = false;
 }
}