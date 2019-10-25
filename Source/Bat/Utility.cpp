// Fill out your copyright notice in the Description page of Project Settings.


#include "Utility.h"

void UUtility::ChangeVal(float *value, float* motify, float* threshold, bool* greater){
    if (greater){
        value = value + motify > threshold? threshold : value + motify;
    }
    else{
        value = value - motify < threshold? threshold : value - motify;
    }
}