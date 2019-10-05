# Library with several utility classes used in my imbAVE.BassZero project

The most relevant classes in the library:

## digPotCluster
Controls 8 digpots (MPC410-10) using shift register (74CH595N). 
Purpose of shift register is to reduce number of pins used for CS (chip selection):

		Normally, you would use 2 (SCLK, MOSI) + 8 (CS for each MPC410-10) = 10 pins
		Like this, you use to 2 (SCLK, MOSI) + 3 (Latch clock, clock, data) = 5 pins


## volCluster
Controls 3 stereo electronic-volume chips (FM62429) using digital 4 pins in total.

## ADSR
Resource effitient class for Attack-Decay-Sustain-Release ENV function computation.


# Notes on the synth control operation

## Prefixes at **MidiConfig.h** 

### SynthState computation variables 

#### CS - Control Synth
Identifiers for synth control variables (State.CSValues array) that are applied to external hardware components (SignalGenerator MCU, digital potentiometers, electronic volume control chips). These values are product of MidiSoundControl.DoTick() method and internal control functions.


#### MDF - Modification Functions
Identifiers for computed values (State.MDFValues array) of time-based control functions, like: ADSR, LFO, ENV, Chaos. 
	
#### CC - Control Channel
MIDI CC channels interpreted by the synth i.e. used in CS computations

### Signal Generator 

#### SID - Signal ID
Identifiers of SignalControlUnits (i.e. waveform sources, oscilators) at SignalGenerator

#### CID - Control ID



# Operation modes

Operation modes (OPMs) are hardware level presets controling synthesis and modulation aspects that are not directly controllable from VSTi nor MIDI CC messages. OP MODs and VARs have different role in different OPMs. 


