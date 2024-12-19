#pragma once

#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast/version.hpp>
#include <boost/asio/dispatch.hpp>
#include <boost/asio/strand.hpp>
#include <boost/config.hpp>

#include <memory>
#include <string>
#include "Cache.h"



namespace beast = boost::beast;         // from <boost/beast.hpp>
namespace http = beast::http;           // from <boost/beast/http.hpp>
namespace net = boost::asio;            // from <boost/asio.hpp>
using tcp = boost::asio::ip::tcp;       // from <boost/asio/ip/tcp.hpp>


// Accepts incoming connections and launches the sessions
class Listener : public std::enable_shared_from_this<Listener> {
public:
	Listener(net::io_context& ioc,
		tcp::endpoint endpoint,
		const std::string& origin,
		std::shared_ptr<Cache> cache);

	// Start accepting incoming connections
	void Run();

private:

	void DoAccept();

	void OnAccept(beast::error_code ec, tcp::socket&& socket);


private:
	net::io_context& m_ioc;
	tcp::acceptor m_acceptor;

	//The URL of the server whose requests we cache
	std::string m_origin;

	std::shared_ptr<Cache> m_cache;
};