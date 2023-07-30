#pragma once

#ifndef MY_HEADER_H
#define MY_HEADER_H

#ifdef _WIN32 // Comprobación para Windows

#include <windows.h>

void PosXY(int x, int y) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD newPosition;
    newPosition.X = x;
    newPosition.Y = y;
    SetConsoleCursorPosition(hConsole, newPosition);
}

#else // Comprobación para otros sistemas (Unix)

#include <stdio.h>

void PosXY(int x, int y) {
    printf("\x1b[%d;%df", y + 1, x + 1);
}

#endif

#endif // MY_HEADER_H
