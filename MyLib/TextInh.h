#include "Image.h"
#include <fstream>
#include <string>
#include <iostream>
using namespace std;


class ImageInh : public Image
{
private:
    ofstream fout;
    ifstream fin;
public:
    ImageInh(int _h=0, int _w=0);
    void Expans_Inh();
    void Write_Image(string filename);
    void Read_Image(string filename);
};