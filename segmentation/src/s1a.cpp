// Contour extraction using MM erosion or dilation

#include <algorithm>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <vector>

#include "../../include/functions.cpp"

cv::Mat image_difference(cv::Mat* img1, cv::Mat* img2) {
  cv::Mat diff = img1->clone();

  for (int i = 0; i < diff.rows; i++) {
    for (int j = 0; j < diff.cols; j++) {
      diff.at<u_char>(i, j) = img1->at<u_char>(i, j) - img2->at<u_char>(i, j);
    }
  }

  // TODO: optimize loop and check RGB images
  // diff.forEach<uchar>(
  //     [](uchar& p, const int* position) -> void {
  //       p = 0;
  //       std::cout << position << "\n";
  //     });

  // cv::MatIterator_<uchar> it1, it2, end1, end2;
  // for (it1 = img1->begin<uchar>(), it2 = img2->begin<uchar>(),
  //     end1 = img1->end<uchar>(), end2 = img2->end<uchar>();
  //      it1 != end1; ++it1, ++it2) {
  //   std::cout << *it1 << "  ";
  // }

  return diff;
}

cv::Mat countour_extraction(cv::Mat* img1, int size = 1) {
  cv::Mat img_8bit;
  cv::cvtColor(*img1, img_8bit, cv::COLOR_BGR2GRAY);
  cv::Mat dilated = dilation(&img_8bit, size);

  return image_difference(&img_8bit, &dilated);
}

int main(int argc, char* argv[]) {
  if (argc != 4) {
    std::cout << "Error: number of arguments: include input image file" << std::endl;
    return 1;
  }
  cv::Mat img1 = cv::imread(argv[1]);
  cv::Mat output = countour_extraction(&img1, atoi(argv[2]));
  cv::imwrite(argv[3], output);
}