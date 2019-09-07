# imbAVR.LCDOnMega

Graphics library for 2.4'' LCD touch screen display module on Arduino MEGA 2540

# Data-representation oriented GUI framework for Arduino

Application GUI is declared trough GuiScreenViewSet that stores all GuiScreenView(s) and manages what is currently shown on the display. 
Building blocks of GuiScreenView(s) are Rows. While Rows are constructed from Labels and Fields. Labels are designed to render static information (text) - therefore to change their content you have to set new value to the **label** parameter manually - while Fields use pointers to automatically reflect changes in properties of your data structures. 

# Type of Fields
To work with different data types, apropriate Field classes are used:
- LCDByteField
- LCDInt16Field
- LCDFloatField
- LCDTextField

The most important property of the base class (LCDField) is How the value is graphically represented



es  are 
Rows contain Labels and Fields. 

is The GUI is "row" oriented

Main parts of the framework:
- Application level screen/forms classes:  GuiScreen, GuiScreenView and GuiScreenViewSet
- Rows (Base abstract class: RowBase)
- Fields (Base abstract class: LCDField)
