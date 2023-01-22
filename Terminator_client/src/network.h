#pragma once
#include <QtCore/QObject>

class networkAPI: public QObject
{
	Q_OBJECT

public:
	networkAPI();
	~networkAPI();
	 bool CheckLogin(QString username, QString password);
	 bool CreateUser(QString username, QString password, QString newUsername, QString newPassword);
	 QString GetData(QString username, QString password, QString listName, QString type);
	 bool PutData(QString login, QString password, QString listName, QJsonObject data);
	 bool DelData(QString login, QString password, QString listName);
	 bool CopyData(QString login, QString password, QString listName, QString destUser);
private:
	
};

