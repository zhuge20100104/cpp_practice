#include <iostream>
#include <stdexcept>

template <class T>
class list {
public:

    list(): m_head(nullptr), m_tail(nullptr) {}

    bool empty() {
        return m_head == nullptr && m_tail == nullptr;
    }

    void push_front(T const& data) {
        m_head = new node(nullptr, data, m_head);
        if(m_head->m_next) { // 不是空链表
        // 双向链表
            m_head->m_next->m_prev = m_head;
        } else {
            m_tail = m_head;
        }
    }

    void pop_front() {
        if(empty()) {
            return;
        }

        node* pnode = m_head->m_next;
        delete m_head;
        if(pnode) { // 剩下的不是空链表，清空前节点指针
            pnode->m_prev = nullptr;
        }else {
            // 仅存的节点被删除了
            m_tail = nullptr;
        }

        m_head = pnode;
    }

    // 获取头结点元素
    T& front() {

    }

    std::size_t size() {
        std::size_t i = 0;
        for(node* pnode = m_head; pnode; pnode=pnode->m_next) {
            ++i;
        }
        return i;
    }
private:
    class node{
    public:
        node(node* prev, T const& data, node* next):
            m_prev(prev), m_data(data), m_next(next) {}
        node* m_prev;
        T m_data;
        node* m_next;
    };

    node* m_head;
    node* m_tail;

    friend std::ostream& operator<< (std::ostream& os, list<T> const& l);
};