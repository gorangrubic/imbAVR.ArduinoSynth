# hardy.Veles::BassZero VSTi 

The VSTi is DAW compatibile user interface, for controlling the BassZero synth hardware.


## Content of this directory

In the root directory are BassZero application classes. The subdirectories contain set of classes that can be used for other similar projects.

Subdirectories are libraries with general purpose classes. Except [Application] library, containing classes for synth control VSTi applications


- All synth control applications are in Application directory


### Data

Data structures (containers/collections), filesystem saving/loading, tree graph data modeling, GUI data binding and text generation.

Data structures describing synth state, configuration, presets and preset libraries. Everyrthing that is loaded and saved to user filesystem.


### Model 

Library for synth modelling, implementing [Data] tree graph structures. Describes synth with: oscilators, modulated parameters, modulation sources...
[Communications] subdirectory has classes for synth parameters conversion into MIDI messages and other data structures.

Classes providing object models for abstract description of synth structure, with emphasis on VST plugin parameters and MIDI communication.


### Utility

General tools



### GUI

Graphic User Interface blocks. 
