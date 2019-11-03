/*
Given a time in 12-hour AM/PM format, convert it to military (24-hour) time.

Note: Midnight is 12:00:00AM on a 12-hour clock, and 00:00:00 on a 24-hour clock. Noon is 12:00:00PM on a 12-hour clock, and 12:00:00 on a 24-hour clock.

Function Description

Complete the timeConversion function in the editor below. It should return a new string representing the input time in 24 hour format.

timeConversion has the following parameter(s):

s: a string representing time in 12 hour format
Input Format
A single string s containing a time in 12-hour clock format (i.e.hh:mm:ss AM orhh:mm:ss PM ), where 01<=hh<=12 and 00<=mm,ss<=59.

Constraints

All input times are valid
Output Format

Convert and print the given time in 24-hour format, where 00<=hh<=23.

Sample Input 0

07:05:45PM
Sample Output 0

19:05:45


We only need to change the hours to convert the time from an AM/PM format to 24 hour format. 
We need to add +12 to the hours if the time is in PM. We need to take care of 12:mm:ssAM types 
additionally as 12:mm:ssAM in a 24 hour format is 00:mm:ss. 12:mm:ssPM type values in 24 hour format are in the form 12:mm:ss.


*/
#include<iostream>
#include<cstdio>

using namespace std;

int main() {
    string s;
    cin >> s;

    int n = s.length();
    int hh, mm, ss;
    hh = (s[0] - '0') * 10 + (s[1] - '0');
    mm = (s[3] - '0') * 10 + (s[4] - '0');
    ss = (s[6] - '0') * 10 + (s[7] - '0');

    if (hh < 12 && s[8] == 'P') hh += 12;
    if (hh == 12 && s[8] == 'A') hh = 0;

    printf("%02d:%02d:%02d\n", hh, mm, ss);

    return 0;
}
