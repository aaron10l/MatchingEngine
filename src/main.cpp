#include <boost/intrusive/slist.hpp>
#include <iostream>

// Define a class that will be stored in the intrusive list
class MyNode : public boost::intrusive::slist_base_hook<> {
public:
    MyNode(int data) : data(data) {}

    int getData() const {
        return data;
    }

private:
    int data;
};

// Define an alias for the intrusive list
using MyNodeList = boost::intrusive::slist<MyNode>;

int main() {
    MyNodeList myList;

    // Insert nodes into the list
    MyNode node1(42);
    MyNode node2(73);
    MyNode node3(18);

    myList.push_front(node1);
    myList.push_front(node2);
    myList.push_front(node3);

    // Iterate over the list and print data
    for (const auto& node : myList) {
        std::cout << "Node data: " << node.getData() << std::endl;
    }

    return 0;
}
