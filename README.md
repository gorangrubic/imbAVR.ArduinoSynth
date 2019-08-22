# imbAVR.ArduinoSynth

Project goal

   To build USB Midi, monophonic, Bass line synth based on Arduino Pro Micro board. 

Concept

   Waveforms are analog modulations of single digital frequency source (digital pin, Arduino tone() method) with pure square waveform.

# Key (hardware) components:
- Arduino Pro Micro
- Microchip MPC 410 10 CP digital potentiometers (10kOhm, 8bit / 256 values)
- UL741 operational amplifier
- Passive components

# Key (firmware) functions:
- MIDI controlled synth, visible as USB MIDI device
- CC values are controlling all variable aspects of synthesis
- Sound preset as 127 bytes for each CC value
- Internal ADSR curves for amplitude modulation and low-pass filter (on master output)

# Current architecture of the synth (breadboard model v2.0)
- Waveform A: low-passed sine-2-triangle integrator (sub and bass)
- - CC controls waveform shape (from square to sine)
- Waveform B: high-passed sharp saw ("perk")
- Waveform A/B mixer
- Master low-pass filter (cut-off), with CC controlled gain amplification (res)
- Amplitude modulation at output (ADSR)
