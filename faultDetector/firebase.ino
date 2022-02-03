void setupFb(){
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.setReadTimeout(object, 1000 * 60);
  Firebase.setwriteSizeLimit(object, "tiny");
  Firebase.setFloatDigits(4);
}

void sendFb(){
  Firebase.setFloat(object, "current1", (val1));
  Firebase.setFloat(object, "current2", (val2));
  Firebase.setFloat(object, "current3", (val3));
}
