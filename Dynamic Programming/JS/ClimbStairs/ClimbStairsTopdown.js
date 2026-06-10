class Solution {
    /**
     * @param {number} n
     * @return {number}
     */
    constructor() {
        this.arr = [];
    }
    climbStairs(n) {
        for(let i = 1;i<=n;i++){
            this.arr[i]= -1;
        }
        return this.recur(n)
    }

    recur(x){
        if (x <= 1) return 1;
        if (x === 2) return 2;

        
        if (this.arr[x] !== -1) {
            return this.arr[x];
        }

      this.arr[x] = this.recur(x-1)+this.recur(x-2);  
      return this.arr[x];
    }
}
