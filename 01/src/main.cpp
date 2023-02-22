#include <iostream>
#include <opencv2/opencv.hpp>

int main(int argc, char *argv[]) {
  if (argc < 2) {
    std::cout << "Error: number of arguments: include input image file" << std::endl;
    return 1;
  }
  std::string data_path = "data/";
  cv::Mat gImg1 = cv::imread(argv[1], cv::IMREAD_GRAYSCALE);

  // Copy of image
  cv::Mat gImg2 = gImg1.clone();

  // Basic method to access pixel (x, y), where x and y denote, respectively
  // the column and row coordinates:
  // Mat::at<type>( y, x )
  //
  // cv::Point() can be used if the order (column, row) is preferred:
  // Mat::at<type>( cv::Point( x, y) )
  //
  //
  // For 8-bit images, use the 'uchar' type:
  // Mat::at<uchar>( y, x )
  // or
  // Mat::at<uchar>( cv::Point( x, y ) )

  std::cout << "gImg2.rows: " << gImg2.rows << std::endl;
  std::cout << "gImg2.cols: " << gImg2.cols << std::endl;
  std::cout << "----------------------------------" << std::endl;
  std::cout << "Accessing pixel values by using at<uchar>(row, column):" << std::endl;
  std::cout << "(upper-left corner)  at<uchar>(0,0): " << (int)gImg2.at<uchar>(0, 0) << std::endl;
  std::cout << "                     at<uchar>(0,1): " << (int)gImg2.at<uchar>(0, 1) << std::endl;
  std::cout << "(upper-right corner) at<uchar>(0,255): " << (int)gImg2.at<uchar>(0, (gImg2.cols - 1)) << std::endl;
  std::cout << "(lower-left corner)  at<uchar>(255,0): " << (int)gImg2.at<uchar>((gImg2.rows - 1), 0) << std::endl;
  std::cout << "(lower-right corner) at<uchar>(255,255): " << (int)gImg2.at<uchar>((gImg2.rows - 1), (gImg2.cols - 1)) << std::endl;
  std::cout << "----------------------------------" << std::endl;
  gImg2.at<uchar>(0, 0) = 1;
  gImg2.at<uchar>(0, 1) = 2;
  gImg2.at<uchar>(0, (gImg2.cols - 1)) = 3;
  gImg2.at<uchar>((gImg2.rows - 1), 0) = 4;
  gImg2.at<uchar>((gImg2.rows - 1), (gImg2.cols - 1)) = 5;
  std::cout << "----------------------------------" << std::endl;
  std::cout << "After modifying those pixels values:" << std::endl;
  std::cout << "Accessing pixel values by using at<uchar>(row, column):" << std::endl;
  std::cout << "(upper-left corner)  at<uchar>(0,0): " << (int)gImg2.at<uchar>(0, 0) << std::endl;
  std::cout << "                     at<uchar>(0,1): " << (int)gImg2.at<uchar>(0, 1) << std::endl;
  std::cout << "(upper-right corner) at<uchar>(0,255): " << (int)gImg2.at<uchar>(0, (gImg2.cols - 1)) << std::endl;
  std::cout << "(lower-left corner)  at<uchar>(255,0): " << (int)gImg2.at<uchar>((gImg2.rows - 1), 0) << std::endl;
  std::cout << "(lower-right corner) at<uchar>(255,255): " << (int)gImg2.at<uchar>((gImg2.rows - 1), (gImg2.cols - 1)) << std::endl;
  std::cout << "----------------------------------" << std::endl;

  std::cout << "Saving image output1.pgm ..." << std::endl;
  imwrite(data_path + "output1.pgm", gImg2);

  std::cout << "Showing image in window... Press a key to finish." << std::endl;
  cv::imshow("Window: Img2", gImg2);
  cv::waitKey(0);  // cvWaitKey(0) or cv::waitKey(0)

  return 0;
}