/*
*Code modified from omgdanieltam/sdvx_leonardo by Daniel Tam (daniel@danieltam.net)
*/

// buttons
#define BT_Z 4
#define BT_X 5
#define BT_C 6
#define BT_V 7
#define BT_S 8
#define BT_D 9
#define BT_F 10

#define BT_Q 15
#define BT_W 14
#define BT_E 16

// encoders
#include <Encoder.h>
#include <Mouse.h>
#include <Keyboard.h>


Encoder enc2(2, 3);
float knob2 = 0;
float old_knob2 = 0;



void setup()
{ 
  // set pins to read, and output high
  // when the pins read low, we know that the buttons have went to ground (aka, pushed down)
  pinMode(BT_Z, INPUT);
  pinMode(BT_X, INPUT);
  pinMode(BT_C, INPUT);
  pinMode(BT_V, INPUT);
  pinMode(BT_S, INPUT);
  pinMode(BT_D, INPUT);
  pinMode(BT_F, INPUT);

  pinMode(BT_Q, INPUT);
  pinMode(BT_W, INPUT);
  pinMode(BT_E, INPUT);

  
  digitalWrite(BT_Z, HIGH);
  digitalWrite(BT_X, HIGH);
  digitalWrite(BT_C, HIGH);
  digitalWrite(BT_V, HIGH);
  digitalWrite(BT_S, HIGH);
  digitalWrite(BT_D, HIGH);
  digitalWrite(BT_F, HIGH);

  digitalWrite(BT_Q, HIGH);
  digitalWrite(BT_W, HIGH);
  digitalWrite(BT_E, HIGH);
  
  Mouse.begin();
  Keyboard.begin();
//  Serial.begin(9600);
}

void loop()
{

  // read encoders
  knob2 = (float)enc2.read();
  
  if(knob2 != old_knob2)
  {
    //Serial.println(knob2);
    if(knob2 - old_knob2 >0)
    {
     
      Mouse.move(0, -5);
    }
    else
    {
     
      Mouse.move(0, 5);
    }
      if(knob2 < -255)
    {
      enc2.write(0);
      old_knob2 = 0;
    }
    else if(knob2 > 255)
    {
      enc2.write(0);
      old_knob2 = 0;
    }
    else
    {
      old_knob2 = knob2;
    }
  }

  // read the buttons for low, if it's low, output a keyboard press  
  if(digitalRead(BT_Z) == LOW)
  {
    Keyboard.press('z');
  }
  else
  {
    Keyboard.release('z');
  }
  
  if(digitalRead(BT_X) == LOW)
  {
    Keyboard.press('x');
  }
  else
  {
    Keyboard.release('x');
  }
  
  if(digitalRead(BT_C) == LOW)
  {
    Keyboard.press('c');
  }
  else
  {
    Keyboard.release('c');
  }
  
  if(digitalRead(BT_V) == LOW)
  {
    Keyboard.press('v');
  }
  else
  {
    Keyboard.release('v');
  }
  
  if(digitalRead(BT_S) == LOW)
  {
    Keyboard.press('s');
  }
  else
  {
    Keyboard.release('s');
  }
  
  if(digitalRead(BT_D) == LOW)
  {
    Keyboard.press('d');
  }
  else
  {
    Keyboard.release('d');
  }
  
  if(digitalRead(BT_F) == LOW)
  {
    Keyboard.press('f');
  }
  else
  {
    Keyboard.release('f');
  }
  if(digitalRead(BT_Q) == LOW)
  {
    Keyboard.press('q');
  }
  else
  {
    Keyboard.release('q');
  }
  if(digitalRead(BT_W) == LOW)
  {
    Keyboard.press('w');
  }
  else
  {
    Keyboard.release('w');
  }
  if(digitalRead(BT_E) == LOW)
  {
    Keyboard.press('e');
  }
  else
  {
    Keyboard.release('e');
  }
}
