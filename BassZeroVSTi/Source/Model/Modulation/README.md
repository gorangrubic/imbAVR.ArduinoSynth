# Modulation Functions

Time periods for LFO, CHAOS and ENV functions  are multiplied with Time Factor parameter, allowing
slow changes / low modulation frequencies.

ADSR functions start with the Initial value. At end of the attack period value reaches the maximum.
Afterwards, the value decays to Sustain value and waits for Note Off MIDI event to fall (release) to zero.

LFO functions are oscilating from zero to Value and back to zero, in each cycle (Time x Time Factor).
CHAOS function moves from Last Target Value to Current Target Value, where New Target Value
is set to random value between 0 and Spread, after each cycle (Time x Time Factor).

ENV functions are two-point interpolated loops. Cycle starts with Level B, moves to Level A in period
defined by Time A and moves back to Level B in period defined by Time B. 

The functions are computed at hardware level, using linear interpolation and addaptable time resolution
(i.e. result at given moment is computed using RTC measurement in ms / computation loop has 
no predefined delay). Output values are in CC MIDI value constrain (0-127). 

# Modulated Synth Parameters

Main rotary slider controls 
unmodulated value, set by:
a) Manual user GUI / mouse action
b) MIDI CC input messages
c) DAW automation

Side slider (linear or rotary) controls
amount of modulation, i.e. how strongly
the modulation source (function) affects the
final output of the parameter. 

Combo menu (below the sliders) value sets what
modulation source (function) is used, or 
if modulation is disabled (when OFF).