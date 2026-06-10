class Solution {
    /**
     * @param {number} n
     * @return {number}
     */
    climbStairs(n) {
        return this.recur(n)
    }

    recur(x){
        if(x<=1){
           return 1;
        }
        if(x==2)
         return 2;

      return  this.recur(x-1)+this.recur(x-2);  
    }
}
