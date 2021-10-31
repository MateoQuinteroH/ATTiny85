
bool a = false;
int b = 0;
void pin_config();
void Encender_LED_OK();
void Apagar_LED_OK();
void Encender_LED_ERROR();
void Apagar_LED_ERROR();

void setup() 
{ 
  pin_config(); // Configura pines
  delay(60000);
  Encender_LED_OK(); // Enciende led que indica que el sensor está listo para funcionar
  Apagar_LED_ERROR();
  
}

void loop() 
{
  if(digitalRead(4)==HIGH)
  {
    Apagar_LED_OK();
    Encender_LED_ERROR();
    digitalWrite(2,HIGH);
    delay(3000);
    digitalWrite(2,LOW);
    Encender_LED_OK();
    Apagar_LED_ERROR();
  }
}

void pin_config()
{
  /* Definiendo los pines como entrada/salida */
  pinMode(4,INPUT); // Sensor
  pinMode(2,OUTPUT); // Buzzer
  pinMode(1,OUTPUT); // Led rojo
  pinMode(0,OUTPUT); // Led verde
  /* Definiendo valores iniciales de los pines */
  digitalWrite(2,LOW); //Buzzer apagado
  digitalWrite(1,HIGH); // Led rojo encendido
  digitalWrite(0,LOW); // Led verde apagado
}

void Encender_LED_OK()
{
  digitalWrite(0,HIGH);
}

void Apagar_LED_OK()
{
  digitalWrite(0,LOW);
}


void Encender_LED_ERROR()
{
  digitalWrite(1,HIGH);;
}
void Apagar_LED_ERROR()
{
  digitalWrite(1,LOW);
}
