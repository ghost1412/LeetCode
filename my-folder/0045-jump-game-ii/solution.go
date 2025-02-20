func jump(nums []int) int {
    if len(nums) == 1 {
        return 0 
    }
    maxCanJump := nums[0]
    currEnd := nums[0]
    jump := 1
    for i:=1; i<len(nums); i++ {
        maxCanJump = max(maxCanJump, nums[i]+i)
        if i == currEnd && i != len(nums)-1 {
            jump++;
            currEnd = maxCanJump
        }
    }
    return jump
}
