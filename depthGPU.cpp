#include <iostream>
#include "opencv2/opencv.hpp"
#include "opencv2/gpu/gpu.hpp"

using namespace cv;
using namespace std;

int main(int argc, char* argv[]){

	Mat src_host;
	VideoCapture cap(0);
	gpu::GpuMat dst,src;
	Mat img;
	
	while(waitKey(5) != 32){
		cap >> src_host;
		src.upload(src_host);

		gpu::threshold(src,dst,128.0,255.0,CV_THRESH_BINARY);

		dst.download(img);

		imshow("Res",img);
		waitKey(10); 
	}
}