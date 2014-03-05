#include "qtserverguiapp.h"
#include <QtGui/QApplication>
#include "myserver.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	qtserverguiapp w;
	MyServer Server;
	Server.StartServer();
	//w.show();
	return a.exec();
}
