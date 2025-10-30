// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryWidget.h"

void UInventoryWidget::NativeConstruct()
{
    Super::NativeConstruct();

    // �� Ŭ���� ������ ���� ����
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

            //// Ŭ�� ���ε� (��ǥ ����)
            //Cell->OnCellClicked.AddDynamic(this, &UInventoryWidget::HandleCellClicked);

            //// UniformGrid�� �߰�
            //if (UUniformGridSlot* Slot = Grid->AddChildToUniformGrid(Cell, y, x))
            //{
            //    Slot->SetHorizontalAlignment(HAlign_Fill);
            //    Slot->SetVerticalAlignment(VAlign_Fill);
            //}

            //Cells[y * GridWidth + x] = Cell;
        }
    }
}
