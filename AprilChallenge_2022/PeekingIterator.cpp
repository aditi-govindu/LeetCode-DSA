/*
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.
 *
 *  class Iterator {
 *		struct Data;
 * 		Data* data;
 *  public:
 *		Iterator(const vector<int>& nums);
 * 		Iterator(const Iterator& iter);
 *
 * 		// Returns the next element in the iteration.
 *		int next();
 *
 *		// Returns true if the iteration has more elements.
 *		bool hasNext() const;
 *	};
 */

/*
Q284. Description: Design an iterator that supports the peek operation on an existing iterator in addition to the hasNext and the next operations.

Implement the PeekingIterator class:
* PeekingIterator(Iterator<int> nums) Initializes the object with the given integer iterator iterator.
* int next() Returns the next element in the array and moves the pointer to the next element.
* boolean hasNext() Returns true if there are still elements in the array.
* int peek() Returns the next element in the array without moving the pointer.

Note: Each language may have a different implementation of the constructor and Iterator, but they all support the int next() and boolean hasNext() functions.
*/

class PeekingIterator : public Iterator {
    int *head;
    int pointer = 0;
    int len;
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
	    int n = nums.size();
        head = new int[n];
        // Initialize vector and set length of nums
        for(auto c : nums)
            head[pointer++] = c;
        pointer = 0;
        len = nums.size();
	}
	
    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        // Return element at top of head
        return head[pointer];
	}
	
	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
        // Return element at top of head and increment pointer to go to next
	    return head[pointer++];
	}
	
	bool hasNext() const {
        // If pointer crosses nums length, no next element exists
	    return pointer < len;
	}
};