#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Fonts/FreeSerif9pt7b.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
// The pins for I2C are defined by the Wire-library. 
// On an arduino UNO:       A4(SDA), A5(SCL)
// On an arduino MEGA 2560: 20(SDA), 21(SCL)
// On an arduino LEONARDO:   2(SDA),  3(SCL), ...
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// 'warlord-helmet', 42x42px
const unsigned char myBitmapwarlord_helmet [] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x03, 0x80, 0x00, 0x00, 0x70, 0x00, 0x0f, 0xe0, 0x00, 0x01, 0xfc, 0x00, 0x0f, 0x00, 
	0x00, 0x00, 0x3e, 0x00, 0x1e, 0x00, 0x00, 0x00, 0x1e, 0x00, 0x1c, 0x00, 0x00, 0x00, 0x0e, 0x00, 
	0x3c, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x3c, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x3c, 0x00, 0x00, 0x00, 
	0x0f, 0x00, 0x3c, 0x00, 0x1e, 0x00, 0x0f, 0x00, 0x3e, 0x00, 0x3f, 0x80, 0x1f, 0x00, 0x3e, 0x00, 
	0xff, 0xc0, 0x1f, 0x00, 0x3f, 0x8c, 0xff, 0xc4, 0x7f, 0x00, 0x3f, 0xcc, 0xff, 0xce, 0xff, 0x00, 
	0x3f, 0xcc, 0x73, 0xcc, 0xff, 0x00, 0x3f, 0xce, 0x73, 0x9c, 0xff, 0x00, 0x1f, 0xcf, 0x21, 0x1c, 
	0xfe, 0x00, 0x07, 0xcf, 0x00, 0x3c, 0xf8, 0x00, 0x03, 0xcf, 0x8c, 0x7c, 0xf0, 0x00, 0x00, 0xcf, 
	0xff, 0xfc, 0xc0, 0x00, 0x00, 0x0d, 0xff, 0xec, 0x00, 0x00, 0x00, 0x0c, 0x3f, 0x0c, 0x00, 0x00, 
	0x00, 0x0c, 0x1e, 0x0c, 0x00, 0x00, 0x00, 0x0c, 0x0e, 0x0c, 0x00, 0x00, 0x00, 0x0e, 0x0c, 0x1c, 
	0x00, 0x00, 0x00, 0x1f, 0x00, 0x3e, 0x00, 0x00, 0x00, 0x1f, 0x80, 0x7e, 0x00, 0x00, 0x00, 0x1f, 
	0xe1, 0xfe, 0x00, 0x00, 0x00, 0x1f, 0xe1, 0xfe, 0x00, 0x00, 0x00, 0x0f, 0xe1, 0xfc, 0x00, 0x00, 
	0x00, 0x07, 0xe1, 0xf8, 0x00, 0x00, 0x00, 0x63, 0xe1, 0xf1, 0x80, 0x00, 0x00, 0xf1, 0xe1, 0xe3, 
	0xe0, 0x00, 0x01, 0xf8, 0xe1, 0xc7, 0xe0, 0x00, 0x00, 0xfc, 0x61, 0x8f, 0xc0, 0x00, 0x00, 0x66, 
	0x21, 0x19, 0x80, 0x00, 0x00, 0x00, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

// Array of all bitmaps for convenience. (Total bytes used to store images in PROGMEM = 272)
const int myBitmapallArray_LEN = 1;
const unsigned char* myBitmapallArray[1] = {
	myBitmapwarlord_helmet
};

// 'sprite1 dino', 11x14px
const unsigned char epd_bitmap_sprite1 [] PROGMEM = {
	0x00, 0x00, 0x3f, 0x80, 0x40, 0x40, 0x80, 0x40, 0x80, 0x40, 0x8c, 0xc0, 0x8c, 0xc0, 0x40, 0x40, 
	0x30, 0x40, 0x40, 0x20, 0x90, 0x20, 0x70, 0xc0, 0x16, 0x80, 0x26, 0x40
};



