#include "Progress.h"

Progress::Progress(QWidget *parent)
    : QDialog(parent)
{
    //ui.setupUi(this);
    display();
}

void Progress::display() {
    setWindowTitle("进度条");
    fileNum = new QLabel("文件数目");
    fileNumLineEdit = new QLineEdit;
    progressType = new QLabel("显示类型");
    comboBox = new QComboBox;
    comboBox->addItem("progreeBar");
    comboBox->addItem("progreeDialog");
    progreeBar = new QProgressBar;
    startBtn = new QPushButton("开始");
    mainLayout = new QGridLayout(this);
    mainLayout->addWidget(fileNum, 0, 0);
    mainLayout->addWidget(fileNumLineEdit, 0, 1);
    mainLayout->addWidget(progressType, 1, 0);
    mainLayout->addWidget(comboBox, 1, 1);
    mainLayout->addWidget(progreeBar, 2, 0, 1, 2);
    mainLayout->addWidget(startBtn, 3, 1);
    mainLayout->setMargin(10);
    mainLayout->setSpacing(10);
    connect(startBtn, SIGNAL(clicked()), this, SLOT(startProgress()));
}

void Progress::startProgress() {
    bool ok;
    int num = fileNumLineEdit->text().toInt(&ok);
    if (comboBox->currentIndex() == 0) {        //进度条
        progreeBar->setRange(0, num);
        for (int i = 0; i < num + 1; i++) {
            progreeBar->setValue(i);
        }
    }
    else if(comboBox->currentIndex() == 1){     //对话框
        QProgressDialog* progreeDialog = new QProgressDialog(this);
        progreeDialog->setWindowModality(Qt::WindowModal);
        progreeDialog->setMinimumDuration(5);
        progreeDialog->setWindowTitle("请等待");
        progreeDialog->setLabelText("复制中...");
        progreeDialog->setCancelButtonText("取消");
        progreeDialog->setRange(0, num);
        for (int i = 0; i < num + 1; i++) {
            progreeDialog->setValue(i);
            if (progreeDialog->wasCanceled()) {
                return;
            }
        }
    }
}
