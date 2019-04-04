
#include <test_thread.hpp>


#include <Chimera/threading.hpp>
#include <Chimera/serial.hpp>
#include <Chimera/gpio.hpp>

#include <boost/circular_buffer.hpp>



void test_thread( void *argument )
{
 
  Chimera::Threading::signalSetupComplete();

  for ( ;; )
  {

    Chimera::delayMilliseconds( 100 );
  }
}

