#include <algorithm>
#include <opencv2/opencv.hpp>
#include <vector>

cv::Mat process_threshold(cv::Mat* img, int threshold) {
  cv::Mat output_img = img->clone();
  output_img.forEach<uchar>([&threshold](uchar& pixel, const int* position) -> void {
    pixel = (pixel >= threshold) ? 255 : 0;
  });

  return output_img;
}

bool compare_images(cv::Mat* img1, cv::Mat* img2) {
  if (img1->rows != img2->rows || img1->cols != img2->cols)
    return false;

  for (int i = 0; i < img1->rows; i++) {
    for (int j = 0; j < img1->cols; j++) {
      if (img1->at<uchar>(i, j) != img2->at<uchar>(i, j))
        return false;
    }
  }
  return true;
}

cv::Mat infimum(cv::Mat* img1, cv::Mat* img2) {
  cv::Mat output = cv::Mat(std::max(img1->rows, img2->rows), std::max(img1->cols, img2->cols), img1->type());

  for (int i = 0; i < output.rows; i++) {
    for (int j = 0; j < output.cols; j++) {
      output.at<uchar>(i, j) = std::min(img1->at<uchar>(i, j), (img2->at<uchar>(i, j)));
    }
  }
  return output;
}

cv::Mat supremum(cv::Mat* img1, cv::Mat* img2) {
  cv::Mat output = cv::Mat(std::max(img1->rows, img2->rows), std::max(img1->cols, img2->cols), img1->type());

  for (int i = 0; i < output.rows; i++) {
    for (int j = 0; j < output.cols; j++) {
      output.at<uchar>(i, j) = std::max(img1->at<uchar>(i, j), (img2->at<uchar>(i, j)));
    }
  }
  return output;
}

cv::Mat erosion(cv::Mat* img1, int size) {
  cv::Mat output = img1->clone();
  std::vector<int> square_values;

  for (int i = 0; i < img1->rows; i++) {
    for (int j = 0; j < img1->cols; j++) {
      for (int x = std::max(i - size, 0); x <= std::min(i + size, img1->rows - 1); x++) {
        for (int y = std::max(j - size, 0); y <= std::min(j + size, img1->cols - 1); y++) {
          square_values.push_back(img1->at<uchar>(x, y));
        }
      }
      output.at<uchar>(i, j) = *std::min_element(square_values.begin(), square_values.end());
      square_values.clear();
    }
  }
  return output;
}

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

cv::Mat closing(cv::Mat* img1, int size) {
  cv::Mat dilated = dilation(img1, size);
  return erosion(&dilated, size);
}

cv::Mat opening(cv::Mat* img1, int size) {
  cv::Mat eroded = erosion(img1, size);
  return dilation(&eroded, size);
}

cv::Mat closing_opening(cv::Mat* img1, int size) {
  cv::Mat opened = opening(img1, size);
  return closing(&opened, size);
}

cv::Mat opening_closing(cv::Mat* img1, int size) {
  cv::Mat closed = closing(img1, size);
  return opening(&closed, size);
}