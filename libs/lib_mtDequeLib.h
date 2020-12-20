#pragma once

#include <mutex>
#include <thread>
#include <deque>
#include <condition_variable>
#include <unistd.h>

template <typename T>
class queueLists
{
    public:
        queueLists() {};
        queueLists(queueLists&& other) : m_deque(move(other.m_deque)) { }
        queueLists(const queueLists& other) = delete;
        void push(T& value);
        void push(T&& value);
        bool pop(T& value);
    private:
        std::deque<T> m_deque;
        std::mutex m_mutex; 
        std::condition_variable m_cv;
};

template <typename T>
void queueLists<T>::push(T& value){
    std::unique_lock<std::mutex> lock(m_mutex);
    m_deque.push_back(value);
    m_cv.notify_one();
}

template <typename T>
void queueLists<T>::push(T&& value){
    std::unique_lock<std::mutex> lock(m_mutex);
    m_deque.push_back(std::move(value));
    m_cv.notify_one();
}

template <typename T>
bool queueLists<T>::pop(T& value){
    std::unique_lock<std::mutex> lock(m_mutex);
    if (m_deque.size())
    {
        value = std::move(m_deque.front());
        m_deque.pop_front();
        return true;
    }
    return false;
}



