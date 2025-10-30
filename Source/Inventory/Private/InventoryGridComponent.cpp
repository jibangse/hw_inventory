// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryGridComponent.h"
#include "AbilitySystemComponent.h"
#include "AbilitySystemInterface.h"
#include "Net/UnrealNetwork.h"
#include "GameFramework/Actor.h"

// Sets default values for this component's properties
UInventoryGridComponent::UInventoryGridComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	SetIsReplicatedByDefault(true);
}


void UInventoryGridComponent::OnRep_Items()
{
	// UI가 이 이벤트에 바인딩해서 그리드 리빌드하면 됨
}

// Called when the game starts
void UInventoryGridComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

void UInventoryGridComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& Out) const
{
	Super::GetLifetimeReplicatedProps(Out);
	//DOREPLIFETIME(UInventoryGridComponent, Items);
}

bool UInventoryGridComponent::CanPlaceAt(const FInventoryItem& C, const FGuid* Ignore) const
{
    if (!C.Data) return false;
    const int32 W = C.W(), H = C.H();

    if (C.X < 0 || C.Y < 0 || C.X + W > GridWidth || C.Y + H > GridHeight)
        return false;

    const int32 Cx1 = C.X, Cy1 = C.Y;
    const int32 Cx2 = Cx1 + W - 1, Cy2 = Cy1 + H - 1;

    for (const auto& E : Items)
    {
        if (!E.IsValid()) continue;
        if (Ignore && E.Guid == *Ignore) continue;

        const int32 Ex1 = E.X, Ey1 = E.Y;
        const int32 Ex2 = Ex1 + E.W() - 1, Ey2 = Ey1 + E.H() - 1;

        const bool Overlap = !(Cx2 < Ex1 || Ex2 < Cx1 || Cy2 < Ey1 || Ey2 < Cy1);
        if (Overlap) return false;
    }
    return true;
}

bool UInventoryGridComponent::FindFirstFit(UItemDataAsset* Data, int32& OutX, int32& OutY) const
{
    if (!Data) return false;
    for (int32 y = 0; y <= GridHeight - Data->SizeY; ++y)
        for (int32 x = 0; x <= GridWidth - Data->SizeX; ++x)
        {
            FInventoryItem C; C.Data = Data; C.X = x; C.Y = y; C.Stack = 1;
            if (CanPlaceAt(C)) { OutX = x; OutY = y; return true; }
        }
    return false;
}


// Called every frame
void UInventoryGridComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

