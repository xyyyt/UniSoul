#ifndef UNI_SOUL_SYSTEM_WRAPPER_HH_
# define UNI_SOUL_SYSTEM_WRAPPER_HH_

# include <memory>
# include <map>
# include <string>
# include <boost/any.hpp>
# include "IWrapper.hpp"
# include "ConnectionManager.hpp"
# include "CommandFactory.hpp"
# include "CommandExecutor.hpp"
# include "ChatRoomManager.hh"
# include "ClientCheckerManager.hh"
# include "ClientInfo.hh"
# include "TCPConnection.hpp"

namespace Network
{
  template <typename T>
  class ITCPSocketServer;

  class ITCPSocket;
}

namespace Wrapper
{
  using VariantMap = std::map<std::string, boost::any>;
    
  class UniSoulSystemWrapper : public IWrapper<VariantMap>
  { 
  public :
    using ServerSocketPtr = std::shared_ptr
      <Network::ITCPSocketServer
       <std::shared_ptr<Network::ITCPSocket>>>;
    using ConnectionManager = Network::Manager::ConnectionManager
      <std::shared_ptr<Network::TCPConnection<Info::ClientInfo>>>;
    using ClientCheckerManager = Persistence::Manager::ClientCheckerManager;
    using ChatRoomManager = Communication::Chat::ChatRoomManager;
    using CommandFactory = Command::CommandFactory<UniSoulSystemWrapper>;
    using CommandExecutor = Command::CommandExecutor<UniSoulSystemWrapper>;
    
  private :
    VariantMap	_components;
      
  public :
    UniSoulSystemWrapper(const ServerSocketPtr&);
    virtual ~UniSoulSystemWrapper();
    virtual VariantMap& getContent();
  };
}

using UniSoulSystemWrapper = Wrapper::UniSoulSystemWrapper;

#endif /* !UNI_SOUL_SYSTEM_WRAPPER_HH_ */
