#include <iostream>
#include "Image.h"
#include "TextAgr.h"
#include "TextInh.h"
using namespace std;


void main()
{
    ImageInh img(3, 3);  
    ImageInh img2(3, 3);
    ImageInh img3(3, 3);
    img.Write_Image("vec.txt");
    img2.Read_Image("vec.txt");
    img.Expans_Inh();
    img.Write_Image("vec.txt");
    img3.Read_Image("vec.txt");
    img2.Print();
    img3.Print();
    ImageAgr img4(new Image(3, 3));
    ImageAgr img5(new Image);
    img4.Write_Image("vec.txt");
    img5.Read_Image("vec.txt");
    img5.Agr_Print();
    img4.Expansion();
    img4.Write_Image("vec.txt");
    img5.Read_Image("vec.txt");
    img5.Agr_Print();
}