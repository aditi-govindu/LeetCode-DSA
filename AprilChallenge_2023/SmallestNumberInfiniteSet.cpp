/*
Q2336. Description: You have a set which contains all positive integers [1, 2, 3, 4, 5, ...].

Implement the SmallestInfiniteSet class:

SmallestInfiniteSet() Initializes the SmallestInfiniteSet object to contain all positive integers.
int popSmallest() Removes and returns the smallest integer contained in the infinite set.
void addBack(int num) Adds a positive integer num back into the infinite set, if it is not already in the infinite set.
*/

class SmallestInfiniteSet {
public:
    int currentInteger;
    set<int> array;

    SmallestInfiniteSet() 
    {
        currentInteger = 1;   
    }
    
    int popSmallest() 
    {
        // Numbers are stored in sorted set. Return first element and pop it from set
        int ans;
        if(!array.empty())
        {
            ans = *array.begin();
            array.erase(array.begin());
        }
        else
        {
            // Smallest number is current number in set
            ans = currentInteger;
            currentInteger++;
        }
        return ans;
    }
    
    void addBack(int num) 
    {
        // Add element if not in the set
        if(currentInteger <= num || array.find(num) != array.end())
            return;
        array.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */