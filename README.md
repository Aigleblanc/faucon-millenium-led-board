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

Ce code est a l'etat de proof mais fonctionne correctement avec quelques modes.

## Photos du montage a l'etat de proof et de l'application Android

https://photos.app.goo.gl/6mhLmhqXX3XbEYuD9

## Les composants utilisés

J'ai mis des liens vers le site aliexpress, mais bien entendu, vous pouvez acheter toutes ces références sur d'autre site.

- Arduino UNO 
  - https://www.aliexpress.com/item/Special-promotions-UNO-R3-MEGA328P-ATMEGA16U2-FOR-ARDUINO-Good-Quality-USB-Cable-in-stock-Hight/656716518.html)
- Led NeoPixels 
  - ( RGBNW : https://www.aliexpress.com/item/10-1000pcs-SK6812-Similar-to-WS2812B-RGBW-Addressable-LED-Pixel-Chips-Matrix-on-Heat-Sink-PCB/32811057113.html )

Particularité avec cette version des leds, c'est la declaration dans la lib adafruit : Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRBW + NEO_KHZ800);
il faut mettre NEO_GRBW + NEO_KHZ800 et utiliser des couleurs en RGBW... ( sans doute une petite subtilité dans la copie des leds )

- Module bluetooth HC-06 
  - (https://www.aliexpress.com/item/HC-06-Bluetooth-Serial-Pass-through-Module-Wireless-Serial-Communication-HC06-Bluetooth-Module-for-arduino-Diy/32857133517.html)
- Condensateur 1000uf 16V
- Resistances 470 Ohm
  - (https://www.aliexpress.com/item/Best-Promotion-1000-Pcs-50-Values-1-4W-Metal-Film-Resistors-Resistance-Assortment-Kit-Set-1/32662610149.html)
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

Version de la PCB, ( je ne l'ai pas encore faite produire pour tester )

![pcbx25](http://img.viky.fr/PCB_Led-board-controleur.png)

- V0.9 : Cette version permet de clipser direction la PCB sur l'arduino UNO !

Vous pouvez voir et modifier la PCB ici si vous desirez la modifier ou vous l'imprimer : 

https://easyeda.com/aigleblanc/arduino-lego-lepin-led-controleur

## Montage

Vous pouvez regarder les différentes photos pour le montage, mais sinon en résumé : 

### Etape 1 - Pile et Shield 

On place la pile dans le shield v3 que l'on branche sur un chargeur de telephone quelques temps pour recharger la pile.

### Etape 2 - Montage des Leds

- On soude les leds en ruban, j'ai fais le choix d'en utiliser 14, 2 x 7, espacées de 2cm entre chaque, et de 2.5cm au centre pour le passage dans le support lego
- J'ai demonté le support centrale de la grille pour laisser un espace en modifiant avec deux trois pieces lego.
- J'ai passé le fils pour le cockpit dans le bras centrale et en le passant par dessous, a l'intérieur c'est deux leds montées en ruban.

### Etape 3 - Montage de l'arduino

- J'ai raccordé la sortie signal 10 (Pour les moteurs) et 11 ( pour le cockpit ) aux resistances 470 Ohm et ensuite raccordé le signal du ruban de led de l'autre coté de la led. 

```
Signal Arduino 11 ----> Resistance 470 Ohm ----> Signal Ruban de Leds Moteurs

Signal Arduino 10 ----> Resistance 470 Ohm ----> Signal Ruban de Leds Cockpit
```

- J'ai raccordé le + 5v et le - de l'arduino sur la plaque de test, mis un condensateur et relié le + et - des leds et le + et - du module bluetooth

```
Pile ----> Condensateur ----> Leds 

                        ----> module BT
```

( Voir le schema de la PCB et les photos pour mieux comprendre )

### Etape 4 - Chargement du programme Arduino et Android

- Installation de l'application Android ( je vous passe le developpement de celle-ci ! )
- Envoie du programme leds.ino sur la L'arduino UNO ( je pense passer a pluun arduino plus petit ensuite )

### Etape 5 - Test

- Alumage de l'arduino, les leds doivent etre toutes bleu lors de l'allumage.
- Lancement de l'app Andoird, connection au BT, surrement nommé HC-05.
- Have Fun !

### Etape 6 - Ce qu'il reste a faire

- Je pense utiliser un arduino plus petit, utiliser une PCB imprimée, voir pourquoi pas, directement integrer le processeur de l'arduino sur la PCB.
- Optimiser avec des fiches simples la connexion entre les rubans de Leds et la Board.
- Compiler l'applicaton pour iPhone et voir si ca marche... 
- Mettre tout ca a disposition.

## Impression 3D

### Boitier pour le Shield v3

https://www.thingiverse.com/thing:2839419

### Boitier pour l'arduino UNO

https://www.thingiverse.com/thing:994827

## Application Android

Vous pouvez utiliser cette aplication pour gérer depuis un telephone Android.

https://github.com/Aigleblanc/faucon-millenium-led-board/blob/master/AppAndroid/faucon.apk