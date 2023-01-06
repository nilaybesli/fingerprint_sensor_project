#include <Adafruit_Fingerprint.h>
#include <LiquidCrystal.h>
#include <Keypad.h>
#include <SoftwareSerial.h>
SoftwareSerial mySerial(10,11);      
Adafruit_Fingerprint finger = Adafruit_Fingerprint(&mySerial);

LiquidCrystal lcd(A0, A1, A2,A3 ,A4 , A5);

int getFingerprintIDez();
int cursorColumn = 0;       //this controls the cursor postition
int menu = 0;               //this controls the menu settings 
int n=0;                    // variable used to point to the bits in the keypad input array
int addr=0;
char pswrdElement=0;
char a='0';                 //variables a,b,c,d are all zero by default and store each digit of the 4 digit passcode
char b='0';
char c='0';
char d='0';
char password[]={a,b,c,d}; //initializing an array called password with variables a,b,c,d that hold the password digits
char input[4];
const byte ROWS = 4;       // Four rows
const byte COLS = 4;       // Four columns

// Define the Keymap
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

// Connect keypad ROW0, ROW1, ROW2 and ROW3 to these Arduino pins.
byte rowPins[ROWS] = { 5,4,3,2 };

// Connect keypad COL0, COL1,COL2 and COL3 to these Arduino pins.
byte colPins[COLS] = {6,7,8,9 }; 


// Create the Keypad
Keypad kpd = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
char ID=0;
char id=0;
void setup() {
   lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print(" NISA KOTMAN  ");
  lcd.setCursor(0, 1);
  lcd.print(" 191502015   ");
  delay(3000);
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print(" NILAY BESLI  ");
  lcd.setCursor(0, 1);
  lcd.print(" 191502022   ");
  delay(3000);
  lcd.clear();

  lcd.setCursor(0,0);
  lcd.print("  SENSOR TESPIT");
  lcd.setCursor(0,1);
  lcd.print("     EDILIYOR!");
  delay(4000);
  lcd.clear();
  
  finger.begin(57600);
  if(finger.verifyPassword()){
    lcd.setCursor(0,0);
    lcd.print("  SENSOR TESPIT");
    lcd.setCursor(0,1);
    lcd.print("     EDILDI!");
    delay(4000);
    lcd.clear();
  }
  else{
    lcd.print("    SENSOR ");
    lcd.setCursor(0,1);
    lcd.print("   BULUNAMADI");
    delay(4000);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("  BAGLANTILARI");
    lcd.setCursor(0,1);
    lcd.print("  KONTROL ET !!");
    while (1) {
      delay(1);
    }
  }
  Serial.begin(9600);
  while (!Serial);  // For Yun/Leo/Micro/Zero/...
  delay(100);
  finger.getTemplateCount();
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("    KAYITLI");
  lcd.setCursor(12,0);
  lcd.print(finger.templateCount); 
  lcd.setCursor(0,1);
  lcd.print("  PARMAK IZI VAR");
  delay(4000);
  lcd.clear();

  lcd.setCursor(0,0);
  lcd.print("GIRIS ICIN");
  lcd.setCursor(0,1);
  lcd.print("A'YA BASINIZ");
  delay(4000);
  lcd.clear();

  lcd.setCursor(0,0);
  lcd.print("SIFRE DEGISTIRMEK");
  lcd.setCursor(0,1);
  lcd.print("ICIN B'YE BASINIZ");
  delay(4000);
  lcd.clear();

  lcd.setCursor(0,0);
  lcd.print("KAYDETMEK ICIN");
  lcd.setCursor(0,1);
  lcd.print("C'YE BASINIZ");
  delay(4000);
  lcd.clear();

   lcd.setCursor(0,0);
  lcd.print("SILMEK ICIN");
  lcd.setCursor(0,1);
  lcd.print("D'YE BASINIZ");
  delay(4000);
  lcd.clear();

}

uint8_t readnumber(void) {
  uint8_t num = 0;

  while (num == 0) {
    while (! Serial.available());
    num = Serial.parseInt();
  }
  return num;
}

