#include <Adafruit_NeoPixel.h>
#include <stdlib.h>  /* pour utiliser strtol */

#ifdef __AVR__
    #include <avr/power.h>
#endif

#define PIN            11
#define NUMPIXELS      2

#define PIN_MOTOR            10
#define NUMPIXELS_MOTOR      14

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRBW + NEO_KHZ800);
Adafruit_NeoPixel pixelsMotor = Adafruit_NeoPixel(NUMPIXELS_MOTOR, PIN_MOTOR, NEO_GRBW + NEO_KHZ800);

int delayval = 500;

void setup() {

    Serial.begin (9600); 

    #if defined (__AVR_ATtiny85__)
    if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
    #endif

    // 0 a 255
    pixelsMotor.setBrightness(200);
    pixelsMotor.begin();

    pixels.setBrightness(200);
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

    // Bleu par defaut
    String r = "0";
    String v = "0";
    String b = "255";
    String w = "0";

    long r_led = strtol(r.c_str(), NULL, 16);
    long v_led = strtol(v.c_str(), NULL, 16);
    long b_led = strtol(b.c_str(), NULL, 16);
    long w_led = strtol(w.c_str(), NULL, 16);

    pixels.setPixelColor(0, r_led, v_led, b_led, w_led);
    pixels.setPixelColor(1, r_led, v_led, b_led, w_led);

    pixels.show();

    pixelsMotor.setPixelColor(0, r_led, v_led, b_led, w_led);
    pixelsMotor.setPixelColor(1, r_led, v_led, b_led, w_led);
    pixelsMotor.setPixelColor(2, r_led, v_led, b_led, w_led);
    pixelsMotor.setPixelColor(3, r_led, v_led, b_led, w_led);
    pixelsMotor.setPixelColor(4, r_led, v_led, b_led, w_led);
    pixelsMotor.setPixelColor(5, r_led, v_led, b_led, w_led);
    pixelsMotor.setPixelColor(6, r_led, v_led, b_led, w_led);
    pixelsMotor.setPixelColor(7, r_led, v_led, b_led, w_led);
    pixelsMotor.setPixelColor(8, r_led, v_led, b_led, w_led);
    pixelsMotor.setPixelColor(9, r_led, v_led, b_led, w_led);
    pixelsMotor.setPixelColor(10, r_led, v_led, b_led, w_led);
    pixelsMotor.setPixelColor(11, r_led, v_led, b_led, w_led);
    pixelsMotor.setPixelColor(12, r_led, v_led, b_led, w_led);
    pixelsMotor.setPixelColor(13, r_led, v_led, b_led, w_led);

    pixelsMotor.show();   

    delay(delayval);
}

