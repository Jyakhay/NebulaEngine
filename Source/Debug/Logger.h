#pragma once

#include "Utilities/Time.h"

#include <string>
#include <vector>
#include <format>
#include <iostream>
#include <sstream>

#define NEBULA_LOG(Severity, Message, ...) Nebula::Logger::Log(Severity, __FUNCTION__, Message, true, __VA_ARGS__);
#define NEBULA_PRINT(Severity, Message, ...) Nebula::Logger::Log(Severity, __FUNCTION__, Message, false, __VA_ARGS__);

namespace Nebula
{
	enum class ELogSeverity
	{
		Neutral,
		Warning,
		Error,
		Success
	};

	struct LogMessage
	{

		LogMessage(ELogSeverity Severity, const std::string& Message)
			:Severity(Severity), Message(Message)
		{}

		ELogSeverity Severity;
		std::string Message;
	};

	class Logger
	{

	public:

		//Logs or Prints the input message.
		template<typename... Args>
		static void Log(ELogSeverity Severity, const std::string& FuncSig, const std::string& Message, bool Output, Args... LogArgs);

		//Cleans the __FUNCTION__ macro. //TODO - Find or create a cross platform alternative!
		static std::string ParseFunction(const std::string& Value);

		//Exports the log file.
		static void ExportLog();

		//Retrieves message history.
		static std::vector<LogMessage>& GetMessageHistory() { return m_MessageHistory; }

	private:

		static std::string GetOldestLogPath();
		static TimeSpan ParseLogTimeFromTitle(const std::string& Path);

		static inline std::stringstream m_LogStream;

		//The number of log files allowed until the oldest files start getting deleted.
		static inline constexpr int m_MaxLogCount = 10;

		//The number of messages allowed until the oldest messages start getting deleted.
		static inline constexpr int m_MaxHistoryCount = 100;

		static inline std::vector<LogMessage> m_MessageHistory;

	};

	template<class... Args>
	void Logger::Log(ELogSeverity Severity, const std::string& FuncSig, const std::string& Message, bool Output, Args... LogArgs)
	{
		TimeSpan CurrentTime = TimeSpan::GetCurrentTime();
		std::string TimeString = std::format("{}:{}:{}", CurrentTime.Hours, CurrentTime.Minutes, CurrentTime.Seconds);

		std::string ClassName = ParseFunction(FuncSig);

		std::string SeverityString;

		switch (Severity) {
		case ELogSeverity::Neutral:
			break;

		case ELogSeverity::Warning:
			SeverityString = " Warning:";
			break;

		case ELogSeverity::Error:
			SeverityString = " Error:";
			break;

		case ELogSeverity::Success:
			SeverityString = " Success:";
			break;
		}

		const std::string OutputMessage = std::format("[{}][{}]{} {}", TimeString, ClassName, SeverityString, std::vformat(Message, std::make_format_args(LogArgs...)));

		std::cout << OutputMessage << '\n';

		if (m_MessageHistory.size() == m_MaxHistoryCount)
		{
			m_MessageHistory.erase(m_MessageHistory.begin());
		}

		m_MessageHistory.push_back(LogMessage(Severity, OutputMessage));

		if (Output)
		{
			m_LogStream << OutputMessage << '\n';
		}

	}
}
