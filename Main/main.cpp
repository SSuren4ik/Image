#include <iostream>
#include "Image.h"
#include "TextAgr.h"
#include "TextInh.h"
using namespace std;


void main()
{
    //ImageInh img(3, 3);  
    //ImageInh img2(3, 3);
    //ImageInh img3(3, 3);
    //img.Write_Image("vec.txt");
    //img2.Read_Image("vec.txt");
    //img.Expans_Inh();
    //img.Write_Image("vec.txt");
    //img3.Read_Image("vec.txt");
    //img2.Print();
    //img3.Print();
    ImageAgr img(new Image(3, 3));
    ImageAgr img2(new Image);
    img.Write_Image("vec.txt");
    img2.Read_Image("vec.txt");
    img2.Agr_Print();
    img.Expansion();
    img.Write_Image("vec.txt");
    img2.Read_Image("vec.txt");
    img2.Agr_Print();
}