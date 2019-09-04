# 各种排序

## 快速排序

快排的设计思想

![快排](/图片资源/快排.png)

设计代码

递归版

```C++
    void Quick_Sort(int *arr,int l,int r){
        if(l>=r)return;
        int val=arr[l];
        int i=l,j=r;
        while(i<j){
            while(i<j&&arr[j]>val)
                j--;
            swap(arr[i],arr[j]);
            while(i<j&&arr[i]<val)
                i++;
            swap(arr[i],arr[j]);
        }
        //左半部分开始遍历
        Quick_Sort(arr,l,i-1);
        //右半部分开始遍历
        Quick_Sort(arr,i+1,r);
    }
```

非递归版的

```C++
    void Quick_Sort(int *arr,int l,int r){
        //先存大再存小，取得时候就可以先取小再取大，大小是指的是数组的索引值
        stack<int> lowHight;
        lowHight.push(r);
        lowHight.push(l);
        while(!lowHight.empty()){
            int i=lowHight.top();
            lowHight.pop();
            int j=lowHight.top();
            lowHight.pop();
            if(i>=j)continue;
            int val=a[l];
            while(i<j){
                while(i<j&&val<arr[j])
                    j--;
                swap(arr[j],arr[i]);
                while(i<j&&val>arr[i])
                    i++;
                swap(arr[i],arr[j]);
            }
            //栈的先进后出特性，先处理左边的数据
            //右边
            lowHight.push(r);
            lowHight.push(i+1);
            //左边
            lowHight.push(i-1);
            lowHight.push(l);
        }
    }
```

## 梳排序

梳排序是冒泡排序的一种改进方式,为此先把冒泡排序写上来，两者互相对比

冒泡排序

```C++
    void Buddle_Sort(int *arr,int l,int r){
        if(l>=r)return;
        for(int i=l;i<r;i++){
            for(int j=i;j<r-i;j++){
                if(arr[j]>arr[j+1])
                    swap(arr[j],arr[j+1]);
            }
        }
    }
```

梳排序
原理：通过将数组分为小的数组，来达到降低时间复杂度的目的

**交换案例**
假设待数组[8 4 3 7 6 5 2 1]

待排数组长度为8,而8÷1.3=6,则比较8和2,4和1,并做交换

[8 4 3 7 6 5 2 1]

[8 4 3 7 6 5 2 1]

交换后的结果为

[2 1 3 7 6 5 8 4]

第二次循环,更新间距为6÷1.3=4,比较2和6,1和5,3和8,7和4

[2 1 3 7 6 5 8 4]

[2 1 3 7 6 5 8 4]

[2 1 3 7 6 5 8 4]

[2 1 3 7 6 5 8 4]

只有7和4需要交换,交换后的结果为

[2 1 3 4 6 5 8 7]

第三次循环,更新距离为3,没有交换

第四次循环,更新距离为2,没有交换

第五次循环,更新距离为1,三处交换

[2 1 3 4 6 5 8 7]

[2 1 3 4 6 5 8 7]

[2 1 3 4 6 5 8 7]

三处交换后的结果为[1 2 3 4 5 6 7 8]

交换后排序结束,顺序输出即可得到[1 2 3 4 5 6 7 8]

```C++
    void Comb_Sort(int *arr,int l,int r){
       float factor=1.3;
       int g=r-l;
       //n the size of array
       int n=r-l;
       bool flag=true;
       while(g>1||flag){
            g=(g>1)?g/factor:g;
            flag=false;
            int i=0;
            //如果全都排序好了，flag为false，g=1直接跳出循环。
            while(i+g<n){
                if(arr[i]>arr[g+i]){
                    std::swap(arr[i],arr[g+i]);
                    flag=true;
                }
                i=i+1;
            }
       }
    }
```

## 归并排序

**分而治之**
![分而治之](/图片资源/分而治之.png)

**合并有序子序列**
![合并相邻有序子序列](/图片资源/合并.png)

