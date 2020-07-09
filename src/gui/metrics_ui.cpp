#include "metrics_ui.h"

#include <metrics_gui.h>
#include <imgui.h>

#include "core/core.h"

namespace Trayracer2 {

MetricsUI::MetricsUI()
{
    m_frameTimeMetric = createScope<MetricsGuiMetric>("Frame time:", "s",
                                                      MetricsGuiMetric::USE_SI_UNIT_PREFIX);
    m_frameTimeMetric->mSelected = true;
    m_frameTimeMetric->mColor[0] = 1.000f;
    m_frameTimeMetric->mColor[1] = 0.391f;
    m_frameTimeMetric->mColor[2] = 0.000f;
    m_frameTimeMetric->mColor[3] = 1.000f;

    m_plot = createScope<MetricsGuiPlot>();
    m_plot->AddMetric(m_frameTimeMetric.get());
}

void MetricsUI::show()
{
    m_frameTimeMetric->AddNewValue(1.0f / ImGui::GetIO().Framerate);
    m_plot->UpdateAxes();

    m_plot->mShowAverage = true;
    m_plot->mShowLegendAverage = true;
    m_plot->mPlotRowCount = 8;
    m_plot->mShowLegendColor = false;

    ImGui::Begin("Performance");
    m_plot->DrawHistory();
    ImGui::End();
}

}
