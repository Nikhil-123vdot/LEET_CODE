class Solution {
public:
    void merge(vector<int>& nums, int s, int mid, int e)
    {
        vector<int> merger(e - s + 1);

        int left = s;
        int right = mid + 1;
        int index = 0;

        while(left <= mid && right <= e)
        {
            if(nums[left] <= nums[right])
            {
                merger[index++] = nums[left++];
            }
            else
            {
                merger[index++] = nums[right++];
            }
        }

        while(left <= mid)
        {
            merger[index++] = nums[left++];
        }

        while(right <= e)
        {
            merger[index++] = nums[right++];
        }

        index = 0;

        while(s <= e)
        {
            nums[s++] = merger[index++];
        }
    }

    void mergeSort(vector<int>& nums, int s, int e)
    {
        if(s >= e)
            return;

        int mid = s + (e - s) / 2;

        mergeSort(nums, s, mid);
        mergeSort(nums, mid + 1, e);

        merge(nums, s, mid, e);
    }

    vector<int> sortArray(vector<int>& nums)
    {
        int n = nums.size();

        mergeSort(nums, 0, n - 1);

        return nums;
    }
};