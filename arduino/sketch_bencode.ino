#include <EmBencode.h>

void EmBencode::PushChar (char ch) {
  Serial.write(ch);
}

static void sendSomeData () {
  EmBencode encoder;
  // send a simple string
  encoder.push("abcde");
  // send a number of bytes, could be binary
  encoder.push("123", 3);
  // send an integer
  encoder.push(12345);
  // send a list with an int, a nested list, and an int
  encoder.startList();
    encoder.push(987);
    encoder.startList();
      encoder.push(654);
    encoder.endList();
    encoder.push(321);
  encoder.endList();
  // send a large integer
  encoder.push(999999999);
  // send a dictionary with two entries
  encoder.startDict();
    encoder.push("resistor");
    encoder.push(416);
    encoder.push("serialno");
    encoder.push("s001");
  encoder.endDict();
  // send one last string
  encoder.push("bye!");
}

void setup () {
  Serial.begin(57600);
  Serial.println("\n[serialSend]");
}

void loop () {
  sendSomeData();
  Serial.println();
  delay(3000);
}
