#include "DECONBOTION2017.h"

using namespace std;

void DECONBOTION2017::initConnection() {
	// connection to show hsv
	connect(ui->warnaSelector, SIGNAL(currentIndexChanged(int)), this, SLOT(changeViewWarna()));
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

	// show speed change
	connect(ui->speedSlider, SIGNAL(valueChange(int)), this, SLOT(changeSliderval()));
	
	// save and load hsv connection
	connect(ui->actionSave, SIGNAL(triggered(bool)), this, SLOT(on_save()));
	connect(ui->actionSave_As, SIGNAL(triggered(bool)), this, SLOT(on_save_as()));
	connect(ui->actionOpen, SIGNAL(triggered(bool)), this, SLOT(on_load()));
	connect(this, SIGNAL(updateHSV()), this, SLOT(loadHSV()));

	// camera thread connection
	connect(camThread, SIGNAL(started()), cam, SLOT(openCamera()));
	connect(ui->startButton, SIGNAL(clicked(bool)), this, SLOT(startCam()));
	connect(ui->stopButton, SIGNAL(clicked(bool)), this, SLOT(stopCam()));
	connect(cam, SIGNAL(sendImage()), this, SLOT(updateLabel()));
	connect(this, SIGNAL(sendHSV(int, int, int, int, int, int, int, int, int)), cam, SLOT(receiveHSV(int, int, int, int, int, int, int, int, int)), Qt::DirectConnection);
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
	cam = new ImgProc();
	cam->moveToThread(camThread);
	initConnection();
	
	
	
	ui->stackedWidget->setCurrentIndex(0);
}

DECONBOTION2017::DECONBOTION2017(QWidget *parent)
	: QMainWindow(parent), ui(new Ui::DECONBOTION2017Class){
	ui->setupUi(this);
	//ui.setupUi(this);
	init();
	
}

DECONBOTION2017::~DECONBOTION2017() {
	stopCam();
	delete camThread;
	delete sendThread;
	delete cam;
	delete ui;
}

void DECONBOTION2017::startCam() {
	// starting camera
	cam->status = true;
	if (!camThread->isRunning())camThread->start();
	ui->startButton->setEnabled(false);
	ui->stopButton->setEnabled(true);
}


void DECONBOTION2017::stopCam( ) {
	// stopping camera
	cam->status = false;
	camThread->wait(100);
	if (camThread->isRunning())camThread->quit();
	ui->startButton->setEnabled(true);
	ui->stopButton->setEnabled(false);
	ui->labelOri->clear();
	ui->labelWarna1->clear();
	ui->labelWarna2->clear();
	ui->labelWarna3->clear();
	ui->labelWarna4->clear();
	ui->labelWarna5->clear();
}

void DECONBOTION2017::updateLabel() {
	// update label view
	ui->labelOri->setPixmap(QPixmap::fromImage(cam->imgOri));
	ui->labelWarna1->setPixmap(QPixmap::fromImage(cam->imgWarna[0]));
	ui->labelWarna2->setPixmap(QPixmap::fromImage(cam->imgWarna[1]));
	ui->labelWarna3->setPixmap(QPixmap::fromImage(cam->imgWarna[2]));
	ui->labelWarna4->setPixmap(QPixmap::fromImage(cam->imgWarna[3]));
	ui->labelWarna5->setPixmap(QPixmap::fromImage(cam->imgWarna[4]));
	qDebug() << "Update cong";
	//qDebug() << cam->imgWarna[0];
}

void DECONBOTION2017::on_save() {
	if (fileName.isEmpty()) {
		fileName = QFileDialog::getSaveFileName(this,
			tr("Save HSV"), "", tr("CSV (*.csv);;Text (*.txt);;ALL File(*.)"));
	}
	if (fileName.isEmpty()) {
		return;
	}
	else {
		QFile file(fileName);
		// cek apa file kebacasss
		if (!file.open(QIODevice::ReadWrite)) {
			QMessageBox::information(this, tr("Tidak bisa membuka file"), file.errorString());
			return;
		}
		QTextStream out(&file);
		QString buff = "", delim = ",";
		for (int i = 0; i < 5; i++) {
			buff += QString::number(hMin[i]);
			buff += delim;
			buff += QString::number(sMin[i]);
			buff += delim;
			buff += QString::number(vMin[i]);
			buff += delim;
			buff += QString::number(hMax[i]);
			buff += delim;
			buff += QString::number(sMax[i]);
			buff += delim;
			buff += QString::number(vMax[i]);
			buff += delim;
			buff += QString::number(erode[i]);
			buff += delim;
			buff += QString::number(dilate[i]);
			buff += "\n";
		}

		out << buff;
	}
}

