#pragma once

#include <QString>

namespace spritelauncher {

//< Utility header

class FileFunctions
{
public:
    static void init();
    static QString appDir();

private:
    inline static QString m_app_dir;
};

} // namespace spritelauncher