// 'sprite2', 11x14px
const unsigned char epd_bitmap_sprite2 [] PROGMEM = {
	0x3f, 0x80, 0x40, 0x40, 0x80, 0x40, 0x80, 0x40, 0x8c, 0xc0, 0x8c, 0xc0, 0xc0, 0x40, 0x30, 0x40, 
	0x20, 0x40, 0x20, 0x40, 0x40, 0x20, 0x90, 0xa0, 0x76, 0xc0, 0x26, 0x40
};

// 'cloud', 16x16px
const unsigned char epd_bitmap_cloud [] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xc0, 0x04, 0x20, 0x18, 0x10, 0x24, 0x0c, 
	0x42, 0x12, 0x40, 0x22, 0x60, 0x02, 0x30, 0x04, 0x1f, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

//button pins
const int buttonPin = 9;
const int buttonPin2 = 10;
int buttonState;
int lastButtonState = LOW;
int buttonState2;
int lastButtonState2 = LOW;

//menu variables
int menu = 0;
int selection = 0;

//pong and atari ball
int xpos = SCREEN_WIDTH/2;
int ypos = SCREEN_HEIGHT/2;
int randModx = random(-2,2);
int randMody = random(-2,2);
int yspeed1 = 0;
int yspeed2 = 0;
int direction1 = 1;
int direction2 = 1;
int score = 0;

//dino
int framer1=1;
int framer2=-1;
int spritey = 0;
int x=-5;
int cloudy = random(5,25);
int cloudy2 = random(5,25);
int cloudspeed = 0;
int cloudspeed2 = 0;
bool isJumping = false;
unsigned long time = 0;

unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 25;
unsigned long lastDebounceTime2 = 0;
unsigned long debounceDelay2 = 25;

// Setup ###########################################################################################

void setup() {



  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(buttonPin2, INPUT_PULLUP);

  Serial.begin(9600);

  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }
  

  display.clearDisplay();
  display.drawBitmap(43,11,myBitmapwarlord_helmet, 42, 42, WHITE);
  display.display();
  delay(2000);



}

//function to check if red button was clicked
bool buttonClicked1() {

  int reading = digitalRead(buttonPin); //reads button state at moment

  if (reading != lastButtonState){
      lastDebounceTime = millis();
  }

  if((millis() - lastDebounceTime) > debounceDelay){

    if (reading != buttonState){
      buttonState = reading;
    

      if (buttonState == LOW){
       lastButtonState = reading; //changes button reading at moment
        return true;

      }
      
    }

  }

  lastButtonState = reading; //changes button reading at moment
  return false;

}

//function to check if blue button was clicked
bool buttonClicked2() {

  int reading2 = digitalRead(buttonPin2); //reads button state at moment

  if (reading2 != lastButtonState2){
      lastDebounceTime2 = millis();
  }

  if((millis() - lastDebounceTime2) > debounceDelay2){

    if (reading2 != buttonState2){
      buttonState2 = reading2;
    

      if (buttonState2 == LOW){
       lastButtonState2 = reading2; //changes button reading at moment
        return true;

      }
      
    }

  }

  lastButtonState2 = reading2; //changes button reading at moment
  return false;

}

