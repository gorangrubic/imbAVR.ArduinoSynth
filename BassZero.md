# hardy.Veles' BassZero 
- MIDI controlled, hardware bass synth module

Development consists of:
- synth hardware 
-- breadboard hardware model
-- design of logical electronic schematics
-- PCB design and PCB production CNC files
- synth firmware
-- signal generator firmware
-- synth controler firmware
- synth software
-- synth control software (VSTi plugin)
-- USB midi device drivers for Windows

## Features

### Oscilators
- Waveform A
- Waveform B
- Filter resonant waveform
- Perk A
- Perk B

All 5 are generated digitally, having pulse as initial waveform.
- Waveform A and B are separatly modulated, by analog circuits, from pulse to saw, triangle, sinewave... and complex shapes. After modulations, these two are mixed together into single waveform, referred futher as: the Main Component. 
- Perk A and B are "helping" oscilators with pulse waveform, meant for specific special effects like fast pitch shifts (e.g. high pitch starting punch point in kick drum)
- Filter resontant waveform plays role in main LP filter effect.

### Logical blocks
- Synth control MCU (Arduino Pro Micro)
- Signal generator MCU (Arduino Nano/Pro Mini)
- Waveform shaper
- Distortion block
- Main LP resonant filter
- AMP and PAN modulation block