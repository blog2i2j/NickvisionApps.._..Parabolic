#include "application.h"
#include <QSysInfo>

using namespace Nickvision::TubeConverter::Shared::Controllers;

namespace Nickvision::TubeConverter::QT
{
    Application::Application(int argc, char* argv[])
        : QApplication{ argc, argv },
        m_controller{ std::make_shared<MainWindowController>(std::vector<std::string>(argv, argv + argc)) },
        m_mainWindow{ nullptr }
    {
        //Set Fusion style on Windows 10 for dark mode support
        if (QSysInfo::productType() == "windows" && QSysInfo::productVersion() == "10")
        {
            QApplication::setStyle("Fusion");
        }
    }

    int Application::exec()
    {
        m_controller->log(Logging::LogLevel::Info, "Started QT application.");
        m_mainWindow = std::make_shared<Views::MainWindow>(m_controller);
        m_mainWindow->show();
        return QApplication::exec();
    }
}