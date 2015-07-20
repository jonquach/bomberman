#include "Exception.hpp"

ErrorException::ErrorException(std::string const &msg) :
  _msg(msg)
{

}

const char *ErrorException::what() const throw()
{
  return _msg.c_str();
}
