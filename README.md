# FancyWrite (Windows only)
Fancy Write gives you the option to write to **cout** with the windows predefined colors. 

## Usage

Include the 3 files (FancyWrite.h, FancyWrite.cpp, FancyColor.h) in your project and don't forget the `#include "FancyWrite.h"`!

## Features

### Change Color
Changes the color for upcoming console outputs. Example:

``` cpp
FancyWrite fancy{};
fancy.changeColor(FancyColor::LIGHTVIOLET);
cout << "I can write multiple lines " << flush;
cout << "and the color stays the same!" << endl;
cout << "Such neon. Much wow." << endl;
```
![exampleWrite](https://github.com/Rhatalin/FancyWrite/blob/master/ExampleImages/FancyWrite_ChangeColor_Example1.PNG)

### Write
Writes a string in color but resets the color to the previous.
Example:

``` cpp
FancyWrite fancy{};
fancy.write("Writing in green like a hacker in every 90's movie!", FancyColor::LIGHTGREEN);
```
![exampleWrite](https://github.com/Rhatalin/FancyWrite/blob/master/ExampleImages/FancyWrite_Write_Example1.PNG)

### Write Wrapped
Writes a string to the console but with a border around.

``` cpp
FancyWrite fancy{};
fancy.writeWrapped("I'm in a border!", '+', FancyColor::LIGHTRED, FancyColor::LIGHTYELLOW);
```
![exampleWrite](https://github.com/Rhatalin/FancyWrite/blob/master/ExampleImages/FancyWrite_WriteWrapped_Example1.PNG)

### Write Repeated
Writes a string to the console multiple times. Example:

``` cpp
FancyWrite fancy{};
fancy.writeRepeated("I like cyan!\n", 10, FancyColor::LIGHTCYAN);
```
![exampleWrite](https://github.com/Rhatalin/FancyWrite/blob/master/ExampleImages/FancyWrite_WriteRepeated_Example1.PNG)

## Contact

If you have any questions or comments let me know on github or on [twitter](https://twitter.com/Rhatalin)!
