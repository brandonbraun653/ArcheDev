
#include <Chimera/chimera.hpp>
#include <Chimera/threading.hpp>

#include <test_thread.hpp>

#include <Arche/arche_threads.hpp>

int main()
{
  ChimeraInit();

  Chimera::Threading::addThread(
    Arche::HeartBeat::threadHeartbeat,
    Arche::HeartBeat::threadName,
    Arche::HeartBeat::RTOS_STACK_DEPTH, NULL,
    Arche::HeartBeat::threadPriority,
    Arche::HeartBeat::threadHandle);

  Chimera::Threading::addThread(
    Arche::IOP::iopSerial,
    Arche::IOP::threadName,
    Arche::IOP::RTOS_STACK_DEPTH, NULL,
    Arche::IOP::threadPriority,
    Arche::IOP::threadHandle);

  Chimera::Threading::addThread(
    Arche::SYS::sysMain,
    Arche::SYS::threadName,
    Arche::SYS::RTOS_STACK_DEPTH, NULL,
    Arche::SYS::threadPriority,
    Arche::SYS::threadHandle);

  /* This should never return */
  Chimera::Threading::startScheduler();

  return 0u;
}
