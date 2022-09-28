#include <gtest.h>
#include "TextAgr.h"

TEST(test_lib, simple_test)
{
    ImageAgr img(new Image(2, 2));
    img.Write_Image("vec.txt");
    ImageAgr img2(new Image);
    img2.Read_Image("vec.txt");
    for (int i = 0; i < 2; i++)
    {
        for (int k =0; k < 2; k++)
        {
            EXPECT_EQ(img2.Get_Pixel_Agr(i, k), img.Get_Pixel_Agr(i, k));
        }
    }
}
TEST(test_lib, simple_test2)
{
    ImageAgr img(new Image(2, 2));
    img.Write_Image("vec.txt");
    ImageAgr img2(new Image);
    img2.Read_Image("vec.txt");
    img.Expansion();
    for (int i = 0; i < img.Get_Height_Agr(); i+=2)
    {
        for (int k = 0; k < img.Get_Weight_Agr() ; k+=2)
        {
            EXPECT_EQ(img.Get_Pixel_Agr(i,k), img2.Get_Pixel_Agr(i/2,k/2));
        }
    }
    for (int i = 1; i < img.Get_Height_Agr() - 1; i += 2)
    {
        for (int k = 0; k < img.Get_Weight_Agr(); k += 2)
        {
            int m = (img.Get_Pixel_Agr(i-1, k) + img.Get_Pixel_Agr(i+1, k)) / 2;
            EXPECT_EQ(img.Get_Pixel_Agr(i, k), m);
        }
    }
    for (int i = 0; i < img.Get_Height_Agr() ; i += 2)
    {
        for (int k = 1; k < img.Get_Weight_Agr() - 1; k += 2)
        {
            int m = (img.Get_Pixel_Agr(i, k-1) + img.Get_Pixel_Agr(i, k+1)) / 2;
            EXPECT_EQ(img.Get_Pixel_Agr(i, k), m);
        }
    }
    for (int i = 0; i < img.Get_Weight_Agr(); i++)
    {
        EXPECT_EQ(img.Get_Pixel_Agr(img.Get_Height_Agr() - 1, i), (img.Get_Pixel_Agr(img.Get_Height_Agr() - 2, i)));
    }
}