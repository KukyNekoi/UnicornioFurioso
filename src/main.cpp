#include "unicornio_pinout.h"
#include "motor.cpp"
#include "music.cpp"
#include "messages.h"

Music *music;
Motor *motor;

void setup()
{
  //settingup pins
  Serial.begin(9600);
  Serial.println("Setting up music module");
  music = new Music();
  Serial.println("Setting up motor module");
  motor = new Motor();
  Serial.println("Setting up BT module");
  BT_SERIAL.begin(9600);
  Serial.println("Setup finished");
}
int16_t previous_state = COMMAND_SILENCE;
void loop()
{
  motor->modulate();
  if (BT_SERIAL.available())
  {
    Serial.print("RECIEVED: ");
    int16_t response = BT_SERIAL.read();
    switch (response) {
    case COMMAND_FORWARD:
      Serial.println("Forward!");
      motor->forward();
      music->engine();
      break;
    case COMMAND_BACKWARD:
      Serial.println("Backwards!");
      motor->backward();
      music->engine();
      break;
    case COMMAND_TURN_LEFT:
      Serial.println("Turn left!");
      motor->turn_left();
      music->drift();
      break;
    case COMMAND_TURN_RIGHT:
      Serial.println("Turn right!");
      motor->turn_right();
      music->drift();
      break;
    case COMMAND_DRIFT_LEFT:
      Serial.println("Drift left!");
      motor->drift_left();
      music->drift();
      break;
    case COMMAND_DRIFT_RIGHT:
      Serial.println("Drift right!");
      motor->drift_right();
      music->drift();
      break;
    case COMMAND_STOP:
      Serial.println("STOP!");
      motor->stop();
      music->engine();
      break;
    case COMMAND_DRIFT_STOP:
      Serial.println("DriftStop!");
      motor->stop();
      music->engine();
      break;
    case COMMAND_SOUND:
      Serial.println("SOUND ON!");
      music->music();
      break;
    case COMMAND_SILENCE:
      Serial.println("SOUND OFF!");
      music->engine();
      break;
    default:
      if(previous_state == COMMAND_TURN_LEFT || previous_state == COMMAND_TURN_RIGHT) {
        motor->forward();
        music->engine();
        Serial.println("Returning to pos");
      }
      break;
    }
    previous_state = response;
  }
}