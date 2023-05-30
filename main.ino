bool combat = true;

void setup() {
  
  // Mise en place du Channel A de la carte de puissance.
  
  pinMode(12, OUTPUT); // Active le moteur sur le Channel A.
  pinMode(9, OUTPUT); // Active le frein du moteur sur le Channel A.

  // Mise en place du reste
  
  pinMode(7, OUTPUT); // LED permettant d'indiquer la présence du mode combat.

  Serial1.begin(9600);
}

void loop(){
 

  if (Serial1.available()) {              // si les données sont dispo
    delay(100);                           // laisser du temps pour que le message arrive
    BTstr = "";
    while (Serial1.available() > 0)     // tant que les caractères arrivent sur la liaison série 1
    {
      BT = Serial1.read();              // Lire la liaison série 1 et ranger le tout dans la variable CHAR 'BT'
            // 
      BTstr = BTstr + BT;               // On remplie la chaine de caractères BTstr

    }
  }

 // Active / désactive le mode combat depuis le bouton en D2
  if (digitalRead(2)) {

        if (combat) {
          combat = false;
        } else {
          combat = true;
        }

        delay(200);
    }


  if (combat) {
    if (BTstr.substring(0, 4) == "[AA]") { // Flèche haut avec
        avance()
    }

    if (BTstr.substring(0, 4) == "[BB]") {
        recule()
    }

    if (BTstr.substring(0, 4) == "[GG]") {
    
    }

    if (BTstr.substring(0, 4) == "[DD]") {
    
    }

    if (BTstr.substring(0, 4) == "[E1]") {
    
    }

    if (BTstr.substring(0, 4) == "[E2]") {
    
    }

    if (BTstr.substring(0, 4) == "[E3]") {
    
    }
    
    if (BTstr.substring(0, 4) == "[E4]") {
    
    }
  } else {
    // Mode course
  }
  
}

// Définiton des fonctions

void avance() {
  digitalWrite(12, HIGH);
  digitalWrite(9, LOW);
  analogWrite(3, HIGH);
}

void recule() {
  digitalWrite(12, LOW);
  digitalWrite(9, LOW);
  analogWrite(3, HIGH);
}

void frein() {
  digitalWrite(9, HIGH);
}
