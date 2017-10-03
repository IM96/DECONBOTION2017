#include "imgproc.h"
#include <qmessagebox.h>

using namespace std;

ImgProc::ImgProc(QObject *parent)
	: QObject(parent)
{
	for (int i = 0; i < 5; i++) {
		hMin[i] = 0;
		sMin[i] = 0;
		vMin[i] = 0;
		hMax[i] = 255;
		vMax[i] = 255;
		sMax[i] = 255;
		erode[i] = 0;
		dilate[i] = 0;
		x[i] = 0;
		y[i] = 0;
	}
	thresHolded = false;
}

ImgProc::ImgProc(){
	for (int i = 0; i < 5; i++) {
		hMin[i] = 0;
		sMin[i] = 0;
		vMin[i] = 0;
		hMax[i] = 255;
		vMax[i] = 255;
		sMax[i] = 255;
		erode[i] = 0;
		dilate[i] = 0;
		x[i] = 0;
		y[i] = 0;
	}
	thresHolded = false;
}

ImgProc::~ImgProc()
{
}

void ImgProc::openCamera() {
	camera.open(0);
	camera.set(CV_CAP_PROP_FRAME_HEIGHT, 360);
	camera.set(CV_CAP_PROP_FRAME_WIDTH, 480);
	qDebug() << camera.get(CV_CAP_PROP_FRAME_WIDTH);
	if (camera.isOpened() == false) {                 // if unsuccessful
		qDebug() << "Error no camera";
		                         // and exit program
		return;                                 //
	}
	thresHolded = false;
	QThread::msleep(50);
	grabFrame();
}

void ImgProc::grabFrame() {
	qDebug() << "Masuk Grab frame\n";
	while (status) {
		// get next frame
		bool blnFrameReadSuccessfully = camera.read(ori);              
		// check if successfully read frame
		if (!blnFrameReadSuccessfully || ori.empty()) {
			// fail and stop
			qDebug() << "No camera detected";
			qDebug() << ori.empty();
			return;                                                                                     //
		}
		// convert to hsv
		cv::cvtColor(ori, hsv, CV_BGR2HSV);

		// threshold image to detect color
		for (int i = 0; i < 5;i++) {
			cv::inRange(hsv, cv::Scalar(hMin[i], sMin[i], vMin[i]), cv::Scalar(hMax[i], sMax[i], vMax[i]), warna[i]);
			morphOps(warna[i], erode[i], dilate[i]);
			imgWarna[i] = matToQImage(warna[i]);
		}
		
		imgOri = matToQImage(ori);

		emit sendImage();
		QThread::msleep(100);
	}
	camera.release();
}

QImage ImgProc::matToQImage(cv::Mat mat)
{
	if (mat.channels() == 1) {                           // if 1 channel (grayscale or black and white) image

		//qDebug() << "sgvudhbkjxn\n";
		return QImage((uchar*)mat.data, mat.cols, mat.rows, mat.step, QImage::Format_Indexed8);     // return QImage
	}
	else if (mat.channels() == 3) {                    // if 3 channel color image
		cv::cvtColor(mat, mat, CV_BGR2RGB);             // flip colors
		return QImage((uchar*)mat.data, mat.cols, mat.rows, mat.step, QImage::Format_RGB888);       // return QImage
	}
	else {
		qDebug() << "in openCVMatToQImage, image was not 1 channel or 3 channel, should never get here";
	}
	return QImage();        // return a blank QImage if the above did not work
}


void ImgProc::receiveHSV(int hmin, int smin, int vmin,
						int hmax, int smax, int vmax, 
						int erode, int dilate, int id) {
	qDebug() << hMin << sMin << vMin << id << "\n";
	// recive hsv and update thresholded image
	hMin[id] = hmin;
	sMin[id] = smin;
	vMin[id] = vmin;
	hMax[id] = hmax;
	sMax[id] = smax;
	vMax[id] = vmax;
	this->erode[id] = erode;
	this->dilate[id] = dilate;
	if (thresHolded) {
		cv::inRange(hsv, cv::Scalar(hMin[id], sMin[id], vMin[id]), cv::Scalar(hMax[id], sMax[id], vMax[id]), warna[id]);
		morphOps(warna[id], erode, dilate);
		qDebug() << hMin[0] << sMin[0] << vMin[0] << "2\n";
		//qDebug() << "thresholded";
	}
	
}

void ImgProc::morphOps(cv::Mat &thresh, int erodex, int dilatex) {
	if (erodex > 0) {
		cv::Mat erodeElement = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(erodex, erodex));
		cv::erode(thresh, thresh, erodeElement);
		cv::erode(thresh, thresh, erodeElement);
	}
	if (dilatex > 0) {
		//dilate with larger element so make sure object is nicely visible
		cv::Mat dilateElement = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(dilatex, dilatex));
		cv::dilate(thresh, thresh, dilateElement);
		cv::dilate(thresh, thresh, dilateElement);
	}
}