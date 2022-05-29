const byte LED = 13;
const byte SW = 8;

void setup(){
  pinMode(LED, OUTPUT);
  //pinMode(SW, INPUT);
  pinMode(SW, INPUT_PULLUP);    //啟用上拉電阻
}

void loop(){
  bool val = digitalRead(SW);
  digitalWrite(LED, val);
}
