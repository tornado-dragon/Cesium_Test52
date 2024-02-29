// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "hexadecimal2RGB.generated.h"

/**
 * 
 */
UCLASS()
class CESIUM_TEST52_API Uhexadecimal2RGB : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintPure, Category = "Utilities")
	static FLinearColor Hexadecimal2RGB(FString HexColorCode);
	
};
