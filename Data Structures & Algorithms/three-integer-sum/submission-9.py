class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        # first we hash
        # then we sort
        # then we two pointer schema, target is the index in the hash
        # if we find target we have a successful triplet
        # add triplets to a set, cast set as list
        nums = sorted(nums)
        triplets = []
        print(nums)
        for i, target in enumerate(nums):
            if target > 0:
                break
            if i > 0 and target == nums[i - 1]:
                continue

            l, r = i + 1, len(nums) - 1
            while l < r:
                total = nums[l] + nums[r]
                # print(nums[l], nums[r], total, nums[target])
                if total < -target:
                    l += 1 
                elif total > -target:
                    r -= 1
                else:
                    triplets.append([nums[l], nums[r], target])
                    l += 1
                    r -= 1
                    while nums[l] == nums[l - 1] and l < r:
                        l += 1

                    
        return triplets