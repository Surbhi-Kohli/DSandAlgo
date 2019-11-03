/*Given the time in numerals we may convert it into words, as shown below:

At minutes=0, use o' clock. For 1<=minutes<=30 , use past, and for minutes>30 use to. Note the space between the apostrophe and clock in o' clock. Write a program which prints the time in words for the input given in the format described.

Function Description

Complete the timeInWords function in the editor below. It should return a time string as described.

timeInWords has the following parameter(s):

h: an integer representing hour of the day
m: an integer representing minutes after the hour
Input Format

The first line contains h, the hours portion The second line contains m , the minutes portion

Constraints
1<=h<=12
0<=m<60

Output Format

Print the time in words as described.

Sample Input 0

5
47
Sample Output 0

thirteen minutes to six  */
// Complete the timeInWords function below.
string timeInWords(int h, int m) {
map <int,string> time;  
time[0]="o' clock";
time[1]="one";
time[2]="two";
time[3]="three";
time[4]="four";
time[5]="five";
time[6]="six";
time[7]="seven";
time[8]="eight";
time[9]="nine";
time[10]="ten";
time[11]="eleven";
time[12]="twelve";
time[13]="thirteen";
time[14]="fourteen";
time[15]="fifteen";
time[16]="sixteen";
time[17]="seventeen";
time[18]="eighteen";
time[19]="nineteen";
time[20]="twenty";
time[21]="twenty one";
time[22]="twenty two";
time[23]="twenty three";
time[24]="twenty four";
time[25]="twenty five";
time[26]="twenty six";
time[27]="twenty seven";
time[28]="twenty eight";
time[29]="twenty nine";


string ans="";
if(m==0)
{
    ans=ans+time[h]+" o' clock";
}
else if(m==30)
ans=ans+"half past "+time[h];


else if(m==15)
ans=ans+"quarter past "+time[h];
else if(m>30)
{
    if(m==59 && h==12)
     ans=ans+time[60-m]+" minute to one";
     else if(m==59)
     ans=ans+time[60-m]+"minute to "+time[h+1];
     else if(m==45)
     ans=ans+"quarter to "+time[h+1];

    
     else
     ans=ans+time[60-m]+" minutes to "+time[h+1];

}
else if(m==1)
{
    ans=ans+time[m]+" minute past "+time[h];
}
else
ans=ans+time[m]+" minutes past "+time[h];
return ans;
}
