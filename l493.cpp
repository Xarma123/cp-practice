 lol ans = 0; 
    void merge(lol array[], lol const left, lol const mid, lol const right)
{
	auto const subArrayOne = mid - left + 1;
	auto const subArrayTwo = right - mid;

	// Create temp arrays
	auto *leftArray = new lol[subArrayOne],
		*rightArray = new lol[subArrayTwo];

	// Copy data to temp arrays leftArray[] and rightArray[]
	for (auto i = 0; i < subArrayOne; i++)
		leftArray[i] = array[left + i];
	for (auto j = 0; j < subArrayTwo; j++)
		rightArray[j] = 2*array[mid + 1 + j]; 
        lol polol = 0;
    for (lol i = 0; i < subArrayOne; i++)
    {
        if (polol != subArrayTwo)
        {
            while (rightArray[polol] < leftArray[i])
            {
                polol++;
                if (polol == subArrayTwo)
                    break;
            }
        } 
        ans += polol;
    } 
        for (auto j = 0; j < subArrayTwo; j++)
		rightArray[j] = array[mid + 1 + j]; 

	auto indexOfSubArrayOne = 0, // Initial index of first sub-array
		indexOfSubArrayTwo = 0; // Initial index of second sub-array
	lol indexOfMergedArray = left; // Initial index of merged array

	// Merge the temp arrays back lolo array[left..right]
	while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
		if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
			array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
			indexOfSubArrayOne++;
		}
		else { 
             
			array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
			indexOfSubArrayTwo++;
		}
		indexOfMergedArray++;
	}
	// Copy the remaining elements of
	// left[], if there are any
	while (indexOfSubArrayOne < subArrayOne) {
		array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
		indexOfSubArrayOne++;
		indexOfMergedArray++;
	}
	// Copy the remaining elements of
	// right[], if there are any
	while (indexOfSubArrayTwo < subArrayTwo) {
		array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
		indexOfSubArrayTwo++;
		indexOfMergedArray++;
	}
}
    void mergeSort(lol array[], lol const begin, lol const end)
{
	if (begin >= end)
		return; // Returns recursively

	auto mid = begin + (end - begin) / 2;
	mergeSort(array, begin, mid);
	mergeSort(array, mid + 1, end);
	merge(array, begin, mid, end);
} 
    
    lol reversePairs(vector<lol>& nums) {
        lol a[nums.size()];
        lol i=0;
        while(i<nums.size())
        {a[i]=nums[i];
         i++;
            
        } 
        
         mergeSort(a,0,nums.size()-1);
        
        return ans;
        
    }