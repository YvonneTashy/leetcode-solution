#include <iostream>
#include <vector>
using namespace std;

// Heapify a subtree rooted at index i
void heapify(vector<int> &nums, int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && nums[left] > nums[largest])
        largest = left;

    if (right < n && nums[right] > nums[largest])
        largest = right;

    if (largest != i)
    {
        swap(nums[i], nums[largest]);
        heapify(nums, n, largest);
    }
}

// Heap sort
void heapSort(vector<int> &nums)
{
    int n = nums.size();

    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(nums, n, i);

    // Extract elements from heap
    for (int i = n - 1; i > 0; i--)
    {
        swap(nums[0], nums[i]);
        heapify(nums, i, 0);
    }
}

int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements separated by space: ";
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    heapSort(nums);

    cout << "Sorted array: ";
    for (int num : nums)
        cout << num << " ";
    cout << endl;

    return 0;
}
