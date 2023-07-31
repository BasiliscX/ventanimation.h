#pragma once
/*
  File: ventanimation.h
  Author: Guillermo Navarro
  Date: 30/07/2023
  Description:

    This software provides a collection of console manipulation and animation functions in C++
    that allows users to perform various tasks, such as changing the cursor position, modifying the console size,
    displaying text with animation, drawing boxes with animation, and more.
    The functions facilitate interactive and visually appealing console-based applications.

    The software is distributed under the MIT Zero-Clause License,
    granting users the freedom to use, modify, and distribute the code freely.
*/
/// Position (X - Y):
void PosXY(int,int); // Change the cursor's position.
int  PosX();         // Return position X.
int  PosY();         // Return position Y.
void Pos_X_Y_INFO(); // Prints the current X - Y position on the screen.
/// Console tools:
int  ConsoleColumns();            // Return the amount of columns.
int  ConsoleRows();               // Return the amount of rows.
void ConsoleSize(int,int);        // Change the console size.
void ConsoleTitle(const char*);   // Change the console title.
void ConsoleCursorSHOW_HIDE(bool);// Show/hide cursor.
void ConsoleClsX_Y(int,int,int);  // Clear console(specific row/position).
void ConsoleDLT();                // Clear all.
/// Animation functions:
void TextAnimation(const char*,int);   // Text with animation.
void BoxAnimation(int,int,int,int);    // Draw a box with animation.
void Pause(int);                       // Slow down the screen printing.
void BackgroundAndTextColor(const int);// Set another color to the text with an underline.

#ifdef _WIN32 // Comprobación para Windows
#include<iostream>
#include<ctime>
#include<windows.h>

/**
 * Description:
 * Set a new cursor position based on the X-Y coordinates.
 * @param x = Receive the new column position.
 * @param y = Receive the new row position.
 */void PosXY(int x, int y){
    HANDLE hConsole=GetStdHandle(STD_OUTPUT_HANDLE);
    COORD newPosition;
    newPosition.X=x;
    newPosition.Y=y;
    SetConsoleCursorPosition(hConsole, newPosition);
}
/**
 * Description:
 * Return the current position X.
 */int PosX(){
    HANDLE hConsole=GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    if (GetConsoleScreenBufferInfo(hConsole, &consoleInfo)){
        int x=consoleInfo.dwCursorPosition.X;
        return x;
    }
    else return 0;
}
/**
 * Description:
 * Return the current position Y.
 */int PosY(){
    HANDLE hConsole=GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    if (GetConsoleScreenBufferInfo(hConsole, &consoleInfo)){
        int y=consoleInfo.dwCursorPosition.Y;
        return y;
    }
    else return 0;
}
/**
 * Description:
 * Prints the current X - Y position on the screen.
 */void Pos_X_Y_INFO(){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);

    COORD posicionCursor = consoleInfo.dwCursorPosition;
    std::cout << "X: " << posicionCursor.X << " - Y: " << posicionCursor.Y << std::endl;
}
/**
 * Description:
 * Return the amount of columns.
 */int ConsoleColumns(){
    HANDLE hConsole=GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    if(GetConsoleScreenBufferInfo(hConsole, &consoleInfo)){
        int columns=consoleInfo.srWindow.Right-consoleInfo.srWindow.Left+1;
        return columns;
        }
        else return 0;
}
/**
 * Description:
 * Return the amount of rows.
 */int ConsoleRows(){
    HANDLE hConsole=GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    if(GetConsoleScreenBufferInfo(hConsole, &consoleInfo)){
        int rows=consoleInfo.srWindow.Bottom-consoleInfo.srWindow.Top+1;
        return rows;
        }
        else return 0;
}
/**
 * Description:
 * Change the console size.
 * @param X = Receives the new number of columns.
 * @param Y = Receives the new number of rows.
 */void ConsoleSize(int X,int Y){
    HANDLE hConsole=GetStdHandle(STD_OUTPUT_HANDLE);
    SMALL_RECT window ={0,0,X,Y};
    SetConsoleWindowInfo(hConsole,TRUE,&window);
}
/**
 * Description:
 * Change the console title.
 * @param TITLE = Receives the new title ("New Title." by default).
 */void ConsoleTitle(const char*TITLE="New Title."){
    SetConsoleTitle(TEXT(TITLE));
}
/**
 * Description:
 * Show/hide cursor.
 * @param CURSOR = Receives 0/FALSE or 1/TRUE (TRUE by default).
 */void ConsoleCursorSHOW_HIDE(bool CURSOR=true){

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;

    GetConsoleCursorInfo(hConsole, &cursorInfo);
    cursorInfo.bVisible = CURSOR;
    SetConsoleCursorInfo(hConsole, &cursorInfo);
}
/**
 * Description:
 * You can clear the console output by specifying from a single position (X/Y) to a whole line.
 * @param X = Receives the column position.
 * @param Y = Receives the row position.
 * @param amount = Receives the number of columns to delete from X, Y (The entire row by default).
 */void ConsoleClsX_Y(int X, int Y, int amount=ConsoleColumns()){
    HANDLE hConsole=GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord={static_cast<SHORT>(X),static_cast<SHORT>(Y)};
    DWORD cells=amount;
    DWORD CHARACTER_W;

    FillConsoleOutputCharacter(hConsole,TEXT(' '),cells,coord,&CHARACTER_W);
}
/**
* Delete all of the console.
*/void ConsoleDLT(){for(int i=0;i<ConsoleRows();i++)ConsoleClsX_Y(0,i);}

