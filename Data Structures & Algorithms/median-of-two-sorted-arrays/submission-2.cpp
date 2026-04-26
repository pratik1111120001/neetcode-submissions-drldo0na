class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size(), mid = (n+m+1)/2;
        if(m<n){
            swap(nums1,nums2);
            swap(n,m);
        }
        int i = 0, j = n;
        while(i <= j)
        {
            int curr1 = (i + j)/2;
            int curr2 = mid - curr1;

            int nums1Left = curr1>0 ? nums1[curr1-1] : INT_MIN;
            int nums1Right = curr1<n ? nums1[curr1] : INT_MAX;
            int nums2Left = curr2>0 && curr2-1<m ? nums2[curr2-1] : INT_MIN;
            int nums2Right = curr2<m ? nums2[curr2] : INT_MAX;

            // int nums1Left= INT_MIN;
            // int nums1Right = INT_MAX;
            // int nums2Left = INT_MIN;
            // int nums2Right = INT_MAX;
            
            cout<<nums1Left<<" "<<nums1Right<<" "<<nums2Left<<" "<<nums2Right<<" "<<i<<" "<<j<<endl;

            if(nums1Left <= nums2Right && nums2Left <= nums1Right){
                if((n + m) % 2 ){
                    return max(nums1Left, nums2Left);
                }
                else{
                    return (1.0*(max(nums1Left,nums2Left) + min(nums1Right,nums2Right)))/2.0;
                }
            }
            if(nums1Left > nums2Right){
                j = curr1 - 1;
            }
            else{
                i = curr1 + 1;
            }
        }
        return -1;
    }
};
