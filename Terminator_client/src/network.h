#pragma once
#include <QMainWindow>

class network
{
	Q_OBJECT

public:
	 bool CheckLogin(QString username, QString password);
private:
	QString url;
};

