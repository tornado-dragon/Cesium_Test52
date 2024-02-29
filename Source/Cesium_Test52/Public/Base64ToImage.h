// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Base64ToImage.generated.h"

UCLASS()
class CESIUM_TEST52_API ABase64ToImage : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABase64ToImage();
	UFUNCTION(BlueprintCallable)
	static void Base64ConvertImage(FString baseString);
	
	UFUNCTION(BlueprintCallable)
	static UTexture2D* LoadTextrue2D(const FString path, bool& IsValid, int32& OutWidth, int32& OutHeight);
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
