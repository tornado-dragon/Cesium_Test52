// Fill out your copyright notice in the Description page of Project Settings.


#include "hexadecimal2RGB.h"

FLinearColor Uhexadecimal2RGB::Hexadecimal2RGB(FString HexColorCode)
{
    HexColorCode.ReplaceInline(TEXT("#"), TEXT(""));

    // 将十六进制字符串转换为整数
    int32 HexColorValue;
    if (HexColorCode.IsNumeric())
    {
        HexColorValue = FCString::Atoi(*HexColorCode);
    }
    else
    {
        HexColorValue = FCString::Strtoi(*HexColorCode, nullptr, 16);
    }

    // 提取RGB通道
    int32 Red = (HexColorValue >> 16) & 0xFF;
    int32 Green = (HexColorValue >> 8) & 0xFF;
    int32 Blue = HexColorValue & 0xFF;

    // 将RGB值映射到0到1之间
    float NormalizedRed = Red / 255.0f;
    float NormalizedGreen = Green / 255.0f;
    float NormalizedBlue = Blue / 255.0f;
    // 创建FLinearColor对象
    return FLinearColor(NormalizedRed, NormalizedGreen, NormalizedBlue, 1.0f);
    //return (Red << 16) | (Green << 8) | Blue;
}

