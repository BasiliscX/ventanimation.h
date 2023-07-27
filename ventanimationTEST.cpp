#include<iostream>
#include<ventanimation.h>

using namespace std;

int main(){

system("mode con: cols=80 lines=40");
system("color 8F");
/*
BackgroundAndTextColor(3);
PosXY(5,1);
BoxAnimation(1);
PosXY(getPosX(),1);
BoxAnimation(2);
PosXY(getPosX(),1);
BoxAnimation(3);
*/
/*
cout<<ConsoleColumns();
cout<<ConsoleRows();

int x,y;
cin>>x;
cin>>y;

ConsoleSize(x,y);
cout<<ConsoleColumns();
cout<<ConsoleRows();
*/

ConsoleTitle();

PosXY(5,getPosY()+2);
BackgroundAndTextColor();
TextAnimation();

return 0;
}
