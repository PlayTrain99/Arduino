#include <LiquidCrystal_I2C.h>
#include <Wire.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

//MENU

int upButton = 10;
int downButton = 11;
int selectButton = 12;
int exitButton = 9;

int buzzer = 5; ///////////

int sensorPin = 7;
int sensorState = 0;
int lastState = 0;

int menu = 1;
/*
int menu2 = 1;
int menu3 = 1;
int menu4 = 1; 
*/
byte screen = 1 ;


// koniec MENU

//NAPOJE i KOKTAJLE

int Pumpe1 = 2;  
int Pumpe2 = 3;
int Pumpe3 = 4;   
int Pumpe4 = 6;

int Vodka = Pumpe1;
int Orange = Pumpe2;
int Cactus = Pumpe3;
int Jager = Pumpe4;


// koniec NAPOJE i KOKTAJLE

void setup() {

Serial.begin(9600); 

//MENU
  
  lcd.begin();
  lcd.backlight();
  pinMode(upButton, INPUT_PULLUP);
  pinMode(downButton, INPUT_PULLUP);
  pinMode(selectButton, INPUT_PULLUP);
  
  pinMode(exitButton, INPUT_PULLUP);

  pinMode(sensorPin, INPUT); 
  digitalWrite(sensorPin, HIGH); 

  pinMode(5, OUTPUT); //////////////
  digitalWrite(5, LOW);//////////

  lcd.setCursor(1,0);
  lcd.print("BarMaster Wita");
  delay(3000);
  
  updateMenu();

// koniec MENU

//NAPOJE i KOKTAJLE


  pinMode(12 , INPUT_PULLUP);
  pinMode(Pumpe1, OUTPUT);
  pinMode(Pumpe2, OUTPUT);
  pinMode(Pumpe3, OUTPUT);
  pinMode(Pumpe4, OUTPUT);


  digitalWrite(Pumpe1, HIGH);
  digitalWrite(Pumpe2, HIGH);
  digitalWrite(Pumpe3, HIGH);
  digitalWrite(Pumpe4, HIGH);
 
// koniec NAPOJE i KOKTAJLE

 /*buzzer*/

}

void loop(){

  if (screen == 1) // sterowanie strona 1
  {
    if (!digitalRead(downButton))
    {
      menu++;
      updateMenu();
      delay(100);
      while (!digitalRead(downButton));
    }
    if (!digitalRead(upButton))
    {
      menu--;
      updateMenu();
      delay(100);
      while (!digitalRead(upButton));
    }
    if (!digitalRead(selectButton))
    {
      executeAction();
      //updateMenu();
      delay(100);
      while (!digitalRead(selectButton));
    }
  }
   
  if (screen == 2) //streowanie strona 2 Drinki
  {
    if (!digitalRead(downButton))
    {
     menu++;
     executeAction1(); 
      delay(100);
      while (!digitalRead(downButton));
    }
    if (!digitalRead(upButton))
    {
      menu--;
      executeAction1();
      delay(100);
      while (!digitalRead(upButton));
    }

   sensorState = digitalRead(sensorPin);
 if(sensorState == LOW){ 
  
    if (!digitalRead(selectButton))
    {
      Drinki();
      executeAction();
      executeAction1();
      delay(100);
       screen = 1;
    menu = 1;
    updateMenu();
     while (!digitalRead(selectButton));
    }
  }
  }

    if (screen == 3) //streowanie strona 3 Alkohole
  {
    if (!digitalRead(downButton))
    {
     menu++;
     executeAction2(); 
      delay(100);
      while (!digitalRead(downButton));
    }
    if (!digitalRead(upButton))
    {
      menu--;
      executeAction2();
      delay(100);
      while (!digitalRead(upButton));
    }

    sensorState = digitalRead(sensorPin);
    if(sensorState == LOW){
      
    if (!digitalRead(selectButton))
    {
      Alkohole();
      executeAction();
      executeAction2();
      delay(100);
     screen = 1;
    menu = 1;
    updateMenu();
     while (!digitalRead(selectButton));
    }
  }
 }

if (screen == 4) //streowanie strona 4 Napoje
  {
    if (!digitalRead(downButton))
    {
     menu++;
     executeAction3(); 
      delay(100);
      while (!digitalRead(downButton));
    }
    if (!digitalRead(upButton))
    {
      menu--;
      executeAction3();
      delay(100);
      while (!digitalRead(upButton));
    }

    sensorState = digitalRead(sensorPin);
 if(sensorState == LOW){
  
    if (!digitalRead(selectButton))
    {
      Napoje();
      executeAction();
      executeAction3();
      delay(100);
      screen = 1;
    menu = 1;
    updateMenu();
     while (!digitalRead(selectButton));
    }
  }
 }


   if (!digitalRead(exitButton)) //cofanie do pierwszej strony 1
  {
    screen = 1;
    menu = 1;
    updateMenu();
    delay(1500);
    while (!digitalRead(exitButton));
  } 
  
}

