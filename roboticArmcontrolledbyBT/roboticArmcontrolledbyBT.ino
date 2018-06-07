#include <Servo.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>
Adafruit_PCD8544 display = Adafruit_PCD8544(7, 6, 5, 4, 3);
Servo menique, anular,  medio, indice, pulgar;
//Servos referidos al rostro
Servo ojoHorizontal, ojoVertical;

char valor;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(19200);
  display.begin();
    display.setContrast(50);

  display.display();
  ojoHorizontal.attach(2);
  ojoVertical.attach(13);
menique.attach(8);
anular.attach(9);
medio.attach(10);
indice.attach(11);
pulgar.attach(12);
abre(menique);
abre(anular);
abre(medio);
abre(indice);
abre(pulgar);
display.clearDisplay();
centrar();
delay(1000);
arriba();
delay(1000);
centrar();
delay(1000);
abajo();
delay(1000);
centrar();
}

void loop() {
  // put your main code here, to run repeatedly:
if (Serial.available()>0){
  valor=Serial.read();
  if (valor=='a'){
      display.setTextSize(1);
  display.setTextColor(BLACK);
  display.clearDisplay();
  display.setCursor(0,0);
  display.println("Cerrando menyique");
  display.display();
    cierra (menique);
  }
    if (valor=='b'){
      display.setTextSize(1);
  display.setTextColor(BLACK);
    display.clearDisplay();

  display.setCursor(0,0);
  display.println("Abriendo menyique");
  display.display();
    abre(menique);
  }
      if (valor=='c'){
      display.setTextSize(1);
  display.setTextColor(BLACK);
    display.clearDisplay();

  display.setCursor(0,0);
  display.println("Cerrando anular");
  display.display();
    cierra(anular);
  }
      if (valor=='d'){
      display.setTextSize(1);
  display.setTextColor(BLACK);
    display.clearDisplay();

  display.setCursor(0,0);
  display.println("Abriendo anular");
  display.display();
    abre(anular);
  }
      if (valor=='e'){
      display.setTextSize(1);
  display.setTextColor(BLACK);
    display.clearDisplay();

  display.setCursor(0,0);
  display.println("Cerrando medio");
  display.display();
    cierra(medio);
  }
      if (valor=='f'){
      display.setTextSize(1);
  display.setTextColor(BLACK);
    display.clearDisplay();

  display.setCursor(0,0);
  display.println("Abriendo medio");
  display.display();
    abre(medio);
  }
        if (valor=='g'){
      display.setTextSize(1);
  display.setTextColor(BLACK);
    display.clearDisplay();

  display.setCursor(0,0);
  display.println("Cerrando indice");
  display.display();
    cierra(indice);
  }
      if (valor=='h'){
      display.setTextSize(1);
  display.setTextColor(BLACK);
    display.clearDisplay();

  display.setCursor(0,0);
  display.println("Abriendo indice");
  display.display();
    abre(indice);
  }
        if (valor=='i'){
      display.setTextSize(1);
  display.setTextColor(BLACK);
    display.clearDisplay();

  display.setCursor(0,0);
  display.println("Cerrando pulgar");
  display.display();
    cierra(pulgar);
  }
      if (valor=='j'){
      display.setTextSize(1);
  display.setTextColor(BLACK);
    display.clearDisplay();

  display.setCursor(0,0);
  display.println("Abriendo pulgar");
  display.display();
    abre(pulgar);
  }
        if (valor=='z'){
      display.setTextSize(1);
  display.setTextColor(BLACK);
    display.clearDisplay();

  display.setCursor(0,0);
  display.println("¡Hola, amigos!");
  display.display();
    saluda();
  }
          if (valor=='y'){
      display.setTextSize(1);
  display.setTextColor(BLACK);
    display.clearDisplay();

  display.setCursor(0,0);
  display.println("¡ROCK!");
  display.display();
    rock();
  }
          if (valor=='x'){
      display.setTextSize(1);
  display.setTextColor(BLACK);
    display.clearDisplay();

  display.setCursor(0,0);
  display.println("¡Victoria!");
  display.display();
    victoria();
  }
            if (valor=='w'){
      display.setTextSize(1);
  display.setTextColor(BLACK);
    display.clearDisplay();

  display.setCursor(0,0);
  display.println("¡OK!¡De acuerdo!");
  display.display();
   ok();
  }
}
}
void victoria(){
     cierra(menique);
cierra(anular);
abre(medio);
abre(indice);
cierra(pulgar);
for (int i=0;i<3;i++){
  movimientoAleatorio();
}
}
void ok(){
     cierra(menique);
cierra(anular);
cierra(medio);
cierra(indice);
abre(pulgar);
for (int i=0;i<3;i++){
  movimientoAleatorio();
}
}
void saluda(){
  for (int n=0;n<3;n++){
   abre(menique);
abre(anular);
abre(medio);
abre(indice);
abre(pulgar);
delay(1000);
cierra(menique);
cierra(anular);
cierra(medio);
cierra(indice);
cierra(pulgar);
delay(1000);
  }
  movimientoAleatorio();
  movimientoAleatorio();
}
void rock(){
     abre(menique);
cierra(anular);
cierra(medio);
abre(indice);
abre(pulgar);
for (int i=0;i<3;i++){
  movimientoAleatorio();
}
}
void abre(Servo motor){
  motor.write(0);
}
void cierra (Servo motor){
  motor.write(180);
}
void movimientoAleatorio(){
  int tiempo=(int)random(500,1500);
  int caso=(int)random(1,8);
  switch(caso){
  case 1:
  arribaIzquierda();
  delay(tiempo);
  centrar();
  break;
    case 2:
  arriba();
  delay(tiempo);
  centrar();
  break;
    case 3:
  arribaDerecha();
  delay(tiempo);
  centrar();
  break;
    case 4:
  izquierda();
  delay(tiempo);
  centrar();
  break;
    case 5:
  derecha();
  delay(tiempo);
  centrar();
  break;
    case 6:
  abajoIzquierda();
  delay(tiempo);
  centrar();
  break;
    case 7:
  abajo();
  delay(tiempo);
  centrar();
  break;
    case 8:
  abajoDerecha();
  delay(tiempo);
  centrar();
  break;
  }
}
void centrar(){
ojoHorizontal.write(90);
ojoVertical.write(90);
  
}
void izquierda(){
  ojoHorizontal.write(45);
  ojoVertical.write(90);
}
void derecha(){
ojoHorizontal.write(135);
ojoVertical.write(90);
}
void abajo(){
  ojoHorizontal.write(90);
ojoVertical.write(135);
}
void arriba(){
  ojoHorizontal.write(90);
ojoVertical.write(45);
}
void arribaIzquierda(){
  ojoHorizontal.write(45);
ojoVertical.write(45);
}
void arribaDerecha(){
  ojoHorizontal.write(135);
ojoVertical.write(45);
}
void abajoIzquierda(){
  ojoHorizontal.write(45);
ojoVertical.write(135);
}
void abajoDerecha(){
    ojoHorizontal.write(135);
ojoVertical.write(135);
}

