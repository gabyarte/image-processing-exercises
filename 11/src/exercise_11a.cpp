#include <fstream>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <queue>

#include "../../include/functions.cpp"

void read_input(std::string input_file_name, int& x, int& y, int& connectivity, int& flat_zone_label) {
  std::ifstream input(input_file_name);

  if (input.is_open()) {
    input >> x;
    input >> y;
    input >> connectivity;
    input >> flat_zone_label;
    input.close();
  } else
    std::cerr << "Cannot open file: " << input_file_name << std::endl;
}

void reconstruct_flat_zone(cv::Mat& input_image, cv::Mat& output_image, cv::Point pixel, int flat_zone_label) {
  uchar pixel_label = input_image.at<uchar>(pixel);
  output_image.at<uchar>(pixel) = flat_zone_label;

  std::queue<cv::Point> flatzone;
  flatzone.push(pixel);

  while (!flatzone.empty()) {
    cv::Point current_point = flatzone.front();
    flatzone.pop();
    for (cv::Point neighbour : get_neighbour(&input_image, current_point)) {
      // IF ((I(p') == I(p)) AND (I'(p') != LABEL_FZ))
      if (input_image.at<uchar>(neighbour) == pixel_label && output_image.at<uchar>(neighbour) != flat_zone_label) {
        // Pixel p' belongs to x's flat zone and has not been treated
        output_image.at<uchar>(neighbour) = flat_zone_label;
        flatzone.push(neighbour);
      }
    }
  }
}

int main(int argc, char* argv[]) {
  if (argc != 4) {
    std::cerr << "Error: number of arguments: check documentation" << std::endl;
    return 1;
  }

  int x, y, connectivity, flat_zone_label = 0;
  read_input(argv[1], x, y, connectivity, flat_zone_label);
  cv::Mat input_img = cv::imread(argv[2], cv::IMREAD_GRAYSCALE);
  cv::Mat output_img = cv::Mat::zeros(input_img.size(), input_img.type());

  reconstruct_flat_zone(input_img, output_img, cv::Point(x, y), flat_zone_label);

  cv::imwrite(argv[3], output_img);
}