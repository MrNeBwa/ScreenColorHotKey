#include <iostream>
#include <string>
#include <windows.h>
#include <vector>
#include <winuser.h>

using std::cout;
using std::string;
using std::vector;
using std::endl;
void checkColor(int x, int y);
void PrintColor(int x, int y);
void FindCursor();

COLORREF Scolor = NULL;
int needColor[3] = {0,0,0};

void SetNeededColor(int R, int G, int B) {
    needColor[0] = R;
    needColor[1] = G;
    needColor[2] = B;
}

COLORREF GetPixelColor(int x, int y) {
    HDC hDC = GetDC(NULL);
    COLORREF color = GetPixel(hDC, x, y);
    ReleaseDC(NULL, hDC);
    Scolor = color;
    return color;
}


class Testing {
private:
    bool test(vector<int> colors) {
        return (colors[0] == colors[1] &&
            colors[2] == colors[3] &&
            colors[5] == colors[4]);
    }

public:
    bool TestColor() {
        return (test(GetColor()));
    }
    
    vector<int> GetColor() {
        vector<int> colors;
        colors.push_back((int)GetRValue(Scolor));
        colors.push_back(needColor[0]);
        colors.push_back((int)GetGValue(Scolor));
        colors.push_back(needColor[1]);
        colors.push_back((int)GetBValue(Scolor));
        colors.push_back(needColor[2]);
        return colors;
    }

    vector<int> ColorInfo() {
        vector<int> colors;
        colors.push_back((int)(GetRValue(Scolor)));
        colors.push_back((int)GetGValue(Scolor));
        colors.push_back((int)GetBValue(Scolor));
        return colors;
    }


};


int main() {
    int x = -508, y = 259;
    cout << "1 - Check is the color right" << endl << "2 - Check what color is it" << endl << 
        "3 - Find write cursor position" << endl << "4 - Settings" << endl;
    int mode = 0;
    std::cin >> mode;
    system("cls");
    switch (mode)
    {
    case 1:
        checkColor(x,y);
        break;
    case 2:
        PrintColor(x,y);
        break;
    case 3:
        FindCursor();
        break;
    case 4:
        cout << "In working" << endl;
        break;
    }
	return 0;
}


void checkColor(int x, int y) {
    Testing test;
    SetNeededColor(255, 255, 255);
    GetPixelColor(x,y);
    if (test.TestColor()) {
        cout << "The right color" << std::endl;
    }
    else {
        cout << "Wrong color" << std::endl;
    }
}

void PrintColor(int x, int y) {
    GetPixelColor(x,y);
    Testing test;
    auto response = test.ColorInfo();
    for (int b : response) {
        cout << b << ", ";
    }
    cout << endl;
}


void FindCursor() {
    cout << "Set a cursor to needed position" << endl;
    Sleep(0);
    for (int i = 3; i > 0; i--) {
        if (i != 1)
            cout << i << "seconds last" << endl;
        else {
            cout << "1 second left" << endl
                ;
        }
        Sleep(1000)
            ;
    }
    system("cls");
    POINT p;
    GetCursorPos(&p);
    cout << "X: " << p.x << endl << "Y: " << p.y << endl;
}



