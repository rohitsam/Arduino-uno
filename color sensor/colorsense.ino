int colred=2;
int colgreen=3;
int colblue=4;
int sensorPin=A0;
int sensorValue=0;
int r=0;
int g=0; 
int b=0;
int delayTime = 200;
int buttonPin=9;
int k=0,m=0,i=0;
int times=3;
int sensorValueR[3];
int sensorValueG[3];
int sensorValueB[3];
int colvalue[3];
int white[3]={120,120,120};
int black[3]={30,30,30};
//second object
//***************
//***************
//***************
int colvalue2[3];
int sensorValueR2[3];
int sensorValueG2[3];
int sensorValueB2[3];
int k2;
int m2,m3=0;
int sensitivity=50;
//****************
//****************
//****************


void setup(){
  
 
  pinMode(colred, OUTPUT);        
  pinMode(colgreen, OUTPUT);
  pinMode(colblue, OUTPUT);
  pinMode(buttonPin, INPUT);
  pinMode(10, OUTPUT);        
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(8,INPUT);
  
  Serial.begin(9600);
}
  
  void loop(){
    
   
 while(k<times){
   
   takereading();
   k++;
   
 }
 while(m<1){
 avarage();
 manipulate();
 check();
 printout();
 


 digitalWrite(13,HIGH);//added 2/24/2016
 delay(100);
 digitalWrite(13,LOW);
  m++;
  }
 //****2***  
 delay(500);

 while(k2<times){
   
   takereading2();
   k2++;
   
 }
 //******2******
 //******2*****
  while(m2<1)
  {
    avarage2();
 manipulate2();
 check2();
 printout2();
 digitalWrite(13,HIGH);//added 2/24/2016
 delay(100);
 digitalWrite(13,LOW);
 

 m2++;
  }
    //*******2*******
    while(m3<1){
     compare(); 
      m3++;
    }
    
    
  
 }
 
 
  

void takereading()
{
  
  

//0 means Analog Input A0
  digitalWrite(colred, HIGH);   Serial.println("*****");
    delay(delayTime);
  sensorValueR[k] = map(analogRead(sensorPin),0,1023,0,255);

  

  digitalWrite(colred, LOW);    delay(delayTime);
  digitalWrite(colgreen, HIGH);   delay(delayTime);  
  
  sensorValueG[k] = map(analogRead(sensorPin),0,1023,0,255);

  


  digitalWrite(colgreen, LOW);    delay(delayTime);
  digitalWrite(colblue, HIGH);   delay(delayTime);
  
  sensorValueB[k] = map(analogRead(sensorPin),0,1023,0,255);
   
   

  digitalWrite(colblue, LOW);  delay(delayTime);
//delay(600);
}
///*******************
/// calibrated in mmy room
void avarage(){
  
    colvalue[0]=(((sensorValueR[0]+sensorValueR[1]+sensorValueR[2])/3)-30)*2.83;
    colvalue[1]=(((sensorValueG[0]+sensorValueG[1]+sensorValueG[2])/3)-30)*2.83;
    colvalue[2]=(((sensorValueB[0]+sensorValueB[1]+sensorValueB[2])/3)-30)*2.83;
    
    
  }
  ///****************
  void printout(){
    Serial.print("R = ");
Serial.println(int(colvalue[0]));
Serial.print("G = ");
Serial.println(int(colvalue[1]));
Serial.print("B = ");
Serial.println(int(colvalue[2]));
  }
  ////******************
  void manipulate(){
    
    colvalue[0]=colvalue[0]-50;
    colvalue[1]=colvalue[1]-50;
    colvalue[2]=colvalue[2]-90;
    
  }
  ///*******************
 
  void check(){
   for(i=0;i<3;i++){
     if(colvalue[i]>255){
       colvalue[i]=255;
     }
     if(colvalue[i]<0){
       colvalue[i]=0;
     }
   }
  }
  //*************************

  
void takereading2(){
  
  

//0 means Analog Input A0
  digitalWrite(colred, HIGH);   Serial.println("*****");
    delay(delayTime);
  sensorValueR2[k2] = map(analogRead(sensorPin),0,1023,0,255);

  

  digitalWrite(colred, LOW);    delay(delayTime);
  digitalWrite(colgreen, HIGH);   delay(delayTime);  
  
  sensorValueG2[k2] = map(analogRead(sensorPin),0,1023,0,255);

  


  digitalWrite(colgreen, LOW);    delay(delayTime);
  digitalWrite(colblue, HIGH);   delay(delayTime);
  
  sensorValueB2[k2] = map(analogRead(sensorPin),0,1023,0,255);
   
   

  digitalWrite(colblue, LOW);  delay(delayTime);
//delay(600);
}
//****************************************
void avarage2(){
  
    colvalue2[0]=(((sensorValueR2[0]+sensorValueR2[1]+sensorValueR2[2])/3)-30)*2.83;
   colvalue2[1]=(((sensorValueG2[0]+sensorValueG2[1]+sensorValueG2[2])/3)-30)*2.83;
    colvalue2[2]=(((sensorValueB2[0]+sensorValueB2[1]+sensorValueB2[2])/3)-30)*2.83;
    
    
  }
  //************************
  void printout2(){
    Serial.print("R = ");
Serial.println(int(colvalue2[0]));
Serial.print("G = ");
Serial.println(int(colvalue2[1]));
Serial.print("B = ");
Serial.println(int(colvalue2[2]));
  }
  //****************
  void manipulate2(){
    
    colvalue2[0]=colvalue2[0]-50;
    colvalue2[1]=colvalue2[1]-50;
    colvalue2[2]=colvalue2[2]-90;
    
  }
 //***************
  void check2(){
   for(i=0;i<3;i++){
     if(colvalue2[i]>255){
       colvalue2[i]=255;
     }
     if(colvalue2[i]<0){
       colvalue2[i]=0;
     }
   }
  }

  //********************
 void compare(){
   
    for(i=0;i<3;i++){
      if(
      colvalue2[i]<colvalue[i]+sensitivity&&colvalue2[i]>colvalue[i]-sensitivity){
        
      
Serial.print("Matched");
      digitalWrite(13,HIGH);  Serial.print("Matched");
       
     
       
       
        
      }
      else{
        Serial.print(" not Matched");
        
      }
   
     
  
   
 }
 }
//****The End*******
 
