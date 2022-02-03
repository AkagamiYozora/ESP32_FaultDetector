void setupCt(){
  adc1_config_channel_atten(ADC1_CHANNEL_6, ADC_ATTEN_DB_11);
  analogReadResolution(10);
  emon1.current (32,105);
  emon2.current (33,105);
  emon3.current (35,105);
}

void mainCt (){
  int sampling = 15;
  int counter1 = 0, counter2 = 0, counter3 = 0;
  float mean1 = 0.00, mean2 = 0.00, mean3 = 0.00;
  while (counter1 < sampling){
    double Irms1 = emon1.calcIrms(1480);  // Calculate Irms only
    counter1++;mean1 += Irms1;
    double Irms2 = emon2.calcIrms(1480);  // Calculate Irms only
    counter2++;mean2 += Irms2;
    double Irms3 = emon3.calcIrms(1480);  // Calculate Irms only
    counter3++;mean3 += Irms3;
  }
  val1 = mean1/counter1;
  val2 = mean2/counter2;
  val3 = mean3/counter3;
}

void testCt (){
  double Irms1 = emon1.calcIrms(1480);  // Calculate Irms only
  double Irms2 = emon2.calcIrms(1480);  // Calculate Irms only
  double Irms3 = emon3.calcIrms(1480);  // Calculate Irms only
  val1 = Irms1*10;
  val2 = Irms2*10;
  val3 = Irms3*10;
}
