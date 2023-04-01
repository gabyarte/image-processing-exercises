// Wheel teeth count

#include <algorithm>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <vector>

#include "../../include/functions.cpp"

int main(int argc, char* argv[]) {
  if (argc != 2) {
    std::cout << "Error: number of arguments: include input image file" << std::endl;
    return 1;
  }

  cv::Mat image = cv::imread(argv[1], cv::IMREAD_GRAYSCALE);

  cv::Mat edges;
  Canny(image, edges, 50, 150, 3);

  cv::Mat kernel = getStructuringElement(cv::MORPH_RECT, cv::Size(3, 3));
  cv::dilate(edges, edges, kernel);

  std::vector<std::vector<cv::Point>> contours;
  findContours(edges, contours, cv::RETR_TREE, cv::CHAIN_APPROX_SIMPLE);
  int teeth_count = contours.size();

  std::cout << "Wheel teeth count: " << teeth_count << std::endl;
}