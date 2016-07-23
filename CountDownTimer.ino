#include <Keypad.h>
#include <DS3231.h>
// Init the DS3231 using the hardware interface
DS3231  rtc(A4, A5);

// Init a Time-data structure
Time  t;


//Keypad
const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
//define the cymbols on the buttons of the keypads
char hexaKeys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {9,8,7,6}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {5,4,3,2}; //connect to the column pinouts of the keypad

//initialize an instance of class NewKeypad
Keypad MyKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 


void setup() {
    // Setup Serial connection
  Serial.begin(115200);

  // Initialize the rtc object
  rtc.begin();
  
  // The following lines can be uncommented to set the date and time
  //rtc.setDOW(FRIDAY);     // Set Day-of-Week to SUNDAY
  //rtc.setTime(8, 30, 0);     // Set the time to 12:00:00 (24hr format)
  //rtc.setDate(1, 1, 2014);   // Set the date to January 1st, 2014

}

byte dateAndTime[7];

void loop() {

  Serial.println("Enter Days Left");
  dateAndTime[0]= MyKeypad.waitForKey();
  Serial.println("Enter Hours Left, in 24 hours with a '0' in the beginning if the hours are below '10'");
  dateAndTime[0]= MyKeypad.waitForKey();
  dateAndTime[0]= MyKeypad.waitForKey();

  
    // Get data from the DS3231
  t = rtc.getTime();

}
