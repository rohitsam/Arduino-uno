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
int colvalue2[3];


void setup(){
  
 
  pinMode(colred, OUTPUT);        
  pinMode(colgreen, OUTPUT);
  pinMode(colblue, OUTPUT);
  pinMode(buttonPin, INPUT);
  pinMode(10, OUTPUT);        
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
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
 output();
 Display();
 m++;
 
  }
 
  
}
void takereading(){
  
  

//0 means Analog Input A0
  digitalWrite(colred, HIGH);   Serial.println("***");
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
void avarage(){
  
    colvalue[0]=(((sensorValueR[0]+sensorValueR[1]+sensorValueR[2])/3)-30)*2.83;
    colvalue[1]=(((sensorValueG[0]+sensorValueG[1]+sensorValueG[2])/3)-30)*2.83;
    colvalue[2]=(((sensorValueB[0]+sensorValueB[1]+sensorValueB[2])/3)-30)*2.83;
    
    
  }
  void printout(){
    Serial.print("R = ");
Serial.println(int(colvalue[0]));
Serial.print("G = ");
Serial.println(int(colvalue[1]));
Serial.print("B = ");
Serial.println(int(colvalue[2]));
  }
  
  void manipulate(){
    
    colvalue[0]=colvalue[0]-50;
    colvalue[1]=colvalue[1]-50;
    colvalue[2]=colvalue[2]-90;
    
  }
 
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

  void output(){
    for(i=0;i<3;i++){
      colvalue2[i]=colvalue[i];
    }
    if(colvalue2[0]<colvalue2[1]&&colvalue2[0]<colvalue2[2]){
      colvalue2[0]=0;
      if(colvalue2[1]<colvalue2[2]){
        colvalue2[1]=colvalue2[1]/2;
      }
      else{
        colvalue2[2]=colvalue2[2]/2;
        
      }
      
    }
    if(colvalue2[1]<colvalue2[2]&&colvalue2[1]<colvalue2[0]){
      colvalue2[1]=0;
      if(colvalue2[2]<colvalue2[0]){
        colvalue2[2]=colvalue2[2]/2;
      }
      else{
        colvalue2[0]=colvalue2[0]/2;
        
      }
      
    }
    if(colvalue2[2]<colvalue2[1]&&colvalue2[2]<colvalue2[0]){
      colvalue2[2]=0;
      if(colvalue2[1]<colvalue2[0]){
        colvalue2[1]=colvalue2[1]/2;
      }
      else{
        colvalue2[0]=colvalue2[0]/2;
        
      }
      
    }
     
  }
  void Display(){
  analogWrite(10,colvalue2[0]);
    analogWrite(11,colvalue2[1]);
   analogWrite(12,colvalue2[2]);
  }
  

