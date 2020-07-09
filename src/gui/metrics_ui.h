#ifndef METRICS_UI_H
#define METRICS_UI_H

#include <metrics_gui.h>

#include "core/core.h"

namespace Trayracer2 {

class MetricsUI {
public:
    MetricsUI();

    void show();

private:
    Scope<MetricsGuiMetric> m_frameTimeMetric;
    Scope<MetricsGuiPlot> m_plot;
};

}

#endif //METRICS_UI_H
