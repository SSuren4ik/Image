#include <gtest.h>
#include "TextAgr.h"

TEST(test_lib, simple_test)
{
    ImageAgr img(new Image(2, 2));
    img.Write_Image("vec.txt");
    ImageAgr img2(new Image);
    img2.Read_Image("vec.txt");
    for (int i = 1; i <= 2; i++)
    {
        for (int k = 1; k <= 2; k++)
        {
            EXPECT_EQ(img2.Get_Pixel_Agr(i, k), img.Get_Pixel_Agr(i, k));
        }
    }
}