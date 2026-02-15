#include"types.h"

/*---------------- MICROSECOND DELAY ----------------*/

void delay_us(u32 tdly)
{
   tdly *= 12;        // Multiply by 12 (approx cycles needed for 1µs delay)
                      // Based on processor clock frequency assumption

   while(tdly--);     // Simple loop to create delay
}

/*---------------- MILLISECOND DELAY ----------------*/

void delay_ms(u32 tdly)
{
    tdly *= 12000;    // Multiply for 1 millisecond delay
                      // 1000 µs × 12 cycles = 12000 loop counts

    while(tdly--);    // Loop until counter becomes zero
}

/*---------------- SECOND DELAY ----------------*/

void delay_s(u32 tdly)
{
    tdly *= 12000000; // Multiply for 1 second delay
                      // 1,000,000 µs × 12 cycles = 12,000,000 loop counts

    while(tdly--);    // Wait until delay completes
}
