#include "qtserverguiapp.h"

qtserverguiapp::qtserverguiapp(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	ui.setupUi(this);
}

qtserverguiapp::~qtserverguiapp()
{

}
