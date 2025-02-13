#include "socket.hh"

#include <cstdlib>
#include <iostream>
#include <span>
#include <string>
using namespace std;

//this function aims to get the URL of the target
// void get_URL(const std::string& host, const std::string& path) {
//     TCPSocket socket;
//     socket.connect(Address(host, "http"));
//     string request = "GET " + path + " HTTP/1.1\r\n"
//                           "Host: " + host + "\r\n"
//                           "Connection: close\r\n\r\n";
//     size_t bytes_written = socket.write(request);
// 	if (bytes_written < request.size()) {
//         cerr << "Failed to write the complete request.\n";
//         return;
//     }
//     string buffer;
//     while (!socket.eof()) {
//         socket.read(buffer);
// 		cout << buffer ;
// 		buffer.clear();
//     }
//     socket.close();
// }
void get_URL(const string &host, const string &path) {
	TCPSocket tsk;
	tsk.connect(Address(host,"http"));

	string request = "GET " + path + " HTTP/1.1\r\n"
					 "Host: " + host + "\r\n"
					 "Connection: close\r\n\r\n";
	tsk.write(request);
	//close the socket
	tsk.shutdown(2);
	string str;
	while(!tsk.eof()) {
		tsk.read(str);
		cout << str;
	}
	tsk.close();
}


int main( int argc, char* argv[] )
{
  try {
    if ( argc <= 0 ) {
      abort(); // For sticklers: don't try to access argv[0] if argc <= 0.
    }

    auto args = span( argv, argc );

    // The program takes two command-line arguments: the hostname and "path" part of the URL.
    // Print the usage message unless there are these two arguments (plus the program name
    // itself, so arg count = 3 in total).
    if ( argc != 3 ) {
      cerr << "Usage: " << args.front() << " HOST PATH\n";
      cerr << "\tExample: " << args.front() << " stanford.edu /class/cs144\n";
      return EXIT_FAILURE;
    }

    // Get the command-line arguments.
    const string host { args[1] };
    const string path { args[2] };

    // Call the student-written function.
    get_URL( host, path );
  } catch ( const exception& e ) {
    cerr << e.what() << "\n";
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
