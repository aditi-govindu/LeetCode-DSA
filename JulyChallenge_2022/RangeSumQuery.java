/*
Q307. Description: Given an integer array nums, handle multiple queries of the following types:

Update the value of an element in nums.
Calculate the sum of the elements of nums between indices left and right inclusive where left <= right.
Implement the NumArray class:

NumArray(int[] nums) Initializes the object with the integer array nums.
void update(int index, int val) Updates the value of nums[index] to be val.
int sumRange(int left, int right) Returns the sum of the elements of nums between indices left and right inclusive (i.e. nums[left] + nums[left + 1] + ... + nums[right]).
*/

class NumArray 
{
    private int[] b;
    private int len;
    private int[] nums;

    public NumArray(int[] nums) 
    {
        this.nums = nums;
        double l = Math.sqrt(nums.length);
        len = (int) Math.ceil(nums.length/l);
        b = new int [len];
        for (int i = 0; i < nums.length; i++)
            b[i / len] += nums[i];
    }
    
    public void update(int index, int val) {
        int b_l = index / len;
        b[b_l] = b[b_l] - nums[index] + val;
        nums[index] = val;
    }
    
    public int sumRange(int i, int j) 
    {
        int sum = 0;
        int startBlock = i / len;
        int endBlock = j / len;
        if (startBlock == endBlock) 
        {
            for (int k = i; k <= j; k++)
                sum += nums[k];
        } 
        else 
        {
            for (int k = i; k <= (startBlock + 1) * len - 1; k++)
                sum += nums[k];
            for (int k = startBlock + 1; k <= endBlock - 1; k++)
                sum += b[k];
            for (int k = endBlock * len; k <= j; k++)
                sum += nums[k];
        }
        return sum;
    }
}

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(index,val);
 * int param_2 = obj.sumRange(left,right);
 */