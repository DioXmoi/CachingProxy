#pragma once

#include "Logger.h"
#include "Cache.h"

#include <boost/asio.hpp>
#include <boost/beast.hpp>

#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast/version.hpp>
#include <boost/asio/dispatch.hpp>

#include <boost/asio/strand.hpp>

#include <boost/config.hpp>

#include <memory>



namespace beast = boost::beast;         // from <boost/beast.hpp>
namespace http = beast::http;           // from <boost/beast/http.hpp>
namespace net = boost::asio;            // from <boost/asio.hpp>
using tcp = boost::asio::ip::tcp;       // from <boost/asio/ip/tcp.hpp>

// Handles an HTTP server connection
class Session : public std::enable_shared_from_this<Session> {
public:
	Session(tcp::socket&& sock, std::shared_ptr<Cache> cache) noexcept;

	void Run();
	
	void DoRead();

	void OnRead(beast::error_code ec, std::size_t bytes_transferred);

	void SendResponse(http::message_generator&& msg);

	void OnWrite(bool keep_alive, beast::error_code ec, std::size_t bytes_transferred);

	void DoClose();

	template <class Body, class Allocator>
	static inline http::message_generator HandleRequest(
		http::request<Body, http::basic_fields<Allocator>>&& req,
		std::shared_ptr<Cache> cache);

private:

	beast::tcp_stream m_stream;
	beast::flat_buffer m_buffer;
	http::request<http::string_body> m_req;
	std::shared_ptr<Cache> m_cache;

};

template <class Body, class Allocator>
static inline http::message_generator Session::HandleRequest(
	http::request<Body, http::basic_fields<Allocator>>&& req,
	std::shared_ptr<Cache> cache) {

	// 1 Проверить в кэше если есть то сразу отдать 

	// 2 Если нет в кэше то устанавливаем соединение и отправляем запрос

	// 3 get и head методы мы кэшируем 
	//if (req.method() == beast::http::verb::get || req.method() == beast::http::verb::head) {
	//	//Кэш кэш ))
	//}

	// 4 Отправляем запрос 

	return http::response<http::empty_body>{ http::status::ok, req.version() };
}