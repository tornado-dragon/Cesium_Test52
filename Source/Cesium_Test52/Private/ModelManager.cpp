// Fill out your copyright notice in the Description page of Project Settings.

#include "ModelManager.h"
#include "Components/ActorComponent.h"
//#include "Cesium3DTiles/Cesium3DTileset.h"
// Sets default values
AModelManager::AModelManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AModelManager::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("This is a warning message. Value: %d"), 42);
	
	
}

// Called every frame
void AModelManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

