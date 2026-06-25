// Copyright Epic Games, Inc. All Rights Reserved.

#include "MyCustomAsset.h"

UMyCustomAsset::UMyCustomAsset()
{
    DisplayName = TEXT("New MyCustomAsset");
    MyFloatValue = 100.0f;
    MyState = EMyAssetState::Active;
}
