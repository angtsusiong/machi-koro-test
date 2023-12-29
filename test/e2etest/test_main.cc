#include <gtest/gtest.h>
#include <drogon/drogon.h>

int main(int argc, char** argv) 
{
    using drogon::app;

    std::promise<void> p1;
    std::future<void> f1 = p1.get_future();

    std::jthread thr([&p1]() {
        app().getLoop()->queueInLoop([&p1]() { p1.set_value(); });
        app().addListener("0.0.0.0", 8086);
        app().run();
    });

    f1.get();
    
    std::this_thread::sleep_for(std::chrono::milliseconds(500));

    testing::InitGoogleTest(&argc, argv);
    int status = RUN_ALL_TESTS();

    app().getLoop()->queueInLoop([]() { app().quit(); });
    return status;
}
