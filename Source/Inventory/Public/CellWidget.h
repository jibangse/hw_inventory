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
	UPROPERTY(meta = (BindWidget)) class UButton* BtnCell;  // 버튼 바인딩
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cell") int32 CellX = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cell") int32 CellY = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cell") bool bIsOccupied = false;

	/** 셀 클릭(좌표 전달) */
	UPROPERTY(BlueprintAssignable, Category = "Cell")
	FOnCellClicked OnCellClicked;

	/** 셀 픽셀 크기(UniformGrid에 원하는 사이즈 전달용) */
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