void updateMenu() {
  switch (menu) {
    case 0:
      menu = 1;
      break;
    case 1:
      lcd.clear();
      lcd.print(">Drinks");
      lcd.setCursor(0, 1);
      lcd.print("Alcohols");
      break;
    case 2:
      lcd.clear();
      lcd.print("Drinks");
      lcd.setCursor(0, 1);
      lcd.print(">Alcohols");
      break;
     case 3:
      lcd.clear();
      lcd.print(">Beverages");
      break;
    case 4:
      menu = 3;
      break;
  }
}

void executeAction() {
  switch (menu) {
    case 1:
      executeAction1();
      break;     
    case 2:
     screen = 3;
      menu = 1;
      executeAction2();
      break;
    case 3:
      screen = 4;
      menu = 1;
      executeAction3();
      break;     
  }
}


void executeAction1() {  //Drinki
  switch (menu) {
    case 0:
      menu = 1;
      break;
    case 1:
      lcd.clear();
      lcd.print(">SexOnTheBeach");
      lcd.setCursor(0, 1);
      lcd.print("VodkaOrange");
      screen = 2;
      break;
    case 2:
      lcd.clear();
      lcd.print("SexOnTheBeach");
      lcd.setCursor(0, 1);
      lcd.print(">VodkaOrange");
      screen = 2;
      break;
     case 3:
      lcd.clear();
      lcd.print(">VodkaCactus");
      lcd.setCursor(0, 1);
      lcd.print("Bomba");
      screen = 2;
      break;
      case 4:
      lcd.clear();
      lcd.print("VodkaCactus");
      lcd.setCursor(0, 1);
      lcd.print(">Bomba");
      screen = 2;
      break;
      case 5:
      menu = 4;
      break;
  }
}

void Drinki() { //Drinki
  switch (menu) { 
    case 1:
      action1();
      break;
    case 2:
      action2();
      break;
    case 3:
      action3();
      break;
    case 4:
      action4();
      break; 
  }
}

void action1() { // Drinki

  lcd.clear();
  lcd.noBacklight();
      lcd.print("Preparing");
      lcd.setCursor(0, 1);
      lcd.print("SexOnTheBeach");
 
 if (digitalRead(12) == LOW) {

    digitalWrite(Vodka, LOW);     
    delay(20000);
    digitalWrite(Vodka, HIGH);
    
    digitalWrite(Orange, LOW); 
    delay(35000);
    digitalWrite(Orange, HIGH);

    digitalWrite(Cactus, LOW); 
    delay(25000);
    digitalWrite(Cactus, HIGH);

   lcd.backlight();
    tone(5, 432); /////////
    delay(1000);////////
    noTone(5); //////////
  } else {
    digitalWrite(Pumpe1, HIGH);
    digitalWrite(Pumpe2, HIGH);
    digitalWrite(Pumpe3, HIGH);
  }
}
void action2() {
  lcd.clear();
  lcd.noBacklight();
      lcd.print("Preparing");
      lcd.setCursor(0, 1);
      lcd.print("VodkaOrange");
  
    if (digitalRead(12) == LOW) {
    digitalWrite(Vodka, LOW);     
    delay(20000);
    digitalWrite(Vodka, HIGH);
    
    digitalWrite(Orange, LOW); 
    delay(40000);
    digitalWrite(Orange, HIGH);

    lcd.backlight();
    tone(5, 432); /////////
    delay(1000);////////
    noTone(5); //////////
  } else {
    digitalWrite(Pumpe1, HIGH);
    digitalWrite(Pumpe2, HIGH);
  }
}
void action3() {

  lcd.clear();
  lcd.noBacklight();
      lcd.print("Preparing");
      lcd.setCursor(0, 1);
      lcd.print("VodkaCactus");
  
    if (digitalRead(12) == LOW) {
    digitalWrite(Vodka, LOW);     
    delay(20000);
    digitalWrite(Vodka, HIGH);
    
    digitalWrite(Cactus, LOW); 
    delay(40000);
    digitalWrite(Cactus, HIGH);
    
    lcd.backlight();
    tone(5, 432); /////////
    delay(1000);////////
    noTone(5); //////////
  } else {
    digitalWrite(Pumpe1, HIGH);
    digitalWrite(Pumpe3, HIGH);
  }
}

