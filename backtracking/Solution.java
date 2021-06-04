/*
https://leetcode.com/problems/permutations/submissions/
Given a collection of distinct integers, return all possible permutations.

Example:

Input: [1,2,3]
Output:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
*/

import java.lang.*;
import java.util.*;
class Solution {
    void perm(List<List<Integer>> ans,LinkedHashSet<Integer> curr,int[] nums)
    {
        int n = nums.length;
        if(curr.size() == n){
            ans.add(new ArrayList<>(curr));
            return;
        }
        
        for(int i=0;i<n;i++)
        {
            if(curr.contains(nums[i]))   continue;
            
            curr.add(nums[i]);
            perm(ans,curr,nums);
           
            curr.remove(nums[i]);
        }
    }
    public List<List<Integer>> permute(int[] nums) {

        List<List<Integer>> ans = new ArrayList<>();

        perm(ans,new LinkedHashSet<Integer>(),nums);
        return ans;
    }
}
//Runner class
class Run
{
    public static void main(String args[])
    {
        Solution ob = new Solution();
        int a[] = {1,2,3};
        List<List<Integer>> ans = ob.permute(a);

        for(List<Integer> row : ans)
        {
            for(Integer val:row)
                System.out.print(val+",");
            System.out.println();
        }

    }
}