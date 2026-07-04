   int totalSum=0;
    for(int i=0;i<nums.size();i++){
        totalSum=totalSum+nums[i];
    }
    int CurrmaxiSum=nums[0];
    int CurrminSum=nums[0];
    int globalMax=nums[0];
    int globalMin=nums[0];
    int result=INT16_MIN;
    for(int j=1;j<nums.size();j++){
        CurrmaxiSum=max(CurrmaxiSum+nums[j],nums[j]);
        CurrminSum=min(CurrminSum+nums[j],nums[j]);
        globalMax=max(globalMax,CurrmaxiSum);
        globalMin=min(globalMin,CurrminSum);
        result=max(result,max(globalMax,totalSum-globalMin));
    }
    if(globalMax<0){
        return globalMax;
    }else{
        return result;
    }
