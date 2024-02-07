#include "byte_stream.hh"

using namespace std;

ByteStream::ByteStream( uint64_t capacity ) : capacity_( capacity ) {}

bool Writer::is_closed() const
{
  // Your code here.
  return closed_;
}

void Writer::push( string data )
{
  // Your code here.
  if (!closed_ && data.size() <= available_capacity()) {
	buffer_ += data;
	bytes_written_ +=data.size();
  }
}

void Writer::close()
{
  closed_ = true;
}

uint64_t Writer::available_capacity() const
{
  // Your code here.
  return capacity_ - buffer_.size();
}

uint64_t Writer::bytes_pushed() const
{
  // Your code here.
  return bytes_written_;
}

bool Reader::is_finished() const
{
  // Your code here.
  return closed_ && buffer_.empty();
}

uint64_t Reader::bytes_popped() const
{
  // Your code here.
  return bytes_read_;
}

string_view Reader::peek() const
{
  // Your code here.
  return string_view(buffer_);
}

void Reader::pop( uint64_t len )
{
  // Your code here.
  if (len <= buffer_.size()) {
	buffer_.erase(0, len);
	bytes_read_ += len;
  }
}

uint64_t Reader::bytes_buffered() const
{
	// Your code here.
	return buffer_.size();
}

void read(Reader& reader, uint64_t len, std::string& out)
{
		string_view data = reader.peek();
		if (data.size() > len) {
				data = data.substr(0, len);
		}
		out = string(data);
		reader.pop(data.size());
}

bool Reader::has_error()
{
	// Your code here.
	return has_error_;
}