#ifndef MOTOR_H
#include <Arduino.h>
#include "unicornio_pinout.h"

class Motor{
    private: 
        int power_left;
        int power_right;

    public:
        Motor(){
            this->stop();
        };

        void Motor::turn_right(){
            // power_left = 255;
            // power_right = 127;
            analogWrite(DRIVER_FORWARD_LEFT, 165);
            analogWrite(DRIVER_FORWARD_RIGHT, 255);
            analogWrite(DRIVER_BACKWARD_LEFT, 0);
            analogWrite(DRIVER_BACKWARD_RIGHT, 0);
        }

        void Motor::turn_left(){
            analogWrite(DRIVER_FORWARD_LEFT, 255);
            analogWrite(DRIVER_FORWARD_RIGHT, 165);
            analogWrite(DRIVER_BACKWARD_LEFT, 0);
            analogWrite(DRIVER_BACKWARD_RIGHT, 0);
            
        }

        void Motor::center(){
            this->forward();
        }

        void Motor::stop(){
            // power_left = 0;
            // power_right = 0;

            analogWrite(DRIVER_FORWARD_LEFT, 0);
            analogWrite(DRIVER_FORWARD_RIGHT, 0);
            analogWrite(DRIVER_BACKWARD_LEFT, 0);
            analogWrite(DRIVER_BACKWARD_RIGHT, 0);
        }


        void Motor::forward(){
            // power_left = 255;
            // power_right = 255;
            analogWrite(DRIVER_FORWARD_LEFT, 255);
            analogWrite(DRIVER_FORWARD_RIGHT, 255);
            analogWrite(DRIVER_BACKWARD_LEFT, 0);
            analogWrite(DRIVER_BACKWARD_RIGHT, 0);
        }

        void Motor::backward(){
            analogWrite(DRIVER_FORWARD_LEFT, 0);
            analogWrite(DRIVER_FORWARD_RIGHT, 0);
            analogWrite(DRIVER_BACKWARD_LEFT, 255);
            analogWrite(DRIVER_BACKWARD_RIGHT, 255);
        }

        void Motor::drift_left(){
            analogWrite(DRIVER_FORWARD_LEFT, 255);
            analogWrite(DRIVER_FORWARD_RIGHT, 0);
            analogWrite(DRIVER_BACKWARD_LEFT, 0);
            analogWrite(DRIVER_BACKWARD_RIGHT, 255);
        }

        void Motor::drift_right(){
            analogWrite(DRIVER_FORWARD_LEFT, 0);
            analogWrite(DRIVER_FORWARD_RIGHT, 255);
            analogWrite(DRIVER_BACKWARD_LEFT, 255);
            analogWrite(DRIVER_BACKWARD_RIGHT, 0);
        }

        void Motor::modulate(){
            // // compute modulation
            // if(power_left < 255 && power_left > -255){
            //     power_left += modulation_left;    
            // }

            // if(power_right < 255 && power_right > -255){
            //     power_right += modulation_right;    
            // }

            // analogWrite(DRIVER_FORWARD_LEFT,power_left);
            // analogWrite(DRIVER_FORWARD_RIGHT,power_right);
            // analogWrite(DRIVER_BACKWARD_LEFT,0);
            // analogWrite(DRIVER_BACKWARD_RIGHT,0);

            // modulate PWM
            // if(power_left == 0){
            //     analogWrite(DRIVER_FORWARD_LEFT, 0xFF);
            //     analogWrite(DRIVER_BACKWARD_LEFT, 0xFF);
            // }
            // else{
            //     if(power_left > 0 ){
            //         analogWrite(DRIVER_FORWARD_LEFT, power_left);
            //         analogWrite(DRIVER_BACKWARD_LEFT, 0);
            //     }
            //     else{
            //         analogWrite(DRIVER_FORWARD_LEFT, 0);
            //         analogWrite(DRIVER_BACKWARD_LEFT, -power_left);
            //     }
            // }

            // if(power_right == 0){
            //     analogWrite(DRIVER_FORWARD_RIGHT, 0xFF);
            //     analogWrite(DRIVER_BACKWARD_RIGHT, 0xFF);
            // }
            // else{

            //     if(power_right > 0 ){
            //         analogWrite(DRIVER_FORWARD_RIGHT, power_right);
            //         analogWrite(DRIVER_BACKWARD_RIGHT, 0);
            //     }
            //     else{
            //         analogWrite(DRIVER_FORWARD_RIGHT, 0);
            //         analogWrite(DRIVER_BACKWARD_RIGHT, -power_right);
            //     }
            // }
            
        }
};


#define MOTOR_H
#endif 