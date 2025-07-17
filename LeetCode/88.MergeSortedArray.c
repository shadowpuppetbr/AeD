#include<stdio.h>

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n);
int main(){
  int nums1[10], nums2[10];
  // Initialize nums1 and nums2 with some values
  for (int i = 0; i < 10; i++) {
    nums1[i] = (i < 5) ? i * 2 : 0; // First 5 elements with values, rest 0
    nums2[i] = i + 1;               // nums2 with values from 1 to 10
  }

  merge(nums1, 10, 5, nums2, 5, 5);
  for (int i = 0; i < 10; i++) {
    printf("%d ", nums1[i]);
  }
  printf("\n");
}


void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int i = m-1, j= n-1 , k = (n+m -1);
    printf(" ");
    while( i>=0 && j>=0 ){
        if(nums1[i] > nums2[j]){
            nums1[k]=nums1[i];
            i--;
            k--;
        } else {
            nums1[k] = nums2[j];
            j--;
            k--;
        }
        
    }
    while(i>=0)
        nums1[k--]= nums1[i--];
    while(j>=0)
        nums1[k--]=nums2[j--];

}
