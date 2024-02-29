// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BP_setLabel.generated.h"

UCLASS()
class CESIUM_TEST52_API ABP_setLabel : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABP_setLabel();

	//TMap<FString, ABP_Label_Actor2*> LabelMap;

	UFUNCTION(BlueprintCallable)
	void InitTextLabel(const FVector& Location);
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
