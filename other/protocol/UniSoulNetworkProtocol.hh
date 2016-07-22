#ifndef UNI_SOUL_NETWORK_PROTOCOL_HH_
# define UNI_SOUL_NETWORK_PROTOCOL_HH_

typedef unsigned char		*byte_array;

namespace Network
{ 
  namespace Protocol
  {
    enum Communication
      {
	TCP = 0x0,
	UDP = 0x1,
	FTP = 0x2
      };

    enum Request
      {
	NONE = 0x0,
	CONNECTION = 0x1,
	DECONNECTION = 0x2,
      };
    
    struct Header
    {
      unsigned short int	header_size;
      Communication		communication;
      Request			request;
    };

    struct Data
    {
      unsigned short int	data_size;
      byte_array		data;
    };

    struct UniSoulPacket
    {
      Header			header;
      Data			data;
    };
  }
}

using UniSoulPacket = Network::Protocol::UniSoulPacket;

#endif /* !UNI_SOUL_NETWORK_PROTOCOL_HH_ */
