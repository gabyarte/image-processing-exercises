// Implement a program 'exercise_03a_erosion' that performs a morphological erosion of size 'i' using a square of size (2*i+1)x(2*i+1):

// exercise_03a_erosion i exercise_03a_input_01.pgm exercise_03a_output_01.pgm Note: 8-connectivity is assumed.
// Use the property of computing an erosion of size i in terms of elementary erosions of size 1.

// Some test images:
// immed_gray_inv.pgm (input image)
// immed_gray_inv_20051123_ero1.pgm (erosion of size 1, 8-connectivity) immed_gray_inv_20051123_ero2.pgm (erosion of size 2, 8-connectivity)

#include <iostream>
#include <opencv2/opencv.hpp>

int main(int argc, char *argv[]) {
  if (argc < 3) {
    std::cout << "Error: number of arguments: include input image file" << std::endl;
    return 1;
  }
  std::string data_path = "data/";
  cv::Mat img1 = cv::imread(argv[1], cv::IMREAD_GRAYSCALE);
  cv::Mat output_img = img1.clone();
  int threshold = std::stoi(argv[2]);

  for (int i = 0; i < img1.rows; i++) {
    for (int j = 0; j < img1.cols; j++) {
      output_img.at<uchar>(j, i) = (img1.at<uchar>(j, i) >= threshold) ? 255 : 0;
    }
  }

  cv::imwrite(data_path + "output1.pgm", output_img);
  cv::imshow("Window: Output", output_img);
  // cv::waitKey(0);
}