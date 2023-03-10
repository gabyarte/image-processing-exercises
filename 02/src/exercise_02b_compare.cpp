#include <fstream>
#include <iostream>
#include <opencv2/opencv.hpp>

bool compare_images(cv::Mat* img1, cv::Mat* img2) {
  if (img1->rows != img2->rows || img1->cols != img2->cols)
    return false;

  for (int i = 0; i < img1->rows; i++) {
    for (int j = 0; j < img1->cols; j++) {
      if (img1->at<uchar>(i, j) != img2->at<uchar>(i, j))
        return false;
    }
  }
  return true;
}

int main(int argc, char* argv[]) {
  if (argc != 3) {
    std::cout << "Error: number of arguments: input output" << std::endl;
    return 1;
  }
  cv::Mat img1 = cv::imread(argv[1], cv::IMREAD_GRAYSCALE);
  cv::Mat img2 = cv::imread(argv[2], cv::IMREAD_GRAYSCALE);

  std::ofstream output;
  output.open("data/exercise_02b_output.txt");
  output << compare_images(&img1, &img2);
  output.close();
  std::cout << compare_images(&img1, &img2);
}