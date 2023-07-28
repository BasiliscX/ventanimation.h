#include<iostream>
#include"ventanimation.h"

int main(){

    int8_t pin=16 ,arrow=27;

        std::cout<<pin<<" Position (X - Y) FUNTIONS:\n";
        std::cout<<"\no PosXY(int,int) = Change the cursor's position.\n";
        std::cout<<arrow<<"current (X=0, Y=4).";

    PosXY(25,5);
        std::cout<<arrow<<"now (X=25, Y=5).";
    PosXY(5,7);
        std::cout<<"o PosX() = Return position X: "<<PosX();
    PosXY(5,8);        std::cout<<"o PosY() = Return position y: "<<PosY();
    PosXY(PosX()-30,PosY()+2);
        std::cout<<"Now you can set the position arithmetically!: PosXY(PosX()-30,PosY()+2).";
    PosXY(5,PosY()+2);
        std::cout<<"o Pos_X_Y_INFO() = Prints the current X - Y position on the screen: ";
        Pos_X_Y_INFO();

    PosXY(0,PosY()+1);
        std::cout<<pin<<" Console tools:";
    PosXY(5,PosY()+2);
        std::cout<<"ConsoleColumns() = Return the amount of columns: "<<ConsoleColumns();
    PosXY(5,PosY()+1);
        std::cout<<"ConsoleRows() = Return the amount of rows: "<<ConsoleRows();
    PosXY(5,PosY()+1);
        std::cout<<"ConsoleSize(int,int) = Change the console size.";
    PosXY(5,PosY()+1);
        std::cout<<"Do you want to try? (try with 110, 20):";

    int X,Y,z;
    char K;
    PosXY(5,PosY()+1);
        std::cout<<"Columns: ";std::cin>>X;
    PosXY(PosX()+25,PosY()-1);
        std::cout<<"Rows: ";std::cin>>Y;
        ConsoleSize(X,Y);
    PosXY(5,PosY()+1);
        std::cout<<"ConsoleTitle(const char*) = Change the console title: ";
    PosXY(5,PosY()+1);
        std::cout<<"New title of the console: ventanimation.h";
        ConsoleTitle("ventanimation.h");
    PosXY(5,PosY()+1);
        std::cout<<"o ConsoleCursorSHOW_HIDE(bool) = Show/hide cursor:";
        ConsoleCursorSHOW_HIDE(0);
    PosXY(5,PosY()+1);
        std::cout<<"o ConsoleClsX_Y(int,int,int) = Clear console(specific row/position):";
    PosXY(5,PosY()+1);
        std::cout<<"Rows to eliminate: 0, 14 (Console tools:)";
        ConsoleClsX_Y(0,14);
    PosXY(5,PosY()+1);
        std::cout<<"Word to eliminate: 5, 16, 14 (ConsoleColumns)";
        ConsoleClsX_Y(5,16,14);
    PosXY(5,PosY()+1);
        std::cout<<"Eliminate all: Press any key ";std::cin>>K;
    ConsoleDLT();

    PosXY(0,0);
        std::cout<<pin<<" Animation functions:";
    PosXY(5,PosY()+2);
        std::cout<<"TextAnimation(const char*,int) = Text with animation.";
    PosXY(5,PosY()+2);
        TextAnimation("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed nec sapien vitae mi fringilla facilisis. Praesent rhoncus condimentum mi vel fermentum. Nam dictum augue a tellus vehicula, eu euismod enim porttitor. Duis id metus et nisi porttitor auctor. Sed dictum, felis eget malesuada tincidunt, elit arcu interdum lectus, eu scelerisque lorem nisi quis ex. Nunc nec bibendum nisi. Suspendisse at leo vitae quam luctus fringilla. Nam aliquet risus vel odio tincidunt, vel rhoncus massa blandit. Vestibulum et velit eu urna fermentum cursus.");
    PosXY(5,15);
        std::cout<<"BoxAnimation(int,int,int,int) = Draw a box with animation.";
        PosXY(5,1);
        BoxAnimation(1);
        PosXY(PosX(),1);
        BoxAnimation(2);
        PosXY(PosX(),1);
        BoxAnimation(3);

    PosXY(5,16);
        std::cout<<"Eliminate all: Press any key ";std::cin>>K;
    ConsoleDLT();

    PosXY(5,1);
        std::cout<<"BackgroundAndTextColor(const int) = Set another color to the text with an underline.";
    PosXY(5,2);
        std::cout<<"Set a color (1 / 15): ";std::cin>>z;
        BackgroundAndTextColor(z);

    ConsoleDLT();

        PosXY(5,1);
        BoxAnimation(1);
        PosXY(PosX(),1);
        BoxAnimation(2);
        PosXY(PosX(),1);
        BoxAnimation(3);

    PosXY(5,PosY()+2);
        std::cout<<"Make a Box:";
    PosXY(5,PosY()+1);
        std::cout<<"width: ";std::cin>>X;
    PosXY(20,PosY()-1);
        std::cout<<"height: ";std::cin>>Y;

    ConsoleDLT();
    BoxAnimation(3,X,Y);

return 0;
}
