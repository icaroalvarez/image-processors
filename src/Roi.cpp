#include <opencv2/imgproc/types_c.h>
#include <opencv2/imgproc.hpp>
#include "Roi.h"

RoiProcessor::RoiProcessor()
:ImageProcessor("roi")
{
    getParameters().registerParameter("top_left_x", IntegerParameter{50, 0, 9999});
    getParameters().registerParameter("top_left_y", IntegerParameter{60, 0, 9999});
    getParameters().registerParameter("width", IntegerParameter{127, 0, 9999});
    getParameters().registerParameter("height", IntegerParameter{161, 0, 9999});
}

cv::Mat RoiProcessor::processImage(const cv::Mat &image)
{
    mosaic.reset();

    auto xValue = MAX(0, getParameters().getParameterValue<int>("top_left_x"));
    xValue = MIN(xValue, image.cols-1);

    auto yValue = MAX(0, getParameters().getParameterValue<int>("top_left_y"));
    yValue = MIN(yValue, image.rows-1);

    auto width = MAX(0, getParameters().getParameterValue<int>("width"));
    width = MIN(width, image.cols-xValue);

    auto height = MAX(0, getParameters().getParameterValue<int>("height"));
    height = MIN(height, image.rows-yValue);

    cv::Mat debugImage;
    if(image.channels() < 3)
    {
        cv::cvtColor(image, debugImage, CV_GRAY2BGR);
    }else{
        debugImage = image.clone();
    }
    cv::rectangle(debugImage, {xValue, yValue, width, height}, {0,255,0});
    mosaic.addImage(debugImage, 0, 0);

    cv::Mat outputImage = image({xValue, yValue, width, height}).clone();
    cv::Mat outputResized;
    cv::resize(outputImage, outputResized, image.size());
    mosaic.addImage(outputResized, 1, 0);
    setDebugImage(mosaic.createMosaic());
    return outputImage;
}
