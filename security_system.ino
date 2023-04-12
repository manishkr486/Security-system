// BY MANISH :)
#include <dht11.h>
#include<Servo.h>
#define DHT11PIN 4
Servo myservo;
int test_led = 11;

int vibration_sensor =10;

int buzzer_pin = 9;
int pirSensor = 8;
dht11 DHT11;

void setup() {
pinMode(test_led,OUTPUT);
pinMode(pirSensor, INPUT);
pinMode(buzzer_pin, OUTPUT);
pinMode(vibration_sensor,INPUT);
myservo.attach(6);
Serial.begin(9600);

}

int dht_data()
{
Serial.println();

int chk = DHT11.read(DHT11PIN);

Serial.print("Humidity (%): ");
Serial.println((float)DHT11.humidity, 2);

Serial.print("Temperature (C): ");
Serial.println((float)DHT11.temperature, 2);

delay(100);

}

void loop()
{
int sensorValue = digitalRead(pirSensor);
Serial.print("Sensor value:");
Serial.println(sensorValue);
int vibrationValue = digitalRead(vibration_sensor);
Serial.print("Vibrator Value:");
Serial.println(vibrationValue);
if( sensorValue==1 && vibrationValue==0 )
{
dht_data();
Serial.println("NO Motion detcted\n");
digitalWrite(buzzer_pin,LOW);
digitalWrite(test_led,LOW);
// myservo.write(0);
delay(100);
Serial.println("Motor is stop\n");
delay(100);

}
else if( sensorValue==0 || vibrationValue==1 )
{
dht_data();
Serial.println("Motion detcted \n"); // for motion detect
digitalWrite(buzzer_pin,HIGH); // for buzzer
digitalWrite(test_led,HIGH);
myservo.write(200);
delay(100);
Serial.println("Motor is running\n");
delay(100);

}
}
