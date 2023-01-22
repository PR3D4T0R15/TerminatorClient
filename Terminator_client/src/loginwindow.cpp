#include "loginwindow.h"
#include "network.h"
#include "ui_loginwindow.h"

#include <QtCore/QCoreApplication>
#include <QString>
#include<QNetworkAccessManager>
#include<QNetworkRequest>
#include<QNetworkReply>
#include<QJsonObject>
#include<QJsonDocument>
#include<QNetworkAccessManager>
#include<iostream>
#include<QDebug>
#include<QEventLoop>
#include<QObject>
#include <QJsonArray>

loginWindow::loginWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::loginWindow)
{
    ui->setupUi(this);
    QPixmap pix(":/Terminator_client/src/img/logo.png");
    ui->label_img->setPixmap(pix);
    ui->label_img->setScaledContents(true);
}

loginWindow::~loginWindow()
{
    delete ui;
}

void loginWindow::on_pushButton_login_clicked()
{
    QString username = ui->lineEdit_login->text();
    QString password = ui->lineEdit_pass->text();

    QByteArray usernameByte = username.toUtf8();
    QByteArray passwordByte = password.toUtf8();

    QNetworkAccessManager* manager = new QNetworkAccessManager;
    QNetworkRequest request;
    QByteArray line;
    QEventLoop eventLoop;

    request.setUrl(QUrl("http://192.168.219.132:8080/login"));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setRawHeader("LOGIN", usernameByte);
    request.setRawHeader("PASS", passwordByte);

    QNetworkReply* reply = manager->get(request);
    QObject::connect(manager, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));
    eventLoop.exec();

    QString reason = reply->attribute(QNetworkRequest::HttpReasonPhraseAttribute).toString();
    qDebug() << reason;
    line = reply->readAll();
    qDebug() << "response:" << line;

    if (reason == "ACCEPTED")
    {
        qDebug() << "trueeeee";
    }
}

