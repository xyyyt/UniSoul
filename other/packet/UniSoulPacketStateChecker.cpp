#include <cstddef>
#include <cstring>
#include "NetworkPacketException.hh"
#include "UniSoulPacketStateChecker.hh"

namespace Network
{
  UniSoulPacketStateChecker
  ::UniSoulPacketStateChecker(const UniSoulPacket& uniSoulPacket) :
    _uniSoulPacket(uniSoulPacket)
  {
  }

  void UniSoulPacketStateChecker::setPacket(const UniSoulPacket& uniSoulPacket)
  {
    _uniSoulPacket = uniSoulPacket;
  }

  bool UniSoulPacketStateChecker::checkPacket() const
  {
    try
      {
	checkPacketHeaderSize();
	checkPacketDataSize();
      }
    catch (const Exception::Network::PacketStateException& e)
      {
	throw e;
      }
    return true;
  }

  void UniSoulPacketStateChecker::checkPacketHeaderSize() const
  { 
    std::size_t	expectedSize = _uniSoulPacket.header.header_size;
    std::size_t	cropSize
      = sizeof(_uniSoulPacket.header.communication)
      + sizeof(_uniSoulPacket.header.request);

    if (expectedSize != cropSize)
      throw Exception::Network::PacketHeaderSizeException();
  }

  void UniSoulPacketStateChecker::checkPacketDataSize() const
  {
    std::size_t	expectedSize = _uniSoulPacket.data.data_size;
    std::size_t	cropSize
      = std::strlen(reinterpret_cast<const char *>(_uniSoulPacket.data.data));

    if (expectedSize != cropSize)
      throw Exception::Network::PacketDataSizeException();
  }
}