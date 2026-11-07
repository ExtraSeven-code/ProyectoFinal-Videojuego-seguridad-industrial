
#include "DownloadsHelper.h"

#if PLATFORM_WINDOWS
#include "Windows/AllowWindowsPlatformTypes.h"
#include <ShlObj.h>
#include <KnownFolders.h>
#include "Windows/HideWindowsPlatformTypes.h"
#endif

FString UDownloadsHelper::GetDownloadsDirectory()
{
#if PLATFORM_WINDOWS

    PWSTR DownloadsPath = nullptr;

    HRESULT Result = SHGetKnownFolderPath(
        FOLDERID_Downloads,
        0,
        nullptr,
        &DownloadsPath
    );

    if (SUCCEEDED(Result) && DownloadsPath != nullptr)
    {
        FString Path = FString(DownloadsPath);

        CoTaskMemFree(DownloadsPath);

        Path.ReplaceInline(TEXT("\\"), TEXT("/"));

        if (!Path.EndsWith(TEXT("/")))
        {
            Path += TEXT("/");
        }

        return Path;
    }

    if (DownloadsPath != nullptr)
    {
        CoTaskMemFree(DownloadsPath);
    }

#endif

    return FString();
}
