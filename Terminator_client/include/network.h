#pragma once
#include <QtCore/QObject>

class networkAPI: public QObject
{
	Q_OBJECT

public:
	networkAPI();
	~networkAPI();

	//check status
	bool IsSuccess();
	int StatusCode();
	QString StatusInfo();

	//user managment
	bool CheckLogin(QString username, QString password);
	bool CreateUser(QString username, QString password, QString newUsername, QString newPassword);
	//data managment
	QJsonArray GetData(QString username, QString password, QString listName, QString type);
	bool PutData(QString username, QString password, QString listName, QJsonArray data);
	bool PostData(QString username, QString password, QString listName, QJsonArray data);
	bool DelData(QString username, QString password, QString listName);
	//copy managment
	bool CopyData(QString username, QString password, QString listName, QString destUser);

private:
	int returnCode;
	bool isSuccess;
	
};

