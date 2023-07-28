#include<iostream>
#include"ventanimation.h"

int main(){
BackgroundAndTextColor(3);
PosXY(5,1);
BoxAnimation(1);
PosXY(PosX(),1);
BoxAnimation(2);
PosXY(PosX(),1);
BoxAnimation(3);
Pos_X_Y_INFO();
/*
cout<<"\nColumnas: "<<ConsoleColumns()<<endl;
cout<<"Filas: "<<ConsoleRows()<<endl;

int x,y;
cout<<"Cambiar filas y columnas:\n";
cin>>x;
cin>>y;
ConsoleSize(x,y);
cout<<ConsoleColumns();
cout<<ConsoleRows();
*/

ConsoleCursorSHOW_HIDE(0);

ConsoleClsX_Y(0,2);

ConsoleTitle();
PosXY(5,PosY()+2);
BackgroundAndTextColor();
TextAnimation("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed nec sapien vitae mi fringilla facilisis. Praesent rhoncus condimentum mi vel fermentum. Nam dictum augue a tellus vehicula, eu euismod enim porttitor. Duis id metus et nisi porttitor auctor. Sed dictum, felis eget malesuada tincidunt, elit arcu interdum lectus, eu scelerisque lorem nisi quis ex. Nunc nec bibendum nisi. Suspendisse at leo vitae quam luctus fringilla. Nam aliquet risus vel odio tincidunt, vel rhoncus massa blandit. Vestibulum et velit eu urna fermentum cursus.");

ConsoleClsX_Y(0,15);

return 0;
}
