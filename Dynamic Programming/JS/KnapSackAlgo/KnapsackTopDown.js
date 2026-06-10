
/**
 * @param {number} W
 * @param {number[]} val
 * @param {number[]} wt
 * @returns {number}
 */

class Solution {
     constructor() {
        this.matrix = [];
    }

    knapsack(W, val, wt) {
        let n = val.length;
        
        // EASIER ALTERNATIVE: Setup matrix with simple loops
        this.matrix = [];
        for (let i = 0; i <= W; i++) {
            this.matrix[i] = [];
            for (let j = 0; j <= n; j++) {
                this.matrix[i][j] = -1;
            }
        }
        
        return this.myKnapsack(W, val, wt, n);
    }
 myKnapsack(W,val,wt,n){
     
             if (n === 0 || W === 0) {
            return 0;
        }

        if(this.matrix[W][n]!=-1){
            return this.matrix[W][n];
        }
     if (wt[n - 1] <= W) {
            this.matrix[W][n] = Math.max(
                val[n - 1] + this.myKnapsack(W - wt[n - 1], val, wt, n - 1),
                this.myKnapsack(W, val, wt, n - 1)
            );
        } else {
            this.matrix[W][n] = this.myKnapsack(W, val, wt, n - 1);
        }
        return this.matrix[W][n];
    }
}
