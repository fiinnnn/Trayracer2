#include "core.h"
#include "core/application.h"

int main()
{
    Trayracer2::Log::init();

    auto* app = new Trayracer2::Application();
    app->run();
    delete app;

    LOG_INFO("Trayracer2 terminated");

    return 0;
}
