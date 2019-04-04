
#include <Chimera/chimera.hpp>
#include <Chimera/threading.hpp>

#include <test_thread.hpp>

#include <Arche/arche_threads.hpp>

int main()
{
  ChimeraInit();

  Chimera::Threading::addThread( Arche::threads, Arche::numThreads );
  Chimera::Threading::startScheduler();

  return 0u;
}
