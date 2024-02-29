#include <Arduino.h>

/* struct Touch {
  const uint8_t Touch;
  uint32_t pressTimes;
  bool touched;
};

Touch person_1 = {14,0,false};
static uint32_t count;

void IRAM_ATTR call();

void setup() {
  Serial.begin(115200);
  pinMode(person_1.Touch, INPUT_PULLUP);
  attachInterrupt(person_1.Touch,call,RISING);
}

void loop() {
  if(person_1.touched){
    Serial.printf("some call the door like", person_1.pressTimes, "times");
    person_1.touched = false;
  }
  if (millis() - count > 60000) {
    count = millis();
    detachInterrupt(person_1.Touch);
    Serial.println("Interrupt Detached!");
  }
}

void IRAM_ATTR call(){
  person_1.pressTimes+= 1;
  person_1.touched = true;
};

*/

volatile int interruptLoop;
int totalIRP;

hw_timer_t * timer = NULL;
portMUX_TYPE timerMux = portMUX_INITIALIZER_UNLOCKED;

void IRAM_ATTR onTimer() {
  portENTER_CRITICAL_ISR(&timerMux);
  interruptLoop++;
  portEXIT_CRITICAL_ISR(&timerMux);
};

void setup() {
  Serial.begin(115200);
  timer = timerBegin(0, 80, true);
  timerAttachInterrupt(timer, &onTimer, true);
  timerAlarmWrite(timer, 500000, true);
  timerAlarmEnable(timer);
}

void loop() {
  if (interruptLoop > 0) {
    portENTER_CRITICAL(&timerMux);
    interruptLoop--;
    portEXIT_CRITICAL(&timerMux);
     totalIRP++;
    Serial.print("An interrupt as occurred. Total number: ");
    Serial.println(totalIRP);
  }
}