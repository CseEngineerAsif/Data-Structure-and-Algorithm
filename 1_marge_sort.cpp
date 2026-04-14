#include<bits/stdc++.h>
using namespace std;

void marge(int a[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int l[n1], r[n2];

    for(int i = 0; i < n1; i++)
        l[i] = a[left + i];

    for(int j = 0; j < n2; j++)
        r[j] = a[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while(i < n1 && j < n2)
    {
        if(l[i] <= r[j])
        {
            a[k] = l[i];
            i++;
        }
        else
        {
            a[k] = r[j];
            j++;
        }
        k++;
    }

    while(i < n1)
    {
        a[k] = l[i];
        i++;
        k++;
    }

    while(j < n2)
    {
        a[k] = r[j];
        j++;
        k++;
    }
}

void marge_sort(int a[], int left, int right)
{
    if(left >= right)
        return;

    int mid = (left + right) / 2;

    marge_sort(a, left, mid);
    marge_sort(a, mid + 1, right);

    marge(a, left, mid, right);
}

int main()
{
    int n;
    cout << "Enter size: ";
    cin >> n;

    int a[n];

    cout << "Enter elements: ";
    for(int i = 0; i < n; i++)
        cin >> a[i];

    marge_sort(a, 0, n - 1);

//    cout << "Sorted array: ";
//    for(int i = 0; i < n; i++)
//        cout << a[i] << " ";
//
//    cout<<endl;

    cout << "Sorted array decending order: ";
    for(int i = n-1; i >= 0; i--)
        cout << a[i] << " ";


    return 0;
}
