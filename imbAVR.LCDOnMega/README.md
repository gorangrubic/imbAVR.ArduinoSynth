# imbAVR.LCDOnMega

Graphics library for 2.4'' LCD touch screen display module on Arduino MEGA 2540

# Data-representation oriented GUI framework for Arduino

Main parts of the framework:
- Application level screen/forms classes:  GuiScreen, GuiScreenView and GuiScreenViewSet
- Rows (Base abstract class: RowBase)
- Fields (Base abstract class: LCDField)

Application GUI is declared trough GuiScreenViewSet that stores all GuiScreenView(s) and manages what is currently shown on the display. 
Building blocks of GuiScreenView(s) are **Rows**, that are constructed from **Labels** and **Fields**. Existing range of different Row classes provides common layout blocks, while graphical or textual representation of data is adjustable at **Field**s level.Labels are designed to render static information (text) - therefore, to change their content you would have to manually assign new value to the LCDLabel.**label** property. On the other hand, **Fields** are automatically updated via pointer. 

# Type of Fields
To work with different data types, apropriate Field classes are used:
- LCDByteField
- LCDInt16Field
- LCDFloatField
- LCDTextField

# Field rendering modes
Field value rendering is controlled by FieldValueRenderMode enumeration and LCDField.renderMode property. Currently implemented modes:
- Numeric
  numeric_value
  Simply renders the value
  
- numeric_ratio 
  Decimal number from 0 to 1, computed as ratio of data value and type value range. i.e. for **byte** variable: v / 255).
  
- numeric_percentage
  Ratio, multiplied by 100 and followed by % symbol

- Graphic

  	- graphic_horizontal_bar
  
  	- graphic_vertical_bar
  
	- graphic_horizontal_biased_bar
  
	- graphic_vertical_biased_bar
	
  	- graphic_resized_box,
	
  	- graphic_resized_circle,
	
  	- graphic_bitBoxArray
  	Renders 8 (or 2 x 8 in parallel) array of squares, representing bit states in byte or int16 values
  
	- graphic_bitBoxArrayLow4
	
	- graphic_bitBoxArrayHigh4
	
  	- graphic_boolean_box
  
	- graphic_boolean_circle
	
	
# Rendering mechanism

Main parts of the framework:
- Application level screen/forms classes:  GuiScreen, GuiScreenView and GuiScreenViewSet
- Rows (Base abstract class: RowBase)
- Fields (Base abstract class: LCDField)



