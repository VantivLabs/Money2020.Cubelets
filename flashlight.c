#include "cubelet.h"
unsigned int last_flash_counter = 0;
void setup()
{
}
void loop()
{
    block_value = weighted_average();
    if (block_value != 0){ //no strobe should occur when block value is zero.
        if (last_flash_counter > 5+(255-block_value)) { //wait between 5 and 260 ~10ms intervals. Theoretically 20-0.4 flashes per second.
            last_flash_counter = 0;
            set_flashlight(255);
            wait(10); 
            set_flashlight(0);
        }
        else {
            last_flash_counter++;
            wait(10);
        }
    }
}