/*

L'applicaton Android/Ios envoie la data sous la forme : 

action:codecouleur
action = [a-z1-9] 1 2 a
codecouleur = 000(red) 000(green) 000(blue) 000(white) 000000000000

Action :

0 - Change la couleur du cockpit par celle demandé sur les deux leds
1 - Change la couleur de toutes les leds des moteurs
2 - Met en blanc toutes les leds du cockpite
3 - Met en blanc toutes les leds des moteurs
4 - 
5 - 
6 - Effet K2000 sur les moteurs
7 - Effet K2000 sur les moteurs
8 - Effet K2000 sur les moteurs
9 - Effet K2000 sur les moteurs

a - Luminosité 10%
b - Luminosité 50%
c - Luminosité 100%
d - 

z - 

*/
void bt_reception() {  
    
    if (Serial.available()){
        String inputString = "";
        
        inputString = Serial.readString();

        // Definition des actions
        String action = inputString.substring(0,1);

        // Change la couleur du cockpit par celle demandé sur les deux leds
        if (action == "0")  {

            long r_led = strtol(inputString.substring(2,5).c_str(), NULL, 16);
            long v_led = strtol(inputString.substring(5,8).c_str(), NULL, 16);
            long b_led = strtol(inputString.substring(8,11).c_str(), NULL, 16);       
            long w_led = strtol(inputString.substring(11).c_str(), NULL, 16);

            pixels.setPixelColor(0, pixels.Color(r_led, v_led, b_led, w_led));
            pixels.setPixelColor(1, pixels.Color(r_led, v_led, b_led, w_led));
           
            pixels.show();
        }

        // Change la couleur de toutes les leds des moteurs
        if (action == "1")  {

            long r_led = strtol(inputString.substring(2,5).c_str(), NULL, 16);
            long v_led = strtol(inputString.substring(5,8).c_str(), NULL, 16);
            long b_led = strtol(inputString.substring(8,11).c_str(), NULL, 16);       
            long w_led = strtol(inputString.substring(11).c_str(), NULL, 16);
         
            pixelsMotor.setPixelColor(0, r_led, v_led, b_led, w_led);
            pixelsMotor.setPixelColor(1, r_led, v_led, b_led, w_led);
            pixelsMotor.setPixelColor(2, r_led, v_led, b_led, w_led);
            pixelsMotor.setPixelColor(3, r_led, v_led, b_led, w_led);
            pixelsMotor.setPixelColor(4, r_led, v_led, b_led, w_led);
            pixelsMotor.setPixelColor(5, r_led, v_led, b_led, w_led);
            pixelsMotor.setPixelColor(6, r_led, v_led, b_led, w_led);
            pixelsMotor.setPixelColor(7, r_led, v_led, b_led, w_led);
            pixelsMotor.setPixelColor(8, r_led, v_led, b_led, w_led);
            pixelsMotor.setPixelColor(9, r_led, v_led, b_led, w_led);
            pixelsMotor.setPixelColor(10, r_led, v_led, b_led, w_led);
            pixelsMotor.setPixelColor(11, r_led, v_led, b_led, w_led);
            pixelsMotor.setPixelColor(12, r_led, v_led, b_led, w_led);
            pixelsMotor.setPixelColor(13, r_led, v_led, b_led, w_led);

            pixelsMotor.show();
        }

        // Met en blanc toutes les leds du cockpite
        if (action == "2")  {
            fullWhite();
        } 

        // Met en blanc toutes les leds des moteurs
        if (action == "3")  {
            fullWhiteMotors();
        }

/*
        knightRider(3, 32, 4, 0xFF1000); // Cycles, Speed, Width, RGB Color (original orange-red)
        knightRider(3, 32, 3, 0xFF00FF); // Cycles, Speed, Width, RGB Color (purple)
        knightRider(3, 32, 2, 0x0000FF); // Cycles, Speed, Width, RGB Color (blue)
        knightRider(3, 32, 5, 0xFF0000); // Cycles, Speed, Width, RGB Color (red)
        knightRider(3, 32, 6, 0x00FF00); // Cycles, Speed, Width, RGB Color (green)
        knightRider(3, 32, 7, 0xFFFF00); // Cycles, Speed, Width, RGB Color (yellow)
        knightRider(3, 32, 8, 0x00FFFF); // Cycles, Speed, Width, RGB Color (cyan)
        knightRider(3, 32, 2, 0xFFFFFF); // Cycles, Speed, Width, RGB Color (white)
*/

        // Effet K2000 sur les moteurs green
        if (action == "6")  {
            knightRider(15, 15, 4, 0x00FF00);
        }

        // Effet K2000 sur les moteurs purple
        if (action == "7")  {
            knightRider(15, 15, 4, 0xFF00FF);
        }

        // Effet K2000 sur les moteurs bleu
        if (action == "8")  {
            knightRider(15, 15, 4, 0x0000FF);
        }

        // Effet K2000 sur les moteurs rouge
        if (action == "9")  {
            knightRider(15, 15, 4, 0xFF1000);
        }

        // Luminosité 10%
        if (action == "a")  {
          pixels.setBrightness(25);
          pixelsMotor.setBrightness(25);
        }

        // Luminosité 50%
        if (action == "b")  {
          pixels.setBrightness(125);
          pixelsMotor.setBrightness(125);
        }
        
        // Luminosité 100%
        if (action == "c")  {
          pixels.setBrightness(255);
          pixelsMotor.setBrightness(255);
        }
        // Led On
        if (action == "d")  {
            led_display();
        }

        // Led Off
        if (action == "e")  {

            String r = "0";
            String v = "0";
            String b = "0";
            String w = "0";

            long r_led = strtol(r.c_str(), NULL, 16);
            long v_led = strtol(v.c_str(), NULL, 16);
            long b_led = strtol(b.c_str(), NULL, 16);
            long w_led = strtol(w.c_str(), NULL, 16);
         
            pixelsMotor.setPixelColor(0, r_led, v_led, b_led, w_led);
            pixelsMotor.setPixelColor(1, r_led, v_led, b_led, w_led);
            pixelsMotor.setPixelColor(2, r_led, v_led, b_led, w_led);
            pixelsMotor.setPixelColor(3, r_led, v_led, b_led, w_led);
            pixelsMotor.setPixelColor(4, r_led, v_led, b_led, w_led);
            pixelsMotor.setPixelColor(5, r_led, v_led, b_led, w_led);
            pixelsMotor.setPixelColor(6, r_led, v_led, b_led, w_led);
            pixelsMotor.setPixelColor(7, r_led, v_led, b_led, w_led);
            pixelsMotor.setPixelColor(8, r_led, v_led, b_led, w_led);
            pixelsMotor.setPixelColor(9, r_led, v_led, b_led, w_led);
            pixelsMotor.setPixelColor(10, r_led, v_led, b_led, w_led);
            pixelsMotor.setPixelColor(11, r_led, v_led, b_led, w_led);
            pixelsMotor.setPixelColor(12, r_led, v_led, b_led, w_led);
            pixelsMotor.setPixelColor(13, r_led, v_led, b_led, w_led);

            pixelsMotor.show();

            pixels.setPixelColor(0, pixels.Color(r_led, v_led, b_led, w_led));
            pixels.setPixelColor(1, pixels.Color(r_led, v_led, b_led, w_led));
           
            pixels.show();

        }
    }

    delay(delayval);
}

