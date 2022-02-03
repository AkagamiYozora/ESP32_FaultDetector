void setupLcd(){
  tft.init();
  tft.setRotation(3);
  tft.fillScreen(ST7735_BLACK);
  tft.setCursor(5,5);
  tft.setTextSize(1);
  tft.setTextColor(ST7735_WHITE);
  tft.setTextWrap(true);
  WiFi.begin(ssid, password);
  while ( WiFi.status() != WL_CONNECTED ) {
    delay ( 500 );
    tft.print ( "." );
  }
  tft.setCursor(5,17);
  tft.print("Connected to : ");
  tft.print(ssid);
  tft.setCursor(5,29);
  tft.print("IP : ");
  tft.print(WiFi.localIP());
}

void mainLcd(){
  //header
  tft.fillScreen(ST7735_WHITE);
  tft.drawRect(2, 2, 156, 124, ST7735_BLACK);
  tft.fillRect(2, 2, 156, 24, ST7735_BLACK);

  //box
  tft.drawRect(5, 38, 120, 23, ST7735_BLUE);
  tft.fillRect(5, 38, 16, 23, ST7735_BLUE);
  tft.fillRect(5, 63, 16, 23, ST7735_CYAN);
  tft.drawRect(5, 63, 120, 23, ST7735_BLACK);
  tft.drawRect(5, 88, 120, 23, ST7735_RED);
  tft.fillRect(5, 88, 16, 23, ST7735_RED);

  //var
  tft.setTextSize(2);
  tft.setCursor(8,42);
  tft.setTextColor(ST7735_BLACK);
  tft.print("R");
  tft.setCursor(8,68);
  tft.setTextColor(ST7735_BLACK);
  tft.print("S");
  tft.setCursor(8,93);
  tft.setTextColor(ST7735_BLACK);
  tft.print("T");
}

void headTime(){
  timeClient.update();
  int n = (120 - timeClient.getFormattedDate().length())/3;
  tft.setCursor(n,5);
  tft.setTextSize(1);
  tft.setTextColor(ST7735_WHITE, ST7735_BLACK);
  tft.setTextWrap(true);
  tft.print(timeClient.getFormattedDate());
  n = (123 - timeClient.getFormattedTime().length())/2;
  tft.setCursor(n,17);
  tft.print(timeClient.getFormattedTime());
}

float tresshold = 0.30;

void varLcd(){
  tft.setTextSize(2);
  tft.setCursor(25,42);
  if(val1<tresshold){
    tft.setTextColor(ST7735_BLACK, ST7735_WHITE);
    tft.fillRect(130, 38, 22, 23, ST7735_GREEN);
  } else{
    tft.setTextColor(ST7735_BLUE, ST7735_WHITE);
    tft.fillRect(130, 38, 22, 23, ST7735_BLUE);
  }
  tft.print(String(val1)+" ");
  
  
  tft.setCursor(25,68);
  if(val2<tresshold){
    tft.setTextColor(ST7735_BLACK, ST7735_WHITE);
    tft.fillRect(130, 63, 22, 23, ST7735_GREEN);
  } else{
    tft.setTextColor(ST7735_BLUE, ST7735_WHITE);
    tft.fillRect(130, 63, 22, 23, ST7735_BLUE);
  }
  tft.print(String(val2)+" ");
  
  tft.setCursor(25,93);
  if(val3<tresshold){
    tft.setTextColor(ST7735_BLACK, ST7735_WHITE);
    tft.fillRect(130, 88, 22, 23, ST7735_GREEN); 
  } else{
    tft.setTextColor(ST7735_BLUE, ST7735_WHITE);
    tft.fillRect(130, 88, 22, 23, ST7735_BLUE);
  }
  tft.print(String(val3)+" ");

  //unit
  tft.setCursor(105,42);
  tft.setTextColor(ST7735_BLACK, ST7735_WHITE);
  tft.print("A");
  tft.setCursor(105,68);
  tft.setTextColor(ST7735_BLACK, ST7735_WHITE);
  tft.print("A");
  tft.setCursor(105,93);
  tft.setTextColor(ST7735_BLACK, ST7735_WHITE);
  tft.print("A");
}
