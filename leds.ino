#include <Adafruit_NeoPixel.h>
#include <stdlib.h>  /* pour utiliser strtol */

#ifdef __AVR__
    #include <avr/power.h>
#endif

#define PIN            10
#define NUMPIXELS      3

#define PIN_MOTOR            11
#define NUMPIXELS_MOTOR      2

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRBW + NEO_KHZ800);
Adafruit_NeoPixel pixelsMotor = Adafruit_NeoPixel(NUMPIXELS_MOTOR, PIN_MOTOR, NEO_GRBW + NEO_KHZ800);

int delayval = 500;

void setup() {

    Serial.begin (9600); 

    #if defined (__AVR_ATtiny85__)
    if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
    #endif

    pixelsMotor.setBrightness(20);
    pixelsMotor.begin();

    pixels.setBrightness(20);
    pixels.begin();

    led_display();
}

void loop() {  

    bt_reception();

}

/*
    Couleur des leds a l'allumage.
*/
void led_display() {

    String r = "0";
    String v = "0";
    String b = "255";
    String w = "127";

    long r_led = strtol(r.c_str(), NULL, 16);
    long v_led = strtol(v.c_str(), NULL, 16);
    long b_led = strtol(b.c_str(), NULL, 16);
    long w_led = strtol(w.c_str(), NULL, 16);

    pixels.setPixelColor(0, r_led, v_led, b_led, w_led);
    pixels.setPixelColor(1, r_led, v_led, b_led, w_led);
    pixels.setPixelColor(2, r_led, v_led, b_led, w_led);

    pixels.show();

    pixelsMotor.setPixelColor(0, r_led, v_led, b_led, w_led);
    pixelsMotor.setPixelColor(1, r_led, v_led, b_led, w_led);

    pixelsMotor.show();   

    delay(delayval);
}

/*

L'applicaton Android/Ios envoie la data sous la forme : 

action:codecouleur
action = [a-z1-9] 1 2 a
codecouleur = 000(red) 000(green) 000(blue) 000(white) 000000000000

Action :

0 - 
1 - 
2 - 
3 - 
4 - 

9 - Modification des leds du second jeux de Leds ( Moteurs arriere )

a - 
b - 
c - 
d - 

z - 

*/
void bt_reception() {  
    
    if (Serial.available()){
        String inputString = "";
        
        inputString = Serial.readString();

        // Definition des actions
        String action = inputString.substring(0,1);

        if (action == "0")  {

            long r_led = strtol(inputString.substring(2,5).c_str(), NULL, 16);
            long v_led = strtol(inputString.substring(5,8).c_str(), NULL, 16);
            long b_led = strtol(inputString.substring(8,11).c_str(), NULL, 16);       
            long w_led = strtol(inputString.substring(11).c_str(), NULL, 16);

            pixels.setPixelColor(0, pixels.Color(r_led, v_led, b_led, w_led));
           
            pixels.show();
        }

        if (action == "1")  {

            long r_led = strtol(inputString.substring(2,5).c_str(), NULL, 16);
            long v_led = strtol(inputString.substring(5,8).c_str(), NULL, 16);
            long b_led = strtol(inputString.substring(8,11).c_str(), NULL, 16);       
            long w_led = strtol(inputString.substring(11).c_str(), NULL, 16);

            pixels.setPixelColor(1, pixels.Color(r_led, v_led, b_led, w_led));
           
            pixels.show();
        }

         if (action == "2")  {

            long r_led = strtol(inputString.substring(2,5).c_str(), NULL, 16);
            long v_led = strtol(inputString.substring(5,8).c_str(), NULL, 16);
            long b_led = strtol(inputString.substring(8,11).c_str(), NULL, 16);       
            long w_led = strtol(inputString.substring(11).c_str(), NULL, 16);

            pixels.setPixelColor(1, r_led, v_led, b_led, w_led);
           
            pixels.show();
        }    

        if (action == "3")  {

            pixels.setPixelColor(0, 0xff00f7);
            pixels.setPixelColor(1, 0xff00f7);
          
            pixels.show();
        }

        if (action == "9")  {

            pixelsMotor.setPixelColor(0, 0xff00f7);
            pixelsMotor.setPixelColor(1, 0xff00f7);
           
            pixelsMotor.show();

        }       

        if (action == "a")  {
          pixels.setBrightness(20); 
        }

        if (action == "b")  {
          pixels.setBrightness(100); 
        }
        
        if (action == "c")  {
          pixels.setBrightness(200); 
        }

        /*if (inputString == "rose")  {
            pixels.setPixelColor(0, 0xff00f7);
            pixels.setPixelColor(1, 0xff00f7);

            pixels.setBrightness(20);
            
            pixels.show();

            Serial.println("Changement de Couleur : ");
            Serial.println(inputString);
        } else if(inputString == "rose2") {

            pixels.setPixelColor(0, 0xff00f7);
            pixels.setPixelColor(1, 0xff00f7);

            pixels.setBrightness(200);
            
            pixels.show();

            Serial.println("Changement de Couleur : ");
            Serial.println(inputString);

        } else if(inputString == "bleu") {

            pixels.setPixelColor(0, 0x0023ff);
            pixels.setPixelColor(1, 0x0023ff);
            
            pixels.show();

            Serial.println("Changement de Couleur : ");
            Serial.println(inputString);  

        } else if(inputString == "blanc") {

            fullWhite();

            Serial.println("Changement de Couleur : ");
            Serial.println(inputString);

        } else if(inputString == "jaune") {
            
            pixels.setPixelColor(0, 0xffff00);
            pixels.setPixelColor(1, 0xffff00);
            
            pixels.show();

            Serial.println("Changement de Couleur : ");
            Serial.println(inputString);

        } else if(inputString == "orange") {

            pixels.setPixelColor(0, 0xffaa00);
            pixels.setPixelColor(1, 0xffaa00);
            
            pixels.show();           

            Serial.println("Changement de Couleur : ");
            Serial.println(inputString);

        } else if(inputString == "rouge") {

            pixels.setPixelColor(0, 0xff0000);
            pixels.setPixelColor(1, 0xff0000);
            
            pixels.show();           

            Serial.println("Changement de Couleur : ");
            Serial.println(inputString);

        }else{
                    
            long rvb_led = strtol(inputString.c_str(), NULL, 16);

            pixels.setPixelColor(0, rvb_led); // 
            pixels.setPixelColor(1, rvb_led); //

            pixels.show();

            Serial.println("Changement de Couleur : ");
            Serial.println(inputString);
        }*/

    }

    delay(delayval);
}

void fullWhite() {
    for(uint16_t i=0; i<pixels.numPixels(); i++) {
        pixels.setPixelColor(i, pixels.Color(255, 255, 255 ));
    }
    pixels.show();
}

void fullColor() {
    for(uint16_t i=0; i<pixels.numPixels(); i++) {
        pixels.setPixelColor(i, pixels.Color(255, 255, 255 ));
    }
    pixels.show();
}
