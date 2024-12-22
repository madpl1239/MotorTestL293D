/*
 * MotorTestL293D.ino
 * 
 * 22-12-2024 by madpl (Bogdan K.)
 */
#define MOTORTEST 1
#define STOPPED 0

bool MOVE = true;
const int SPEED = 130;

// motor 1
const int mot1a = D2;
const int mot1b = D4;
const int pwm1 = D3;

// motor 2
const int mot2a = D7;
const int mot2b = D8;
const int pwm2 = D5;


void setup(void)
{
  pinMode(mot1a, OUTPUT);
  pinMode(mot1b, OUTPUT);
  pinMode(pwm1, OUTPUT);
  analogWrite(pwm1, STOPPED);
  digitalWrite(mot1a, LOW);
  digitalWrite(mot1b, LOW);

  pinMode(mot2a, OUTPUT);
  pinMode(mot2b, OUTPUT);
  pinMode(pwm2, OUTPUT);
  analogWrite(pwm2, STOPPED);
  digitalWrite(mot2a, LOW);
  digitalWrite(mot2b, LOW);
}


void stop(void)
{
  analogWrite(pwm1, STOPPED);
  digitalWrite(mot1a, LOW);
  digitalWrite(mot1b, LOW);

  analogWrite(pwm2, STOPPED);
  digitalWrite(mot2a, LOW);
  digitalWrite(mot2b, LOW);
}


void forward(int pwm)
{
  analogWrite(pwm1, pwm);
  digitalWrite(mot1b, LOW);
  digitalWrite(mot1a, HIGH);
  
  analogWrite(pwm2, pwm);
  digitalWrite(mot2b, LOW);
  digitalWrite(mot2a, HIGH);
}


void backward(int pwm)
{
  analogWrite(pwm1, pwm);
  digitalWrite(mot1a, LOW);
  digitalWrite(mot1b, HIGH);
  
  analogWrite(pwm2, pwm);
  digitalWrite(mot2a, LOW);
  digitalWrite(mot2b, HIGH);
}


void loop(void)
{
  stop();
  delay(500);

  if(MOVE)
  {
    forward(SPEED);
    delay(1000);

    stop();
    delay(1000);

    backward(SPEED);
    delay(1000);
    MOVE = false;
  }

  stop();
}
