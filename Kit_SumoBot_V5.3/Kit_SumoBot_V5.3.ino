/****************************************************************************************************************************                                                         
 * Projet               : Kit SumoBot 2021 
 * Entité               : Association ESIEESPACE : http://www.esieespace.fr/ 
 * Auteurs              : Jérémie DUTHIL
 *                      : Antoine BESSIERE
 *                      : Louis DESPLANCHE
 * Création             : 05/07/2016
 * Dernière mise à jour : 06/07/2020
 * Version              : 5.2.0
 * --------------------------------------------------------------------------------------------------------------------------
 * Description          :
 * Ce code est fourni avec le Kit SumoBot et permet de contrôler les différentes parties du robot.
 * Ceci est une base fonctionnelle à améliorer. Pour toute question, visiter le forum SumoBot : http://sumobot.esieespace.fr 
 * Pour plus d'informations sur l'utilisation d'Arduino, voir la documentation officielle : http://www.arduino.cc/en/Reference 
 * Ce code est du domaine public, il peut donc être modifié et redistribué.
 * --------------------------------------------------------------------------------------------------------------------------
 * Révision |    Date    | Description
 * 3.0.0    | 02/08/2016 | Création
 * 5.0.0    | 06/01/2020 | Modification
 * 5.2.0    | 06/07/2020 | Modification
 ***************************************************************************************************************************/


#include "Kit_SumoBot.h"
/****************************************************************************************************************************                                                         
 * Initialisation
 ****************************************************************************************************************************
 * Cette fonction permet d'initialiser notre programme en définissant la direction des pins et autres actions 
 * qui ne seront exécuter qu'une seule fois. Cette fonction est appelée après un reset, donc au démarrage de la carte 
 * ou après l'appuie sur le bouton reset de la carte Arduino.
 ***************************************************************************************************************************/
void setup()
{
  #if DEBUG
    // Initialisation du lien série
    Serial.begin(9600); // init liaison UART
    Serial.print("Bonjour, je suis le Kit SumoBot de l'ESIEESPACE version : "+ String(VERSION));
    Serial.println("-----------------------------------------------------------");
    Serial.println("Initialisation");
  #endif
  //
  
  // Initialisation des entrées
  pinMode(BP,                INPUT_PULLUP); // On ajoute une résistance de pullup pour que la pin soit à un niveau HIGH par défaut.
  pinMode(TCRT_AVG,          INPUT);
  pinMode(TCRT_AVD,          INPUT);
  pinMode(ULTRASON_ECHO,     INPUT);
  
  // Initialisation des sorties
  pinMode(LED_1,             OUTPUT);
  pinMode(LED_2,             OUTPUT);
  pinMode(MOTEUR_G_PWM,      OUTPUT);
  pinMode(MOTEUR_G_DIR_1,    OUTPUT);
  pinMode(MOTEUR_G_DIR_2,    OUTPUT);
  pinMode(MOTEUR_D_PWM,      OUTPUT);
  pinMode(MOTEUR_D_DIR_1,    OUTPUT);
  pinMode(MOTEUR_D_DIR_2,    OUTPUT);
  pinMode(ULTRASON_TRIGGER,  OUTPUT);
  Serial.flush();
}

/****************************************************************************************************************************                                                         
 * Fonction principale
 ****************************************************************************************************************************
 * Cette fonction permet l'exécution du code "en boucle". 
 * Si le programme atteint la dernière ligne de cette fonction, l'exécution recommence indéfiniment.
 ***************************************************************************************************************************/
void loop()
{
  // Déclaration des variables
  byte ligne;      // Cette variable servira à mémoriser l'état des capteurs de ligne blanche
  byte ligne_mem;  // Cette variable servira à mémoriser le dernier capteur de ligne activé
  long distance;   // Cette variable servira à mémoriser l'état du capteur ultrason et la distance de l'adversaire
  
  #if DEBUG
    Serial.println("Attente du bouton GO");
  #endif
  
  // Attente du bouton GO
  attente_go();
  
  // Attente des 5sec règlementaires
  delay(5000); 
  while(1) {
    Serial.println("avance");
    moteur_avance(MOTEUR_100, MOTEUR_100);
    delay(100);
  }

}

void attente_go()
{
  bool led = false;              // On créer une variable pour l'état des leds
  
  while(digitalRead(BP) == HIGH) // Tant que le bouton poussoir est à l'état haut (grâce à la fonction PULLUP)
  {    
    if (led)                     // On fait clignoter les 2 leds pour montrer qu'on attend le go
    {
      digitalWrite(LED_1, LOW);
      digitalWrite(LED_2, HIGH);
    }
    else
    {
      digitalWrite(LED_1, HIGH);
      digitalWrite(LED_2, LOW);
    }
    
    led = !led;                  // on inverse la variable pour inverser l'état des leds
    
    delay(100);                  // On répète l'opération toutes les 200ms, c'est ce qui créer le clignotement
  }
  
  digitalWrite(LED_1, LOW);
  digitalWrite(LED_2, LOW);
  
  // Quand le bouton est pressé, on quitte la boucle While et on sort de la fonction attente_go()
  
  #if DEBUG
    Serial.println("Go !");
  #endif
}
