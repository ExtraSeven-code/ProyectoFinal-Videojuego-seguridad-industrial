
#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "DownloadsHelper.generated.h"

UCLASS()
class PROYECTOFINAL_API UDownloadsHelper : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:

    UFUNCTION(BlueprintCallable, Category = "Archivos")
    static FString GetDownloadsDirectory();
};
