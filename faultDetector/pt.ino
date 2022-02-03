static int updateTime(struct pt *pt){
  static unsigned long lastTimeBlink = 0;
  PT_BEGIN(pt);
  while(1) {
    lastTimeBlink = millis();
    PT_WAIT_UNTIL(pt, millis() - lastTimeBlink > 100);
    headTime();
  }
  PT_END(pt);
}

static int updateCT(struct pt *pt){
  static unsigned long lastTimeBlink = 0;
  PT_BEGIN(pt);
  while(1) {
    lastTimeBlink = millis();
    PT_WAIT_UNTIL(pt, millis() - lastTimeBlink > 200);
//    mainCt();
    testCt();
    varLcd();
  }
  PT_END(pt);
}

static int updateFb(struct pt *pt){
  static unsigned long lastTimeBlink = 0;
  PT_BEGIN(pt);
  while(1) {
    lastTimeBlink = millis();
    PT_WAIT_UNTIL(pt, millis() - lastTimeBlink > 300);
    sendFb();
  }
  PT_END(pt);
}
