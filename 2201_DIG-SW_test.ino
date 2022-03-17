#define  TXD1 PA9
#define  RXD1 PA10
HardwareSerial Serial1( RXD1, TXD1 ); 

uint8_t SWsel[3]={PD11,PD12,PD13};
uint8_t SWrow[4]={PD14,PD15,PC8,PC9};
uint8_t val[4];

void setup() {
  Serial1.begin(115200);
  for(int i= 0;i<=3;i++){
    pinMode(SWrow[i],INPUT);
  }
  for(int i= 0;i<=2;i++){
    pinMode(SWsel[i],OUTPUT);
  }
}

void loop() {
  int n=6;
  for(int j=0;j<=5;j++){
    digitalWrite(SWsel[0],(j&1)>>0);
    digitalWrite(SWsel[1],(j&2)>>1);
    digitalWrite(SWsel[2],(j&4)>>2);

    for(int k=0; k<=3; k++){
    val[k]=!digitalRead(SWrow[k]);
    val[k]=val[k]<<k;
    }
    
    uint8_t Sval=val[0]+val[1]+val[2]+val[3];
    String Disp = "DSW" + String(j+n)+ "=" + String(Sval) ;
    Serial1.println(Disp);
    n=0;
  }
  delay(2000);
}
