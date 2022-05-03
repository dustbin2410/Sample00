#ifndef BASEAPPDATA_H
#define BASEAPPDATA_H

#include "utility/misc/StdHeader.h"
#include "utility/misc/AppLogger.h"
#include "utility/misc/QtCoreHeader.h"

struct sBaseAppData
{
    virtual void load();
    virtual void save();
    virtual void reset();
};

struct sBaseAppConfig
{
    string CompanyName;
    string ApplicationName;
    pair<string, bool>   License;     // Key/Value pair (key in QSetting)

    sBaseAppConfig();
    void setApplicationInfo(const string& comname, const string& appname);

    virtual void load(QSettings&);
    virtual void save(QSettings&);
    virtual void reset();
};

struct sApplicationData
{
    sBaseAppData* Data;
    sBaseAppConfig* Config;
    
    void load();
    void save();
    void reset();
    void loadData();
    void saveData();
    void loadConfig();
    void saveConfig();
    void setApplicationInfo(sBaseAppConfig*, sBaseAppData*);
};

class sAppData;
class sAppConfig;

extern AppLogger Logger;
extern sApplicationData AppData;

AppLogger* GetLoggerPtr();
sAppData* GetAppDataPtr();
sAppConfig* GetAppConfigPtr();
sApplicationData* GetApplicationDataPtr();

void LoadCoreData();
void RequestLicenseAgreement();
void InitLogger(const string& logName);
void InitModules();

#endif // BASEAPPDATA_H
