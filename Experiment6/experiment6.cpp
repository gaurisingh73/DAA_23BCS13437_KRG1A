class Solution{
bool isSubsetSumRec(vector<int>& arr, int n, int sum) {

    if (sum == 0)
        return true;
    if (n == 0)
        return false;
    if (arr[n - 1] > sum)
        return isSubsetSumRec(arr, n - 1, sum);
    return isSubsetSumRec(arr, n - 1, sum) 
      		|| isSubsetSumRec(arr, n - 1, sum - arr[n - 1]);
}

bool isSubsetSum(vector<int>& arr, int sum) {
    return isSubsetSumRec(arr, arr.size(), sum);
}};
