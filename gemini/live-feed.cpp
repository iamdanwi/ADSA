#include <iostream>
#include <deque>

int main()
{
    std::deque<int> dq;

    dq.push_front(21);
    dq.push_back(31);
    dq.push_front(31);

    std::cout << "Top element is " << dq.at(0);
    return 0;
}