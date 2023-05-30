int CaptG =  3; // Initialiser le capteur IR de gauche sur l'entrée D3.
int CaptD = 4; // Initialiser le capteur IR de droite sur l'entrée D4.

void setup() { // Initialiser les entrées/sorties.
  
  pinMode(12, OUTPUT); // Active le moteur sur le Channel A. (Moteur de gauche)
  pinMode(13, OUTPUT); // Active le moteur sur le Channel B. (Moteur de droite)
  pinMode(8, OUTPUT); // Active le le frein du moteur sur le Channel B. (Frein de droite)
  pinMode(9, OUTPUT); // Active le frein du moteur sur le Channel A. (Frein de gauche)
  pinMode(CaptG, INPUT); // Initialise le capteur IR de gauche.
  pinMode(CaptD, INPUT); // Initialise le capteur IR de droite.
  Serial.begin(9600);

}

void loop() { // Mise en boucle du programme.

  if(HIGH == digitalRead(CaptG) and HIGH == digitalRead(CaptD)) // Si le capteur IR droit et gauche sont sur la ligne.
    {
     digitalWrite(12, HIGH); // Mettre la direction sur le moteur gauche.
     digitalWrite(9, LOW); // Désactiver le frein de gauche.
     digitalWrite(13, HIGH); // Mettre la direction sur le moteur droit.
     digitalWrite(8, LOW); // Désactiver le frein de droite.
     analogWrite(11, HIGH); // Mettre la vitesse à 255 à droite.
     analogWrite(3, HIGH); // Mettre la vitesse à 255 à gauche.
    }
 
  else 
  {
    if (HIGH == digitalRead(CaptG) and LOW == digitalRead(CaptD)) // Si le capteur IR droit n'est pas sur la ligne, mais que le capteur IR gauche l'est.
     {
      digitalWrite(12, LOW); // Désactiver la direction sur le moteur gauche.
      digitalWrite(9, HIGH); // Activer le frein de gauche.
      digitalWrite(13, HIGH); // Mettre la direction sur le moteur droit.
      digitalWrite(8, LOW); // Désactiver le frein de droite.
      analogWrite(11, HIGH); // Mettre la vitesse à 255 à droite.
      analogWrite(3, LOW); // Mettre la vitesse à 0 à gauche.
     }
     
    else
    
     if (LOW == digitalRead(CaptG) and HIGH == digitalRead(CaptD)) // Si le capteur IR droit est sur la ligne, mais que le capteur IR gauche ne l'est pas.
     {
      digitalWrite(12, HIGH); // Mettre la direction sur le moteur gauche.
      digitalWrite(9, LOW); // Désactiver le frein de gauche.
      digitalWrite(13, LOW); // Désactiver la direction sur le moteur droit.
      digitalWrite(8, HIGH); // Activer le frein de droite.
      analogWrite(11, LOW); // Mettre la vitesse à 0 à droite.
      analogWrite(3, HIGH); // Mettre la vitesse à 255 à gauche.
      Serial.println("Black"); 
     }
     else
      {
      
      }
  }
  delay(100); // Mettre un délai de 0.1s.

 }
