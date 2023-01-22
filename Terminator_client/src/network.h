#pragma once
#include <QtCore/QObject>

class networkAPI: public QObject
{
	Q_OBJECT

public:
	networkAPI();
	~networkAPI();
	//user managment
	bool CheckLogin(QString username, QString password);
	bool CreateUser(QString username, QString password, QString newUsername, QString newPassword);
	//data managment
	QString GetData(QString username, QString password, QString listName, QString type);
	bool PutData(QString username, QString password, QString listName, QByteArray data);
	bool PostData(QString username, QString password, QString listName, QByteArray data);
	bool DelData(QString username, QString password, QString listName);
	//copy managment
	bool CopyData(QString username, QString password, QString listName, QString destUser);
private:
	
};

