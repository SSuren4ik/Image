#include "TextInh.h"

ImageInh::ImageInh(int _h, int _w):Image(_h, _w)
{
    ;
}

void ImageInh::Write_Image(string filename)
{
    fout.open(filename);
    if (!fout.is_open())
    {
        return;
    }
    fout << Get_Height() << endl;
    fout << Get_Weight() << endl;
    for (int i = 0; i < Get_Height(); i++)
    {
        for (int k = 0; k < Get_Weight(); k++)
        {
            fout << Get_Pixel(i, k) << " ";
        }
        fout << endl;
    }
    fout.close();
}
void ImageInh::Expans_Inh()
{
    Plus();
}

void ImageInh::Read_Image(string filename)
{
    fin.open(filename);
    if (!fin.is_open())
    {
        return;
    }
    if (!(h == 0 || w == 0))
    {
        delete[] arr[0];
        delete[] arr;
    }
    fin >> h;
    fin >> w;
    arr = new int* [h];
    arr[0] = new int[h * w];
    for (int i = 1; i < h; i++)
    {
        arr[i] = arr[0] + i * w;
    }
    for (int i = 0; i < Get_Height(); i++)
    {
        for (int k = 0; k < Get_Weight(); k++)
        {
            fin >> Get_Pixel(i, k);
        }
    }
    fin.close();
}