/*
 * By: Mokuzaru
 * At: mokuzaru.com
 * 
 * Pines para arduino nano o uno
 * 
 * Pin 6  = trigger
 * pin 5 = echo
 * 
 * 
 * pin 13 = salida
 * 
 * When the ultrasonic detecte something at eight cm or more, it has a high output at pin 13. Otherwise stays low.
 * 
 * 
 */
 int echo = 5;
 int trigger = 6;
 int salida = 13;
 long distancia;
 long tiempo;
 
void setup() {
  Serial.begin (9600);
  pinMode(trigger,OUTPUT);
  pinMode(echo,INPUT);
  pinMode(salida,OUTPUT);
  //It's important to keep the exit signal low at start
  digitalWrite(salida,LOW);
}

void loop() {
 digitalWrite(trigger,LOW);
 delayMicroseconds(5);
 digitalWrite(trigger,HIGH);
 delayMicroseconds(10);
 tiempo=pulseIn(echo,HIGH);
 distancia = int(0.017*tiempo);
 Serial.println("distancia: ");
 Serial.println(distancia);
 if(distancia >= 80){
    digitalWrite(salida, HIGH);
  }else{
    digitalWrite(salida,LOW);
    Serial.println("te envié un uno");
  }
 delay(1000*60); 
}
