// Grassfire propagation algorithm
#include <iostream>
#include <opencv2/opencv.hpp>
#include <unordered_set>
#include <utility>
#include <vector>

#include "../../include/functions.cpp"

struct PointHasher {
  size_t operator()(const cv::Point& point) const {
    return std::hash<int>{}(point.x) ^ std::hash<int>{}(point.y);
  }
};

struct PointComparator {
  bool operator()(const cv::Point& point1, const cv::Point& point2) const {
    return point1 == point2;
  }
};

cv::Mat grass_propagation(cv::Mat* img, int size) {
  std::vector<std::vector<cv::Point>> regions;
  std::unordered_set<cv::Point, PointHasher, PointComparator> burnt;

  cv::Mat img_gray;
  cv::cvtColor(*img, img_gray, cv::COLOR_BGR2GRAY);

  for (int i = 0; i < img_gray.rows; i++) {
    for (int j = 0; j < img_gray.cols; j++) {
      cv::Point current(j, i);
      if ((int)img_gray.at<uchar>(i, j) != 0 && burnt.find(current) == burnt.end()) {  // ? apply threshold???
        std::vector<cv::Point> new_region = generate_region(&img_gray, current, size);
        regions.push_back(new_region);
        burnt.insert(new_region.begin(), new_region.end());
      }
    }
  }

  // print regions
  cv::Mat result;
  cv::cvtColor(img_gray, result, cv::COLOR_GRAY2BGR);

  for (auto region : regions) {
    cv::Vec3b random_color(rand() % 256, rand() % 256, rand() % 256);
    for (auto point : region) {
      result.at<cv::Vec3b>(point) = random_color;
    }
  }
  return result;
}

int main(int argc, char* argv[]) {
  if (argc > 4) {
    std::cout << "Error: number of arguments: include input image file" << std::endl;
    return 1;
  }
  cv::Mat img1 = cv::imread(argv[1]);
  cv::Mat output = grass_propagation(&img1, atoi(argv[2]));
  cv::imwrite(argv[3], output);
}