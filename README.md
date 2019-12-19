# Fancy Write
Fancy Write gives you the option to write to [Standard Output Stream](http://www.cplusplus.com/doc/tutorial/basic_io/) with the Windows predefined colors. **It only works on Windows!**

## Usage

Include [FancyWrite.h](https://github.com/Rhatalin/FancyWrite/blob/master/FancyWrite/FancyWrite/FancyWrite.h) in your project.
Fancy Write uses the namespace `Fancy`, so you could use `using namespace Fancy;`.
Get the FancyWrite instance by the following:
```cpp
FancyWrite& fancy{ FancyWrite::getInstance() };
```

## Features

### Change Color
Changes the color for upcoming console outputs.
Example:

``` cpp
fancy.changeColor(FancyColor::LIGHTVIOLET);
cout << "I can write multiple lines " << flush;
cout << "and the color stays the same!" << endl;
cout << "Such neon. Much wow." << endl;
```
![exampleWrite](https://github.com/Rhatalin/FancyWrite/blob/master/ExampleImages/FancyWrite_ChangeColor_Example1.PNG)

### Write
Writes a string in color but resets the color afterwards.
Example:

``` cpp
fancy.write("Writing in green like a hacker in every 90's movie!", FancyColor::LIGHTGREEN);
```
![exampleWrite](https://github.com/Rhatalin/FancyWrite/blob/master/ExampleImages/FancyWrite_Write_Example1.PNG)

### Write Wrapped
Writes a string to the console but with a border around.
Example:

``` cpp
fancy.writeWrapped("I'm in a border!", '+', FancyColor::LIGHTRED, FancyColor::LIGHTYELLOW);
```
![exampleWrite](https://github.com/Rhatalin/FancyWrite/blob/master/ExampleImages/FancyWrite_WriteWrapped_Example1.PNG)

### Write Repeated
Writes a string to the console multiple times.
Example:

``` cpp
fancy.writeRepeated("I like cyan!\n", 10, FancyColor::LIGHTCYAN);
```
![exampleWrite](https://github.com/Rhatalin/FancyWrite/blob/master/ExampleImages/FancyWrite_WriteRepeated_Example1.PNG)

## Contact

If you have any questions or comments let me know on github or on [twitter](https://twitter.com/Rhatalin)!
