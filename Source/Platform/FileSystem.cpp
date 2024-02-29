#include "FileSystem.h"

#include <filesystem>

namespace Nebula
{
	uint32_t FileSystem::GetNumFilesInDirectory(const std::string& Directory)
	{
		if (std::filesystem::exists(Directory))
		{

			uint32_t FileCount = 0;
			for (auto& Entry : std::filesystem::directory_iterator(Directory))
			{
				++FileCount;
			}

			return FileCount;

		}

		return 0;
	}

	std::string FileSystem::GetExecutableDirectory()
	{
		return std::filesystem::path(m_ExecutablePath).parent_path().string() + '\\';
	}

	std::string FileSystem::GetContentDirectory()
	{
		return GetExecutableDirectory() + "Content\\";
	}
}
