int segments[10][7] = {
  {1,1,1,1,1,1,0},  //0
  {0,1,1,0,0,0,0},  //1
  {1,1,0,1,1,0,1},  //2
  {1,1,1,1,0,0,1},  //3
  {0,1,1,0,0,1,1},  //4
  {1,0,1,1,0,1,1},  //5
  {1,0,1,1,1,1,1},  //6
  {1,1,1,0,0,0,0},  //7
  {1,1,1,1,1,1,1},  //8
  {1,1,1,1,0,1,1}   //9
};

const int btn = 2;
int cnt = 0;

void setup(){
  for(int pin=5;pin<=11;pin++){
    pinMode(pin, OUTPUT);
  }

  pinMode(btn, INPUT);
}

void segmentWrite(int digit){
  for(int ledSeg=0;ledSeg<7;ledSeg++){
    digitalWrite(ledSeg+5, segments[digit][ledSeg]);
  }
}

void loop(){
  int btnStatus = 0;
  btnStatus = digitalRead(btn);
  delay(100);
  segmentWrite(cnt);

  if(btnStatus==HIGH){
    cnt++;

    if(cnt>9){
      cnt = 0;
    }

    delay(100);
  }
}