# FancyWrite (Windows only)
Fancy Write gives you the option to write to **cout** with the windows predefined colors. 

## Usage

Include the 3 files (FancyWrite.h, FancyWrite.cpp, FancyColor.h) in your project and don't forget the `#include "FancyWrite.h"`!

## Features

### Change Color
Changes the color for upcoming console outputs.
Example:

``` cpp
FancyWrite fancy{};
fancy.changeColor(FancyColor::LIGHTRED);
cout << "This text is red" << endl;
```
Output: `This text is red` (in red, trust me).

### Write
Writes a string in color but resets the color to the previous.
Example:

``` cpp
FancyWrite fancy{};
fancy.write("Blue Text", FancyColor::LIGHTBLUE);
```
Output: `Blue Text` (in blue).

### Write Wrapped
Writes a string to the console but with a border around.

``` cpp
FancyWrite fancy{};
fancy.writeWrapped("I'm in a border!", '+', FancyColor::WHITE, FancyColor::GRAY);
```
Output:

``` cpp
+++++++++++++++++++
+ I'm in a border +
+++++++++++++++++++
```
(+ are white, text is gray).

### Write Repeated
Writes a string to the console multiple times. Example:

``` cpp
FancyWrite fancy{};
fancy.writeRepeated("-", 10, FancyColor::WHITE);
```
Output: `----------` (in white).

## Contact

If you have any questions or comments let me know on github or on [twitter](https://twitter.com/Rhatalin)!
