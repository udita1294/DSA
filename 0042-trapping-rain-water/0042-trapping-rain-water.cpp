class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int>L_max(n,0);
        vector<int>R_max(n,0);
        int Lmaxi = height[0];
        int Rmaxi = height[n-1];
        for(int i=0;i<n;i++){
            Lmaxi = max(Lmaxi,height[i]);
            L_max[i] = Lmaxi;
        }
        for(int i=n-1;i>=0;i--){
            Rmaxi = max(Rmaxi,height[i]);
            R_max[i] = Rmaxi;
        }
        int totalWater = 0;
        for(int i=0;i<n;i++){
            totalWater += min(L_max[i],R_max[i]) - height[i];
        }
        return totalWater;
    }
};