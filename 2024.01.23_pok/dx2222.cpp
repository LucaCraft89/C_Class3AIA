#include <iostream>
#include <vector>

void stalinSort(std::vector<int>& nums) {
    int maxNum = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] >= maxNum) {
            maxNum = nums[i];
        } else {
            nums.erase(nums.begin() + i);
            i--;
        }

        std::cout << "Iteration " << i << ": ";
        for (int num : nums) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    std::vector<int> nums = {4, 2, 7, 1, 5, 3, 6};
    
    std::cout << "Before Stalin sort: ";
    for (int num : nums) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    
    stalinSort(nums);
    
    std::cout << "After Stalin sort: ";
    for (int num : nums) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    
    return 0;
}
