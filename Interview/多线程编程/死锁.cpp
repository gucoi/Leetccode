#include<iostream>
#include<thread>
#include<list>
#include<mutex>

using namespace std;

class Comm{
    public:
        void Generate(){
        /*
        Defined in header <mutex>
        template< class Mutex >
        class lock_guard;
        The class lock_guard is a mutex wrapper that provides a convenient RAII-style mechanism for owning a mutex for the duration of a scoped block.
        When a lock_guard object is created, it attempts to take ownership of the mutex it is given. When control leaves the scope in which the lock_guard object was created, the lock_guard is destructed and the mutex is released.
        The lock_guard class is non-copyabl
        */
            for(size_t i=0;i<100;i++){
                // lock_guard<mutex> lock(mtx);
                mtx1.lock();
                mtx2.lock();
                msg.push_back(i);
                cout<<"Generate the"<<i<<endl;
                mtx2.unlock();
                mtx1.unlock();
            }
        }
        void Recive(){
            for(size_t i=0;i<100;i++){
                mtx2.lock();
                mtx1.lock();
                cout<<"Recive the "<<msg.front()<<endl;
                msg.pop_front();
                mtx1.unlock();
                mtx2.unlock();
            }
        }
    private:
        list<int> msg;
        mutex mtx1;
        mutex mtx2;
};

int main(){
    Comm com;
    thread sum(&Comm::Generate,&com);
    thread Rec(&Comm::Recive,&com);

    sum.join();
    Rec.join();

    getchar();
    return 0;
}