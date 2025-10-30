// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "ItemDataAsset.generated.h"

class UGameplayAbility;
class UGameplayEffect;

/**
 * 
 */

UENUM(BlueprintType)
enum class EItemType : uint8
{
	Base,
	Consumable,
	Equipable_Weapon,
	Equipable_Armor,
	Equipable_Outfit
};

UCLASS(BlueprintType)
class INVENTORY_API UItemDataAsset : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item")
	int32 ItemID;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item")
	int32 SizeX = 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item")
	int32 SizeY = 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item")
	EItemType ItemType = EItemType::Base;

	
};
