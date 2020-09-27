这周的作业难度较大，信念差一点崩塌，不过静下来分析大牛的代码，收获良多，也有一部分原因是知识储备不足造成的。
在看网上题解的过程中，发现一位大神的关于回溯法的模板比较不错：
vector<vector<int>> main(...){
    vector<vector<int>>res;  // Store the result, could be other container
    backtrack(res, ...);  // Recursion function to fill the res
    return res;
}

void backtrack(vector<vector<int>>& res, int cur, ..., vector<int>vec){
    if(meet the end critria, i.e. cur reach the end of array){  
        //vec could be a certain path/combination/subset
        res.push_back(vec);
        return;
    }
    // Current element is not selected
    backtrack(res, cur+1, ..., vec);
    // Current element is selected
    vec.push_back(cur); // or could be vec.push_back(nums[cur]), vec.push_back(graph[cur]);
    backtrack(res,cur+1, ..., vec);
}
