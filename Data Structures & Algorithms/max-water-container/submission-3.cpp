class Solution {
public:
    int maxArea(vector<int>& heights) {
        int currWater=0;
        int maxWater=0;

        int i=0;
        int j=heights.size()-1;

        while(i<j){
            int length=min(heights[i],heights[j]);
            int width=j-i;

            currWater=length * width;
            maxWater=max(maxWater,currWater);
        
            if(heights[i]<heights[j]){
                i++;
            }
            else{
                j--;
            }
        
        }
        return maxWater;
    }
};
