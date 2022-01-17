/*#include <SPI.h>
#include <SD.h>
#include"header.h"


File myFile;

const int chipSelect = 4;



void loop()
{
  Serial.print("Initializing SD card...");
   pinMode(SS, OUTPUT);
   
  if (!SD.begin(chipSelect)) {
    Serial.println("initialization failed!");
    return;
  }
  Serial.println("initialization done.");
  
  //Ouverture du fichier, ou création du fichier si il ne le trouve pas
  myFile = SD.open(__DATE__, FILE_WRITE);
  
  //Vérification de l'accés à la carte et ouverture du fichier
  if (myFile) {
    Serial.print("Writing to" __DATE__);
    myFile.println("DATA");
    //Fermeture du fichier
    myFile.close();
    Serial.println("done.");
  } else {
    //Si le fichier ne s'ouvre pas, message d'erreur et affichage LED
    Serial.println("error opening test.txt");
  }
}*/