void fullWhite() {
    for(uint16_t i=0; i<pixels.numPixels(); i++) {
        pixels.setPixelColor(i, pixels.Color(255, 255, 255 ));
    }
    pixels.show();
}

void fullWhiteMotors() {
    for(uint16_t i=0; i<pixelsMotor.numPixels(); i++) {
        pixelsMotor.setPixelColor(i, pixelsMotor.Color(255, 255, 255 ));
    }
    pixelsMotor.show();
}

void fullColor() {
    for(uint16_t i=0; i<pixels.numPixels(); i++) {
        pixels.setPixelColor(i, pixels.Color(255, 255, 255 ));
    }
    pixels.show();
}

/* 
    Effet Kit K2000
*/
// Cycles - one cycle is scanning through all pixels left then right (or right then left)
// Speed - how fast one cycle is (32 with 16 pixels is default KnightRider speed)
// Width - how wide the trail effect is on the fading out LEDs.  The original display used
//         light bulbs, so they have a persistance when turning off.  This creates a trail.
//         Effective range is 2 - 8, 4 is default for 16 pixels.  Play with this.
// Color - 32-bit packed RGB color value.  All pixels will be this color.
// knightRider(cycles, speed, width, color);
void knightRider(uint16_t cycles, uint16_t speed, uint8_t width, uint32_t color) {
    uint32_t old_val[NUMPIXELS_MOTOR]; // up to 256 lights!
    // Larson time baby!
    for(int i = 0; i < cycles; i++){
        for (int count = 1; count<NUMPIXELS_MOTOR; count++) {
            pixelsMotor.setPixelColor(count, color);
            old_val[count] = color;
            for(int x = count; x>0; x--) {
                old_val[x-1] = dimColor(old_val[x-1], width);
                pixelsMotor.setPixelColor(x-1, old_val[x-1]); 
            }
            pixelsMotor.show();
            delay(speed);
        }
        for (int count = NUMPIXELS_MOTOR-1; count>=0; count--) {
            pixelsMotor.setPixelColor(count, color);
            old_val[count] = color;
            for(int x = count; x<=NUMPIXELS_MOTOR ;x++) {
                old_val[x-1] = dimColor(old_val[x-1], width);
                pixelsMotor.setPixelColor(x+1, old_val[x+1]);
            }
            pixelsMotor.show();
            delay(speed);
        }
    }
}

void clearStrip() {
    for( int i = 0; i<NUMPIXELS_MOTOR; i++){
        pixelsMotor.setPixelColor(i, 0x000000); pixelsMotor.show();
    }
}

uint32_t dimColor(uint32_t color, uint8_t width) {
   return (((color&0xFF0000)/width)&0xFF0000) + (((color&0x00FF00)/width)&0x00FF00) + (((color&0x0000FF)/width)&0x0000FF);
}

// Using a counter and for() loop, input a value 0 to 251 to get a color value.
// The colors transition like: red - org - ylw - grn - cyn - blue - vio - mag - back to red.
// Entering 255 will give you white, if you need it.
uint32_t colorWheel(byte WheelPos) {
    byte state = WheelPos / 21;
    switch(state) {
        case 0: return pixelsMotor.Color(255, 0, 255 - ((((WheelPos % 21) + 1) * 6) + 127)); break;
        case 1: return pixelsMotor.Color(255, ((WheelPos % 21) + 1) * 6, 0); break;
        case 2: return pixelsMotor.Color(255, (((WheelPos % 21) + 1) * 6) + 127, 0); break;
        case 3: return pixelsMotor.Color(255 - (((WheelPos % 21) + 1) * 6), 255, 0); break;
        case 4: return pixelsMotor.Color(255 - (((WheelPos % 21) + 1) * 6) + 127, 255, 0); break;
        case 5: return pixelsMotor.Color(0, 255, ((WheelPos % 21) + 1) * 6); break;
        case 6: return pixelsMotor.Color(0, 255, (((WheelPos % 21) + 1) * 6) + 127); break;
        case 7: return pixelsMotor.Color(0, 255 - (((WheelPos % 21) + 1) * 6), 255); break;
        case 8: return pixelsMotor.Color(0, 255 - ((((WheelPos % 21) + 1) * 6) + 127), 255); break;
        case 9: return pixelsMotor.Color(((WheelPos % 21) + 1) * 6, 0, 255); break;
        case 10: return pixelsMotor.Color((((WheelPos % 21) + 1) * 6) + 127, 0, 255); break;
        case 11: return pixelsMotor.Color(255, 0, 255 - (((WheelPos % 21) + 1) * 6)); break;
        default: return pixelsMotor.Color(0, 0, 0); break;
    }
}