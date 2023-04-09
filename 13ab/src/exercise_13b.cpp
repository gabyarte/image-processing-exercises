#include <iostream>
#include <opencv2/opencv.hpp>

cv::Mat something(cv::Mat* img) {
  cv::Mat output_img = img->clone();

  return output_img;
}

int main(int argc, char* argv[]) {
  if (argc != 3) {
    std::cout << "Error: number of arguments: input output" << std::endl;
    return 1;
  }
  cv::Mat img1 = cv::imread(argv[1], cv::IMREAD_GRAYSCALE);

  cv::Mat output_img = something(&img1);

  cv::imwrite(argv[2], output_img);
  cv::imshow("Window: Output", output_img);
}