// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AbilitySystemInterface.h"
#include "GameplayAbilitySpec.h"
#include "GameplayEffectTypes.h"
#include "GameplayTagContainer.h"
#include "ItemDataAsset.h"
#include "InventoryGridComponent.generated.h"

class UAbilitySystemComponent;
//class FGameplayEffectHandle;

/** 런타임 아이템(복제 쉬우라고 USTRUCT로 구현) */
USTRUCT(BlueprintType)
struct INVENTORY_API FInventoryItem
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite) FGuid Guid;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) TObjectPtr<UItemDataAsset> Data = nullptr;

    /** 그리드 좌상단(0-based) */
    UPROPERTY(EditAnywhere, BlueprintReadWrite) int32 X = 0;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) int32 Y = 0;

    UPROPERTY(EditAnywhere, BlueprintReadWrite) int32 Stack = 1;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) bool  bEquipped = false;

    /** 서버 전용 핸들(복제 안 함) */
    //FGameplayEffectHandle       EquippedGE;
    FGameplayAbilitySpecHandle  GrantedAbility;

    int32 W() const { return Data ? Data->SizeX : 1; }
    int32 H() const { return Data ? Data->SizeY : 1; }
    bool  IsValid() const { return Data && Stack > 0; }
};


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class INVENTORY_API UInventoryGridComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInventoryGridComponent();

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Inventory") int32 GridWidth = 10;
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Inventory") int32 GridHeight = 6;

    /** 간단 복제: RepNotify TArray */
    UPROPERTY(ReplicatedUsing = OnRep_Items)
    TArray<FInventoryItem> Items;

    UFUNCTION() void OnRep_Items();

    UFUNCTION(BlueprintPure)
    const TArray<FInventoryItem>& GetItems() const { return Items; }

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& Out) const override;

    bool CanPlaceAt(const FInventoryItem& C, const FGuid* Ignore = nullptr) const;
    bool FindFirstFit(UItemDataAsset* Data, int32& OutX, int32& OutY) const;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
