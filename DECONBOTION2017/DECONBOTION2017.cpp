#include "DECONBOTION2017.h"
#include <opencv2\imgproc\imgproc.hpp>
#include <opencv2\core\core.hpp>
#include <opencv2\highgui\highgui.hpp>

void DECONBOTION2017::initConnection() {
	connect(ui->hMin1, SIGNAL(valueChanged(int)), this, SLOT(changeSliderval()));
	connect(ui->hMin2, SIGNAL(valueChanged(int)), this, SLOT(changeSliderval()));
	connect(ui->hMin3, SIGNAL(valueChanged(int)), this, SLOT(changeSliderval()));
	connect(ui->hMin4, SIGNAL(valueChanged(int)), this, SLOT(changeSliderval()));
	connect(ui->hMin5, SIGNAL(valueChanged(int)), this, SLOT(changeSliderval()));
	
	connect(ui->hMax1, SIGNAL(valueChanged(int)), this, SLOT(changeSliderval()));
	connect(ui->hMax2, SIGNAL(valueChanged(int)), this, SLOT(changeSliderval()));
	connect(ui->hMax3, SIGNAL(valueChanged(int)), this, SLOT(changeSliderval()));
	connect(ui->hMax4, SIGNAL(valueChanged(int)), this, SLOT(changeSliderval()));
	connect(ui->hMax5, SIGNAL(valueChanged(int)), this, SLOT(changeSliderval()));

	connect(ui->sMin1, SIGNAL(valueChanged(int)), this, SLOT(changeSliderval()));
	connect(ui->sMin2, SIGNAL(valueChanged(int)), this, SLOT(changeSliderval()));
	connect(ui->sMin3, SIGNAL(valueChanged(int)), this, SLOT(changeSliderval()));
	connect(ui->sMin4, SIGNAL(valueChanged(int)), this, SLOT(changeSliderval()));
	connect(ui->sMin5, SIGNAL(valueChanged(int)), this, SLOT(changeSliderval()));

	connect(ui->sMax1, SIGNAL(valueChanged(int)), this, SLOT(changeSliderval()));
	connect(ui->sMax2, SIGNAL(valueChanged(int)), this, SLOT(changeSliderval()));
	connect(ui->sMax3, SIGNAL(valueChanged(int)), this, SLOT(changeSliderval()));
	connect(ui->sMax4, SIGNAL(valueChanged(int)), this, SLOT(changeSliderval()));
	connect(ui->sMax5, SIGNAL(valueChanged(int)), this, SLOT(changeSliderval()));

	
	connect(ui->vMin1, SIGNAL(valueChanged(int)), this, SLOT(changeSliderval()));
	connect(ui->vMin2, SIGNAL(valueChanged(int)), this, SLOT(changeSliderval()));
	connect(ui->vMin3, SIGNAL(valueChanged(int)), this, SLOT(changeSliderval()));
	connect(ui->vMin4, SIGNAL(valueChanged(int)), this, SLOT(changeSliderval()));
	connect(ui->vMin5, SIGNAL(valueChanged(int)), this, SLOT(changeSliderval()));

	connect(ui->vMax1, SIGNAL(valueChanged(int)), this, SLOT(changeSliderval()));
	connect(ui->vMax2, SIGNAL(valueChanged(int)), this, SLOT(changeSliderval()));
	connect(ui->vMax3, SIGNAL(valueChanged(int)), this, SLOT(changeSliderval()));
	connect(ui->vMax4, SIGNAL(valueChanged(int)), this, SLOT(changeSliderval()));
	connect(ui->vMax5, SIGNAL(valueChanged(int)), this, SLOT(changeSliderval()));

	connect(ui->erode1, SIGNAL(valueChanged(int)), this, SLOT(changeSliderval()));
	connect(ui->erode2, SIGNAL(valueChanged(int)), this, SLOT(changeSliderval()));
	connect(ui->erode3, SIGNAL(valueChanged(int)), this, SLOT(changeSliderval()));
	connect(ui->erode4, SIGNAL(valueChanged(int)), this, SLOT(changeSliderval()));
	connect(ui->erode5, SIGNAL(valueChanged(int)), this, SLOT(changeSliderval()));

	connect(ui->dilate1, SIGNAL(valueChanged(int)), this, SLOT(changeSliderval()));
	connect(ui->dilate2, SIGNAL(valueChanged(int)), this, SLOT(changeSliderval()));
	connect(ui->dilate3, SIGNAL(valueChanged(int)), this, SLOT(changeSliderval()));
	connect(ui->dilate4, SIGNAL(valueChanged(int)), this, SLOT(changeSliderval()));
	connect(ui->dilate5, SIGNAL(valueChanged(int)), this, SLOT(changeSliderval()));

	connect(ui->startButton, SIGNAL(clicked(bool)), this, SLOT(startCam()));
	connect(ui->stopButton, SIGNAL(ui->stopButton->cliced(bool)), this, SLOT(stopCam()));
}

void DECONBOTION2017::init() {
	// init all variable and all connection
	for (int i = 0; i < 5; i++) {
		hMin[i] = 0;
		sMin[i] = 0;
		vMin[i] = 0;
		hMax[i] = 255;
		vMax[i] = 255;
		sMax[i] = 255;
		erode[i] = 0;
		dilate[i] = 0;
	}
	camThread = new QThread();
	sendThread = new QThread();
	initConnection();
	ui->stackedWidget->setCurrentIndex(0);
}

DECONBOTION2017::DECONBOTION2017(QWidget *parent)
	: QMainWindow(parent), ui(new Ui::DECONBOTION2017Class)
{
	ui->setupUi(this);
	//ui.setupUi(this);
	init();
	
}
void DECONBOTION2017::changeSliderval() {
	// set value
	hMin[0] = ui->hMin1->value();

	// show value
	ui->hMinVal1->setText(QString::number(hMin[0]));
	
}

void DECONBOTION2017::startCam() {
	c
}


void DECONBOTION2017::stopCam( ) {

}