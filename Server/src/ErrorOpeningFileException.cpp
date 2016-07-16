#include <utility>
#include "ErrorOpeningFileException.hh"

namespace Exception
{
  namespace Persistence
  {
    ErrorOpeningFileException::ErrorOpeningFileException(const std::string& what_arg) :
      std::runtime_error(std::move(what_arg))
    {
    }

    ErrorOpeningFileException::~ErrorOpeningFileException() { }    
  }
}
