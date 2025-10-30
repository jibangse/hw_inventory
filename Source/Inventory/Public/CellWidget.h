// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CellWidget.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnCellClicked, int32, CellX, int32, CellY);
/**
 * 
 */
UCLASS()
class INVENTORY_API UCellWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY(meta = (BindWidget)) class UButton* BtnCell;  // ��ư ���ε�
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cell") int32 CellX = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cell") int32 CellY = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cell") bool bIsOccupied = false;

	/** �� Ŭ��(��ǥ ����) */
	UPROPERTY(BlueprintAssignable, Category = "Cell")
	FOnCellClicked OnCellClicked;

	/** �� �ȼ� ũ��(UniformGrid�� ���ϴ� ������ ���޿�) */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cell")
	int32 CellPixelSize = 64;

public:
	virtual void NativeConstruct() override;

	UFUNCTION(BlueprintCallable, Category = "Cell")
	void SetOccupied(bool bInOccupied)
	{
		bIsOccupied = bInOccupied;
		//ApplyVisual();
	}
	
};
