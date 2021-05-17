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
	displayLetterCount(sortedStr);
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
void displayLetterCount(String str) {
	int letters[57] = {};
	for(int i = 0; i < str.length(); i++) {
		int index = str[i] - 65;
		letters[index] = letters[index] + 1;
	}
	for(int i = 0; i < 57; i++) {
		if(letters[i] > 0) {
			letters[i] = letters[i] + 1;	
			char myLetter = i + 65;
			Serial.print(myLetter);
			Serial.println(letters[index]);
		}
	}
	
}
