#ifndef APPWINDOW_H
#define APPWINDOW_H

#include "utility/gui/GuiUtil.h"
#include "utility/misc/StdHeader.h"
#include "utility/gui/QtGuiHeader.h"

class AppWindow : public QMainWindow
{
    Q_OBJECT
public:
    AppWindow(QWidget *parent = 0);
    ~AppWindow();

public:
    void buildView();
    void initWindow();
    virtual void initApplication() = 0;

public:
    string getAboutString() const;

public:
    QWidget* m_Main;

    string m_Version;
    string m_AppName;
    string m_IconName;
};

#endif // APPWINDOW_H
