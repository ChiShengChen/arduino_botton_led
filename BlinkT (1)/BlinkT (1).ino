
  int led = 11;
  int sw = 3;
  int m = 0;
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.

  pinMode(led, OUTPUT);
  pinMode(sw, INPUT_PULLUP);
  Serial.begin(9600);
}

// the loop function runs over and over again forever
void loop() {
  if(digitalRead(sw)==1 && m!=2){
   m=1;  
    }    

   if(digitalRead(sw)==1 && m==2){
   m=2;  
    }    
    
 /* if(digitalRead(sw)== 0 && m!=4 ){
   m=3; }
  
  if(digitalRead(sw)== 0 && m==4 ){
   m=4; }*/

    if(digitalRead(sw)== 0 ){
   m=4; }
   
  switch(m){
    case 1:
      for(int i; i<= 255 ;i++){
      analogWrite(led, i); 
      delay(30);
      }
      m++;
      break;
      
    case 2:
      analogWrite(led, 255);
      break;
      
    case 3:
      for(int i; i<= 255 ;i--){
      analogWrite(led, i); 
      delay(30);
      }
      m++;
      break;
      
    case 4:
     analogWrite(led, 0);
     break;
      }
     Serial.print("m=");
     Serial.println(m);
     Serial.print("sw=");
     Serial.println(digitalRead(sw));
 }
