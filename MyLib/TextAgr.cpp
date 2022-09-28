#include "TextAgr.h"

ImageAgr::ImageAgr(Image* _img)
{
    img = new Image(*_img);
}
void ImageAgr::Write_Image(string filename)
{
    fout.open(filename);
    if (!fout.is_open())
    {
        return;
    }
    fout << img->Get_Height() << endl;
    fout << img->Get_Weight() << endl;
    for (int i = 1; i <= img->Get_Height(); i++)
    {
        for (int k = 1; k <= img->Get_Weight(); k++)
        {
            fout << img->Get_Pixel(i, k) << " ";
        }
        fout << endl;
    }
    fout.close();
}
void ImageAgr::Expansion()
{
    img->Plus();
}
void ImageAgr::Agr_Print()
{
    img->Print();
}
int& ImageAgr::Get_Pixel_Agr(int h, int w)
{
    return img->Get_Pixel(h, w);
}
void ImageAgr::Read_Image(string filename)
{
    fin.open(filename);
    if (!fin.is_open())
    {
        return;
    }
    delete img;
    int _h = 0;
    int _w = 0;
    fin >> _h;
    fin >> _w;
    img = new Image(_h, _w);
    for (int i = 1; i <= _h; i++)
    {
        for (int k = 1; k<=_w; k++)
        {
            fin >> img->Get_Pixel(i, k);
            cout << img->Get_Pixel(i, k) << " ";
        }
        cout << endl;
    }
    fin.close();
}