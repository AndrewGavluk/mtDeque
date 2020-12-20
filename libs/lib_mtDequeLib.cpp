#include "lib_mtDequeLib.h" 
/*
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

}*/

