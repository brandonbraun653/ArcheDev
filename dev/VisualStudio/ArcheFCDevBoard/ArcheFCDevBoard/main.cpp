
#include <Chimera/chimera.hpp>
#include <Chimera/threading.hpp>

#include <test_thread.hpp>

#include <Arche/threads.hpp>

int main()
{
  ChimeraInit();

  Chimera::Threading::addThread( Arche::threads.data(), Arche::threads.size());
  Chimera::Threading::startScheduler();

  return 0u;
}
