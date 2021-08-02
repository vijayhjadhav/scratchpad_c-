#include <iostream>
#include <algorithm>
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

void ScaleusingHeightandWidth(Mat& image)
{
    // down scale the image
    int down_height = 200;
    int down_width = 300;
    Mat resized_down;
    //resize down
    resize(image, resized_down, Size(down_width, down_height), INTER_LINEAR);
    imshow("My downscaled Photo", resized_down);

    // up scale the image
    int up_height = 400;
    int up_width = 600;
    Mat resized_up;
    //resize up
    resize(image, resized_up, Size(up_width, up_height), INTER_LINEAR);
    imshow("My Upscaled Photo", resized_up);
}

void ScaleusingScalefactor(Mat& input, Mat& output, double scale_x, double scale_y)
{       
    resize(input, output, Size(), scale_x, scale_y, INTER_LINEAR);   
}

bool CompareImage(Mat& image1, Mat& image2)
{
    if ((image1.cols != image2.cols) || (image1.rows != image2.rows) || (image1.dims != image2.dims))
        return false;

    Mat diff, diffcolor;

    cv::compare(image1, image2, diff, cv::CMP_EQ);
    auto percentage = countNonZero(diff);
    //cv::cvtColor(diff, diffcolor, cv::COLOR_BGR2HSV);
    //CV_RGB2HSV
    //absdiff(image1, image2, dst);
    //auto const diff = image1 != image2;
    
    //return std::equal(image1.begin<uchar>(), image1.end<uchar>(), image2.begin<uchar>());
    return percentage != 0 ? true : false;
}

int main()
{
    Mat image = imread("C:\\Personal\\data\\1530511260135.jpg", IMREAD_COLOR);

    Mat image2 = imread("C:\\Personal\\data\\1530511260500.jpg", IMREAD_COLOR);
    //imshow("My Photo", image);

    //ScaleusingHeightandWidth(image);

   /* Mat scaled_image1;
    ScaleusingScalefactor(image, scaled_image1, 0.4, 0.4);*/
    //imshow("My Scaled Photo 1", scaled_image1);
    
    /*Mat scaled_image2;
    ScaleusingScalefactor(image, scaled_image2, 0.4, 0.4);*/
   // imshow("My Scaled Photo 2", scaled_image2);

    if (CompareImage(image, image2))
        std::cout << "Images are equal" << std::endl;

    //Mat scaled_image3;
    //ScaleusingScalefactor(image, scaled_image3, 1.0, 1.0);
    ////imshow("My Scaled Photo 3", scaled_image3);

    //Mat scaled_image4;
    //ScaleusingScalefactor(image, scaled_image4, 1.2, 1.2);
    ////imshow("My Scaled Photo 4", scaled_image4);

    //Mat scaled_image5;
    //ScaleusingScalefactor(image, scaled_image5, 1.6, 1.6);
    ////imshow("My Scaled Photo 5", scaled_image5);

    //Mat a, b, c, d, e;
    //hconcat(scaled_image1, scaled_image2, a);
    ////vconcat(scaled_image3, b);
    //vconcat(scaled_image4, scaled_image5, c);
    //vconcat(a, c, d);
    ////vconcat(d, c, e);
    //imshow("together", a);
    waitKey(0);
    return 0;

}