void loop() {
   readKeypad(); 
    

}
void askForCode(){
  lcd.print("sifre gir");  //prints when the user wants to enter the code
}

void readKeypad(){
  char key = kpd.getKey();
  lcd.setCursor(cursorColumn,1);          // set the cursor to column "cursorColumn", line 1
  if(key)                      // Check for a valid key.
  {
    switch (key)
    {
      case '0':                                 // Each case is a button that is pressed
        if(menu == 1){                          // the value of "menu" determines the setting parameter and what each button does in that setting  
          lcd.print('0');
          cursorColumn=cursorColumn+1;
          input[n]='0';
          n=n+1;
        }
        else if(menu == 3){
          lcd.print('0');
          cursorColumn=cursorColumn+1;
          input[n]='0';
          n=n+1;
        }
        else if(menu == 4){
          lcd.print('0');
          cursorColumn=cursorColumn+1;
          input[n]='0';
          n=n+1;
        }
        break;
      case '1':
        if(menu == 1){
        lcd.print('1');
          cursorColumn=cursorColumn+1;
          input[n]='1';
          n=n+1;
        }
        else if(menu == 3){
          lcd.print('1');
          cursorColumn=cursorColumn+1;
          input[n]='1';
          n=n+1;
        }
        else if(menu == 4){
          lcd.print('1');
          cursorColumn=cursorColumn+1;
          input[n]='1';
          n=n+1;
        }
        break;
      case '2':
        if(menu == 1){
          lcd.print('2');
          cursorColumn=cursorColumn+1;
          input[n]='2';
          n=n+1;
        }
        else if(menu == 3){
          lcd.print('2');
          cursorColumn=cursorColumn+1;
          input[n]='2';
          n=n+1;
        }
        else if(menu == 4){
          lcd.print('2');
          cursorColumn=cursorColumn+1;
          input[n]='2';
          n=n+1;
        }
        break;
      case '3':
        if(menu == 1){
          lcd.print('3');
          cursorColumn=cursorColumn+1;
          input[n]='3';
          n=n+1;
        }
        else if(menu == 3){
          lcd.print('3');
          cursorColumn=cursorColumn+1;
          input[n]='3';
          n=n+1;
        } 
        else if(menu == 4){
          lcd.print('3');
          cursorColumn=cursorColumn+1;
          input[n]='3';
          n=n+1;
        }
        break;
      case '4':
        if(menu == 1){
          lcd.print('4');
          cursorColumn=cursorColumn+1;
          input[n]='4';
          n=n+1;
        }
        else if(menu == 3){
          lcd.print('4');
          cursorColumn=cursorColumn+1;
          input[n]='4';
          n=n+1;
        }
        else if(menu == 4){
          lcd.print('4');
          cursorColumn=cursorColumn+1;
          input[n]='4';
          n=n+1;
        }
        break;
      case '5':
        if(menu == 1){
          lcd.print('5');
          cursorColumn=cursorColumn+1;
          input[n]='5';
          n=n+1;
        }
        else if(menu == 3){
          lcd.print('5');
          cursorColumn=cursorColumn+1;
          input[n]='5';
          n=n+1;
        }
        else if(menu == 4){
          lcd.print('5');
          cursorColumn=cursorColumn+1;
          input[n]='5';
          n=n+1;
        }
        break;
      case '6':
        if(menu == 1){
          lcd.print('6');
          cursorColumn=cursorColumn+1;
          input[n]='6';
          n=n+1;
        }
        else if(menu == 3){
          lcd.print('6');
          cursorColumn=cursorColumn+1;
          input[n]='6';
          n=n+1;
        }
        else if(menu == 4){
          lcd.print('6');
          cursorColumn=cursorColumn+1;
          input[n]='6';
          n=n+1;
        }
        break;
      case '8':
        if(menu == 1){
          lcd.print('8');
          cursorColumn=cursorColumn+1;
          input[n]='8';
          n=n+1;
        }
        else if(menu == 3){
          lcd.print('8');
          cursorColumn=cursorColumn+1;
          input[n]='8';
          n=n+1;
        }
        else if(menu == 4){
          lcd.print('8');
          cursorColumn=cursorColumn+1;
          input[n]='8';
          n=n+1;
        }
        break;
      case '9':
        if(menu == 1){
          lcd.print('9');
          cursorColumn=cursorColumn+1;
          input[n]='9';
          n=n+1;
        }
        else if(menu == 3){
          lcd.print('9');
          cursorColumn=cursorColumn+1;
          input[n]='9';
          n=n+1;
        }
        else if(menu == 4){
          lcd.print('9');
          cursorColumn=cursorColumn+1;
          input[n]='9';
          n=n+1;
        }
        break;   
      case '7':
        if(menu == 1){
          lcd.print('7');
          cursorColumn=cursorColumn+1;
          input[n]='7';
          n=n+1;
        break;
        }
        else if(menu == 3){
          lcd.print('7');
          cursorColumn=cursorColumn+1;
          input[n]='7';
          n=n+1;
        }
        else if(menu == 4){
          lcd.print('7');
          cursorColumn=cursorColumn+1;
          input[n]='7';
          n=n+1;
        }   
      case 'A':
        if(menu == 0){
          lcd.setCursor(0,0);
          askForCode();
          lcd.setCursor(0,1);
          menu=menu+1;
        }
        break;
      case 'B':
        if(menu == 0){
          lcd.setCursor(0,0);
          lcd.print("Change Code?");
          lcd.setCursor(0,1);
          menu=menu+2;
        }
      case 'C':
       
        getFingerprintEnroll() ;
        break;   
      case 'D':
      lcd.clear();
        deleteFingerprint();
        break;
        case '#':
        reset();
        break;
      case '*':
        if(menu == 2){
          lcd.setCursor(0,0);
          lcd.print("Enter old code");
          lcd.setCursor(0,1);
          menu=menu+1;
        }  
      default:
       return; 
    }
  } 
  if(menu==1 && n > 3){                             //If the menu is in setting 1 and the input array has been filled with 4 digits then...
    doorlockCheck();    //calls the function to check whether the code that was input matches the code that is stored
  }
  else if(menu==3 && n > 3){
    oldCodeCheck();  
  }
  else if(menu==4 && n > 3){
  changeToNewCode(password,input);
  delay(250); 
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("şifre değişti");
  delay(1000);
  reset();
  }
  if(checkCode(password,input) == true){
    getFingerprintIDez();
    delay(50);
  }
  
}


