/*
设k是允许改变的次数
d是回文串中不同的个数
1. k<d: 不可能
2. k==d: 取每个不同字符的最大值，改变
3. k=d+1: 如果回文是奇数，改变中间此值为9
4. k>=d+2: 从第0位开始，都变成9

第一次思路卡在4，因为有两个选择:
1. 按照（2），只改变1个
2. 如果两个都不是9，都改成9, 改变2个
3. 如果最后还剩下k，从最高位开始改成9，一次改变2个
*/

/* !!分类不重叠非常重要!!       不重不漏
1. 第一次扫描: 列出必须改变的位changed[]，同时改变s[b]=s[a]. 使两种改变方法不重迭. 已经形成回文
2. 第二次扫描: 两次改变9越早越好->最大值, 
3. !!!设计地非常精妙!!!
*/
#if 0   //partly right
vector<int> Diff(const string& s) {
    vector<int> ret;
    int l = 0;
    int r = (int)s.size()-1;
    
    while(l<r) {
        if(s[l]!=s[r]) ret.push_back(l);
        ++l;
        --r;
    }
    
    return ret;
}

void Replace(string& s, int l) {
    int len = s.size();
    if(s[l]>s[len-1-l]) {
        s[len-1-l] = s[l];
    } else {
        s[l] = s[len-1-l];
    }
}

void Increase2(string& s) {
    int len = s.size();
    int i = 0;
    
    while(i<len && s[i]=='9') ++i;
    if(i>=len) return;
    
    s[i] = '9';
    s[len-1-i] = '9';
}

string highestValuePalindrome(string s, int n, int k) {
    vector<int> diff = Diff(s);
    int lenD = diff.size();
            
    if(lenD>k) return "-1";
    
    if(lenD==k) {
        for(int i : diff) Replace(s, i);
        return s;
    }
    
    int moreK = k-lenD;
    int lenS = s.size();
    
    if(moreK==1) {
        if(lenD==0) {
            if(lenS%2==0) return s;
            s[lenS/2] = '9';
            return s; 
        }
        
        s[ diff[0] ] = '9';
        s[ lenS-1-diff[0] ] = '9';
        
        for(int i=1; i<lenD; ++i) Replace(s, diff[i]);
        return s;
    }
       
    if(moreK==2) {
        if(lenD==0) {
            Increase2(s);
            return s; 
        }
        
        if(lenD==1) {
            s[ diff[0] ] = '9';
            s[ lenS-1-diff[0] ] = '9';    
            return s; 
        }
        
        cout << "hhh" << endl;
    }
    
    return s;
}
#else
string highestValuePalindrome(string s, int n, int k) {
    assert(n == (int)s .length());
    bool changed[ n ] = {false};
    
    int l=0, r=n-1;
    while(l<r) {
        if(s[l]>s[r]) {
            s[r] = s[l];
            changed[r] = true;
            --k;
        } else if(s[l]<s[r]) {
            s[l] = s[r];
            changed[l] = true;
            --k;
        }
        
        if(k<0) return "-1";
        ++l;
        --r;
    }
    
    l=0, r=n-1;
    while(l<=r && k>0) {        //Changing 9 earliest 
        if(s[l]!='9') {
            if(l==r) {          //medium
                s[l] = '9';
                --k;
            } else if(changed[l] || changed[r]) {
                s[l]=s[r]='9';
                --k;
            } else if(k>=2) {            //Changing 9 earliest
                s[l]=s[r]='9';
                k -= 2;
            }
        }
            
        ++l;
        --r;
    }
    
    return s;
}
#endif