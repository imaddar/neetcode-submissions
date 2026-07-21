class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        start, end = 0, len(numbers) - 1
        while start < end:
            total = numbers[start] + numbers[end]
            print(numbers[start], numbers[end], total, target)
            if total > target:
                end -= 1
            elif total < target:
                start += 1
            else:
                return [start + 1, end + 1]
        return [start + 1, end + 1]
