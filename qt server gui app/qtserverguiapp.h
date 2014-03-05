#ifndef QTSERVERGUIAPP_H
#define QTSERVERGUIAPP_H

#include <QtGui/QMainWindow>
#include "ui_qtserverguiapp.h"

class qtserverguiapp : public QMainWindow
{
	Q_OBJECT

public:
	qtserverguiapp(QWidget *parent = 0, Qt::WFlags flags = 0);
	~qtserverguiapp();

private:
	Ui::qtserverguiappClass ui;
};

#endif // QTSERVERGUIAPP_H
