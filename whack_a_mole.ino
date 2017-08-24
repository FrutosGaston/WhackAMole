
const int XEASY = 1000;  //Nivel de dificultad extra Facil
const int EASY = 500;    //Nivel de dificultad Facil
const int MEDIUM = 300;  //Nivel de dificultad medium
const int HARD = 200;    //Nivel de dificultad dificil
//Asignacion de pines para los Led
const int led_Yellow = 7;
const int led_Green =  8;
const int led_Blue =  9;
const int led_Red = 10;
//Asignacion de pines para los switches
const int SW_Yellow = 2;
const int SW_Green = 3;
const int SW_Blue = 4;
const int SW_Red = 5;

bool initialize = false;

int led_Random;
bool started = false;     //indica si el juego ha comenzado
int dificultad = EASY;    //Nivel de dificultad por defecto

//
bool notSWYellowPress = true;
bool notSWGreenPress = true;
bool notSWBluePress = true;
bool notSWRedPress = true;



void setup()
{
  // Inicializamos los Led (pin)como salidas
  pinMode(led_Yellow, OUTPUT);
  pinMode(led_Green, OUTPUT);
  pinMode(led_Blue, OUTPUT);
  pinMode(led_Red, OUTPUT);
  //Inicializamos los Switch (pin) como entradas
  pinMode(SW_Yellow, INPUT);
  pinMode(SW_Green, INPUT);
  pinMode(SW_Blue, INPUT);
  pinMode(SW_Red, INPUT);
  //Escribimos un Low en los pines de los switches
  digitalWrite(SW_Yellow, LOW);
  digitalWrite(SW_Green, LOW);
  digitalWrite(SW_Blue, LOW);
  digitalWrite(SW_Red, LOW);
}

void wrong()
{ /* Enciende los led indicando que el jugador perdio
     reinicia el juego (started=False)
  */

  int timesDo = 3;
  while (timesDo > 0)
  {
    turnOnAllLeds();
    delay(500);
    turnOffAllLeds();
    delay(500);
    timesDo--;
  }
  started = false;
}

boolean isNotPressed(int sw)
{ /* dado un numero de Switch indica
     si este no fue presionado.
  */
  return (digitalRead(sw) == LOW);
}

boolean isPressed(int sw)
{ /* dado un numero de Switch indica
     si este fue presionado.
  */
  return !(isNotPressed(sw));
}

boolean anySwitchPressed()
{ /* Indica si algun switch fue presionado.
  */
  return ( !(isNotPressed(SW_Yellow) && isNotPressed(SW_Green) && isNotPressed(SW_Blue) && isNotPressed(SW_Red)));
}

boolean noButtonPresed()
{ /* Indica si ningun switch fue presionado.
  */
  return (!anySwitchPressed());
}



void toggleLed(int aLed, int aTime)
{ /* dado un Led (pin) lo enciende y lo a apaga
     a un intervalo dado por aTime
  */
  digitalWrite(aLed, HIGH);
  delay(aTime);
  digitalWrite(aLed, LOW);
  delay(aTime);

}
void toggleLedsAsc(int aTime)
{ //hace un toggle de todos los led de manera ascendente (de amarillo a rojo)
  toggleLed(led_Yellow, aTime);
  toggleLed(led_Green, aTime);
  toggleLed(led_Blue, aTime);
  toggleLed(led_Red, aTime);
}

void toggleLedsDesc(int aTime)
{ //hace un toggle de todos los led de manera descendente (de rojo a amarillo)
  toggleLed(led_Red, aTime);
  toggleLed(led_Blue, aTime);
  toggleLed(led_Green, aTime);
  toggleLed(led_Yellow, aTime);
}

void turnOnAllLedOneByOne(int aTime)
{ //Enciende todos los led de a uno a la vez
  digitalWrite(led_Red, HIGH);
  delay(aTime);
  digitalWrite(led_Blue, HIGH);
  delay(aTime);
  digitalWrite(led_Green, HIGH);
  delay(aTime);
  digitalWrite(led_Yellow, HIGH);
  delay(aTime);
}

