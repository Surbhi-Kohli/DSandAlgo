/*
Maximum profit from sale of wines
Given n wines in a row, with integers denoting the cost of each wine respectively. Each year you have to sell either the first or the last wine in the row. However, the price of wines increases over time. Let the initial profits from the wines be P1, P2, P3…Pn. On the Yth year, the profit from the ith wine will be Y*Pi. So it is clear that n bottles will take n years to sell.

Find the maximum profit u can make by selling all the bottles


*/
#include <iostream>
#include<climits>
using namespace std;

int minCoins(int wine[],int i,int j,int dp[][100],int year)
{
   if(i>j)
   return 0;
   if(dp[i][j]!=0)
   return dp[i][j];
 
   int op1=wine[i]*year+minCoins(wine,i+1,j,dp,year+1);
   int op2=wine[j]*year+minCoins(wine,i,j-1,dp,year+1);
  
   
   dp[i][j]=max(op1,op2);
   return dp[i][j];
   
}


int main() {
	
	int wine[]={2,3,5,1,4};
	int dp[100][100]={0};
	int end=sizeof(wine)/sizeof(int);
	cout<<minCoins(wine,0,end-1,dp,1); //50
	return 0;
}
