// IOEngine.cpp

#include "IOEngine.hpp"

IOEngine::IOEngine() 
{
	this->p_socket = new tcp::socket(this->ioContext);
}

IOEngine::~IOEngine() {

}

void IOEngine::connect(std::string IP, uint16_t PORT)
{
	tcp::resolver resolver(this->ioContext);
	tcp::resolver::results_type endpoints = resolver.resolve(IP, std::to_string(PORT));
	boost::asio::connect(*this->p_socket, endpoints);
}


void IOEngine::listenForMessages(uint16_t listenPort)
{
	tcp::acceptor acceptor(this->ioContext, tcp::endpoint(tcp::v4(), listenPort));

	for(;;) {
		acceptor.accept(*this->p_socket);

		std::array<char, 128> buffer;
		boost::system::error_code error;
		size_t length = this->p_socket->read_some(boost::asio::buffer(buffer), error);

		if (error == boost::asio::error::eof) {
			break;
		}
		else if (error) {
			throw boost::system::system_error(error);
		}
		std::cout << "Received: ";
		std::cout.write(buffer.data(), length);
		std::cout << std::endl;
		break;
	}
}

void IOEngine::sendMessage(std::string& message) 
{
	boost::asio::write(*this->p_socket, boost::asio::buffer(message));
}

void IOEngine::~IOEngine()
{
	delete this->p_socket
}



