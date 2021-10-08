def bin_search(l,r,ele,arr):
    
    if r>=l:
        mid=int((l+r)/2)
        if arr[mid]==ele:
            return mid
        elif arr[mid]>ele:
            return bin_search(l,mid-1,ele,arr)
        else:
            return bin_search(mid+1,r,ele,arr)
    else:
        return -1
