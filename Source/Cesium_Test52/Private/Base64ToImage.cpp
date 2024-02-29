#include "Base64ToImage.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"
#include "Engine/Texture2DDynamic.h"
#include "IImageWrapperModule.h"
#include "Templates/SharedPointer.h"
#include "Misc/Base64.h"
#include <string> // 确保包含了 string 头文件
#include <fstream> // 包含文件操作相关的头文件

// Sets default values
ABase64ToImage::ABase64ToImage()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABase64ToImage::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABase64ToImage::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

//void loadImageBase64(FString BaseString)
//{
//	//FString ContentString = getStr()
//	TArray<uint8> data;
//	FBase64::Decode(BaseString, data);
//	//auto Texture = DataToTexture(data);
//}

//UTexture2DDynamic* DataToTexture(const TArray<uint8>Data)
//{
//	IImageWrapperModule& ImageWrapperModule = FModuleManager::LoadModuleChecked<IImageWrapperModule>(FName("ImageWrapper"));
//	TSharedPtr<IImageWrapper> ImageWrappers[3] =
//	{
//		ImageWrapperModule.CreateImageWrapper(EImageFormat::PNG),
//		ImageWrapperModule.CreateImageWrapper(EImageFormat::JPEG),
//		ImageWrapperModule.CreateImageWrapper(EImageFormat::BMP),
//	};
//
//	for (auto ImageWrapper : ImageWrappers)
//	{
//		if (ImageWrapper.IsValid() && ImageWrapper->SetCompressed(Data.GetData(), Data.Num()))
//		{
//			TArray<uint8> RawData;
//			if (ImageWrapper->GetRaw(ERGBFormat::BGRA, 8, RawData))
//			{
//				if (UTexture2DDynamic* Texture = UTexture2DDynamic::Create(ImageWrapper->GetWidth(), ImageWrapper->GetHeight()))
//				{
//					Texture->SRGB = true;
//					Texture->UpdateResource();
//
//					FTexture2DDynamicResource* ParmTextureResource = static_cast<FTexture2DDynamicResource*>(Texture->Resource);
//					ENQUEUE_RENDER_COMMAND(FWriteRawDataToTexture)(
//						[ParmTextureResource, RawData](FRHICommandListImmediate& RHICmdList)
//						{
//							WriteRawToTexture_RenderThread(ParmTextureResource, RawData);
//						});
//					OnImageReceived.Broadcast(Texture);
//					return Texture;
//				}
//			}
//		}
//	}
//
//	UE_LOG(LogTemp, Error, TEXT("DataToTexture Fail"));
//	return nullptr;
//}

void ABase64ToImage::Base64ConvertImage(FString baseString)
{
	TArray<uint8> outArray;
	if (FBase64::Decode(baseString, outArray))
	{
		char* p = reinterpret_cast<char*>(outArray.GetData());
		std::string imgPath = TCHAR_TO_UTF8(*FPaths::ProjectSavedDir());
		imgPath += "out.png";
		std::ofstream imgFile(imgPath, std::ios::binary | std::ios::out);
		imgFile.write(p, outArray.Num());
		imgFile.close();

	}
}

static TSharedPtr<IImageWrapper>  GetImageWrapperByExtention(const FString path)
{
	IImageWrapperModule& module = FModuleManager::LoadModuleChecked<IImageWrapperModule>(FName("ImageWrapper"));
	if (path.EndsWith(".png"))
	{
		return module.CreateImageWrapper(EImageFormat::PNG);
	}
	if (path.EndsWith(".jpg"))
	{
		return module.CreateImageWrapper(EImageFormat::JPEG);
	}

	return nullptr;
}

UTexture2D* ABase64ToImage::LoadTextrue2D(const FString path, bool& IsValid, int32& OutWidth, int32& OutHeight)
{
	UTexture2D* Texture = nullptr;
	IsValid = false;
	if (!FPlatformFileManager::Get().GetPlatformFile().FileExists(*path))
	{
		return nullptr;
	}
	TArray<uint8> CompressedData;
	if (!FFileHelper::LoadFileToArray(CompressedData, *path))
	{
		return nullptr;
	}
	TSharedPtr<IImageWrapper> ImageWrapper = GetImageWrapperByExtention(path);
	if (ImageWrapper.IsValid() && ImageWrapper->SetCompressed(CompressedData.GetData(), CompressedData.Num()))
	{
		TArray<uint8> UncompressedRGBA;
		if (ImageWrapper->GetRaw(ERGBFormat::RGBA, 8, UncompressedRGBA))
		{
			Texture = UTexture2D::CreateTransient(ImageWrapper->GetWidth(), ImageWrapper->GetHeight(), PF_R8G8B8A8);
			if (Texture != nullptr)
			{
				IsValid = true;
				OutWidth = ImageWrapper->GetWidth();
				OutHeight = ImageWrapper->GetHeight();
				void* TextureData = Texture->PlatformData->Mips[0].BulkData.Lock(LOCK_READ_WRITE);
				FMemory::Memcpy(TextureData, UncompressedRGBA.GetData(), UncompressedRGBA.Num());
				Texture->PlatformData->Mips[0].BulkData.Unlock();
				Texture->UpdateResource();
			}
		}
	}
	return Texture;
}

