# Lab 7: ANDER MARIN

Link to this file in your GitHub repository:

[https://github.com/andermarin/Digital-electronics-2](https://github.com/andermarin/Digital-electronics-2)


### Analog-to-Digital Conversion

1. Complete table with voltage divider, calculated, and measured ADC values for all five push buttons.

   | **Push button** | **PC0[A0] voltage** | **ADC value (calculated)** | **ADC value (measured)** |
   | :-: | :-: | :-: | :-: |
   | Right  | 0&nbsp;V | 0   | 0 |
   | Up     | 0.495&nbsp;V | 101 | 102 |
   | Down   |  0.784&nbsp;V     |  160   | 256 |
   | Left   |    1.01&nbsp;V   |   207  | 409 |
   | Select |   2&nbsp;V    |   409  | 639 |
   | none   |   5&nbsp;V    |   1023  | 1023 |

2. Code listing of ACD interrupt service routine for sending data to the LCD/UART and identification of the pressed button. Always use syntax highlighting and meaningful comments:

```c
/**********************************************************************
 * Function: ADC complete interrupt
 * Purpose:  Display value on LCD and send it to UART.
 **********************************************************************/
ISR(ADC_vect)
{
    uint16_t value = 0;
	char lcd_string[4] = "0000";

	value = ADC;                  // Copy ADC result to 16-bit variable
	
	//Clear previous value
	lcd_gotoxy(8,0);
	lcd_puts("    ");
	lcd_gotoxy(8,1);
	lcd_puts("                ");
	//Put the value
	itoa(value, lcd_string, 10);  // Convert decimal value to string
	lcd_gotoxy(8,0);
	lcd_puts(lcd_string);
	//Send the same value to UART
	uart_puts(lcd_string);
	uart_puts("   ");
	
	//HEXA
	
	//WHAT BUTTON IS PRESSED
	if(value=1023){
			lcd_gotoxy(8,1);
			lcd_puts("                ");
		lcd_gotoxy(8,1);
		lcd_puts("none");
		uart_puts("none");
	}if(value=639){
			lcd_gotoxy(8,1);
			lcd_puts("                ");
		lcd_gotoxy(8,1);
		lcd_puts("select");
		uart_puts("select");
	}if(value=409){
			lcd_gotoxy(8,1);
			lcd_puts("                ");
		lcd_gotoxy(8,1);
		lcd_puts("left");
		uart_puts("left");
	}if(value=256){
			lcd_gotoxy(8,1);
			lcd_puts("                ");
		lcd_gotoxy(8,1);
		lcd_puts("down");
		uart_puts("down");
	}if(value=102){
			lcd_gotoxy(8,1);
			lcd_puts("                ");
		lcd_gotoxy(8,1);
		lcd_puts("up");
		uart_puts("up");
	}else{
		lcd_gotoxy(8,1);
		lcd_puts("                ");
		lcd_gotoxy(8,1);
		lcd_puts("right");
		uart_puts("right");
	}


}
```


### UART communication

1. (Hand-drawn) picture of UART signal when transmitting three character data `De2` in 4800 7O2 mode (7 data bits, odd parity, 2 stop bits, 4800&nbsp;Bd).

   ![your figure](https://github.com/andermarin/Digital-electronics-2/blob/main/Labs/07-uart/WhatsApp%20Image%202021-11-09%20at%2010.53.47.jpeg)

2. Flowchart figure for function `get_parity(uint8_t data, uint8_t type)` which calculates a parity bit of input 8-bit `data` according to parameter `type`. The image can be drawn on a computer or by hand. Use clear descriptions of the individual steps of the algorithms.

   ![your figure](https://github.com/andermarin/Digital-electronics-2/blob/main/Labs/07-uart/Captura.JPG)


### Temperature meter

Consider an application for temperature measurement and display. Use temperature sensor [TC1046](http://ww1.microchip.com/downloads/en/DeviceDoc/21496C.pdf), LCD, one LED and a push button. After pressing the button, the temperature is measured, its value is displayed on the LCD and data is sent to the UART. When the temperature is too high, the LED will start blinking.

1. Scheme of temperature meter. The image can be drawn on a computer or by hand. Always name all components and their values.

   ![your figure]()
