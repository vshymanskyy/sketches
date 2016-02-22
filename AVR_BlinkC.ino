/* blick-c.pde
 *
 * Blink in "pure" C, within the Arduino environment.
 *
 * Turns on an LED on for one second, then off for one second, repeatedly.
 *
 * One of a series of "Blink" examples using various techniques.
 *   This praticular example uses pure C code writing directly to the AVR PORTS,
 *   and none of the actual Arduino library functions, but it uses the millisecond
 *   timer maintained by the arduino runtime environment for the delay loop.
 *
 * The circuit:
 *     LED connected from digital pin 13 to ground, with suitable resistor.
 *
 *     Note: On most Arduino boards, there is already an LED on the board
 *     connected to pin 13, so you don't need any extra components for this example.
 *
 * Created Nov 2009, by Bill Westfield.
 *   Based on the blink.pde example distributer with the Arduino IDE,
 *      Created 1 June 2005 By David Cuartielles
 *        based on an orginal by H. Barragan for the Wiring i/o board
 */

#define LEDPORT PORTB    // Arduino pin 13 is bit 5 of port B
#define LEDPORT_DIR DDRB
#define LEDBIT 5

/*
 * timer0_millis is a variable maintained by the arduino environment.
 * it is incremented as appropriate inside a timer0 interrupt routine,
 * and must be declared "volatile" so that the compiler knows its value
 * can change even though we don't change it.
 */
extern volatile unsigned long timer0_millis;  // maintained by arduino environment

// The setup() method runs once, when the sketch starts

void setup()   {                
  // initialize the digital pin as an output:
  LEDPORT_DIR = _BV(LEDBIT);
}

// the loop() method runs over and over again,
// as long as the Arduino has power

void loop()                     
{
  unsigned long timeout;
  
  LEDPORT |= _BV(LEDBIT);         // on
  timeout = timer0_millis;        // "now"
  while (timer0_millis - timeout < 1000)  // wait till "now" is 1000 ms later.
    ; // spin for one second
    
  LEDPORT &= ~_BV(LEDBIT);       // off
  timeout = timer0_millis;
  while (timer0_millis - timeout < 1000)
    ; // spin for one second
}
