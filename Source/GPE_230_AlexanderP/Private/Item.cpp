// Fill out your copyright notice in the Description page of Project Settings.


#include "Item.h"
#include "DrawDebugHelpers.h"
#include "GPE_230_AlexanderP/GPE_230_AlexanderP.h"

// Sets default values
AItem::AItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AItem::BeginPlay()
{
	Super::BeginPlay();
	
	UE_LOG(LogTemp, Warning, TEXT("Begin play from C++"));

		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(1, 60.f, FColor::Emerald, FString("Onscreen Message from C++"));
	    }

		FVector Location = GetActorLocation();

		DRAW_SPHERE(Location);

}

// Called every frame
void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	UE_LOG(LogTemp, Warning, TEXT("DeltaTime: %f"), DeltaTime);

	if (GEngine)
	{
		FString name = GetName();

		FString message = FString::Printf(TEXT("DeltaTime: %f"), DeltaTime);

		FString itemNameMessage = FString::Printf(TEXT("Item Name: %s"), *name);

		GEngine->AddOnScreenDebugMessage(1, 60.f, FColor::Emerald, itemNameMessage);
	}

}

