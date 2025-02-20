func removeDuplicates(nums []int) int {
    currFreq := 1
    k := 1

    for i:=1; i<len(nums); i++ {
        if nums[i] == nums[i-1]{
            if (currFreq < 2) {
                nums[k] = nums[i]
                k++;
            }
            currFreq++;
        } else { 
            currFreq = 1;
            nums[k] = nums[i];
            k++;
        }
    }
    return k;
}
