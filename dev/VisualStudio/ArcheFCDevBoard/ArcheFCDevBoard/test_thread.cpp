
#include <test_thread.hpp>


#include <Chimera/threading.hpp>
#include <Chimera/serial.hpp>
#include <Chimera/gpio.hpp>

#include <boost/circular_buffer.hpp>

static const uint32_t baudrate = 115200;
static const Chimera::Serial::CharWid width = Chimera::Serial::CharWid::CW_8BIT;
static const Chimera::Serial::Parity parity = Chimera::Serial::Parity::PAR_NONE;
static const Chimera::Serial::StopBits stop = Chimera::Serial::StopBits::SBITS_ONE;
static const Chimera::Serial::FlowControl flow = Chimera::Serial::FlowControl::FCTRL_NONE;

static constexpr size_t bufferSize = 100;

void test_thread( void *argument )
{
  Chimera::Serial::IOPins pins;
  Chimera::Serial::SerialClass serial( bufferSize );

  Chimera::Threading::signalThreadSetupComplete();

  pins.tx.pin       = 0;
  pins.tx.port      = Chimera::GPIO::Port::PORTA;
  pins.tx.pull      = Chimera::GPIO::Pull::PULL_UP;
  pins.tx.drive     = Chimera::GPIO::Drive::ALTERNATE_PUSH_PULL;
  pins.tx.alternate = GPIO_AF8_UART4;

  pins.rx.pin       = 1;
  pins.rx.port      = Chimera::GPIO::Port::PORTA;
  pins.rx.pull      = Chimera::GPIO::Pull::PULL_UP;
  pins.rx.drive     = Chimera::GPIO::Drive::ALTERNATE_PUSH_PULL;
  pins.rx.alternate = GPIO_AF8_UART4;

  boost::circular_buffer<uint8_t> rxBuffer( bufferSize );
  boost::circular_buffer<uint8_t> txBuffer( bufferSize );

  serial.assignHW( 4, pins );
  serial.configure( baudrate, width, parity, stop, flow );
  serial.enableBuffering( Chimera::Serial::SubPeripheral::TX, &txBuffer );
  serial.enableBuffering( Chimera::Serial::SubPeripheral::RX, &rxBuffer );

  serial.begin( Chimera::Serial::Modes::BLOCKING, Chimera::Serial::Modes::DMA );

  std::string hello_world = "hello world\r\n";
  std::string queue_data  = "some queued data\r\n";

  std::array<uint8_t, bufferSize> readData;
  readData.fill(0);

  size_t bytesAvailable = 0;

  serial.read(nullptr, 5);

  for ( ;; )
  {
    //serial.write( reinterpret_cast<const uint8_t *>( hello_world.data() ), hello_world.length() );
    //serial.write( reinterpret_cast<const uint8_t *>( queue_data.data() ), queue_data.length() );

    if ( serial.available( &bytesAvailable ) )
    {
      auto maxLen = std::min( bufferSize, bytesAvailable );
      serial.readAsync( readData.data(), maxLen );
      serial.write( readData.data(), bytesAvailable );
      serial.read(nullptr, 5);
    }


    Chimera::delayMilliseconds( 100 );
  }
}

