#include <iostream>
#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/calib3d/calib3d.hpp"
#include "opencv2/contrib/contrib.hpp"
#include "opencv2/core/core.hpp"

using namespace std;
using namespace cv;

int main(int argc, char* argv[]){
	VideoCapture left(0);
	VideoCapture right(2);
	Mat img_l, img_r, disp;
	StereoBM sbm;
	Mat g1,g2;
	while(waitKey(10) != 32){
		left >> img_l;
		right >> img_r;
		cvtColor(img_l,g1,CV_BGR2GRAY);
		cvtColor(img_r,g2,CV_BGR2GRAY);
		sbm.state->SADWindowSize = 9;
		sbm.state->numberOfDisparities = 112;
		sbm.state->preFilterSize = 5;
		sbm.state->preFilterCap = 61;
		sbm.state->minDisparity = -39;
		sbm.state->textureThreshold = 507;
		sbm.state->uniquenessRatio = 0;
		sbm.state->speckleWindowSize = 0;
		sbm.state->speckleRange = 8;
		sbm.state->disp12MaxDiff = 1;
		sbm(g1,g2,disp);
   		normalize(disp,disp,0,255,CV_MINMAX,CV_8U);
    	imshow("Disp",disp);
    	imshow("left",img_l);
    	imshow("right",img_r);
	}
	return 0;
}