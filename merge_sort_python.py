n, m = map(int, input().split())

ara = list(map(int, input().split(" ")))

def merge_sort(lo, hi):
    if (lo == hi):
        return
    
    mid = lo + (hi - lo)//2

    merge_sort(lo, mid)
    merge_sort(mid+1, hi)

    temp = [-1 for i in range(hi-lo+1)]
    i = lo
    j = mid+1
    k = 0
    kk = lo

    while kk <= hi:
        if i == mid+1:
            temp[k] = ara[j]
            j += 1
        elif j == hi+1:
            temp[k] = ara[i]
            i += 1
        elif ara[i] < ara[j]:
            temp[k] = ara[i]
            i += 1
        else:
            temp[k] = ara[j]
            j += 1

        # last
        k += 1
        kk += 1

    k = 0
    kk = lo

    while kk <= hi:
        ara[kk] = temp[k]
        # last
        k += 1
        kk += 1

merge_sort(0, n-1)
