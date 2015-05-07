class Solution {
public:
  /***********method 1*************/
  
  /*  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
    {
        vector<int> nums3;
        nums3.resize(m + n);
        int i = 0, j =0;
        int k = 0;
        while(i < m && j < n)
        {
            if(nums1[i] < nums2[j])
            {
                nums3[k] = nums1[i];
                i++;
            }
            else
            {
                nums3[k] = nums2[j];
                j++;
            }
            k++;
        }
        while(i < m)
        {
            nums3[k++] = nums1[i++];
        }
        while(j < n)
        {
            nums3[k++] = nums2[j++];
        }
        nums1 = nums3;
    }*/
    /***********method 2*************/
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
{
	int start = 0;
	int j;
	for(int i = 0; i < n; i++)
	{

		for(j = start; j < m + i; j++)
		{
			if(nums2[i] < nums1[j])break;
				
		}
		for(int k = m + i - 1; k >= j; k--)
		{
			nums1[k + 1] = nums1[k];

		}
		nums1[j] = nums2[i]; 
		start = j;
	}
}
    
};