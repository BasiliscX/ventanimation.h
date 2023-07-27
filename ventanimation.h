#pragma once

#include<iostream>
#include<ctime>
#include<windows.h>

/// Change the cursor's position:
void PosXY(int x, int y){
    HANDLE hConsole=GetStdHandle(STD_OUTPUT_HANDLE);
    COORD newPosition;
    newPosition.X=x;
    newPosition.Y=y;
    SetConsoleCursorPosition(hConsole, newPosition);
}
/// Get position X:
int getPosX(){
HANDLE hConsole=GetStdHandle(STD_OUTPUT_HANDLE);
CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
if (GetConsoleScreenBufferInfo(hConsole, &consoleInfo)){
    int x=consoleInfo.dwCursorPosition.X;
    return x;
}
else return 0;
}
/// Get position Y:
int getPosY(){
HANDLE hConsole=GetStdHandle(STD_OUTPUT_HANDLE);
CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
if (GetConsoleScreenBufferInfo(hConsole, &consoleInfo)){
    int y=consoleInfo.dwCursorPosition.Y;
    return y;
}
else return 0;
}

/// Slow down the screen printing:
void Pause(int millisecond) {
    clock_t endPause=clock()+millisecond*CLOCKS_PER_SEC/1000;
    while(clock()<endPause){}
}

/// Draw a box:
void BoxAnimation(int tipe=1, int width=20, int height=10, int velocity=5){

int i, x, y;
x=getPosX();
y=getPosY();

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
/// Create a typing animation with the entered text.
void TextAnimation(const char*text="Here is your text.", int velocity=5){

int i=0;
while(text[i]!='\0'){std::cout<<text[i++];Pause(velocity);}

}
/// Set another color to the text with an underline.
void BackgroundAndTextColor(const int CUSTOM_COLOR=15){
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
/// Prints the amount of columns.
int ConsoleColumns(){
HANDLE hConsole=GetStdHandle(STD_OUTPUT_HANDLE);
CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
if(GetConsoleScreenBufferInfo(hConsole, &consoleInfo)){
    int columns=consoleInfo.srWindow.Right-consoleInfo.srWindow.Left+1;
    return columns;
    }
    else return 0;
}
/// Prints the amount of rows.
int ConsoleRows(){
HANDLE hConsole=GetStdHandle(STD_OUTPUT_HANDLE);
CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
if(GetConsoleScreenBufferInfo(hConsole, &consoleInfo)){
    int rows=consoleInfo.srWindow.Bottom-consoleInfo.srWindow.Top+1;
    return rows;
    }
    else return 0;
}
/// change the console size.
void ConsoleSize(int X=80, int Y=40){
HANDLE hConsole=GetStdHandle(STD_OUTPUT_HANDLE);
SMALL_RECT window ={0,0,X,Y};
SetConsoleWindowInfo(hConsole,TRUE,&window);
}

void ConsoleTitle(const char*TITLE="New Title."){
SetConsoleTitle(TEXT(TITLE));
}

