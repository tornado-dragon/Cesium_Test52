// Fill out your copyright notice in the Description page of Project Settings.


#include "hexadecimal2RGB.h"

FLinearColor Uhexadecimal2RGB::Hexadecimal2RGB(FString HexColorCode)
{
    HexColorCode.ReplaceInline(TEXT("#"), TEXT(""));

    // ��ʮ�������ַ���ת��Ϊ����
    int32 HexColorValue;
    if (HexColorCode.IsNumeric())
    {
        HexColorValue = FCString::Atoi(*HexColorCode);
    }
    else
    {
        HexColorValue = FCString::Strtoi(*HexColorCode, nullptr, 16);
    }

    // ��ȡRGBͨ��
    int32 Red = (HexColorValue >> 16) & 0xFF;
    int32 Green = (HexColorValue >> 8) & 0xFF;
    int32 Blue = HexColorValue & 0xFF;

    // ��RGBֵӳ�䵽0��1֮��
    float NormalizedRed = Red / 255.0f;
    float NormalizedGreen = Green / 255.0f;
    float NormalizedBlue = Blue / 255.0f;
    // ����FLinearColor����
    return FLinearColor(NormalizedRed, NormalizedGreen, NormalizedBlue, 1.0f);
    //return (Red << 16) | (Green << 8) | Blue;
}

