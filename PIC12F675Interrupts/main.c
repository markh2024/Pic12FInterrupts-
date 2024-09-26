// Function prototypes
void debounce(void);

/*
 * File:   main.c
 * Author: mark david harrington  london kent da6 8np
 * Created on 09 March 2026, 22:44
 */


// My C code for doing this 
#include <xc.h>

// PIC12F675 Configuration Bit Settings
#pragma config FOSC = INTRCIO    // Internal RC oscillator, GPIO on GP4 and GP5
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-Up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = OFF      // GP3/MCLR pin function select
#pragma config BOREN = OFF      // Brown-out Detect Enable bit
#pragma config CP = OFF         // Code Protection bit (Program Memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)

#define _XTAL_FREQ 4000000      // Define clock frequency as 4 MHz
#define BUTTON GPIObits.GP5     // Define button input pin on GP5

                            // gp0 |gp1|gp2 |gp4 ;
unsigned char  arraybits[4]= {0x01,0x02,0x04,0x10} ; 
unsigned char m_counter = 1  ;
// Interrupt Service Routine
void __interrupt() myISR(void)
{
    
    // reset m_counter 
    if (m_counter == 5){
        m_counter = 1 ;
    }
    // Handle GPIO interrupt-on-change (GP5)
    if (GPIF && (BUTTON == 0))  // Check if GP5 interrupt occurred and button pressed
    {
        
        
        switch (m_counter)
        {
            case 1:            // Toggle LED on GP0
                GPIO= arraybits[0] ;
                break ;
            case 2:
                
                GPIO = arraybits[1];
                break ;
            case 3:
                 GPIO = arraybits[2];;
                break ; 
            case 4: 
                 GPIO= arraybits[3] ;
              
           
                
        
        }            
        
        m_counter +=1 ; // increment counter by 1 
    }
    GPIF = 0;  // Clear the GPIO interrupt flag
    
}

// Function to handle switch debouncing if required
void debounce(void)
{
    __delay_ms(50);             // Simple debounce delay (50 ms)
    while (BUTTON == 0);        // Wait until the button is released
}

// Initialize GPIO and peripherals
void InitCCT(void)
{
    ANSEL  = 0x00;              // Set all ports as digital I/O
    ADCON0 = 0x00;              // Shut off the A/D Converter
    CMCON  = 0x07;              // Shut off the Comparator
    VRCON  = 0x00;              // Shut off the Voltage Reference
    TRISIO = 0b00100000;        // Set GP5 as input, all others (GP0) as output
    OPTION_REG = 0b00001111;    // Enable weak pull-ups globally
    IOC = 0b00100000;           // Enable interrupt-on-change for GP5
    GPIO = 0x00;                // Initialize all GPIOs to 0
    WPU |= (1 << 5);            // Enable weak pull-up on GP5
    
}

void main(void)
{
    InitCCT();                  // Initialize I/O and peripherals

    // Enable global interrupts and GPIO interrupt-on-change
    INTCON = 0b10100000;        // GIE (Global Interrupt Enable) + GPIF (Interrupt-on-change)
    GPIF = 0;                   // Clear GP5 interrupt-on-change flag

    while (1)
    {
        // Main loop: additional code can be added here if needed
    }

    return;
}
