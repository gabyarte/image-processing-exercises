// Implement a program 'exercise_03a_erosion' that performs a morphological erosion of size 'i' using a square of size (2*i+1)x(2*i+1):

// exercise_03a_erosion i exercise_03a_input_01.pgm exercise_03a_output_01.pgm Note: 8-connectivity is assumed.
// Use the property of computing an erosion of size i in terms of elementary erosions of size 1.

// Some test images:
// immed_gray_inv.pgm (input image)
// immed_gray_inv_20051123_ero1.pgm (erosion of size 1, 8-connectivity) immed_gray_inv_20051123_ero2.pgm (erosion of size 2, 8-connectivity)

#include <algorithm>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <vector>

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

int main(int argc, char* argv[]) {
  if (argc < 4) {
    std::cout << "Error: number of arguments: include input image file" << std::endl;
    return 1;
  }
  cv::Mat img1 = cv::imread(argv[1], cv::IMREAD_GRAYSCALE);
  cv::Mat output = dilation(&img1, std::atoi(argv[2]));
  cv::imwrite(argv[3], output);
  cv::imshow("Window: Output", output);
}