#include "gui.h"

#include "dockspace.h"
#include "menu_bar.h"
#include "viewport.h"
#include "settings_ui.h"

namespace Trayracer2 {

void GUI::show(Raytracer& raytracer)
{
    Dockspace::show();

    MenuBar::show();

    Viewport::show(raytracer);

    m_sceneui.show(raytracer.getScene());

    m_metricsui.show();

    SettingsUI::show();
}

}
