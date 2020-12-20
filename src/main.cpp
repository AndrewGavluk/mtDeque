#include <atomic>
#include <functional>
#include <memory>
#include <random>

#include <vector>


#include "lib_mtDequeLib.h" 

void testBasic0()
{
    queueLists<int> q1;
    int a =1;
    q1.push (a);
    bool success = q1.pop(a);
    (void)(success);
}

void testBasic1()
{
    queueLists<std::unique_ptr<int>> q1;
    auto ptr = std::make_unique<int>();
    q1.push(std::move(ptr));
    bool success = q1.pop(ptr);
    (void)(success);
}

void testBasic2()
{
    queueLists<std::unique_ptr<int>> q1;
    q1.push(std::make_unique<int>());
    queueLists<std::unique_ptr<int>> q2 = std::move(q1);
}

void testBasic()
{
    testBasic0();
    testBasic1();
    testBasic2();
}

void testMultyThread()
{
    std::vector<std::thread> threads;
    queueLists<std::unique_ptr<int>> q1;

	std::atomic<int> elems {0};
	std::atomic<int> running_threads {0};

    int LOOP_CNT = 1000;
    int MAX_THREADS = std::thread::hardware_concurrency();
    
    for (int ix = 0; ix < MAX_THREADS; ++ix) {  
        ++running_threads;
		threads.push_back(std::thread([&]() {
			auto my_rand = std::bind(std::uniform_int_distribution<int>(0, RAND_MAX), 
									std::default_random_engine(ix));

			for (int i = 0; i < LOOP_CNT; ++i) {

				if (my_rand() % 2) {
					q1.push(std::make_unique<int>());
					++elems;
				}
				else {
					--elems;
                    std::unique_ptr<int> a;
					q1.pop(a);
				}
			}
			running_threads--;

		}));

    }

    for(auto &th : threads) {
		th.join();
	};
}

int main(){
    testBasic();
    testMultyThread();
return 0;
}
