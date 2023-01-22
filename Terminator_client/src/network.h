#pragma once
#include <QtCore/QObject>

class networkAPI: public QObject
{
	Q_OBJECT

public:
	networkAPI();
	~networkAPI();
	 bool CheckLogin(QString username, QString password);
private:
	
};

