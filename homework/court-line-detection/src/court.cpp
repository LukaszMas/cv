/************************************************************************/
/**   This program detects lines in given image and draws them on it   **/
/************************************************************************/

#include <stdio.h>

#include <opencv2/opencv.hpp>

std::vector<cv::Vec2f> build_lines(cv::Mat, int, double);

int main(int argc, char** argv)
{
    const char* fileName = "court.png";
    int kernel_thickness = 9;
    double slope_tolerance = 15;

    if (argc > 1)
        fileName = argv[1];
    if (argc > 2)
        kernel_thickness = std::stoi(argv[2]);
    if (argc > 3)
        slope_tolerance = std::stod(argv[3]);

    cv::Mat image = cv::imread(fileName);
    if (!image.data)
    {
        printf("Image cannot be opened.");
        [[maybe_unused]] int c = getchar();
        return -1;
    }

    std::vector<cv::Vec2f> lines = build_lines(image, kernel_thickness, slope_tolerance);

    for (auto selected = lines.begin(); selected != lines.end(); selected++)
    {
        float rho = (*selected)[0];
        float theta = (*selected)[1];
        cv::Point pt1, pt2;
        double a = cos(theta), b = sin(theta);
        double x0 = a * rho, y0 = b * rho;
        pt1.x = cvRound(x0 + 1000 * (-b));
        pt1.y = cvRound(y0 + 1000 * (a));
        pt2.x = cvRound(x0 - 1000 * (-b));
        pt2.y = cvRound(y0 - 1000 * (a));
        cv::line(image, pt1, pt2, cv::Scalar(0, 0, 255), 1, cv::LINE_AA);
    }

    imshow("Lines detected", image);
    cv::waitKey(0);

    return 0;
}

std::vector<cv::Vec2f> build_lines(cv::Mat image, int kernel_thickness, double slope_tolerance)
{
    cv::cvtColor(image, image, cv::COLOR_BGR2GRAY);
    imshow("grayscale", image);
    cv::waitKey(0);

    cv::GaussianBlur(image, image, cv::Size(kernel_thickness, kernel_thickness), 0);
    imshow("gaussian", image);
    cv::waitKey(0);

    cv::Canny(image, image, 15, 30, 3);
    imshow("canny", image);
    cv::waitKey(0);

    std::vector<cv::Vec2f> lines;
    HoughLines(image, lines, 1, CV_PI / 180, 150, 0, 0);

    // Reducing the number of lines by merging similar ones by parameter averages.
    for (auto selected = lines.begin(); selected != lines.end(); selected++)
    {
        cv::Vec2f sum = *selected;
        int match_amount = 1;

        for (auto candidate = ++std::vector<cv::Vec2f>::iterator(selected);
             candidate != lines.end();)
        {
            float thickness = abs((*selected)[0] - (*candidate)[0]);
            double slope = abs((*selected)[1] - (*candidate)[1]);

            if (thickness < kernel_thickness && slope < slope_tolerance * CV_PI / 180)
            {
                sum += *candidate;
                match_amount++;
                candidate = lines.erase(candidate);
            }
            else
                candidate++;
        }

        *selected = sum / match_amount;
    }

    return lines;
}
