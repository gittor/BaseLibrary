
#pragma once

#include <map>
#include <string>

namespace cex
{
	class config_t
	{
	public:
		config_t(void);
		config_t(const std::string& fname);
		~config_t(void);

		bool load(const std::string& fname);

		std::string get(const std::string& key, const std::string& def = std::string());
		config_t& set(const std::string& key, const std::string& value);

		std::map<std::string, std::string> content();

		void flush();

		void autoFlush(bool bAutoFlushOnDestroy = true);

		std::string get(const std::string& fname, const std::string& key, const std::string& def/* = std::string()*/);
		void set(const std::string& fname, const std::string& key, const std::string& value);

	private:
		std::map<std::string, std::string> m_content;
		std::string m_fname;
		bool m_autoFlush;
	};
}
