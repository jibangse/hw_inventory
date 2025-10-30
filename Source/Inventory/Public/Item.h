// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Item.generated.h"

/**
 * 
 */

USTRUCT(BlueprintType)
struct INVENTORY_API FPoint2D
{
	GENERATED_BODY()

	FPoint2D()
	{
		X = 0;
		Y = 0;
	}

	FPoint2D(const int32 InX, const int32 InY)
	{
		X = InX;
		Y = InY;
	}

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (ClampMin = 0, UIMin = 0))
	int32 X;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (ClampMin = 0, UIMin = 0))
	int32 Y;

	bool operator == (const FPoint2D& Other) const
	{
		return Other.X == X && Other.Y == Y;
	}

	FPoint2D operator + (const FPoint2D& Other) const
	{
		return FPoint2D(Other.X + X, Other.Y + Y);
	}

	bool operator > (const FPoint2D& Other) const
	{
		return Other.X > X && Other.Y > Y;
	}

	bool operator >= (const FPoint2D& Other) const
	{
		return Other.X >= X && Other.Y >= Y;
	}

	bool operator < (const FPoint2D& Other) const
	{
		return (Other.X < X && Other.Y < Y);
	}

	bool operator <= (const FPoint2D& Other) const
	{
		return (Other.X <= X && Other.Y <= Y);
	}
};

UCLASS(BlueprintType, Blueprintable)
class INVENTORY_API UItem : public UObject
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = true), Category = "Item")
	uint8 ID = 0;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = true), Category = "Item")
	FPoint2D Size;


	
};
