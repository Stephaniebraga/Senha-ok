#include <avr/wdt.h>

String st;
String senha="12345";
char c, ex;
void setup(){
  //wdt_enable(WDTO_8S);
  Serial.begin(9600);
   Serial.println("Reiniciou");
  Serial.println("Escolha:"); 
  //Serial.println("CADASTRO='C' e EXCLUIR='E'");
   Serial.println("DIGITE A SUA SENHA!"); 
}

void loop(){
  //if(Serial.available()>0){
    //ex=Serial.read();
    //Serial.println("DIGITE A SUA SENHA!"); 
    int t1=millis();
    while(Serial.available()>0){
      c=Serial.read();
      st.concat(c);
    }
    delay(1000);  
    //Serial.println(st);
    if(st==senha){
      Serial.println("Ok");
      Serial.println("Escolha:"); 
      Serial.println("CADASTRO='C' e EXCLUIR='E'");
      while (! Serial.available());
      if(Serial.available()>0){
        ex=Serial.read();
      if(ex=='E' || ex=='e'){  
    //delay(1000);
        Serial.println("Voce escolheu exluir!"); 
      }
      else if(ex=='C' || ex=='c')
        Serial.println("Voce escolheu cadastrar!");
      }
    } 
    else if(st!=""){
           Serial.println(st);
           Serial.println("Senha errada. digite novamente."); 
           st="";
         }
 int t2=millis();
 int time=(t2-t1)/1000;
// Serial.println(time);
// wdt_reset();
}
