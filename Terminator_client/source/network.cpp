#include "network.h"

#include <QString>
#include<QNetworkAccessManager>
#include<QNetworkRequest>
#include<QNetworkReply>
#include<QJsonObject>
#include<QJsonDocument>
#include<iostream>
#include<QDebug>
#include<QEventLoop>
#include<QObject>
#include <QUrlQuery>

#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>

networkAPI::networkAPI()
{
    returnCode = 0;
    isSuccess = false;
}

networkAPI::~networkAPI()
{

}

bool networkAPI::IsSuccess()
{
    return isSuccess;
}

int networkAPI::StatusCode()
{
    return returnCode;
}

QString networkAPI::StatusInfo()
{
    switch (returnCode)
    {
    case 200:
        return "OK";
        break;
    case 201:
        return "Created";
        break;
    case 202:
        return "Accepted";
        break;
    default:
        return "Error receiving return code ";
        break;
    }
}


//check if login and password are correct
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

//create a new user from given newusername and newpassword
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
    request.setRawHeader("newPASS", newPasswordByte);

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

//get data from server in json form
QJsonArray networkAPI::GetData(QString username, QString password, QString listName, QString type)
{
    QByteArray usernameByte = username.toUtf8();
    QByteArray passwordByte = password.toUtf8();
    QByteArray listNameByte = listName.toUtf8();

    QNetworkAccessManager* manager = new QNetworkAccessManager;
    QNetworkRequest request;
    QByteArray line;
    QEventLoop eventLoop;

    QUrl url("http://192.168.219.132:8080/data");
    QUrlQuery query;
    query.addQueryItem("type", type);
    url.setQuery(query.query());

    request.setUrl(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setRawHeader("LOGIN", usernameByte);
    request.setRawHeader("PASS", passwordByte);
    request.setRawHeader("LISTNAME", listNameByte);

    QNetworkReply* reply = manager->get(request);
    QObject::connect(manager, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));
    eventLoop.exec();

    QString status_code = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toString();

    line = reply->readAll();

    QJsonDocument output = QJsonDocument::fromJson(line);
    QJsonArray array = output.array();

    return array;
    
}

//create data on server from given json
bool networkAPI::PutData(QString username, QString password, QString listName, QJsonArray data)
{
    QJsonDocument jsonData = QJsonDocument(data);
    QByteArray jsonBIN = jsonData.toJson(QJsonDocument::Compact);

    QByteArray usernameByte = username.toUtf8();
    QByteArray passwordByte = password.toUtf8();
    QByteArray listNameByte = listName.toUtf8();

    QNetworkAccessManager* manager = new QNetworkAccessManager;
    QNetworkRequest request;
    QByteArray line;
    QEventLoop eventLoop;

    QUrl url("http://192.168.219.132:8080/data");
    
    request.setUrl(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setRawHeader("LOGIN", usernameByte);
    request.setRawHeader("PASS", passwordByte);
    request.setRawHeader("LISTNAME", listNameByte);

    QNetworkReply* reply = manager->put(request, jsonBIN);
    QObject::connect(manager, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));
    eventLoop.exec();

    QString status_code = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toString();

    line = reply->readAll();

    if (status_code == "200")
    {
        return true;
    }

    return false;
}

//update json filed in database
bool networkAPI::PostData(QString username, QString password, QString listName, QJsonArray data)
{
    QJsonDocument jsonData = QJsonDocument(data);
    QByteArray jsonBIN = jsonData.toJson(QJsonDocument::Compact);

    QByteArray usernameByte = username.toUtf8();
    QByteArray passwordByte = password.toUtf8();
    QByteArray listNameByte = listName.toUtf8();

    QNetworkAccessManager* manager = new QNetworkAccessManager;
    QNetworkRequest request;
    QByteArray line;
    QEventLoop eventLoop;

    QUrl url("http://192.168.219.132:8080/data");

    request.setUrl(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setRawHeader("LOGIN", usernameByte);
    request.setRawHeader("PASS", passwordByte);
    request.setRawHeader("LISTNAME", listNameByte);

    QNetworkReply* reply = manager->post(request, jsonBIN);
    QObject::connect(manager, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));
    eventLoop.exec();

    QString status_code = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toString();

    line = reply->readAll();

    if (status_code == "200")
    {
        return true;
    }

    return false;
}

//delete selected data by name
bool networkAPI::DelData(QString username, QString password, QString listName)
{
    QByteArray usernameByte = username.toUtf8();
    QByteArray passwordByte = password.toUtf8();
    QByteArray listNameByte = listName.toUtf8();

    QNetworkAccessManager* manager = new QNetworkAccessManager;
    QNetworkRequest request;
    QByteArray line;
    QEventLoop eventLoop;

    request.setUrl(QUrl("http://192.168.219.132:8080/data"));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setRawHeader("LOGIN", usernameByte);
    request.setRawHeader("PASS", passwordByte);
    request.setRawHeader("LISTNAME", listNameByte);

    QNetworkReply* reply = manager->deleteResource(request);
    QObject::connect(manager, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));
    eventLoop.exec();

    //zwraca kod 
    QString status_code = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toString();

    if (status_code == "200")
    {
        return true;
    }
    else
    {
        return false;
    }
}


//copy data to be accessible to another user
bool networkAPI::CopyData(QString username, QString password, QString listName, QString destUser)
{
    QByteArray usernameByte = username.toUtf8();
    QByteArray passwordByte = password.toUtf8();
    QByteArray listNameByte = listName.toUtf8();
    QByteArray destUserByte = destUser.toUtf8();

    QNetworkAccessManager* manager = new QNetworkAccessManager;
    QNetworkRequest request;
    QByteArray line;
    QEventLoop eventLoop;
    QByteArray data;

    request.setUrl(QUrl("http://192.168.219.132:8080/datamove"));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setRawHeader("LOGIN", usernameByte);
    request.setRawHeader("PASS", passwordByte);
    request.setRawHeader("LISTNAME", listNameByte);
    request.setRawHeader("DESTUSER", destUserByte);

    QNetworkReply* reply = manager->put(request, data);
    QObject::connect(manager, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));
    eventLoop.exec();

    //zwraca kod 
    QString status_code = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toString();

    if (status_code == "200")
    {
        return true;
    }
    else
    {
        return false;
    }
}
