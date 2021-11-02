# Lab 6: ANDER MARIN

Link to your `Digital-electronics-2` GitHub repository:

[https://github.com/andermarin/Digital-electronics-2](https://github.com/andermarin/Digital-electronics-2)


### LCD display module

1. In your words, describe what ASCII table is.
   * ASCII: Is a table that contains characters, numbers... with their 7-bit code. It is used to represent those characters in binary, hexa and so on.

2. (Hand-drawn) picture of time signals between ATmega328P and LCD keypad shield (HD44780 driver) when transmitting three character data `De2`.

   ![your figure](https://github.com/andermarin/Digital-electronics-2/blob/main/Labs/06-lcd/TIME.jpeg)


### Stopwatch

1. Flowchart figure for `TIMER2_OVF_vect` interrupt service routine which overflows every 16&nbsp;ms but it updates the stopwatch LCD approximately every 100&nbsp;ms (6 x 16&nbsp;ms = 100&nbsp;ms). Display tenths of a second and seconds `00:seconds.tenths`. Let the stopwatch counts from `00:00.0` to `00:59.9` and then starts again. The image can be drawn on a computer or by hand. Use clear descriptions of the individual steps of the algorithms.

   ![your figure](https://github.com/andermarin/Digital-electronics-2/blob/main/Labs/06-lcd/Captura.JPG)


### Custom characters

1. Code listing with syntax highlighting of two custom character definition:

```c
/* Variables ---------------------------------------------------------*/
// Custom character definition
uint8_t customChar1[16] = {
    // WRITE YOUR CODE HERE
    0b00111,
    0b01110,
    0b11100,
    0b11111,
    0b11100,
    0b01110,
    0b00111,
    0b00011
};
uint8_t customChar2[16] = {
    // WRITE YOUR CODE HERE
    0b11100,
    0b11111,
    0b11100,
    0b11100,
    0b11100,
    0b11100,
    0b11111,
    0b11100
};
```


### Kitchen alarm

Consider a kitchen alarm with an LCD, one LED and three push buttons: start, +1 minute, -1 minute. Use the +1/-1 minute buttons to increment/decrement the timer value. After pressing the Start button, the countdown starts. The countdown value is shown on the display in the form of mm.ss (minutes.seconds). At the end of the countdown, the LED will start blinking.

1. Scheme of kitchen alarm; do not forget the supply voltage. The image can be drawn on a computer or by hand. Always name all components and their values.

   ![your figure](https://github.com/andermarin/Digital-electronics-2/blob/main/Labs/06-lcd/CIRCUIT%20DRAWING.png)
