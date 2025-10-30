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
    /** �����̳ʿ��� ��ġ�� UniformGridPanel�� ���ε� (�̸�: Grid) */
    UPROPERTY(meta = (BindWidget)) UUniformGridPanel* Grid = nullptr;

    /** ������ �� ���� Ŭ����(UCellWidget �Ļ� BP�� ��õ) */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "InventoryUI")
    TSubclassOf<UCellWidget> CellClass;

    /** �� �ȼ� ũ�� (UCellWidget���� ���޵�) */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "InventoryUI")
    int32 CellPixelSize = 64;

    /** ���� ǥ������ �׸��� ũ��(�κ��丮 ������Ʈ���� �о��) */
    UPROPERTY(BlueprintReadOnly, Category = "InventoryUI")
    int32 GridWidth = 0;

    UPROPERTY(BlueprintReadOnly, Category = "InventoryUI")
    int32 GridHeight = 0;

    /** ���õ� �� ��ǥ */
    UPROPERTY(BlueprintReadOnly, Category = "InventoryUI")
    int32 SelectedX = -1;

    UPROPERTY(BlueprintReadOnly, Category = "InventoryUI")
    int32 SelectedY = -1;

protected:
    UPROPERTY(Transient) TWeakObjectPtr<UInventoryGridComponent> InventoryComp;

    /** �� Ǯ (Y*GridWidth + X) �ε����� ���� */
    UPROPERTY(Transient) TArray<TObjectPtr<UCellWidget>> Cells;

public:
	virtual void NativeConstruct() override;

    UFUNCTION(BlueprintCallable, Category = "InventoryUI")
    void GenerateGrid();
};
