// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef VIRECO_ViReCoCharacter_generated_h
#error "ViReCoCharacter.generated.h already included, missing '#pragma once' in ViReCoCharacter.h"
#endif
#define VIRECO_ViReCoCharacter_generated_h

#define ViReCo_Source_ViReCo_ViReCoCharacter_h_14_RPC_WRAPPERS
#define ViReCo_Source_ViReCo_ViReCoCharacter_h_14_RPC_WRAPPERS_NO_PURE_DECLS
#define ViReCo_Source_ViReCo_ViReCoCharacter_h_14_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAViReCoCharacter(); \
	friend VIRECO_API class UClass* Z_Construct_UClass_AViReCoCharacter(); \
public: \
	DECLARE_CLASS(AViReCoCharacter, ACharacter, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/ViReCo"), NO_API) \
	DECLARE_SERIALIZER(AViReCoCharacter) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define ViReCo_Source_ViReCo_ViReCoCharacter_h_14_INCLASS \
private: \
	static void StaticRegisterNativesAViReCoCharacter(); \
	friend VIRECO_API class UClass* Z_Construct_UClass_AViReCoCharacter(); \
public: \
	DECLARE_CLASS(AViReCoCharacter, ACharacter, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/ViReCo"), NO_API) \
	DECLARE_SERIALIZER(AViReCoCharacter) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define ViReCo_Source_ViReCo_ViReCoCharacter_h_14_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AViReCoCharacter(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AViReCoCharacter) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AViReCoCharacter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AViReCoCharacter); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AViReCoCharacter(AViReCoCharacter&&); \
	NO_API AViReCoCharacter(const AViReCoCharacter&); \
public:


#define ViReCo_Source_ViReCo_ViReCoCharacter_h_14_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AViReCoCharacter(AViReCoCharacter&&); \
	NO_API AViReCoCharacter(const AViReCoCharacter&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AViReCoCharacter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AViReCoCharacter); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AViReCoCharacter)


#define ViReCo_Source_ViReCo_ViReCoCharacter_h_14_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__Mesh1P() { return STRUCT_OFFSET(AViReCoCharacter, Mesh1P); } \
	FORCEINLINE static uint32 __PPO__FP_Gun() { return STRUCT_OFFSET(AViReCoCharacter, FP_Gun); } \
	FORCEINLINE static uint32 __PPO__FP_MuzzleLocation() { return STRUCT_OFFSET(AViReCoCharacter, FP_MuzzleLocation); } \
	FORCEINLINE static uint32 __PPO__VR_Gun() { return STRUCT_OFFSET(AViReCoCharacter, VR_Gun); } \
	FORCEINLINE static uint32 __PPO__VR_MuzzleLocation() { return STRUCT_OFFSET(AViReCoCharacter, VR_MuzzleLocation); } \
	FORCEINLINE static uint32 __PPO__FirstPersonCameraComponent() { return STRUCT_OFFSET(AViReCoCharacter, FirstPersonCameraComponent); } \
	FORCEINLINE static uint32 __PPO__R_MotionController() { return STRUCT_OFFSET(AViReCoCharacter, R_MotionController); } \
	FORCEINLINE static uint32 __PPO__L_MotionController() { return STRUCT_OFFSET(AViReCoCharacter, L_MotionController); }


#define ViReCo_Source_ViReCo_ViReCoCharacter_h_11_PROLOG
#define ViReCo_Source_ViReCo_ViReCoCharacter_h_14_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ViReCo_Source_ViReCo_ViReCoCharacter_h_14_PRIVATE_PROPERTY_OFFSET \
	ViReCo_Source_ViReCo_ViReCoCharacter_h_14_RPC_WRAPPERS \
	ViReCo_Source_ViReCo_ViReCoCharacter_h_14_INCLASS \
	ViReCo_Source_ViReCo_ViReCoCharacter_h_14_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define ViReCo_Source_ViReCo_ViReCoCharacter_h_14_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ViReCo_Source_ViReCo_ViReCoCharacter_h_14_PRIVATE_PROPERTY_OFFSET \
	ViReCo_Source_ViReCo_ViReCoCharacter_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	ViReCo_Source_ViReCo_ViReCoCharacter_h_14_INCLASS_NO_PURE_DECLS \
	ViReCo_Source_ViReCo_ViReCoCharacter_h_14_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID ViReCo_Source_ViReCo_ViReCoCharacter_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
