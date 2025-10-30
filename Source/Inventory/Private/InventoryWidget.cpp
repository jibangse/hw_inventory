// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryWidget.h"

void UInventoryWidget::NativeConstruct()
{
    Super::NativeConstruct();

    // 셀 클래스 없으면 에러 방지
    if (!ensure(CellClass)) return;
    if (!ensure(Grid)) return;

}

void UInventoryWidget::GenerateGrid()
{
    if (!Grid || !CellClass) return;

    Grid->ClearChildren();
    Cells.Reset();
    Cells.SetNum(GridWidth * GridHeight);

    for (int32 y = 0; y < GridHeight; ++y)
    {
        for (int32 x = 0; x < GridWidth; ++x)
        {
            //UCellWidget* Cell = CreateWidget<UCellWidget>(GetWorld(), CellClass);
            //if (!ensure(Cell)) continue;

            //Cell->CellX = x;
            //Cell->CellY = y;
            //Cell->CellPixelSize = CellPixelSize;
            //Cell->SetOccupied(false);

            //// 클릭 바인딩 (좌표 전달)
            //Cell->OnCellClicked.AddDynamic(this, &UInventoryWidget::HandleCellClicked);

            //// UniformGrid에 추가
            //if (UUniformGridSlot* Slot = Grid->AddChildToUniformGrid(Cell, y, x))
            //{
            //    Slot->SetHorizontalAlignment(HAlign_Fill);
            //    Slot->SetVerticalAlignment(VAlign_Fill);
            //}

            //Cells[y * GridWidth + x] = Cell;
        }
    }
}
