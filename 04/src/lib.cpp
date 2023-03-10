#include <algorithm>
#include <opencv2/opencv.hpp>
#include <vector>

cv::Mat erosion(cv::Mat* img1, int size) {
  cv::Mat output = img1->clone();
  std::vector<int> square_values;

  for (int i = 0; i < img1->rows; i++) {
    for (int j = 0; j < img1->cols; j++) {
      for (int x = std::max(i - size, 0); x <= std::min(i + size, img1->rows - 1); x++) {
        for (int y = std::max(j - size, 0); y <= std::min(j + size, img1->cols - 1); y++) {
          square_values.push_back(img1->at<uchar>(x, y));
        }
      }
      output.at<uchar>(i, j) = *std::min_element(square_values.begin(), square_values.end());
      square_values.clear();
    }
  }
  return output;
}

cv::Mat dilation(cv::Mat* img1, int size) {
  cv::Mat output = img1->clone();
  std::vector<int> square_values;

  for (int i = 0; i < img1->rows; i++) {
    for (int j = 0; j < img1->cols; j++) {
      for (int x = std::max(i - size, 0); x <= std::min(i + size, img1->rows - 1); x++) {
        for (int y = std::max(j - size, 0); y <= std::min(j + size, img1->cols - 1); y++) {
          square_values.push_back(img1->at<uchar>(x, y));
        }
      }
      output.at<uchar>(i, j) = *std::max_element(square_values.begin(), square_values.end());
      square_values.clear();
    }
  }
  return output;
}