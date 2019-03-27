
#include <Chimera/chimera.hpp>
#include <Chimera/threading.hpp>

#include <test_thread.hpp>

int main()
{
  ChimeraInit();

  Chimera::Threading::addThread( test_thread, "tt", 500, NULL, 2, NULL );
  Chimera::Threading::addThread( led_heartbeat, "led", 200, NULL, 2, NULL );

  /* This should never return */
  Chimera::Threading::startScheduler();

  return 0u;
}
