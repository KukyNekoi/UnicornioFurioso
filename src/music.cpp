#ifndef MUSIC_H

#include <Arduino.h>
#include "unicornio_pinout.h"
#define SD_ChipSelectPin 4
#include <SD.h>
#include <TMRpcm.h>
#include <SPI.h>

class Music {
  private:
    TMRpcm *tmrpcm;
    bool sd_status;

  public:
    Music::Music(){
        this->tmrpcm = new TMRpcm();
        pinMode(SPEAKER_1, OUTPUT);
        pinMode(SPEAKER_2, OUTPUT);
        tmrpcm->speakerPin = 5;
        tmrpcm->loop(true);
        // tmrpcm->speakerPin2 = 6;
        Serial.println("Starting SD.");
        Serial.println("****");
        Serial.println(SD_ChipSelectPin);
        Serial.println("****");
        if (!SD.begin(SD_ChipSelectPin)) {
            Serial.println("SD failed to initialize. Ignoring");
            this->sd_status = false;
            return;
        }
        else {
            Serial.println("SD Ready and operational!");
            this->sd_status = true;
            tmrpcm->setVolume(5);
        }
    }

    void Music::drift() {
        tmrpcm->play("drift.wav");//, false);
    }

    void Music::engine() {
        tmrpcm->play("engine.wav");//, false);
    }

    void Music::music() {
        tmrpcm->play("ost1.wav");//, true);
    }
};

#define MUSIC_H
#endif