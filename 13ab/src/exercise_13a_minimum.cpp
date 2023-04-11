#include <fstream>
#include <iostream>
#include <opencv2/opencv.hpp>

#include "../../include/functions.cpp"

void read_input(std::string input_file_name, int& x, int& y, int& connectivity) {
  std::ifstream input(input_file_name);

  if (input.is_open()) {
    input >> x;
    input >> y;
    input >> connectivity;
    input.close();
  } else
    std::cerr << "Cannot open file: " << input_file_name << std::endl;
}

bool flat_zone_regional_minimum(cv::Mat& input_image, cv::Mat& output_image, cv::Point pixel) {
  int flat_zone_label = 255;
  uchar pixel_label = input_image.at<uchar>(pixel);
  output_image.at<uchar>(pixel) = flat_zone_label;

  std::queue<cv::Point> flatzone;
  flatzone.push(pixel);

  while (!flatzone.empty()) {
    cv::Point current_point = flatzone.front();
    flatzone.pop();
    for (cv::Point neighbour : get_neighbour(&input_image, current_point)) {
      int neighbour_label = input_image.at<uchar>(neighbour);
      if (neighbour_label < pixel_label) return false;  // if there is any neighbour lower then its not a min
      // IF ((I(p') == I(p)) AND (I'(p') != LABEL_FZ))
      if (neighbour_label == pixel_label && output_image.at<uchar>(neighbour) != flat_zone_label) {
        // Pixel p' belongs to x's flat zone and has not been treated
        output_image.at<uchar>(neighbour) = flat_zone_label;
        flatzone.push(neighbour);
      }
    }
  }
  return true;
}

int main(int argc, char* argv[]) {
  if (argc != 4) {
    std::cerr << "Error: number of arguments: check documentation" << std::endl;
    return 1;
  }

  int x, y, connectivity, flat_zone_label = 0;
  read_input(argv[1], x, y, connectivity);
  cv::Mat input_img = cv::imread(argv[2], cv::IMREAD_GRAYSCALE);
  cv::Mat output_img = cv::Mat::zeros(input_img.size(), input_img.type());

  bool is_min = flat_zone_regional_minimum(input_img, output_img, cv::Point(x, y));

  std::cout << "Is a region minimum: " << is_min << std::endl;
  std::ofstream output(argv[3]);
  if (output.is_open()) {
    output << is_min << std::endl;
    output.close();
  } else {
    std::cerr << "Error: Cannot open output file" << std::endl;
    return 1;
  }
}