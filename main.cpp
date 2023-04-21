#include <hFramework.h>
#include "Lego_Touch.h"

//#include "hCloudClient.h"
#include <stddef.h>
#include <stdio.h>


using namespace hFramework;

void hMain()
{
	hMot3.setEncoderPolarity(Polarity::Normal);  //changing encoder polarity (Polarity::Normal is default)
    hMot3.setMotorPolarity(Polarity::Reversed);  //changing motor polarity

	// hLegoSensor_simple ls1(hSens1);
	// hLegoSensor_simple ls2(hSens2);
	// Lego_Touch sensor1(ls1);
	// Lego_Touch sensor2(ls2);
	
	char c;
	bool motorOn = false;
	while (1)
    {  
        // if (Serial.available() > 0) { // checking Serial availability
        //     c = Serial.getch();
        //     if(c == 'a') {
        //         hMot3.rotRel(500, 200, false, INFINITE); //rotate by 500 ticks relatively to the current position, with 20% power
        //         hLED1.toggle();
        //     }
        //     if(c == 's') {
        //         hMot3.rotRel(-500, 200, true, INFINITE); //relative rotate 500 encoder ticks left with 20% of power with blocking task
        //         hLED1.toggle();
        //     }
        //     if(c == 'd') {
        //         hMot3.rotAbs(0, 200, true, INFINITE); //rotate to "0" ticks absolute position, and block program until task finishes
        //         hLED1.toggle();
        //     }
            
        // }
		// bool pressed1 = sensor1.isPressed();
		// bool pressed2 = sensor2.isPressed();

		bool state1 = hBtn1.isPressed();
		bool state2 = hBtn2.isPressed();

		hMot3.rotAbs(0, 300, false, INFINITE);
		if(state1){
			hMot3.rotRel(-90, 400, true, INFINITE);
		}
		if(state2){
			motorOn = !motorOn;
			sys.delay(200);
			
		}
		if(motorOn){
			hMot1.setPower(1000);
		}
	
		// hMot3.rotAbs(0, 100, true, INFINITE);
		// sys.delay(1000);
		// hMot3.rotRel(-90, 400, true, INFINITE);
		printf("test 111 %d\r\n", (int) sys.getRefTime());
		// sys.delay(200);
    }
}