int maxChunksToSorted(int* arr, int arrSize) {
    int chunks = 0, prefixSum = 0, sortedPrefixSum = 0;

    for( int i=0; i<arrSize; i++){

        prefixSum += arr[i];

        sortedPrefixSum += i;

        if( prefixSum == sortedPrefixSum){
            chunks++;
        }
    }
    return chunks;
    
}