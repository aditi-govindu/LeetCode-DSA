/*
Q412. Description: Given an integer n, return a string array answer (1-indexed) where:
answer[i] == "FizzBuzz" if i is divisible by 3 and 5.
answer[i] == "Fizz" if i is divisible by 3.
answer[i] == "Buzz" if i is divisible by 5.
answer[i] == i (as a string) if none of the above conditions are true.
*/

class Solution {
    public List<String> fizzBuzz(int n) {
        List<String> solution = new ArrayList<String>();
        for(int i = 1; i <= n; i++)
        {
            if(i%3 == 0 && i%5 == 0)
                solution.add("FizzBuzz"); 
            else if(i%3 == 0)
                solution.add("Fizz");
            else if(i%5 == 0)
                solution.add("Buzz");
            else
                solution.add(Integer.toString(i));
        }
        return solution;
    }
}