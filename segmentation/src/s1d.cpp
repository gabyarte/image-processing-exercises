// Coffee grains watershed markers
#include <algorithm>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <vector>

int main(int argc, char* argv[]) {
  if (argc != 3) {
    std::cout << "Error: number of arguments: include input image file" << std::endl;
    return 1;
  }
  cv::Mat image = cv::imread(argv[1]);

  cv::Mat gray_image;
  cv::cvtColor(image, gray_image, cv::COLOR_BGR2GRAY);

  cv::Mat thresholded;
  cv::threshold(gray_image, thresholded, 80, 255, 1);

  cv::Mat kernel = cv::getStructuringElement(cv::MORPH_ELLIPSE, cv::Size(5, 5));
  morphologyEx(thresholded, thresholded, cv::MORPH_OPEN, kernel);

  std::vector<std::vector<cv::Point>> contours;
  findContours(thresholded, contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);

  cv::Mat markers = cv::Mat::zeros(image.size(), CV_32SC1);

  for (size_t i = 0; i < contours.size(); i++) {
    drawContours(markers, contours, static_cast<int>(i), cv::Scalar(static_cast<int>(i) + 1), -1);
  }

  watershed(image, markers);

  cv::Mat segmented = cv::Mat::zeros(image.size(), CV_8UC3);
  for (int i = 0; i < markers.rows; i++) {
    for (int j = 0; j < markers.cols; j++) {
      int index = markers.at<int>(i, j);
      if (index == -1) {
        segmented.at<cv::Vec3b>(i, j) = cv::Vec3b(0, 0, 255);
      } else {
        segmented.at<cv::Vec3b>(i, j) = image.at<cv::Vec3b>(i, j);
      }
    }
  }

  cv::imwrite(argv[2], segmented);
}