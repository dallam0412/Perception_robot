/******************************************************************************
 * MIT License
 * 
 * Copyright (c) 2021 Dhanush Babu Allam, Guru Nandhan A D P, Vignesh RR
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE. 
 ******************************************************************************/
/**
 * @file test.cpp
 * @author Dhanush Babu Allam, Guru Nandhan A D P, Vignesh RR
 * @This module runs unit test
 * @version 0.1
 * @date 2022-10-19
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "../app/camera.cpp"
#include "../app/detector.cpp"
//#include "../app/humanTracker.cpp"
#include <gtest/gtest.h>
#include <opencv2/opencv.hpp>

using namespace cv;

/* TEST(getImage, should_pass) {
  Camera C;
  EXPECT_EQ(C.getImage().channels(), 3);
} */

// TEST(ImageHeightCheck, should_pass) {
//   Detector D;
//   cv::Mat image = D.getImage();
//   EXPECT_EQ(D.preProcessing(image).size().height, 640);
// }

// TEST(ImageWidthCheck, should_pass) {
//   Detector D;
//   cv::Mat image = D.getImage();
//   EXPECT_EQ(D.preProcessing(image).size().width, 640);
// }

/* TEST(countHumans, should_pass) {
    Mat img = cv::imread("..//data//test.png");
    Detector Dec;
    EXPECT_EQ(Dec.filterHuman(img), 1);
} */

TEST(DetectedObjectCheck, should_pass) {
   Detector D;
  cv::VideoCapture cap("../data/video.MOV");
  cv::Mat frame;
  cv::Mat output;
  // int i=1;
  bool a=true;
  while (a) {
    cap.read(frame);
    output = D.objectDetections(frame);
    a=false;
    //i--;
  }
    EXPECT_EQ(output.channels(), 3);
}

TEST(PreprocessObjectCheck, should_pass) {
   Detector D;
  cv::VideoCapture cap("../data/video.MOV");
  cv::Mat frame;
  cv::Mat output;
  cv::dnn::Net net;
  net = cv::dnn::readNet("./../model/yolov5s.onnx");
  std::vector<cv::Mat> detections;
  // int i=1;
  bool a=true;
  while (a) {
    cap.read(frame);
    detections = D.preProcessing(frame,net);

    a=false;
    //i--;
  }
  std::cout<<"\n The width of the detected image is :"<<detections[0].size().width;
    EXPECT_EQ(detections[0].size().width, 25200);
}

/* TEST(PostprocessObjectCheck, should_pass) {
   Detector D;
  cv::VideoCapture cap("../data/video.MOV");
  cv::Mat frame;
  cv::dnn::Net net;
  net = cv::dnn::readNet("./../model/yolov5s.onnx");
  std::vector<cv::Mat> detections;
  // int i=1;
  bool a=true;
  while (a) {
    cap.read(frame);
    detections = D.preProcessing(frame,net);

    a=false;
    //i--;
  }
  std::cout<<"\n The width of the detected image is :"<<detections[0].size().width;
    EXPECT_EQ(detections[0].size().width, 25200);
}
 */
