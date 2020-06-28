#include "log.h"

#include <spdlog/sinks/stdout_color_sinks.h>

namespace Trayracer2 {

std::shared_ptr<spdlog::logger> Log::m_logger;

void Log::init()
{
    spdlog::set_pattern("%^[%T] [%n|%l] %v%$");

    m_logger = spdlog::stdout_color_mt("TRAYRACER2");
    m_logger->set_level(spdlog::level::trace);

    LOG_INFO("Logging initialized");
}

}
