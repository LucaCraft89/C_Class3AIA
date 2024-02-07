#include <iostream>
#include <vector>

int main() {
    // Create a vector of integers
    std::vector<int> numbers;

    // Add elements to the vector
    numbers.push_back(10);
    numbers.push_back(20);
    numbers.push_back(30);

    // Access elements using indexing
    std::cout << "First element: " << numbers[0] << std::endl;
    std::cout << "Second element: " << numbers[1] << std::endl;
    std::cout << "Third element: " << numbers[2] << std::endl;

    // Iterate over the vector using a range-based for loop
    std::cout << "All elements: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Get the size of the vector
    std::cout << "Size of the vector: " << numbers.size() << std::endl;

    // Check if the vector is empty
    std::cout << "Is the vector empty? " << (numbers.empty() ? "Yes" : "No") << std::endl;

    // Clear the vector
    numbers.clear();

    // Check if the vector is empty after clearing
    std::cout << "Is the vector empty after clearing? " << (numbers.empty() ? "Yes" : "No") << std::endl;

    return 0;
}
