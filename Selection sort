/*
 * Enter numbers one at a time and return a list of sorted number once the number 0
 * is entered.
 */
int sortingArray[97];
int index;

void setup() {
  Serial.begin(9600);
  index = 0;
}

void loop() {
  if(Serial.available()) {
    int ourNumber = Serial.parseInt();
    if(ourNumber == 0){
      selectionSort();
      printNumbers();
      index = 0;
    } else {
      sortingArray[index] = ourNumber;
      index++;
      Serial.print("received ");
      Serial.println(ourNumber);
      for(int i = 0; i < index; i++) {
        Serial.print(sortingArray[i]);
        Serial.print(" ");
      }
      Serial.println();
    }
  }
}

void selectionSort(){
  for(int i = 0; i < sizeof(sortingArray)/sizeof(sortingArray[0]); i++) {
    int tempNum = sortingArray[i];
    int jIndex = i;
    for(int j = i + 1; j < sizeof(sortingArray)/sizeof(sortingArray[0]); j++) {
      if(tempNum < sortingArray[j]) {
        tempNum = sortingArray[j];
        jIndex = j;
      }
    }
    sortingArray[jIndex] = sortingArray[i];
    sortingArray[i] = tempNum;
  }
}

void printNumbers(){
  for(int i = 0; i < index; i++) {
    Serial.print(sortingArray[i]);
    Serial.print(" ");
  }
  Serial.println("I'm done.");
  Serial.println();
}