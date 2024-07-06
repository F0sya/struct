#include <iostream>
#include <Windows.h>
using namespace std;

struct Rect {
    int x;
    int y;
    int width;
    int height;
};


void changeSize(Rect& rect, int newWidth, int newHeight) {
    rect.width = newWidth;
    rect.height = newHeight;
}

void changeCoord(int x, int y) {
    COORD pos = { x, y };
    HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(output, pos);
}

void moveRect(Rect& rect, int x, int y)
{
    rect.x = x;
    rect.y = y;
}

void printRect(Rect& rect) {
    int x = rect.x;
    int y = rect.y;
    for (int i = 0; i < rect.height; ++i) {
        changeCoord(x, y);
        for (int j = 0; j < rect.width; ++j) {
            cout << "*";
        }
        y++;
    }
    cout << endl;
}

int main() {
    int input_width; cout << "Enter a width of rect:"; cin >> input_width;
    int input_height; cout << "Enter a height of rect:"; cin >> input_height;
    
    int starter_position_x; cout << "Enter a start coord x:"; cin >> starter_position_x;
    int starter_position_y; cout << "Enter a start coord y:"; cin >> starter_position_y;
    
    Rect rect = {starter_position_x,starter_position_y,input_width,input_height };

    system("cls");
    printRect(rect);
    system("pause");

    cout << "Choose new coord x:"; cin >> starter_position_x;
    cout << "Choose new coord y:"; cin >> starter_position_y;

    system("cls");

    moveRect(rect, starter_position_x, starter_position_y);
    printRect(rect);
    system("pause");

    cout << "Choose new width:"; cin >> input_width;
    cout << "Choose new height:"; cin >> input_height;

    system("cls");
    changeSize(rect, input_width, input_height);
    printRect(rect);
    return 0;
}