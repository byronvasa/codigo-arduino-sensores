//#define POTENCIOMETER 5
#define BUZZER 11
//#define SERIALSPEED 9600
#define LDR 0
int POTENCIOMETER = A5;
//int BUZZER = 11;
int SERIALSPEED = 9600;
int LED1 = 3;
int LED2 = 5;
int LED3 = 6;  

void setup()
{
  
  Serial.begin (9600);
  pinMode(3,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  Serial.println("boton 1 para altavoz y el 2 pa la otra y el 3 pa la otra");
  pinMode(POTENCIOMETER, INPUT);
  pinMode(BUZZER, OUTPUT);
  digitalWrite(BUZZER, LOW);
  Serial.begin(SERIALSPEED);
  
}

void loop()
{	
    
    digitalWrite(3, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW); 
    if(Serial.available() > 0){
      Serial.println("ha presionado la 1ra opcion");
     char letra = Serial.read();  
     if(letra == '1' == true){
       digitalWrite(3, HIGH);
       digitalWrite(5, LOW);
       digitalWrite(6, LOW);
       int var = 0;
       while(var < 30){
        Serial.println("led1 encendido");
        int readed = analogRead(POTENCIOMETER);
        readed = map(readed, 0, 1023, 0, 590);
        analogWrite(BUZZER, readed);
        var = var+1;
        delay(450);
         if(var < 0){ 
         	break;
         }
        
           
       }
     }
        
  	 if(letra == '2' == true){
      Serial.println("ha presionado la 2da opcion");
     	digitalWrite(3, LOW);
        digitalWrite(5, HIGH);
        digitalWrite(6, LOW);
       int var = 0;
       while(var < 30){
         if(var < 30){
          int valor = analogRead(LDR);
          int frecuencia = 400 + (valor / 2);
          tone(BUZZER, frecuencia);
          delay(300);
          var = var + 1;
          if (var < 0)
           break;
         }
       }   
     }
      
      // encender los LEDs
      
     if(letra == '3') {
      Serial.println("ha presionado la 3ra opcion");
      digitalWrite(3, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(6, HIGH);
      delay(5000); // Esperar 5 segundos
      digitalWrite(3, LOW);
      digitalWrite(5, LOW);
      digitalWrite(6, LOW);
      delay(1000); // Esperar 1 segundo
      digitalWrite(3, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(6, HIGH);
      delay(2000); // Esperar 2 segundos
      digitalWrite(3, LOW);
      digitalWrite(5, LOW);
      digitalWrite(6, LOW);
    }
      
    }
  }
