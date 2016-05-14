#include <Keypad.h>

long randNumber;
const byte numRows= 4; //number of rows on the keypad
const byte numCols= 4; //number of columns on the keypad
char press1;
char press2;
char press3;
char press4;
char press5;

char key1;
char key2;
char key3;
char key4;
char key5;

int led1 = 13;
int led2 = 12;
int led3 = 11;
int led4 = 10;

//keymap defines the key pressed according to the row and columns just as appears on the keypad
char keymap[numRows][numCols]= 
{
{'1', '2', '3', 'A'}, 
{'4', '5', '6', 'B'}, 
{'7', '8', '9', 'C'},
{'*', '0', '#', 'D'}
};

//Code that shows the the keypad connections to the arduino terminals
byte rowPins[numRows] = {9,8,7,6}; //Rows 0 to 3
byte colPins[numCols]= {5,4,3,2}; //Columns 0 to 3

//initializes an instance of the Keypad class
Keypad myKeypad= Keypad(makeKeymap(keymap), rowPins, colPins, numRows, numCols);

void setup()
{
  Serial.begin(9600);
  randomSeed(analogRead(0)); //randomSeed() will then shuffle the random function
  Serial.println("Welcome to Morse Code Game");
  Serial.println("Instructions:");
  Serial.println("The monitor will display a random number from 0 to 9");
  Serial.println("Your job is to input the correct Morse Code of the number");
  Serial.println("Dots = 1 and Dash = 2");
  Serial.println("You have 5 lives and 10 trials");
  Serial.println("Good Luck");
  Serial.println();
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
}

void loop()
{
  int trails = 0;
  int count = 0; //counter
  int lives = 4;
  char temp;
  Serial.println("Press any key to begin!");
  temp = myKeypad.waitForKey();
  Serial.println();
  
  //LED 4 Lives Default
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, HIGH);
  digitalWrite(led4, HIGH);
  
  while (lives > 0 && trails < 10)
  {
  count = 0; //counter reset
  Serial.print("Press code for: "); 
  randNumber = random(10);
  Serial.println(randNumber);
  if (randNumber == 1)
  {
      key1 = '1';
      key2 = '2';
      key3 = '2';
      key4 = '2';
      key5 = '2';
  }
  else if (randNumber == 2)
  {
      key1 = '1';
      key2 = '1';
      key3 = '2';
      key4 = '2';
      key5 = '2';
  }
  else if (randNumber == 3)
  {
      key1 = '1';
      key2 = '1';
      key3 = '1';
      key4 = '2';
      key5 = '2';
  }
  else if (randNumber == 4)
  {
      key1 = '1';
      key2 = '1';
      key3 = '1';
      key4 = '1';
      key5 = '2';
  }
  else if (randNumber == 5)
  {
      key1 = '1';
      key2 = '1';
      key3 = '1';
      key4 = '1';
      key5 = '1';
  }
  else if (randNumber == 6)
  {
      key1 = '2';
      key2 = '1';
      key3 = '1';
      key4 = '1';
      key5 = '1';
  }
  else if (randNumber == 7)
  {
      key1 = '2';
      key2 = '2';
      key3 = '1';
      key4 = '1';
      key5 = '1';
  }
  else if (randNumber == 8)
  {
      key1 = '2';
      key2 = '2';
      key3 = '2';
      key4 = '1';
      key5 = '1';
  }
  else if (randNumber == 9)
  {
      key1 = '2';
      key2 = '2';
      key3 = '2';
      key4 = '2';
      key5 = '1';
  }
  else if (randNumber == 0)
  {
      key1 = '2';
      key2 = '2';
      key3 = '2';
      key4 = '2';
      key5 = '2';
  }
  else
     Serial.println("Key Error");
 
  //Read morse code
  Serial.print("Lives = ");
  Serial.println(lives);
  Serial.print("Trails = ");
  Serial.println(trails);
  Serial.print("Press1 = ");
  press1 = myKeypad.waitForKey();
  //delay(10000);  
  if (press1 != NO_KEY)
  {
    Serial.println(press1);
  }
  
  Serial.print("Press2 = ");  
  press2 = myKeypad.waitForKey();
  //delay(10000);    
  if (press2 != NO_KEY)
  {
    Serial.println(press2);
  }

  Serial.print("Press3 = ");  
  press3 = myKeypad.waitForKey();
  //delay(10000);    
  if (press3 != NO_KEY)
  {
    Serial.println(press3);
  }

  Serial.print("Press4 = "); 
  press4 = myKeypad.waitForKey(); 
  //delay(10000);   
  if (press4 != NO_KEY)
  {
    Serial.println(press4);
  }

  Serial.print("Press5 = ");  
  press5 = myKeypad.waitForKey();
  //delay(10000);    
  if (press5 != NO_KEY)
  {
    Serial.println(press5);
  }  
  Serial.println();
  
  //Check for correct morse code
  if(press1 == key1)
    count = count+1;
  else
    count = count+0;
  if(press2 == key2)
    count = count+1;
  else
    count = count+0;
  if(press3 == key3)
    count = count+1;
  else
    count = count+0;
  if(press4 == key4)
    count = count+1;
  else
    count = count+0;
  if(press5 == key5)
    count = count+1;
  else
    count = count+0;
    
  if(count == 5) //if 5 correct morse code
    Serial.println("Correct");
  else
  {
    Serial.println("Incorrect");
    lives = lives-1;
  }
  //LED Lives
  if(lives == 3)
    digitalWrite(led1, LOW);
  else if(lives == 2)
    digitalWrite(led2, LOW);
  else if(lives == 1)
    digitalWrite(led3, LOW);
  else if(lives == 0)
    digitalWrite(led4, LOW);
  else
    lives = lives+0;  
  
  trails = trails+1; 
    
  }//while loop bracket   
  
  //if no lives
  if(lives == 0)
    Serial.println("You Lose");
  else
  {
    Serial.println("You Win");
  }
  Serial.println();
  
  delay(10000);
}