void turnOffAllLedOneByOne(int aTime)
{ //apaga todos los led de a uno a la vez
  digitalWrite(led_Red, LOW);
  delay(aTime);
  digitalWrite(led_Blue, LOW);
  delay(aTime);
  digitalWrite(led_Green, LOW);
  delay(aTime);
  digitalWrite(led_Yellow, LOW);
  delay(aTime);
}

void turnOnAllLeds()
{ //Enciende todos los leds al mismo tiempo
  digitalWrite(led_Red, HIGH);
  digitalWrite(led_Blue, HIGH);
  digitalWrite(led_Green, HIGH);
  digitalWrite(led_Yellow, HIGH);
}

void turnOffAllLeds()
{ //apaga todos los leds al mismo tiempo
  digitalWrite(led_Red, LOW);
  digitalWrite(led_Blue, LOW);
  digitalWrite(led_Green, LOW);
  digitalWrite(led_Yellow, LOW);
}

void win()
{ /* Enciende los led indicando que el jugador Gano
     reinicia el juego (started=False)
  */
  turnOnAllLeds();
  started = false;
}

void initialization(int i)
{ //rutina de inicializacion

  toggleLedsAsc(i);
  toggleLedsDesc(i);
  turnOnAllLedOneByOne(i);
  turnOffAllLedOneByOne(i);
  for (int a = 0; a < 6; a++)
  {
    turnOnAllLeds();
    delay(i);
    turnOffAllLeds();
    delay(i);
  }
  delay(i * 4);
  initialize = true;
}

void checkSwitch()
{ //chequea cual es el switch que esta presionado

  if ( isPressed(SW_Yellow)) {
    notSWYellowPress = false;
  } else if ( isPressed(SW_Green)) {
    notSWGreenPress = false;
  } else if ( isPressed(SW_Blue)) {
    notSWBluePress = false;
  } else if ( isPressed(SW_Red)) {
    notSWRedPress = false;
  };
}

void diley(unsigned long ms)
{ /*dado un tiempo en ms genera un retardo
     chequea si algun switch fue presionado
  */
  for (int x = 0; x < ms; x++)
  {
    delay(5);
    if (anySwitchPressed() || x == ms - 1)
    {
      checkSwitch();
    }
  }
}

void apagarLed(int lednumber)
{ //apaga el led indicado
  digitalWrite(lednumber, LOW);
}
/***********************************************************/

void loop() {

  if (started & initialize)
  {
    led_Random = random(7, 11);//genera un numero de pin random
    digitalWrite(led_Random, HIGH);
    diley(dificultad);

    if (led_Random == 7 && (notSWYellowPress || !notSWGreenPress || !notSWBluePress || !notSWRedPress))
    {
      wrong();
    }

    if (led_Random == 8 && (notSWGreenPress || !notSWYellowPress || !notSWBluePress || !notSWRedPress)) //((isNotPressed(SW_Green) && anySwitchPressed()) || isNotPressed(SW_Green)))
    {
      wrong();
    }

    if (led_Random == 9 && (notSWBluePress || !notSWYellowPress || !notSWGreenPress || !notSWRedPress))
    {
      wrong();
    }

    if (led_Random == 10 && (notSWRedPress || !notSWYellowPress || !notSWBluePress || !notSWGreenPress))
    {
      wrong();
    }

    digitalWrite(led_Random, LOW);

    notSWYellowPress = true;
    notSWGreenPress = true;
    notSWBluePress = true;
    notSWRedPress = true;

    apagarLed(led_Random);
    delay(100);
    if (dificultad > 100)
    {
      dificultad = dificultad - 10;
    }
    if (dificultad <= 100)
    {
      dificultad = dificultad - 5;
    }

    if (dificultad <= 50)
    {
      win();
    }

  }
  else
  {
    turnOffAllLeds();
    started = anySwitchPressed();
    checkSwitch();

    if (started && (!notSWYellowPress ))
    {
      notSWYellowPress = true;
      dificultad = XEASY;
      initialization(500);
    }
    if (started && (!notSWGreenPress ))
    {
      notSWGreenPress = true;
      dificultad = EASY;
      initialization(300);
    }
    if (started && (!notSWBluePress ))
    {
      notSWBluePress = true;
      dificultad = MEDIUM;
      initialization(200);
    }
    if (started && (!notSWRedPress ))
    {
      notSWRedPress = true;
      dificultad = HARD;
      initialization(100);
    }

  }
}
