func canJump(nums []int) bool {
    maxCanJump := 0

    for i:=0; i<len(nums); i++ {
        if i <= maxCanJump {
            maxCanJump = max(maxCanJump, i+nums[i])
        } else {
            return false;
        }
    }
    return maxCanJump >= len(nums) - 1;
}
