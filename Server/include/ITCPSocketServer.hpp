#ifndef ITCP_SOCKET_SERVER_HPP_
# define ITCP_SOCKET_SERVER_HPP_

# include <sys/socket.h>
# include <netinet/in.h>
# include <netinet/ip.h>
# include "ITCPSocket.hh"

namespace Network
{
  using t_sockaddr = struct sockaddr;
  
  template <typename T>
  class ITCPSocketServer : virtual public ITCPSocket
  {
  public :
    virtual ~ITCPSocketServer() { }
    virtual bool bind(const t_sockaddr *, int) = 0;
    virtual bool listen(int) = 0;
    virtual T accept(t_sockaddr *, int *) = 0;
  };
}

#endif /* ! ITCP_SOCKET_SERVER_HPP_ */