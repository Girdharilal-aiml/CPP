// 11. The Magic Inventory Bag:
// Rule: Design a storage utility entity called InventoryBag. It must be capable of holding a fixed array of 10 items of any one specific data type.
// Rule: Include an integer to track how many items are currently inside. Write a method storeItem(item) that takes an item of that specific type and adds it to the array only if the bag isn't full.

#include "iostream"
using namespace std;

template<typename T>
class InventoryBag{
private:
    T items[10];
    int count=0;
public:
    void storeItem(T item){
        if(count<10){
            items[count] = item;
            count++;
        }
    }

    int getCount(){
        return count;
    }
};

int main(){
    InventoryBag<double> bag;
    bag.storeItem(3.14);
    bag.storeItem(2.71);
}