/**
 * Description:
 * You can create a typing animation by entering a text as the first parameter and the typing speed as the second parameter.
 * @param text = Receives the text ("Here is your text." by default).
 * @param velocity = Receives the typing speed (10 by default).
 */void TextAnimation(const char*text="Here is your text.", int velocity=10){
    int i=0;
    while(text[i]!='\0'){std::cout<<text[i++];Pause(velocity);}
}
/**
 * Description:
 * Allows creating a box animation (3 different types).
 * @param tipe = Receives the box type (1 by default).
 * @param width = Receives the width of the box (20 by default).
 * @param width = Receives the height of the box (10 by default).
 * @param velocity = Receives the print speed (10 by default).
 */void BoxAnimation(int tipe=1, int width=20, int height=10, int velocity=10){
    int i, x, y;
    x=PosX();
    y=PosY();

    switch(tipe){
    case 1:
        enum Line1{
                    topLeftCorner1   =218, topRightCorner1   =191,
                    horizontalLine1  =196, verticalLine1     =179,
                    bottomLeftCorner1=192, bottomRightCorner1=217,};

        std::cout<<(char)topLeftCorner1;
        for(i=1;i<width;i++){std::cout<<(char)horizontalLine1;Pause(velocity);}
        std::cout<<(char)topRightCorner1;

        for(i=0;i<height;i++){PosXY(x,++y);std::cout<<(char)verticalLine1;
        PosXY((width+x),y);std::cout<<(char)verticalLine1;Pause(velocity);}

        PosXY(x,y);
        std::cout<<(char)bottomLeftCorner1;
        for(i=1;i<width;i++){std::cout<<(char)horizontalLine1;Pause(velocity);}
        std::cout<<(char)bottomRightCorner1;
    break;
    case 2:
        enum Line2{
                    topLeftCorner2   =201, topRightCorner2   =187,
                    horizontalLine2  =205, verticalLine2     =186,
                    bottomLeftCorner2=200, bottomRightCorner2=188,};

        std::cout<<(char)topLeftCorner2;
        for(i=1;i<width;i++){std::cout<<(char)horizontalLine2;Pause(velocity);}
        std::cout<<(char)topRightCorner2;

        for(i=0;i<height;i++){PosXY(x,++y);std::cout<<(char)verticalLine2;
        PosXY((width+x),y);std::cout<<(char)verticalLine2;Pause(velocity);}

        PosXY(x,y);
        std::cout<<(char)bottomLeftCorner2;
        for(i=1;i<width;i++){std::cout<<(char)horizontalLine2;Pause(velocity);}
        std::cout<<(char)bottomRightCorner2;
    break;
    case 3:
        enum Line3{
                    topHorizontalLine3   =220,
                    bottomHorizontalLine3=223,
                    verticalLine3        =219,};

        for(i=0;i<=width;i++){std::cout<<(char)topHorizontalLine3;Pause(velocity);}

        for(i=0;i<height;i++){PosXY(x,++y);std::cout<<(char)verticalLine3;
        PosXY((width+x),y);std::cout<<(char)verticalLine3;Pause(velocity);}

        PosXY(x,y);
        for(i=0;i<=width;i++){std::cout<<(char)bottomHorizontalLine3;Pause(velocity);}
    break;
    }
}
/**
 * Description:
 * You can create a delay in milliseconds during execution.
 * @param millisecond = Receives the number of milliseconds for the delay.
 */void Pause(int millisecond){
    clock_t endPause=clock()+millisecond*CLOCKS_PER_SEC/1000;
    while(clock()<endPause){}
}
/**
 * Description:
 * Set another color to the text with an underline.
 * @param CUSTOM_COLOR = Receives the number of the color (15 by default).
 */void BackgroundAndTextColor(const int CUSTOM_COLOR=15){
        /*
        <0 = DEFAULT
         0 = Black      1 = Blue    2 = Green   3 = Cyan    4 = Red
         5 = Purple     6 = Yellow  7 = White   8 = Gray    9 = Light Blue
        10 = Light Green    11 = Light Cyan     12 = Light Red
        13 = Light Purple   14 = Light Yellow   15 = Bright White
        */
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, CUSTOM_COLOR | FOREGROUND_INTENSITY);
}

#else // Comprobación para otros sistemas (Unix)

#include <stdio.h>
#include <iostream>
#include <cstdio>
#include <termios.h>
#include <unistd.h>
#include <sys/ioctl.h>

/**
 * Description:
 * Set a new cursor position based on the X-Y coordinates.
 * @param x = Receive the new column position.
 * @param y = Receive the new row position.
 */void PosXY(int x, int y) {
    printf("\x1b[%d;%df", y + 1, x + 1);
}


/**
 * Description:
 * Return the current position X.
 */int PosX() {
    struct termios term, term_orig;
    int fd = STDOUT_FILENO;
    if (tcgetattr(fd, &term_orig) == -1)
        return -1;

    term = term_orig;
    term.c_lflag &= ~ICANON & ~ECHO;
    if (tcsetattr(fd, TCSANOW, &term) == -1)
        return -1;

    std::cout << "\x1b[6n"; // Request cursor position
    int x = -1;
    std::cin >> x; // Read response (like "\x1b[<y>;<x>R")
    tcsetattr(fd, TCSANOW, &term_orig);

    return x;
}
/**
 * Description:
 * Return the current position Y.
 */int PosY() {
    struct termios term, term_orig;
    int fd = STDOUT_FILENO;
    if (tcgetattr(fd, &term_orig) == -1)
        return -1;

    term = term_orig;
    term.c_lflag &= ~ICANON & ~ECHO;
    if (tcsetattr(fd, TCSANOW, &term) == -1)
        return -1;

    std::cout << "\x1b[6n"; // Request cursor position
    int y = -1;
    std::cin >> y; // Read response (like "\x1b[<y>;<x>R")
    tcsetattr(fd, TCSANOW, &term_orig);

    // Extract the Y position from the response
    int pos = 0;
    while (y % 10 != ';') {
        pos = pos * 10 + (y % 10);
        y /= 10;
    }

    return pos - 1; // Subtract 1 as ANSI coordinates are 1-based
}
/**
 * Description:
 * Prints the current X - Y position on the screen.
 */
