# ventanimation.h

`ventanimation.h` is a header file that provides a collection of functions for manipulating the console in C++. The functions include creating text animations, drawing boxes, changing the console size, changing the console title, and more.

## Getting Started

To use the functions in your project, include the `ventanimation.h` header file in your source code.

```cpp
#include "ventanimation.h"

Functions
void PosXY(int x, int y): Positions the cursor at the specified coordinates (x, y).
void ConsoleSize(int width, int height): Changes the console size to the specified width and height.
void ConsoleDLT(): Clears the entire console.
void ConsoleTitle(const char* title): Changes the console title to the specified string.
void ConsoleCursorSHOW_HIDE(bool show): Shows or hides the cursor based on the boolean value (true for show, false for hide).
void ConsoleClsX_Y(int x, int y, int length): Clears a specific part of the console starting from coordinates (x, y) with the specified length.
void TextAnimation(const char* text, int speed): Displays the specified text with animation at the current cursor position. The speed parameter determines the animation speed.
void BoxAnimation(int type, int width = 0, int height = 0): Draws a box with animation based on the specified type. The width and height parameters are optional and only used for box types 2 and 3.


Example Usage
#include <iostream>
#include "ventanimation.h"

int main() {
    PosXY(10, 5);
    std::cout << "Hello, World!";

    ConsoleSize(80, 25);
    ConsoleTitle("My Awesome Console");

    ConsoleCursorSHOW_HIDE(false);

    ConsoleClsX_Y(0, 10, 20);
    TextAnimation("This is a text animation!", 50);

    BoxAnimation(1, 40, 10);
    BoxAnimation(2, 30);
    BoxAnimation(3, 20);

    return 0;
}

Contributing
Contributions are welcome! If you find any bugs or have suggestions for improvements, please feel free to open an issue or submit a pull request.