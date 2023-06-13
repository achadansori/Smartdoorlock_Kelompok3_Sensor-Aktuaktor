void password_enter() {

  if ((customKey >= '0') && (customKey <= '9') && customKey) {
    password[i++] = customKey;
    lcd.setCursor(i - 1, 1);
    lcd.print("*");
  }
  if (i == 4) {
    delay(200);
    for (int j = 0; j < 4; j++)
      pass[j] = EEPROM.read(j);
    if (!(strncmp(password, pass, 4))) {
      lcd.clear();
      delay(15);
      lcd.setCursor(1, 0);
      lcd.print("Password Benar");
      delay(1500);
      i = 0;
      digitalWrite(relay1, HIGH);
      lcd.setCursor(1, 0);
      lcd.print("Akses Diterima");
      lcd.setCursor (0, 1);
      lcd.print(F("AutoLock after "));
      for (int i = 5; i > 0; i--) {
        lcd.setCursor (15, 1); lcd.print(i);
        delay (1000);
      }
      digitalWrite(relay1, LOW);
      lcd.clear();
      delay(15);
      menu_utama = true;
    }

    else {
      i = 0;
      lcd.clear();
      delay(15);
      lcd.setCursor(1, 0);
      lcd.print("Password Salah");
      delay(1500);
      lcd.clear();
      delay(15);
      menu_utama = true;
    }
  }
}

void change() {
  int j = 0;
  lcd.clear();
  delay(15);
  lcd.print("Password Lama:");
  lcd.setCursor(0, 1);
  while (j < 4) {
    char key = customKeypad.getKey();
    if ((key >= '0') && (key <= '9') && key) {
      pass1[j++] = key;
      lcd.print(key);
    }
    key = 0;
  }
  delay(500);

  if ((strncmp(pass1, pass, 4))) {
    lcd.clear();
    delay(15);
    lcd.setCursor(1, 0);
    lcd.print("Password Salah");
    //lcd.print("Wrong Passkey...");
    lcd.setCursor(0, 1);
    lcd.print("Silahkan Ulangi");
    delay(1500);
  }
  else {
    j = 0;

    lcd.clear();
    delay(15);
    lcd.print("Password Baru:");
    lcd.setCursor(0, 1);
    while (j < 4) {
      char key = customKeypad.getKey();
      if ((key >= '0') && (key <= '9') && key) {
        pass[j] = key;
        lcd.print(key);
        EEPROM.write(j, key);
        j++;
      }
    }
    lcd.print("  Done......");
    delay(1000);
  }
  customKey = 0;
  lcd.clear();
  delay(15);
  menu_utama = true;
}
