#ifndef LOG_H
#define LOG_H

#include <memory>
#include <spdlog/spdlog.h>

namespace Trayracer2 {

class Log {
public:
	static void init();

	inline static std::shared_ptr<spdlog::logger>& getLogger() { return m_logger; }

private:
	static std::shared_ptr<spdlog::logger> m_logger;
};

}

#define LOG_TRACE(...) ::Trayracer2::Log::getLogger()->trace(__VA_ARGS__)
#define LOG_DEBUG(...) ::Trayracer2::Log::getLogger()->debug(__VA_ARGS__)
#define LOG_INFO(...)  ::Trayracer2::Log::getLogger()->info(__VA_ARGS__)
#define LOG_WARN(...)  ::Trayracer2::Log::getLogger()->warn(__VA_ARGS__)
#define LOG_ERROR(...) ::Trayracer2::Log::getLogger()->error(__VA_ARGS__)
#define LOG_CRIT(...)  ::Trayracer2::Log::getLogger()->critical(__VA_ARGS__)

#endif //LOG_H
