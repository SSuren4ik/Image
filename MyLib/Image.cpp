#include "Image.h"

Image::Image(int _h, int _w)
{
    h = _h;
    w = _w;
    arr = new int* [h];
    arr[0] = new int[h * w];
    for (int i = 1; i < h; i++)
    {
        arr[i] = arr[0] + i * w;
    }
    for (int i = 0; i <h; i++)
    {
        for (int k = 0; k < w; k++)
        {
            Get_Pixel(i, k) = (k +rand() %10) * 10;
        }
    }
}

Image::Image(const Image& a)
{
    h = a.h;
    w = a.w;
    arr = new int* [h];
    arr[0] = new int[h * w];
    for (int i = 1; i < h; i++)
    {
        arr[i] = arr[0] + i * w;
    }
    for (int i = 0; i < h; i++)
    {
        for (int k = 0; k < w; k++)
        {
            arr[i][k] = a.arr[i][k];
        }
    }
}
int Image::Get_Height()
{
    return h;
}
int Image::Get_Weight()
{
    return w;
}

void Image::Print()
{
    for (int i = 0; i < h; i++)
    {
        for (int k = 0; k < w; k++)
        {
            cout << arr[i][k] << " ";
        }
        cout << endl;
    }
}

void Image::Plus()
{
    int** arr2 = new int* [h * 2];
    arr2[0] = new int[h * w * 4];
    for (int i = 1; i < h * 2; i++)
    {
        arr2[i] = arr2[0] + i * w * 2;
    }//выделение памяти
    for (int i = 0; i < h * 2; i++)
    {
        for (int k = 0; k < w * 2; k++)
        {
            arr2[i][k] = 0;
        }
    }
    for (int i = 0; i < h; i++)
    {
        for (int k = 0; k < w; k++)
        {
            arr2[i * 2][k * 2] = arr[i][k];
        }
    }//перенесение в четные столбцы 
    for (int i = 1; i < h * 2 - 1; i += 2)
    {
        for (int k = 0; k < w * 2 - 1; k += 2)
        {
            arr2[i][k] = (arr2[i - 1][k] + arr2[i + 1][k]) / 2;
        }
    }//средние значения в нечетных строках
    for (int i = 0; i < h * 2 - 1; i++)
    {
        for (int k = 1; k < w * 2 - 1; k += 2)
        {
            arr2[i][k] = (arr2[i][k - 1] + arr2[i][k + 1]) / 2;
        }
        arr2[i][w * 2 - 1] = arr2[i][w * 2 - 2];
    }//средние значения в нечетных столбцах
    for (int i = 0; i < w * 2; i++)
    {
        arr2[h * 2 - 1][i] = arr2[h * 2 - 2][i];
    }//копируем все в нижнюю строку

    delete[] arr[0];
    delete[] arr;
    h *= 2;
    w *= 2;
    arr = arr2;
}
Image& Image:: operator =(const Image& image)
{
    if (this == &image)
    {
        return *this;
    }
    delete[] arr[0];
    delete[] arr;
    h = image.h;
    w = image.w;
    arr = new int* [h];
    arr[0] = new int[h * w];
    for (int i = 1; i < h; i++)
    {
        arr[i] = arr[0] + i * w;
    }
    for (int i = 0; i < h; i++)
    {
        for (int k = 0; k < w; k++)
        {
            arr[i][k] = image.arr[i][k];
        }
    }
    return *this;
}
int& Image::Get_Pixel(int _h, int _w)
{
    if (_w < 0 || _h < 0 || _w >= w || _h >= h)
    {
        throw 1;
    }
    return arr[_h][_w];
}
Image::~Image()
{
    if (h == 0 || w == 0)
    {
        return;
    }
    delete[] arr[0];
    delete[] arr;
}