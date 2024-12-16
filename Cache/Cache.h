#pragma once

#include <string>
#include <shared_mutex>
#include <unordered_map>
#include <optional>


class Cache {
public:
	Cache() = default;

	void Set(const std::string& key, const std::string& value);
	std::optional<std::string> TryGet(const std::string& key) const;
	bool Contains(const std::string& key) const;

private:
	std::shared_mutex m_mutex;
	std::unordered_map<std::string, std::string> m_data;
};