
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>

using namespace std;

template <typename T>
size_t partition(vector<T>& data, size_t start, size_t end) {
  const auto& pivot = data[end];
  size_t current_small_loc = start;  // 검은색 지시자

  // i 가 빨간색 지시자 역할을 한다.
  for (size_t i = start; i <= end; i++) {
    if (data[i] <= pivot) {
      swap(data[current_small_loc++], data[i]);
    }
  }
  return current_small_loc - 1;
}



template <typename T>
void quicksort(vector<T>& data, size_t start, size_t end) {
  if (start >= end) {
    return;
  }
  size_t pivot_pos = partition(data, start, end);
  quicksort(data, start, pivot_pos - 1);
  quicksort(data, pivot_pos + 1, end);
}


int main()
{
    int arr[10000];
    int n;
    // scanf("%d",&n);

    // for(int i = 0 ; i < n ; i++)
    // {
    //     scanf("%d",&arr[i]);
    // }
    // vector<int> vec(arr,arr+n);
    vector<int> vec;
    vec.push_back(2);
    vec.push_back(52);
    vec.push_back(457);
    vec.push_back(662426);
    vec.push_back(13);
    vec.push_back(4242);
    vec.push_back(2352);
    vec.push_back(5);
    vec.push_back(3);
    for(int i = 0 ; i < vec.size() ; i++)
        {
            printf("%d ",vec.at(i));
        }
    printf("\n");
    quicksort(vec,0,vec.size()-1);

    for(int i = 0 ; i < vec.size() ; i++)
    {
        printf("%d ",vec.at(i));
    }
    printf("\n");
    
}