/*
You wish to buy video games from the famous online video game store Mist.

Usually, all games are sold at the same price,p dollars. However, they are
planning to have the seasonal Halloween Sale next month in which you can 
buy games at a cheaper price. Specifically, the first game you buy during the sale will be sold at p dollars,
but every subsequent game you buy will be sold at exactly d dollars less than the cost of the previous one
you bought. This will continue until the cost becomes less than or equal to m dollars, after which every game you buy will cost m dollars each.

For example, if p=20,d=3  and m=6 , then the following are the costs of the first 11 games you buy, in order:
20,17,14,11,8,6,6,6,6,6,6
You have s dollars in your Mist wallet. How many games can you buy during the Halloween Sale?

Input Format
The first and only line of input contains four space-separated integers p,d,m and s.
Constraints
1<=m<=p<=100
1<=d<=100
1<=s<=10^4

Output Format
Print a single line containing a single integer denoting the maximum number of games you can buy.

Sample Input   Sample Output
20 3 6 80       6
*/
int howManyGames(int p, int d, int m, int s) {
    // Return the number of games you can buy
    int moneyLeft=s;
    int count=0;
    while(true)
    {//  cout<<"moneyLeft"<<moneyLeft<<endl;
    //    cout<<"gift's price"<<p<<endl;
         if(moneyLeft<p)
           break;
            moneyLeft-=p;
             count++;
             if(p!=m&&p-d>m)
            {//   cout<<p<<"!="<<m<<endl;
            //    cout<<"P-d is"<<p-d<<endl;
               p-=d;
             }
            else {
         p=m;
            }

    }
return count;
}
