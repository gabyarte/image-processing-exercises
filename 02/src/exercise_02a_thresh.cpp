#include <iostream>
#include <opencv2/opencv.hpp>

cv::Mat process_threshold(cv::Mat* img, int threshold) {
  cv::Mat output_img = img->clone();
  output_img.forEach<uchar>([&threshold](uchar& pixel, const int* position) -> void {
    pixel = (pixel >= threshold) ? 255 : 0;
  });

  return output_img;
}

int main(int argc, char* argv[]) {
  if (argc != 4) {
    std::cout << "Error: number of arguments: input threshold output" << std::endl;
    return 1;
  }
  cv::Mat img1 = cv::imread(argv[1], cv::IMREAD_GRAYSCALE);
  int threshold = std::stoi(argv[2]);

  cv::Mat output_img = process_threshold(&img1, threshold);

  cv::imwrite(argv[3], output_img);
  cv::imshow("Window: Output", output_img);
  // cv::waitKey(0);
}