void Pos_X_Y_INFO() {
    struct termios term, term_orig;
    int fd = STDOUT_FILENO;
    if (tcgetattr(fd, &term_orig) == -1)
        return;

    term = term_orig;
    term.c_lflag &= ~ICANON & ~ECHO;
    if (tcsetattr(fd, TCSANOW, &term) == -1)
        return;

    std::cout << "\x1b[6n"; // Request cursor position
    int x, y;
    std::cin >> y >> x; // Read response (like "\x1b[<y>;<x>R")
    tcsetattr(fd, TCSANOW, &term_orig);

    // Extract the X and Y positions from the response
    int posX = 0;
    while (x % 10 != ';') {
        posX = posX * 10 + (x % 10);
        x /= 10;
    }

    int posY = 0;
    while (y % 10 != '[') {
        posY = posY * 10 + (y % 10);
        y /= 10;
    }

    std::cout << "X: " << posX - 1 << " - Y: " << posY - 1 << std::endl; // Subtract 1 for 0-based coordinates
}
/**
 * Description:
 * Return the amount of columns.
 */int ConsoleColumns() {
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    return w.ws_col;
}
/**
 * Description:
 * Return the amount of rows.
 */int ConsoleRows() {
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    return w.ws_row;
}
/**
 * Description:
 * Change the console size.
 * @param X = Receives the new number of columns.
 * @param Y = Receives the new number of rows.
 */void ConsoleSize(int X, int Y) {
    // Construct the escape sequence to set the terminal size
    std::cout << "\x1b[8;" << Y << ";" << X << "t";
}
/**
 * Description:
 * Change the console title.
 * @param TITLE = Receives the new title ("New Title." by default).
 */void ConsoleTitle(const char* TITLE = "New Title.") {
    std::cout << "\033]0;" << TITLE << "\007";
}
/**
 * Description:
 * Show/hide cursor.
 * @param CURSOR = Receives false (0) to hide or true (1) to show (true by default).
 */void ConsoleCursorSHOW_HIDE(bool CURSOR = true) {
    if (CURSOR) {
        std::cout << "\033[?25h"; // Show cursor
    } else {
        std::cout << "\033[?25l"; // Hide cursor
    }
}
/**
 * Description:
 * You can clear the console output by specifying from a single position (X/Y) to a whole line.
 * @param X = Receives the column position.
 * @param Y = Receives the row position.
 * @param amount = Receives the number of columns to delete from X, Y (The entire row by default).
 */void ConsoleClsX_Y(int X, int Y, int amount = ConsoleColumns()) {
    std::cout << "\033[" << Y + 1 << ";" << X + 1 << "H"; // Move cursor to X, Y position
    std::cout << "\033[2K"; // Erase entire line
}
/**
 * Delete all of the console.
 */void ConsoleDLT() {
    std::cout << "\033[2J"; // Clear the entire screen
    std::cout << "\033[H";  // Move cursor to the top-left corner
}

/**
 * Description:
 * You can create a typing animation by entering a text as the first parameter and the typing speed as the second parameter.
 * @param text = Receives the text ("Here is your text." by default).
 * @param velocity = Receives the typing speed (10 by default).
 */void TextAnimation(const char* text = "Here is your text.", int velocity = 10) {
    int i = 0;
    while (text[i] != '\0') {
        std::cout << text[i++] << std::flush; // Imprime el caracter actual sin saltar de línea
        usleep(velocity * 1000); // Espera el tiempo de velocidad en milisegundos
    }
}





//mirar:

void PosXY(int x, int y) {
    std::cout << "\x1b[" << y + 1 << ";" << x + 1 << "f";
}

