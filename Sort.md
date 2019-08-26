# 各种排序

## 快速排序

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
       int r=0;
       int g=r-l;
       bool flag=true;
       while(g>1||flag){
            g=(g>1)?g/factor:g;
            flag=false;
            int i=0;
            while(i+g<=n){
                if(a[i+l]>a[g+i+l]){
                    swap(a[i],a[g+i]);
                    flag=true;
                }
                i=i+1;
            }
       }
    }
```
