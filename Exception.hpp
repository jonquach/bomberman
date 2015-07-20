#ifndef EXCEPTION_HPP_
#define EXCEPTION_HPP_

#include <exception>
#include <string>

class ErrorException : public std::exception
{
private:
  std::string _msg;

public:
  ErrorException(std::string const &);
  virtual ~ErrorException() throw() {}
  virtual const char *what() const throw();
};

#endif
