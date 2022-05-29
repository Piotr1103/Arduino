const byte LED = 13;
const byte SW = 8;

bool lastState = LOW;
bool toggle = LOW;

void setup(){
  pinMode(LED, OUTPUT);
  pinMode(SW, INPUT);
}

void loop(){
  bool b1 = digitalRead(SW);

  if(b1){
    delay(20);                    //讓開關延遲偵測20毫秒，避免開關彈跳
    bool b2 = digitalRead(SW);    //再次讀取開關

    if(b1 == b2){                 //若兩次讀取值都相同
      lastState = b1;             //開關若是高電位，則將該狀態存入lastState
    }
  }

  if(b1 != lastState){            //放開開關後，b1和lastState狀態將不同
    toggle = !toggle;             //燈號反轉
    digitalWrite(LED, toggle);    //寫入
    lastState = LOW;              //讓lastState和b1狀態歸同，在下一次按下開關前不會進入此選擇分支
  }
}
