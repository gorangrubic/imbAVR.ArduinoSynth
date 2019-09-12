# imbAVR.ArduinoSynth

Project goal

      To build USB Midi, monophonic, Bass line synth based on Arduino Pro Micro board. 

Concept

      Waveforms are analog modulations of single digital frequency source (digital pin, Arduino tone() method) with pure square waveform.

## Key (hardware) components:
- Arduino Pro Micro
- Microchip MPC 410 10 CP digital potentiometers (10kOhm, 8bit / 256 values)
- UL741 operational amplifier
- Passive components

## Key (firmware) functions:
- MIDI controlled synth, visible as USB MIDI device
- CC values are controlling all variable aspects of synthesis
- Sound preset as 127 bytes for each CC value
- Internal ADSR curves for amplitude modulation and low-pass filter (on master output)

## Current architecture of the synth (breadboard model v2.0)
- Waveform A: low-passed sine-2-triangle integrator (sub and bass)
- - CC controls waveform shape (from square to sine)
- Waveform B: high-passed sharp saw ("perk")
- Waveform A/B mixer
- Master low-pass filter (cut-off), with CC controlled gain amplification (res)
- Amplitude modulation at output (ADSR)



# Sub-projects of general relevance
Development of the synth required number of classes/libraries, having general relevance for Arduino/MCU projects. Here I'll drop some highlights:

- imbAVR.LCDOnMega 
      
Elementary data-representation GUI framework, embedded with lower-level drivers to run 4'' LCD touchscreen panel on Arduino MEGA 2569.

- imbAVR.StructTransferSPI

Lightweight library for sending structured data (structs) to another Arduino using SPI protocol. 

- imbAVR.DedicatedSignalGeneratorLibrary

Turns Arduino Nano, Mini, Micro.. into square-pulse audio-signal generator, with up to 12 separate outputs - each having its PWM, pitch, phase shifts and automation. Arduino that is turned into dedicated signal generator is controled by another Arduno via (software)serial  and powerful signal control instruction protocol. 
