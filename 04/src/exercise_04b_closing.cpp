#include <algorithm>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <vector>

#include "lib.cpp"

cv::Mat closing(cv::Mat* img1, int size) {
  cv::Mat dilated = dilation(img1, size);
  return erosion(&dilated, size);
}

int main(int argc, char* argv[]) {
  if (argc < 4) {
    std::cout << "Error: number of arguments: include input image file" << std::endl;
    return 1;
  }
  cv::Mat img1 = cv::imread(argv[1], cv::IMREAD_GRAYSCALE);
  cv::Mat output = closing(&img1, std::atoi(argv[2]));
  cv::imwrite(argv[3], output);
  cv::imshow("Window: Output", output);
}