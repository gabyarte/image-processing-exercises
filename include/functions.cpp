#include <algorithm>
#include <opencv2/opencv.hpp>
#include <ranges>
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

// 8  connection
std::vector<cv::Point> get_neighbour(cv::Mat* img, cv::Point current_pos, int size = 1) {
  std::vector<cv::Point> neighbours;
  for (int y = std::max(current_pos.y - size, 0); y <= std::min(current_pos.y + size, img->rows - 1); y++) {
    for (int x = std::max(current_pos.x - size, 0); x <= std::min(current_pos.x + size, img->cols - 1); x++) {
      cv::Point point(x, y);
      if (current_pos != point)
        neighbours.push_back(point);
    }
  }
  return neighbours;
}

std::vector<cv::Point> generate_region(cv::Mat* img, cv::Point current_pos, int size) {
  int current_color = img->at<uchar>(current_pos.y, current_pos.x);
  std::vector<cv::Point> to_visit = {current_pos};
  std::vector<cv::Point> region;

  while (!to_visit.empty()) {
    cv::Point current_point = to_visit.back();

    //  std::cout << region.size() << " should be 1 " << (std::find(region.begin(), region.end(), current_point) == region.end()) << "\n";

    region.push_back(current_point);
    to_visit.pop_back();
    std::vector<cv::Point> neighbours = get_neighbour(img, current_point, size);
    std::copy_if(neighbours.begin(),
                 neighbours.end(),
                 std::back_inserter(to_visit), [&region, &current_color, img](cv::Point val) {
                   return (
                       current_color == (int)img->at<uchar>(val) && (std::find(region.begin(), region.end(), val) == region.end()));
                 });  // ? is not filtering as it should

    // for (auto neighbour : get_neighbour(img, current_point, size)) {
    //   if (current_color == (int)img->at<uchar>(current_point) && (std::find(region.begin(), region.end(), neighbour) == region.end())))
    // }
  }
  return region;
}