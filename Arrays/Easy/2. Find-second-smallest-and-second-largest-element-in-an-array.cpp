// Bruteforce
vector<int> getSecondOrderElements(int n, vector<int> a) {
    sort(a.begin(), a.end());

    return {a[n-2], a[1]};
}

// Time Complexity: O(NlogN), For sorting the array
// Space Complexity: O(1)


// Better
vector<int> getSecondOrderElements(int n, vector<int> arr) {
    int min=INT_MAX;
    int max=INT_MIN;

    for(int i=0; i<n; i++) {
        if(arr[i]>max) max=arr[i];
        if(arr[i]<min) min=arr[i];
    }

    int sec_max=INT_MIN, sec_min=INT_MAX;

    for(int i=0; i<n; i++)
    {
        if(arr[i]!=max && arr[i]>sec_max) sec_max=arr[i];
        if(arr[i]!=min && arr[i]<sec_min) sec_min=arr[i];
    }
    return {sec_max, sec_min};
}

// Time Complexity: O(N), We do two linear traversals in our array
// Space Complexity: O(1)


// Optimal

vector<int> getSecondOrderElements(int n, vector<int> arr) {
    int max=INT_MIN, min=INT_MAX;

    int sec_max=INT_MIN, sec_min=INT_MAX;

    for(int i=0; i<n; i++) {

        // when you get the max element then the current max element whold be your second largest max
        if(arr[i]>max) sec_max=max, max=arr[i]; 
        else if(arr[i]!=max && arr[i]>sec_max) sec_max=arr[i];

        if(arr[i]<min) sec_min=min,  min=arr[i];
        else if(arr[i]!=min && arr[i]<sec_min) sec_min=arr[i];

    }


    return {sec_max, sec_min};
}

// Time Complexity: O(N), Single-pass solution
// Space Complexity: O(1)

