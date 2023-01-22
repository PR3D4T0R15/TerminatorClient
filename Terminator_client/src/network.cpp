#include "network.h"

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

network::network()
{

}

network::~network()
{

}

bool network::CheckLogin(QString username, QString password)
{
    QNetworkAccessManager* manager = new QNetworkAccessManager;
    QNetworkRequest request;
    QByteArray line;
    QByteArray status;
    QEventLoop eventLoop;

    QByteArray username = useraname;
    QByteArray password = password;

    request.setUrl(QUrl("http://192.168.219.132:8080/login"));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setHeader("LOGIN", username);
    request.setHeader("PASS", password);
    QNetworkReply* reply = manager->get(request);
    QObject::connect(manager, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));
    eventLoop.exec();
    line = reply->readAll();
    status = reply->attribute(QNetworkRequest::HttpReasonPhraseAttribute);

    qDebug() << "status: " << status;
    qDebug() << "response:" << line;
}