boolean checkCode(char *a,char *b){                   //The function to check whether the contents of the first parameter,an array, match the 
  int p;                                              //match the contents of the second parameter, also an array.
  for(p=0; p<4; p++) 
    if(a[p]!=b[p]) return false;
    return true;
}

int changeToNewCode(char *a, char *b){
  int p = 0;
  for(p=0; p<4; p++){
    a[p]=b[p];
  } 
  n=0;
}


int doorlockCheck(){
  if(n > 3){
   if(checkCode(password,input) == true){
     delay(250);
     lcd.clear();
     lcd.setCursor(0,0);
     lcd.print("dogru!"); 
     fingerCheck(); 
   }
  else{
   delay(250);
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print("gecersiz kod!"); 
   delay(2000); 
   reset();
    }  
   cursorColumn=0;
   n=0;
  }
}

int oldCodeCheck(){
  if(n > 3){
   if(checkCode(password,input) == true){
     delay(250);  
     lcd.clear();
     lcd.setCursor(0,0);
     lcd.print("Correct!"); 
     delay(1000);
     lcd.clear();
     lcd.setCursor(0,0);
     lcd.print("Enter new Code");
     menu=4;
   }
  else{
   delay(250);
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print("Invalid Code!"); 
   delay(2000);
   reset();
    } 
   n=0; 
   cursorColumn=0;
  }
}

void reset(){
  int i;
  cursorColumn=0;
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Room 0");
  menu=0;
  n=0;
  for(i=0;i<4;i++){
    input[i]='r';
  }
}

