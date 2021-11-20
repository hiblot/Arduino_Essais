// Exemple pour lire la valeur contenue à l’adresse 14 de l’EEPROM de son Arduino
// avec la fonction EEPROM.read
#include <EEPROM.h>

int adresseW1 = 42;
float valeurW1 = 17777;

int adresseW2 = 142;
float valeurW2 = 696969;

float valeurINITIALE = 0;
float valeurCurrente = 0;
float valeurTOTALEGLOBALE = 0;

float valeurMAX = 50;

float valeurR1;
float valeurR2; 


void setup() {
  Serial.begin(9600) ;

  //first INIT 
  //EEPROM.put(adresseW1, valeurINITIALE);
  //EEPROM.put(adresseW2, valeurINITIALE);
  
  EEPROM.get(adresseW1, valeurR1);  // Retourne la valeur FLOAT contenue à l’adresse « 42 » de l’eeprom
  EEPROM.get(adresseW2, valeurR2);  // Retourne la valeur FLOAT contenue à l’adresse « 142 » de l’eeprom
  
  Serial.print("Valeur à l’adresse "); Serial.print(adresseW1);  Serial.print(" = "); Serial.println(valeurR1); 
  Serial.print("Valeur à l’adresse "); Serial.print(adresseW2);  Serial.print(" = "); Serial.println(valeurR2); 
}

void loop() 
{

  // Tester 
  increment();

  
}

void increment()
{
    EEPROM.get(adresseW1, valeurR1);  // Retourne la valeur FLOAT contenue à l’adresse « 42 » de l’eeprom
    EEPROM.get(adresseW2, valeurR2);  // Retourne la valeur FLOAT contenue à l’adresse « 142 » de l’eeprom
    


    valeurR1 = valeurR1 + 1;
    valeurR2 = valeurR2 + 1;
    if (valeurR1 > valeurMAX)
      {
        valeurR1 = 0;
      }

    EEPROM.put(adresseW1, valeurR1);
    EEPROM.put(adresseW2, valeurR2);
  
  
    Serial.print("Valeur à l’adresse "); Serial.print(adresseW1);  Serial.print(" = "); Serial.println(valeurR1); 
    Serial.print("Valeur à l’adresse "); Serial.print(adresseW2);  Serial.print(" = "); Serial.println(valeurR2); 

    delay(2500);

}