void DECONBOTION2017::on_save_as() {
	fileName = QFileDialog::getSaveFileName(this,
		tr("Save HSV"), "", tr("CSV (*.csv);;Text (*.txt);;ALL File(*.)"));
	on_save();
}

void DECONBOTION2017::on_load() {
	QString buffer;
	fileName = QFileDialog::getOpenFileName(this,
		tr("Load HSV"), "", tr("CSV (*.csv);;Text (*.txt);;ALL File(*.)"));
	if (fileName.isEmpty()) {
		//qDebug() << "kok empty??";
		return;
	}
	else {
		QFile file(fileName);
		if (!file.open(QIODevice::ReadWrite)) {
			QMessageBox::information(this, tr("Tidak bisa memuat file."), file.errorString());
			return;
		}
		QTextStream in(&file);
		for (int i = 0; i < 5; i++) {
			in >> buffer;
			//qDebug() << "Buffer: " << buffer;

			QStringList wordList = buffer.split(",");
			//qDebug() << wordList;
			hMin[i] = wordList[0].toInt();
			sMin[i] = wordList[1].toInt();
			vMin[i] = wordList[2].toInt();
			hMax[i] = wordList[3].toInt();
			sMax[i] = wordList[4].toInt();
			vMax[i] = wordList[5].toInt();
			erode[i] = wordList[6].toInt();
			dilate[i] = wordList[7].toInt();
			
		}
		emit updateHSV();
		
	}
}

