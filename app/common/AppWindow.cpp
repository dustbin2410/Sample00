#include "utility/misc/StdMacro.h"
#include "utility/misc/MiscUtil.h"

#include "AppUtil.h"
#include "AppWindow.h"

AppWindow::AppWindow(QWidget *parent)
    : QMainWindow(parent)
{

}

AppWindow::~AppWindow()
{

}

void AppWindow::initWindow()
{
    setCentralWidget(m_Main);

    setWindowTitle(m_AppName.c_str());

    // Centralize the window
    QRect scrRect = QApplication::desktop()->screenGeometry();
    QRect appRect = rect();
    QPoint tmpPoint = scrRect.center() - appRect.center();
    move(tmpPoint.x()/2, tmpPoint.y()/2);

    // Maximize window:
    setWindowIcon(QIcon(m_IconName.c_str()));
}

string AppWindow::getAboutString() const
{
    return MiscUtil::GetAboutString(m_AppName);
}
