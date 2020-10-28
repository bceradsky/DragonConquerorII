#include <iostream>
#include <string>
#include <windows.h>
#include "../include/funcs.h"
#include "../include/global.h"
#include "../include/tinyxml2.h"

using namespace std;
using namespace tinyxml2;


void slowText(string text, int rate) {
  for (int i = 0; i < text.size(); i++) {
    if (text[i] != '`') {
      cout << text[i];
      Sleep(rate);
    } else {
      Sleep(500);
    }
  }
}

void setWindow(int Width, int Height) {
  _COORD coord;
  coord.X = Width;
  coord.Y = Height;

  _SMALL_RECT Rect;
  Rect.Top = 0;
  Rect.Left = 0;
  Rect.Bottom = Height - 1;
  Rect.Right = Width - 1;

  HANDLE Handle = GetStdHandle(STD_OUTPUT_HANDLE);      // Get Handle
  SetConsoleScreenBufferSize(Handle, coord);            // Set Buffer Size
  SetConsoleWindowInfo(Handle, TRUE, &Rect);            // Set Window Size
}
void clearScreen() {
  HANDLE hStdOut;
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  DWORD count;
  DWORD cellCount;
  COORD homeCoords = { 0, 0 };

  hStdOut = GetStdHandle( STD_OUTPUT_HANDLE );
  if (hStdOut == INVALID_HANDLE_VALUE) return;

  /* Get the number of cells in the current buffer */
  if (!GetConsoleScreenBufferInfo( hStdOut, &csbi )) return;
  cellCount = csbi.dwSize.X *csbi.dwSize.Y;

  /* Fill the entire buffer with spaces */
  if (!FillConsoleOutputCharacter(
    hStdOut,
    (TCHAR) ' ',
    cellCount,
    homeCoords,
    &count
    )) return;

  /* Fill the entire buffer with the current colors and attributes */
  if (!FillConsoleOutputAttribute(
    hStdOut,
    csbi.wAttributes,
    cellCount,
    homeCoords,
    &count
    )) return;

  /* Move the cursor home */
  SetConsoleCursorPosition( hStdOut, homeCoords );
}

void titleScreen() {
  XMLDocument doc;
  doc.LoadFile("../lib/logoandexit.xml");
  const char* title = doc.FirstChildElement("Root")->FirstChildElement("logo")->GetText();
  slowText(title, 1);
}

void exitScreen() {
  XMLDocument doc;
  doc.LoadFile("../lib/logoandexit.xml");
  const char* exit_text = doc.FirstChildElement("Root")->FirstChildElement("exit_text")->GetText();
  slowText(exit_text, 1);
}
