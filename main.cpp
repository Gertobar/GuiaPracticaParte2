#include <iostream>
#include <cstdlib>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/imgcodecs/imgcodecs.hpp>
#include <opencv2/video/video.hpp>
#include <opencv2/videoio/videoio.hpp>


using namespace cv;
using namespace std;

Mat r1 = imread("angiografia.jpg", IMREAD_GRAYSCALE);
Mat r2 = imread("radiografia2.jpg", IMREAD_GRAYSCALE);
Mat r3 = imread("angiografia2.jpg", IMREAD_GRAYSCALE);

Mat r1Ero;
Mat r2Ero;
Mat r3Ero;

Mat r1Dil;
Mat r2Dil;
Mat r3Dil;

Mat top1;
Mat top2;
Mat top3;

Mat black1;
Mat black2;
Mat black3;

Mat topBlack1;
Mat topBlack2;
Mat topBlack3;

void createAndView() {
    namedWindow("Original 1", WINDOW_AUTOSIZE);
    namedWindow("Original 2", WINDOW_AUTOSIZE);
    namedWindow("Original 3", WINDOW_AUTOSIZE);

    namedWindow("Erosión 1", WINDOW_AUTOSIZE);
    namedWindow("Erosión 2", WINDOW_AUTOSIZE);
    namedWindow("Erosión 3", WINDOW_AUTOSIZE);

    namedWindow("Dilatación 1", WINDOW_AUTOSIZE);
    namedWindow("Dilatación 2", WINDOW_AUTOSIZE);
    namedWindow("Dilatación 3", WINDOW_AUTOSIZE);

    namedWindow("TopHat 1", WINDOW_AUTOSIZE);
    namedWindow("TopHat 2", WINDOW_AUTOSIZE);
    namedWindow("TopHat 3", WINDOW_AUTOSIZE);

    namedWindow("BlackHat 1", WINDOW_AUTOSIZE);
    namedWindow("BlackHat 2", WINDOW_AUTOSIZE);
    namedWindow("BlackHat 3", WINDOW_AUTOSIZE);

    namedWindow("Top-Black 1", WINDOW_AUTOSIZE);
    namedWindow("Top-Black 2", WINDOW_AUTOSIZE);
    namedWindow("Top-Black 3", WINDOW_AUTOSIZE);


    imshow("Original 1", r1);
    imshow("Original 2", r2);
    imshow("Original 3", r3);

    imshow("Erosión 1", r1Ero);
    imshow("Erosión 2", r2Ero);
    imshow("Erosión 3", r3Ero);

    imshow("Dilatación 1", r1Dil);
    imshow("Dilatación 2", r2Dil);
    imshow("Dilatación 3", r3Dil);

    imshow("TopHat 1", top1);
    imshow("TopHat 2", top2);
    imshow("TopHat 3", top3);

    imshow("BlackHat 1", top1);
    imshow("BlackHat 2", top2);
    imshow("BlackHat 3", top3);

    imshow("Top-Black 1", topBlack1);
    imshow("Top-Black 2", topBlack2);
    imshow("Top-Black 3", topBlack3);

}

int main() {

    Mat mascara = getStructuringElement(MORPH_CROSS, Size(37, 37));

    erode(r1, r1Ero, mascara);
    erode(r2, r2Ero, mascara);
    erode(r3, r3Ero, mascara);

    dilate(r1, r1Dil, mascara);
    dilate(r2, r2Dil, mascara);
    dilate(r3, r3Dil, mascara);

    morphologyEx(r1, top1, MORPH_TOPHAT, mascara);
    morphologyEx(r2, top2, MORPH_TOPHAT, mascara);
    morphologyEx(r3, top3, MORPH_TOPHAT, mascara);

    morphologyEx(r1, black1, MORPH_BLACKHAT, mascara);
    morphologyEx(r2, black2, MORPH_BLACKHAT, mascara);
    morphologyEx(r3, black3, MORPH_BLACKHAT, mascara);


    topBlack1 = r1 + abs(top1 - black1);
    topBlack2 = r2 + abs(top2 - black2);
    topBlack3 = r3 + abs(top3 - black3);

    createAndView();

    waitKey(0);
    destroyAllWindows();
    return 0;
}
