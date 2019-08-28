# Library with several utility classes used in my imbAVE.BassZero project

The most relevant classes in the library:

## digPotCluster
Controls 8 digpots (MPC410-10) using shift register (74CH595N). 
Purpose of shift register is to reduce number of pins used for CS (chip selection):

		Normally, you would use 2 (SCLK, MOSI) + 8 (CS for each MPC410-10) = 10 pins
		Like this, you use to 2 (SCLK, MOSI) + 3 (Latch clock, clock, data) = 5 pins

## ADSR
Resource effitient class for Attack-Decay-Sustain-Release ENV function computation.


## MathTool
Computation functions used for ADSR and other ENV functions