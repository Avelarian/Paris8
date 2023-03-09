#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <functional>

class RtsCts
{
public:
  bool IsCtsReceived() const
  {
    return cts_received;
  }

public:
  bool IsRtsSent() const
  {
    return rts_sent;
  }

public:
  void SetCtsReceived(bool value)
  {
    cts_received = value;
  }

public:
  void SetRtsSent(bool value)
  {
    rts_sent = value;
  }

private:
  bool cts_received = false;

private:
  bool rts_sent = false;
};

std::mutex mtx;
std::condition_variable cv;
RtsCts rts_cts;

void sender_thread()
{
  // Envoie une demande RTS
  {
    std::unique_lock<std::mutex> lock(mtx);
    rts_cts.SetRtsSent(true);
    std::cout << "RTS sent" << std::endl;
  }
  cv.notify_one();

  // Attend la réponse CTS
  {
    std::unique_lock<std::mutex> lock(mtx);
    cv.wait(
        lock, std::bind(&RtsCts::IsCtsReceived, &rts_cts));
    std::cout << "CTS received" << std::endl;
  }

  // Transmet les données
  std::cout << "Data transmitted" << std::endl;

  // Envoie un signal de fin de transmission
  {
    std::unique_lock<std::mutex> lock(mtx);
    rts_cts.SetCtsReceived(false);
    rts_cts.SetRtsSent(false);
    std::cout << "Transmission finished" << std::endl;
  }
}

void receiver_thread()
{
  // Attend une demande RTS
  {
    std::unique_lock<std::mutex> lock(mtx);
    cv.wait(
        lock, std::bind(&RtsCts::IsRtsSent, &rts_cts));
    std::cout << "RTS received" << std::endl;
  }

  // Envoie une réponse CTS
  {
    std::unique_lock<std::mutex> lock(mtx);
    rts_cts.SetCtsReceived(true);
    std::cout << "CTS sent" << std::endl;
  }
  cv.notify_one();
}

int main()
{
  std::thread sender(sender_thread);
  std::thread receiver(receiver_thread);

  sender.join();
  receiver.join();

  return 0;
}