void fingerCheck(){
  if (finger.verifyPassword()) {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Found sensor!");
    
  }
  else {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Did not find fingerprint sensor :(");
    while (1);
  }
  lcd.setCursor(0,1);
  lcd.print("Waiting...");
   
  //return ;
  getFingerprintIDez();
    delay(50);
}
uint8_t getFingerprintID() {
  uint8_t p = finger.getImage();
  switch (p) {
    case FINGERPRINT_OK:
      Serial.println("Image taken");
      break;
    case FINGERPRINT_NOFINGER:
      Serial.println("No finger detected");
      return p;
    case FINGERPRINT_PACKETRECIEVEERR:
      Serial.println("Communication error");
      return p;
    case FINGERPRINT_IMAGEFAIL:
      Serial.println("Imaging error");
      return p;
    default:
      Serial.println("Unknown error");
      return p;
  }

  // OK success!

  p = finger.image2Tz();
  switch (p) {
    case FINGERPRINT_OK:
      Serial.println("Image converted");
      break;
    case FINGERPRINT_IMAGEMESS:
      Serial.println("Image too messy");
      return p;
    case FINGERPRINT_PACKETRECIEVEERR:
      Serial.println("Communication error");
      return p;
    case FINGERPRINT_FEATUREFAIL:
      Serial.println("Could not find fingerprint features");
      return p;
    case FINGERPRINT_INVALIDIMAGE:
      Serial.println("Could not find fingerprint features");
      return p;
    default:
      Serial.println("Unknown error");
      return p;
  }
  
  // OK converted!
  p = finger.fingerSearch();
  if (p == FINGERPRINT_OK) {
    Serial.println("Found a print match!");
  } else if (p == FINGERPRINT_PACKETRECIEVEERR) {
    Serial.println("Communication error");
    return p;
  } else if (p == FINGERPRINT_NOTFOUND) {
    Serial.println("Did not find a match");
    return p;
  } else {
    Serial.println("Unknown error");
    return p;
  }   
  
  // found a match!
  Serial.print("Found ID #"); Serial.print(finger.fingerID); 
  Serial.print(" with confidence of "); Serial.println(finger.confidence); 
}

// returns -1 if failed, otherwise returns ID #
int getFingerprintIDez() {
  uint8_t p = finger.getImage();
  if (p != FINGERPRINT_OK)  return -1;

  p = finger.image2Tz();
  if (p != FINGERPRINT_OK)  return -1;

  p = finger.fingerFastSearch();
  if (p != FINGERPRINT_OK)  return -1;

   
  lcd.clear();
  lcd.print("Found ID #"); lcd.print(finger.fingerID); 
  lcd.setCursor(0,1);
  lcd.print("Confidence "); lcd.print(finger.confidence);
  delay(5000);
  reset();
  return finger.fingerID; 
}

uint8_t getFingerprintEnroll() {

Serial.println("Ready to enroll a fingerprint!");
  Serial.println("Please type in the ID # (from 1 to 127) you want to save this finger as...");
  id = readnumber();
  if (id == 0) {// ID #0 not allowed, try again!
     return;
  }
  Serial.print("Enrolling ID #");
  Serial.println(id);
  int p = -1;
  Serial.print("Waiting for valid finger to enroll as #"); Serial.println(ID);
  while (p != FINGERPRINT_OK) {
    p = finger.getImage();
    switch (p) {
    case FINGERPRINT_OK:
      Serial.println("Image taken");
      break;
    case FINGERPRINT_NOFINGER:
      Serial.println(".");
      break;
    case FINGERPRINT_PACKETRECIEVEERR:
      Serial.println("Communication error");
      break;
    case FINGERPRINT_IMAGEFAIL:
      Serial.println("Imaging error");
      break;
    default:
      Serial.println("Unknown error");
      break;
    }
  }

  // OK success!

  p = finger.image2Tz(1);
  switch (p) {
    case FINGERPRINT_OK:
      Serial.println("Image converted");
      break;
    case FINGERPRINT_IMAGEMESS:
      Serial.println("Image too messy");
      return p;
    case FINGERPRINT_PACKETRECIEVEERR:
      Serial.println("Communication error");
      return p;
    case FINGERPRINT_FEATUREFAIL:
      Serial.println("Could not find fingerprint features");
      return p;
    case FINGERPRINT_INVALIDIMAGE:
      Serial.println("Could not find fingerprint features");
      return p;
    default:
      Serial.println("Unknown error");
      return p;
  }

  Serial.println("Remove finger");
  delay(2000);
  p = 0;
  while (p != FINGERPRINT_NOFINGER) {
    p = finger.getImage();
  }
  Serial.print("ID "); Serial.println(ID);
  p = -1;
  Serial.println("Place same finger again");
  while (p != FINGERPRINT_OK) {
    p = finger.getImage();
    switch (p) {
    case FINGERPRINT_OK:
      Serial.println("Image taken");
      break;
    case FINGERPRINT_NOFINGER:
      Serial.print(".");
      break;
    case FINGERPRINT_PACKETRECIEVEERR:
      Serial.println("Communication error");
      break;
    case FINGERPRINT_IMAGEFAIL:
      Serial.println("Imaging error");
      break;
    default:
      Serial.println("Unknown error");
      break;
    }
  }

  // OK success!

  p = finger.image2Tz(2);
  switch (p) {
    case FINGERPRINT_OK:
      Serial.println("Image converted");
      break;
    case FINGERPRINT_IMAGEMESS:
      Serial.println("Image too messy");
      return p;
    case FINGERPRINT_PACKETRECIEVEERR:
      Serial.println("Communication error");
      return p;
    case FINGERPRINT_FEATUREFAIL:
      Serial.println("Could not find fingerprint features");
      return p;
    case FINGERPRINT_INVALIDIMAGE:
      Serial.println("Could not find fingerprint features");
      return p;
    default:
      Serial.println("Unknown error");
      return p;
  }

  // OK converted!
  Serial.print("Creating model for #");  Serial.println(ID);

  p = finger.createModel();
  if (p == FINGERPRINT_OK) {
    Serial.println("Prints matched!");
  } else if (p == FINGERPRINT_PACKETRECIEVEERR) {
    Serial.println("Communication error");
    return p;
  } else if (p == FINGERPRINT_ENROLLMISMATCH) {
    Serial.println("Fingerprints did not match");
    return p;
  } else {
    Serial.println("Unknown error");
    return p;
  }

  Serial.print("ID "); Serial.println(ID);
  p = finger.storeModel(ID);
  if (p == FINGERPRINT_OK) {
    Serial.println("Stored!");
  } else if (p == FINGERPRINT_PACKETRECIEVEERR) {
    Serial.println("Communication error");
    return p;
  } else if (p == FINGERPRINT_BADLOCATION) {
    Serial.println("Could not store in that location");
    return p;
  } else if (p == FINGERPRINT_FLASHERR) {
    Serial.println("Error writing to flash");
    return p;
  } else {
    Serial.println("Unknown error");
    return p;
  }

  return true;
}





uint8_t deleteFingerprint() {
  Serial.println("Please type in the ID # (from 1 to 127) you want to delete...");
  uint8_t id = readnumber();
  
  if (id == 0) {// ID #0 not allowed, try again!
     return;
  }

  Serial.print("Deleting ID #");
  Serial.println(id);
  uint8_t p = -1;

  p = finger.deleteModel(id);

  if (p == FINGERPRINT_OK) {
    Serial.println("Deleted!");
  } else if (p == FINGERPRINT_PACKETRECIEVEERR) {
    Serial.println("Communication error");
  } else if (p == FINGERPRINT_BADLOCATION) {
    Serial.println("Could not delete in that location");
  } else if (p == FINGERPRINT_FLASHERR) {
    Serial.println("Error writing to flash");
  } else {
    Serial.print("Unknown error: 0x"); Serial.println(p, HEX);
  }

  return p;
}
