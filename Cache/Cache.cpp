#include "Cache.h"


void Cache::Set(const std::string& key, const std::string& value) {
	std::unique_lock lock{ m_mutex };

	m_data[key] = value;
}

std::optional<std::string> Cache::TryGet(const std::string& key) const {
	std::shared_lock lock{ m_mutex };
	if (m_data.contains(key)) { 
		return m_data.at(key); 
	}

	return { };
}

bool Cache::Contains(const std::string& key) const {
	std::shared_lock lock{ m_mutex };

	return m_data.contains(key);
}