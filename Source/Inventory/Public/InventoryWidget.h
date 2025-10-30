// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/UniformGridPanel.h"
#include "Components/UniformGridSlot.h"
#include "CellWidget.h"
#include "InventoryGridComponent.h" 
#include "InventoryWidget.generated.h"

/**
 * 
 */
UCLASS()
class INVENTORY_API UInventoryWidget : public UUserWidget
{
	GENERATED_BODY()

public:
    /** 디자이너에서 배치한 UniformGridPanel에 바인딩 (이름: Grid) */
    UPROPERTY(meta = (BindWidget)) UUniformGridPanel* Grid = nullptr;

    /** 생성할 셀 위젯 클래스(UCellWidget 파생 BP를 추천) */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "InventoryUI")
    TSubclassOf<UCellWidget> CellClass;

    /** 셀 픽셀 크기 (UCellWidget에도 전달됨) */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "InventoryUI")
    int32 CellPixelSize = 64;

    /** 현재 표시중인 그리드 크기(인벤토리 컴포넌트에서 읽어옴) */
    UPROPERTY(BlueprintReadOnly, Category = "InventoryUI")
    int32 GridWidth = 0;

    UPROPERTY(BlueprintReadOnly, Category = "InventoryUI")
    int32 GridHeight = 0;

    /** 선택된 셀 좌표 */
    UPROPERTY(BlueprintReadOnly, Category = "InventoryUI")
    int32 SelectedX = -1;

    UPROPERTY(BlueprintReadOnly, Category = "InventoryUI")
    int32 SelectedY = -1;

protected:
    UPROPERTY(Transient) TWeakObjectPtr<UInventoryGridComponent> InventoryComp;

    /** 셀 풀 (Y*GridWidth + X) 인덱스로 접근 */
    UPROPERTY(Transient) TArray<TObjectPtr<UCellWidget>> Cells;

public:
	virtual void NativeConstruct() override;

    UFUNCTION(BlueprintCallable, Category = "InventoryUI")
    void GenerateGrid();
};
