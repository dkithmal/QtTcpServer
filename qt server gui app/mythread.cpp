#include "mythread.h"
#include "ftplistitem.h"

MyThread::MyThread(int ID,QObject *parent) :
QThread(parent)
{
	this->socketDescriptor = ID;
}

void MyThread::run()
{
	//thered start hear
	qDebug()<<socketDescriptor<<"starting therad";
	socket = new QTcpSocket();
	if(!socket->setSocketDescriptor(this->socketDescriptor))
	{
		emit error(socket->error());
		return;
	}

	connect(socket,SIGNAL(readyRead()),this,SLOT(readyRead()),Qt::DirectConnection);
	connect(socket,SIGNAL(disconnected()),this,SLOT(disconnected()),Qt::DirectConnection);
	connect(socket,SIGNAL(bytesWritten(qint64)),this,SLOT(bytesWritten(qint64)),Qt::DirectConnection);
	qDebug()<<socketDescriptor<<"clianat connected";

	exec();
}


void MyThread::readyRead()
{
	//Append to the command buffer
	mCommandBuffer.append(socket->readAll());
	qDebug()<<mCommandBuffer;
	//mSocket->write("dddd");

	//qDebug()<<mCommandBuffer;
	//Check to see if it is the end of line
	if(mCommandBuffer.endsWith('\n'))
	{
		ProcessCommand(mCommandBuffer);
		mCommandBuffer.clear();
	}
	//   QByteArray Data = socket->readAll();
	//if(Data=="USER")
	//{
	//	qDebug()<<"user command";
	//}
	//   qDebug()<<socketDescriptor<<"Data in:"<<Data;   
	//   socket->write(Data);
}


void MyThread::disconnected()
{
	qDebug()<<socketDescriptor<<"Disconnected";
	socket->deleteLater();
	exit(0);

}
void MyThread::ProcessCommand(QString ClientCommand)
{
	QStringList Commands = ClientCommand.split("\n");

	foreach(QString Command, Commands)
	{
		QString ClientCommand = Command.trimmed();
		if(ClientCommand != "")
		{
			//Execute the command
			ExecuteCommand(ClientCommand);
		}
	}
}
void MyThread::bytesWritten(qint64 bytes)
{
	qDebug()<<bytes;
}
void MyThread::ExecuteCommand(QString ClientCommand)
{
	QString Command = "";
	QString Arg = "";

	if(ClientCommand.contains(" "))
	{
		//Contains arquments
		int pos = ClientCommand.indexOf(" ");
		Command = ClientCommand.mid(0,pos).trimmed();
		Arg = ClientCommand.mid(pos + 1).trimmed();
	}
	else
	{
		//No arquments
		Command = ClientCommand.trimmed();
	}

	qDebug() << "Client: " << Command << " " << Arg;

	//QMetaObject metaObject = this->staticMetaObject;
	//QMetaEnum metaEnum = metaObject.enumerator(metaObject.indexOfEnumerator("RequestCommands"));
	//qDebug()<<metaEnum.keysToValue(Command.toUpper().toAscii());


	//switch(metaEnum.keysToValue(Command.toUpper().toAscii()))
	//{
	//case LIST: // List a directory
	//	DoLIST(Arg);
	//	break;
	//}
	if (Command=="LIST")
	{

		DoLIST(Arg);
	}
	else if (Command=="RETR")
	{

		DoRETR(Arg);

	}
}

void MyThread::DoLIST(QString Arg)
{

	QString path ="D:/Dawnload";
	if (Arg=="")
	{
		qDebug()<<"its here";
		ListFile(path);
	}
	else
	{
		ListFile(Arg);

	}



}
void MyThread::DoRETR(QString Arg)
{
	//MessageBoxA(0,"its here","eee",0);
	QFileInfo fi(Arg);

	if(!fi.exists())
	{
		//qDebug()<<"its here"<<Path;
		//Not found
		//emit OnError("Directory not found");
	}
	else
	{
		mydownwork(1);
		//Found
		if(fi.isDir())
		{
			QDir dir(Arg);

			//list a directory
			//qDebug() << "LIST SEND DIRECTORY";
			foreach(QFileInfo item, dir.entryInfoList())
			{
				//FTPListItem ftpList;
				//SendResponse(ftpList.Convert(item));

				//mSocket->waitForBytesWritten();
			}
			//myworksssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss

			//emit OnFinished();
		}
		else
		{

			//list a single file
			qDebug() << "LIST SEND FILE";
			QFile file(Arg);
			file.open(QIODevice::ReadOnly);
			while (!file.atEnd()) 
			{
				QByteArray buffer = file.read(1024 * 8);
				socket->write(buffer);
				socket->waitForBytesWritten(5000);
			}
			file.close();
			//QByteArray tosend=file.readAll();
			//qDebug()<<tosend.length();
			//socket->write(tosend);
			//socket->waitForBytesWritten(50000);

			//FTPListItem ftpList;
			//SendResponse(ftpList.Convert(fi));
			//emit OnFinished();
		}
		mydownwork(2);
	}


}

void MyThread::ListFile(QString Path)
{

	QFileInfo fi(Path);

	if(!fi.exists())
	{
		//qDebug()<<"its here"<<Path;
		//Not found
		//emit OnError("Directory not found");
	}
	else
	{
		mywork(1);
		//Found
		if(fi.isDir())
		{
			QDir dir(Path);

			//list a directory
			qDebug() << "LIST SEND DIRECTORY";
			foreach(QFileInfo item, dir.entryInfoList())
			{
				FTPListItem ftpList;
				SendResponse(ftpList.Convert(item));

				//mSocket->waitForBytesWritten();
			}
			//myworksssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss

			//emit OnFinished();
		}
		else
		{
			//list a single file
			qDebug() << "LIST SEND FILE";
			FTPListItem ftpList;
			SendResponse(ftpList.Convert(fi));
			//emit OnFinished();
		}
		mywork(2);
	}


}
void MyThread::SendResponse(QString data)
{


	QByteArray datasend;
	datasend = data.toAscii();
	//socket->write("start");
	socket->write(datasend);
}



void MyThread::Tofilelist()
{
	qDebug()<<"hehe";
	socket->write("its here");
}


void MyThread::mywork(int info)
{
	if(info==1)
	{
		socket->write("start\n");

	}
	else
	{
		socket->write("finish");

	}

}
void MyThread::mydownwork(int info)
{
	if(info==1)
	{
		socket->write("downstart");

	}
	else
	{
		socket->write("finishdown");

	}

}