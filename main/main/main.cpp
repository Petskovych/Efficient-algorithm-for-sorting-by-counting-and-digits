#include <iostream>
#include <vector>

 
void countingSort(int arr[], int n) {
    int max = arr[0], min = arr[0];
    
    for (int i = 1; i < n; ++i) {
        if (arr[i] > max)
            max = arr[i];
        if (arr[i] < min)
            min = arr[i];
    }
    int range = max - min + 1;  
    int* count = new int[range]();  

   
    for (int i = 0; i < n; ++i)
        count[arr[i] - min]++;

     
    for (int i = 0, j = 0; i < range; ++i)
        while (count[i]--)
            arr[j++] = i + min;

    
    delete[] count;
}

 
int getDigit(int num, int exp) {
    return (num / exp) % 10;
}

 void RadixSort(std::vector<int>& arr) {
    int max = *std::max_element(arr.begin(), arr.end());

    
    for (int exp = 1; max / exp > 0; exp *= 10) {
        std::vector<int> count(10, 0);  
        std::vector<int> output(arr.size()); // Вихідний масив

       
        for (int i = 0; i < arr.size(); ++i) {
            int digit = getDigit(arr[i], exp);
            count[digit]++;
        }

     
        for (int i = 1; i <10 ; ++i) {
            count[i] += count[i - 1];
        }
         
        for (int i = arr.size() - 1; i >= 0; --i) {
            int digit = getDigit(arr[i], exp);
            output[count[digit] - 1] = arr[i];
            count[digit]--;
        }
         
        for (int i = 0; i < arr.size(); ++i) {
            arr[i] = output[i];
        }
    }
}

int main() {
    int n;
    std::cout << "Enter the size of the array: ";
    std::cin >> n;

    std::vector<int> arr(n); // Створення вектора з розміром n

    std::cout << "Enter " << n << "-digit integer numbers:\n";
    for (int i = 0; i < n; ++i)
        std::cin >> arr[i];

   
    RadixSort(arr);
 
    std::cout << "Sorted array: ";
    for (int i = 0; i < n; ++i)
        std::cout << arr[i] << " ";
    std::cout << std::endl;

    return 0;
}
