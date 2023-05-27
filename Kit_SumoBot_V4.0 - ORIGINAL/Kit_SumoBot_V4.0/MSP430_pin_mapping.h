/****************************************************************************************************************************                                                         
 * Inclusion des bibliothèques
 ****************************************************************************************************************************
 * Cette partie permet d'inclure des bibliothèques renfermant des fonctions utiles.
 ***************************************************************************************************************************/
// bibliothèque pour la gestion de projet Arduino
#include "Arduino.h" 

// Les noms Ax et Px.x sont déclarés dans la librairie de base qui se situe dans le dossier d'installation d'Energia : hardware\energia\msp430\variants\MSP-EXP430G2553LP\pins_energia.h
// Les noms Dx sont déclarés ici et reprennent le schéma du Kit SumoBot
//                      +-\/-+
//               VCC   1|    |20  GND
//    D0   (A0)  P1.0  2|    |19  XIN              D15
//    D1   (A1)  P1.1  3|    |18  XOUT             D14
//    D2   (A2)  P1.2  4|    |17  TEST
//    D3   (A3)  P1.3  5|    |16  RST#
//    D4   (A4)  P1.4  6|    |15  P1.7  (A7) (SCL) D13
//    D5   (A5)  P1.5  7|    |14  P1.6  (A6) (SDA) D12
//    D6         P2.0  8|    |13  P2.5             D11
//    D7         P2.1  9|    |12  P2.4             D10
//    D8         P2.2 10|    |11  P2.3             D9
//                      +----+
//
static const uint8_t D0  = 2;
static const uint8_t D1  = 3;
static const uint8_t D2  = 4;
static const uint8_t D3  = 5;
static const uint8_t D4  = 6;
static const uint8_t D5  = 7;
static const uint8_t D6  = 8;
static const uint8_t D7  = 9;
static const uint8_t D8  = 10;
static const uint8_t D9  = 11;
static const uint8_t D10 = 12;
static const uint8_t D11 = 13;
static const uint8_t D12 = 14;
static const uint8_t D13 = 15;
static const uint8_t D14 = 18;
static const uint8_t D15 = 19;
