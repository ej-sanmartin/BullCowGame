#pragma once

#include "CoreMinimal.h"
#include "Console/Cartridge.h"
#include "BullCowCartridge.generated.h"

struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class BULLCOWGAME_API UBullCowCartridge : public UCartridge
{
	GENERATED_BODY()

	public:
	virtual void BeginPlay() override;
	virtual void OnInput(const FString& PlayerInput) override;
	void InitGame();
	void EndGame();
	TArray<FString> GetValidWords(const TArray<FString>& WordList) const;
	void ProcessGuess(const FString& Guess);
	bool IsIsogram(const FString& Word) const;
	FBullCowCount GetBullCows(const FString& Guess) const;

	private:
	TArray<FString> Words;
	TArray<FString> ValidWords;
	FString HiddenWord;
	int32 Lives;
	bool bGameOver;
};
