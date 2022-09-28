#pragma once
#include <iostream>

using namespace std;

class Image
{
protected:
    int h;
    int w;
    int** arr;
public:
    Image(int _h=0, int _w=0);
    Image(const Image& a);
    int Get_Height();
    int Get_Weight();
    void Plus();
    void Print();
    Image& operator =(const Image& image);
    int& Get_Pixel(int _h, int _w);
    ~Image();
};