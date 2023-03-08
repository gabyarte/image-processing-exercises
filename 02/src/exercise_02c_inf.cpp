#include <iostream>
#include <opencv2/opencv.hpp>

cv::Mat infimum(cv::Mat* img1, cv::Mat* img2) {
  cv::Mat output = cv::Mat(std::max(img1->rows, img2->rows), std::max(img1->cols, img2->cols), img1->type());

  for (int i = 0; i < output.rows; i++) {
    for (int j = 0; j < output.cols; j++) {
      output.at<uchar>(j, i) = std::min(img1->at<uchar>(j, i), (img2->at<uchar>(j, i)));
    }
  }
  return output;
}

int main(int argc, char* argv[]) {
  if (argc < 4) {
    std::cout << "Error: number of arguments: include input image file" << std::endl;
    return 1;
  }
  cv::Mat img1 = cv::imread(argv[1], cv::IMREAD_GRAYSCALE);
  cv::Mat img2 = cv::imread(argv[2], cv::IMREAD_GRAYSCALE);
  cv::Mat output = infimum(&img1, &img1);
  cv::imwrite(argv[3], output);
  cv::imshow("Window: Output", output);
  cv::waitKey(0);
}