void DECONBOTION2017::changeSliderval() {
	// send hsv value to image processing thread
	emit sendHSV(
		ui->hMin1->value(),
		ui->sMin1->value(),
		ui->vMin1->value(),
		ui->hMax1->value(),
		ui->sMax1->value(),
		ui->vMax1->value(),
		ui->erode1->value(),
		ui->dilate1->value(),
		0
	);
	emit sendHSV(
		ui->hMin2->value(),
		ui->sMin2->value(),
		ui->vMin2->value(),
		ui->hMax2->value(),
		ui->sMax2->value(),
		ui->vMax2->value(),
		ui->erode2->value(),
		ui->dilate2->value(),
		1
	);
	emit sendHSV(
		ui->hMin3->value(),
		ui->sMin3->value(),
		ui->vMin3->value(),
		ui->hMax3->value(),
		ui->sMax3->value(),
		ui->vMax3->value(),
		ui->erode3->value(),
		ui->dilate3->value(),
		2
	);
	emit sendHSV(
		ui->hMin4->value(),
		ui->sMin4->value(),
		ui->vMin4->value(),
		ui->hMax4->value(),
		ui->sMax4->value(),
		ui->vMax4->value(),
		ui->erode4->value(),
		ui->dilate4->value(),
		3
	);
	emit sendHSV(
		ui->hMin5->value(),
		ui->sMin5->value(),
		ui->vMin5->value(),
		ui->hMax5->value(),
		ui->sMax5->value(),
		ui->vMax5->value(),
		ui->erode5->value(),
		ui->dilate5->value(),
		4
	);
	// show min value
	ui->hMinVal1->setText(QString::number(ui->hMin1->value()));
	ui->hMinVal2->setText(QString::number(ui->hMin2->value()));
	ui->hMinVal3->setText(QString::number(ui->hMin3->value()));
	ui->hMinVal4->setText(QString::number(ui->hMin4->value()));
	ui->hMinVal5->setText(QString::number(ui->hMin5->value()));

	ui->sMinVal1->setText(QString::number(ui->sMin1->value()));
	ui->sMinVal2->setText(QString::number(ui->sMin2->value()));
	ui->sMinVal3->setText(QString::number(ui->sMin3->value()));
	ui->sMinVal4->setText(QString::number(ui->sMin4->value()));
	ui->sMinVal5->setText(QString::number(ui->sMin5->value()));

	ui->vMinVal1->setText(QString::number(ui->vMin1->value()));
	ui->vMinVal2->setText(QString::number(ui->vMin2->value()));
	ui->vMinVal3->setText(QString::number(ui->vMin3->value()));
	ui->vMinVal4->setText(QString::number(ui->vMin4->value()));
	ui->vMinVal5->setText(QString::number(ui->vMin5->value()));

	// show max value
	ui->hMaxVal1->setText(QString::number(ui->hMax1->value()));
	ui->hMaxVal2->setText(QString::number(ui->hMax2->value()));
	ui->hMaxVal3->setText(QString::number(ui->hMax3->value()));
	ui->hMaxVal4->setText(QString::number(ui->hMax4->value()));
	ui->hMaxVal5->setText(QString::number(ui->hMax5->value()));

	ui->sMaxVal1->setText(QString::number(ui->sMax1->value()));
	ui->sMaxVal2->setText(QString::number(ui->sMax2->value()));
	ui->sMaxVal3->setText(QString::number(ui->sMax3->value()));
	ui->sMaxVal4->setText(QString::number(ui->sMax4->value()));
	ui->sMaxVal5->setText(QString::number(ui->sMax5->value()));

	ui->vMaxVal1->setText(QString::number(ui->vMax1->value()));
	ui->vMaxVal2->setText(QString::number(ui->vMax2->value()));
	ui->vMaxVal3->setText(QString::number(ui->vMax3->value()));
	ui->vMaxVal4->setText(QString::number(ui->vMax4->value()));
	ui->vMaxVal5->setText(QString::number(ui->vMax5->value()));

	ui->dilateVal1->setText(QString::number(ui->dilate1->value()));
	ui->dilateVal2->setText(QString::number(ui->dilate2->value()));
	ui->dilateVal3->setText(QString::number(ui->dilate3->value()));
	ui->dilateVal4->setText(QString::number(ui->dilate4->value()));
	ui->dilateVal5->setText(QString::number(ui->dilate5->value()));

	ui->erodeVal1->setText(QString::number(ui->erode1->value()));
	ui->erodeVal2->setText(QString::number(ui->erode2->value()));
	ui->erodeVal3->setText(QString::number(ui->erode3->value()));
	ui->erodeVal4->setText(QString::number(ui->erode4->value()));
	ui->erodeVal5->setText(QString::number(ui->erode5->value()));

	// change value
	hMin[0] = ui->hMin1->value();
	hMin[1] = ui->hMin2->value();
	hMin[2] = ui->hMin3->value();
	hMin[3] = ui->hMin4->value();
	hMin[4] = ui->hMin5->value();

	sMin[0] = ui->sMin1->value();
	sMin[1] = ui->sMin2->value();
	sMin[2] = ui->sMin3->value();
	sMin[3] = ui->sMin4->value();
	sMin[4] = ui->sMin5->value();

	vMin[0] = ui->vMin1->value();
	vMin[1] = ui->vMin2->value();
	vMin[2] = ui->vMin3->value();
	vMin[3] = ui->vMin4->value();
	vMin[4] = ui->vMin5->value();

	hMax[0] = ui->hMax1->value();
	hMax[1] = ui->hMax2->value();
	hMax[2] = ui->hMax3->value();
	hMax[3] = ui->hMax4->value();
	hMax[4] = ui->hMax5->value();

	sMax[0] = ui->sMax1->value();
	sMax[1] = ui->sMax2->value();
	sMax[2] = ui->sMax3->value();
	sMax[3] = ui->sMax4->value();
	sMax[4] = ui->sMax5->value();

	vMax[0] = ui->vMax1->value();
	vMax[1] = ui->vMax2->value();
	vMax[2] = ui->vMax3->value();
	vMax[3] = ui->vMax4->value();
	vMax[4] = ui->vMax5->value();

	dilate[0] = ui->dilate1->value();
	dilate[1] = ui->dilate2->value();
	dilate[2] = ui->dilate3->value();
	dilate[3] = ui->dilate4->value();
	dilate[4] = ui->dilate5->value();

	erode[0] = ui->erode1->value();
	erode[1] = ui->erode2->value();
	erode[2] = ui->erode3->value();
	erode[3] = ui->erode4->value();
	erode[4] = ui->erode5->value();

	// update speed view
	speed = ui->speedSlider->value();
	ui->speedVal->setText(QString::number(speed));
}

void DECONBOTION2017::loadHSV() {
	ui->dilateVal1->setText(QString::number(dilate[0]));
	ui->dilate1->setValue(dilate[0]);
	ui->dilateVal2->setText(QString::number(dilate[1]));
	ui->dilateVal3->setText(QString::number(dilate[2]));
	ui->dilateVal4->setText(QString::number(dilate[3]));
	ui->dilateVal5->setText(QString::number(dilate[4]));

	//ui->erodeVal1->setText(QString::number)
}

void DECONBOTION2017::changeViewWarna() {
	ui->stackedWidget->setCurrentIndex(ui->warnaSelector->currentIndex());
}