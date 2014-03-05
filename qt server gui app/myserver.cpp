#include "myserver.h"

MyServer::MyServer(QObject *parent) :
QTcpServer(parent)
{
}

void MyServer::StartServer()
{
	if(!this->listen(QHostAddress::Any,80))
	{
		qDebug()<<"could not start server";
	}
	else
	{
		qDebug()<<"listening...";
	}

}
void MyServer::incomingConnection(int socketDescriptor)
{
	qDebug()<<socketDescriptor<<"connecting....";
	MyThread *thread = new MyThread(socketDescriptor,this);
	connect(thread,SIGNAL(finished()),thread,SLOT(deleteLater()));

	thread->start();
}
