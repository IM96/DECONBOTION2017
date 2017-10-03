#ifndef IMGPROC_H
#define IMGPROC_H

#include <QObject>
#include <opencv2\imgproc\imgproc.hpp>
#include <opencv2\core\core.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <qdebug.h>
#include <qthread.h>
#include <qmessagebox.h>
#include <qmutex.h>
namespace cv {
	using std::vector;
}

class ImgProc : public QObject
{
	Q_OBJECT

public:
	ImgProc(QObject *parent);
	explicit ImgProc();
	~ImgProc();
	bool status;
	bool thresHolded;
	QImage imgOri;
	QImage imgWarna[5];
private:
	int hMin[5], sMin[5], vMin[5];
	int hMax[5], sMax[5], vMax[5];
	int dilate[5], erode[5];
	int x[5], y[5];
	cv::Mat ori;
	cv::Mat hsv;
	cv::Mat warna[5]; // detect colors
	cv::vector<cv::vector <cv::Point> > contours[5]; // contour color that detected
	cv::vector<cv::Vec4i> hierarchy[5];
	cv::VideoCapture camera; // camera to capture image
	QImage matToQImage(cv::Mat); // turn mat into QImage
	void morphOps(cv::Mat &thresh, int, int); // morpOps remove salt and pepper noise
	void grabFrame();
public slots:
	void receiveHSV(int, int, int, int, int, int, int, int, int);
	void openCamera();
signals:
	void sendImage();
};

#endif // IMGPROC_H
