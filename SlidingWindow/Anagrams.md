

Count Occurences of Anagrams
MediumAccuracy: 48.09%Submissions: 72K+Points: 4
Fast-Track your resumes to top tech companies and get the job you deserve! Register for Job-A-Thon Hiring Challenge  

banner
Given a word pat and a text txt. Return the count of the occurrences of anagrams of the word in the text.

Example 1:

Input:
txt = forxxorfxdofr
pat = for
Output: 3
Explanation: for, orf and ofr appears
in the txt, hence answer is 3.
Example 2:

Input:
txt = aabaabaa
pat = aaba
Output: 4
Explanation: aaba is present 4 times
in txt.
Your Task:
Complete the function search() which takes two strings pat, txt, as input parameters and returns an integer denoting the answer. 
You don't need to print answer or take inputs.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(26) or O(256)

Constraints:
1 <= |pat| <= |txt| <= 105
Both strings contain lowercase English letters.

 

Company Tags
Topic Tags
Related Interview Experiences
If you are facing any issue on this page. Please let us know.
Output Window
Suggest Feedback
Compilation Completed
For Input: 
the code is not passing all test cases
```

//User function Template for javascript


/**
 * @param {string} pat
 * @param {string} txt
 * @return {number}
*/

class Solution {
    search(pat,txt){
       //code here
       let map= new Map();
       let count=0,finalAns=0;
       for(let i=0;i<pat.length;i++){
          if(!map.has(pat[i]))
          { 
              map.set(pat[i],1);
              count++;
          }
          else{
              let val=map.get(pat[i]);
              map.set(pat[i],val++);
          }
       }
      // console.log(count)
       let i=0,j=0;
       let k=pat.length;
       while(i<txt.length && j<txt.length){
            // console.log(map)
           if(j-i+1<=k){
               //console.log(txt[j]);
              
               if(map.has(txt[j])){
                  console.log("map has" , txt[j] ," ie:" ,map.get(txt[j]));
                  let val = map.get(txt[j]);
                
                  if(val>0){
                    map.set(txt[j], val - 1);
                //   console.log(map);
                   if(map.get(txt[j])==0 && count!=0)
                   count--;
                  }
               }
               if(j-i+1==k){
                  console.log("i: ",i," j: ",j)
                  console.log("count: ",count);
                    if(count==0)
                    finalAns++;
                   
                        if(map.has(txt[i]))
                        {
                            let val= map.get(txt[i])
                            map.set(txt[i],val+1);
                            if(map.get(txt[i])==1)
                                count++;
                        
                        }
                        
                    
                    i++;
               }
              
           }
            j++;
       }
       //console.log("finalAns: ",finalAns);
       return finalAns;
    }
}
```

