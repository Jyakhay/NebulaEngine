#include "Logger.h"

#include <filesystem>
#include <iostream>

#include <fstream>

#include "Core/Application.h"
#include "Core/NebulaEngine.h"
#include "Platform/FileSystem.h"
#include "Utilities/Time.h"

namespace Nebula
{

	std::string Logger::ParseFunction(const std::string& Value)
	{
		const size_t ClassNameStart = Value.find(':') + 2;
		const size_t ClassNameEnd = Value.find_last_of(':') - 1;

		return Value.substr(ClassNameStart, ClassNameEnd - ClassNameStart);
	}

	void Logger::ExportLog()
	{
		const std::string OutputDirectory = FileSystem::GetExecutableDirectory() + "Saved\\Logs\\";

		if (!std::filesystem::exists(OutputDirectory))
		{
			std::filesystem::create_directories(OutputDirectory);
		}
		else
		{
			const uint32_t FileCount = FileSystem::GetNumFilesInDirectory(OutputDirectory);

			//If the max amount of log files has been reached, delete the oldest one.
			if (FileCount >= m_MaxLogCount)
			{
				const std::string OldestLog = GetOldestLogPath();
				std::filesystem::remove(OldestLog);
			}
		}

		//Parse current time into string for file name.
		TimeSpan CurrentTime = TimeSpan::GetCurrentTime();
		const std::string ParsedTime = std::format("[{}-{}-{} {}.{}.{}] - {}",
			CurrentTime.Years, CurrentTime.Months, CurrentTime.Days, CurrentTime.Hours, CurrentTime.Minutes, CurrentTime.Seconds, GEngine->GetApplication()->GetName());

		std::ofstream OutputStream(OutputDirectory + ParsedTime + ".log");
		OutputStream << m_LogStream.str();
		OutputStream.close();
	}

	std::string Logger::GetOldestLogPath()
	{
		std::vector<std::string> Paths;

		for (auto& Path : std::filesystem::directory_iterator(FileSystem::GetExecutableDirectory() + "Saved/Logs/"))
		{
			TimeSpan CreationTime = ParseLogTimeFromTitle(std::filesystem::path(Path).stem().string());

			//Compare current path to all other paths, the last file in the vector is the oldest log file.
			int InsertIndex = 0;
			for (auto& OtherPath : Paths)
			{
				TimeSpan OtherCreationTime = ParseLogTimeFromTitle(std::filesystem::path(OtherPath).stem().string());

				if (CreationTime.CompareTo(OtherCreationTime) == 1)
					InsertIndex++;
			}

			Paths.insert(Paths.begin() + InsertIndex, Path.path().string());

		}

		return Paths.at(Paths.size() - 1);
	}

	TimeSpan Logger::ParseLogTimeFromTitle(const std::string& Path)
	{
		TimeSpan ReturnValue;

		std::string DateSection = Path.substr(1, Path.find_last_of('-') - 3);

		const size_t DateTimeSplitIndex = DateSection.find(' ');

		//Separate Date and Time.
		const std::string Date = DateSection.substr(0, DateSection.find(' '));
		const std::string Time = DateSection.substr(DateTimeSplitIndex + 1, DateSection.size() - DateTimeSplitIndex);

		std::istringstream DateStream;
		DateStream.str(Date);

		//Retrieve the 3 date values.
		std::string CurrentString;
		std::vector<int> DateValues;

		while (std::getline(DateStream, CurrentString, '-'))
		{
			DateValues.push_back(std::stoi(CurrentString));
		}

		//Retrieve the 3 time values.
		std::istringstream TimeStream;
		TimeStream.str(Time);

		std::vector<int> TimeValues;
		while (std::getline(TimeStream, CurrentString, '.'))
		{
			TimeValues.push_back(std::stoi(CurrentString));
		}

		ReturnValue.Years = DateValues[0];
		ReturnValue.Months = DateValues[1];
		ReturnValue.Days = DateValues[2];
		ReturnValue.Hours = TimeValues[0];
		ReturnValue.Minutes = TimeValues[1];
		ReturnValue.Seconds = TimeValues[2];

		return {};
	}
}
