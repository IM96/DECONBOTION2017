#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_DECONBOTION2017.h"
#include <qthread.h>
//#include "imgproc.h"
#include <qthread.h>
#include <qobject.h>
#include <qdebug.h>

class DECONBOTION2017 : public QMainWindow
{
	Q_OBJECT

public:
	DECONBOTION2017(QWidget *parent = Q_NULLPTR);

private:
	Ui::DECONBOTION2017Class *ui;
	int hMin[5], sMin[5], vMin[5];
	int hMax[5], sMax[5], vMax[5];
	int erode[5], dilate[5];
	//ImgProc cam;
	QThread *camThread;
	QThread *sendThread;
	void init();
	void initConnection();
signals:
	void finished(bool);
	void statusCam(bool);

public slots:
	void startCam();
	void stopCam();
	void changeSliderval();
};
