// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/Button.h"
#include "CellWidget.generated.h"

/**
 * 
 */
UCLASS()
class INVENTORY_API UCellWidget : public UButton
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cell") int32 CellX = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cell") int32 CellY = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cell") bool bIsOccupied = false;
	
};
