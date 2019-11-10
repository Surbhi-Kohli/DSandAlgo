/*
Gary is an avid hiker. He tracks his hikes meticulously, paying close attention to small details like topography. During his last hike he took exactly n steps. For every step he took, he noted if it was an uphill,U , or a downhill, D step. Gary's hikes start and end at sea level and each step up or down represents a 1 unit change in altitude. We define the following terms:

A mountain is a sequence steps above sea level, starting with a step up from sea level and ending with a step down to sea level.
A valley is a sequence steps below sea level, starting with a step down from sea level and ending with a step up to sea level.
Given Gary's sequence of up and down steps during his last hike, find and print the number of valleys he walked through.

For example, if Gary's path is s=[DDUUUUDD], he first enters a valley 2 units deep. Then he climbs out an up onto a mountain 2 units high. Finally, he returns to sea level and ends his hike.

Function Description
Complete the countingValleys function in the editor below. It must return an integer that denotes the number of valleys Gary traversed.

countingValleys has the following parameter(s):

n: the number of steps Gary takes
s: a string describing his path
Input Format

The first line contains an integer n , the number of steps in Gary's hike.
The second line contains a single string s, of n characters that describe his path.

Constraints
2<=n<=10^6
s[i] E {U,D}

Output Format
Print a single integer that denotes the number of valleys Gary walked through during his hike.

Sample Input

8
UDDDUDUU

Sample Output
1*/
int countingValleys(int n, string s) {
  
        int v = 0;     // # of valleys
        int lvl = 0;   // current level
        for(int i=0;i<n;i++){

            if(s[i] == 'U') ++lvl;
            if(s[i] == 'D') --lvl;
            
            // if we just came UP to sea level
            if(lvl == 0 && s[i] == 'U')
                ++v;
        }
        return v;

}