void action4() {
    lcd.clear();
    lcd.noBacklight();
      lcd.print("Preparing");
      lcd.setCursor(0, 1);
      lcd.print("Bomba");
  
    if (digitalRead(12) == LOW) {
    digitalWrite(Jager, LOW); 
    delay(22000);
    digitalWrite(Jager, HIGH);

    lcd.backlight();
    tone(5, 432); /////////
    delay(1000);////////
    noTone(5); //////////
  } else {
    digitalWrite(Pumpe4, HIGH);
  }
}

void executeAction2() {  //Alkohole
  switch (menu) {
    case 0:
      menu = 1;
      break;
    case 1:
      lcd.clear();
      lcd.print(">Vodka 50ml");
      lcd.setCursor(0, 1);
      lcd.print("Vodka 30ml");
      screen = 3;
      break;
    case 2:
      lcd.clear();
      lcd.print("Vodka 50ml");
      lcd.setCursor(0, 1);
      lcd.print(">Vodka 30ml");
      screen = 3;
      break;
      case 3:
      lcd.clear();
      lcd.print(">Jager 50ml");
      lcd.setCursor(0, 1);
      lcd.print("Jager 30ml");
      screen = 3;
      break;
    case 4:
      lcd.clear();
      lcd.print("Jager 50ml");
      lcd.setCursor(0, 1);
      lcd.print(">Jager 30ml");
      screen = 3;
      break;
      case 5:
      menu = 4;
      break;
  }
}

void Alkohole() { //Alohole 
  switch (menu) { 
    case 1:
      Vodka50ml();
      break;
    case 2:
      Vodka30ml();
      break;
      case 3:
      Jager50ml();
      break;
    case 4:
      Jager30ml();
      break;
  }
}

void Vodka50ml() { // Alohole
 lcd.clear();
 lcd.noBacklight();
      lcd.print("Pouring");
      lcd.setCursor(0, 1);
      lcd.print("Vodka50ml");
 
 if (digitalRead(12) == LOW) { 
    digitalWrite(Vodka, LOW); 
    delay(20000);
    digitalWrite(Vodka, HIGH);

lcd.backlight();
    tone(5, 432); /////////
    delay(1000);////////
    noTone(5); ////////// 
  } else {
    digitalWrite(Pumpe1, HIGH);
  }
}


void Vodka30ml() { // Alohole
 lcd.clear();
   lcd.noBacklight();
      lcd.print("Pouring");
      lcd.setCursor(0, 1);
      lcd.print("Vodka30ml");

if (digitalRead(12) == LOW) { 
    digitalWrite(Vodka, LOW); 
    delay(10000);
    digitalWrite(Vodka, HIGH);

lcd.backlight();
    tone(5, 432); /////////
    delay(1000);////////
    noTone(5); //////////
 } else {
    digitalWrite(Pumpe1, HIGH);
}

}

void Jager50ml() { // Alohole
 lcd.clear();
   lcd.noBacklight();
      lcd.print("Pouring");
      lcd.setCursor(0, 1);
      lcd.print("Jager50ml");
 
 if (digitalRead(12) == LOW) { 
    digitalWrite(Jager, LOW); 
    delay(20000);
    digitalWrite(Jager, HIGH);

lcd.backlight();
    tone(5, 432); /////////
    delay(1000);////////
    noTone(5); ////////// 
  } else {
    digitalWrite(Pumpe4, HIGH);
  }
}


