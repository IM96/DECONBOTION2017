#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_DECONBOTION2017.h"
#include <qthread.h>
//#include "imgproc.h"
#include <qthread.h>
#include <qobject.h>
#include <qdebug.h>
#include "imgproc.h"
#include "saver.h"
#include <qtextstream.h>
#include <qfile.h>
#include <qfiledialog.h>

using namespace std;

class DECONBOTION2017 : public QMainWindow
{
	Q_OBJECT

public:
	DECONBOTION2017(QWidget *parent = Q_NULLPTR);
	~DECONBOTION2017();

private:
	void init();
	void initConnection();

	Ui::DECONBOTION2017Class *ui;
	ImgProc *cam;
	QThread *camThread;
	QThread *sendThread;
	QString fileName;
	//Saver saver;
	int hMin[5], sMin[5], vMin[5];
	int hMax[5], sMax[5], vMax[5];
	int dilate[5], erode[5];
	int speed;

signals:
	void finished(bool);
	void statusCam(bool);
	void sendHSV(int, int, int, int, int, int, int, int, int);
	void updateHSV();
public slots:
	void startCam();
	void stopCam();
	void changeSliderval();
	void updateLabel();
	void on_save();
	void on_save_as();
	void on_load();
	void loadHSV();
	void changeViewWarna();
};
