#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length();
        int n = p.length();

        int s_ptr = 0;
        int p_ptr = 0; 
        
        int star_ptr = -1;     
        int s_match_ptr = 0; 

        while (s_ptr < m) {
            
            if (p_ptr < n && (p[p_ptr] == '?' || p[p_ptr] == s[s_ptr])) {
                s_ptr++;
                p_ptr++;
            }
            else if (p_ptr < n && p[p_ptr] == '*') {
                star_ptr = p_ptr;      
                s_match_ptr = s_ptr; 
                p_ptr++;            
            }
            else if (star_ptr != -1) {
                p_ptr = star_ptr + 1; 
                s_match_ptr++;       
                s_ptr = s_match_ptr; 
            }
            else {
                return false;
            }
        }

        while (p_ptr < n && p[p_ptr] == '*') {
            p_ptr++;
        }

        return p_ptr == n;
    }
};
