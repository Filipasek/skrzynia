#include <hFramework.h>
#include "Lego_Touch.h"

// #include "hCloudClient.h"
#include <stddef.h>
#include <stdio.h>

using namespace hFramework;

void hMain()
{

    hMot3.setEncoderPolarity(Polarity::Normal); // changing encoder polarity (Polarity::Normal is default)
    hMot3.setMotorPolarity(Polarity::Reversed); // changing motor polarity
    hMot1.setEncoderPolarity(Polarity::Normal); // changing encoder polarity (Polarity::Normal is default)
    hMot1.setMotorPolarity(Polarity::Reversed); // changing motor polarity
    hMot2.setEncoderPolarity(Polarity::Normal); // changing encoder polarity (Polarity::Normal is default)
    hMot2.setMotorPolarity(Polarity::Reversed); // changing motor polarity
    hMot4.setEncoderPolarity(Polarity::Normal); // changing encoder polarity (Polarity::Normal is default)
    hMot4.setMotorPolarity(Polarity::Reversed); // changing motor polarity

    // hLegoSensor_simple ls1(hSens1);
    // hLegoSensor_simple ls2(hSens2);
    // Lego_Touch sensor1(ls1);
    // Lego_Touch sensor2(ls2);

    int currentGear = 0;
    bool toBeChanged = false;
    while (1)
    {
        hMot1.rotAbs(0, 200, false, INFINITE);
        bool state1 = hBtn1.isPressed(); // gear up
        bool state2 = hBtn2.isPressed(); // gear down

        if (state1 && currentGear < 5)
        { // gear up if not at max gear (5)
            currentGear++;
            toBeChanged = true;
            sys.delay(300);
        }
        if (state2 && currentGear > -1)
        { // gear down if not at min gear (reverse)
            currentGear--;
            toBeChanged = true;
            sys.delay(300);
        }
        if (toBeChanged)
        {
            switch (currentGear)
            {
            case 0:
                printf("Gear 0\n");
                hMot1.rotRel(-85, 800, false, INFINITE); // clutch engaged
                sys.delay(100);

                hMot2.rotAbs(0, 250, false, INFINITE); // starting position, neutral
                hMot3.rotAbs(0, 250, false, INFINITE); // starting position, neutral
                hMot4.rotAbs(0, 250, false, INFINITE); // starting position, neutral

                sys.delay(1000);
                hMot1.rotAbs(0, 200, false, INFINITE); // clutch disengaged
                toBeChanged = false;
                break;
            case 1:
                printf("Gear 1\n");
                hMot1.rotRel(-85, 800, false, INFINITE); // clutch engaged
                sys.delay(100);

                hMot2.rotAbs(0, 250, false, INFINITE);   // starting position, neutral
                hMot2.rotRel(-60, 250, false, INFINITE); // starting position, neutral
                hMot3.rotAbs(0, 250, false, INFINITE);   // starting position, neutral
                hMot4.rotAbs(0, 250, false, INFINITE);   // starting position, neutral

                sys.delay(1000);
                hMot1.rotAbs(0, 200, false, INFINITE); // clutch disengaged
                toBeChanged = false;
                break;
            case 2:
                printf("Gear 2\n");
                hMot1.rotRel(-85, 800, false, INFINITE); // clutch engaged
                sys.delay(100);

                hMot2.rotAbs(0, 250, false, INFINITE);  // starting position, neutral
                hMot2.rotRel(60, 250, false, INFINITE); // starting position, neutral
                hMot3.rotAbs(0, 250, false, INFINITE);  // starting position, neutral
                hMot4.rotAbs(0, 250, false, INFINITE);  // starting position, neutral

                sys.delay(1000);
                hMot1.rotAbs(0, 200, false, INFINITE); // clutch disengaged
                toBeChanged = false;
                break;
            case 3:
                printf("Gear 3\n");
                hMot1.rotRel(-85, 800, false, INFINITE); // clutch engaged
                sys.delay(100);

                hMot2.rotAbs(0, 250, false, INFINITE);   // starting position, neutral
                hMot3.rotAbs(0, 250, false, INFINITE);   // starting position, neutral
                hMot3.rotRel(-60, 250, false, INFINITE); // starting position, neutral
                hMot4.rotAbs(0, 250, false, INFINITE);   // starting position, neutral

                sys.delay(1000);
                hMot1.rotAbs(0, 200, false, INFINITE); // clutch disengaged
                toBeChanged = false;
                break;
            case 4:
                printf("Gear 4\n");
                hMot1.rotRel(-85, 800, false, INFINITE); // clutch engaged
                sys.delay(100);

                hMot2.rotAbs(0, 250, false, INFINITE);  // starting position, neutral
                hMot3.rotAbs(0, 250, false, INFINITE);  // starting position, neutral
                hMot3.rotRel(60, 250, false, INFINITE); // starting position, neutral
                hMot4.rotAbs(0, 250, false, INFINITE);  // starting position, neutral

                sys.delay(1000);
                hMot1.rotAbs(0, 200, false, INFINITE); // clutch disengaged
                toBeChanged = false;
                break;
            case 5:
                printf("Gear 5\n");
                hMot1.rotRel(-85, 800, false, INFINITE); // clutch engaged
                sys.delay(100);

                hMot2.rotAbs(0, 250, false, INFINITE);  // starting position, neutral
                hMot3.rotAbs(0, 250, false, INFINITE);  // starting position, neutral
                hMot4.rotAbs(0, 250, false, INFINITE);  // starting position, neutral
                hMot4.rotRel(60, 250, false, INFINITE); // starting position, neutral

                sys.delay(1000);
                hMot1.rotAbs(0, 200, false, INFINITE); // clutch disengaged
                toBeChanged = false;
                break;
            case -1:
                printf("Reverse\n");
                hMot1.rotRel(-85, 800, false, INFINITE); // clutch engaged
                sys.delay(100);

                hMot2.rotAbs(0, 250, false, INFINITE);   // starting position, neutral
                hMot3.rotAbs(0, 250, false, INFINITE);   // starting position, neutral
                hMot4.rotAbs(0, 250, false, INFINITE);   // starting position, neutral
                hMot4.rotRel(-60, 250, false, INFINITE); // starting position, neutral

                sys.delay(1000);
                hMot1.rotAbs(0, 200, false, INFINITE); // clutch disengaged
                toBeChanged = false;
                break;
            }
        }
        // hMot3.rotAbs(0, 250, false, INFINITE);
        // sys.delay(1000);
        // hMot3.rotRel(-90, 400, false, INFINITE);
        printf("test control systems %d\r\n", (int)sys.getRefTime());
    }
}