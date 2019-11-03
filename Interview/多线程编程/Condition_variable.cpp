#include<iostream>
#include<list>
#include<mutex>
#include<thread>
#include<condition_variable>

using namespace std;
class Comm{
    public:
        void Generate(){
            for(size_t i=0;i<100;i++){
                unique_lock<mutex> lock(mtx);
                msg.push_back(i);
                cout<<"Generate msg "<<i<<endl;
            }
        }
        void Recivemsg(){
            for(size_t i=0;i<100;i++){
                unique_lock<mutex> lock(mtx);
                condition.wait(lock,[this](){
                    if(!msg.empty()){
                        return true;
                    }
                    return false;
                });
                cout<<"Recive "<<msg.front()<<endl;

                
                msg.pop_front();
            }
        }
    private:
        list<int> msg;
        mutex mtx;
        condition_variable condition;
};

int main(){
    Comm com;
    
    thread t1(&Comm::Generate,&com);
    thread t2(&Comm::Recivemsg,&com);

    t1.join();
    t2.join();

    getchar();
    return 0;
}