#include "Progress.h"

Progress::Progress(QWidget *parent)
    : QDialog(parent)
{
    //ui.setupUi(this);
    display();
}

void Progress::display() {
    setWindowTitle("������");
    fileNum = new QLabel("�ļ���Ŀ");
    fileNumLineEdit = new QLineEdit;
    progressType = new QLabel("��ʾ����");
    comboBox = new QComboBox;
    comboBox->addItem("progreeBar");
    comboBox->addItem("progreeDialog");
    progreeBar = new QProgressBar;
    startBtn = new QPushButton("��ʼ");
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
    if (comboBox->currentIndex() == 0) {        //������
        progreeBar->setRange(0, num);
        for (int i = 0; i < num + 1; i++) {
            progreeBar->setValue(i);
        }
    }
    else if(comboBox->currentIndex() == 1){     //�Ի���
        QProgressDialog* progreeDialog = new QProgressDialog(this);
        progreeDialog->setWindowModality(Qt::WindowModal);
        progreeDialog->setMinimumDuration(5);
        progreeDialog->setWindowTitle("��ȴ�");
        progreeDialog->setLabelText("������...");
        progreeDialog->setCancelButtonText("ȡ��");
        progreeDialog->setRange(0, num);
        for (int i = 0; i < num + 1; i++) {
            progreeDialog->setValue(i);
            if (progreeDialog->wasCanceled()) {
                return;
            }
        }
    }
}
