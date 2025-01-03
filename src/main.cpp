#include <avr/io.h>
#include <util/delay.h>

#define F_CPU 16000000UL

#define SERVO_PIN     PB1   // Pin for the servo (OC1A, Pin 9 on Arduino Uno)
#define TRIGGER PD5
#define ECHO PD6

void servoInit()
{
  DDRB |= (1 << SERVO_PIN);
  PORTB |= (1<<SERVO_PIN);
}

void rotateServo(int angle)
{
  for(int i=0;i<50;i++)
  {
    switch(angle)
    {
     case 0:
         PORTB |= (1<<SERVO_PIN);  
         _delay_ms(0); 
         PORTB &= ~(1<<SERVO_PIN);
         _delay_ms(20); 
      break;
      case 45:
         PORTB |= (1<<SERVO_PIN);  
         _delay_ms(1); 
         PORTB &= ~(1<<SERVO_PIN);
         _delay_ms(19); 
      break;
      case 90:
         PORTB |= (1<<SERVO_PIN);  
         _delay_ms(1.5); 
         PORTB &= ~(1<<SERVO_PIN);
         _delay_ms(18.5); 
      break;
      case 135:
         PORTB |= (1<<SERVO_PIN);  
         _delay_ms(2); 
         PORTB &= ~(1<<SERVO_PIN);
         _delay_ms(18); 
      break;
      case 180:
         PORTB |= (1<<SERVO_PIN);  
         _delay_ms(2.5); 
         PORTB &= ~(1<<SERVO_PIN);
         _delay_ms(17.5); 
      break;
    }
    _delay_ms(50);
  }
}

void ultrasonicInit()
{
  DDRD |= (1 << TRIGGER);
  PORTD &= ~(1 << TRIGGER);
  DDRD &= ~(1 << ECHO);
}

void triggerUltrasonic()
{
  PORTD |= (1 << TRIGGER);
  _delay_us(10);
  PORTD &= ~(1 << TRIGGER);
}

uint16_t echoUltrasonicDuration()
{
  while (!(PIND & (1 << ECHO)));
  TCCR1B |= ((1 << CS11) | (1 << CS10));
  TCNT1 = 50536;
  while (PIND & (1 << ECHO));
  return (TCNT1-50536);
}

double distanceUltrasonic()
{
  uint16_t counts;
  
  triggerUltrasonic();
  counts = echoUltrasonicDuration();
  return(counts*4/58.0);
}



int main(void) 
{
  double distance;
    
  servoInit();
  ultrasonicInit();
  while (1) 
  {
    distance = distanceUltrasonic();
    if(distance<=5)
      rotateServo(90);
    else
      rotateServo(0);
  }
  return 0;
}
