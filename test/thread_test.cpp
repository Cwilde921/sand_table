#include<thread>
// #include<pthread.h>
#include<iostream>
#include<chrono>
#include<mutex>
#include<vector>
#include<memory>


// be sure to comile with -pthread
// g++ test.cpp -o a.out -pthread

class ThObj
{
    public:
        std::shared_ptr<std::vector<int>> m_vec;
        int m_thnum;

        ThObj(std::shared_ptr<std::vector<int>> vec, int thnum)
        {
            m_vec = vec;
            m_thnum = thnum;
        }

        void operator() (int ct, std::mutex &mtx)
        {
            std::cout<< "starting thread" << std::endl;
            for(int i=0; i<ct; i++)
            {
                // std::cout<< "looping" << std::endl;
                mtx.lock();
                m_vec->push_back(m_thnum);
                mtx.unlock();
                std::this_thread::sleep_for(std::chrono::seconds(1));

            }
            std::cout<< "finishing thread" << std::endl;
        }
};


void thread_fun(int ct, std::mutex &mtx, std::vector<int> &v, int thnum)
{
    std::cout<< "starting thread" << std::endl;
    for(int i=0; i<ct; i++)
    {
        // std::cout<< "looping" << std::endl;
        mtx.lock();
        v.push_back(thnum);
        mtx.unlock();
        std::this_thread::sleep_for(std::chrono::seconds(1));

    }
    std::cout<< "finishing thread" << std::endl;
}

void launch() 
{
    std::mutex mtx;
    std::vector<int> v;
    std::shared_ptr<std::vector<int>> vec = std::make_shared<std::vector<int>>(v);

    vec->push_back(0);

    std::thread th1(ThObj(vec, 1), 5, std::ref(mtx));
    std::thread th2(ThObj(vec, 2), 5, std::ref(mtx));
    std::thread th3(ThObj(vec, 3), 5, std::ref(mtx));
    std::thread th4(ThObj(vec, 4), 5, std::ref(mtx));

    // std::thread th1(thread_fun, 5, std::ref(mtx), std::ref(vec), 1);
    // std::thread th2(thread_fun, 5, std::ref(mtx), std::ref(vec), 2);
    // std::thread th3(thread_fun, 5, std::ref(mtx), std::ref(vec), 3);
    // std::thread th4(thread_fun, 5, std::ref(mtx), std::ref(vec), 4);
    std::cout<< "after calling main thread" << std::endl;
    th1.join();
    th2.join();
    th3.join();
    th4.join();
    // return th1;
    for(int i=0; i < vec->size(); i++)
    {
        std::cout << vec->at(i) << ' ';
    }
}

int main()
{
    launch();
    std::cout<< "back in main" << std::endl;
    return 0;
}