void loop() {
  
  display.clearDisplay();

  //menu
  if (menu == 0){

    //snake menu
    if (selection == 0){
      display.setTextColor(WHITE);
      display.setTextSize(2);
      display.setCursor(0, 2);
      display.println("Snake");
    }
    else{
      display.setTextSize(1);
      display.setCursor(0, 2);
      display.println("Snake");
    }

    //Pong menu text
    if (selection == 1){
      display.setTextColor(WHITE);
      display.setTextSize(2);
      display.setCursor(40, 22);
      display.println("Atari");
    }
    else{
      display.setTextSize(1);
      display.setCursor(50, 25);
      display.println("Atari");
    }

    //Atari menu text
    if (selection == 2){
      display.setTextColor(WHITE);
      display.setTextSize(2);
      display.setCursor(65, 42);
      display.println("Pong");
    }
    else{
      display.setTextSize(1);
      display.setCursor(90, 50);
      display.println("Pong");
    }

    //reset selection to first item
    if (selection > 2){
      selection = 0;
    }

    //change selection every time red button clicked
    if (buttonClicked1() == true){
      selection++;
    }

    if (selection == 0 and buttonClicked2() ==true){
      menu = 1;
    }

    if (selection == 1 and buttonClicked2() ==true){
      int framer1 =1;
      int framer2=-1;
      unsigned long time = 0;
      menu = 2;
    }

    if (selection == 2 and buttonClicked2() ==true){
      xpos = SCREEN_WIDTH/2;
      ypos = SCREEN_HEIGHT/2;
      randModx = random(-2,2);
      randMody = random(-2,2);

      //pong
      yspeed1 = 0;
      yspeed2 = 0;
      direction1 = 1;
      direction2 = 1;
      menu = 3;
      score = 0;
    }


  } 

  //Snake
  if (menu == 1){
    display.setTextColor(SSD1306_WHITE);
    display.setTextSize(1);
    display.setCursor(0, 0);
    display.println("Snake");

    if (buttonClicked2()==true){
      menu = 0;
      selection = 0;
    }
  } 

  //dino
  if (menu == 2){
    display.drawRect(0,59,128,5,WHITE);
    display.drawBitmap(130-(cloudspeed*2), cloudy,epd_bitmap_cloud,16,16,WHITE);
    display.drawBitmap(190-(cloudspeed2), cloudy2,epd_bitmap_cloud,16,16,WHITE);

    if ((cloudspeed*2) > 140){
      cloudspeed=0;
      cloudy = random(5,25);
    }

    if ((cloudspeed2) > 200){
      cloudspeed2=0;
      cloudy2 = random(5,25);
    }
    


    if ((millis() - time) > 100){
      framer1*=-1;
      framer2*=-1;
      cloudspeed++;
      cloudspeed2++;
      time = millis();
    }

    if (buttonClicked1()){
      spritey = 1;
      isJumping = true;
    }

    if (isJumping){
      spritey = (-(x*x))+32;
      x+=1;
    }

    if (spritey < 0){
        isJumping = false;
        spritey = 0;
        x=-5;

    }

    

    display.drawBitmap(15,(46-spritey)*framer1,epd_bitmap_sprite1,11,14,WHITE);
    display.drawBitmap(15,(46-spritey)*framer2,epd_bitmap_sprite2,11,14,WHITE);

    

    if (buttonClicked2()==true){
      menu = 0;
      selection = 0;
    }



  } 

  //pong
  if (menu == 3){

    display.setTextColor(SSD1306_WHITE);
    display.setTextSize(1);
    display.setCursor(60, 10);
    display.println(score);

    display.drawRoundRect(xpos,ypos,3,3,1,WHITE);
    xpos+=randModx;
    ypos+=randMody;

    //left paddle physics
    display.drawFastVLine(3,yspeed1,20,WHITE);
    yspeed1+=direction1;

    if (buttonClicked1() == true){
      direction1*=-1;
    }

    if (yspeed1 > 42 or yspeed1 < 1){
      direction1*=-1;
    }

    display.drawFastVLine(123,yspeed2,20,WHITE);
    yspeed2+=direction2;

    if (buttonClicked2() == true){
      direction2*=-1;
    }

    if (yspeed2 > 42 or yspeed2 < 1){
      direction2*=-1;
    }

    //ball physics

    if ((xpos == 3 and (ypos > yspeed1 and ypos < yspeed1+20)) or (xpos == 121 and (ypos > yspeed2 and ypos < yspeed2+20))){
      randModx = randModx*-1;
      randMody = random(-2,2);
      score++;
    }

    if (xpos > 125 or xpos < 1){
      menu = 0;
      selection = 0;
    }

    if (ypos > 60 or ypos < 2){
      randModx = random(-2,2);
      randMody = randMody * -1;
    }

  } 

  display.display();

}




