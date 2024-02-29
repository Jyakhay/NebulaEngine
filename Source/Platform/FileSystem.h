#pragma once

#include <string>

namespace Nebula
{

	class FileSystem
	{

	public:

		static uint32_t GetNumFilesInDirectory(const std::string& Directory);

		static std::string GetExecutablePath() { return m_ExecutablePath; }
		static std::string GetExecutableDirectory();

		static std::string GetContentDirectory();

	private:

		static inline std::string m_ExecutablePath;

		friend class NebulaEngine;

	};

}