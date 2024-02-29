// Fill out your copyright notice in the Description page of Project Settings.


#include "BP_setLabel.h"

// Sets default values
ABP_setLabel::ABP_setLabel()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABP_setLabel::BeginPlay()
{
	Super::BeginPlay();	
	
}

// Called every frame
void ABP_setLabel::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ABP_setLabel::InitTextLabel(const FVector& Location)
{
    // Create a new instance of MyCustomActor
    //UE_LOG(LogTemp, Warning, TEXT("@@SpawnActorAtLocation"));

    UClass* AClass = LoadClass<AActor>(nullptr, TEXT("Blueprint'/Game/BluePrint/BP_Label_Actor2.BP_Label_Actor2_C'"));

    if (AClass)
    {
        FTransform SpawnTransform = FTransform(FRotator::ZeroRotator, Location, FVector::OneVector);

        GetWorld()->SpawnActor<AActor>(AClass, SpawnTransform);
        //UE_LOG(LogTemp, Warning, TEXT("@@SpawnActor"));

    }
    //if (NewActor)
    //{
    //    // Add the new actor to the LabelMap
    //    FString Key = FString::Printf(TEXT("%f_%f_%f"), X, Y, Z);
    //    LabelMap.Add(Key, NewActor);
    //}
}

