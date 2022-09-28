#include "Image.h"
#include <fstream>
#include <string>
#include <iostream>
using namespace std;

class ImageAgr
{
private:
    Image* img;
    ofstream fout;
    ifstream fin;
public:
    ImageAgr(Image* _img);
    void Agr_Print();
    int& Get_Pixel_Agr(int _h, int _w);
    void Expansion();
    void Write_Image(string filename);
    void Read_Image(string filename);
};