#include <iostream>
#include <thread>
#include <mutex>
#include <deque>
#include <chrono>
using namespace std;

deque<int> q;
mutex m;

void prod() {
    int count = 10;
    while (count > 0) {
        unique_lock<mutex> uLock(m);    // lock
        cout << "pushing data : " << count << endl;
        q.push_front(count);            // pushing data in queue
        uLock.unlock();                 // unlock
        this_thread::sleep_for(chrono::seconds(1));
        count--;
    }
}

void cons() {
    int data = 0;
    while (data != 1) {
        unique_lock<mutex> uLock(m, defer_lock);
        if (!q.empty()) {
            uLock.lock();               // lock
            data = q.back();            // take data and
            q.pop_back();               // popping data from queue
            uLock.unlock();             // unlock
            cout << "consumer got value : " << data << endl;
        }
        else {
            cout << "consumer waiting for data..." << endl; // continuous looping
        }
        this_thread::sleep_for(chrono::seconds(2));
    }
}

int main() {

    thread t1(prod);
    thread t2(cons);

    t1.join();
    t2.join();

    // IMPORTANT Points -
    // how to decide these sleep times ??

    // If producer is SLOW and consumer is FAST
    // Queue will underflow & underflow is ok not destructive issue because
    // consumer will keep waiting for data but why to waste CPU cycles

    // If producer is FAST and consumer is SLOW
    // Queue will overflow after sometime which will cause data loss

    // Solution is - some mechanism which could tell consumer thread that
    // data is available and you can process it otherwise it will make
    // consumer thread sleep
    // This is nothing but Condition Variable

}