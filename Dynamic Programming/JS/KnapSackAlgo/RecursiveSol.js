/**
 * @param {number} W
 * @param {number[]} val
 * @param {number[]} wt
 * @returns {number}
 */

class Solution {
    knapsack(W, val, wt) {
        // code here
        let n = val.length-1;
        return this.myKnapsack(W,val,wt,n);
        return ans;
    }
 myKnapsack(W,val,wt,n){
        if(n<0|| W==0){
            return 0;
        }
        if(wt[n]<=W)
        return Math.max((val[n]+this.myKnapsack(W-wt[n],val,wt,n-1)), this.myKnapsack(W,val,wt,n-1))
        
        else
        return this.myKnapsack(W,val,wt,n-1);
    }
}