/**
 * Description:
 * Allows creating a box animation (3 different types).
 * @param tipe = Receives the box type (1 by default).
 * @param width = Receives the width of the box (20 by default).
 * @param height = Receives the height of the box (10 by default).
 * @param velocity = Receives the print speed (10 by default).
 */void BoxAnimation(int tipe = 1, int width = 20, int height = 10, int velocity = 10) {
    int i, x, y;
    x = PosX();
    y = PosY();

    switch (tipe) {
        case 1:
            std::cout << "\u250c"; // ┌
            for (i = 1; i < width; i++) { std::cout << "\u2500"; Pause(velocity); } // ─
            std::cout << "\u2510"; // ┐

            for (i = 0; i < height; i++) {
                PosXY(x, ++y);
                std::cout << "\u2502"; // │
                PosXY((width + x), y);
                std::cout << "\u2502"; // │
                Pause(velocity);
            }

            PosXY(x, y);
            std::cout << "\u2514"; // └
            for (i = 1; i < width; i++) { std::cout << "\u2500"; Pause(velocity); } // ─
            std::cout << "\u2518"; // ┘
            break;

        case 2:
            std::cout << "\u2554"; // ╔
            for (i = 1; i < width; i++) { std::cout << "\u2550"; Pause(velocity); } // ═
            std::cout << "\u2557"; // ╗

            for (i = 0; i < height; i++) {
                PosXY(x, ++y);
                std::cout << "\u2551"; // ║
                PosXY((width + x), y);
                std::cout << "\u2551"; // ║
                Pause(velocity);
            }

            PosXY(x, y);
            std::cout << "\u255a"; // ╚
            for (i = 1; i < width; i++) { std::cout << "\u2550"; Pause(velocity); } // ═
            std::cout << "\u255d"; // ╝
            break;

        case 3:
            std::cout << "\u2551"; // ║
            for (i = 1; i < width; i++) { std::cout << "\u2550"; Pause(velocity); } // ═
            std::cout << "\u2551"; // ║

            for (i = 0; i < height; i++) {
                PosXY(x, ++y);
                std::cout << "\u2551"; // ║
                PosXY((width + x), y);
                std::cout << "\u2551"; // ║
                Pause(velocity);
            }

            PosXY(x, y);
            std::cout << "\u255a"; // ╚
            for (i = 1; i < width; i++) { std::cout << "\u2550"; Pause(velocity); } // ═
            std::cout << "\u255d"; // ╝
            break;
    }
}
/**
 * Description:
 * You can create a delay in milliseconds during execution.
 * @param millisecond = Receives the number of milliseconds for the delay.
 */void Pause(int millisecond) {
    usleep(millisecond * 1000);
}




/**
 * Description:
 * Set another color to the text with an underline.
 * @param CUSTOM_COLOR = Receives the number of the color (15 by default).
 */
// Códigos de escape ANSI para colores del texto
#define ANSI_BLACK "\x1b[30m"
#define ANSI_RED "\x1b[31m"
#define ANSI_GREEN "\x1b[32m"
#define ANSI_YELLOW "\x1b[33m"
#define ANSI_BLUE "\x1b[34m"
#define ANSI_MAGENTA "\x1b[35m"
#define ANSI_CYAN "\x1b[36m"
#define ANSI_WHITE "\x1b[37m"
#define ANSI_RESET "\x1b[0m"

// Códigos de escape ANSI para colores del fondo
#define ANSI_BG_BLACK "\x1b[40m"
#define ANSI_BG_RED "\x1b[41m"
#define ANSI_BG_GREEN "\x1b[42m"
#define ANSI_BG_YELLOW "\x1b[43m"
#define ANSI_BG_BLUE "\x1b[44m"
#define ANSI_BG_MAGENTA "\x1b[45m"
#define ANSI_BG_CYAN "\x1b[46m"
#define ANSI_BG_WHITE "\x1b[47m"

void BackgroundAndTextColor(const int CUSTOM_COLOR = 15) {
    switch (CUSTOM_COLOR) {
        case 0: std::cout << ANSI_BLACK; break;
        case 1: std::cout << ANSI_BLUE; break;
        case 2: std::cout << ANSI_GREEN; break;
        case 3: std::cout << ANSI_CYAN; break;
        case 4: std::cout << ANSI_RED; break;
        case 5: std::cout << ANSI_MAGENTA; break;
        case 6: std::cout << ANSI_YELLOW; break;
        case 7: std::cout << ANSI_WHITE; break;
        case 8: std::cout << ANSI_BG_BLACK; break;
        case 9: std::cout << ANSI_BG_BLUE; break;
        case 10: std::cout << ANSI_BG_GREEN; break;
        case 11: std::cout << ANSI_BG_CYAN; break;
        case 12: std::cout << ANSI_BG_RED; break;
        case 13: std::cout << ANSI_BG_MAGENTA; break;
        case 14: std::cout << ANSI_BG_YELLOW; break;
        case 15: std::cout << ANSI_BG_WHITE; break;
        default: std::cout << ANSI_RESET; break;
    }
}
#endif

