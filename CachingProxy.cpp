#include <iostream>
#include <string>
#include <format>


#include <boost/asio.hpp>
#include <boost/program_options.hpp>


#include "CachingProxyConfig.h"

#include "ConsoleCommand.h"
#include "CommandLineOptions.h"


namespace po = boost::program_options;

int main(int argc, char* const argv[]) {
    std::cout << "Version " << CachingProxy_VERSION_MAJOR << "." << CachingProxy_VERSION_MINOR << "\n";


	auto res{ ConsoleCommand::Parse(argc, argv) };

	if (!res) {
		std::cout << "Enter \"--help\".\n";
		return 1;
	}

	if (res.port && res.origin) {
		// main logic proxy server
		int port{ res.port.value() };
		std::string uri{ res.origin.value() };
		std::cout << std::format("Caching proxy server started on port {} and forwarding to {}\n", port, uri);
	}
	else if (res.isClearCache) {
		// clear cache get and head request
		std::cout << "Cache cleared\n";
	}

	return 0;
}

//caching-proxy --port <number> --origin <url>

//--memory-cache: Should use a Memory Cache that will be cleaned when the process finishes?