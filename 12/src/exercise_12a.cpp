#include <fstream>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <queue>

#include "../../include/functions.cpp"

void read_input(std::string input_file_name, int& connectivity) {
  std::ifstream input(input_file_name);

  if (input.is_open()) {
    input >> connectivity;
    input.close();
  } else {
    std::cerr << "Cannot open file: " << input_file_name << std::endl;
  }
}

// Same function from exercise 11 but using int because uchar gave problems with 32 bits image
void reconstruct_flat_zone(cv::Mat& input_image, cv::Mat& output_image, cv::Point pixel, int flat_zone_label) {
  int pixel_label = static_cast<int>(input_image.at<uchar>(pixel));
  output_image.at<int>(pixel) = flat_zone_label;

  std::queue<cv::Point> flatzone;
  flatzone.push(pixel);

  while (!flatzone.empty()) {
    cv::Point current_point = flatzone.front();
    flatzone.pop();
    for (cv::Point neighbour : get_neighbour(&input_image, current_point)) {
      // IF ((I(p') == I(p)) AND (I'(p') != LABEL_FZ))
      if (static_cast<int>(input_image.at<uchar>(neighbour)) == pixel_label && output_image.at<int>(neighbour) != flat_zone_label) {
        // Pixel p' belongs to x's flat zone and has not been treated
        output_image.at<int>(neighbour) = flat_zone_label;
        flatzone.push(neighbour);
      }
    }
  }
}

int get_num_of_flat_zones(cv::Mat& input_image) {
  cv::Mat aux = cv::Mat::zeros(input_image.size(), CV_32S);
  int flat_zone_label = 1;  // one diff color for each flat zone

  for (int row = 0; row < input_image.rows; row++) {
    for (int col = 0; col < input_image.cols; col++) {
      if (aux.at<int>(row, col) == 0) {  // if not in flat zone yet
        reconstruct_flat_zone(input_image, aux, cv::Point(col, row), flat_zone_label);
        flat_zone_label++;
      }
    }
  }

  return flat_zone_label - 1;
}

int main(int argc, char* argv[]) {
  if (argc != 4) {
    std::cerr << "Error: Incorrect number of arguments: check documentation" << std::endl;
    return 1;
  }

  int connectivity;
  read_input(argv[1], connectivity);

  cv::Mat input_image = cv::imread(argv[2], cv::IMREAD_GRAYSCALE);
  int num_flat_zones = get_num_of_flat_zones(input_image);

  std::cout << "Number of flat zones: " << num_flat_zones << std::endl;
  std::ofstream output(argv[3]);
  if (output.is_open()) {
    output << num_flat_zones << std::endl;
    output.close();
  } else {
    std::cerr << "Error: Cannot open output file" << std::endl;
    return 1;
  }

  return 0;
}
