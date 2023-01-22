#include "network.h"

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

#include <QJsonObject>


networkAPI::networkAPI()
{

}

networkAPI::~networkAPI()
{

}

bool networkAPI::CheckLogin(QString username, QString password)
{
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

    //zwraca kod 
    QString status_code = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toString();
    
    if (status_code == "202")
    {
        return true;
    }
    else
    {
        return false;
    }   
}

bool networkAPI::CreateUser(QString username, QString password, QString newUsername, QString newPassword)
{
    QByteArray usernameByte = username.toUtf8();
    QByteArray passwordByte = password.toUtf8();
    QByteArray newUsernameByte = newUsername.toUtf8();
    QByteArray newPasswordByte = newPassword.toUtf8();

    QNetworkAccessManager* manager = new QNetworkAccessManager;
    QNetworkRequest request;
    QByteArray line;
    QEventLoop eventLoop;
    QByteArray data;

    request.setUrl(QUrl("http://192.168.219.132:8080/login"));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setRawHeader("LOGIN", usernameByte);
    request.setRawHeader("PASS", passwordByte);
    request.setRawHeader("newLOGIN", newUsernameByte);
    request.setRawHeader("newPASS", passwordByte);

    QNetworkReply* reply = manager->put(request, data);
    QObject::connect(manager, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));
    eventLoop.exec();

    QString status_code = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toString();

    if (status_code == "201")
    {
        return true;
    }
    else
    {
        return false;
    }
}
