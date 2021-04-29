void setup() {
  Serial.begin(9600);
}

void loop() {
  if(Serial.available() > 0) {
    String myStr = Serial.readString();
    //char myChar = Serial.read();
    //int accii = myChar;
    
    Serial.println(myStr);
    String sortedStr = sorter(myStr);
	Serial.println(sortedStr);
  }
}

String sorter(String str){
  String sortedStr = str;
  for( int i = 1; i < str.length(); i++){
    for( int j = i - 1; j >= 0 && sortedStr[j] > sortedStr[j+1] ; j--) {
		char tempChar = sortedStr[j];
		sortedStr[j] = sortedStr[j + 1];
		sortedStr[j + 1] = tempChar;
	}
  }  
  return SortedStr;
}

