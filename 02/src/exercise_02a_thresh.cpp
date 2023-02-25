#include <iostream>
#include <opencv2/opencv.hpp>

cv::Mat process_threshold(cv::Mat* img, int threshold) {
  cv::Mat output_img = img->clone();
  for (int i = 0; i < img->rows; i++) {
    for (int j = 0; j < img->cols; j++) {
      output_img.at<uchar>(j, i) = (img->at<uchar>(j, i) >= threshold) ? 255 : 0;
    }
  }
  return output_img;
}

int main(int argc, char* argv[]) {
  if (argc < 3) {
    std::cout << "Error: number of arguments: include input image file" << std::endl;
    return 1;
  }
  std::string data_path = "data/";
  cv::Mat img1 = cv::imread(argv[1], cv::IMREAD_GRAYSCALE);
  int threshold = std::stoi(argv[2]);

  cv::Mat output_img = process_threshold(&img1, threshold);

  cv::imwrite(data_path + "output1.pgm", output_img);
  cv::imshow("Window: Output", output_img);
  // cv::waitKey(0);
}