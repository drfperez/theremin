int sensorValue;//Crea una variable que guarda el valor dela fotoresistencia LDR .
int sensorLow=1023;//Esta variable almacena el valor mnimo de la resistencia
int sensorHigh=0;//Esta variable almacena el valor mximo de la resistencia
const int ledPin=13;//Se crea una constante llamada ledPin que controla el encendido y apagado del LED de la placa
void setup() {
 pinMode(ledPin,OUTPUT);//Se define el LED de la placa como una salida
 digitalWrite(ledPin,HIGH);//Se enciende el LED
 while(millis()<5000){//Los siguientes pasos calibraran los valores mximos y mnimos del sensor durante 5 segundos
      sensorValue=analogRead(A0);
      if(sensorValue>sensorHigh){//Si el el valor que detecta el sensor es mayor que la variable sensorHigh se le da a esta variable ese valor
        sensorHigh=sensorValue;
      }
      if(sensorValue<sensorLow){//Si el valor que detecta el sensor es menpor que la variable sensorLow se le da a esta variable ese valor
        sensorLow=sensorValue;
      }
 }
 digitalWrite(ledPin,LOW);
 }

void loop() {
 sensorValue=analogRead(A0);Se procede a la lectura del valor del sensor
 int pitch=//Se crea una variable llamada pitch que cambia de rango el valor leido por el sensor
 map(sensorValue,sensorLow,sensorHigh,50,4000);//Se utilizan las variables sensorLow y sensorHigh para limitar el rango de valores del sensor
 tone(8,pitch,20);//Dependiendo del valor del sensor se realiza un sonido u otro utilizando la funcin tone y la variable pitch
 delay(10);//Se esperan 10 milisegundos hasta volver a comprobar el valor del sensor

}