void Jager30ml() { // Alohole
 lcd.clear();
   lcd.noBacklight();
      lcd.print("Pouring");
      lcd.setCursor(0, 1);
      lcd.print("Jager30ml");

if (digitalRead(12) == LOW) { 
    digitalWrite(Jager, LOW); 
    delay(10000);
    digitalWrite(Jager, HIGH);

lcd.backlight();
    tone(5, 432); /////////
    delay(1000);////////
    noTone(5); //////////
 } else {
    digitalWrite(Pumpe4, HIGH);
}

}

void executeAction3() {  //Napoje
  switch (menu) {
    case 0:
      menu = 1;
      break;
     case 1:
      lcd.clear();
      lcd.print(">Orange 200ml");
      lcd.setCursor(0, 1);
      lcd.print("Orange 100ml");
      screen = 4;
      break;
      case 2:
      lcd.clear();
      lcd.print("Orange 200ml");
      lcd.setCursor(0, 1);
      lcd.print(">Orange 100ml");
      screen = 4;
      break;
      case 3:
      lcd.clear();
      lcd.print(">Cactus 200ml");
      lcd.setCursor(0, 1);
      lcd.print("Cactus100ml");
      screen = 4;
      break;
      case 4:
      lcd.clear();
      lcd.print("Cactus200ml");
      lcd.setCursor(0, 1);
      lcd.print(">Cactus100ml");
      screen = 4;
      break;
      case 5:
      menu = 4;
      break;
  }
}

void Napoje() { //Napoje
  switch (menu) { 
    case 1:
      Orange200ml();
      break;
    case 2:
      Orange100ml();
      break;
    case 3:
      Cactus200ml();
      break;
    case 4:
      Cactus100ml();
      break; 
  }
}

void Orange200ml() { // Napoje
 lcd.clear();
   lcd.noBacklight();
      lcd.print("Pouring");
      lcd.setCursor(0, 1);
      lcd.print("Orange200ml");
 
 if (digitalRead(12) == LOW) { 
    digitalWrite(Orange, LOW); 
    delay(100000);
    digitalWrite(Orange, HIGH);

lcd.backlight();
    tone(5, 432); /////////
    delay(1000);////////
    noTone(5); //////////
  } else {
    digitalWrite(Pumpe2, HIGH);
  }
}
void Orange100ml() { // Napoje
   lcd.clear();
     lcd.noBacklight();
      lcd.print("Pouring");
      lcd.setCursor(0, 1);
      lcd.print("Orange100ml");
  
if (digitalRead(12) == LOW) { 
    digitalWrite(Orange, LOW); 
    delay(55000);
    digitalWrite(Orange, HIGH);

lcd.backlight();
    tone(5, 432); /////////
    delay(1000);////////
    noTone(5); //////////
  } else {
    digitalWrite(Pumpe2, HIGH);
  }
}

void Cactus200ml() { // Napoje
  
lcd.clear();
  lcd.noBacklight();
      lcd.print("Pouring");
      lcd.setCursor(0, 1);
      lcd.print("Cactus200ml");

  if (digitalRead(12) == LOW) { 
    digitalWrite(Cactus, LOW); 
    delay(100000);
    digitalWrite(Cactus, HIGH);

lcd.backlight();
    tone(5, 432); /////////
    delay(1000);////////
    noTone(5); //////////
  } else {
    digitalWrite(Pumpe3, HIGH);
  }
}
 
void Cactus100ml() { // Napoje
 lcd.clear();
   lcd.noBacklight();
      lcd.print("Pouring");
      lcd.setCursor(0, 1);
      lcd.print("Cactus100ml");
  
 if (digitalRead(12) == LOW) { 
    digitalWrite(Cactus, LOW); 
    delay(55000);
    digitalWrite(Cactus, HIGH);

lcd.backlight();
    tone(5, 432); /////////
    delay(1000);////////
    noTone(5); //////////
  } else {
    digitalWrite(Pumpe3, HIGH);
  }
}
