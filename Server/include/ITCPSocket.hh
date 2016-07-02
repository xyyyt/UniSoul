#ifndef ITCP_SOCKET_HH_
# define ITCP_SOCKET_HH_

# include <string>
# include "ISocket.hh"

namespace Network
{
  class ITCPSocket : ISocket
  {
  public :
    virtual ~ITCPSocket() { }
    virtual bool send(const std::string&) const = 0;
    virtual std::string recv() const = 0;
  };
}

#endif /* !ITCP_SOCKET_HH_ */
