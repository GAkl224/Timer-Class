#include <iostream>
#include <ctime>

using namespace std;

class Timer {
    private:
        clock_t startT;
        clock_t stopT;
        bool on;

    public:
        Timer() : on(false) {}

        void start() {
            if (!on) {
                startT = clock();
                on = true;
            }
        }

        void stop() {
            if (on) {
                stopT = clock();
                on = false;
            }
        }

        int elapsed() const {
            if (on) {
                clock_t now = clock();
                return static_cast<int>((now - startT) / CLOCKS_PER_SEC);
            } else {
                return static_cast<int>((stopT - startT) / CLOCKS_PER_SEC);
            }
        }
    };

//driver
int main() {
    Timer timer;

    cout << "Elapsed time: " << timer.elapsed() << " seconds\n";

    timer.start();// start

    //timer will go for 10 seconds
    while (timer.elapsed() < 10) {
        //timer is running
    }

    timer.stop(); 

    cout << "Elapsed time: " << timer.elapsed() << " seconds\n";

    return 0;
}