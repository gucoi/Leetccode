#include<iostream>
#include<thread>
#include<vector>
#include<list>
#include<mutex>

class Comm{
public:
    void msgGenerator(){
        for (size_t i = 0; i < 500; i++){
            //需要保护的数据进行加锁，这里就是容器msg,
            //在对msg进行写操作时候，不允许读操作进行

            // 1
            // mtx_1.lock();std::cout<<"\ngenerator lock 1"<<std::endl;
            // mtx_2.lock();std::cout<<"generator lock 2"<<std::endl;
            // msg.push_back(i); std::cout<<"generator: "<<i<<std::endl;
            // mtx_2.unlock();std::cout<<"generator unlock 2"<<std::endl;
            // mtx_1.unlock();std::cout<<"generator unlock 1"<<std::endl;
 
            //2
            // std::lock(mtx_1, mtx_2);
            // std::lock_guard<std::mutex> lockGrd1(mtx_1,std::adopt_lock);
            // std::lock_guard<std::mutex> lockGrd2(mtx_2,std::adopt_lock);
            // msg.push_back(i);

            //3 unique_lock可以像lock_guard一样可以自己实现lock和 unlock
            std::unique_lock<std::mutex> uniGrd(mtx_1, std::try_to_lock);
            if(uniGrd.owns_lock()) { //拿到了lock()
                msg.push_back(i);
                std::cout<<"generator: "<<i<<std::endl;
            }
            else{
               std::cout<<i<<"th fail to lock.\n";
            }

            //4 
            // std::unique_lock<std::mutex> uniGrd(mtx_1, std::defer_lock);
            // uniGrd.lock();

            // //处理一些没有共享数据的代码
            // uniGrd.unlock();
            
            // //下面又是一些需要处理共享数据的代码
            // uniGrd.lock(); 
            // msg.push_back(i);
            // std::cout<<"generator: "<<i<<std::endl;

            //最后由于unique_lock自己就可以unlock，不需要unlock


            //5
            // std::unique_lock<std::mutex> uniLock(mtx_1);
            // auto mtxPtr = uniLock.release();
            // msg.push_back(i);
            // std::cout<<"generator: "<<i<<std::endl;
            // mtxPtr->unlock();

            // 6
            // std::unique_lock<std::mutex> uniLock1(mtx_1);
            // std::unique_lock<std::mutex> uniLock2(std::move(uniLock1));
            // msg.push_back(i);
            // std::cout<<"generator: "<<i<<std::endl;

        }
    }

    void msgReceive(){
        for (size_t i = 0; i < 100; i++){
            //下面的if-else里面，一个分支执行了，另一个分支就不会执行
            // 如果把unlock放在分支里面，每个分支都需要加
            // mtx_1.lock();std::cout<<"\nrecieve lock 2"<<std::endl;
            // mtx_2.lock(); std::cout<<"recieve lock 1"<<std::endl;
            /** */
            // mtx_1.unlock();std::cout<<"recieve unlock 1"<<std::endl;
            // mtx_2.unlock();std::cout<<"recieve unlock 2"<<std::endl;
            
            // std::lock(mtx_1, mtx_2);
            // std::lock_guard<std::mutex> lockGrd1(mtx_1,std::adopt_lock);
            // std::lock_guard<std::mutex> lockGrd2(mtx_2,std::adopt_lock);
            /** */

            std::unique_lock<std::mutex>uniGrd(mtx_1);
            //  人为阻塞线程20s
            // std::chrono::milliseconds tme(1000);
            // std::this_thread::sleep_for(tme);

            if(msg.empty()) std::cout<<"empty.\n";
            else{
                int content = msg.front();
                msg.pop_front();
                std::cout<<"receive: "<<content<<std::endl;
            }
         
        }
    }   

private:
    std::list<int> msg;
    std::mutex mtx_1; //创建一个互斥量，不同线程访问同一个数据，必须使用同一个互斥量进行加锁和解锁
    std::mutex mtx_2;
};

int main(int argc, char const *argv[]){
    Comm com;

    std::thread sumbit(&Comm::msgGenerator, &com);
    std::thread receive(&Comm::msgReceive, &com);

    sumbit.join();
    receive.join();

    std::cout<<"Main thread.";
    getchar();
    return 0;
}

