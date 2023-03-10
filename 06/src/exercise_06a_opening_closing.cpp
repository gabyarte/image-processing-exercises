#include <algorithm>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <vector>

#include "../../include/functions.cpp"

cv::Mat opening_closing(cv::Mat* img1, int size) {
  cv::Mat closed = closing(img1, size);
  return opening(&closed, size);
}

int main(int argc, char* argv[]) {
  if (argc < 4) {
    std::cout << "Error: number of arguments: include input image file" << std::endl;
    return 1;
  }
  cv::Mat img1 = cv::imread(argv[1], cv::IMREAD_GRAYSCALE);
  cv::Mat output = opening_closing(&img1, std::atoi(argv[2]));
  cv::imwrite(argv[3], output);
  cv::imshow("Window: Output", output);
}