```C++
    void MergeSort(int *arr,int l, int r){
        if(l<=r)return;
        int mid=((r-l)/2)+l;
        int len=r-l;
        int *Left=new int[mid-l];
        int *Right=new int[len-mid-l];
        for(int i=0;i<mid;i++)
            Left[i]=arr[i+l];
        for(int i=mid;i<r;i++)
            Right[i-mid]=arr[i+l];
        MergeSort(Left,l,mid);
        MergeSort(Right,mid+1,r);
        Merge(arr,Left,Right,mid-l,r-mid);
    }
    void Merge(int *arr,int *L,int* R,int l,int r){
        int i=0,j=0,k=0;
        while(i<l&&j<r){
            if(L[i]<R[j]){
                arr[k++]=L[i++];
            }
            else
                arr[k++]=R[j++];
        }
        while(i<l)arr[k++]=L[i++];
        while(j<r)arr[k++]=L[j++];
    }
```

## 堆排序

```C++
    //构建大堆
    void BuildMaxHeap(int *A,int len){
        for(int i=len/2;i>0;i--){
            AdjustDown(A,i,len);
        }
    }
    void AdjustDown(int *A,int k,int len){
        int temp=A[k];
        for(i=2*k;i<=len;i++){
            if(i<len&&A[i]<A[i+1])
                i++;
            if(temp>=A[i])
                break;
            else{
                A[k]=A[i];
                k=i;
            }
        }
        A[k]=temp;
    }
    //堆排序算法
    void HeapSort(int *A,int len){
        BuildMaxHeap(A,len);
        for(i=len;i>1;i--){
            std::swap(A[i],A[1]);
            AdjustDown(A,1,i-1);
        }
    }
```

## 插入排序

### 直接插入排序

时间复杂度：O(n^2)
具体过程可以参考此图片
![直接插入排序](/图片资源/直接插入排序.jpg)

```C++
    void DistrictInsertSort(int A[],int n){
            int i,j;
            for(i=1;i<n;i++){
                if(A[i]<A[i-1]){
                    int temp=A[i];
                    for(j=i-1;j>=0&&temp<A[j];--j){
                        A[j+1]=A[j];
                    }
                    A[j+1]=temp;
                }
            }
        }
```

### 希尔排序

#### 希尔交换排序

```C++
    void ShellSort(int A[],int n){
        //前后记录位置的增量 dk
        //增量dk 并逐步减小增量
        for(int dk=n/2;dk>0;dk/=2){
            //从第dk个元素，逐个对其所在组进行直接插入排序操作
            for(int i=dk;i<n;++i){
                int j=i;
                while(j-dk>=0&&A[j]<A[j-dk]){
                    //插入排序交换法
                    swap(A[j],A[j-dk]);
                    j-=dk;
                }
            }
        }
    }
```

#### 希尔插入（移动）排序

```C++
    void ShellSort(int *A,int n){
        for(int dk=n/2;dk>0;dk/=2){
            for(int i=dk;i<n;i++){
                int j=i;
                int temp=A[i];
                if(A[j]<A[j-dk]){
                    while(j-dk>=0&&temp<A[j-dk]){
                        //移动法
                        A[j]=A[j-dk];
                        j-=dk;
                    }
                    A[j]=temp;
                }
            }
        }
    }
```

### 折半插入排序

直接插入排序的改进版，时间复杂度为O(n^2)

```C++
    void InsertSort(int A[],int n){
        int i,j=0;
        for(i=1;i<n;i++){
            int temp=A[i];
            low=1;
            high=i-1;
            while(low<high){
                mid=(low+high)/2;
                if(A[mid]>temp){
                    high=mid-1；//查找左半子树
                }
                else
                    low=mid+1;
                for(j=i-1;j>high+1;--j){
                    A[j+1]=A[j];
                }
                A[high+1]=temp;
            }
        }

    }
```