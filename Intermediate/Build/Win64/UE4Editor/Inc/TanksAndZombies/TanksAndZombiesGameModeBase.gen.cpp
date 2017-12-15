// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "TanksAndZombiesGameModeBase.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeTanksAndZombiesGameModeBase() {}
// Cross Module References
	TANKSANDZOMBIES_API UClass* Z_Construct_UClass_ATanksAndZombiesGameModeBase_NoRegister();
	TANKSANDZOMBIES_API UClass* Z_Construct_UClass_ATanksAndZombiesGameModeBase();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_TanksAndZombies();
// End Cross Module References
	void ATanksAndZombiesGameModeBase::StaticRegisterNativesATanksAndZombiesGameModeBase()
	{
	}
	UClass* Z_Construct_UClass_ATanksAndZombiesGameModeBase_NoRegister()
	{
		return ATanksAndZombiesGameModeBase::StaticClass();
	}
	UClass* Z_Construct_UClass_ATanksAndZombiesGameModeBase()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			static UObject* (*const DependentSingletons[])() = {
				(UObject* (*)())Z_Construct_UClass_AGameModeBase,
				(UObject* (*)())Z_Construct_UPackage__Script_TanksAndZombies,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
				{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
				{ "IncludePath", "TanksAndZombiesGameModeBase.h" },
				{ "ModuleRelativePath", "TanksAndZombiesGameModeBase.h" },
				{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
			};
#endif
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<ATanksAndZombiesGameModeBase>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&ATanksAndZombiesGameModeBase::StaticClass,
				DependentSingletons, ARRAY_COUNT(DependentSingletons),
				0x00900288u,
				nullptr, 0,
				nullptr, 0,
				nullptr,
				&StaticCppClassTypeInfo,
				nullptr, 0,
				METADATA_PARAMS(Class_MetaDataParams, ARRAY_COUNT(Class_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUClass(OuterClass, ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ATanksAndZombiesGameModeBase, 499535861);
	static FCompiledInDefer Z_CompiledInDefer_UClass_ATanksAndZombiesGameModeBase(Z_Construct_UClass_ATanksAndZombiesGameModeBase, &ATanksAndZombiesGameModeBase::StaticClass, TEXT("/Script/TanksAndZombies"), TEXT("ATanksAndZombiesGameModeBase"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ATanksAndZombiesGameModeBase);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
