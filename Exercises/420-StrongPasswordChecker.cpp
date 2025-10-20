#include <iostream>
#include <string>
#include <vector>
#include <queue> 
#include <algorithm> 

using namespace std;

class Solution {
public:
    int strongPasswordChecker(string password) {
        int n = password.length();

        bool hasLower = false, hasUpper = false, hasDigit = false;
        for (char c : password) {
            if (islower(c)) hasLower = true;
            if (isupper(c)) hasUpper = true;
            if (isdigit(c)) hasDigit = true;
        }
        int missingTypes = (hasLower ? 0 : 1) + (hasUpper ? 0 : 1) + (hasDigit ? 0 : 1);
        vector<int> repeats;
        for (int i = 0; i < n; ) {
            char c = password[i];
            int count = 0;
            while (i < n && password[i] == c) {
                count++;
                i++;
            }
            if (count >= 3) {
                repeats.push_back(count);
            }
        }
        
        int totalRepeatChanges = 0;
        for (int L : repeats) {
            totalRepeatChanges += L / 3;
        }

        if (n < 6) {
            int insertNeeded = 6 - n;
            return max(insertNeeded, missingTypes);
        }

        if (n >= 6 && n <= 20) {
            return max(missingTypes, totalRepeatChanges);
        }

        if (n > 20) {
            int deleteNeeded = n - 20;
            int steps = deleteNeeded; 

           
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
            for (int L : repeats) {
                pq.push({L % 3, L});
            }

            int d = deleteNeeded;
            while (d > 0 && !pq.empty()) {
                auto [mod, L] = pq.top();
                pq.pop();
                int removeCount = min(d, mod + 1); 
                
                d--;
                L--;

                if (mod == 0) {
                    totalRepeatChanges--;
                }
                
                if (L >= 3) {
                    pq.push({L % 3, L});
                }
            }
            
            if (d > 0) {
                 totalRepeatChanges -= d / 3;
            }
            steps += max(missingTypes, totalRepeatChanges);
            return steps;
        }
        
        return 0; 
    }
};