#pragma once

#include <QtWidgets/QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QProgressBar>
#include <QComboBox>
#include <QPushButton>
#include <QGridLayout>
#include <QProgressDialog>
//#include "ui_Progress.h"
#ifdef WIN32
#pragma execution_character_set("utf-8")
#endif
class Progress : public QDialog
{
    Q_OBJECT

public:
    Progress(QWidget *parent = Q_NULLPTR);
    void display();
private slots:
    void startProgress();
private:
    //Ui::ProgressClass ui;
    QLabel* fileNum, * progressType;
    QLineEdit* fileNumLineEdit;
    QComboBox* comboBox;
    QPushButton* startBtn;
    QGridLayout* mainLayout;
    QProgressBar* progreeBar;
};
