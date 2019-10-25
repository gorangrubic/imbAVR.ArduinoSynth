# Introduction

*hardy.Veles BassZero* is hardware synthisizer, designed primarly for bass line synthesis. Using analog modulation circuits it provides resonant rich and analogly-smooth sound. 

## BassZero architecture

### BassZero VSTi

*BassZero VSTi* provides a DAW with complete control over *BassZero*.

### Components

The synth combines 5 oscilators:
- WF A
- WF B
- PERK A
- PERK B
- FLT

Oscilators can operate in:
- Pulse-Width Modulation mode
- Waveform pattern mode

### Signal flow

After waveform modulation and pre-amplification, WF A and WF B signals are mixed into single, mono, output (WF). 
The WF signal goes trough VCO resonant low-pass filter, modulated by FLT signal. From filter output, WF is equally sent to L and R channel, thus effectivly being mono.
After waveform modulation, PERK A and PERK B are distributed to L and R output bus.
Before the final re-amplification of L and R busses, both are AMP modulated for stereo panning of the final sound. 

#### Waveform oscilators

The waveform oscilators are responsible for the main sound component. WF A and WF B are combined into single waveform and further provided as mono.
Features:
- active low-pass filter used for waveform modulation
- gain / distortion 
- combined into mono signal

#### Perk oscilators

The Perk oscilators are high-passed, with independent stereo pan control.
Features:
- active high-pass filter
- separate stereo panning






### BassZero VSTi

### 