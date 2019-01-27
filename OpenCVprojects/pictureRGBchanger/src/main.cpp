#include <iostream>
#include "opencv2/opencv.hpp"

int main(int argc, char** argv){
    //create picture objects
    cv::Mat original = cv::imread("9Ball.jpg", cv::IMREAD_COLOR);
    cv::Mat noBlue = cv::imread("9Ball.jpg", cv::IMREAD_COLOR);
    cv::Mat noGreen = cv::imread("9Ball.jpg", cv::IMREAD_COLOR);
    cv::Mat noRed = cv::imread("9Ball.jpg", cv::IMREAD_COLOR);
    
    //edit pucture objects
    for(int pics = 3; pics > 0; pics --){
        for(int r=0; r<original.rows; r++){

            for(int c=0; c<original.cols; c++){
                if(pics ==3){
                    noBlue.at<cv::Vec3b>(r,c)[0] = noBlue.at<cv::Vec3b>(r,c)[0] * 0;
                }
                else if(pics == 2){
                    noGreen.at<cv::Vec3b>(r,c)[1] = noGreen.at<cv::Vec3b>(r,c)[1] * 0;
                }
                else if(pics == 1){
                    noRed.at<cv::Vec3b>(r,c)[2] = noRed.at<cv::Vec3b>(r,c)[2] * 0;
                }
            }

        }
    }

    //create windows for picture objects
    cv::namedWindow("original", cv::WINDOW_FREERATIO);
    cv::namedWindow("noBlue"  , cv::WINDOW_KEEPRATIO);
    cv::namedWindow("noGreen" , cv::WINDOW_KEEPRATIO);
    cv::namedWindow("noRed"   , cv::WINDOW_KEEPRATIO);

    //display picture objects
    cv::imshow("original", original);
    cv::resizeWindow("original",original.rows/3,original.cols/3);
    cv::imshow("noBlue", noBlue);
    cv::imshow("noGreen", noGreen);
    cv::imshow("noRed", noRed);
    
    //position windows
    cv::moveWindow("noBlue"  , 0 + original.cols * 0 , 0 );
    cv::moveWindow("noGreen" , 0 + original.cols * 1 , 0 );
    cv::moveWindow("noRed"   , 0 + original.cols * 2 , 0 );
    cv::moveWindow("original", 0 + original.cols * 3 , 0 );

    
    //hold window open
    cv::waitKey(0);

    return 0;
}
