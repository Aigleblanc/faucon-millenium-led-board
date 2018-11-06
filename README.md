# Faucon Millenium Lego Led Board Bluetooth
Gestion d'éclairage pour le Faucon millenium lego

![Version](https://img.shields.io/badge/version-v0.9-orange.svg)

> WIP

```
 _____                _     _             
|  ___|              | |   (_)            
| |__ _ __ ___  _   _| |___ _  ___  _ __  
|  __| '_ ` _ \| | | | / __| |/ _ \| '_ \ 
| |__| | | | | | |_| | \__ \ | (_) | | | |
\____/_| |_| |_|\__,_|_|___/_|\___/|_| |_| Lego
```

## Arduino, Led NeoPixel et Bluetooth

Ce code permet de piloter un arduino en bluetooth depuis une app android pour modifier l'éclairage du Faucon Millenium Lego.

Ce code est a l'etat de proof mais fonctionne correctement.

## Les composants utilisés

J'ai mis des liens vers le site aliexpress, mais bien entendu, vous pouvez acheter toutes ces références sur d'autre site.

- Arduino UNO
  -(https://www.aliexpress.com/item/Special-promotions-UNO-R3-MEGA328P-ATMEGA16U2-FOR-ARDUINO-Good-Quality-USB-Cable-in-stock-Hight/656716518.html)
- Led NeoPixels 
  - ( RGBNW : https://www.aliexpress.com/item/10-1000pcs-SK6812-Similar-to-WS2812B-RGBW-Addressable-LED-Pixel-Chips-Matrix-on-Heat-Sink-PCB/32811057113.html )

Particularité avec cette version des leds, c'est la declaration dans la lib adafruit : Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRBW + NEO_KHZ800);
il faut mettre NEO_GRBW + NEO_KHZ800 et utiliser des couleurs en RGBW... ( sans doute une petite subtilité dans la copie des leds )

- Module bluetooth HC-06 
  - (https://www.aliexpress.com/item/HC-06-Bluetooth-Serial-Pass-through-Module-Wireless-Serial-Communication-HC06-Bluetooth-Module-for-arduino-Diy/32857133517.html)
- Condensateur 1000uf 16V
- Resistances 470 Ohm 
  -(https://www.aliexpress.com/item/Best-Promotion-1000-Pcs-50-Values-1-4W-Metal-Film-Resistors-Resistance-Assortment-Kit-Set-1/32662610149.html)
- Pile 18650 2000mah
  -  (https://www.aliexpress.com/item/LiitoKala-for-HG2-18650-18650-3000mah-electronic-cigarette-Rechargeable-batteries-power-high-discharge-power-bank-flashlight/32852288308.html)
- Shield de protection pour la pile 
  - (https://www.aliexpress.com/item/18650-Battery-Shield-V3-For-Raspberry-Pi-WEMOS-For-Arduino-Micro-USB-Type-A-USB-Output/32841386302.html)
- Une plaque de test 
  - (https://www.aliexpress.com/item/B1304-Free-shipping-10pcs-Double-Side-Prototype-PCB-diy-Universal-Printed-Circuit-Board-4x6cm/32351802217.html)
- Des cables 
  - (https://www.aliexpress.com/item/Free-shipping-Dupont-line-120pcs-10cm-male-to-male-male-to-female-and-female-to-female/2041500641.html)
- De quoi souder :)

## PCB

Je viens de mettre au propre une version de la PCB, 

![pcbx25](http://img.viky.fr/PCB_Led-board-controleur_20181106155842.png)
- zoom x2.5

- 43mm x 28mm sur 2 couches.

Vous pouvez utiliser la PCB ici si vous desirez la modifier ou vous l'imprimer : 

https://easyeda.com/aigleblanc/arduino-lego-lepin-led-controleur

## Application Android

Vous pouvez utiliser cette aplication pour gérer depuis un telephone Android.

https://github.com/Aigleblanc/faucon-millenium-led-board/blob/master/AppAndroid/faucon.apk