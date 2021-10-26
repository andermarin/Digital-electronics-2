# Lab 5: ANDER MARIN

Link to your `Digital-electronics-2` GitHub repository:

[https://github.com/andermarin/Digital-electronics-2](https://github.com/andermarin/Digital-electronics-2)


### 7-segment library

1. In your words, describe the difference between Common Cathode and Common Anode 7-segment display.
   * CC SSD: All LED cathodes are connected to the same ground, so activate the LEDS we have to apply high voltage,1, in the segment pin that we want. It is like active high.
   * CA SSD: All LED anodes are connected to the same supply voltage, so activate the LEDS we have to apply low voltage, 0, in the segment pin that we want to use. It is like active low.

2. Code listing with syntax highlighting of two interrupt service routines (`TIMER1_OVF_vect`, `TIMER0_OVF_vect`) from counter application with at least two digits, ie. values from 00 to 59:

```c
/**********************************************************************
 * Function: Timer/Counter1 overflow interrupt
 * Purpose:  Increment counter value from 00 to 59.
 **********************************************************************/
ISR(TIMER1_OVF_vect)
{
    // WRITE YOUR CODE HERE
    static uint8_t counter1 = 0; //The ones counter
    static uint8_t counter2 = 0; //The tens counter
    while (counter1 !== 9){
       counter1++;   
    }
    counter1 = 0;
    counter2++;
    if (counter2==6){
      counter2=0;
      counter1=0;
    }
}
```

```c
/**********************************************************************
 * Function: Timer/Counter0 overflow interrupt
 * Purpose:  Display tens and units of a counter at SSD.
 **********************************************************************/
ISR(TIMER0_OVF_vect)
{
    static uint8_t pos = 0;

    // WRITE YOUR CODE HERE
static uint8_t pos = 0;
   if(pos == 0){
      SEG_update_shift_regs(counter1,0);
   }
   pos++;
   if(pos){
      SEG_update_shift_regs(counter2,1);
   }
   pos = 0;
}
```

3. Flowchart figure for function `SEG_clk_2us()` which generates one clock period on `SEG_CLK` pin with a duration of 2&nbsp;us. The image can be drawn on a computer or by hand. Use clear descriptions of the individual steps of the algorithms.

   ![your figure](https://github.com/andermarin/Digital-electronics-2/blob/main/Labs/05-segments/Assigment_draw.JPG)


### Kitchen alarm

Consider a kitchen alarm with a 7-segment display, one LED and three push buttons: start, +1 minute, -1 minute. Use the +1/-1 minute buttons to increment/decrement the timer value. After pressing the Start button, the countdown starts. The countdown value is shown on the display in the form of mm.ss (minutes.seconds). At the end of the countdown, the LED will start blinking.

1. Scheme of kitchen alarm; do not forget the supply voltage. The image can be drawn on a computer or by hand. Always name all components and their values.

   ![your figure](https://github.com/andermarin/Digital-electronics-2/blob/main/Labs/05-segments/05-segment/Assigmentdesign.png)
