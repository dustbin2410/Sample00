#include "utility/misc/StringUtil.h"
#include "utility/misc/QtCoreHeader.h"

#include "BaseAppData.h"

void sBaseAppData::load()
{
    
}

void sBaseAppData::save()
{
    
}

void sBaseAppData::reset()
{
    
}

sBaseAppConfig::sBaseAppConfig()
{
    reset();
}

void sBaseAppConfig::reset()
{
    CompanyName = "Virtium";
    ApplicationName = "vtToolSet";
    License = pair<string, bool>("key_vtlicense", false);
}

void sBaseAppConfig::load(QSettings& setting)
{
    reset();
    
    QString key;
    
    key = QString(License.first.c_str());
    if(true == setting.contains(key))
    {
        License.second = setting.value(key).toBool();
    }
}

void sBaseAppConfig::save(QSettings& setting)
{
    setting.setValue(License.first.c_str(), License.second);
}

void sBaseAppConfig::setApplicationInfo(const string& comname, const string& appname)
{
    CompanyName = comname;
    ApplicationName = appname;
}

void sApplicationData::setApplicationInfo(sBaseAppConfig* appconf, sBaseAppData* appdata)
{
    Data = appdata;
    Config = appconf;
}

void sApplicationData::loadData()
{
    Data->load();
}

void sApplicationData::saveData()
{
    Data->save();
}

void sApplicationData::loadConfig()
{
    QSettings setting(Config->CompanyName.c_str(), Config->ApplicationName.c_str());
    setting.beginGroup("Config");
    Config->load(setting);
    setting.endGroup();
}

void sApplicationData::saveConfig()
{
    QSettings setting(Config->CompanyName.c_str(), Config->ApplicationName.c_str());
    setting.beginGroup("Config");
    Config->save(setting);
    setting.endGroup();
}

void sApplicationData::load()
{
    loadConfig();
    loadData();
}

void sApplicationData::save()
{
    saveData();
    saveConfig();
}

void sApplicationData::reset()
{
    Data->reset();
    Config->reset();
    
    loadConfig(); // Config is alway ready
}

static string GetBaseApplicationInfo()
{
    string info = "DreamBigSemi Base Application Info String";

    return info;
}