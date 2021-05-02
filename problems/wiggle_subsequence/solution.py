class Solution:
    def wiggleMaxLength(self, nums: List[int]) -> int:
        c = 1
        p = nums[0]
        isInc = None   
        for i in range(1,len(nums)):
            if isInc == True:
                if nums[i]>p:
                    isInc = False
                    c+=1
            elif isInc == False:
                if nums[i]<p:
                    isInc=True
                    c+=1
            else:
                print(isInc)
                if nums[i]>p:
                    isInc=False
                    c+=1
                elif nums[i]<p:
                    isInc = True
                    c+=1
            p = nums[i]        
        return c  