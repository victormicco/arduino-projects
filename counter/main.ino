int ledA = 13;
int ledB = 12;
int ledC = 11;
int ledD = 10;
int ledE = 9;
int ledF = 8;
int ledG = 7;
int incrementButtonPin = 2;
int decrementButtonPin = 3;
int incrementReading = 0;
int decrementReading = 0;
int lastIncrementReading = 0;
int lastDecrementReading = 0;
int counter = 0;

void setup() {
  pinMode(ledA, OUTPUT);
  pinMode(ledB, OUTPUT);
  pinMode(ledC, OUTPUT);
  pinMode(ledD, OUTPUT);
  pinMode(ledE, OUTPUT);
  pinMode(ledF, OUTPUT);
  pinMode(ledG, OUTPUT);
  pinMode(incrementButtonPin, INPUT);
  pinMode(decrementButtonPin, INPUT);
  Serial.begin(9600);
}

void displayNumber(int number) {
  bool segments[10][7] = {
    {LOW, LOW, LOW, LOW, LOW, LOW, HIGH},  // 0
    {HIGH, LOW, LOW, HIGH, HIGH, HIGH, HIGH},  // 1
    {LOW, LOW, HIGH, LOW, LOW, HIGH, LOW},  // 2
    {LOW, LOW, LOW, LOW, HIGH, HIGH, LOW},  // 3
    {HIGH, LOW, LOW, HIGH, HIGH, LOW, LOW},  // 4
    {LOW, HIGH, LOW, LOW, HIGH, LOW, LOW},  // 5
    {LOW, HIGH, LOW, LOW, LOW, LOW, LOW},  // 6
    {LOW, LOW, LOW, HIGH, HIGH, HIGH, HIGH},  // 7
    {LOW, LOW, LOW, LOW, LOW, LOW, LOW},  // 8
    {LOW, LOW, LOW, LOW, HIGH, LOW, LOW}   // 9
  };

  digitalWrite(ledA, segments[number][0]);
  digitalWrite(ledB, segments[number][1]);
  digitalWrite(ledC, segments[number][2]);
  digitalWrite(ledD, segments[number][3]);
  digitalWrite(ledE, segments[number][4]);
  digitalWrite(ledF, segments[number][5]);
  digitalWrite(ledG, segments[number][6]);
  delay(100);
}

void loop() {
  incrementReading = digitalRead(incrementButtonPin);
  decrementReading = digitalRead(decrementButtonPin);

  if (incrementReading != lastIncrementReading) {
    if (incrementReading == HIGH) {
      counter++;
    }
  }
  lastIncrementReading = incrementReading;

  if (decrementReading != lastDecrementReading) {
    if (decrementReading == HIGH) {
      counter--;
    }
  }
  lastDecrementReading = decrementReading;

  if (counter >= 10) {
    counter = 0;
  }
  if (counter <= -1) {
    counter = 9;
  }

  displayNumber(counter);
  Serial.println(counter);
}
